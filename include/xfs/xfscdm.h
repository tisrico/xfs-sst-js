/******************************************************************************
*                                                                             *
* xfscdm.h      XFS - Cash Dispenser (CDM) definitions                        *
*                                                                             *
*               Version 3.00 (10/18/00)                                       *
*                                                                             *
******************************************************************************/
 
#ifndef __INC_XFSCDM__H
#define __INC_XFSCDM__H

#ifdef __cplusplus
extern "C" {
#endif

#include <xfsapi.h>

/* be aware of alignment */
#pragma pack (push, 1)

/* values of WFSCDMCAPS.wClass */

// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMCAPS.wClass"], codeName:"XfsServiceClass"}
#define     WFS_SERVICE_CLASS_CDM               (3)
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"nc", bitwise:false, applies:[], codeName:"XfsClassVersion"}    
#define     WFS_SERVICE_CLASS_VERSION_CDM       0x0003
// xfs-sst-js:{name:"end"}

#define     WFS_SERVICE_CLASS_NAME_CDM          "CDM"

#define     CDM_SERVICE_OFFSET                  (WFS_SERVICE_CLASS_CDM * 100)

/* CDM Info Commands */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.u.dwCommandCode"], codeName:"XfsInfoCmd"}
#define     WFS_INF_CDM_STATUS                  (CDM_SERVICE_OFFSET + 1)
#define     WFS_INF_CDM_CAPABILITIES            (CDM_SERVICE_OFFSET + 2)
#define     WFS_INF_CDM_CASH_UNIT_INFO          (CDM_SERVICE_OFFSET + 3)
#define     WFS_INF_CDM_TELLER_INFO             (CDM_SERVICE_OFFSET + 4)
#define     WFS_INF_CDM_CURRENCY_EXP            (CDM_SERVICE_OFFSET + 6)
#define     WFS_INF_CDM_MIX_TYPES               (CDM_SERVICE_OFFSET + 7)
#define     WFS_INF_CDM_MIX_TABLE               (CDM_SERVICE_OFFSET + 8)
#define     WFS_INF_CDM_PRESENT_STATUS          (CDM_SERVICE_OFFSET + 9)
// xfs-sst-js:{name:"end"}

/* CDM Execute Commands */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.u.dwCommandCode"], codeName:"XfsExecuteCmd"}
#define     WFS_CMD_CDM_DENOMINATE              (CDM_SERVICE_OFFSET + 1)
#define     WFS_CMD_CDM_DISPENSE                (CDM_SERVICE_OFFSET + 2)
#define     WFS_CMD_CDM_PRESENT                 (CDM_SERVICE_OFFSET + 3)
#define     WFS_CMD_CDM_REJECT                  (CDM_SERVICE_OFFSET + 4)
#define     WFS_CMD_CDM_RETRACT                 (CDM_SERVICE_OFFSET + 5)
#define     WFS_CMD_CDM_OPEN_SHUTTER            (CDM_SERVICE_OFFSET + 7)
#define     WFS_CMD_CDM_CLOSE_SHUTTER           (CDM_SERVICE_OFFSET + 8)
#define     WFS_CMD_CDM_SET_TELLER_INFO         (CDM_SERVICE_OFFSET + 9)
#define     WFS_CMD_CDM_SET_CASH_UNIT_INFO      (CDM_SERVICE_OFFSET + 10)
#define     WFS_CMD_CDM_START_EXCHANGE          (CDM_SERVICE_OFFSET + 11)
#define     WFS_CMD_CDM_END_EXCHANGE            (CDM_SERVICE_OFFSET + 12)
#define     WFS_CMD_CDM_OPEN_SAFE_DOOR          (CDM_SERVICE_OFFSET + 13)
#define     WFS_CMD_CDM_CALIBRATE_CASH_UNIT     (CDM_SERVICE_OFFSET + 15)
#define     WFS_CMD_CDM_SET_MIX_TABLE           (CDM_SERVICE_OFFSET + 20)
#define     WFS_CMD_CDM_RESET                   (CDM_SERVICE_OFFSET + 21)
#define     WFS_CMD_CDM_TEST_CASH_UNITS         (CDM_SERVICE_OFFSET + 22)
#define     WFS_CMD_CDM_COUNT                   (CDM_SERVICE_OFFSET + 23)
// xfs-sst-js:{name:"end"}

/* CDM Messages */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.u.dwEventID"], codeName:"XfsEvent"}
#define     WFS_SRVE_CDM_SAFEDOOROPEN           (CDM_SERVICE_OFFSET + 1)
#define     WFS_SRVE_CDM_SAFEDOORCLOSED         (CDM_SERVICE_OFFSET + 2)
#define     WFS_USRE_CDM_CASHUNITTHRESHOLD      (CDM_SERVICE_OFFSET + 3)
#define     WFS_SRVE_CDM_CASHUNITINFOCHANGED    (CDM_SERVICE_OFFSET + 4)
#define     WFS_SRVE_CDM_TELLERINFOCHANGED      (CDM_SERVICE_OFFSET + 5)
#define     WFS_EXEE_CDM_DELAYEDDISPENSE        (CDM_SERVICE_OFFSET + 6)
#define     WFS_EXEE_CDM_STARTDISPENSE          (CDM_SERVICE_OFFSET + 7)
#define     WFS_EXEE_CDM_CASHUNITERROR          (CDM_SERVICE_OFFSET + 8)
#define     WFS_SRVE_CDM_ITEMSTAKEN             (CDM_SERVICE_OFFSET + 9)
#define     WFS_EXEE_CDM_PARTIALDISPENSE        (CDM_SERVICE_OFFSET + 10)
#define     WFS_EXEE_CDM_SUBDISPENSEOK          (CDM_SERVICE_OFFSET + 11)
#define     WFS_SRVE_CDM_ITEMSPRESENTED         (CDM_SERVICE_OFFSET + 13)
#define     WFS_SRVE_CDM_COUNTS_CHANGED         (CDM_SERVICE_OFFSET + 14)
#define     WFS_EXEE_CDM_INCOMPLETEDISPENSE     (CDM_SERVICE_OFFSET + 15)
#define     WFS_EXEE_CDM_NOTEERROR              (CDM_SERVICE_OFFSET + 16)
#define     WFS_EXEE_CDM_MEDIADETECTED          (CDM_SERVICE_OFFSET + 17) //is not used
#define     WFS_SRVE_CDM_MEDIADETECTED          (CDM_SERVICE_OFFSET + 17) //Added by Nexus Software - the name is changed to match the name specified
																		  //in document - The Media Detected service event may be generated as a result of a WFS_CMD_CDM_RESET.
