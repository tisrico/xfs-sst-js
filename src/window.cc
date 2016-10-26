#include "Window.h"
#include <uv.h>

Nan::Persistent<v8::Function> Window::constructor;
Window* Window::m_lpInstance = nullptr;

Window::Window(const Nan::FunctionCallbackInfo<v8::Value>& info):
	m_this(v8::Isolate::GetCurrent(), info.Holder()), m_sarted(false){
}

Window::~Window() {
}

void Window::Init(v8::Local<v8::Object> exports) {
	Nan::HandleScope scope;

	// Prepare constructor template
	v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
	tpl->SetClassName(Nan::New("XfsMgr").ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	Nan::SetPrototypeMethod(tpl, "__start", Start);
	Nan::SetPrototypeMethod(tpl, "__call", Start);

	
	constructor.Reset(tpl->GetFunction());
	exports->Set(Nan::New("XfsMgr").ToLocalChecked(), tpl->GetFunction());
}

void Window::New(const Nan::FunctionCallbackInfo<v8::Value>& info) {
	if (info.IsConstructCall()) {
		assert(!m_lpInstance);
		m_lpInstance = new Window(info);
		m_lpInstance->Wrap(info.This());
		info.GetReturnValue().Set(info.This());
	}
	else {
		v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
		info.GetReturnValue().Set(cons->NewInstance(0, nullptr));
	}
}

void Window::Start(const Nan::FunctionCallbackInfo<v8::Value>& info) {
	Nan::EscapableHandleScope scope;
	Window* obj = ObjectWrap::Unwrap<Window>(info.Holder());

	v8::Local<v8::Value> argv[2] = {
		Nan::New("window").ToLocalChecked(),
		Nan::New("started").ToLocalChecked(),
	};
	Nan::MakeCallback(info.Holder(), "post", 2, argv);

	obj->StartThread();
}

bool Window::StartThread() {
	if(!m_sarted) {
		m_loop = uv_default_loop();
		uv_async_init(m_loop, &m_async, OnWindowMessage);
		m_async.data = this;

		uv_thread_create(&m_thread_id, WinMessagePump, this);
		// post message....
		m_sarted = true;
		return true;
	}

	return false;
}

void Window::OnWindowMessage(uv_async_t *handle) {
	v8::HandleScope scope(v8::Isolate::GetCurrent());
	Window* pWindow = (Window*)handle->data;

	v8::Local<v8::Value> argv[2] = {
		Nan::New("window").ToLocalChecked(),
		Nan::New("closed").ToLocalChecked(),
	};
	
	Nan::MakeCallback(Nan::New(pWindow->m_this), "post", 2, argv);

	uv_close((uv_handle_t*)handle, nullptr);
}

void Window::WinMessagePump(LPVOID p) {
	Window* pThis = (Window*)p;

	const char CLASS_NAME[] = "Sample Window Class";

	WNDCLASS wc = {};

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = nullptr; // hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	// Create the window.

	HWND hwnd = CreateWindowEx(
		0,                              // Optional window styles.
		CLASS_NAME,                     // Window class
		"Sample Window",    			// Window text
		WS_OVERLAPPEDWINDOW,            // Window style
										// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,       // Parent window    
		NULL,       // Menu
		NULL, //hInstance,  // Instance handle
		NULL        // Additional application data
	);

	if (hwnd == NULL) {
		return;
	}

	ShowWindow(hwnd, SW_SHOW);

	// Run the message loop.

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	uv_async_send(&pThis->m_async);
	return;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &ps);
	}
	return 0;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void Window::Create(const Nan::FunctionCallbackInfo<v8::Value>& info) {
	Window* obj = ObjectWrap::Unwrap<Window>(info.Holder());
}
