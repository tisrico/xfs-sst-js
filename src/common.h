#ifndef XSJ_COMMON_H
#define XSJ_COMMON_H

#include "xfsconf.h"
#include <string>

//#############################################################################
//#############################################################################
#define LPSTR(str) (const_cast<LPSTR>(std::string(str).c_str()))

//#############################################################################
//#############################################################################
inline std::string XFSReadKey(HKEY _base, const std::string& _path, const std::string& _key) {
	HKEY hKey;
	if (WFMOpenKey(_base, LPSTR(_path), &hKey)) {
		return "";
	}

	DWORD l_dwSize = 1023;
	char data[1024];
	WFMQueryValue(hKey, LPSTR(_key), data, &l_dwSize);

	WFMCloseKey(hKey);
	return std::string(data);
}

//#############################################################################
//#############################################################################

#define XFSReadLogicalServiceKey(_path, _key)								\
	XFSReadKey(WFS_CFG_MACHINE_XFS_ROOT,									\
				std::string("LOGICAL_SERVICES\\")+_path, _key)

#define XFSLSKey	XFSReadLogicalServiceKey

#endif