// xfs-sst-js:{name:"end"}

/* values of WFSCDMSTATUS.fwDevice */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMSTATUS.fwDevice"], codeName:"XfsCdmDevStatus"}
#define     WFS_CDM_DEVONLINE                   WFS_STAT_DEVONLINE
#define     WFS_CDM_DEVOFFLINE                  WFS_STAT_DEVOFFLINE
#define     WFS_CDM_DEVPOWEROFF                 WFS_STAT_DEVPOWEROFF
#define     WFS_CDM_DEVNODEVICE                 WFS_STAT_DEVNODEVICE
#define     WFS_CDM_DEVHWERROR                  WFS_STAT_DEVHWERROR
#define     WFS_CDM_DEVUSERERROR                WFS_STAT_DEVUSERERROR
#define     WFS_CDM_DEVBUSY                     WFS_STAT_DEVBUSY
// xfs-sst-js:{name:"end"}

/* values of WFSCDMSTATUS.fwSafeDoor */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMSTATUS.fwSafeDoor"], codeName:"XfsCdmSafeDoor"}
#define     WFS_CDM_DOORNOTSUPPORTED            (1)
#define     WFS_CDM_DOOROPEN                    (2)
#define     WFS_CDM_DOORCLOSED                  (3)
#define     WFS_CDM_DOORUNKNOWN                 (5)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMSTATUS.fwDispenser */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMSTATUS.fwDispenser"], codeName:"XfsCdmDispensorStatus"}
#define     WFS_CDM_DISPOK                      (0)
#define     WFS_CDM_DISPCUSTATE                 (1)
#define     WFS_CDM_DISPCUSTOP                  (2)
#define     WFS_CDM_DISPCUUNKNOWN               (3)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMSTATUS.fwIntermediateStacker */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMSTATUS.fwIntermediateStacker"], codeName:"XfsCdmIntermediateStacker"}
#define     WFS_CDM_ISEMPTY                     (0)
#define     WFS_CDM_ISNOTEMPTY                  (1)
#define     WFS_CDM_ISNOTEMPTYCUST              (2)
#define     WFS_CDM_ISNOTEMPTYUNK               (3)
#define     WFS_CDM_ISUNKNOWN                   (4)
#define     WFS_CDM_ISNOTSUPPORTED              (5)
// xfs-sst-js:{name:"end"}


/* values of WFSCDMOUTPOS.fwShutter */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMOUTPOS.fwShutter"], codeName:"XfsCdmShutterStatus"}
#define     WFS_CDM_SHTCLOSED                   (0)
#define     WFS_CDM_SHTOPEN                     (1)
#define     WFS_CDM_SHTJAMMED                   (2)
#define     WFS_CDM_SHTUNKNOWN                  (3)
#define     WFS_CDM_SHTNOTSUPPORTED             (4)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMOUTPOS.fwPositionStatus */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMOUTPOS.fwPositionStatus"], codeName:"XfsCdmPositionStatus"}
#define     WFS_CDM_PSEMPTY                     (0)
#define     WFS_CDM_PSNOTEMPTY                  (1)
#define     WFS_CDM_PSUNKNOWN                   (2)
#define     WFS_CDM_PSNOTSUPPORTED              (3)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMOUTPOS.fwTransport */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMOUTPOS.fwTransport"], codeName:"XfsCdmTransportState"}
#define     WFS_CDM_TPOK                        (0)
#define     WFS_CDM_TPINOP                      (1)
#define     WFS_CDM_TPUNKNOWN                   (2)
#define     WFS_CDM_TPNOTSUPPORTED              (3)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMOUTPOS.fwTransportStatus */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMOUTPOS.fwTransportStatus"], codeName:"XfsCdmTransportStatus"}
#define     WFS_CDM_TPSTATEMPTY                 (0)
#define     WFS_CDM_TPSTATNOTEMPTY              (1)
#define     WFS_CDM_TPSTATNOTEMPTYCUST          (2)
#define     WFS_CDM_TPSTATNOTEMPTY_UNK          (3)
#define     WFS_CDM_TPSTATNOTSUPPORTED          (4)
// xfs-sst-js:{name:"end"}


