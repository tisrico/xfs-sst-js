#pragma warning(disable:4996)
#pragma warning(disable:4530)
#pragma warning(disable:4577)

#include "Window.h"
#include <uv.h>
#include "xsj-trans.h"
#include "xfsapi.h"
#include "common.h"
#include "json.hpp"
#include "xfsdevice.h"

using json = nlohmann::json;

//#############################################################################
//#############################################################################
std::string str_toupper(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return std::toupper(c); }
	);
	return s;
}

//#############################################################################
//#############################################################################
#define DefineXFSProcessor(evt, proc) void Window::proc(LPWFSRESULT pData)

//#############################################################################
//#############################################################################
Nan::Persistent<v8::Function> Window::constructor;
Window* Window::m_lpInstance = nullptr;
DWORD Window::m_nodeThread = GetCurrentThreadId();

//#############################################################################
//#############################################################################
Window::Window(const Nan::FunctionCallbackInfo<v8::Value>& info):
	m_this(v8::Isolate::GetCurrent(), info.Holder()), m_sarted(false), 
	m_hwnd(nullptr), m_traceLevel(WFS_TRACE_API), m_timeOut(10000), m_loop(nullptr),
	m_xfsStarted(false) {
}

//#############################################################################
//#############################################################################
Window::~Window() {
}

