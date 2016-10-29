#include "xsj-trans.h"
#include <string>
#include <map>

//##############################################################################
//##############################################################################
enum XSJProcssType {
	XPT_Query,
	XPT_Execute,
	XPT_Unsolicited,
};

//##############################################################################
//##############################################################################
struct XSJCallData {
	HSERVICE 		hService;
	DWORD 			dwCommand;
	XSJProcssType 	dwType;
	DWORD 			dwTimeout;
	LPVOID 			lpData;
};

//##############################################################################
//##############################################################################
inline Translator* findTranslator(const std::string cmd, bool toXfs) {
	int size = 0;
	Translator* pTranslator = GetTranslators(size);

	for(int i=0; i<size; i++) {

		if(pTranslator->strCommand == cmd) {
			if(toXfs && pTranslator->fpToXFS) {
				return pTranslator;
			}

			if(!toXfs && pTranslator->fpToJS) {
				return pTranslator;
			}
		}
		pTranslator++;
	}
	return nullptr;
}

//##############################################################################
//##############################################################################
inline bool JS2XFS(const json& j, XSJCallData& cd) {
	if (j.find("service") == j.end() || j.find("command") == j.end() ||
		j.find("timeout") == j.end() ||	j.find("data") == j.end()) {
		return false;
	}

	if(!j["service"].is_number() || !j["command"].is_string() ||
		!j["timeout"].is_number() || !j["data"].is_object()) {
		return false;
	}

	std::string strCommand = j["command"];
	cd.hService = j["service"];
	cd.dwTimeout = j["timeout"];
	cd.dwType = (strCommand.find("XFS_INF") == 0)?XPT_Query:XPT_Execute;
	if(cd.dwType == XPT_Query) {
		cd.dwCommand = GetXfsInfoCmdId(strCommand);
	}
	else {
		cd.dwCommand = GetXfsExecuteCmdId(strCommand);
	}

	auto pTranslator = findTranslator(strCommand, true);
	if(pTranslator) {
		cd.lpData = pTranslator->fpToXFS(j["data"]);
	}

	return true;
}

//##############################################################################
//##############################################################################
inline std::string XFS2JS(XSJProcssType pt, const LPWFSRESULT result, json& j) {
	if(result == nullptr) {
		return "";
	}

	std::string strCommand;
	if(pt == XPT_Query) {
		strCommand = GetXfsInfoCmdName(result->u.dwCommandCode);
	}
	else if(pt == XPT_Execute) {
		strCommand = GetXfsExecuteCmdName(result->u.dwCommandCode);
	}
	else {
		strCommand = GetXfsEventName(result->u.dwEventID);	
	}

	j = XSJTranslate<WFSRESULT>(result);
	j["type"] = strCommand;

	auto pTranslator = findTranslator(strCommand, false);
	if(pTranslator) {
		j["result"] = pTranslator->fpToJS(result->lpBuffer);
	}
	else {
		j["result"] = std::map<std::string, std::string>();
	}

	return pTranslator->strCodeName;
}