/* values of WFSCDMCAPS.fwType */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMCAPS.fwType"], codeName:"XfsCdmType"}
#define     WFS_CDM_TELLERBILL                  (0)
#define     WFS_CDM_SELFSERVICEBILL             (1)
#define     WFS_CDM_TELLERCOIN                  (2)
#define     WFS_CDM_SELFSERVICECOIN             (3)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMCAPS.fwRetractAreas */
/* values of WFSCDMRETRACT.usRetractArea */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMCAPS.fwRetractAreas", "WFSCDMRETRACT.usRetractArea"], codeName:"XfsCdmRetractArea"}
#define     WFS_CDM_RA_RETRACT                  (0x0001)
#define     WFS_CDM_RA_TRANSPORT                (0x0002)
#define     WFS_CDM_RA_STACKER                  (0x0004)
#define     WFS_CDM_RA_REJECT                   (0x0008)
#define     WFS_CDM_RA_NOTSUPP                  (0x0010)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMCAPS.fwRetractTransportActions */
/* values of WFSCDMCAPS.fwRetractStackerActions */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMCAPS.fwRetractTransportActions", "WFSCDMCAPS.fwRetractStackerActions", "WFSCDMRETRACT.fwRetractStackerActions"], codeName:"XfsCdmRetractStackerActions"}
#define     WFS_CDM_PRESENT                     (0x0001)
#define     WFS_CDM_RETRACT                     (0x0002)
#define     WFS_CDM_REJECT                      (0x0004)
#define     WFS_CDM_NOTSUPP                     (0x0008)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMCAPS.fwMoveItems */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMCAPS.fwMoveItems"], codeName:"XfsCdmMoveItems"}
#define     WFS_CDM_FROMCU                      (0x0001)
#define     WFS_CDM_TOCU                        (0x0002)
#define     WFS_CDM_TOTRANSPORT                 (0x0004)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMCASHUNIT.usType */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMCASHUNIT.usType"], codeName:"XfsCdmCashUnitType"}
#define     WFS_CDM_TYPENA                      (1)
#define     WFS_CDM_TYPEREJECTCASSETTE          (2)
#define     WFS_CDM_TYPEBILLCASSETTE            (3)
#define     WFS_CDM_TYPECOINCYLINDER            (4)
#define     WFS_CDM_TYPECOINDISPENSER           (5)
#define     WFS_CDM_TYPERETRACTCASSETTE         (6)
#define     WFS_CDM_TYPECOUPON                  (7)
#define     WFS_CDM_TYPEDOCUMENT                (8)
#define     WFS_CDM_TYPEREPCONTAINER           (11)
#define     WFS_CDM_TYPERECYCLING              (12)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMCASHUNIT.usStatus */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMCASHUNIT.usStatus", "WFSCDMCOUNTEDPHYSCU.usPStatus", "WFSCDMPHCU.usPStatus"], codeName:"XfsCdmCashUnitStatus"}
#define     WFS_CDM_STATCUOK                    (0)
#define     WFS_CDM_STATCUFULL                  (1)
#define     WFS_CDM_STATCUHIGH                  (2)
#define     WFS_CDM_STATCULOW                   (3)
#define     WFS_CDM_STATCUEMPTY                 (4)
#define     WFS_CDM_STATCUINOP                  (5)
#define     WFS_CDM_STATCUMISSING               (6)
#define     WFS_CDM_STATCUNOVAL                 (7)
#define     WFS_CDM_STATCUNOREF                 (8)
#define     WFS_CDM_STATCUMANIP                 (9)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMMIXTYPE.usMixType */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMCASHUNIT.usMixType"], codeName:"XfsCdmMixType"}
#define     WFS_CDM_MIXALGORITHM                (1)
#define     WFS_CDM_MIXTABLE                    (2)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMMIXTYPE.usMixNumber */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMCASHUNIT.usMixNumber"], codeName:"XfsCdmMixNumber"}
#define     WFS_CDM_INDIVIDUAL                  (0)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMMIXTYPE.usSubType (predefined mix algorithms) */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMMIXTYPE.usSubType"], codeName:"XfsCdmMixSubType"}
#define     WFS_CDM_MIX_MINIMUM_NUMBER_OF_BILLS            (1)
#define     WFS_CDM_MIX_EQUAL_EMPTYING_OF_CASH_UNITS       (2)
#define     WFS_CDM_MIX_MAXIMUM_NUMBER_OF_CASH_UNITS       (3)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMPRESENTSTATUS.wPresentState */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSCDMPRESENTSTATUS.wPresentState"], codeName:"XfsCdmPresentStatus"}
#define     WFS_CDM_PRESENTED                   (1)
#define     WFS_CDM_NOTPRESENTED                (2)
#define     WFS_CDM_UNKNOWN                     (3)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMDISPENSE.fwPosition */
/* values of WFSCDMCAPS.fwPositions */
/* values of WFSCDMOUTPOS.fwPosition */
/* values of WFSCDMTELLERPOS.fwPosition */
/* values of WFSCDMTELLERDETAILS.fwOutputPosition */
/* values of WFSCDMPHYSICALCU.fwPosition */

// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSCDMTELLERDETAILSIN.ulInputPosition", "WFSCDMTELLERDETAILSIN.fwOutputPosition", "WFSCDMCLOSESHUTTER.fwPosition", "WFSCDMPRESENTSTATUSIN.fwPosition", "WFSCDMDISPENSE.fwPosition","WFSCDMCAPS.fwPositions","WFSCDMOUTPOS.fwPosition","WFSCDMTELLERPOS.fwPosition","WFSCDMTELLERDETAILS.fwOutputPosition","WFSCDMPHYSICALCU.fwPosition", "WFSCDMPRESENTPOSITION.fwPosition"], codeName:"XfsCdmDispensePosition"}
#define     WFS_CDM_POSNULL                     (0x0000)
#define     WFS_CDM_POSLEFT                     (0x0001)
#define     WFS_CDM_POSRIGHT                    (0x0002)
#define     WFS_CDM_POSCENTER                   (0x0004)
#define     WFS_CDM_POSTOP                      (0x0040)
#define     WFS_CDM_POSBOTTOM                   (0x0080)
#define     WFS_CDM_POSREJECT                   (0x0100)
#define     WFS_CDM_POSFRONT                    (0x0800)
#define     WFS_CDM_POSREAR                     (0x1000)
// xfs-sst-js:{name:"end"}

