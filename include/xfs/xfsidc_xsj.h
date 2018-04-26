#include "xfsidc.h"
#include "xfsapi.h"
#include <windows.h>

// xfs-sst-js:{name:"data", type:"WFSIDCFORMNAME", codeName:"IDCQueryForm", leading:1, output:false, input:true, command:"WFS_INF_IDC_QUERY_FORM"}
typedef struct {
	__CHARRAY szFormName[1024];						// xfs-sst-js:{name:"data.field", defaultValue:null}
} WFSIDCFORMNAME, *LPWFSIDCFORMNAME;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCREADTRACKFORMNAME", codeName:"IDCReadTrack", leading:1, output:false, input:true, command:"WFS_CMD_IDC_READ_TRACK"}
typedef struct {
	__CHARRAY szFormName[1024];						// xfs-sst-js:{name:"data.field", defaultValue:null}
} WFSIDCREADTRACKFORMNAME, *LPWFSIDCREADTRACKFORMNAME;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCREADTRACKDATA", codeName:"IDCReadTrack", leading:1, output:true, input:false, command:"WFS_CMD_IDC_READ_TRACK", nestedStruct:true, nestedType:"LPSTR"}
typedef struct {
	LPSTR lpstrTrackData;								// xfs-sst-js:{name:"data.field"}
} WFSIDCREADTRACKDATA, *LPWFSIDCREADTRACKDATA;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSREADRAWDATA", codeName:"IDCReadRawData", leading:1, output:false, input:true, command:"WFS_CMD_IDC_READ_RAW_DATA"}
typedef struct {
	WORD wReadData;							// xfs-sst-js:{name:"data.field", defaultValue:"WFS_IDC_TRACK1"}
} WFSREADRAWDATA, *LPWFSREADRAWDATA;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCCHIPIOOUT", codeName:"IdcChipIoOut", leading:3, output:true, input:false, command:"WFS_CMD_IDC_CHIP_IO"}
typedef struct _wfs_idc_chip_io_out
{
    WORD           wChipProtocol;                                // xfs-sst-js:{name:"data.field"}
    ULONG          ulChipDataLength;                             // xfs-sst-js:{name:"data.field"}
    LPBYTE         lpbChipData;                                  // xfs-sst-js:{name:"data.field"}
} WFSIDCCHIPIOOUT, * LPWFSIDCCHIPIOOUT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCHIPPOWER", codeName:"IdcChipPower", leading:3, output:false, input:true, command:"WFS_CMD_IDC_CHIP_POWER"}
typedef struct {
	WORD wChipPower;							// xfs-sst-js:{name:"data.field", defaultValue:"WFS_IDC_CHIPPOWERCOLD"}
} WFSCHIPPOWER, *LPWFSCHIPPOWER;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCFORMLIST", codeName:"IdcFormlist", leading:1, output:true, input:false, command:"WFS_INF_IDC_FORM_LIST", nestedStruct:true, nestedType:"LPSTR"}
typedef struct {
	LPSTR lpszFormList;									// xfs-sst-js:{name:"data.field", ntStringList:true}
} WFSIDCFORMLIST, *LPWFSIDCFORMLIST;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCEJECTCARD", codeName:"IdcEjectCard", leading:1, output:false, input:true, command:"WFS_CMD_IDC_EJECT_CARD"}
typedef struct {
} WFSIDCEJECTCARD, *LPWFSIDCEJECTCARD;
// xfs-sst-js:{name:"end"}


// xfs-sst-js:{name:"data", type:"WFSIDCRESETCOUNT", codeName:"IdcRestCount", leading:1, output:false, input:true, command:"WFS_CMD_IDC_RESET_COUNT"}
typedef struct {
} WFSIDCRESETCOUNT, *LPWFSIDCRESETCOUNT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCCARDDATARAWINPUT", codeName:"IdcWriteRawData", leading:3, output:false, input:true, command:"WFS_CMD_IDC_WRITE_RAW_DATA"}
typedef struct _wfs_idc_card_data_raw_input
{
    WORD            wDataSource;                                  // xfs-sst-js:{name:"data.field"}
    WORD            wStatus;
    ULONG           ulDataLength;                                 // xfs-sst-js:{name:"data.field"}
    LPBYTE          lpbData;                                      // xfs-sst-js:{name:"data.field"}
    WORD            fwWriteMethod;                                // xfs-sst-js:{name:"data.field"}
} WFSIDCCARDDATARAWINPUT, * LPWFSIDCCARDDATARAWINPUT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCRESETIN", codeName:"IdcReset", leading:3, output:false, input:true, command:"WFS_CMD_IDC_RESET"}
typedef struct {
	WORD wResetIn;							// xfs-sst-js:{name:"data.field", defaultValue:"WFS_IDC_EJECT"}
} WFSIDCRESETIN, *LPWFSIDCRESETIN;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCCHIPPOWER", codeName:"IdcReset", leading:3, output:false, input:true, command:"WFS_CMD_IDC_CHIP_POWER"}
typedef struct {
	WORD wChipPower;							// xfs-sst-js:{name:"data.field", defaultValue:"WFS_IDC_CHIPPOWERCOLD"}
} WFSIDCCHIPPOWER, *LPWFSIDCCHIPPOWER;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIPARSEDATAOUT", codeName:"IDCReadTrack", leading:1, output:true, input:false, command:"WFS_CMD_IDC_PARSE_DATA", nestedStruct:true, nestedType:"LPSTR"}
typedef struct {
	LPSTR lpParseData;								// xfs-sst-js:{name:"data.field"}
} WFSIPARSEDATAOUT, *LPWFSIPARSEDATAOUT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCRETAINBIN", codeName:"IdcRetainBin", leading:3, output:true, input:false, command:"WFS_USRE_IDC_RETAINBINTHRESHOLD",  nestedStruct:true, nestedType:"WORD", nestedCast:"LPWORD"}
typedef struct {
	WORD wRetainBin;							// xfs-sst-js:{name:"data.field"}
} WFSIDCRETAINBIN, *LPWFSIDCRETAINBIN;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCRESETOUT", codeName:"IdcRetainBin", leading:3, output:true, input:false, command:"WFS_SRVE_IDC_MEDIADETECTED", nestedStruct:true, nestedType:"WORD", nestedCast:"LPWORD"}
typedef struct {
	WORD wResetOut;							// xfs-sst-js:{name:"data.field"}
} WFSIDCRESETOUT, *LPWFSIDCRESETOUT;
// xfs-sst-js:{name:"end"}
