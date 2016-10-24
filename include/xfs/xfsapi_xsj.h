#include "xfsapi.h"

enum XSJCallType {
	XCT_Execute,
	XCT_Query,
};

struct XSJCallData {
	HSERVICE hService;
	DWORD dwCommand;
	XSJCallType dwType;
	DWORD dwTimeout;
	LPVOID lpData;
};


struct 