/* values of WFSCDMTELLERDETAILS.ulInputPosition */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSCDMTELLERDETAILS.ulInputPosition"], codeName:"XfsCdmInputPosition"}
#define     WFS_CDM_POSINLEFT                   (0x0001)
#define     WFS_CDM_POSINRIGHT                  (0x0002)
#define     WFS_CDM_POSINCENTER                 (0x0004)
#define     WFS_CDM_POSINTOP                    (0x0008)
#define     WFS_CDM_POSINBOTTOM                 (0x0010)
#define     WFS_CDM_POSINFRONT                  (0x0020)
#define     WFS_CDM_POSINREAR                   (0x0040)
// xfs-sst-js:{name:"end"}

/* values of fwExchangeType */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSCDMCAPS.fwExchangeType", "WFSCDMSTARTEX.fwExchangeType"], codeName:"XfsCdmExchangeType"}
#define     WFS_CDM_EXBYHAND                    (0x0001)
#define     WFS_CDM_EXTOCASSETTES               (0x0002)
// xfs-sst-js:{name:"end"}


/* values of WFSCDMTELLERUPDATE.usAction */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSCDMTELLERUPDATESETTI.usAction", "WFSCDMTELLERUPDATE.usAction"], codeName:"XfsCdmTellerUpdateAction"}
#define     WFS_CDM_CREATE_TELLER               (1)
#define     WFS_CDM_MODIFY_TELLER               (2)
#define     WFS_CDM_DELETE_TELLER               (3)
// xfs-sst-js:{name:"end"}


/* values of WFSCDMCUERROR.wFailure */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSCDMCUERROR.wFailure"], codeName:"XfsCdmMcuErrors"}
#define     WFS_CDM_CASHUNITEMPTY               (1)
#define     WFS_CDM_CASHUNITERROR               (2)
#define     WFS_CDM_CASHUNITFULL                (4)
#define     WFS_CDM_CASHUNITLOCKED              (5)
#define     WFS_CDM_CASHUNITINVALID             (6)
#define     WFS_CDM_CASHUNITCONFIG              (7)
// xfs-sst-js:{name:"end"}


/* values of lpusReason in WFS_EXEE_CDM_NOTESERROR */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFS_EXEE_CDM_NOTESERROR.WFS_EXEE_CDM_NOTESERROR"], codeName:"XfsCdmNotesError"}
#define     WFS_CDM_DOUBLENOTEDETECTED          (1)
#define     WFS_CDM_LONGNOTEDETECTED            (2)
#define     WFS_CDM_SKEWEDNOTE                  (3)
#define     WFS_CDM_INCORRECTCOUNT              (4)
#define     WFS_CDM_NOTESTOOCLOSE               (5)
// xfs-sst-js:{name:"end"}


/* WOSA/XFS CDM Errors */ 
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.hResult"], codeName:"XfsErrorCode"}
#define WFS_ERR_CDM_INVALIDCURRENCY         (-(CDM_SERVICE_OFFSET + 0))
#define WFS_ERR_CDM_INVALIDTELLERID         (-(CDM_SERVICE_OFFSET + 1))
#define WFS_ERR_CDM_CASHUNITERROR           (-(CDM_SERVICE_OFFSET + 2))
#define WFS_ERR_CDM_INVALIDDENOMINATION     (-(CDM_SERVICE_OFFSET + 3))
#define WFS_ERR_CDM_INVALIDMIXNUMBER        (-(CDM_SERVICE_OFFSET + 4))
#define WFS_ERR_CDM_NOCURRENCYMIX           (-(CDM_SERVICE_OFFSET + 5))
#define WFS_ERR_CDM_NOTDISPENSABLE          (-(CDM_SERVICE_OFFSET + 6))
#define WFS_ERR_CDM_TOOMANYITEMS            (-(CDM_SERVICE_OFFSET + 7))
#define WFS_ERR_CDM_UNSUPPOSITION           (-(CDM_SERVICE_OFFSET + 8))
#define WFS_ERR_CDM_SAFEDOOROPEN            (-(CDM_SERVICE_OFFSET + 10))
#define WFS_ERR_CDM_SHUTTERNOTOPEN          (-(CDM_SERVICE_OFFSET + 12))
#define WFS_ERR_CDM_SHUTTEROPEN             (-(CDM_SERVICE_OFFSET + 13))
#define WFS_ERR_CDM_SHUTTERCLOSED           (-(CDM_SERVICE_OFFSET + 14))
#define WFS_ERR_CDM_INVALIDCASHUNIT         (-(CDM_SERVICE_OFFSET + 15))
#define WFS_ERR_CDM_NOITEMS                 (-(CDM_SERVICE_OFFSET + 16))
#define WFS_ERR_CDM_EXCHANGEACTIVE          (-(CDM_SERVICE_OFFSET + 17))
#define WFS_ERR_CDM_NOEXCHANGEACTIVE        (-(CDM_SERVICE_OFFSET + 18))
#define WFS_ERR_CDM_SHUTTERNOTCLOSED        (-(CDM_SERVICE_OFFSET + 19))
#define WFS_ERR_CDM_PRERRORNOITEMS          (-(CDM_SERVICE_OFFSET + 20))
#define WFS_ERR_CDM_PRERRORITEMS            (-(CDM_SERVICE_OFFSET + 21))
#define WFS_ERR_CDM_PRERRORUNKNOWN          (-(CDM_SERVICE_OFFSET + 22))
#define WFS_ERR_CDM_ITEMSTAKEN              (-(CDM_SERVICE_OFFSET + 23))
#define WFS_ERR_CDM_INVALIDMIXTABLE         (-(CDM_SERVICE_OFFSET + 27))
#define WFS_ERR_CDM_OUTPUTPOS_NOT_EMPTY     (-(CDM_SERVICE_OFFSET + 28))
#define WFS_ERR_CDM_INVALIDRETRACTPOSITION  (-(CDM_SERVICE_OFFSET + 29))
#define WFS_ERR_CDM_NOTRETRACTAREA          (-(CDM_SERVICE_OFFSET + 30))
#define WFS_ERR_CDM_NOCASHBOXPRESENT        (-(CDM_SERVICE_OFFSET + 33))
#define WFS_ERR_CDM_AMOUNTNOTINMIXTABLE     (-(CDM_SERVICE_OFFSET + 34))
#define WFS_ERR_CDM_ITEMSNOTTAKEN           (-(CDM_SERVICE_OFFSET + 35))
#define WFS_ERR_CDM_ITEMSLEFT               (-(CDM_SERVICE_OFFSET + 36))
// xfs-sst-js:{name:"end"}