//#############################################################################
//#############################################################################
void Window::Init(v8::Local<v8::Object> exports) {
	Nan::HandleScope scope;

	// Prepare constructor template
	v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
	tpl->SetClassName(Nan::New("XfsMgr").ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	Nan::SetPrototypeMethod(tpl, "__call", Call);

	constructor.Reset(tpl->GetFunction());
	exports->Set(Nan::New("XfsMgr").ToLocalChecked(), tpl->GetFunction());
}

//#############################################################################
//#############################################################################
bool Window::IsNodeThread() {
	return Window::m_nodeThread == GetCurrentThreadId();
}

//#############################################################################
//#############################################################################
void Window::New(const Nan::FunctionCallbackInfo<v8::Value>& info) {
	if (info.IsConstructCall()) {
		assert(nullptr == m_lpInstance);
		m_lpInstance = new Window(info);
		m_lpInstance->Wrap(info.This());
		info.GetReturnValue().Set(info.This());
	}
	else {
		v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
		info.GetReturnValue().Set(cons->NewInstance(0, nullptr));
	}
}

//#############################################################################
//#############################################################################
bool Window::StartThread() {
	if(!m_sarted) {
		PostNodeEvent("win.start", "");
		m_sarted = true;

		m_loop = uv_default_loop();
		uv_async_init(m_loop, &m_async, OnNodeMessage);
		m_async.data = new MessageQueue();

		uv_thread_create(&m_thread_id, WinMessagePump, this);
		return m_sarted;
	}

	Nan::ThrowError("XFS Manager started.");;
	return false;
}

//#############################################################################
// processing messages from Window to Node
//#############################################################################
void Window::OnNodeMessage(uv_async_t *handle) {
	if (!handle->data) {
		return;
	}

	InterThreadMessage* pMessage = nullptr;
	(*(MessageQueue*)handle->data) >> pMessage;

	while(nullptr != pMessage) {
		ProcessNodeMessage(pMessage);

		if (pMessage->strTitle == "win.exit") {
			((Window*)pMessage->lpData)->m_sarted = false;
			uv_close((uv_handle_t*)handle, nullptr);
			delete handle->data;
			handle->data = nullptr;
			break;
		}

		pMessage = nullptr;
		(*(MessageQueue*)handle->data) >> pMessage;
	}

}

//#############################################################################
// process messages from Window to Node
//#############################################################################
void Window::ProcessNodeMessage(InterThreadMessage* pMessage)
{
	v8::HandleScope scope(v8::Isolate::GetCurrent());
	v8::Local<v8::Value> argv[2] = {
		Nan::New(pMessage->strTitle).ToLocalChecked(),
		Nan::New(pMessage->strData).ToLocalChecked(),
	};
	
	if (pMessage->strTitle.find("console.") != -1) {
		((Window*)pMessage->lpData)->SendNodeEvent(pMessage->strTitle, pMessage->strData);
		return;
	}

	if (HSERVICE_MGR == pMessage->hService) {
		((Window*)pMessage->lpData)->PostNodeEvent(pMessage->strTitle, pMessage->strData);
	}
	else {
		XfsDevice* pDevice = nullptr;
		if (pMessage && Window::m_lpInstance) {
			auto it = Window::m_lpInstance->m_services.find(pMessage->hService);
			if (it != Window::m_lpInstance->m_services.end()) {
				pDevice = it->second;
				pDevice->PostNodeEvent(pMessage->strTitle, pMessage->strData);
			}
		}
	}
}

//#############################################################################
//#############################################################################
void Window::WinMessagePump(LPVOID p) {
	Window* pThis = (Window*)p;
	const char CLASS_NAME[] = "XSJ Window Class";
	WNDCLASS wc = {};

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = nullptr; // hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);
	HWND hwnd = CreateWindowEx(
		0,                              // Optional window styles.
		CLASS_NAME,                     // Window class
		"XSJ Window",    				// Window text
		WS_OVERLAPPEDWINDOW,            // Window style
										// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,       // Parent window    
		NULL,       // Menu
		NULL, //hInstance,  // Instance handle
		NULL        // Additional application data
	);

	if (hwnd == NULL) {
		CASS(hwnd != NULL) << "Can't create Window: 0x" << std::hex << GetLastError();
		return;
	}

	pThis->m_hwnd = hwnd;
	ShowWindow(hwnd, SW_HIDE);

	// Run the message loop.
	CINF << "Start Windows Messaging Pump";
	MSG msg = {};

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	pThis->SendToNode(HSERVICE_MGR, "win.exit", "", pThis);
	return;
}

//#############################################################################
//#############################################################################
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LPWFSRESULT pData = (LPWFSRESULT)lParam;
	XfsDevice* pDevice = nullptr;

	if ((uMsg >= WFS_OPEN_COMPLETE && uMsg <= WFS_SYSTEM_EVENT) && 
		pData && Window::m_lpInstance) {

		auto it = Window::m_lpInstance->m_services.find(pData->hService);
		if (it != Window::m_lpInstance->m_services.end()) {
			pDevice = it->second;
		}
	}

	switch (uMsg) {
	case WM_CREATE:
		if (Window::m_lpInstance) {
			Window::m_lpInstance->SendToNode(HSERVICE_MGR, "initialize", "", Window::m_lpInstance);
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
	}

	// node to device manager
	case WM_NODE2WIN:	{
		auto pmsg = (InterThreadMessage*)wParam;
		if (pmsg) {
			XCINF <<  pmsg->strTitle << ":" << pmsg->strData;
		}

		if(pmsg && pmsg->hService == HSERVICE_MGR && 
			pmsg->lpData == Window::m_lpInstance && Window::m_lpInstance != nullptr) {

			json& j = *(json*)lParam;
			auto result = Window::m_lpInstance->ProcessV8Message(pmsg, j);
			j["title"] = pmsg->strTitle;
			j["error"] = GetXfsErrorCodeName(result);
			j["success"] = (result == WFS_SUCCESS);
			return result;
		}

		break;
	}

	// node to a device
	case WM_NODE2WINDEV: {
		auto pmsg = (InterThreadMessage*)wParam;
		if (pmsg) {
			XCINF << pmsg->strTitle << ":" << pmsg->strData;
		}
		if (pmsg && pmsg->hService != HSERVICE_MGR && lParam &&
			pmsg->lpData != nullptr) {
			XfsDevice* pDevice = (XfsDevice*)pmsg->lpData;
			json& j = *(json*)lParam;

			auto result = pDevice->ProcessV8Message(pmsg->strTitle, pmsg->strData, j);

			j["title"] = pmsg->strTitle;
			j["error"] = GetXfsErrorCodeName(result);
			j["success"] = (result == WFS_SUCCESS);
			return result;
		}
		break;
	}

	XFSDeviceProcessorEntry(WFS_CLOSE_COMPLETE, CloseComplete);
	XFSDeviceProcessorEntry(WFS_LOCK_COMPLETE, LockComplete);
	XFSDeviceProcessorEntry(WFS_UNLOCK_COMPLETE, UnlockComplete);
	XFSDeviceProcessorEntry(WFS_REGISTER_COMPLETE, RegisterComplete);
	XFSDeviceProcessorEntry(WFS_DEREGISTER_COMPLETE, DeregisterComplete);
	XFSDeviceProcessorEntry(WFS_GETINFO_COMPLETE, GetInfoComplete);
	XFSDeviceProcessorEntry(WFS_EXECUTE_COMPLETE, ExecuteComplete);

	XFSProcessorEntry(WFS_OPEN_COMPLETE, OpenComplete);
	XFSProcessorEntry(WFS_EXECUTE_EVENT, ExecuteEvent);
	XFSProcessorEntry(WFS_SERVICE_EVENT, ServiceEvent);
	XFSProcessorEntry(WFS_USER_EVENT, UserEvent);
	XFSProcessorEntry(WFS_SYSTEM_EVENT, SystemEvent);
	XFSProcessorEntry(WFS_TIMER_EVENT, TimerEvent);
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

//#############################################################################
//#############################################################################
void Window::Call(const Nan::FunctionCallbackInfo<v8::Value>& info) {
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

	Window* obj = ObjectWrap::Unwrap<Window>(info.Holder());
	auto ret = obj->Command(title, data);
	info.GetReturnValue().Set(ret);
}

//#############################################################################
//#############################################################################
v8::Local<v8::Value> Window::Command(const std::string & title, const std::string & data) {
	json j;
	if ("initialize" == title) {
		j = StartThread();
		return Nan::New(j.dump()).ToLocalChecked();
	}

	if (!m_sarted) {
		Nan::ThrowError("XFS Manager not started.");;
		return Nan::New(j.dump()).ToLocalChecked();
	}

	//getTraceLevel
	if ("getTraceLevel" == title) {
		j = GetXfsTraceLevelName(m_traceLevel);
		return Nan::New(j.dump()).ToLocalChecked();
	}

	//setTraceLevel
	if ("setTraceLevel" == title) {
		m_traceLevel = GetXfsTraceLevelId(data);
		j = GetXfsTraceLevelName(m_traceLevel);
		return Nan::New(j.dump()).ToLocalChecked();
	}

	//getTimeOut
	if ("getTimeOut" == title) {
		j = m_timeOut;
		return Nan::New(j.dump()).ToLocalChecked();
	}

	//setTimeOut
	if ("setTimeOut" == title) {
		m_timeOut = atol(data.c_str());
		j = m_timeOut;
		return Nan::New(j.dump()).ToLocalChecked();
	}

	if (!m_hwnd) {
		Nan::ThrowError("XFS Manager is starting...");;
		return Nan::New(j.dump()).ToLocalChecked();
	}

	// start
	// cleanUp
	// open, 
	// uninitialize

	auto msg = InterThreadMessage({ HSERVICE_MGR, title, data, this});
	json jr;

	SendMessage(m_hwnd, WM_NODE2WIN, (WPARAM)&msg, (LPARAM)&jr);

	if (title == "open") {
		auto clss = jr["class"].get<std::string>();
		auto logicalName = jr["logicalName"].get<std::string>();
		auto hService = jr["service"];
		m_serviceInformation[hService] = DeviceInformation({ clss , logicalName });
	}

	return Nan::New(jr.dump()).ToLocalChecked();
}

//#############################################################################
//#############################################################################
HRESULT Window::ProcessV8Message(InterThreadMessage* pmsg, json& jr) {
	if (!pmsg) {
		return XSJ_INVALID_DATA;
	}

	XCINF << "@Window " << pmsg->strTitle << " " << pmsg->strData;
	json j = json::parse(pmsg->strData);
	HRESULT hr;

	// open a logic device
	if (pmsg->strTitle == "open") {
		if (!m_xfsStarted) {
			hr = XSJ_INVALID_STATE;
			jr["errorMessage"] = "XFS not started";
			return hr;
		}

		DWORD dwVersionsRequired = j["versionsRequired"];
		std::string logicalName = j["logicalName"];
		HAPP appHandle = (HAPP)((int)j["appHandle"]);
		std::string appId = j["appId"];
		DWORD traceLevel = GetXfsTraceLevelId(j["traceLevel"]);
		DWORD timeOut = j["timeOut"];

		WFSVERSION srvcVersion;
		WFSVERSION spiVersion;
		HSERVICE   hService;
		REQUESTID requestID;

		hr = WFSAsyncOpen(const_cast<char *>(logicalName.c_str()), appHandle,
			(appId=="_no_used")?NULL:const_cast<char *>(appId.c_str()), traceLevel, timeOut,
			&hService, m_hwnd, dwVersionsRequired, &srvcVersion, &spiVersion, &requestID);

		if (WFS_SUCCESS != hr) {
			jr["errorMessage"] = "xfs not started";
			return hr;
		}

		jr["service"] = (int)hService;
		jr["serviceVersion"] = XSJTranslate(&srvcVersion);
		jr["spiVersion"] = XSJTranslate(&spiVersion);
		jr["requestID"] = requestID;
		jr["class"] = str_toupper(XFSLSKey(logicalName, "class"));
		jr["logicalName"] = logicalName;

		return hr;
	}

	// start xfs manager
	if (pmsg->strTitle == "start") {
		if (m_xfsStarted) {
			hr = XSJ_INVALID_STATE;
			jr["errorMessage"] = "XFS started";
			return hr;
		}

		DWORD dwVersionsRequired = j["versionRequired"];
		WFSVERSION version = { 0 };

		hr = WFSStartUp(dwVersionsRequired, &version);
		if (WFS_SUCCESS != hr) {
			return hr;
		}

		m_xfsStarted = true;
		jr = XSJTranslate(&version);
		return hr;
	}

	// cleanUp xfs manager
	if (pmsg->strTitle == "cleanUp") {
		if (!m_xfsStarted) {
			jr["errorMessage"] = "XFS not started";
			return XSJ_INVALID_STATE;
		}

		HRESULT hr = WFSCleanUp();
		if (WFS_SUCCESS != hr) {
			return hr;
		}

		m_xfsStarted = false;
		return hr;
	}

	// uninitialize, shutdown window thread
	if (pmsg->strTitle == "uninitialize") {
		if (m_xfsStarted) {
			jr["errorMessage"] = "XFS is running";
			return XSJ_INVALID_STATE;
		}

		PostMessage(((Window*)pmsg->lpData)->m_hwnd, WM_CLOSE, NULL, NULL);
		return WFS_SUCCESS;
	}

	// createAppHandle
	if ("createAppHandle" == pmsg->strTitle) {
		HAPP handle;
		hr = WFSCreateAppHandle(&handle);

		if (WFS_SUCCESS != hr) {
			return hr;
		}

		jr = XSJTranslate(handle);
		return hr;
	}

	// destroyAppHandle
	if ("destroyAppHandle" == pmsg->strTitle) {
		HAPP handle = (HAPP)atol(pmsg->strData.c_str());
		return WFSDestroyAppHandle(&handle);
	}

	CERR << "unsupported command:" << pmsg->strTitle << " " << pmsg->strData;

	hr = XSJ_COMMAND_NOT_FOUND;
	jr["error"] = GetXfsErrorCodeName(hr);
	jr["title"] += ".error";
	return hr;
}

//#############################################################################
// send message from Window thread to Node thread
//#############################################################################
void Window::SendToNode(HSERVICE hService, const std::string& title, const std::string& data, LPVOID lpData) {
	auto pReturn = new InterThreadMessage({ hService,title, data, lpData });
	(*(MessageQueue*)m_async.data) << pReturn;
	uv_async_send(&m_async);
}

//#############################################################################
// post message to Node event mechanism, the event is actually emitted with a
// dealy of setImmediate
//#############################################################################
v8::Local<v8::Value> Window::PostNodeEvent(const std::string & title, const std::string & data) {
	v8::Local<v8::Value> argv[2] = {
		Nan::New(title).ToLocalChecked(),
		Nan::New(data).ToLocalChecked(),
	};
	return Nan::MakeCallback(Nan::New(m_this), "_post", 2, argv);
}

//#############################################################################
// send message to Node event mechanism
//#############################################################################
v8::Local<v8::Value> Window::SendNodeEvent(const std::string & title, const std::string & data) {
	v8::Local<v8::Value> argv[2] = {
		Nan::New(title).ToLocalChecked(),
		Nan::New(data).ToLocalChecked(),
	};
	return Nan::MakeCallback(Nan::New(m_this), "_send", 2, argv);
}

//#############################################################################
//#############################################################################
void Window::AddDevice(HSERVICE hService, XfsDevice* pDevice) {
	m_services[hService] = pDevice;
	auto info = m_serviceInformation[hService];
	pDevice->m_class = info.m_class;
	pDevice->m_logicalName = info.m_logicalName;
}

//#############################################################################
// at the moment of open call, node side doesn't know the service id
// so when completed, it has to be sent to the manager
//#############################################################################
DefineXFSProcessor(WFS_OPEN_COMPLETE, OpenComplete) {
	//pData
	json j = XSJTranslate(pData);
	SendToNode(HSERVICE_MGR, "open.complete", j.dump(), this);
}

//#############################################################################
//#############################################################################
DefineXFSProcessor(WFS_EXECUTE_EVENT, ExecuteEvent) {

}

//#############################################################################
//#############################################################################
DefineXFSProcessor(WFS_SERVICE_EVENT, ServiceEvent) {

}

//#############################################################################
//#############################################################################
DefineXFSProcessor(WFS_USER_EVENT, UserEvent) {

}

//#############################################################################
//#############################################################################
DefineXFSProcessor(WFS_SYSTEM_EVENT, SystemEvent) {

}

//#############################################################################
//#############################################################################
DefineXFSProcessor(WFS_TIMER_EVENT, TimerEvent) {

}