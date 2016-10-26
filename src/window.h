#ifndef XSJ_WINDOW_H 
#define XSJ_WINDOW_H

#include <nan.h>
#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window: public Nan::ObjectWrap {
public:
  static void Init(v8::Local<v8::Object> exports);

private:
  explicit Window(const Nan::FunctionCallbackInfo<v8::Value>& info);
  ~Window();

  static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static void Start(const Nan::FunctionCallbackInfo<v8::Value>& info);

  static void Call(const Nan::FunctionCallbackInfo<v8::Value>& info);

  static void OnWindowMessage(uv_async_t *handle);
  bool StartThread();

  static void WinMessagePump(LPVOID p);
  static void Create(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static Nan::Persistent<v8::Function> constructor;

protected:
  uv_loop_t                  *m_loop;
  uv_async_t                  m_async;
  uv_thread_t                 m_thread_id;
  v8::Persistent<v8::Object>  m_this;
  bool                        m_sarted;
  static Window*              m_lpInstance;
};

#endif