/*=================================================================*/
/* CDM Info Command Structures */
/*=================================================================*/
// xfs-sst-js:{name:"data", type:"WFSCDMOUTPOS", codeName:"CdmPosition", leading:3, output:true, input:false, command:""}
typedef struct _wfs_cdm_position
{
    WORD            fwPosition;                 // xfs-sst-js:{name:"data.field"}
    WORD            fwShutter;                  // xfs-sst-js:{name:"data.field"}
    WORD            fwPositionStatus;           // xfs-sst-js:{name:"data.field"}
    WORD            fwTransport;                // xfs-sst-js:{name:"data.field"}
    WORD            fwTransportStatus;          // xfs-sst-js:{name:"data.field"}
} WFSCDMOUTPOS, * LPWFSCDMOUTPOS;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMSTATUS", codeName:"CdmStatus", leading:3, output:true, input:false, command:"WFS_INF_CDM_STATUS"}
typedef struct _wfs_cdm_status
{
    WORD             fwDevice;                  // xfs-sst-js:{name:"data.field"}
    WORD             fwSafeDoor;                // xfs-sst-js:{name:"data.field"}
    WORD             fwDispenser;               // xfs-sst-js:{name:"data.field"}
    WORD             fwIntermediateStacker;     // xfs-sst-js:{name:"data.field"}
    LPWFSCDMOUTPOS * lppPositions;              // xfs-sst-js:{name:"data.field", ntArray:true}
    LPSTR            lpszExtra;                 // xfs-sst-js:{name:"data.field"}
} WFSCDMSTATUS, * LPWFSCDMSTATUS;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCAPS", codeName:"CdmCaps", leading:3, output:true, input:false, command:"WFS_INF_CDM_CAPABILITIES"}
typedef struct _wfs_cdm_caps
{
    WORD            wClass;                     // xfs-sst-js:{name:"data.field"}
    WORD            fwType;                     // xfs-sst-js:{name:"data.field"}
    WORD            wMaxDispenseItems;          // xfs-sst-js:{name:"data.field"}
    BOOL            bCompound;                  // xfs-sst-js:{name:"data.field"}
    BOOL            bShutter;                   // xfs-sst-js:{name:"data.field"}
    BOOL            bShutterControl;            // xfs-sst-js:{name:"data.field"}
    WORD            fwRetractAreas;             // xfs-sst-js:{name:"data.field"}
    WORD            fwRetractTransportActions;  // xfs-sst-js:{name:"data.field"}
    WORD            fwRetractStackerActions;    // xfs-sst-js:{name:"data.field"}
    BOOL            bSafeDoor;                  // xfs-sst-js:{name:"data.field"}
    BOOL            bCashBox;                   // xfs-sst-js:{name:"data.field"}
    BOOL            bIntermediateStacker;       // xfs-sst-js:{name:"data.field"}
    BOOL            bItemsTakenSensor;          // xfs-sst-js:{name:"data.field"}
    WORD            fwPositions;                // xfs-sst-js:{name:"data.field"}
    WORD            fwMoveItems;                // xfs-sst-js:{name:"data.field"}
    WORD            fwExchangeType;             // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszExtra;                  // xfs-sst-js:{name:"data.field"}
} WFSCDMCAPS, * LPWFSCDMCAPS;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMPHCU", codeName:"CdmPhyCashUnit", leading:3, output:true, input:true, command:""}
typedef struct _wfs_cdm_physicalcu
{
    LPSTR           lpPhysicalPositionName;     // xfs-sst-js:{name:"data.field"}
    __CHARRAY       cUnitID[5];                 // xfs-sst-js:{name:"data.field", fixedArrayNNT:true, defautValue:null}
    ULONG           ulInitialCount;             // xfs-sst-js:{name:"data.field"}
    ULONG           ulCount;                    // xfs-sst-js:{name:"data.field"}
    ULONG           ulRejectCount;              // xfs-sst-js:{name:"data.field"}
    ULONG           ulMaximum;                  // xfs-sst-js:{name:"data.field"}
    USHORT          usPStatus;                  // xfs-sst-js:{name:"data.field"}
    BOOL            bHardwareSensor;            // xfs-sst-js:{name:"data.field"}
} WFSCDMPHCU, * LPWFSCDMPHCU;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCASHUNIT", codeName:"CdmCashUnit", leading:3, output:true, input:true, command:""}
typedef struct _wfs_cdm_cashunit
{
    USHORT          usNumber;                   // xfs-sst-js:{name:"data.field"}
    USHORT          usType;                     // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszCashUnitName;           // xfs-sst-js:{name:"data.field"}
    __CHARRAY       cUnitID[5];                 // xfs-sst-js:{name:"data.field", fixedArrayNNT:true, defautValue:null}
    __CHARRAY       cCurrencyID[3];             // xfs-sst-js:{name:"data.field", fixedArrayNNT:true, defautValue:null}
    ULONG           ulValues;                   // xfs-sst-js:{name:"data.field"}
    ULONG           ulInitialCount;             // xfs-sst-js:{name:"data.field"}
    ULONG           ulCount;                    // xfs-sst-js:{name:"data.field"}
    ULONG           ulRejectCount;              // xfs-sst-js:{name:"data.field"}
    ULONG           ulMinimum;                  // xfs-sst-js:{name:"data.field"}
    ULONG           ulMaximum;                  // xfs-sst-js:{name:"data.field"}
    BOOL            bAppLock;                   // xfs-sst-js:{name:"data.field"}
    USHORT          usStatus;                   // xfs-sst-js:{name:"data.field"}
    USHORT          usNumPhysicalCUs;           // xfs-sst-js:{name:"data.field"}
    LPWFSCDMPHCU   *lppPhysical;                // xfs-sst-js:{name:"data.field", ntArray:true}
} WFSCDMCASHUNIT, * LPWFSCDMCASHUNIT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCUINFO", codeName:"CdmCashUnitInfo", leading:3, output:true, input:false, command:"WFS_INF_CDM_CASH_UNIT_INFO"}
typedef struct _wfs_cdm_cu_info
{
    USHORT          usTellerID;             // xfs-sst-js:{name:"data.field"}
    USHORT          usCount;                // xfs-sst-js:{name:"data.field"}
    LPWFSCDMCASHUNIT *lppList;              // xfs-sst-js:{name:"data.field", ntArray:true}
} WFSCDMCUINFO, * LPWFSCDMCUINFO;
// xfs-sst-js:{name:"end"}

