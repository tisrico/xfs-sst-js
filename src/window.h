#ifndef XSJ_WINDOW_H 
#define XSJ_WINDOW_H

#include <nan.h>
#include <windows.h>
#include "xfsapi.h"
#include <string>
#include <iostream>
#include <sstream>
#include <queue>
#include <uv.h>
#include <map>
#include "json.hpp"

//#############################################################################
//#############################################################################
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//#############################################################################
//#############################################################################
class InterThreadMessage {
public:
	HSERVICE		hService;
	std::string		strTitle;
	std::string		strData;
	LPVOID			lpData;
};

//#############################################################################
//#############################################################################
#define HSERVICE_MGR	HSERVICE(-1)
#define WM_NODE2WIN		(WM_USER + 30)
#define WM_NODE2WINDEV	(WM_USER + 31)

//#############################################################################
//#############################################################################
#define XFSProcessorEntry(evt, proc)				\
	case evt: {										\
		if (pData) {								\
			if(Window::m_lpInstance) {				\
				Window::m_lpInstance->proc(pData);	\
			}										\
			WFSFreeResult(pData);					\
		}											\
		break;										\
	}

//#############################################################################
//#############################################################################
#define XFSDeviceProcessorEntry(evt, proc)		\
	case evt: {									\
		if (pDevice) {							\
				pDevice->proc(pData);			\
			}									\
		WFSFreeResult(pData);					\
		break;									\
	}
//#############################################################################
//#############################################################################
class Log;
class XfsDevice;

//#############################################################################
//#############################################################################
#define DeclareXFSProcessor(evt, proc) void proc(LPWFSRESULT pData);

//#############################################################################
//#############################################################################
class Window: public Nan::ObjectWrap {
public:
  static void Init(v8::Local<v8::Object> exports);
  static bool IsNodeThread();

  v8::Local<v8::Value> PostNodeEvent(const std::string& title, const std::string& data);
  v8::Local<v8::Value> SendNodeEvent(const std::string& title, const std::string& data);
  void AddDevice(HSERVICE hService, XfsDevice* pDevice);

  DeclareXFSProcessor(WFS_OPEN_COMPLETE, OpenComplete);
  DeclareXFSProcessor(WFS_EXECUTE_EVENT, ExecuteEvent);
  DeclareXFSProcessor(WFS_SERVICE_EVENT, ServiceEvent);
  DeclareXFSProcessor(WFS_USER_EVENT, UserEvent);
  DeclareXFSProcessor(WFS_SYSTEM_EVENT, SystemEvent);
  DeclareXFSProcessor(WFS_TIMER_EVENT, TimerEvent);

private:
  explicit Window(const Nan::FunctionCallbackInfo<v8::Value>& info);
  ~Window();

  static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static void Call(const Nan::FunctionCallbackInfo<v8::Value>& info);
  
  v8::Local<v8::Value> Command(const std::string& title, const std::string& data);
  HRESULT ProcessV8Message(InterThreadMessage* pMessage, nlohmann::json& jr);
  static void ProcessNodeMessage(InterThreadMessage* pMessage);

  void SendToNode(HSERVICE hService, const std::string& title, const std::string& data, LPVOID lpData);

  bool StartThread();
  static void OnNodeMessage(uv_async_t *handle);
  static void WinMessagePump(LPVOID p);
  static Nan::Persistent<v8::Function> constructor;

  friend LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
  friend class SimpleLog;
  friend class XfsDevice;

protected:
  uv_loop_t                  *m_loop;
  uv_async_t                  m_async;
  uv_thread_t                 m_thread_id;
  v8::Persistent<v8::Object>  m_this;
  bool                        m_sarted;
  bool						  m_xfsStarted;
  DWORD						  m_traceLevel;
  DWORD						  m_timeOut;
  HWND						  m_hwnd;

  static DWORD				  m_nodeThread;
  static Window*              m_lpInstance;
  std::map<HSERVICE, XfsDevice*> m_services;
};

//#############################################################################
//#############################################################################
class SimpleLog : public std::stringstream {
public:
	SimpleLog(const std::string& type_ = "log", bool cond_ = true, const std::string express_="") {
		type = "console." + type_;
		condition = cond_;
		express = express_;
	}
	~SimpleLog() {
		if (condition && type == "console.assert") {
			return;
		}

		std::string log = std::stringstream::str();
		if (express.length() && !condition) {
			log = "(" + express + ") => " + log;
		}

		if (!Window::m_lpInstance) {
			OutputDebugString(log.c_str());
			return;
		}

		if (Window::IsNodeThread()) {
			Window::m_lpInstance->SendNodeEvent(type, log);
		}
		else {
			log = "(*)" + log;
			Window::m_lpInstance->SendToNode(HSERVICE_MGR, type, log, Window::m_lpInstance);
		}
	}

	std::string		type;
	bool			condition;
	std::string		express;
};

//#############################################################################
//#############################################################################
//#define CLOG		(SimpleLog("log"))   // app
#define CWAR		(SimpleLog("warn"))
#define CINF		(SimpleLog("info"))
//#define CTRAC		(SimpleLog("trace")) // app
#define CERR		(SimpleLog("error"))
#define CASS(c)		(SimpleLog("assert", (c), (#c)))
#define XCINF		((SimpleLog("info")) << "[" <<__FUNCTION__ << ", line:" << __LINE__ << "] " )

//#############################################################################
//#############################################################################
class MessageQueue : protected std::queue<InterThreadMessage*> {
public:
	MessageQueue() {
		uv_mutex_init(&handle);
	}
	~MessageQueue() {
		uv_mutex_destroy(&handle);
	}
	MessageQueue& operator <<(InterThreadMessage* message) {
		uv_mutex_lock(&handle);
		push(message);
		uv_mutex_unlock(&handle);
		return *this;
	}

	MessageQueue& operator >>(InterThreadMessage* &message) {
		message = nullptr;
		uv_mutex_lock(&handle);
		if (size()) {
			message = front();
			pop();
		}
		uv_mutex_unlock(&handle);
		return *this;
	}

protected:
	uv_mutex_t handle;
};


#endif
