/******************************************************************************
*                                                                             *
* xfsdep.h   XFS - Depository (DEP) definitions                               *
*                                                                             *
*            Version 3.00  (10/18/00)                                         *
*                                                                             *
*******************************************************************************/

#ifndef __INC_XFSDEP__H
#define __INC_XFSDEP__H

#ifdef __cplusplus
extern "C" {
#endif

#include <xfsapi.h>

/*   be aware of alignment   */
#pragma pack(push,1)


/* values of WFSDEPCAPS.wClass */

#define    WFS_SERVICE_CLASS_DEP             (6)
#define    WFS_SERVICE_CLASS_VERSION_DEP     (0x0003)	/* Version 3.00 */
#define    WFS_SERVICE_CLASS_NAME_DEP        "DEP"

#define    DEP_SERVICE_OFFSET           (WFS_SERVICE_CLASS_DEP * 100)

/* DEP Info Commands */

#define    WFS_INF_DEP_STATUS           (DEP_SERVICE_OFFSET + 1)
#define    WFS_INF_DEP_CAPABILITIES     (DEP_SERVICE_OFFSET + 2)

/* DEP Execute Commands */

#define    WFS_CMD_DEP_ENTRY            (DEP_SERVICE_OFFSET + 1)
#define    WFS_CMD_DEP_DISPENSE         (DEP_SERVICE_OFFSET + 2)
#define    WFS_CMD_DEP_RETRACT          (DEP_SERVICE_OFFSET + 3)
#define    WFS_CMD_DEP_CLEAR_TRANSPORT  (DEP_SERVICE_OFFSET + 4)
#define    WFS_CMD_DEP_RESET_COUNT      (DEP_SERVICE_OFFSET + 5)
#define    WFS_CMD_DEP_RESET            (DEP_SERVICE_OFFSET + 6)


/* DEP Messages */

#define    WFS_SRVE_DEP_ENVTAKEN        (DEP_SERVICE_OFFSET + 1)
#define    WFS_EXEE_DEP_ENVDEPOSITED    (DEP_SERVICE_OFFSET + 2)
#define    WFS_EXEE_DEP_DEPOSITERROR    (DEP_SERVICE_OFFSET + 3)
#define    WFS_USRE_DEP_DEPTHRESHOLD    (DEP_SERVICE_OFFSET + 4)
#define    WFS_USRE_DEP_TONERTHRESHOLD  (DEP_SERVICE_OFFSET + 5)
#define    WFS_USRE_DEP_ENVTHRESHOLD    (DEP_SERVICE_OFFSET + 6)
#define    WFS_SRVE_DEP_CONTINSERTED    (DEP_SERVICE_OFFSET + 7)
#define    WFS_SRVE_DEP_CONTREMOVED     (DEP_SERVICE_OFFSET + 8) 
#define    WFS_SRVE_DEP_ENVINSERTED     (DEP_SERVICE_OFFSET + 9)
#define    WFS_SRVE_DEP_MEDIADETECTED   (DEP_SERVICE_OFFSET + 10)


/* values of WFSDEPSTATUS.fwDevice */
#define    WFS_DEP_DEVONLINE            WFS_STAT_DEVONLINE
#define    WFS_DEP_DEVOFFLINE           WFS_STAT_DEVOFFLINE
#define    WFS_DEP_DEVPOWEROFF          WFS_STAT_DEVPOWEROFF
#define    WFS_DEP_DEVBUSY              WFS_STAT_DEVBUSY
#define    WFS_DEP_DEVNODEVICE          WFS_STAT_DEVNODEVICE
#define    WFS_DEP_DEVHWERROR           WFS_STAT_DEVHWERROR
#define    WFS_DEP_DEVUSERERROR         WFS_STAT_DEVUSERERROR

/* values of WFSDEPSTATUS.fwDepContainer, fwDepTransport */

#define    WFS_DEP_DEPOK                (0)
#define    WFS_DEP_DEPHIGH              (1)
#define    WFS_DEP_DEPFULL              (2)
#define    WFS_DEP_DEPINOP              (3)
#define    WFS_DEP_DEPMISSING           (4)
#define    WFS_DEP_DEPUNKNOWN           (5)
#define    WFS_DEP_DEPNOTSUPP           (6)

/* values of WFSDEPSTATUS.fwEnvSupply, fwEnvDispenser */

#define    WFS_DEP_ENVOK                (0)
#define    WFS_DEP_ENVLOW               (1)
#define    WFS_DEP_ENVEMPTY             (2)
#define    WFS_DEP_ENVINOP              (3)
#define    WFS_DEP_ENVMISSING           (4)
#define    WFS_DEP_ENVUNKNOWN           (5)
#define    WFS_DEP_ENVNOTSUPP           (6)
#define    WFS_DEP_ENVUNLOCKED          (7)

/* values of WFSDEPSTATUS.fwPrinter */

#define    WFS_DEP_PTROK                (0)
#define    WFS_DEP_PTRINOP              (1)
#define    WFS_DEP_PTRUNKNOWN           (2)
#define    WFS_DEP_PTRNOTSUPP           (3)

/* values of WFSDEPSTATUS.fwToner */

#define    WFS_DEP_TONERFULL            (0)
#define    WFS_DEP_TONERLOW             (1)
#define    WFS_DEP_TONEROUT             (2)
#define    WFS_DEP_TONERUNKNOWN         (3)
#define    WFS_DEP_TONERNOTSUPP         (4)

/* values of WFSDEPSTATUS.fwShutter */

#define    WFS_DEP_SHTCLOSED            (0)
#define    WFS_DEP_SHTOPEN              (1)
#define    WFS_DEP_SHTJAMMED            (2)
#define    WFS_DEP_SHTUNKNOWN           (3)
#define    WFS_DEP_SHTNOTSUPP           (4)

/* values of WFSDEPCAPS.fwType */

#define    WFS_DEP_TYPEENVELOPE         (0x0001)
#define    WFS_DEP_TYPEBAGDROP          (0x0002)

/* values of WFSDEPCAPS.fwEnvSupply */

#define    WFS_DEP_ENVMOTORIZED         (1)
#define    WFS_DEP_ENVMANUAL            (2)
#define    WFS_DEP_ENVNONE              (3)

/* values of WFSDEPCAPS.fwRetractEnvelope */

#define    WFS_DEP_NORETRACT	        (1)
#define    WFS_DEP_RETRACTDEP           (2)
#define    WFS_DEP_RETRACTDISP          (3)

/* values of WFSDEPCAPS.fwCharSupport, WFSDEPENVELOPE.fwCharSupport */

#define    WFS_DEP_ASCII                (0x0001)
#define    WFS_DEP_UNICODE              (0x0002)

/* values of dwDepMediaControl    */

#define    WFS_DEP_CTRLEJECT                (0x0001)
#define    WFS_DEP_CTRLRETRACT              (0x0002)

/* values of WFSDEPMEDIADETECTED.fwCharSupport, WFSDEPENVELOPE.fwCharSupport  */

#define    WFS_DEP_NOMEDIA            (1)
#define    WFS_DEP_MEDIARETRACTED     (2)
#define    WFS_DEP_MEDIADISPENSER     (3)
#define    WFS_DEP_MEDIAEJECTED       (4)
#define    WFS_DEP_MEDIAJAMMED        (5)
#define    WFS_DEP_MEDIAUNKNOWN       (6)

#define    WFS_ERR_DEP_DEPFULL          (-(DEP_SERVICE_OFFSET + 0))
#define    WFS_ERR_DEP_DEPJAMMED        (-(DEP_SERVICE_OFFSET + 1))
#define    WFS_ERR_DEP_ENVEMPTY         (-(DEP_SERVICE_OFFSET + 2))
#define    WFS_ERR_DEP_ENVJAMMED        (-(DEP_SERVICE_OFFSET + 3))
#define    WFS_ERR_DEP_ENVSIZE          (-(DEP_SERVICE_OFFSET + 4))
#define    WFS_ERR_DEP_NOENV            (-(DEP_SERVICE_OFFSET + 5))
#define    WFS_ERR_DEP_PTRFAIL          (-(DEP_SERVICE_OFFSET + 6))
#define    WFS_ERR_DEP_SHTNOTCLOSED     (-(DEP_SERVICE_OFFSET + 7))
#define    WFS_ERR_DEP_SHTNOTOPENED     (-(DEP_SERVICE_OFFSET + 8))
#define    WFS_ERR_DEP_CONTMISSING      (-(DEP_SERVICE_OFFSET + 9))
#define    WFS_ERR_DEP_DEPUNKNOWN       (-(DEP_SERVICE_OFFSET + 10))
#define    WFS_ERR_DEP_CHARSETNOTSUPP   (-(DEP_SERVICE_OFFSET + 11))
#define    WFS_ERR_DEP_TONEROUT         (-(DEP_SERVICE_OFFSET + 12))

/*====================================================================*/
/*    DEP Info Command Structures and variables                       */
/*====================================================================*/

typedef struct _wfs_dep_status
{
    WORD        fwDevice;
    WORD        fwDepContainer;
    WORD        fwDepTransport;
    WORD        fwEnvSupply;
    WORD        fwEnvDispenser;
    WORD        fwPrinter;
    WORD        fwToner;
    WORD        fwShutter;
    WORD        wNumOfDeposits;
    LPSTR       lpszExtra;
} WFSDEPSTATUS, * LPWFSDEPSTATUS;


typedef struct _wfs_dep_caps
{
    WORD        wClass;
    WORD        fwType;
    WORD        fwEnvSupply;
    BOOL        bDepTransport;
    BOOL        bPrinter;
    BOOL        bToner;
    BOOL        bShutter;
    BOOL        bPrintOnRetracts;
    WORD        fwRetractEnvelope;
    WORD        wMaxNumChars;
    WORD        fwCharSupport;
    LPSTR       lpszExtra;
} WFSDEPCAPS, * LPWFSDEPCAPS;

/*====================================================================*/
/*    DEP Execute Command Structures                   */
/*====================================================================*/

typedef struct _wfs_dep_envelope
{
    LPSTR       lpszPrintData;
    LPWSTR      lpszUNICODEPrintData;
} WFSDEPENVELOPE, * LPWFSDEPENVELOPE;

/*====================================================================*/
/*    DEP Message Structures                       */
/*====================================================================*/

typedef struct _wfs_dep_media_detected
{
    WORD      wDispenseMedia;
    WORD      wDepositMedia;
} WFSDEPMEDIADETECTED, * LPWFSDEPMEDIADETECTED;


/*    restore alignment        */
#pragma pack(pop)

#ifdef __cplusplus
}    /*extern "C"*/
#endif

#endif  /* __INC_XFSDEP__H */

