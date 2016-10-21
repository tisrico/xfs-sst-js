/******************************************************************************
*                                                                             *
* xfsptr.h    XFS - Banking Printer (PTR) definitions                         *
*              (receipt, journal, passbook and document printer)             *
*                                                                             *
*             Version 3.00  (10/18/2000)                                      *
*                                                                             *
******************************************************************************/

#ifndef __INC_XFSPTR__H
#define __INC_XFSPTR__H

#ifdef __cplusplus
extern "C" {
#endif

#include <xfsapi.h>

/*   be aware of alignment   */
#pragma pack(push,1)


/* value of WFSPTRCAPS.wClass */

#define    WFS_SERVICE_CLASS_PTR            (1)
#define    WFS_SERVICE_CLASS_VERSION_PTR    (0x0003) /* Version 3.00 */
#define    WFS_SERVICE_CLASS_NAME_PTR       "PTR"

#define    PTR_SERVICE_OFFSET               (WFS_SERVICE_CLASS_PTR * 100)


/* PTR Info Commands */

#define    WFS_INF_PTR_STATUS               (PTR_SERVICE_OFFSET + 1)
#define    WFS_INF_PTR_CAPABILITIES         (PTR_SERVICE_OFFSET + 2)
#define    WFS_INF_PTR_FORM_LIST            (PTR_SERVICE_OFFSET + 3)
#define    WFS_INF_PTR_MEDIA_LIST           (PTR_SERVICE_OFFSET + 4)
#define    WFS_INF_PTR_QUERY_FORM           (PTR_SERVICE_OFFSET + 5)
#define    WFS_INF_PTR_QUERY_MEDIA          (PTR_SERVICE_OFFSET + 6)
#define    WFS_INF_PTR_QUERY_FIELD          (PTR_SERVICE_OFFSET + 7)


/* PTR Execute Commands */

#define    WFS_CMD_PTR_CONTROL_MEDIA        (PTR_SERVICE_OFFSET + 1)
#define    WFS_CMD_PTR_PRINT_FORM           (PTR_SERVICE_OFFSET + 2)
#define    WFS_CMD_PTR_READ_FORM            (PTR_SERVICE_OFFSET + 3)
#define    WFS_CMD_PTR_RAW_DATA             (PTR_SERVICE_OFFSET + 4)
#define    WFS_CMD_PTR_MEDIA_EXTENTS        (PTR_SERVICE_OFFSET + 5)
#define    WFS_CMD_PTR_RESET_COUNT          (PTR_SERVICE_OFFSET + 6)
#define    WFS_CMD_PTR_READ_IMAGE           (PTR_SERVICE_OFFSET + 7)
#define    WFS_CMD_PTR_RESET                (PTR_SERVICE_OFFSET + 8)
#define    WFS_CMD_PTR_RETRACT_MEDIA        (PTR_SERVICE_OFFSET + 9)
#define    WFS_CMD_PTR_DISPENSE_PAPER       (PTR_SERVICE_OFFSET + 10)


/* PTR Messages */

#define    WFS_EXEE_PTR_NOMEDIA             (PTR_SERVICE_OFFSET + 1)
#define    WFS_EXEE_PTR_MEDIAINSERTED       (PTR_SERVICE_OFFSET + 2)
#define    WFS_EXEE_PTR_FIELDERROR          (PTR_SERVICE_OFFSET + 3)
#define    WFS_EXEE_PTR_FIELDWARNING        (PTR_SERVICE_OFFSET + 4)
#define    WFS_USRE_PTR_RETRACTBINTHRESHOLD (PTR_SERVICE_OFFSET + 5)
#define    WFS_SRVE_PTR_MEDIATAKEN          (PTR_SERVICE_OFFSET + 6)
#define    WFS_USRE_PTR_PAPERTHRESHOLD      (PTR_SERVICE_OFFSET + 7)
#define    WFS_USRE_PTR_TONERTHRESHOLD      (PTR_SERVICE_OFFSET + 8)
#define    WFS_SRVE_PTR_MEDIAINSERTED       (PTR_SERVICE_OFFSET + 9)
#define    WFS_USRE_PTR_LAMPTHRESHOLD       (PTR_SERVICE_OFFSET + 10)
#define    WFS_USRE_PTR_INKTHRESHOLD        (PTR_SERVICE_OFFSET + 11)
#define    WFS_SRVE_PTR_MEDIADETECTED       (PTR_SERVICE_OFFSET + 12)


/* values of WFSPTRSTATUS.fwDevice */

#define    WFS_PTR_DEVONLINE                WFS_STAT_DEVONLINE
#define    WFS_PTR_DEVOFFLINE               WFS_STAT_DEVOFFLINE
#define    WFS_PTR_DEVPOWEROFF              WFS_STAT_DEVPOWEROFF
#define    WFS_PTR_DEVNODEVICE              WFS_STAT_DEVNODEVICE
#define    WFS_PTR_DEVHWERROR               WFS_STAT_DEVHWERROR
#define    WFS_PTR_DEVUSERERROR             WFS_STAT_DEVUSERERROR
#define    WFS_PTR_DEVBUSY                  WFS_STAT_DEVBUSY


/* values of WFSPTRSTATUS.fwMedia and
             WFSPTRMEDIADETECTED.wPosition */

#define    WFS_PTR_MEDIAPRESENT             (0)
#define    WFS_PTR_MEDIANOTPRESENT          (1)
#define    WFS_PTR_MEDIAJAMMED              (2)
#define    WFS_PTR_MEDIANOTSUPP             (3)
#define    WFS_PTR_MEDIAUNKNOWN             (4)
#define    WFS_PTR_MEDIAENTERING            (5)
#define    WFS_PTR_MEDIARETRACTED           (6)


/* Size and max index of fwPaper array */

#define    WFS_PTR_SUPPLYSIZE    (16)
#define    WFS_PTR_SUPPLYMAX     (WFS_PTR_SUPPLYSIZE - 1)


/* Indices of WFSPTRSTATUS.fwPaper [...] */

#define    WFS_PTR_SUPPLYUPPER              (0)
#define    WFS_PTR_SUPPLYLOWER              (1)
#define    WFS_PTR_SUPPLYEXTERNAL           (2)
#define    WFS_PTR_SUPPLYAUX                (3)
#define    WFS_PTR_SUPPLYAUX2               (4)
#define    WFS_PTR_SUPPLYPARK               (5)


/* values of WFSPTRSTATUS.fwPaper and
             WFSPTRPAPERTHRESHOLD.wPaperThreshold */

#define    WFS_PTR_PAPERFULL                (0)
#define    WFS_PTR_PAPERLOW                 (1)
#define    WFS_PTR_PAPEROUT                 (2)
#define    WFS_PTR_PAPERNOTSUPP             (3)
#define    WFS_PTR_PAPERUNKNOWN             (4)
#define    WFS_PTR_PAPERJAMMED              (5)


/* values of WFSPTRSTATUS.fwToner */

#define    WFS_PTR_TONERFULL                (0)
#define    WFS_PTR_TONERLOW                 (1)
#define    WFS_PTR_TONEROUT                 (2)
#define    WFS_PTR_TONERNOTSUPP             (3)
#define    WFS_PTR_TONERUNKNOWN             (4)


/* values of WFSPTRSTATUS.fwInk */

#define    WFS_PTR_INKFULL                  (0)
#define    WFS_PTR_INKLOW                   (1)
#define    WFS_PTR_INKOUT                   (2)
#define    WFS_PTR_INKNOTSUPP               (3)
#define    WFS_PTR_INKUNKNOWN               (4)


/* values of WFSPTRSTATUS.fwLamp */

#define    WFS_PTR_LAMPOK                   (0)
#define    WFS_PTR_LAMPFADING               (1)
#define    WFS_PTR_LAMPINOP                 (2)
#define    WFS_PTR_LAMPNOTSUPP              (3)
#define    WFS_PTR_LAMPUNKNOWN              (4)


/* values of WFSPTRSTATUS.fwRetractBin and
             WFSPTRBINTHRESHOLD.wRetractBin */

#define    WFS_PTR_RETRACTBINOK             (0)
#define    WFS_PTR_RETRACTBINFULL           (1)
#define    WFS_PTR_RETRACTNOTSUPP           (2)
#define    WFS_PTR_RETRACTUNKNOWN           (3)
#define    WFS_PTR_RETRACTBINHIGH           (4)


/* values of WFSPTRCAPS.fwType */

#define    WFS_PTR_TYPERECEIPT              0x0001
#define    WFS_PTR_TYPEPASSBOOK             0x0002
#define    WFS_PTR_TYPEJOURNAL              0x0004
#define    WFS_PTR_TYPEDOCUMENT             0x0008
#define    WFS_PTR_TYPESCANNER              0x0010


/* values of WFSPTRCAPS.wResolution, WFSPTRPRINTFORM.wResolution */

#define    WFS_PTR_RESLOW                   0x0001
#define    WFS_PTR_RESMED                   0x0002
#define    WFS_PTR_RESHIGH                  0x0004
#define    WFS_PTR_RESVERYHIGH              0x0008


/* values of WFSPTRCAPS.fwReadForm */

#define    WFS_PTR_READOCR                  0x0001
#define    WFS_PTR_READMICR                 0x0002
#define    WFS_PTR_READMSF                  0x0004
#define    WFS_PTR_READBARCODE              0x0008
#define    WFS_PTR_READPAGEMARK             0x0010
#define    WFS_PTR_READIMAGE                0x0020
#define    WFS_PTR_READEMPTYLINE            0x0040


/* values of WFSPTRCAPS.fwWriteForm */

#define    WFS_PTR_WRITETEXT                0x0001
#define    WFS_PTR_WRITEGRAPHICS            0x0002
#define    WFS_PTR_WRITEOCR                 0x0004
#define    WFS_PTR_WRITEMICR                0x0008
#define    WFS_PTR_WRITEMSF                 0x0010
#define    WFS_PTR_WRITEBARCODE             0x0020
#define    WFS_PTR_WRITESTAMP               0x0040


/* values of WFSPTRCAPS.fwExtents */

#define    WFS_PTR_EXTHORIZONTAL            0x0001
#define    WFS_PTR_EXTVERTICAL              0x0002


/* values of WFSPTRCAPS.fwControl, dwMediaControl */

#define    WFS_PTR_CTRLEJECT                0x0001
#define    WFS_PTR_CTRLPERFORATE            0x0002
#define    WFS_PTR_CTRLCUT                  0x0004
#define    WFS_PTR_CTRLSKIP                 0x0008
#define    WFS_PTR_CTRLFLUSH                0x0010
#define    WFS_PTR_CTRLRETRACT              0x0020
#define    WFS_PTR_CTRLSTACK                0x0040
#define    WFS_PTR_CTRLPARTIALCUT           0x0080
#define    WFS_PTR_CTRLALARM                0x0100
#define    WFS_PTR_CTRLATPFORWARD           0x0200
#define    WFS_PTR_CTRLATPBACKWARD          0x0400
#define    WFS_PTR_CTRLTURNMEDIA            0x0800
#define    WFS_PTR_CTRLSTAMP                0x1000
#define    WFS_PTR_CTRLPARK                 0x2000


/* values of WFSPTRCAPS.fwPaperSources,
             WFSFRMMEDIA.wPaperSources,
             WFSPTRPRINTFORM.wPaperSource and
             WFSPTRPAPERTHRESHOLD.wPaperSource   */

#define    WFS_PTR_PAPERANY                 0x0001
#define    WFS_PTR_PAPERUPPER               0x0002
#define    WFS_PTR_PAPERLOWER               0x0004
#define    WFS_PTR_PAPEREXTERNAL            0x0008
#define    WFS_PTR_PAPERAUX                 0x0010
#define    WFS_PTR_PAPERAUX2                0x0020
#define    WFS_PTR_PAPERPARK                0x0040


/* values of WFSPTRCAPS.fwImageType,
             WFSPTRIMAGEREQUEST.wFrontImageFormat and
             WFSPTRIMAGEREQUEST.wBackImageFormat */

#define    WFS_PTR_IMAGETIF                 0x0001
#define    WFS_PTR_IMAGEWMF                 0x0002
#define    WFS_PTR_IMAGEBMP                 0x0004


/* values of WFSPTRCAPS.fwFrontImageColorFormat,
             WFSPTRCAPS.fwBackImageColorFormat,
             WFSPTRIMAGEREQUEST.wFrontImageColorFormat and
             WFSPTRIMAGEREQUEST.wBackImageColorFormat */

#define    WFS_PTR_IMAGECOLORBINARY         0x0001
#define    WFS_PTR_IMAGECOLORGRAYSCALE      0x0002
#define    WFS_PTR_IMAGECOLORFULL           0x0004


/* values of WFSPTRCAPS.fwCodelineFormat and
             WFSPTRIMAGEREQUEST.wCodelineFormat */

#define    WFS_PTR_CODELINECMC7             0x0001
#define    WFS_PTR_CODELINEE13B             0x0002
#define    WFS_PTR_CODELINEOCR              0x0004


/* values of WFSPTRCAPS.fwImageSource,
             WFSPTRIMAGEREQUEST.fwImageSource and
             WFSPTRIMAGE.wImageSource */

#define    WFS_PTR_IMAGEFRONT               0x0001
#define    WFS_PTR_IMAGEBACK                0x0002
#define    WFS_PTR_CODELINE                 0x0004


/* values of WFSPTRCAPS.fwCharSupport, WFSFRMHEADER.fwCharSupport  */

#define    WFS_PTR_ASCII                    0x0001
#define    WFS_PTR_UNICODE                  0x0002


/* values of WFSFRMHEADER.wBase, WFSFRMMEDIA.wBase, WFSPTRMEDIAUNIT.wBase */

#define    WFS_FRM_INCH                     (0)
#define    WFS_FRM_MM                       (1)
#define    WFS_FRM_ROWCOLUMN                (2)


/* values of WFSFRMHEADER.wAlignment */

#define    WFS_FRM_TOPLEFT                  (0)
#define    WFS_FRM_TOPRIGHT                 (1)
#define    WFS_FRM_BOTTOMLEFT               (2)
#define    WFS_FRM_BOTTOMRIGHT              (3)


/* values of WFSFRMHEADER.wOrientation */

#define    WFS_FRM_PORTRAIT                 (0)
#define    WFS_FRM_LANDSCAPE                (1)


/* values of WFSFRMMEDIA.fwMediaType */

#define    WFS_FRM_MEDIAGENERIC             (0)
#define    WFS_FRM_MEDIAPASSBOOK            (1)
#define    WFS_FRM_MEDIAMULTIPART           (2)


/* values of WFSFRMMEDIA.fwFoldType */

#define    WFS_FRM_FOLDNONE                 (0)
#define    WFS_FRM_FOLDHORIZONTAL           (1)
#define    WFS_FRM_FOLDVERTICAL             (2)


/* values of WFSFRMFIELD.fwType */

#define    WFS_FRM_FIELDTEXT                (0)
#define    WFS_FRM_FIELDMICR                (1)
#define    WFS_FRM_FIELDOCR                 (2)
#define    WFS_FRM_FIELDMSF                 (3)
#define    WFS_FRM_FIELDBARCODE             (4)
#define    WFS_FRM_FIELDGRAPHIC             (5)
#define    WFS_FRM_FIELDPAGEMARK            (6)


/* values of WFSFRMFIELD.fwClass */

#define    WFS_FRM_CLASSSTATIC              (0)
#define    WFS_FRM_CLASSOPTIONAL            (1)
#define    WFS_FRM_CLASSREQUIRED            (2)


/* values of WFSFRMFIELD.fwAccess */

#define    WFS_FRM_ACCESSREAD               0x0001
#define    WFS_FRM_ACCESSWRITE              0x0002


/* values of WFSFRMFIELD.fwOverflow */

#define    WFS_FRM_OVFTERMINATE             (0)
#define    WFS_FRM_OVFTRUNCATE              (1)
#define    WFS_FRM_OVFBESTFIT               (2)
#define    WFS_FRM_OVFOVERWRITE             (3)
#define    WFS_FRM_OVFWORDWRAP              (4)


/* values of WFSPTRFIELDFAIL.wFailure */

#define    WFS_PTR_FIELDREQUIRED            (0)
#define    WFS_PTR_FIELDSTATICOVWR          (1)
#define    WFS_PTR_FIELDOVERFLOW            (2)
#define    WFS_PTR_FIELDNOTFOUND            (3)
#define    WFS_PTR_FIELDNOTREAD             (4)
#define    WFS_PTR_FIELDNOTWRITE            (5)
#define    WFS_PTR_FIELDHWERROR             (6)
#define    WFS_PTR_FIELDTYPENOTSUPPORTED    (7)
#define    WFS_PTR_FIELDGRAPHIC             (8)
#define    WFS_PTR_CHARSETFORM              (9)


/* values of WFSPTRPRINTFORM.wAlignment */

#define    WFS_PTR_ALNUSEFORMDEFN           (0)
#define    WFS_PTR_ALNTOPLEFT               (1)
#define    WFS_PTR_ALNTOPRIGHT              (2)
#define    WFS_PTR_ALNBOTTOMLEFT            (3)
#define    WFS_PTR_ALNBOTTOMRIGHT           (4)


/* values of WFSPTRPRINTFORM.wOffsetX and WFSPTRPRINTFORM.wOffsetY */

#define    WFS_PTR_OFFSETUSEFORMDEFN        0xffff


/* values of WFSPTRRAWDATA.wInputData */

#define    WFS_PTR_NOINPUTDATA              (0)
#define    WFS_PTR_INPUTDATA                (1)


/* values of WFSPTRIMAGE.wStatus */

#define     WFS_PTR_DATAOK                  (0)
#define     WFS_PTR_DATASRCNOTSUPP          (1)
#define     WFS_PTR_DATASRCMISSING          (2)


/* XFS PTR Errors */ 

#define    WFS_ERR_PTR_FORMNOTFOUND         (-(PTR_SERVICE_OFFSET + 0))
#define    WFS_ERR_PTR_FIELDNOTFOUND        (-(PTR_SERVICE_OFFSET + 1))
#define    WFS_ERR_PTR_NOMEDIAPRESENT       (-(PTR_SERVICE_OFFSET + 2))
#define    WFS_ERR_PTR_READNOTSUPPORTED     (-(PTR_SERVICE_OFFSET + 3))
#define    WFS_ERR_PTR_FLUSHFAIL            (-(PTR_SERVICE_OFFSET + 4))
#define    WFS_ERR_PTR_MEDIAOVERFLOW        (-(PTR_SERVICE_OFFSET + 5))
#define    WFS_ERR_PTR_FIELDSPECFAILURE     (-(PTR_SERVICE_OFFSET + 6))
#define    WFS_ERR_PTR_FIELDERROR           (-(PTR_SERVICE_OFFSET + 7))
#define    WFS_ERR_PTR_MEDIANOTFOUND        (-(PTR_SERVICE_OFFSET + 8))
#define    WFS_ERR_PTR_EXTENTNOTSUPPORTED   (-(PTR_SERVICE_OFFSET + 9))
#define    WFS_ERR_PTR_MEDIAINVALID         (-(PTR_SERVICE_OFFSET + 10))
#define    WFS_ERR_PTR_FORMINVALID          (-(PTR_SERVICE_OFFSET + 11))
#define    WFS_ERR_PTR_FIELDINVALID         (-(PTR_SERVICE_OFFSET + 12))
#define    WFS_ERR_PTR_MEDIASKEWED          (-(PTR_SERVICE_OFFSET + 13))
#define    WFS_ERR_PTR_RETRACTBINFULL       (-(PTR_SERVICE_OFFSET + 14))
#define    WFS_ERR_PTR_STACKERFULL          (-(PTR_SERVICE_OFFSET + 15))
#define    WFS_ERR_PTR_PAGETURNFAIL         (-(PTR_SERVICE_OFFSET + 16))
#define    WFS_ERR_PTR_MEDIATURNFAIL        (-(PTR_SERVICE_OFFSET + 17))
#define    WFS_ERR_PTR_SHUTTERFAIL          (-(PTR_SERVICE_OFFSET + 18))
#define    WFS_ERR_PTR_MEDIAJAMMED          (-(PTR_SERVICE_OFFSET + 19))
#define    WFS_ERR_PTR_FILE_IO_ERROR        (-(PTR_SERVICE_OFFSET + 20))
#define    WFS_ERR_PTR_CHARSETDATA          (-(PTR_SERVICE_OFFSET + 21))
#define    WFS_ERR_PTR_PAPERJAMMED          (-(PTR_SERVICE_OFFSET + 22))
#define    WFS_ERR_PTR_PAPEROUT             (-(PTR_SERVICE_OFFSET + 23))
#define    WFS_ERR_PTR_INKOUT               (-(PTR_SERVICE_OFFSET + 24))
#define    WFS_ERR_PTR_TONEROUT             (-(PTR_SERVICE_OFFSET + 25))
#define    WFS_ERR_PTR_LAMPINOP             (-(PTR_SERVICE_OFFSET + 26))
#define    WFS_ERR_PTR_SOURCEINVALID        (-(PTR_SERVICE_OFFSET + 27))
#define    WFS_ERR_PTR_SEQUENCEINVALID      (-(PTR_SERVICE_OFFSET + 28))
#define    WFS_ERR_PTR_MEDIASIZE            (-(PTR_SERVICE_OFFSET + 29))


/*=================================================================*/
/* PTR Info Command Structures */
/*=================================================================*/

typedef struct _wfs_ptr_retract_bins
{
   WORD      wRetractBin;
   USHORT    usRetractCount;
} WFSPTRRETRACTBINS, * LPWFSPTRRETRACTBINS;

typedef struct _wfs_ptr_status        
{
    WORD            fwDevice;
    WORD            fwMedia;
    WORD            fwPaper[WFS_PTR_SUPPLYSIZE];
    WORD            fwToner;
    WORD            fwInk;
    WORD            fwLamp;
    LPWFSPTRRETRACTBINS *lppRetractBins;
    USHORT          usMediaOnStacker;
    LPSTR           lpszExtra;
} WFSPTRSTATUS, * LPWFSPTRSTATUS;

typedef struct _wfs_ptr_caps
{
    WORD            wClass;
    WORD            fwType;
    BOOL            bCompound;
    WORD            wResolution;
    WORD            fwReadForm;
    WORD            fwWriteForm;
    WORD            fwExtents;
    WORD            fwControl;
    USHORT          usMaxMediaOnStacker;
    BOOL            bAcceptMedia;
    BOOL            bMultiPage;
    WORD            fwPaperSources;
    BOOL            bMediaTaken;
    USHORT          usRetractBins;
    LPUSHORT        lpusMaxRetract;
    WORD            fwImageType;
    WORD            fwFrontImageColorFormat;
    WORD            fwBackImageColorFormat;
    WORD            fwCodelineFormat;
    WORD            fwImageSource;
    WORD            fwCharSupport;
    BOOL            bDispensePaper;
    LPSTR           lpszExtra;
} WFSPTRCAPS, * LPWFSPTRCAPS;

typedef struct _wfs_frm_header
{
    LPSTR           lpszFormName;
    WORD            wBase;
    WORD            wUnitX;
    WORD            wUnitY;
    WORD            wWidth;
    WORD            wHeight;
    WORD            wAlignment;
    WORD            wOrientation;
    WORD            wOffsetX;
    WORD            wOffsetY;
    WORD            wVersionMajor;
    WORD            wVersionMinor;
    LPSTR           lpszUserPrompt;
    WORD            fwCharSupport;
    LPSTR           lpszFields;
} WFSFRMHEADER, * LPWFSFRMHEADER;

typedef struct _wfs_frm_media
{
    WORD            fwMediaType;
    WORD            wBase;
    WORD            wUnitX;
    WORD            wUnitY;
    WORD            wSizeWidth;
    WORD            wSizeHeight;
    WORD            wPageCount;
    WORD            wLineCount;
    WORD            wPrintAreaX;
    WORD            wPrintAreaY;
    WORD            wPrintAreaWidth;
    WORD            wPrintAreaHeight;
    WORD            wRestrictedAreaX;
    WORD            wRestrictedAreaY;
    WORD            wRestrictedAreaWidth;
    WORD            wRestrictedAreaHeight;
    WORD            wStagger;
    WORD            wFoldType;
    WORD            wPaperSources;
} WFSFRMMEDIA, * LPWFSFRMMEDIA;

typedef struct _wfs_ptr_query_field
{
    LPSTR           lpszFormName;
    LPSTR           lpszFieldName;
} WFSPTRQUERYFIELD, * LPWFSPTRQUERYFIELD;

typedef struct _wfs_frm_field
{
    LPSTR           lpszFieldName;
    WORD            wIndexCount;
    WORD            fwType;
    WORD            fwClass;
    WORD            fwAccess;
    WORD            fwOverflow;
    LPSTR           lpszInitialValue;
    LPWSTR          lpszUNICODEInitialValue;
    LPSTR           lpszFormat;
    LPWSTR          lpszUNICODEFormat;
} WFSFRMFIELD, * LPWFSFRMFIELD;


/*=================================================================*/
/* PTR Execute Command Structures */
/*=================================================================*/

typedef struct _wfs_ptr_print_form
{
    LPSTR           lpszFormName; 
    LPSTR           lpszMediaName;
    WORD            wAlignment;
    WORD            wOffsetX;
    WORD            wOffsetY;
    WORD            wResolution;
    DWORD           dwMediaControl;
    LPSTR           lpszFields;
    LPWSTR          lpszUNICODEFields;
    WORD            wPaperSource;
} WFSPTRPRINTFORM, * LPWFSPTRPRINTFORM;

typedef struct _wfs_ptr_read_form
{
    LPSTR           lpszFormName;
    LPSTR           lpszFieldNames;
    LPSTR           lpszMediaName;
    DWORD           dwMediaControl;
} WFSPTRREADFORM, * LPWFSPTRREADFORM;

typedef struct _wfs_ptr_read_form_out
{	
    LPSTR           lpszFields;
    LPWSTR          lpszUNICODEFields;
} WFSPTRREADFORMOUT, * LPWFSPTRREADFORMOUT;

typedef struct _wfs_ptr_raw_data
{
    WORD            wInputData;
    ULONG           ulSize;
    LPBYTE          lpbData;
} WFSPTRRAWDATA, * LPWFSPTRRAWDATA;

typedef struct _wfs_ptr_raw_data_in
{
    ULONG           ulSize;
    LPBYTE          lpbData;
} WFSPTRRAWDATAIN, * LPWFSPTRRAWDATAIN;

typedef struct _wfs_ptr_media_unit
{
    WORD            wBase;
    WORD            wUnitX;
    WORD            wUnitY;
} WFSPTRMEDIAUNIT, * LPWFSPTRMEDIAUNIT;

typedef struct _wfs_ptr_media_ext
{
    ULONG           ulSizeX;
    ULONG           ulSizeY;
} WFSPTRMEDIAEXT, * LPWFSPTRMEDIAEXT;

typedef struct _wfs_ptr_image_request
{
    WORD           wFrontImageType;
    WORD           wBackImageType;
    WORD           wFrontImageColorFormat;
    WORD           wBackImageColorFormat;
    WORD           wCodelineFormat;
    WORD           fwImageSource;
    LPSTR          lpszFrontImageFile;
    LPSTR          lpszBackImageFile;
} WFSPTRIMAGEREQUEST, * LPWFSPTRIMAGEREQUEST;

typedef struct _wfs_ptr_image
{
    WORD           wImageSource;
    WORD           wStatus;
    ULONG          ulDataLength;
    LPBYTE         lpbData;
} WFSPTRIMAGE, * LPWFSPTRIMAGE;

typedef struct _wfs_ptr_reset
{
    DWORD         dwMediaControl;
    USHORT        usRetractBinNumber;
} WFSPTRRESET, * LPWFSPTRRESET;


/*=================================================================*/
/* PTR Message Structures */
/*=================================================================*/

typedef struct _wfs_ptr_field_failure
{
    LPSTR           lpszFormName;
    LPSTR           lpszFieldName;
    WORD            wFailure;
} WFSPTRFIELDFAIL, * LPWFSPTRFIELDFAIL;

typedef struct _wfs_ptr_bin_threshold
{
    USHORT        usBinNumber;
    WORD          wRetractBin;
} WFSPTRBINTHRESHOLD, * LPWFSPTRBINTHRESHOLD;

typedef struct _wfs_ptr_paper_threshold
{
     WORD          wPaperSource;
     WORD          wPaperThreshold;
} WFSPTRPAPERTHRESHOLD, * LPWFSPTRPAPERTHRESHOLD;

typedef struct _wfs_ptr_media_detected
{
    WORD          wPosition;
    USHORT        usRetractBinNumber;
} WFSPTRMEDIADETECTED, * LPWFSPTRMEDIADETECTED;

/*   restore alignment   */
#pragma pack(pop)

#ifdef __cplusplus
}       /*extern "C"*/
#endif
#endif    /* __INC_XFSPTR__H */
