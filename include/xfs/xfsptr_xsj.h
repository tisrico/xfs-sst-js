#include "xfsptr.h"
#include "xfsapi.h"
#include <windows.h>

typedef CHAR __CHARRAY;
// xfs-sst-js:{name:"data", type:"WFSPTRFORMNAME", codeName:"PtrQueryForm", leading:1, output:false, input:true, command:"WFS_INF_PTR_QUERY_FORM"}
typedef struct {
	__CHARRAY szFormName[1024];						// xfs-sst-js:{name:"data.field", defaultValue:null}
} WFSPTRFORMNAME, *LPWFSPTRFORMNAME;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRMEDIANAME", codeName:"PtrQueryMedia", leading:1, output:false, input:true, command:"WFS_INF_PTR_QUERY_MEDIA"}
typedef struct {
	__CHARRAY szMediaName[1024];						// xfs-sst-js:{name:"data.field", defaultValue:null}
} WFSPTRMEDIANAME, *LPWFSPTRMEDIANAME;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRFORMLIST", codeName:"PtrFormlist", leading:1, output:true, input:false, command:"WFS_INF_PTR_FORM_LIST", nestedStruct:true, nestedType:"LPSTR"}
typedef struct {
	LPSTR lpszFormList;									// xfs-sst-js:{name:"data.field", ntStringList:true}
} WFSPTRFORMLIST, *LPWFSPTRFORMLIST;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRMEDIALIST", codeName:"PtrMedialist", leading:1, output:true, input:false, command:"WFS_INF_PTR_MEDIA_LIST", nestedStruct:true, nestedType:"LPSTR"}
typedef struct {
	LPSTR lpszMediaList;								// xfs-sst-js:{name:"data.field", ntStringList:true}
} WFSPTRMEDIALIST, *LPWFSPTRMEDIALIST;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTCONTROLMEDIA", codeName:"PtrControlMedia", leading:1, output:false, input:true, command:"WFS_CMD_PTR_CONTROL_MEDIA"}
typedef struct {
	DWORD dwMediaControl;							// xfs-sst-js:{name:"data.field", defaultValue:"WFS_PTR_CTRLEJECT"}
} WFSPTCONTROLMEDIA, *LPWFSPTCONTROLMEDIA;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRRESETCOUNT", codeName:"PtrResetCount", leading:1, output:false, input:true, command:"WFS_CMD_PTR_RESET_COUNT"}
typedef struct {
	USHORT usBinNumber;									// xfs-sst-js:{name:"data.field", defaultValue:0}
} WFSPTRRESETCOUNT, *LPWFSPTRRESETCOUNT;
// xfs-sst-js:{name:"end"}


// xfs-sst-js:{name:"data", type:"WFSPTRRETRACTMEDIA", codeName:"PtrRetractMedia", leading:1, output:true, input:true, command:"WFS_CMD_PTR_RETRACT_MEDIA"}
typedef struct {
	USHORT usBinNumber;									// xfs-sst-js:{name:"data.field", defaultValue:1}
} WFSPTRRETRACTMEDIA, *LPWFSPTRRETRACTMEDIA;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRDISPENSEPAPER", codeName:"PtrDispensePaper", leading:1, output:false, input:true, command:"WFS_CMD_PTR_DISPENSE_PAPER"}
typedef struct {
	WORD wPaperSource;									// xfs-sst-js:{name:"data.field", defaultValue:"WFS_PTR_PAPERANY"}
} WFSPTRDISPENSEPAPER, *LPWFSPTRDISPENSEPAPER;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRNOMEDIA", codeName:"PtrNoMedia", leading:1, output:true, input:false, command:"WFS_EXEE_PTR_NOMEDIA", nestedStruct:true, nestedType:"LPSTR"}
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

// xfs-sst-js:{name:"data", type:"WFSPTRTONERTHRESHOLD", codeName:"PtrTonerThreshold", leading:1, output:true, input:false, command:"WFS_USRE_PTR_TONERTHRESHOLD", nestedStruct:true, nestedType:"WORD", nestedCast:"LPWORD"}
typedef struct {
	WORD lpwTonerThreshold;							// xfs-sst-js:{name:"data.field"}
} WFSPTRTONERTHRESHOLD, *LPWFSPTRTONERTHRESHOLD;
// xfs-sst-js:{name:"end"}


// xfs-sst-js:{name:"data", type:"WFSPTRLAMPTHRESHOLD", codeName:"PtrLampThreshold", leading:1, output:true, input:false, command:"WFS_USRE_PTR_LAMPTHRESHOLD", nestedStruct:true, nestedType:"WORD", nestedCast:"LPWORD"}
typedef struct {
	WORD wLampThreshold;							// xfs-sst-js:{name:"data.field"}
} WFSPTRLAMPTHRESHOLD, *LPWFSPTRLAMPTHRESHOLD;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRINKTHRESHOLD", codeName:"PtrInkThreshold", leading:1, output:true, input:false, command:"WFS_USRE_PTR_INKTHRESHOLD", nestedStruct:true, nestedType:"WORD", nestedCast:"LPWORD"}
typedef struct {
	WORD wInkThreshold;								// xfs-sst-js:{name:"data.field"}
} WFSPTRINKTHRESHOLD, *LPWFSPTRINKTHRESHOLD;
// xfs-sst-js:{name:"end"}
