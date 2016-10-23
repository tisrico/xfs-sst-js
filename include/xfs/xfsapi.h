/************************************************************************
*                                                                       *
* xfsapi.h      XFS - API functions, types, and definitions             *
*                                                                       *
*               Version 3.00  --  10/18/00                              *
*                                                                       *
************************************************************************/

#ifndef __inc_xfsapi__h
#define __inc_xfsapi__h

#ifdef __cplusplus
extern "C" {
#endif

/*   be aware of alignment   */
#pragma pack(push,1)

/****** Common *********************************************************/

#include <windows.h>

typedef unsigned short USHORT;
typedef char CHAR;
typedef short SHORT;
typedef unsigned long ULONG;
typedef unsigned char UCHAR;
typedef SHORT * LPSHORT;
typedef LPVOID * LPLPVOID;
typedef ULONG * LPULONG;
typedef USHORT * LPUSHORT;

typedef HANDLE HPROVIDER;

typedef ULONG REQUESTID;
typedef REQUESTID * LPREQUESTID;

typedef HANDLE HAPP;
typedef HAPP * LPHAPP;

typedef USHORT HSERVICE;
typedef HSERVICE * LPHSERVICE;

typedef LONG HRESULT;
typedef HRESULT * LPHRESULT;

typedef BOOL (WINAPI * XFSBLOCKINGHOOK)(VOID);
typedef XFSBLOCKINGHOOK * LPXFSBLOCKINGHOOK;

/****** String lengths **************************************************/

#define WFSDDESCRIPTION_LEN                     256
#define WFSDSYSSTATUS_LEN                       256
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSDEVSTATUS.fwState"], codeName:"XfsDevStatus"}
/****** Values of WFSDEVSTATUS.fwState **********************************/

#define WFS_STAT_DEVONLINE                      (0)
#define WFS_STAT_DEVOFFLINE                     (1)
#define WFS_STAT_DEVPOWEROFF                    (2)
#define WFS_STAT_DEVNODEVICE                    (3)
#define WFS_STAT_DEVHWERROR                     (4)
#define WFS_STAT_DEVUSERERROR                   (5)
#define WFS_STAT_DEVBUSY                        (6)
// xfs-sst-js:{name:"end"}
/****** Value of WFS_DEFAULT_HAPP ***************************************/

#define WFS_DEFAULT_HAPP                        (0)

/****** Data Structures *************************************************/

// xfs-sst-js:{name:"data", type: "WFSRESULT", codeName: "XfsResult", leading:3, output:true, input:false, command:""}
typedef struct _wfs_result
{
    REQUESTID       RequestID;								// xfs-sst-js:{name:"data.field"}
    HSERVICE        hService;                               // xfs-sst-js:{name:"data.field"}
    SYSTEMTIME      tsTimestamp;                            // xfs-sst-js:{name:"data.field", take_addr:true}
    HRESULT         hResult;                                // xfs-sst-js:{name:"data.field"}
    union {
        DWORD       dwCommandCode;                          // xfs-sst-js:{name:"data.field", scope:"u."}
        DWORD       dwEventID;                              // xfs-sst-js:{name:"data.field", scope:"u.", codeName:"XfsEvent"}
    } u;
    LPVOID          lpBuffer;                               // x|fs-sst-js:{name:"data.field"}
} WFSRESULT, * LPWFSRESULT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type: "WFSVERSION", codeName: "XfsVersion", leading:3, output:true, input:false, command:""}
typedef struct _wfsversion
{
    WORD            wVersion;                               // xfs-sst-js:{name:"data.field"}
    WORD            wLowVersion;                            // xfs-sst-js:{name:"data.field"}
    WORD            wHighVersion;                           // xfs-sst-js:{name:"data.field"}
    CHAR            szDescription[WFSDDESCRIPTION_LEN+1];   // xfs-sst-js:{name:"data.field"}
    CHAR            szSystemStatus[WFSDSYSSTATUS_LEN+1];    // xfs-sst-js:{name:"data.field"}
} WFSVERSION, * LPWFSVERSION;
// xfs-sst-js:{name:"end"}

/****** Message Structures **********************************************/

