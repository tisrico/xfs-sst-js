#include <time.h>
#include <windows.h>
#include <sstream>
#include <iomanip>
#include "xfsapi.h"

std::string SystemTime2String(const SYSTEMTIME *st) {
	std::stringstream oss;
	oss << st->wYear << ":" 
	<< std::setw(2) << std::setfill('0') << st->wMonth << ":" 
	<< std::setw(2) << std::setfill('0') << st->wDay << " "
	<< std::setw(2) << std::setfill('0') << st->wHour << ":"
	<< std::setw(2) << std::setfill('0') << st->wMinute << ":"
	<< std::setw(2) << std::setfill('0') << st->wSecond;

	return oss.str();
}

std::vector<std::string> list2Strings(LPCSTR pList) {
	std::vector<std::string> list;
	LPCSTR pp = pList;
	while(pp && *pp) {
		std::string name;
		while(*pp) {
			name += *pp;
			pp++;
		}
		list.push_back(name);
	}

	return list;
}

/*
// xfs-sst-js:{name:"data", type: "SYSTEMTIME", codeName: "SysteTime", leading:1, output:true, input:false, command:"", directCopy:true}
	j = SystemTime2String(p);
// xfs-sst-js:{name:"end"}
*/

typedef struct {
	LPSTR lpszFormList;
} WFSPTRFORMLIST, *LPWFSPTRFORMLIST;
/*
// xfs-sst-js:{name:"data", type: "WFSPTRFORMLIST", codeName: "PtrFormlist", leading:1, output:true, input:false, command:"WFS_INF_PTR_FORM_LIST", directCopy:true}
	return j = list2Strings(p->lpszFormList);
// xfs-sst-js:{name:"end"}
*/

typedef struct {
	LPSTR lpszMediaList;
} WFSPTRMEDIALIST, *LPWFSPTRMEDIALIST;
/*
// xfs-sst-js:{name:"data", type: "WFSPTRMEDIALIST", codeName: "PtrMedialist", leading:1, output:true, input:false, command:"WFS_INF_PTR_MEDIA_LIST"}
	return j = list2Strings(p->lpszMediaList);
// xfs-sst-js:{name:"end"}
*/

typedef struct {
	LPDWORD lpdwMediaControl;
} WFSPTRMEDIACONTROL, *LPWFSPTRMEDIACONTROL;
// xfs-sst-js:{name:"data", type: "WFSPTRMEDIACONTROL", codeName: "PtrMediaControl", leading:1, output:false, input:true, command:"WFS_CMD_PTR_CONTROL_MEDIA"}
// xfs-sst-js:{name:"end"}

typedef struct {
	LPUSHORT lpusBinNumber;
} WFSPTRRESETCOUNT, *LPWFSPTRRESETCOUNT;
// xfs-sst-js:{name:"data", type: "WFSPTRRESETCOUNT", codeName: "PtrResetCount", leading:1, output:false, input:true, command:"WFS_CMD_PTR_RESET_COUNT"}
// xfs-sst-js:{name:"end"}

typedef struct {
	LPUSHORT lpusBinNumber;
} WFSPTRRETRACTMEDIA, *LPWFSPTRRETRACTMEDIA;
// xfs-sst-js:{name:"data", type: "WFSPTRRETRACTMEDIA", codeName: "PtrRetractMedia", leading:1, output:true, input:true, command:"WFS_CMD_PTR_RETRACT_MEDIA"}
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type: "WFSPTRDISPENSEPAPER", codeName: "PtrDispensePaper", leading:1, output:false, input:true, command:"WFS_CMD_PTR_DISPENSE_PAPER"}
typedef struct {
	WORD wPaperSource;									// xfs-sst-js:{name:"data.field"}
} WFSPTRDISPENSEPAPER, *LPWFSPTRDISPENSEPAPER;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type: "WFSPTRNOMEDIA", codeName: "PtrNoMedia", leading:1, output:true, input:false, command:"WFS_EXEE_PTR_NOMEDIA"}
typedef struct {
	LPSTR lpszUserPrompt; 								// xfs-sst-js:{name:"data.field"}
} WFSPTRNOMEDIA, *LPWFSPTRNOMEDIA;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type: "WFSPTRFIELDWARNING", codeName: "PtrFieldWarning", leading:1, output:true, input:false, command:"WFS_EXEE_PTR_FIELDWARNING"}
typedef struct {
	LPWFSPTRFIELDFAIL lpFieldFail;								// x|fs-sst-js:{name:"data.field"} // tbd
} WFSPTRFIELDWARNING, *LPWFSPTRFIELDWARNING;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type: "WFSPTRTONERTHRESHOLD", codeName: "PtrTonerThreshold", leading:1, output:true, input:false, command:"WFS_USRE_PTR_TONERTHRESHOLD"}
typedef struct {
	LPWORD lpwTonerThreshold;							// xfs-sst-js:{name:"data.field", pointerOfNamedCode:true}
} WFSPTRTONERTHRESHOLD, *LPWFSPTRTONERTHRESHOLD;
// xfs-sst-js:{name:"end"}


// xfs-sst-js:{name:"data", type: "WFSPTRLAMPTHRESHOLD", PtrLampThreshold: "SysteTime", leading:1, output:true, input:false, command:"WFS_USRE_PTR_LAMPTHRESHOLD"}
typedef struct {
	LPWORD lpwLampThreshold;							// xfs-sst-js:{name:"data.field", pointerOfNamedCode:true}
} WFSPTRLAMPTHRESHOLD, *LPWFSPTRLAMPTHRESHOLD;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type: "WFSPTRINKTHRESHOLD", codeName: "PtrInkThreshold", leading:1, output:true, input:false, command:"WFS_USRE_PTR_INKTHRESHOLD"}
typedef struct {
	LPWORD lpwInkThreshold;								// xfs-sst-js:{name:"data.field", pointerOfNamedCode:true}
} WFSPTRINKTHRESHOLD, *LPWFSPTRINKTHRESHOLD;
// xfs-sst-js:{name:"end"}