typedef struct _wfs_cdm_teller_info_
{
    USHORT          usTellerID;
    CHAR            cCurrencyID[3];
} WFSCDMTELLERINFO_, * LPWFSCDMTELLERINFO_;

// xfs-sst-js:{name:"data", type:"WFSCDMTELLERINFO", codeName:"CdmTellerInfo", leading:3, output:false, input:true, command:"WFS_INF_CDM_TELLER_INFO"}
typedef struct _wfs_cdm_teller_info
{
    USHORT          usTellerID;              // xfs-sst-js:{name:"data.field", defaultValue:0}
    __CHARRAY       cCurrencyID[3];          // xfs-sst-js:{name:"data.field", fixedArray:true, arrayLength:3, defaultValue:null}
} WFSCDMTELLERINFO, * LPWFSCDMTELLERINFO;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMTELLERTOTALS", codeName:"CdmTellerTotal", leading:3, output:true, input:false, command:""}
typedef struct _wfs_cdm_teller_totals
{
   char             cCurrencyID[3];                 // xfs-sst-js:{name:"data.field", fixedArrayNNT:true}
   ULONG            ulItemsReceived;                // xfs-sst-js:{name:"data.field"}
   ULONG            ulItemsDispensed;               // xfs-sst-js:{name:"data.field"}
   ULONG            ulCoinsReceived;                // xfs-sst-js:{name:"data.field"}
   ULONG            ulCoinsDispensed;               // xfs-sst-js:{name:"data.field"}
   ULONG            ulCashBoxReceived;              // xfs-sst-js:{name:"data.field"}
   ULONG            ulCashBoxDispensed;             // xfs-sst-js:{name:"data.field"}
} WFSCDMTELLERTOTALS, * LPWFSCDMTELLERTOTALS;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMTELLERDETAILS", codeName:"CdmTellerDetails", leading:3, output:true, input:false, command:"WFS_INF_CDM_TELLER_INFO"}
typedef struct _wfs_cdm_teller_details
{
    USHORT                usTellerID;                   // xfs-sst-js:{name:"data.field"}
    ULONG                 ulInputPosition;              // xfs-sst-js:{name:"data.field"}
    WORD                  fwOutputPosition;             // xfs-sst-js:{name:"data.field"}
    LPWFSCDMTELLERTOTALS *lppTellerTotals;              // xfs-sst-js:{name:"data.field", ntArray:true}
} WFSCDMTELLERDETAILS, * LPWFSCDMTELLERDETAILS;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCURRENCYEXP", codeName:"CdmCurrencyExp", leading:3, output:true, input:false, command:"WFS_INF_CDM_CURRENCY_EXP"}
typedef struct _wfs_cdm_currency_exp
{
    CHAR            cCurrencyID[3];                     // xfs-sst-js:{name:"data.field", fixedArrayNNT:true}
    SHORT           sExponent;                          // xfs-sst-js:{name:"data.field"}
} WFSCDMCURRENCYEXP, * LPWFSCDMCURRENCYEXP;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMMIXTYPE", codeName:"CdmMixType", leading:3, output:true, input:false, command:"WFS_INF_CDM_MIX_TYPES"}
typedef struct _wfs_cdm_mix_type
{
    USHORT          usMixNumber;                     // xfs-sst-js:{name:"data.field"}
    USHORT          usMixType;                       // xfs-sst-js:{name:"data.field"}
    USHORT          usSubType;                       // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszName;                        // xfs-sst-js:{name:"data.field"}
} WFSCDMMIXTYPE, * LPWFSCDMMIXTYPE;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMMIXROW", codeName:"CdmMixRow", leading:3, output:true, input:true, command:""}
typedef struct _wfs_cdm_mix_row
{
    ULONG           ulAmount;                   // xfs-sst-js:{name:"data.field"}
    LPUSHORT        lpusMixture;                // xfs-sst-js:{name:"data.field"}
} WFSCDMMIXROW, * LPWFSCDMMIXROW;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMMIXTABLE", codeName:"CdmMixTable", leading:3, output:true, input:false, command:"WFS_INF_CDM_MIX_TABLE"}
typedef struct _wfs_cdm_mix_table
{
    USHORT          usMixNumber;                    // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszName;                       // xfs-sst-js:{name:"data.field"}
    USHORT          usRows;                         // xfs-sst-js:{name:"data.field"}
    USHORT          usCols;                         // xfs-sst-js:{name:"data.field"}
    LPULONG         lpulMixHeader;                  // xfs-sst-js:{name:"data.field", fixedArrayPointers:true, fixedArrayPointersLength:"p->usCols"}
    LPWFSCDMMIXROW  *lppMixRows;                    // xfs-sst-js:{name:"data.field", ntArray:true}
} WFSCDMMIXTABLE, * LPWFSCDMMIXTABLE;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMDENOMINATION", codeName:"CdmDenomination", leading:3, output:true, input:false, command:""}
typedef struct _wfs_cdm_denomination
{
    CHAR            cCurrencyID[3];                 // xfs-sst-js:{name:"data.field", fixedArrayNNT:true}
    ULONG           ulAmount;                       // xfs-sst-js:{name:"data.field"}
    USHORT          usCount;                        // xfs-sst-js:{name:"data.field"}
    LPULONG         lpulValues;                     // xfs-sst-js:{name:"data.field", fixedArrayPointers:true, fixedArrayPointersLength:"p->usCount"}
    ULONG           ulCashBox;                      // xfs-sst-js:{name:"data.field"}
} WFSCDMDENOMINATION, * LPWFSCDMDENOMINATION;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMDENOMINATIONIN", codeName:"CdmDenominationIn", leading:3, output:false, input:true, command:""}
typedef struct _wfs_cdm_denomination_in
{
	__CHARRAY       cCurrencyID[3];                 // xfs-sst-js:{name:"data.field", fixedArrayNNT:true}
	ULONG           ulAmount;                       // xfs-sst-js:{name:"data.field"}
	USHORT          usCount;                        // xfs-sst-js:{name:"not.used.data.field"}
	LPULONG         lpulValues;                     // xfs-sst-js:{name:"data.field", pointer2FixedArray:true, pointer2FixedArrayLength:"p->usCount"}
	ULONG           ulCashBox;                      // xfs-sst-js:{name:"data.field"}
} WFSCDMDENOMINATIONIN, *LPWFSCDMDENOMINATIONIN;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMPRESENTSTATUS", codeName:"CdmPresentStatus", leading:3, output:true, input:false, command:"WFS_INF_CDM_PRESENT_STATUS"}
typedef struct _wfs_cdm_present_status
{
    LPWFSCDMDENOMINATION  lpDenomination;           // xfs-sst-js:{name:"data.field"}
    WORD                  wPresentState;            // xfs-sst-js:{name:"data.field"}
    LPSTR                 lpszExtra;                // xfs-sst-js:{name:"data.field"}
} WFSCDMPRESENTSTATUS, * LPWFSCDMPRESENTSTATUS;
// xfs-sst-js:{name:"end"}

