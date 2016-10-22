/******************************************************************************
*                                                                             *
* xfsceu.h    XFS - Card Embossing Unit (CEU) definitions                     *
*                                                                             *
*             Version 3.00  (10/18/00)                                        *
*                                                                             *
******************************************************************************/
 
#ifndef __INC_XFSCEU__H
#define __INC_XFSCEU__H

#ifdef __cplusplus
extern "C" {
#endif

#include <xfsapi.h>

/*   be aware of alignment   */
#pragma pack(push,1)


/* values of WFSCEUCAPS.wClass */

#define     WFS_SERVICE_CLASS_CEU               (12)
#define     WFS_SERVICE_CLASS_NAME_CEU          "CEU"
#define     WFS_SERVICE_CLASS_VERSION_CEU       0x0003

#define     CEU_SERVICE_OFFSET                  (WFS_SERVICE_CLASS_CEU * 100)

/* CEU Info Commands */

#define     WFS_INF_CEU_STATUS                  (CEU_SERVICE_OFFSET + 1)
#define     WFS_INF_CEU_CAPABILITIES            (CEU_SERVICE_OFFSET + 2)
#define     WFS_INF_CEU_FORM_LIST               (CEU_SERVICE_OFFSET + 3)
#define     WFS_INF_CEU_QUERY_FORM              (CEU_SERVICE_OFFSET + 4)
#define     WFS_INF_CEU_MEDIA_LIST              (CEU_SERVICE_OFFSET + 5)
#define     WFS_INF_CEU_QUERY_MEDIA             (CEU_SERVICE_OFFSET + 6)
#define     WFS_INF_CEU_QUERY_FIELD             (CEU_SERVICE_OFFSET + 7)

/* CEU Execute Commands */

#define     WFS_CMD_CEU_EMBOSS_CARD             (CEU_SERVICE_OFFSET + 1)
#define     WFS_CMD_CEU_RESET                   (CEU_SERVICE_OFFSET + 2)


/* CEU Messages */

#define     WFS_SRVE_CEU_INPUTBINTHRESHOLD      (CEU_SERVICE_OFFSET + 1)
#define     WFS_SRVE_CEU_OUTPUTBINTHRESHOLD     (CEU_SERVICE_OFFSET + 2)
#define     WFS_SRVE_CEU_RETAINBINTHRESHOLD     (CEU_SERVICE_OFFSET + 3)
#define     WFS_EXEE_CEU_FIELDERROR             (CEU_SERVICE_OFFSET + 4)
#define     WFS_EXEE_CEU_FIELDWARNING           (CEU_SERVICE_OFFSET + 5)
#define     WFS_EXEE_CEU_EMBOSS_FAILURE         (CEU_SERVICE_OFFSET + 6)
#define     WFS_EXEE_CEU_MEDIAREMOVED           (CEU_SERVICE_OFFSET + 7)

#define     WFS_SRVE_CEU_MEDIADETECTED          (CEU_SERVICE_OFFSET + 8)

/* values of WFSCEUSTATUS.fwDevice */
#define     WFS_CEU_DEVONLINE                   WFS_STAT_DEVONLINE
#define     WFS_CEU_DEVOFFLINE                  WFS_STAT_DEVOFFLINE
#define     WFS_CEU_DEVPOWEROFF                 WFS_STAT_DEVPOWEROFF
#define     WFS_CEU_DEVNODEVICE                 WFS_STAT_DEVNODEVICE
#define     WFS_CEU_DEVHWERROR                  WFS_STAT_DEVHWERROR
#define     WFS_CEU_DEVUSERERROR                WFS_STAT_DEVUSERERROR
#define     WFS_CEU_DEVBUSY                     WFS_STAT_DEVBUSY

/* values of WFSCEUSTATUS.fwMedia  */

#define     WFS_CEU_MEDIAPRESENT                (1)
#define     WFS_CEU_MEDIANOTPRESENT             (2)
#define     WFS_CEU_MEDIAJAMMED                 (3)
#define     WFS_CEU_MEDIANOTSUPP                (4)
#define     WFS_CEU_MEDIAUNKNOWN                (5)
#define     WFS_CEU_MEDIAENTERING               (6)
#define     WFS_CEU_MEDIATOPPER                 (7)
#define     WFS_CEU_MEDIAINHOPPER               (8)
#define     WFS_CEU_MEDIAOUTHOPPER              (9)
#define     WFS_CEU_MEDIAMSRE                   (10)
#define     WFS_CEU_MEDIARETAINED               (11)
#define     WFS_CEU_MEDIAREMOVED                (12)

/* values of WFSCEUSTATUS.fwRetainBin  */

#define     WFS_CEU_RETAINBINOK                 (1)
#define     WFS_CEU_RETAINBINFULL               (2)
#define     WFS_CEU_RETAINBINHIGH               (3)
#define     WFS_CEU_RETAINBINNOTSUPP            (4)

/* values of WFSCEUSTATUS.fwOutputBin  */

#define     WFS_CEU_OUTPUTBINOK                 (1)
#define     WFS_CEU_OUTPUTBINFULL               (2)
#define     WFS_CEU_OUTPUTBINHIGH               (3)
#define     WFS_CEU_OUTPUTNOTSUPP               (4)

/* values of WFSCEUSTATUS.fwInputBin  */

#define     WFS_CEU_INPUTBINOK                  (1)
#define     WFS_CEU_INPUTBINEMPTY               (2)
#define     WFS_CEU_INPUTBINLOW                 (3)
#define     WFS_CEU_INPUTNOTSUPP                (4)

/* values of _wfs_ceu_frm_header.wBase , wfs_ceu_frm_media.wBase  */

#define     WFS_CEU_INCH                        (1)
#define     WFS_CEU_MM                          (2)
#define     WFS_CEU_ROWCOLUMN                   (3)

/* values of _wfs_ceu_frm_header.wAlignment */

#define     WFS_CEU_TOPLEFT                     (1)
#define     WFS_CEU_TOPRIGHT                    (2)
#define     WFS_CEU_BOTTOMLEFT                  (3)
#define     WFS_CEU_BOTTOMRIGHT                 (4)

/* values of _wfs_ceu_frm_media.fwMediaType  */

#define     WFS_CEU_MEDIAECARD                  (1)

/* values of _wfs_ceu_frm_field.fwType  */

#define     WFS_CEU_FIELDTEXT                   (1)
#define     WFS_CEU_FIELDOCR                    (2)

/* values of _wfs_ceu_frm_field.fwClass  */

#define     WFS_CEU_CLASSSTATIC                 (1)
#define     WFS_CEU_CLASSOPTIONAL               (2)
#define     WFS_CEU_CLASSREQUIRED               (3)

/* values WFSCEUFIELDFAIL.wFailure */

#define     WFS_CEU_FIELDREQUIRED               (1)
#define     WFS_CEU_FIELDSTATICOVWR             (2)
#define     WFS_CEU_FIELDOVERFLOW               (3)
#define     WFS_CEU_FIELDNOTFOUND               (4)
#define     WFS_CEU_FIELDNOTREAD                (5)
#define     WFS_CEU_FIELDNOTWRITE               (6)
#define     WFS_CEU_FIELDHWERROR                (7)
#define     WFS_CEU_FIELDTYPENOTSUPPORTED       (8)

/* values of WFSCEUEMBOSSCARD.fwChipProtocols */

#define     WFS_CEU_NOTSUPP                     0x0000
#define     WFS_CEU_CHIPT0                      0x0001
#define     WFS_CEU_CHIPT1                      0x0002
#define     WFS_CEU_CHIPT2                      0x0004
#define     WFS_CEU_CHIPT3                      0x0008
#define     WFS_CEU_CHIPT4                      0x0010
#define     WFS_CEU_CHIPT5                      0x0020
#define     WFS_CEU_CHIPT6                      0x0040
#define     WFS_CEU_CHIPT7                      0x0080
#define     WFS_CEU_CHIPT8                      0x0100
#define     WFS_CEU_CHIPT9                      0x0200
#define     WFS_CEU_CHIPT10                     0x0400
#define     WFS_CEU_CHIPT11                     0x0800
#define     WFS_CEU_CHIPT12                     0x1000
#define     WFS_CEU_CHIPT13                     0x2000
#define     WFS_CEU_CHIPT14                     0x4000
#define     WFS_CEU_CHIPT15                     0x8000

/* WFS_EXEE_CEU_EMBOSS_FAILURE  Flags  */

#define     WFS_CEU_STEPPER_ERROR               (1)
#define     WFS_CEU_TOPPER_FOIL_BREAK           (2)
#define     WFS_CEU_CARD_FEED_ERROR             (3)
#define     WFS_CEU_MAGNETIC_STRIPE_ERROR       (4)
#define     WFS_CEU_RETAIN_BIN_FULL             (5)
#define     WFS_CEU_OUTPUT_BIN_FULL             (6)
#define     WFS_CEU_COVER_OPEN                  (7)
#define     WFS_CEU_TOPPER_JAM                  (8)
#define     WFS_CEU_STACKER_ERROR               (9)
#define     WFS_CEU_SYSTEM_ERROR                (10)
#define     WFS_CEU_OCR_ERROR                   (11)
#define     WFS_CEU_EMBOSS_LIMITS_EXCEEDED      (12)
#define     WFS_CEU_COMMUNICATIONS_FAILURE      (13)
#define     WFS_CEU_DATA_FORMAT_ERROR           (14)
#define     WFS_CEU_BUFFER_OVERRUN              (15)
#define     WFS_CEU_PRE_ENCODE_READ_ERROR       (16)
#define     WFS_CEU_PRE_ENCODE_DATA_MATCH_ERROR (17)
#define     WFS_CEU_INPUT_BIN_EMPTY             (18)
#define     WFS_CEU_DEVICE_BUSY                 (19)

/* values of lpwCeuMediacontrol paramater of WFS_CMD_CEU_RESET command */
#define     WFS_CEU_CTRLTOINPUTBIN              (1)
#define     WFS_CEU_CTRLTOOUTPUTBIN             (2)
#define     WFS_CEU_CTRLTORETAINBIN             (3)

/* WOSA/XFS CEU Errors */ 

#define WFS_ERR_CEU_FORMNOTFOUND                (-(CEU_SERVICE_OFFSET + 1))
#define WFS_ERR_CEU_FORMINVALID                 (-(CEU_SERVICE_OFFSET + 2))
#define WFS_ERR_CEU_MEDIANOTFOUND               (-(CEU_SERVICE_OFFSET + 3))
#define WFS_ERR_CEU_MEDIAINVALID                (-(CEU_SERVICE_OFFSET + 4))
#define WFS_ERR_CEU_NOMEDIA                     (-(CEU_SERVICE_OFFSET + 5))
#define WFS_ERR_CEU_MEDIAOVERFLOW               (-(CEU_SERVICE_OFFSET + 6))
#define WFS_ERR_CEU_IDC_FORMNOTFOUND            (-(CEU_SERVICE_OFFSET + 7))
#define WFS_ERR_CEU_IDC_FORMINVALID             (-(CEU_SERVICE_OFFSET + 8))
#define WFS_ERR_CEU_INVALIDDATA                 (-(CEU_SERVICE_OFFSET + 9))
#define WFS_ERR_CEU_PROTOCOLNOTSUPP             (-(CEU_SERVICE_OFFSET + 10))
#define WFS_ERR_CEU_ATRNOTOBTAINED              (-(CEU_SERVICE_OFFSET + 11))
#define WFS_ERR_CEU_FIELDSPECFAILURE            (-(CEU_SERVICE_OFFSET + 12))
#define WFS_ERR_CEU_FIELDERROR                  (-(CEU_SERVICE_OFFSET + 13))
#define WFS_ERR_CEU_EMBOSSFAILURE               (-(CEU_SERVICE_OFFSET + 14))
#define WFS_ERR_CEU_FIELDNOTFOUND               (-(CEU_SERVICE_OFFSET + 15))


/*=================================================================*/
/* CEU Info Command Structures and variables */
/*=================================================================*/

typedef struct _wfs_ceu_status
{
    WORD      fwDevice;
    WORD      fwMedia;
    WORD      fwRetainBin;
    WORD      fwOutputBin;
    WORD      fwInputBin;
    USHORT    usTotalCards;
    USHORT    usOutputCards;
    USHORT    usRetainCards;
    LPSTR     lpszExtra;
} WFSCEUSTATUS, * LPWFSCEUSTATUS;

typedef struct _wfs_ceu_caps
{
    WORD      wClass;
    BOOL      bCompound;
    BOOL      bCompareMagneticStripe;
    BOOL      bMagneticStripeRead;
    BOOL      bMagneticStripeWrite;
    BOOL      bChipIO;
    WORD      wChipProtocol;
    LPSTR     lpszExtra;
} WFSCEUCAPS, * LPWFSCEUCAPS;


typedef struct _wfs_ceu_form
{
    LPSTR     lpszFormName;
    LPSTR     lpszFields;
} WFSCEUFORM, * LPWFSCEUFORM;

typedef struct _wfs_ceu_frm_media
{
    WORD      fwMediaType;
    WORD      wBase;
    WORD      wUnitX;
    WORD      wUnitY;
    WORD      wSizeWidth;
    WORD      wSizeHeight;
    WORD      wEmbossAreaX;
    WORD      wEmbossAreaY;
    WORD      wEmbossAreaWidth;
    WORD      wEmbossAreaHeight;
    WORD      wRestrictedAreaX;
    WORD      wRestrictedAreaY;
    WORD      wRestrictedAreaWidth;
    WORD      wRestrictedAreaHeight;
} WFSCEUFRMMEDIA, * LPWFSCEUFRMMEDIA;

typedef struct _wfs_ceu_query_field
{
    LPSTR     lpszFormName;
    LPSTR     lpszFieldName;
} WFSCEUQUERYFIELD, * LPWFSCEUQUERYFIELD;

typedef struct _wfs_ceu_frm_field
{
    LPSTR     lpszFieldName;
    WORD      fwType;
    WORD      fwClass;
    LPSTR     lpszInitialValue;
    LPSTR     lpszFormat;
} WFSCEUFRMFIELD, * LPWFSCEUFRMFIELD;

/*=================================================================*/
/* CEU Execute Command Structures */
/*=================================================================*/

typedef struct _wfs_ceu_emboss_card
{
    LPSTR     lpszFormName;
    LPSTR     lpszMediaName;
    LPSTR     lpszFields;
    LPSTR     lpszCompareFormIOFormName;
    LPSTR     lpszCompareFormIOTrackData;
    LPSTR     lpszFormIOFormName;
    LPSTR     lpszFormIOTrackData;
    WORD      wChipProtocol;
    ULONG     ulChipDataLength;
    LPBYTE    lpbChipData;
} WFSCEUEMBOSSCARD, * LPWFSCEUEMBOSSCARD;


/*=================================================================*/
/* CEU Message Structures */
/*=================================================================*/

typedef struct _wfs_ceu_field_failure
{
    LPSTR     lpszFormName;
    LPSTR     lpszFieldName;
    WORD      wFailure;
} WFSCEUFIELDFAIL, * LPWFSCEUFIELDFAIL;

#ifdef __cplusplus 
}
#endif 

//restore alignment
#pragma pack (pop)

#endif  /* __INC_XFSCEU__H */