// xfs-sst-js:{name:"data", type: "WFSDEVSTATUS", codeName: "XfsDevStatus", leading:3, output:true, input:false, command:""}
typedef struct _wfs_devstatus
{
    LPSTR           lpszPhysicalName;           // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszWorkstationName;        // xfs-sst-js:{name:"data.field"}
    DWORD           dwState;                    // xfs-sst-js:{name:"data.field"}
} WFSDEVSTATUS, * LPWFSDEVSTATUS;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type: "WFSUNDEVMSG", codeName: "XfsUndevMsg", leading:3, output:true, input:false, command:""}
typedef struct _wfs_undevmsg
{
    LPSTR           lpszLogicalName;            // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszWorkstationName;        // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszAppID;                  // xfs-sst-js:{name:"data.field"}
    DWORD           dwSize;                     // xfs-sst-js:{name:"data.field"}
    LPBYTE          lpbDescription;             // xfs-sst-js:{name:"data.field"}
    DWORD           dwMsg;                      // xfs-sst-js:{name:"data.field"}
    LPWFSRESULT     lpWFSResult;                // xfs-sst-js:{name:"data.field"}
} WFSUNDEVMSG, * LPWFSUNDEVMSG;  
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type: "WFSAPPDISC", codeName: "XfsAppDisc", leading:3, output:true, input:false, command:""}
typedef struct _wfs_appdisc
{
    LPSTR           lpszLogicalName;            // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszWorkstationName;        // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszAppID;                  // xfs-sst-js:{name:"data.field"}
} WFSAPPDISC, * LPWFSAPPDISC;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type: "WFSHWERROR", codeName: "XfsHwError", leading:3, output:true, input:false, command:""}
typedef struct _wfs_hwerror
{
    LPSTR           lpszLogicalName;			// xfs-sst-js:{name:"data.field"}
    LPSTR           lpszPhysicalName;           // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszWorkstationName;        // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszAppID;                  // xfs-sst-js:{name:"data.field"}
    DWORD           dwAction;					// xfs-sst-js:{name:"data.field"}
    DWORD           dwSize;                     // xfs-sst-js:{name:"data.field"}
    LPBYTE          lpbDescription;             // xfs-sst-js:{name:"data.field"}
} WFSHWERROR, * LPWFSHWERROR;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type: "WFSVRSNERROR", codeName: "XfsVrsnError", leading:3, output:true, input:false, command:""}
typedef struct _wfs_vrsnerror
{
    LPSTR           lpszLogicalName;			// xfs-sst-js:{name:"data.field"}
    LPSTR           lpszWorkstationName;        // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszAppID;                  // xfs-sst-js:{name:"data.field"}
    DWORD           dwSize;                     // xfs-sst-js:{name:"data.field"}
    LPBYTE          lpbDescription;				// xfs-sst-js:{name:"data.field"}
    LPWFSVERSION    lpWFSVersion;               // xfs-sst-js:{name:"data.field"}
} WFSVRSNERROR, * LPWFSVRSNERROR;
// xfs-sst-js:{name:"end"}

/****** Error codes ******************************************************/
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.hResult"], codeName:"XfsErrorCode"}
#define WFS_SUCCESS                             (0)
#define WFS_ERR_ALREADY_STARTED                 (-1)
#define WFS_ERR_API_VER_TOO_HIGH                (-2)
#define WFS_ERR_API_VER_TOO_LOW                 (-3)
#define WFS_ERR_CANCELED                        (-4)
#define WFS_ERR_CFG_INVALID_HKEY                (-5)
#define WFS_ERR_CFG_INVALID_NAME                (-6)
#define WFS_ERR_CFG_INVALID_SUBKEY              (-7)
#define WFS_ERR_CFG_INVALID_VALUE               (-8)
#define WFS_ERR_CFG_KEY_NOT_EMPTY               (-9)
#define WFS_ERR_CFG_NAME_TOO_LONG               (-10)
#define WFS_ERR_CFG_NO_MORE_ITEMS               (-11)
#define WFS_ERR_CFG_VALUE_TOO_LONG              (-12)
#define WFS_ERR_DEV_NOT_READY                   (-13)
#define WFS_ERR_HARDWARE_ERROR                  (-14)
#define WFS_ERR_INTERNAL_ERROR                  (-15)
#define WFS_ERR_INVALID_ADDRESS                 (-16)
#define WFS_ERR_INVALID_APP_HANDLE              (-17)
#define WFS_ERR_INVALID_BUFFER                  (-18)
#define WFS_ERR_INVALID_CATEGORY                (-19)
#define WFS_ERR_INVALID_COMMAND                 (-20)
#define WFS_ERR_INVALID_EVENT_CLASS             (-21)
#define WFS_ERR_INVALID_HSERVICE                (-22)
#define WFS_ERR_INVALID_HPROVIDER               (-23)
#define WFS_ERR_INVALID_HWND                    (-24)
#define WFS_ERR_INVALID_HWNDREG                 (-25)
#define WFS_ERR_INVALID_POINTER                 (-26)
#define WFS_ERR_INVALID_REQ_ID                  (-27)
#define WFS_ERR_INVALID_RESULT                  (-28)
#define WFS_ERR_INVALID_SERVPROV                (-29)
#define WFS_ERR_INVALID_TIMER                   (-30)
#define WFS_ERR_INVALID_TRACELEVEL              (-31)
#define WFS_ERR_LOCKED                          (-32)
#define WFS_ERR_NO_BLOCKING_CALL                (-33)
#define WFS_ERR_NO_SERVPROV                     (-34)
#define WFS_ERR_NO_SUCH_THREAD                  (-35)
#define WFS_ERR_NO_TIMER                        (-36)
#define WFS_ERR_NOT_LOCKED                      (-37)
#define WFS_ERR_NOT_OK_TO_UNLOAD                (-38)
#define WFS_ERR_NOT_STARTED                     (-39)
#define WFS_ERR_NOT_REGISTERED                  (-40)
#define WFS_ERR_OP_IN_PROGRESS                  (-41)
#define WFS_ERR_OUT_OF_MEMORY                   (-42)
#define WFS_ERR_SERVICE_NOT_FOUND               (-43)
#define WFS_ERR_SPI_VER_TOO_HIGH                (-44)
#define WFS_ERR_SPI_VER_TOO_LOW                 (-45)
#define WFS_ERR_SRVC_VER_TOO_HIGH               (-46)
#define WFS_ERR_SRVC_VER_TOO_LOW                (-47)
#define WFS_ERR_TIMEOUT                         (-48)
#define WFS_ERR_UNSUPP_CATEGORY                 (-49)
#define WFS_ERR_UNSUPP_COMMAND                  (-50)
#define WFS_ERR_VERSION_ERROR_IN_SRVC           (-51)
#define WFS_ERR_INVALID_DATA                    (-52)
#define WFS_ERR_SOFTWARE_ERROR                  (-53)
#define WFS_ERR_CONNECTION_LOST                 (-54)
#define WFS_ERR_USER_ERROR                      (-55)
#define WFS_ERR_UNSUPP_DATA                     (-56)
#define WFS_ERR_SP_CRASH                        (-1025)
// xfs-sst-js:{name:"end"}
#define WFS_INDEFINITE_WAIT                     0

