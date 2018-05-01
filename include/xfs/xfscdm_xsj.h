
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


// xfs-sst-js:{name:"data", type:"WFSCDMTELLERINFOCHANGED", codeName:"CdmTellerInfoChanged", leading:3, output:true, input:false, command:"WFS_SRVE_CDM_TELLERINFOCHANGED"}
typedef struct {
    USHORT          usTellerID;                  // xfs-sst-js:{name:"data.field"}
}WFSCDMTELLERINFOCHANGED, * LPWFSCDMTELLERINFOCHANGED;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMDELAYDISPENSE", codeName:"CdmDelayDispense", leading:3, output:true, input:false, command:"WFS_EXEE_CDM_DELAYEDDISPENSE"}
typedef struct {
    ULONG          ulDelay;                     // xfs-sst-js:{name:"data.field"}
}WFSCDMDELAYDISPENSE, * LPWFSCDMDELAYDISPENSE;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMSTARTDISPENSE", codeName:"CdmStartDispense", leading:3, output:true, input:false, command:"WFS_EXEE_CDM_STARTDISPENSE"}
typedef struct {
    REQUESTID          hReqID;                     // xfs-sst-js:{name:"data.field"}
}WFSCDMSTARTDISPENSE, * LPWFSCDMSTARTDISPENSE;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMITEMTAKEN", codeName:"CdmItemTaken", leading:3, output:true, input:false, command:"WFS_SRVE_CDM_ITEMSTAKEN"}
typedef struct {
    WORD          fwPosition;                     // xfs-sst-js:{name:"data.field"}
}WFSCDMITEMTAKEN, * LPWFSCDMITEMTAKEN;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMPARTIALDISPENSE", codeName:"CdmPartialDispense", leading:3, output:true, input:false, command:"WFS_EXEE_CDM_PARTIALDISPENSE"}
typedef struct {
    USHORT          usDispNum;                  // xfs-sst-js:{name:"data.field"}
}WFSCDMPARTIALDISPENSE, * LPWFSCDMPARTIALDISPENSE;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMNOTEERROR", codeName:"CdmNoteError", leading:3, output:true, input:false, command:"WFS_EXEE_CDM_NOTEERROR"}
typedef struct {
    USHORT          fuReason;                     // xfs-sst-js:{name:"data.field"}
}WFSCDMNOTEERROR, * LPWFSCDMNOTEERROR;
// xfs-sst-js:{name:"end"}
