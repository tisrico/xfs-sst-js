/******************************************************************************
*                                                                             *
* xfsidc.h    XFS - Identification card unit (IDC) definitions                *
*                                                                             *
*             Version 3.02  (09/05/03)                                        *
*                                                                             *
******************************************************************************/
 
#ifndef __INC_XFSIDC__H
#define __INC_XFSIDC__H

#ifdef __cplusplus
extern "C" {
#endif

#include <xfsapi.h>

/*   be aware of alignment   */
#pragma pack(push,1)


/* values of WFSIDCCAPS.wClass */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRCAPS.wClass"], codeName:"XfsServiceClass"}
#define     WFS_SERVICE_CLASS_IDC               (2)
// xfs-sst-js:{name:"end"}

#define     WFS_SERVICE_CLASS_NAME_IDC          "IDC"
#define     WFS_SERVICE_CLASS_VERSION_IDC       0x0203

#define     IDC_SERVICE_OFFSET                  (WFS_SERVICE_CLASS_IDC * 100)

/* IDC Info Commands */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.u.dwCommandCode"], codeName:"XfsInfoCmd"}
#define     WFS_INF_IDC_STATUS                  (IDC_SERVICE_OFFSET + 1)
#define     WFS_INF_IDC_CAPABILITIES            (IDC_SERVICE_OFFSET + 2)
#define     WFS_INF_IDC_FORM_LIST               (IDC_SERVICE_OFFSET + 3)
#define     WFS_INF_IDC_QUERY_FORM              (IDC_SERVICE_OFFSET + 4)
// xfs-sst-js:{name:"end"}

/* IDC Execute Commands */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.u.dwCommandCode"], codeName:"XfsExecuteCmd"}
#define     WFS_CMD_IDC_READ_TRACK              (IDC_SERVICE_OFFSET + 1)
#define     WFS_CMD_IDC_WRITE_TRACK             (IDC_SERVICE_OFFSET + 2)
#define     WFS_CMD_IDC_EJECT_CARD              (IDC_SERVICE_OFFSET + 3)
#define     WFS_CMD_IDC_RETAIN_CARD             (IDC_SERVICE_OFFSET + 4)
#define     WFS_CMD_IDC_RESET_COUNT             (IDC_SERVICE_OFFSET + 5)
#define     WFS_CMD_IDC_SETKEY                  (IDC_SERVICE_OFFSET + 6)
#define     WFS_CMD_IDC_READ_RAW_DATA           (IDC_SERVICE_OFFSET + 7)
#define     WFS_CMD_IDC_WRITE_RAW_DATA          (IDC_SERVICE_OFFSET + 8)
#define     WFS_CMD_IDC_CHIP_IO                 (IDC_SERVICE_OFFSET + 9)
#define     WFS_CMD_IDC_RESET                   (IDC_SERVICE_OFFSET + 10)
#define     WFS_CMD_IDC_CHIP_POWER              (IDC_SERVICE_OFFSET + 11)
#define     WFS_CMD_IDC_PARSE_DATA              (IDC_SERVICE_OFFSET + 12)
// xfs-sst-js:{name:"end"}

/* IDC Messages */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.u.dwEventID"], codeName:"XfsEvent"}
#define     WFS_EXEE_IDC_INVALIDTRACKDATA       (IDC_SERVICE_OFFSET + 1)
#define     WFS_EXEE_IDC_MEDIAINSERTED          (IDC_SERVICE_OFFSET + 3)
#define     WFS_SRVE_IDC_MEDIAREMOVED           (IDC_SERVICE_OFFSET + 4)
#define     WFS_SRVE_IDC_CARDACTION             (IDC_SERVICE_OFFSET + 5)
#define     WFS_USRE_IDC_RETAINBINTHRESHOLD     (IDC_SERVICE_OFFSET + 6)
#define     WFS_EXEE_IDC_INVALIDMEDIA           (IDC_SERVICE_OFFSET + 7)
#define     WFS_EXEE_IDC_MEDIARETAINED          (IDC_SERVICE_OFFSET + 8)
#define     WFS_SRVE_IDC_MEDIADETECTED          (IDC_SERVICE_OFFSET + 9)
// xfs-sst-js:{name:"end"}

/* values of WFSIDCSTATUS.fwDevice */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSIDCSTATUS.fwDevice"], codeName:"XfsIdcDevStatus"}
#define     WFS_IDC_DEVONLINE                   WFS_STAT_DEVONLINE
#define     WFS_IDC_DEVOFFLINE                  WFS_STAT_DEVOFFLINE
#define     WFS_IDC_DEVPOWEROFF                 WFS_STAT_DEVPOWEROFF
#define     WFS_IDC_DEVNODEVICE                 WFS_STAT_DEVNODEVICE
#define     WFS_IDC_DEVHWERROR                  WFS_STAT_DEVHWERROR
#define     WFS_IDC_DEVUSERERROR                WFS_STAT_DEVUSERERROR
#define     WFS_IDC_DEVBUSY                     WFS_STAT_DEVBUSY
// xfs-sst-js:{name:"end"}

/* values of WFSIDCSTATUS.fwMedia, WFSIDCRETAINCARD.fwPosition,  */
/* WFSIDCCARDACT.fwPosition  */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSIDCSTATUS.fwMedia", "WFSIDCRETAINCARD.fwPosition"], codeName:"XfsIdcMediaPosition"}
#define     WFS_IDC_MEDIAPRESENT                (1)
#define     WFS_IDC_MEDIANOTPRESENT             (2)
#define     WFS_IDC_MEDIAJAMMED                 (3)
#define     WFS_IDC_MEDIANOTSUPP                (4)
#define     WFS_IDC_MEDIAUNKNOWN                (5)
#define     WFS_IDC_MEDIAENTERING               (6)
#define     WFS_IDC_MEDIALATCHED                (7)
// xfs-sst-js:{name:"end"}

/* values of WFSIDCSTATUS.fwRetainBin */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSIDCSTATUS.fwRetainBin", "WFSIDCRETAINBIN.wRetainBin"], codeName:"XfsIdcRetainBin"}
#define     WFS_IDC_RETAINBINOK                 (1)
#define     WFS_IDC_RETAINNOTSUPP               (2)
#define     WFS_IDC_RETAINBINFULL               (3)
#define     WFS_IDC_RETAINBINHIGH               (4)
// xfs-sst-js:{name:"end"}

/* values of WFSIDCSTATUS.fwSecurity */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSIDCSTATUS.fwSecurity"], codeName:"XfsIdcSecurity"}
#define     WFS_IDC_SECNOTSUPP                  (1)
#define     WFS_IDC_SECNOTREADY                 (2)
#define     WFS_IDC_SECOPEN                     (3)
// xfs-sst-js:{name:"end"}

/* values of WFSIDCSTATUS.fwChipPower */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSIDCSTATUS.fwChipPower"], codeName:"XfsIdcChipPower"}
#define     WFS_IDC_CHIPONLINE                  (0)
#define     WFS_IDC_CHIPPOWEREDOFF              (1)
#define     WFS_IDC_CHIPBUSY                    (2)
#define     WFS_IDC_CHIPNODEVICE                (3)
#define     WFS_IDC_CHIPHWERROR                 (4)
#define     WFS_IDC_CHIPNOCARD                  (5)
#define     WFS_IDC_CHIPNOTSUPP                 (6)
#define     WFS_IDC_CHIPUNKNOWN                 (7)
// xfs-sst-js:{name:"end"}

/* values of WFSIDCCAPS.fwType */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSIDCCAPS.fwType"], codeName:"XfsIdcType"}
#define     WFS_IDC_TYPEMOTOR                   (1)
#define     WFS_IDC_TYPESWIPE                   (2)
#define     WFS_IDC_TYPEDIP                     (3)
#define     WFS_IDC_TYPECONTACTLESS             (4)
#define     WFS_IDC_TYPELATCHEDDIP              (5)
#define     WFS_IDC_TYPEPERMANENT               (6)
// xfs-sst-js:{name:"end"}

/* values of WFSIDCCAPS.fwReadTracks, WFSIDCCAPS.fwWriteTracks,
             WFSIDCCARDDATA.wDataSource */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSIDCCAPS.fwReadTracks", "WFSIDCCAPS.fwWriteTracks", "WFSIDCCARDDATA.wDataSource", "WFSREADRAWDATA.wReadData", "WFSIDCCARDDATARAWINPUT.wDataSource"], codeName:"XfsIdcTrack"}
#define     WFS_IDC_NOTSUPP                     0x0000
#define     WFS_IDC_TRACK1                      0x0001
#define     WFS_IDC_TRACK2                      0x0002
#define     WFS_IDC_TRACK3                      0x0004
// xfs-sst-js:{name:"end"}

/* further values of WFSIDCCARDDATA.wDataSource */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSIDCCARDDATA.wDataSource"], codeName:"XfsIdcDataSource"}
#define     WFS_IDC_CHIP                        0x0008
#define     WFS_IDC_SECURITY                    0x0010
#define     WFS_IDC_FLUXINACTIVE                0x0020
#define     WFS_IDC_TRACK_WM                    0x8000
// xfs-sst-js:{name:"end"}

/* values of WFSIDCCAPS.fwChipProtocols */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSIDCCAPS.fwChipProtocols", "WFSIDCCHIPIO.wChipProtocol", "WFSIDCCHIPIOOUT.wChipProtocol"], codeName:"XfsIdcChipProtocol"}
#define     WFS_IDC_CHIPT0                      0x0001
#define     WFS_IDC_CHIPT1                      0x0002
#define     WFS_IDC_CHIPT2                      0x0004
#define     WFS_IDC_CHIPT3                      0x0008
#define     WFS_IDC_CHIPT4                      0x0010
#define     WFS_IDC_CHIPT5                      0x0020
#define     WFS_IDC_CHIPT6                      0x0040
#define     WFS_IDC_CHIPT7                      0x0080
#define     WFS_IDC_CHIPT8                      0x0100
#define     WFS_IDC_CHIPT9                      0x0200
#define     WFS_IDC_CHIPT10                     0x0400
#define     WFS_IDC_CHIPT11                     0x0800
#define     WFS_IDC_CHIPT12                     0x1000
#define     WFS_IDC_CHIPT13                     0x2000
#define     WFS_IDC_CHIPT14                     0x4000
#define     WFS_IDC_CHIPT15                     0x8000
// xfs-sst-js:{name:"end"}

/* values of WFSIDCCAPS.fwSecType */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSIDCCAPS.fwSecType"], codeName:"XfsIdcSecType"}
#define     WFS_IDC_SECNOTSUPP                  (1)
#define     WFS_IDC_SECMMBOX                    (2)
#define     WFS_IDC_SECCIM86                    (3)
// xfs-sst-js:{name:"end"}

/* values of WFSIDCCAPS.fwPowerOnOption, WFSIDCCAPS.fwPowerOffOption,  */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSIDCCAPS.fwPowerOnOption", "WFSIDCCAPS.fwPowerOffOption", "WFSIDCREST.wResetIn"], codeName:"XfsIdcPowerOption"}
#define     WFS_IDC_NOACTION                    (1)
#define     WFS_IDC_EJECT                       (2)
#define     WFS_IDC_RETAIN                      (3)
#define     WFS_IDC_EJECTTHENRETAIN             (4)
#define     WFS_IDC_READPOSITION                (5)
// xfs-sst-js:{name:"end"}

/* values of WFSIDCCAPS.fwWriteMode; WFSIDCWRITETRACK.fwWriteMethod, WFSIDCCARDDATA.fwWriteMethod */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSIDCCAPS.fwWriteMode", "WFSIDCWRITETRACK.fwWriteMethod", "WFSIDCCARDDATA.fwWriteMethod", "WFSIDCCARDDATARAWINPUT.fwWriteMethod"], codeName:"XfsIdcWriteMethod"}
#define     WFS_IDC_UNKNOWN                     0x0001
#define     WFS_IDC_LOCO                        0x0002
#define     WFS_IDC_HICO                        0x0004
#define     WFS_IDC_AUTO                        0x0008
// xfs-sst-js:{name:"end"}

/* values of WFSIDCCAPS.fwChipPower */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSIDCCAPS.fwChipPower", "WFSCHIPPOWER.wChipPower", "WFSIDCCHIPPOWER.wChipPower"], codeName:"XfsIdcChipPower"}
#define     WFS_IDC_CHIPPOWERCOLD               0x0002
#define     WFS_IDC_CHIPPOWERWARM               0x0004
#define     WFS_IDC_CHIPPOWEROFF                0x0008
// xfs-sst-js:{name:"end"}

/* values of WFSIDCFORM.fwAction */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSIDCFORM.fwAction"], codeName:"XfsIdcFormAction"}
#define     WFS_IDC_ACTIONREAD                  0x0001
#define     WFS_IDC_ACTIONWRITE                 0x0002
// xfs-sst-js:{name:"end"}

/* values of WFSIDCTRACKEVENT.fwStatus, WFSIDCCARDDATA.wStatus */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSIDCTRACKEVENT.fwStatus", "WFSIDCCARDDATA.wStatus"], codeName:"XfsIdcCardTrackStatus"}
#define     WFS_IDC_DATAOK                      (0)
#define     WFS_IDC_DATAMISSING                 (1)
#define     WFS_IDC_DATAINVALID                 (2)
#define     WFS_IDC_DATATOOLONG                 (3)
#define     WFS_IDC_DATATOOSHORT                (4)
#define     WFS_IDC_DATASRCNOTSUPP              (5)
#define     WFS_IDC_DATASRCMISSING              (6)
// xfs-sst-js:{name:"end"}

/* values WFSIDCCARDACT.wAction */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSIDCCARDACT.wAction", "WFSIDCRESETOUT.wResetOut"], codeName:"XfsIdcCardAction"}
#define     WFS_IDC_CARDRETAINED                (1)
#define     WFS_IDC_CARDEJECTED                 (2)
#define     WFS_IDC_CARDREADPOSITION            (3)
#define     WFS_IDC_CARDJAMMED                  (4)
// xfs-sst-js:{name:"end"}

/* values of WFSIDCCARDDATA.lpbData if security is read */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSIDCCARDDATA.lpbData____"], codeName:"XfsIdcSecLevel"}
#define     WFS_IDC_SEC_READLEVEL1              '1'
#define     WFS_IDC_SEC_READLEVEL2              '2'
#define     WFS_IDC_SEC_READLEVEL3              '3'
#define     WFS_IDC_SEC_READLEVEL4              '4'
#define     WFS_IDC_SEC_READLEVEL5              '5'
#define     WFS_IDC_SEC_BADREADLEVEL            '6'
#define     WFS_IDC_SEC_NODATA                  '7'
#define     WFS_IDC_SEC_DATAINVAL               '8'
#define     WFS_IDC_SEC_HWERROR                 '9'
#define     WFS_IDC_SEC_NOINIT                  'A'
// xfs-sst-js:{name:"end"}

/* WOSA/XFS IDC Errors */ 
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.hResult"], codeName:"XfsErrorCode"}
#define WFS_ERR_IDC_MEDIAJAM                    (-(IDC_SERVICE_OFFSET + 0))
#define WFS_ERR_IDC_NOMEDIA                     (-(IDC_SERVICE_OFFSET + 1))
#define WFS_ERR_IDC_MEDIARETAINED               (-(IDC_SERVICE_OFFSET + 2))
#define WFS_ERR_IDC_RETAINBINFULL               (-(IDC_SERVICE_OFFSET + 3))
#define WFS_ERR_IDC_INVALIDDATA                 (-(IDC_SERVICE_OFFSET + 4))
#define WFS_ERR_IDC_INVALIDMEDIA                (-(IDC_SERVICE_OFFSET + 5))
#define WFS_ERR_IDC_FORMNOTFOUND                (-(IDC_SERVICE_OFFSET + 6))
#define WFS_ERR_IDC_FORMINVALID                 (-(IDC_SERVICE_OFFSET + 7))
#define WFS_ERR_IDC_DATASYNTAX                  (-(IDC_SERVICE_OFFSET + 8))
#define WFS_ERR_IDC_SHUTTERFAIL                 (-(IDC_SERVICE_OFFSET + 9))
#define WFS_ERR_IDC_SECURITYFAIL                (-(IDC_SERVICE_OFFSET + 10))
#define WFS_ERR_IDC_PROTOCOLNOTSUPP             (-(IDC_SERVICE_OFFSET + 11))
#define WFS_ERR_IDC_ATRNOTOBTAINED              (-(IDC_SERVICE_OFFSET + 12))
#define WFS_ERR_IDC_INVALIDKEY                  (-(IDC_SERVICE_OFFSET + 13))
#define WFS_ERR_IDC_WRITE_METHOD                (-(IDC_SERVICE_OFFSET + 14))
#define WFS_ERR_IDC_CHIPPOWERNOTSUPP            (-(IDC_SERVICE_OFFSET + 15))
#define WFS_ERR_IDC_CARDTOOSHORT                (-(IDC_SERVICE_OFFSET + 16))
#define WFS_ERR_IDC_CARDTOOLONG                 (-(IDC_SERVICE_OFFSET + 17))
// xfs-sst-js:{name:"end"}

/*=================================================================*/
/* IDC Info Command Structures and variables */
/*=================================================================*/

// xfs-sst-js:{name:"data", type:"WFSIDCSTATUS", codeName:"IdcStatus", leading:3, output:true, input:false, command:"WFS_INF_IDC_STATUS"}
typedef struct _wfs_idc_status
{
    WORD            fwDevice;                               // xfs-sst-js:{name:"data.field"}
    WORD            fwMedia;                                // xfs-sst-js:{name:"data.field"}
    WORD            fwRetainBin;                            // xfs-sst-js:{name:"data.field"}
    WORD            fwSecurity;                             // xfs-sst-js:{name:"data.field"}
    USHORT          usCards;                                // xfs-sst-js:{name:"data.field"}
    WORD            fwChipPower;                            // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszExtra;                              // xfs-sst-js:{name:"data.field"}
} WFSIDCSTATUS, * LPWFSIDCSTATUS;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCCAPS", codeName:"IdcCpas", leading:3, output:true, input:false, command:"WFS_INF_IDC_CAPABILITIES"}
typedef struct _wfs_idc_caps
{
    WORD            wClass;                                 // xfs-sst-js:{name:"data.field"}
    WORD            fwType;                                 // xfs-sst-js:{name:"data.field"}
    BOOL            bCompound;                              // xfs-sst-js:{name:"data.field"}
    WORD            fwReadTracks;                           // xfs-sst-js:{name:"data.field"}
    WORD            fwWriteTracks;                          // xfs-sst-js:{name:"data.field"}
    WORD            fwChipProtocols;                        // xfs-sst-js:{name:"data.field"}
    USHORT          usCards;                                // xfs-sst-js:{name:"data.field"}
    WORD            fwSecType;                              // xfs-sst-js:{name:"data.field"}
    WORD            fwPowerOnOption;                        // xfs-sst-js:{name:"data.field"}
    WORD            fwPowerOffOption;                       // xfs-sst-js:{name:"data.field"}
    BOOL            bFluxSensorProgrammable;                // xfs-sst-js:{name:"data.field"}
    BOOL            bReadWriteAccessFollowingEject;         // xfs-sst-js:{name:"data.field"}
    WORD            fwWriteMode;                            // xfs-sst-js:{name:"data.field"}
    WORD            fwChipPower;                            // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszExtra;                              // xfs-sst-js:{name:"data.field"}
} WFSIDCCAPS, * LPWFSIDCCAPS;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCFORM", codeName:"IdcForm", leading:3, output:true, input:false, command:"WFS_INF_IDC_QUERY_FORM"}
typedef struct _wfs_idc_form
{
    LPSTR           lpszFormName;                                // xfs-sst-js:{name:"data.field"}
    CHAR            cFieldSeparatorTrack1;                       // xfs-sst-js:{name:"data.field"}
    CHAR            cFieldSeparatorTrack2;                       // xfs-sst-js:{name:"data.field"}
    CHAR            cFieldSeparatorTrack3;                       // xfs-sst-js:{name:"data.field"}
    WORD            fwAction;                                    // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszTracks;                                  // xfs-sst-js:{name:"data.field"}
    BOOL            bSecure;                                     // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszTrack1Fields;                            // xfs-sst-js:{name:"data.field", ntStringList:true}
    LPSTR           lpszTrack2Fields;                            // xfs-sst-js:{name:"data.field", ntStringList:true}
    LPSTR           lpszTrack3Fields;                            // xfs-sst-js:{name:"data.field", ntStringList:true}
} WFSIDCFORM, * LPWFSIDCFORM;
// xfs-sst-js:{name:"end"}

/*=================================================================*/
/* IDC Execute Command Structures */
/*=================================================================*/

// xfs-sst-js:{name:"data", type:"WFSIDCWRITETRACK", codeName:"IdcWriteTrack", leading:3, output:false, input:true, command:"WFS_CMD_IDC_WRITE_TRACK"}
typedef struct _wfs_idc_write_track
{
    LPSTR           lpstrFormName;                                // xfs-sst-js:{name:"data.field", defaultValue:null}
    LPSTR           lpstrTrackData;                               // xfs-sst-js:{name:"data.field", defaultValue:null}
    WORD            fwWriteMethod;                                // xfs-sst-js:{name:"data.field",  defaultValue:"WFS_IDC_LOCO"}
} WFSIDCWRITETRACK, * LPWFSIDCWRITETRACK;
// xfs-sst-js:{name:"end"}


// xfs-sst-js:{name:"data", type:"WFSIDCRETAINCARD", codeName:"IdcRetainCard", leading:3, output:true, input:false, command:"WFS_CMD_IDC_RETAIN_CARD"}
typedef struct _wfs_idc_retain_card
{
    USHORT          usCount;                                // xfs-sst-js:{name:"data.field"}
    WORD            fwPosition;                             // xfs-sst-js:{name:"data.field"}
} WFSIDCRETAINCARD, * LPWFSIDCRETAINCARD;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCSETKEY", codeName:"IdcSetKey", leading:3, output:false, input:true, command:"WFS_CMD_IDC_SETKEY"}
typedef struct _wfs_idc_setkey
{
    USHORT          usKeyLen;                                // xfs-sst-js:{name:"data.field", defaultValue:0}
    LPBYTE          lpbKeyValue;                             // xfs-sst-js:{name:"data.field", defaultValue:null}
} WFSIDCSETKEY, * LPWFSIDCSETKEY;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCCARDDATA", codeName:"IdcCardData", leading:3, output:true, input:false, command:"WFS_CMD_IDC_READ_RAW_DATA"}
typedef struct _wfs_idc_card_data
{
    WORD            wDataSource;                                  // xfs-sst-js:{name:"data.field"}
    WORD            wStatus;                                      // xfs-sst-js:{name:"data.field"}
    ULONG           ulDataLength;                                 // xfs-sst-js:{name:"data.field"}
    LPBYTE          lpbData;                                      // xfs-sst-js:{name:"data.field"}
    WORD            fwWriteMethod;                                // xfs-sst-js:{name:"data.field"}
} WFSIDCCARDDATA, * LPWFSIDCCARDDATA;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCCHIPIO", codeName:"IdcChipIo", leading:3, output:true, input:true, command:"WFS_CMD_IDC_CHIP_IO"}
typedef struct _wfs_idc_chip_io
{
    WORD           wChipProtocol;                                // xfs-sst-js:{name:"data.field", defaultValue:"WFS_IDC_NOTSUPP"}
    ULONG          ulChipDataLength;                             // xfs-sst-js:{name:"data.field", defaultValue:0}
    LPBYTE         lpbChipData;                                  // xfs-sst-js:{name:"data.field", defaultValue:null}
} WFSIDCCHIPIO, * LPWFSIDCCHIPIO;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCCHIPPOWEROUT", codeName:"IdcChipPowerOut", leading:3, output:true, input:false, command:"WFS_CMD_IDC_CHIP_POWER"}
typedef struct _wfs_idc_chip_power_out
{
    ULONG          ulChipDataLength;                            // xfs-sst-js:{name:"data.field"}
    LPBYTE         lpbChipData;                                 // xfs-sst-js:{name:"data.field"}
} WFSIDCCHIPPOWEROUT, * LPWFSIDCCHIPPOWEROUT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCPARSEDATA", codeName:"IdcParseData", leading:3, output:false, input:true, command:"WFS_CMD_IDC_PARSE_DATA"}
typedef struct _wfs_idc_parse_data
{
    LPSTR             lpstrFormName;                            // xfs-sst-js:{name:"data.field", defaultValue:null }
    LPWFSIDCCARDDATA  *lppCardData;                             // xfs-sst-js:{name:"data.field", ntArray:true, defaultValue:{}} // tbd
} WFSIDCPARSEDATA, * LPWFSIDCPARSEDATA;
// xfs-sst-js:{name:"end"}


/*=================================================================*/
/* IDC Message Structures */
/*=================================================================*/

// xfs-sst-js:{name:"data", type:"WFSIDCTRACKEVENT", codeName:"IdcTrackEvent", leading:3, output:true, input:false, command:"WFS_EXEE_IDC_INVALIDTRACKDATA"}
typedef struct _wfs_idc_track_event
{
    WORD            fwStatus;                               // xfs-sst-js:{name:"data.field"}
    LPSTR           lpstrTrack;                             // xfs-sst-js:{name:"data.field"}
    LPSTR           lpstrData;                              // xfs-sst-js:{name:"data.field"}
} WFSIDCTRACKEVENT, * LPWFSIDCTRACKEVENT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSIDCCARDACT", codeName:"IdcCardAct", leading:3, output:true, input:false, command:"WFS_SRVE_IDC_CARDACTION"}
typedef struct _wfs_idc_card_act
{
    WORD            wAction;
    WORD            wPosition;
} WFSIDCCARDACT, * LPWFSIDCCARDACT;
// xfs-sst-js:{name:"end"}


/*   restore alignment   */
#pragma pack(pop)

#ifdef __cplusplus
}       /*extern "C"*/
#endif

#endif  /* __INC_XFSIDC__H */