/****** Messages ********************************************************/

/* Message-No = (WM_USER + No) */
// xfs-sst-js:{name:"nc", bitwise:false, applies:[], codeName:"XfsMessage"}
#define WFS_OPEN_COMPLETE                       (WM_USER + 1)
#define WFS_CLOSE_COMPLETE                      (WM_USER + 2)
#define WFS_LOCK_COMPLETE                       (WM_USER + 3)
#define WFS_UNLOCK_COMPLETE                     (WM_USER + 4)
#define WFS_REGISTER_COMPLETE                   (WM_USER + 5)
#define WFS_DEREGISTER_COMPLETE                 (WM_USER + 6)
#define WFS_GETINFO_COMPLETE                    (WM_USER + 7)
#define WFS_EXECUTE_COMPLETE                    (WM_USER + 8)

#define WFS_EXECUTE_EVENT                       (WM_USER + 20)
#define WFS_SERVICE_EVENT                       (WM_USER + 21)
#define WFS_USER_EVENT                          (WM_USER + 22)
#define WFS_SYSTEM_EVENT                        (WM_USER + 23)

#define WFS_TIMER_EVENT                         (WM_USER + 100)
// xfs-sst-js:{name:"end"}
/****** Event Classes ***************************************************/
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFPRegister.dwEventClass", "WFPDeregister.dwEventClass"], codeName:"XfsEventClass"}
#define SERVICE_EVENTS                          (1)
#define USER_EVENTS                             (2)
#define SYSTEM_EVENTS                           (4)
#define EXECUTE_EVENTS                          (8)
// xfs-sst-js:{name:"end"}
/****** System Event IDs ************************************************/
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.u.dwEventID"], codeName:"XfsSysEvent"}
#define WFS_SYSE_UNDELIVERABLE_MSG              (1)
#define WFS_SYSE_HARDWARE_ERROR                 (2)
#define WFS_SYSE_VERSION_ERROR                  (3)
#define WFS_SYSE_DEVICE_STATUS                  (4)
#define WFS_SYSE_APP_DISCONNECT                 (5)
#define WFS_SYSE_SOFTWARE_ERROR                 (6)
#define WFS_SYSE_USER_ERROR                     (7)
#define WFS_SYSE_LOCK_REQUESTED                 (8)
// xfs-sst-js:{name:"end"}

/****** XFS Trace Level ********************************************/
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFMSetTraceLevel.dwTraceLevel"], codeName:"XfsTraceLevel"}
#define WFS_TRACE_API                           0x00000001
#define WFS_TRACE_ALL_API                       0x00000002
#define WFS_TRACE_SPI                           0x00000004
#define WFS_TRACE_ALL_SPI                       0x00000008
#define WFS_TRACE_MGR                           0x00000010
// xfs-sst-js:{name:"end"}
/****** XFS Error Actions ********************************************/
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSHWERROR.dwAction"], codeName:"XfsErrorAction"}
#define WFS_ERR_ACT_NOACTION                    (0x0000)
#define WFS_ERR_ACT_RESET                       (0x0001)
#define WFS_ERR_ACT_SWERROR                     (0x0002)
#define WFS_ERR_ACT_CONFIG                      (0x0004)
#define WFS_ERR_ACT_HWCLEAR                     (0x0008)
#define WFS_ERR_ACT_HWMAINT                     (0x0010)
#define WFS_ERR_ACT_SUSPEND                     (0x0020)
// xfs-sst-js:{name:"end"}
/****** API functions ***************************************************/