/*=================================================================*/
/* CDM Execute Command Structures */
/*=================================================================*/

// xfs-sst-js:{name:"data", type:"WFSCDMDENOMINATE", codeName:"CdmDenominate", leading:3, output:false, input:true, command:"WFS_CMD_CDM_DENOMINATE"}
typedef struct _wfs_cdm_denominate
{
    USHORT					usTellerID;               // xfs-sst-js:{name:"data.field", defaultValue:0}
    USHORT					usMixNumber;              // xfs-sst-js:{name:"data.field", defaultValue:0}
    LPWFSCDMDENOMINATIONIN	lpDenomination;           // xfs-sst-js:{name:"data.field", defaultValue:[]}
} WFSCDMDENOMINATE, * LPWFSCDMDENOMINATE;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMDISPENSE", codeName:"CdmDispense", leading:3, output:false, input:true, command:"WFS_CMD_CDM_DISPENSE"}
typedef struct _wfs_cdm_dispense
{
    USHORT                usTellerID;               // xfs-sst-js:{name:"data.field", defaultValue:0}
    USHORT                usMixNumber;              // xfs-sst-js:{name:"data.field", defaultValue:0}
    WORD                  fwPosition;               // xfs-sst-js:{name:"data.field", defaultValue:0}
    BOOL                  bPresent;                 // xfs-sst-js:{name:"data.field", defaultValue:false}
    LPWFSCDMDENOMINATIONIN  lpDenomination;         // xfs-sst-js:{name:"data.field", defaultValue:[]}
} WFSCDMDISPENSE, * LPWFSCDMDISPENSE;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMPHYSICALCU", codeName:"CdmPhysicalCu", leading:3, output:false, input:true, command:"WFS_CMD_CDM_COUNT"}
typedef struct _wfs_cdm_physical_cu
{
    BOOL      bEmptyAll;                        // xfs-sst-js:{name:"data.field", defaultValue:true}
    WORD      fwPosition;                       // xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_POSNULL"}
    LPSTR     lpPhysicalPositionName;           //xfs-sst-js:{name:"data.field", defaultValue:null}
} WFSCDMPHYSICALCU, *LPWFSCDMPHYSICALCU;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCOUNTEDPHYSCU", codeName:"CdmCountedPhysCu", leading:3, output:true, input:false, command:""}
typedef struct _wfs_cdm_counted_phys_cu
{
    LPSTR        lpPhysicalPositionName;        //xfs-sst-js:{name:"data.field", defaultValue:null}
    CHAR         cUnitId[5];                    // xfs-sst-js:{name:"data.field", fixedArrayNNT:true}
    ULONG        ulDispensed;                   // xfs-sst-js:{name:"data.field"}
    ULONG        ulCounted;                     // xfs-sst-js:{name:"data.field"}
    USHORT       usPStatus;                     // xfs-sst-js:{name:"data.field"}
} WFSCDMCOUNTEDPHYSCU, *LPWFSCDMCOUNTEDPHYSCU;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCOUNT", codeName:"CdmCount", leading:3, output:true, input:false, command:"WFS_CMD_CDM_COUNT"}
typedef struct _wfs_cdm_count
{
    USHORT                  usNumPhysicalCUs;   // xfs-sst-js:{name:"data.field"}
    LPWFSCDMCOUNTEDPHYSCU  *lppCountedPhysCUs;  // xfs-sst-js:{name:"data.field", ntArray:true}
} WFSCDMCOUNT, *LPWFSCDMCOUNT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMRETRACT", codeName:"CdmRetract", leading:3, output:false, input:true, command:"WFS_CMD_CDM_RETRACT"}
typedef struct _wfs_cdm_retract
{
    WORD                  fwOutputPosition;     // xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_POSNULL"}
    USHORT                usRetractArea;        // xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_RA_RETRACT"}
    USHORT                usIndex;              // xfs-sst-js:{name:"data.field", defaultValue:0}
} WFSCDMRETRACT, * LPWFSCDMRETRACT;
// xfs-sst-js:{name:"end"}

