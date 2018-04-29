// xfs-sst-js:{name:"data", type:"WFSCDMTELLERINFODUP", codeName:"CdmTellerInfo", leading:3, output:false, input:true, command:"WFS_INF_CDM_TELLER_INFO"}
typedef struct _wfs_cdm_teller_info_dup
{
    USHORT          usTellerID;              // xfs-sst-js:{name:"data.field", defaultValue:0}
    __CHARRAY       cCurrencyID[3];          // xfs-sst-js:{name:"data.field", fixedArray:true, arrayLength:3, defaultValue:null}
} WFSCDMTELLERINFODUP, * LPWFSCDMTELLERINFODUP;
// xfs-sst-js:{name:"end"}

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
    LPULONG         lpulValues;                     // xfs-sst-js:{name:"data.field", fixedArrayPointers:true, fixedArrayPointersLength:"p->usCount"}
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

// xfs-sst-js:{name:"data", type:"WFSCDMTELLERUPDATESETTI", codeName:"CdmUpdateTellorInfo", leading:3, output:false, input:true, command:"WFS_CMD_CDM_SET_TELLER_INFO"}
typedef struct _wfs_cdm_teller_update_set_ti
{
    USHORT                usAction;							// xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_CREATE_TELLER"}
    LPWFSCDMTELLERDETAILS lpTellerDetails;					// xfs-sst-js:{name:"data.field", defaultValue:{}}
} WFSCDMTELLERUPDATESETTI, * LPWFSCDMTELLERUPDATESETTI;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCUINFOIN", codeName:"CdmCashUnitInfoIn", leading:3, output:false, input:true, command:""}
typedef struct _wfs_cdm_cu_info_in
{
    USHORT          usTellerID;             // xfs-sst-js:{name:"data.field"}
    USHORT          usCount;                // xfs-sst-js:{name:"data.field"}
    LPWFSCDMCASHUNIT *lppList;              // xfs-sst-js:{name:"data.field", ntArray:true}
} WFSCDMCUINFOIN, * LPWFSCDMCUINFOIN;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMTELLERUPDATESETTI", codeName:"CdmUpdateTellorInfo", leading:3, output:false, input:true, command:"WFS_CMD_CDM_SET_CASH_UNIT_INFO"}
typedef struct
{
    WFSCDMCUINFOIN lpCUInfo;					// xfs-sst-js:{name:"data.field", defaultValue:{}}
} WFSCDMSETCASHUNITINFO, * LPWFSCDMSETCASHUNITINFO;
// xfs-sst-js:{name:"end"}