HRESULT extern WINAPI WFSCancelAsyncRequest ( HSERVICE hService, REQUESTID RequestID);

HRESULT extern WINAPI WFSCancelBlockingCall ( DWORD dwThreadID);

HRESULT extern WINAPI WFSCleanUp ();

HRESULT extern WINAPI WFSClose ( HSERVICE hService);

HRESULT extern WINAPI WFSAsyncClose ( HSERVICE hService, HWND hWnd, LPREQUESTID lpRequestID);

HRESULT extern WINAPI WFSCreateAppHandle ( LPHAPP lphApp);

HRESULT extern WINAPI WFSDeregister ( HSERVICE hService, DWORD dwEventClass, HWND hWndReg);

HRESULT extern WINAPI WFSAsyncDeregister ( HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, LPREQUESTID lpRequestID);

HRESULT extern WINAPI WFSDestroyAppHandle ( HAPP hApp);

HRESULT extern WINAPI WFSExecute ( HSERVICE hService, DWORD dwCommand, LPVOID lpCmdData, DWORD dwTimeOut, LPWFSRESULT * lppResult);

HRESULT extern WINAPI WFSAsyncExecute ( HSERVICE hService, DWORD dwCommand, LPVOID lpCmdData, DWORD dwTimeOut, HWND hWnd, LPREQUESTID lpRequestID);

HRESULT extern WINAPI WFSFreeResult ( LPWFSRESULT lpResult);

HRESULT extern WINAPI WFSGetInfo ( HSERVICE hService, DWORD dwCategory, LPVOID lpQueryDetails, DWORD dwTimeOut, LPWFSRESULT * lppResult);

HRESULT extern WINAPI WFSAsyncGetInfo ( HSERVICE hService, DWORD dwCategory, LPVOID lpQueryDetails, DWORD dwTimeOut, HWND hWnd, LPREQUESTID lpRequestID);

BOOL extern WINAPI WFSIsBlocking ();

HRESULT extern WINAPI WFSLock ( HSERVICE hService, DWORD dwTimeOut , LPWFSRESULT * lppResult);

HRESULT extern WINAPI WFSAsyncLock ( HSERVICE hService, DWORD dwTimeOut, HWND hWnd,  LPREQUESTID lpRequestID);

HRESULT extern WINAPI WFSOpen ( LPSTR lpszLogicalName, HAPP hApp, LPSTR lpszAppID, DWORD dwTraceLevel, DWORD dwTimeOut, DWORD dwSrvcVersionsRequired, LPWFSVERSION lpSrvcVersion, LPWFSVERSION lpSPIVersion, LPHSERVICE lphService);

HRESULT extern WINAPI WFSAsyncOpen ( LPSTR lpszLogicalName, HAPP hApp, LPSTR lpszAppID, DWORD dwTraceLevel, DWORD dwTimeOut, LPHSERVICE lphService, HWND hWnd, DWORD dwSrvcVersionsRequired, LPWFSVERSION lpSrvcVersion, LPWFSVERSION lpSPIVersion, LPREQUESTID lpRequestID);

HRESULT extern WINAPI WFSRegister ( HSERVICE hService, DWORD dwEventClass, HWND hWndReg);

HRESULT extern WINAPI WFSAsyncRegister ( HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, LPREQUESTID lpRequestID);

HRESULT extern WINAPI WFSSetBlockingHook ( XFSBLOCKINGHOOK lpBlockFunc, LPXFSBLOCKINGHOOK lppPrevFunc);

HRESULT extern WINAPI WFSStartUp ( DWORD dwVersionsRequired, LPWFSVERSION lpWFSVersion);

HRESULT extern WINAPI WFSUnhookBlockingHook ();

HRESULT extern WINAPI WFSUnlock ( HSERVICE hService);

HRESULT extern WINAPI WFSAsyncUnlock ( HSERVICE hService, HWND hWnd, LPREQUESTID lpRequestID);

HRESULT extern WINAPI WFMSetTraceLevel ( HSERVICE hService, DWORD dwTraceLevel);


/*   restore alignment   */
#pragma pack(pop)

#ifdef __cplusplus
}       /*extern "C"*/
#endif

#endif  /* __inc_xfsapi__h */