typedef struct _wfs_cdm_teller_update
{
    USHORT                usAction;
    LPWFSCDMTELLERDETAILS lpTellerDetails;
} WFSCDMTELLERUPDATE, * LPWFSCDMTELLERUPDATE;

// xfs-sst-js:{name:"data", type:"WFSCDMSTARTEX", codeName:"CdmStartEx", leading:3, output:false, input:true, command:"WFS_CMD_CDM_START_EXCHANGE"}
typedef struct _wfs_cdm_start_ex
{
    WORD             fwExchangeType;			// xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_CREATE_TELLER"}
    USHORT           usTellerID;				// xfs-sst-js:{name:"data.field", defaultValue:0}
    USHORT           usCount;					
    LPUSHORT         lpusCUNumList;				// xfs-sst-js:{name:"data.field", defaultValue:[], pointer2FixedArray:true, pointer2FixedArrayLength:"p->usCount"}
} WFSCDMSTARTEX, * LPWFSCDMSTARTEX;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMITEMPOSITION", codeName:"CdmReset", leading:3, output:false, input:true, command:"WFS_CMD_CDM_RESET"}
typedef struct _wfs_cdm_itemposition
{
    USHORT             usNumber;				// xfs-sst-js:{name:"data.field", defaultValue:0}
    LPWFSCDMRETRACT    lpRetractArea;			// xfs-sst-js:{name:"data.field", defaultValue:null}
    WORD               fwOutputPosition;		// xfs-sst-js:{name:"data.field", defaultValue:"WFS_CDM_POSNULL"}
} WFSCDMITEMPOSITION, * LPWFSCDMITEMPOSITION;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSCDMCALIBRATE", codeName:"CdmPresentStatus", leading:3, output:true, input:false, command:"WFS_INF_CDM_PRESENT_STATUS"}
typedef struct _wfs_cdm_calibrate
{
    USHORT                   usNumber;
    USHORT                   usNumOfBills;
    LPWFSCDMITEMPOSITION    *lpPosition;
} WFSCDMCALIBRATE, * LPWFSCDMCALIBRATE;
// xfs-sst-js:{name:"end"}


/*=================================================================*/
/* CDM Message Structures */
/*=================================================================*/

typedef struct _wfs_cdm_cu_error
{
    WORD              wFailure;
    LPWFSCDMCASHUNIT  lpCashUnit;
} WFSCDMCUERROR, * LPWFSCDMCUERROR;
// xfs-sst-js:{name:"end"}

typedef struct _wfs_cdm_counts_changed
{
    USHORT            usCount;
    USHORT           *lpusCUNumList;
} WFSCDMCOUNTSCHANGED, * LPWFSCDMCOUNTSCHANGED;
// xfs-sst-js:{name:"end"}


/* restore alignment */
#pragma pack (pop)

#ifdef __cplusplus
}       /*extern "C"*/
#endif

#endif  /* __INC_XFSCDM__H */

