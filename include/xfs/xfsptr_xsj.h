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

// xfs-sst-js:{name:"data", type:"WFSPTCONTROLMEDIA", codeName:"PtrControlMedia", leading:1, output:false, input:true, command:"WFS_CMD_PTR_CONTROL_MEDIA"}
typedef struct {
	DWORD dwMediaControl;							// xfs-sst-js:{name:"data.field"}
} WFSPTCONTROLMEDIA, *LPWFSPTCONTROLMEDIA;
// xfs-sst-js:{name:"end"}


// xfs-sst-js:{name:"data", type:"WFSPTRRESETCOUNT", codeName:"PtrResetCount", leading:1, output:false, input:true, command:"WFS_CMD_PTR_RESET_COUNT"}
typedef struct {
	USHORT usBinNumber;									// xfs-sst-js:{name:"data.field"}
} WFSPTRRESETCOUNT, *LPWFSPTRRESETCOUNT;
// xfs-sst-js:{name:"end"}


// xfs-sst-js:{name:"data", type:"WFSPTRRETRACTMEDIA", codeName:"PtrRetractMedia", leading:1, output:true, input:true, command:"WFS_CMD_PTR_RETRACT_MEDIA"}
typedef struct {
	USHORT usBinNumber;									// xfs-sst-js:{name:"data.field"}
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
    LPSTR           lpszFormName;				 		// xfs-sst-js:{name:"data.field"}
    LPSTR           lpszFieldName;                      // xfs-sst-js:{name:"data.field"}
    WORD            wFailure;                           // xfs-sst-js:{name:"data.field"}
} WFSPTRFIELDWARNING, *LPWFSPTRFIELDWARNING;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRTONERTHRESHOLD", codeName:"PtrTonerThreshold", leading:1, output:true, input:false, command:"WFS_USRE_PTR_TONERTHRESHOLD"}
typedef struct {
	WORD wTonerThreshold;							// xfs-sst-js:{name:"data.field"}
} WFSPTRTONERTHRESHOLD, *LPWFSPTRTONERTHRESHOLD;
// xfs-sst-js:{name:"end"}


// xfs-sst-js:{name:"data", type:"WFSPTRLAMPTHRESHOLD", codeName:"PtrLampThreshold", leading:1, output:true, input:false, command:"WFS_USRE_PTR_LAMPTHRESHOLD"}
typedef struct {
	WORD wLampThreshold;							// xfs-sst-js:{name:"data.field"}
} WFSPTRLAMPTHRESHOLD, *LPWFSPTRLAMPTHRESHOLD;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRINKTHRESHOLD", codeName:"PtrInkThreshold", leading:1, output:true, input:false, command:"WFS_USRE_PTR_INKTHRESHOLD"}
typedef struct {
	WORD wInkThreshold;								// xfs-sst-js:{name:"data.field"}
} WFSPTRINKTHRESHOLD, *LPWFSPTRINKTHRESHOLD;
// xfs-sst-js:{name:"end"}
