#include "xfsdevice.h"
#include <uv.h>

Nan::Persistent<v8::Function> XfsDevice::constructor;

XfsDevice::XfsDevice(const Nan::FunctionCallbackInfo<v8::Value>& info):
	m_this(v8::Isolate::GetCurrent(), info.Holder()){
}

XfsDevice::~XfsDevice() {
}

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

void XfsDevice::Call(const Nan::FunctionCallbackInfo<v8::Value>& info) {
	Nan::EscapableHandleScope scope;
	XfsDevice* obj = ObjectWrap::Unwrap<XfsDevice>(info.Holder());

	v8::Local<v8::Value> argv[2] = {
		Nan::New("window").ToLocalChecked(),
		Nan::New("start").ToLocalChecked(),
	};
	Nan::MakeCallback(info.Holder(), "post", 2, argv);
}

