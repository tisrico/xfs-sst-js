
// xfs-sst-js:{name:"data", type:"WFSCDMMIXEDNUMBER", codeName:"CdmMixedNumber", leading:3, output:false, input:true, command:"WFS_INF_CDM_MIX_TABLE"}
typedef struct {
	USHORT usMixNumber;							// xfs-sst-js:{name:"data.field", defaultValue:0}
} WFSCDMMIXEDNUMBER, *LPWFSCDMMIXEDNUMBER;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMPRESENTSTATUSIN", codeName:"CdmPresentStatus", leading:3, output:false, input:true, command:"WFS_INF_CDM_PRESENT_STATUS"}
typedef struct {
	WORD fwPosition;							// xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_POSNULL"}
} WFSCDMPRESENTSTATUSIN, *LPWFSCDMPRESENTSTATUSIN;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMDENOMINATIONDISP", codeName:"CdmDenominationDisp", leading:3, output:true, input:false, command:"WFS_CMD_CDM_DISPENSE"}
typedef struct _wfs_cdm_denomination_disp
{
    CHAR            cCurrencyID[3];                 // xfs-sst-js:{name:"data.field", fixedArrayNNT:true}
    ULONG           ulAmount;                       // xfs-sst-js:{name:"data.field"}
    USHORT          usCount;                        // xfs-sst-js:{name:"data.field"}
    LPULONG         lpulValues;                     // xfs-sst-js:{name:"data.field", pointer2FixedArray:true, pointer2FixedArrayLength:"p->usCount"}
    ULONG           ulCashBox;                      // xfs-sst-js:{name:"data.field"}
} WFSCDMDENOMINATIONDISP, * LPWFSCDMDENOMINATIONDISP;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMPRESENTPOSITION", codeName:"CdmPresent", leading:3, output:false, input:true, command:"WFS_CMD_CDM_PRESENT"}
typedef struct {
	WORD fwPosition;							// xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_POSNULL"}
} WFSCDMPRESENTPOSITION, *LPWFSCDMPRESENTPOSITION;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMREJECT", codeName:"CdmReject", leading:3, output:false, input:true, command:"WFS_CMD_CDM_REJECT"}
typedef struct {
} WFSCDMREJECT, *LPWFSCDMREJECT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCLOSESHUTTER", codeName:"CdmPresent", leading:3, output:false, input:true, command:"WFS_CMD_CDM_CLOSE_SHUTTER"}
typedef struct {
	WORD fwPosition;							// xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_POSNULL"}
} WFSCDMCLOSESHUTTER, *LPWFSCDMCLOSESHUTTER;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMTELLERDETAILSIN", codeName:"CdmTellerDetailsIn", leading:3, output:false, input:true, command:""}
typedef struct _wfs_cdm_teller_details_in
{
	USHORT 	usTellerID;							// xfs-sst-js:{name:"data.field", defaultValue:0}
	ULONG 	ulInputPosition;					// xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_POSNULL"}
	WORD 	fwOutputPosition;					// xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_POSNULL"}
	LPWFSCDMTELLERTOTALS* lppTellerTotals;		// xfs-sst-js:{name:"data.field", defaultValue:[]}
} WFSCDMTELLERDETAILSIN, * LPWFSCDMTELLERDETAILSIN;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMTELLERUPDATESETTI", codeName:"CdmUpdateTellorInfo", leading:3, output:false, input:true, command:"WFS_CMD_CDM_SET_TELLER_INFO"}
typedef struct _wfs_cdm_teller_update_set_ti
{
    USHORT                usAction;							// xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_CREATE_TELLER"}
    LPWFSCDMTELLERDETAILSIN lpTellerDetails;					// xfs-sst-js:{name:"data.field", defaultValue:{}}
} WFSCDMTELLERUPDATESETTI, * LPWFSCDMTELLERUPDATESETTI;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCUINFOIN", codeName:"CdmCashUnitInfoIn", leading:3, output:false, input:true, command:"WFS_CMD_CDM_SET_CASH_UNIT_INFO"}
typedef struct _wfs_cdm_cu_info_in
{
    USHORT          usTellerID;             // xfs-sst-js:{name:"data.field", defaultValue:0}
    USHORT          usCount;
    LPWFSCDMCASHUNIT *lppList;              // xfs-sst-js:{name:"data.field", defaultValue:[], fixedArrayPointers:true, fixedArrayPointersLength:"p->usCount"}
} WFSCDMCUINFOIN, * LPWFSCDMCUINFOIN;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCUINFOSE", codeName:"CdmCashUnitInfoSe", leading:3, output:true, input:false, command:"WFS_CMD_CDM_START_EXCHANGE"}
typedef struct _wfs_cdm_cu_info_se
{
    USHORT          usTellerID;             // xfs-sst-js:{name:"data.field"}
    USHORT          usCount;                // xfs-sst-js:{name:"data.field"}
    LPWFSCDMCASHUNIT *lppList;              // xfs-sst-js:{name:"data.field", ntArray:true}
} WFSCDMCUINFOSE, * LPWFSCDMCUINFOSE;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCUINFOINEE", codeName:"CdmCashUnitInfoInEe", leading:3, output:false, input:true, command:"WFS_CMD_CDM_END_EXCHANGE"}
typedef struct _wfs_cdm_cu_info_in_ee
{
    USHORT          usTellerID;             // xfs-sst-js:{name:"data.field", defaultValue:0}
    USHORT          usCount;
    LPWFSCDMCASHUNIT *lppList;              // xfs-sst-js:{name:"data.field", defaultValue:[], fixedArrayPointers:true, fixedArrayPointersLength:"p->usCount"}
} WFSCDMCUINFOINEE, * LPWFSCDMCUINFOINEE;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMOPENSAFEDOOR", codeName:"CdmOpenSafeDoor", leading:3, output:false, input:true, command:"WFS_CMD_CDM_OPEN_SAFE_DOOR"}
typedef struct
{
} WFSCDMOPENSAFEDOOR, * LPWFSCDMOPENSAFEDOOR;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMMIXTABLESMT", codeName:"CdmMixTable", leading:3, output:false, input:true, command:"WFS_CMD_CDM_SET_MIX_TABLE"}
typedef struct _wfs_cdm_mix_table_smt
{
    USHORT          usMixNumber;                    // xfs-sst-js:{name:"data.field", defaultValue:0}
    LPSTR           lpszName;                       // xfs-sst-js:{name:"data.field"}
    USHORT          usRows;                         // xfs-sst-js:{name:"data.field", defaultValue:0}
    USHORT          usCols;                         // xfs-sst-js:{name:"data.field", defaultValue:0}
    LPULONG         lpulMixHeader;                  // xfs-sst-js:{name:"data.field", pointer2FixedArray:true, pointer2FixedArrayLength:"p->usCols", defaultValue:[]}
    LPWFSCDMMIXROW  *lppMixRows;                    // xfs-sst-js:{name:"data.field", ntArray:true, defaultValue:[]}
} WFSCDMMIXTABLESMT, * LPWFSCDMMIXTABLESMT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMITEMPOSITIONTCU", codeName:"CdmTestCashUnit", leading:3, output:false, input:true, command:"WFS_CMD_CDM_TEST_CASH_UNITS"}
typedef struct _wfs_cdm_itemposition_tcu
{
    USHORT             usNumber;				// xfs-sst-js:{name:"data.field", defaultValue:0}
    LPWFSCDMRETRACT    lpRetractArea;			// xfs-sst-js:{name:"data.field", defaultValue:null}
    WORD               fwOutputPosition;		// xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_POSNULL"}
} WFSCDMITEMPOSITIONTCU, * LPWFSCDMITEMPOSITIONTCU;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCUINFOTCU", codeName:"CdmTestCashUnit", leading:3, output:true, input:false, command:"WFS_CMD_CDM_TEST_CASH_UNITS"}
typedef struct _wfs_cdm_cu_info_tcu
{
    USHORT          usTellerID;             // xfs-sst-js:{name:"data.field"}
    USHORT          usCount;                // xfs-sst-js:{name:"data.field"}
    LPWFSCDMCASHUNIT *lppList;              // xfs-sst-js:{name:"data.field", ntArray:true}
} WFSCDMCUINFOTCU, * LPWFSCDMCUINFOTCU;
// xfs-sst-js:{name:"end"}
