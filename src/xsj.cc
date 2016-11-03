#pragma warning(disable:4996)
#pragma warning(disable:4530)
#pragma warning(disable:4577)

#include <nan.h>
#include "window.h"
#include "xfsdevice.h"

void module(v8::Local<v8::Object> exports) {
	Window::Init(exports);
	XfsDevice::Init(exports);
}

NODE_MODULE(xsj, module)
