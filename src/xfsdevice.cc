#include "xfsdevice.h"
#include <uv.h>
#include "common.h"
#include "window.h"
#include "json.hpp"
#include "xsj.h"

using json = nlohmann::json;

//#############################################################################
//#############################################################################
Nan::Persistent<v8::Function> XfsDevice::constructor;
#define DefineXFSProcessor(evt, proc) void XfsDevice::proc(LPWFSRESULT pData)

//#############################################################################
//#############################################################################
XfsDevice::XfsDevice(const Nan::FunctionCallbackInfo<v8::Value>& info):
	m_this(v8::Isolate::GetCurrent(), info.Holder()), 
	m_traceLevel(WFS_TRACE_API), m_timeOut(10000) {
}

//#############################################################################
//#############################################################################
XfsDevice::~XfsDevice() {
}

//#############################################################################
//#############################################################################
void XfsDevice::Init(v8::Local<v8::Object> exports) {
	Nan::HandleScope scope;

	// Prepare constructor template
	v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
	tpl->SetClassName(Nan::New("XfsDevice").ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	Nan::SetPrototypeMethod(tpl, "___call", Call);
	
	constructor.Reset(tpl->GetFunction());
	exports->Set(Nan::New("XfsDevice").ToLocalChecked(), tpl->GetFunction());
}

//#############################################################################
//#############################################################################
void XfsDevice::New(const Nan::FunctionCallbackInfo<v8::Value>& info) {
	if (info.IsConstructCall()) {
		XfsDevice* obj = new XfsDevice(info);
		obj->Wrap(info.This());
		info.GetReturnValue().Set(info.This());
	}
	else {
		v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
		info.GetReturnValue().Set(cons->NewInstance(0, nullptr));
	}
}

//#############################################################################
//#############################################################################
void XfsDevice::Call(const Nan::FunctionCallbackInfo<v8::Value>& info) {
	if (info.Length() != 2) {
		Nan::ThrowSyntaxError("Wrong argument number.");;
		return;
	}

	if (!info[0]->IsString() || !info[1]->IsString()) {
		Nan::ThrowTypeError("Wrong argument type.");;
		return;
	}

	std::string title(*Nan::Utf8String(info[0]));
	std::string data(*Nan::Utf8String(info[1]));

	CINF << "Call " << title << " " << data;

	XfsDevice* obj = ObjectWrap::Unwrap<XfsDevice>(info.Holder());
	auto ret = obj->Command(title, data);
	info.GetReturnValue().Set(ret);
}

//#############################################################################
//#############################################################################
v8::Local<v8::Value> XfsDevice::Command(const std::string& title, const std::string& data) {
	// 
	//getTraceLevel
	if ("getTraceLevel" == title) {
		return Nan::New(GetXfsTraceLevelName(m_traceLevel)).ToLocalChecked();
	}

	//setTraceLevel
	if ("setTraceLevel" == title) {
		m_traceLevel = GetXfsTraceLevelId(data);
		return Nan::New(GetXfsTraceLevelName(m_traceLevel)).ToLocalChecked();
	}

	//getTimeOut
	if ("getTimeOut" == title) {
		return Nan::New((int)m_timeOut);
	}

	//setTimeOut
	if ("setTimeOut" == title) {
		m_timeOut = atol(data.c_str());
		return Nan::New((int)m_timeOut);
	}

	auto pmsg = new InterThreadMessage({ HSERVICE_MGR, title, data, this });
	if (!PostMessage(Window::m_lpInstance->m_hwnd, WM_NODE2WINDEV, (WPARAM)pmsg, NULL)) {
		delete pmsg;
		return Nan::New(false);
	}

	return Nan::New(true);
}

//#############################################################################
//#############################################################################
void XfsDevice::ProcessV8Message(const std::string& title, const std::string& data) {

	REQUESTID rid = 0;
	json j, jr;

	if ("query" == title) {
		XSJCallData cd;

		j.parse(data.c_str());
		jr["callId"] = j["callId"];;

		if (JS2XFS(j, cd)) {
			REQUESTID rid = 0;
			HRESULT hr = WFSAsyncGetInfo(m_service, cd.dwCommand, cd.lpData,
				cd.dwTimeout, Window::m_lpInstance->m_hwnd, &rid);

			jr["requestId"] = rid;

			if (hr == WFS_SUCCESS) {
				Window::m_lpInstance->SendToNode(m_service, "query", jr.dump(), this);
			}
			else {
				jr["result"] = GetXfsErrorCodeName(hr);
				Window::m_lpInstance->SendToNode(m_service, "query.error", jr.dump(), this);
			}
		}
		else {
			jr["result"] = "error";
			Window::m_lpInstance->SendToNode(m_service, "query.error", jr.dump(), this);
		}

		return;
	}

	if ("execute" == title) {
		XSJCallData cd;

		j.parse(data.c_str());
		jr["callId"] = j["callId"];

		if (JS2XFS(j, cd)) {
			HRESULT hr = WFSAsyncExecute(m_service, cd.dwCommand, cd.lpData, 
				cd.dwTimeout, Window::m_lpInstance->m_hwnd, &rid);

			jr["requestId"] = rid;

			if (hr == WFS_SUCCESS) {
				Window::m_lpInstance->SendToNode(m_service, "execute", jr.dump(), this);
			}
			else {
				jr["result"] = GetXfsErrorCodeName(hr);
				Window::m_lpInstance->SendToNode(m_service, "execute.error", jr.dump(), this);
			}
		}
		else {
			jr["result"] = "error";
			Window::m_lpInstance->SendToNode(m_service, "execute.error", jr.dump(), this);
		}

		return;
	}

	if ("lock" == title) {
		jr["callId"] = j["callId"];;
		DWORD timeOut = j["timeOut"];
		HRESULT hr = WFSAsyncLock(m_service, timeOut, Window::m_lpInstance->m_hwnd, &rid);
		if (hr == WFS_SUCCESS) {
			Window::m_lpInstance->SendToNode(m_service, "lock", jr.dump(), this);
		}
		else {
			jr["result"] = GetXfsErrorCodeName(hr);
			Window::m_lpInstance->SendToNode(m_service, "lock.error", jr.dump(), this);
		}
		return;
	}

	if ("unlock" == title) {
		HRESULT hr = WFSAsyncUnlock(m_service, Window::m_lpInstance->m_hwnd, &rid);

		jr["callId"] = j["callId"];
		if (hr == WFS_SUCCESS) {
			Window::m_lpInstance->SendToNode(m_service, "unlock", j.dump(), this);
		}
		else {
			jr["result"] = GetXfsErrorCodeName(hr);
			Window::m_lpInstance->SendToNode(m_service, "unlock.error", jr.dump(), this);
		}
		return;
	}

	if ("cancelRequest" == title) {
		rid = j["cancelRequest"];
		HRESULT hr = WFSCancelAsyncRequest(m_service, rid);

		jr["result"] = GetXfsErrorCodeName(hr);
		jr["callId"] = j["callId"];

		if (hr == WFS_SUCCESS) {
			Window::m_lpInstance->SendToNode(m_service, "cancelRequest", jr.dump(), this);
		}
		else {
			Window::m_lpInstance->SendToNode(m_service, "cancelRequest.error", jr.dump(), this);
		}
		return;
	}

	if ("close" == title) {
		HRESULT hr = WFSAsyncClose(m_service, Window::m_lpInstance->m_hwnd, &rid);
		jr["result"] = GetXfsErrorCodeName(hr);
		jr["callId"] = j["callId"];

		if (hr == WFS_SUCCESS) {
			Window::m_lpInstance->SendToNode(m_service, "close", jr.dump(), this);
		}
		else {
			Window::m_lpInstance->SendToNode(m_service, "close.error", jr.dump(), this);
		}
		return;
	}

	if ("register" == title) {
		DWORD cls = GetXfsEventClassId(j["eventClass"]);
		HRESULT hr = WFSRegister(m_service, cls, Window::m_lpInstance->m_hwnd);

		jr["result"] = GetXfsErrorCodeName(hr);
		jr["callId"] = j["callId"];

		if (hr == WFS_SUCCESS) {
			Window::m_lpInstance->SendToNode(m_service, "register", jr.dump(), this);
		}
		else {
			Window::m_lpInstance->SendToNode(m_service, "register.error", jr.dump(), this);
		}
		return;
	}

	if ("deregister" == title) {
		DWORD cls = GetXfsEventClassId(j["eventClass"]);
		HRESULT hr = WFSDeregister(m_service, cls, Window::m_lpInstance->m_hwnd);

		jr["result"] = GetXfsErrorCodeName(hr);
		jr["callId"] = j["callId"];
		if (hr == WFS_SUCCESS) {
			Window::m_lpInstance->SendToNode(m_service, "deregister", jr.dump(), this);
		}
		else {
			Window::m_lpInstance->SendToNode(m_service, "deregister.error", jr.dump(), this);
		}
		return;
	}
}

//#############################################################################
//#############################################################################
v8::Local<v8::Value> XfsDevice::PostNodeEvent(const std::string & title, const std::string & data) {
	v8::Local<v8::Value> argv[2] = {
		Nan::New(title).ToLocalChecked(),
		Nan::New(data).ToLocalChecked(),
	};

	return Nan::MakeCallback(Nan::New(m_this), "_post", 2, argv);
}

//#############################################################################
//#############################################################################
v8::Local<v8::Value> XfsDevice::SendNodeEvent(const std::string & title, const std::string & data) {
	v8::Local<v8::Value> argv[2] = {
		Nan::New(title).ToLocalChecked(),
		Nan::New(data).ToLocalChecked(),
	};

	return Nan::MakeCallback(Nan::New(m_this), "_send", 2, argv);
}

//#############################################################################
//#############################################################################
DefineXFSProcessor(WFS_CLOSE_COMPLETE, CloseComplete) {
	json j = XSJTranslate(pData);
	Window::m_lpInstance->SendToNode(m_service, "close.compelete", j.dump(), this);
}

//#############################################################################
//#############################################################################
DefineXFSProcessor(WFS_LOCK_COMPLETE, LockComplete) {
	json j = XSJTranslate(pData);
	Window::m_lpInstance->SendToNode(m_service, "lock.compelete", j.dump(), this);
}

//#############################################################################
//#############################################################################
DefineXFSProcessor(WFS_UNLOCK_COMPLETE, UnlockComplete) {
	json j = XSJTranslate(pData);
	Window::m_lpInstance->SendToNode(m_service, "unlock.compelete", j.dump(), this);
}

//#############################################################################
//#############################################################################
DefineXFSProcessor(WFS_REGISTER_COMPLETE, RegisterComplete) {
	json j = XSJTranslate(pData);
	Window::m_lpInstance->SendToNode(m_service, "register.compelete", j.dump(), this);
}

//#############################################################################
//#############################################################################
DefineXFSProcessor(WFS_DEREGISTER_COMPLETE, DeregisterComplete) {
	json j = XSJTranslate(pData);
	Window::m_lpInstance->SendToNode(m_service, "deregister.compelete", j.dump(), this);
}

//#############################################################################
//#############################################################################
DefineXFSProcessor(WFS_GETINFO_COMPLETE, GetInfoComplete) {
	json j;
	auto codeName = XFS2JS(XPT_Query, pData, j);
	if (codeName.length()) {
		Window::m_lpInstance->SendToNode(m_service, codeName, j.dump(), this);
	}
	else {
		j = XSJTranslate(pData);
		Window::m_lpInstance->SendToNode(m_service, "query.error", j.dump(), this);
	}
}

//#############################################################################
//#############################################################################
DefineXFSProcessor(WFS_EXECUTE_COMPLETE, ExecuteComplete) {
	json j;
	auto codeName = XFS2JS(XPT_Execute, pData, j);
	if (codeName.length()) {
		Window::m_lpInstance->SendToNode(m_service, codeName, j.dump(), this);
	}
	else {
		j = XSJTranslate(pData);
		Window::m_lpInstance->SendToNode(m_service, "execute.error", j.dump(), this);
	}
}
