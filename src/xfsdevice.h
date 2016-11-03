#ifndef XSJ_XFS_DEVICE_H 
#define XSJ_XFS_DEVICE_H

#include <nan.h>
#include <windows.h>
#include "xfsapi.h"
#include "json.hpp"

//#############################################################################
//#############################################################################
#define DeclareXFSProcessor(evt, proc) void proc(LPWFSRESULT pData);

//#############################################################################
//#############################################################################
class XfsDevice: public Nan::ObjectWrap {
public:
  static void Init(v8::Local<v8::Object> exports);
  v8::Local<v8::Value> PostNodeEvent(const std::string& title, const std::string& data);
  v8::Local<v8::Value> SendNodeEvent(const std::string& title, const std::string& data);
  v8::Local<v8::Value> XfsDevice::Command(const std::string& title, const std::string& data);
  HRESULT ProcessV8Message(const std::string& title, const std::string& data, nlohmann::json& jr);

  DeclareXFSProcessor(WFS_CLOSE_COMPLETE, CloseComplete);
  DeclareXFSProcessor(WFS_LOCK_COMPLETE, LockComplete);
  DeclareXFSProcessor(WFS_UNLOCK_COMPLETE, UnlockComplete);
  DeclareXFSProcessor(WFS_REGISTER_COMPLETE, RegisterComplete);
  DeclareXFSProcessor(WFS_DEREGISTER_COMPLETE, DeregisterComplete);
  DeclareXFSProcessor(WFS_GETINFO_COMPLETE, GetInfoComplete);
  DeclareXFSProcessor(WFS_EXECUTE_COMPLETE, ExecuteComplete);

private:
  explicit XfsDevice(const Nan::FunctionCallbackInfo<v8::Value>& info);
  ~XfsDevice();

  static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static Nan::Persistent<v8::Function> constructor;

  static void Call(const Nan::FunctionCallbackInfo<v8::Value>& info);

protected:
  v8::Persistent<v8::Object>	m_this;
  HSERVICE						m_service;
  DWORD							m_traceLevel;
  DWORD							m_timeOut;
  bool							m_syncCall;
};

#endif
