#include "xfsptr.h"
#include "xfsapi.h"
#include <windows.h>

typedef struct {
	LPSTR lpszFormList;
} WFSPTRFORMLIST, *LPWFSPTRFORMLIST;
/*
// xfs-sst-js:{name:"data", type:"WFSPTRFORMLIST", codeName:"PtrFormlist", leading:1, output:true, input:false, command:"WFS_INF_PTR_FORM_LIST", directCopy:true}
	return j = XSJ_List2Strings(p->lpszFormList);
// xfs-sst-js:{name:"end"}
*/

typedef struct {
	LPSTR lpszMediaList;
} WFSPTRMEDIALIST, *LPWFSPTRMEDIALIST;
/*
// xfs-sst-js:{name:"data", type:"WFSPTRMEDIALIST", codeName:"PtrMedialist", leading:1, output:true, input:false, command:"WFS_INF_PTR_MEDIA_LIST", directCopy:true}
	return j = XSJ_List2Strings(p->lpszMediaList);
// xfs-sst-js:{name:"end"}
*/

// xfs-sst-js:{name:"data", type:"WFSPTRMEDIACONTROL", codeName:"PtrMediaControl", leading:1, output:false, input:true, command:"WFS_CMD_PTR_CONTROL_MEDIA"}
typedef struct {
	LPDWORD lpdwMediaControl;							// xfs-sst-js:{name:"data.field", valueAtPointer:true}
} WFSPTRMEDIACONTROL, *LPWFSPTRMEDIACONTROL;
// xfs-sst-js:{name:"end"}


// xfs-sst-js:{name:"data", type:"WFSPTRRESETCOUNT", codeName:"PtrResetCount", leading:1, output:false, input:true, command:"WFS_CMD_PTR_RESET_COUNT"}
typedef struct {
	LPUSHORT lpusBinNumber;							// xfs-sst-js:{name:"data.field", valueAtPointer:true}
} WFSPTRRESETCOUNT, *LPWFSPTRRESETCOUNT;
// xfs-sst-js:{name:"end"}


// xfs-sst-js:{name:"data", type:"WFSPTRRETRACTMEDIA", codeName:"PtrRetractMedia", leading:1, output:true, input:true, command:"WFS_CMD_PTR_RETRACT_MEDIA"}
typedef struct {
	LPUSHORT lpusBinNumber;							// xfs-sst-js:{name:"data.field", valueAtPointer:true}
} WFSPTRRETRACTMEDIA, *LPWFSPTRRETRACTMEDIA;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRDISPENSEPAPER", codeName:"PtrDispensePaper", leading:1, output:false, input:true, command:"WFS_CMD_PTR_DISPENSE_PAPER"}
typedef struct {
	WORD wPaperSource;									// xfs-sst-js:{name:"data.field"}
} WFSPTRDISPENSEPAPER, *LPWFSPTRDISPENSEPAPER;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRNOMEDIA", codeName:"PtrNoMedia", leading:1, output:true, input:false, command:"WFS_EXEE_PTR_NOMEDIA"}
typedef struct {
	LPSTR lpszUserPrompt; 								// xfs-sst-js:{name:"data.field"}
} WFSPTRNOMEDIA, *LPWFSPTRNOMEDIA;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRFIELDWARNING", codeName:"PtrFieldWarning", leading:1, output:true, input:false, command:"WFS_EXEE_PTR_FIELDWARNING"}
typedef struct {
	LPWFSPTRFIELDFAIL lpFieldFail;						// xfs-sst-js:{name:"data.field"}
} WFSPTRFIELDWARNING, *LPWFSPTRFIELDWARNING;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRTONERTHRESHOLD", codeName:"PtrTonerThreshold", leading:1, output:true, input:false, command:"WFS_USRE_PTR_TONERTHRESHOLD"}
typedef struct {
	LPWORD lpwTonerThreshold;							// xfs-sst-js:{name:"data.field", valueAtPointer:true}
} WFSPTRTONERTHRESHOLD, *LPWFSPTRTONERTHRESHOLD;
// xfs-sst-js:{name:"end"}


// xfs-sst-js:{name:"data", type:"WFSPTRLAMPTHRESHOLD", PtrLampThreshold: "SysteTime", leading:1, output:true, input:false, command:"WFS_USRE_PTR_LAMPTHRESHOLD"}
typedef struct {
	LPWORD lpwLampThreshold;							// xfs-sst-js:{name:"data.field", valueAtPointer:true}
} WFSPTRLAMPTHRESHOLD, *LPWFSPTRLAMPTHRESHOLD;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRINKTHRESHOLD", codeName:"PtrInkThreshold", leading:1, output:true, input:false, command:"WFS_USRE_PTR_INKTHRESHOLD"}
typedef struct {
	LPWORD lpwInkThreshold;								// xfs-sst-js:{name:"data.field", valueAtPointer:true}
} WFSPTRINKTHRESHOLD, *LPWFSPTRINKTHRESHOLD;
// xfs-sst-js:{name:"end"}
