#ifndef XSJ_XFS_DEVICE_H 
#define XSJ_XFS_DEVICE_H

#include <nan.h>
#include <windows.h>

class XfsDevice: public Nan::ObjectWrap {
public:
  static void Init(v8::Local<v8::Object> exports);

private:
  explicit XfsDevice(const Nan::FunctionCallbackInfo<v8::Value>& info);
  ~XfsDevice();

  static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static Nan::Persistent<v8::Function> constructor;

  static void Call(const Nan::FunctionCallbackInfo<v8::Value>& info);

  protected:
  v8::Persistent<v8::Object>  m_this;
};

#endif
