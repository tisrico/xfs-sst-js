#include <nan.h>
#include "window.h"
#include "xfsdevice.h"

void module(v8::Local<v8::Object> exports) {
	Window::Init(exports);
	XfsDevice::Init(exports);
}

NODE_MODULE(xsj, module)
