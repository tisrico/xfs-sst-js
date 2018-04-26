#include "xfsidc.h"
#include "xfsapi.h"
#include <windows.h>

// xfs-sst-js:{name:"data", type:"WFSIDCFORMNAME", codeName:"IDCQueryForm", leading:1, output:false, input:true, command:"WFS_INF_IDC_QUERY_FORM"}
typedef struct {
	__CHARRAY szFormName[1024];						// xfs-sst-js:{name:"data.field", defaultValue:null}
} WFSIDCFORMNAME, *LPWFSIDCFORMNAME;
// xfs-sst-js:{name:"end"}

