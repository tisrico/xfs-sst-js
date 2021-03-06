#pragma warning(disable:4996)
#pragma warning(disable:4530)
#pragma warning(disable:4577)

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
	m_this(v8::Isolate::GetCurrent(), info.Holder()), m_syncCall(false),
	m_traceLevel(WFS_TRACE_API), m_timeOut(10000), m_service(0) {
	if (info.Length() > 0) {
		m_service = info[0]->Int32Value();
		Window::m_lpInstance->AddDevice(m_service, this);
	}

	XCINF << "new XfsDeve, service:" << m_service;
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
	Nan::SetPrototypeMethod(tpl, "__call", Call);
	
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

	XCINF << "Call " << title << " " << data;

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

	//getService
	if ("getService" == title) {
		return Nan::New((int)m_service);
	}

	//sync
	if ("sync" == title) {
		m_syncCall = true;
		return Nan::New(true);
	}

	//async
	if ("async" == title) {
		m_syncCall = false;
		return Nan::New(true);
	}

	if ("isSync" == title) {
		return Nan::New(m_syncCall);
	}

	if ("isAsync" == title) {
		return Nan::New(!m_syncCall);
	}

	if ("getVersion" == title) {
		auto vtag = "WFS_SERVICE_CLASS_VERSION_" + m_class;
		auto version = GetXfsClassVersionId(vtag);
		
		json jr;
		jr["major"] = version % 256;
		jr["minor"] = version / 256;
		jr["version"] = version;

		return Nan::New(jr.dump()).ToLocalChecked();
	}

	InterThreadMessage msg({ m_service, title, data, this });
	json jr;

	SendMessage(Window::m_lpInstance->m_hwnd, WM_NODE2WINDEV, 
		(WPARAM)&msg, (LPARAM)&jr);
	jr["asyncCall"] = !m_syncCall;

	return Nan::New(jr.dump()).ToLocalChecked();
}

//#############################################################################
//#############################################################################
HRESULT XfsDevice::ProcessV8Message(const std::string& title, const std::string& data, json& jr) {
	REQUESTID rid = 0;
	json j;
	HRESULT hr;

	XCINF << "@Window " << title << " " << data;
	j = json::parse(data.c_str());

	if (j.find("timeOut") == j.end()) {
		j["timeOut"] = m_timeOut;
	}

	j["service"] = m_service;
	jr["title"] = title;
	jr["service"] = m_service;
	jr["error"] = "WFS_SUCCESS";

	// query
	if ("query" == title) {
		XSJCallData cd;
		if (JS2XFS(j, cd)) {
			REQUESTID rid = 0;
			if (m_syncCall) {
				LPWFSRESULT lpResult = nullptr;
				hr = WFSGetInfo(m_service, cd.dwCommand, cd.lpData,
					cd.dwTimeout, &lpResult);
				if (true || hr == WFS_SUCCESS) {
					XFS2JS(XPT_Query, lpResult, jr);
				}
			}
			else {
				hr = WFSAsyncGetInfo(m_service, cd.dwCommand, cd.lpData,
					cd.dwTimeout, Window::m_lpInstance->m_hwnd, &rid);

				if (hr == WFS_SUCCESS) {
					jr["requestID"] = rid;
				}
			}
		}
		else {
			hr = XSJ_COMMAND_NOT_FOUND;
		}

		return hr;
	}

	// execute
	if ("execute" == title) {
		XSJCallData cd;
		if (JS2XFS(j, cd)) {
			if (m_syncCall) {
				LPWFSRESULT lpResult = nullptr;
				hr = WFSExecute(m_service, cd.dwCommand, cd.lpData,
					cd.dwTimeout, &lpResult);
				if (true || hr == WFS_SUCCESS) {
					XFS2JS(XPT_Execute, lpResult, jr);
				}
			}
			else {
				REQUESTID rid = 0;
				hr = WFSAsyncExecute(m_service, cd.dwCommand, cd.lpData,
					cd.dwTimeout, Window::m_lpInstance->m_hwnd, &rid);

				if (hr == WFS_SUCCESS) {
					jr["requestID"] = rid;
				}
			}
		}
		else {
			hr = XSJ_COMMAND_NOT_FOUND;
		}

		return hr;
	}

	// lock
	if ("lock" == title) {
		DWORD timeOut = j["timeOut"];
		if (m_syncCall) {
			LPWFSRESULT lpResult = nullptr;
			hr = WFSLock(m_service, timeOut, &lpResult);
			if (true || hr == WFS_SUCCESS) {
				XFS2JS(XPT_Lock, lpResult, jr);// tbd
			}
		}
		else {
			hr = WFSAsyncLock(m_service, timeOut, Window::m_lpInstance->m_hwnd, &rid);
			if (hr == WFS_SUCCESS) {
				jr["requestID"] = rid;
			}
		}
		return hr;
	}

	// unlock
	if ("unlock" == title) {
		if (m_syncCall) {
			hr = WFSUnlock(m_service);
		}
		else {
			hr = WFSAsyncUnlock(m_service, Window::m_lpInstance->m_hwnd, &rid);
			if (hr == WFS_SUCCESS) {
				jr["requestID"] = rid;
			}
		}
		return hr;
	}

	if ("cancelRequest" == title) {
		hr = WFSCancelAsyncRequest(m_service, rid);
		if (hr == WFS_SUCCESS) {
			jr["requestID"] = rid;
		}
		return hr;
	}

	if ("close" == title) {
		if (m_syncCall) {
			hr = WFSClose(m_service);
		}
		else {
			hr = WFSAsyncClose(m_service, Window::m_lpInstance->m_hwnd, &rid);
			if (hr == WFS_SUCCESS) {
				jr["requestID"] = rid;
			}
		}
		return hr;
	}

	if ("register" == title) {
		DWORD cls = GetXfsEventId(j["eventClass"]);
		if (m_syncCall) {
			hr = WFSRegister(m_service, cls, Window::m_lpInstance->m_hwnd);
		}
		else {
			hr = WFSAsyncRegister(m_service, cls, Window::m_lpInstance->m_hwnd,
				Window::m_lpInstance->m_hwnd, &rid);
			if (hr == WFS_SUCCESS) {
				jr["requestID"] = rid;
			}
		}
		return hr;
	}

	if ("deregister" == title) {
		DWORD cls = GetXfsEventId(j["eventClass"]);
		if (m_syncCall) {
			hr = WFSDeregister(m_service, cls, Window::m_lpInstance->m_hwnd);
		}
		else {
			hr = WFSAsyncDeregister(m_service, cls, Window::m_lpInstance->m_hwnd, 
				Window::m_lpInstance->m_hwnd, &rid);
			if (hr == WFS_SUCCESS) {
				jr["requestID"] = rid;
			}
		}
		return hr;
	}

	XCINF << "unsupported: " << title << " " << data;
	return XSJ_COMMAND_NOT_FOUND;
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
	XFS2JS(XPT_Lock, pData, j);
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
	std::string codeName;

	try {
		codeName = XFS2JS(XPT_Query, pData, j);
	}
	catch (...) {
		XCINF << "error in XFS2JS";
	}

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
	std::string codeName;

	j["error"] = GetXfsErrorCodeName(pData->hResult);

	try {
		codeName = XFS2JS(XPT_Execute, pData, j);
	} catch (...) {
		XCINF << "error in XFS2JS";
	}

	if (codeName.length()) {
		Window::m_lpInstance->SendToNode(m_service, codeName, j.dump(), this);
	}
	else {
		Window::m_lpInstance->SendToNode(m_service, "execute.error", j.dump(), this);
	}

}
