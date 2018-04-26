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

// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRCAPS.wClass"], codeName:"XfsServiceClass"}
#define    WFS_SERVICE_CLASS_PTR            (1)
// xfs-sst-js:{name:"end"}

#define    WFS_SERVICE_CLASS_VERSION_PTR    (0x0003) /* Version 3.00 */
#define    WFS_SERVICE_CLASS_NAME_PTR       "PTR"

#define    PTR_SERVICE_OFFSET               (WFS_SERVICE_CLASS_PTR * 100)


/* PTR Info Commands */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.u.dwCommandCode"], codeName:"XfsInfoCmd"}
#define    WFS_INF_PTR_STATUS               (PTR_SERVICE_OFFSET + 1)
#define    WFS_INF_PTR_CAPABILITIES         (PTR_SERVICE_OFFSET + 2)
#define    WFS_INF_PTR_FORM_LIST            (PTR_SERVICE_OFFSET + 3)
#define    WFS_INF_PTR_MEDIA_LIST           (PTR_SERVICE_OFFSET + 4)
#define    WFS_INF_PTR_QUERY_FORM           (PTR_SERVICE_OFFSET + 5)
#define    WFS_INF_PTR_QUERY_MEDIA          (PTR_SERVICE_OFFSET + 6)
#define    WFS_INF_PTR_QUERY_FIELD          (PTR_SERVICE_OFFSET + 7)
// xfs-sst-js:{name:"end"}

/* PTR Execute Commands */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.u.dwCommandCode"], codeName:"XfsExecuteCmd"}
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
// xfs-sst-js:{name:"end"}

/* PTR Messages */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.u.dwEventID"], codeName:"XfsEvent"}
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
// xfs-sst-js:{name:"end"}

/* values of WFSPTRSTATUS.fwDevice */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRSTATUS.fwDevice"], codeName:"XfsPtrDevStatus"}
#define    WFS_PTR_DEVONLINE                WFS_STAT_DEVONLINE
#define    WFS_PTR_DEVOFFLINE               WFS_STAT_DEVOFFLINE
#define    WFS_PTR_DEVPOWEROFF              WFS_STAT_DEVPOWEROFF
#define    WFS_PTR_DEVNODEVICE              WFS_STAT_DEVNODEVICE
#define    WFS_PTR_DEVHWERROR               WFS_STAT_DEVHWERROR
#define    WFS_PTR_DEVUSERERROR             WFS_STAT_DEVUSERERROR
#define    WFS_PTR_DEVBUSY                  WFS_STAT_DEVBUSY
// xfs-sst-js:{name:"end"}

/* values of WFSPTRSTATUS.fwMedia and
             WFSPTRMEDIADETECTED.wPosition */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRSTATUS.fwMedia", "WFSPTRMEDIADETECTED.wPosition"], codeName:"XfsPtrMediaPostion"}
#define    WFS_PTR_MEDIAPRESENT             (0)
#define    WFS_PTR_MEDIANOTPRESENT          (1)
#define    WFS_PTR_MEDIAJAMMED              (2)
#define    WFS_PTR_MEDIANOTSUPP             (3)
#define    WFS_PTR_MEDIAUNKNOWN             (4)
#define    WFS_PTR_MEDIAENTERING            (5)
#define    WFS_PTR_MEDIARETRACTED           (6)
// xfs-sst-js:{name:"end"}

/* Size and max index of fwPaper array */

#define    WFS_PTR_SUPPLYSIZE    (16)
#define    WFS_PTR_SUPPLYMAX     (WFS_PTR_SUPPLYSIZE - 1)


/* Indices of WFSPTRSTATUS.fwPaper [...] */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRSTATUS.fwPaper.index"], index:true, codeName:"XfsPtrPaperSupply"}
#define    WFS_PTR_SUPPLYUPPER              (0)
#define    WFS_PTR_SUPPLYLOWER              (1)
#define    WFS_PTR_SUPPLYEXTERNAL           (2)
#define    WFS_PTR_SUPPLYAUX                (3)
#define    WFS_PTR_SUPPLYAUX2               (4)
#define    WFS_PTR_SUPPLYPARK               (5)
// xfs-sst-js:{name:"end"}

/* values of WFSPTRSTATUS.fwPaper and
             WFSPTRPAPERTHRESHOLD.wPaperThreshold */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRSTATUS.fwPaper", "WFSPTRPAPERTHRESHOLD.wPaperThreshold"], codeName:"XfsPtrPaperStatus"}
#define    WFS_PTR_PAPERFULL                (0)
#define    WFS_PTR_PAPERLOW                 (1)
#define    WFS_PTR_PAPEROUT                 (2)
#define    WFS_PTR_PAPERNOTSUPP             (3)
#define    WFS_PTR_PAPERUNKNOWN             (4)
#define    WFS_PTR_PAPERJAMMED              (5)
// xfs-sst-js:{name:"end"}

/* values of WFSPTRSTATUS.fwToner */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRSTATUS.fwToner", "WFSPTRTONERTHRESHOLD.lpwTonerThreshold"], codeName:"XfsPtrTonerSatus"}
#define    WFS_PTR_TONERFULL                (0)
#define    WFS_PTR_TONERLOW                 (1)
#define    WFS_PTR_TONEROUT                 (2)
#define    WFS_PTR_TONERNOTSUPP             (3)
#define    WFS_PTR_TONERUNKNOWN             (4)
// xfs-sst-js:{name:"end"}

/* values of WFSPTRSTATUS.fwInk */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRSTATUS.fwInk", "WFSPTRINKTHRESHOLD.wInkThreshold"], codeName:"XfsPtrInkStatus"}
#define    WFS_PTR_INKFULL                  (0)
#define    WFS_PTR_INKLOW                   (1)
#define    WFS_PTR_INKOUT                   (2)
#define    WFS_PTR_INKNOTSUPP               (3)
#define    WFS_PTR_INKUNKNOWN               (4)
// xfs-sst-js:{name:"end"}

/* values of WFSPTRSTATUS.fwLamp */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRSTATUS.fwLamp", "WFSPTRLAMPTHRESHOLD.wLampThreshold"], codeName:"XfsPtrLampStatus"}
#define    WFS_PTR_LAMPOK                   (0)
#define    WFS_PTR_LAMPFADING               (1)
#define    WFS_PTR_LAMPINOP                 (2)
#define    WFS_PTR_LAMPNOTSUPP              (3)
#define    WFS_PTR_LAMPUNKNOWN              (4)
// xfs-sst-js:{name:"end"}

/* values of WFSPTRSTATUS.fwRetractBin and
             WFSPTRBINTHRESHOLD.wRetractBin */
// applies to WFSPTRRETRACTBINS.wRetractBin
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRRETRACTBINS.wRetractBin", "WFSPTRSTATUS.fwRetractBin", "WFSPTRBINTHRESHOLD.wRetractBin"], codeName:"XfsPtrRetractBinStatus"}
#define    WFS_PTR_RETRACTBINOK             (0)
#define    WFS_PTR_RETRACTBINFULL           (1)
#define    WFS_PTR_RETRACTNOTSUPP           (2)
#define    WFS_PTR_RETRACTUNKNOWN           (3)
#define    WFS_PTR_RETRACTBINHIGH           (4)
// xfs-sst-js:{name:"end"}

/* values of WFSPTRCAPS.fwType */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSPTRCAPS.fwType"], codeName:"XfsPtrType"}
#define    WFS_PTR_TYPERECEIPT              0x0001
#define    WFS_PTR_TYPEPASSBOOK             0x0002
#define    WFS_PTR_TYPEJOURNAL              0x0004
#define    WFS_PTR_TYPEDOCUMENT             0x0008
#define    WFS_PTR_TYPESCANNER              0x0010
// xfs-sst-js:{name:"end"}

/* values of WFSPTRCAPS.wResolution, WFSPTRPRINTFORM.wResolution */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSPTRCAPS.wResolution", "WFSPTRPRINTFORM.wResolution"], codeName:"XfsPtrResolution"}
#define    WFS_PTR_RESLOW                   0x0001
#define    WFS_PTR_RESMED                   0x0002
#define    WFS_PTR_RESHIGH                  0x0004
#define    WFS_PTR_RESVERYHIGH              0x0008
// xfs-sst-js:{name:"end"}

/* values of WFSPTRCAPS.fwReadForm */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSPTRCAPS.fwReadForm"], codeName:"XfsPtrFormReadCap"}
#define    WFS_PTR_READOCR                  0x0001
#define    WFS_PTR_READMICR                 0x0002
#define    WFS_PTR_READMSF                  0x0004
#define    WFS_PTR_READBARCODE              0x0008
#define    WFS_PTR_READPAGEMARK             0x0010
#define    WFS_PTR_READIMAGE                0x0020
#define    WFS_PTR_READEMPTYLINE            0x0040
// xfs-sst-js:{name:"end"}

/* values of WFSPTRCAPS.fwWriteForm */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSPTRCAPS.fwWriteForm"], codeName:"XfsPtrFormWriteCap"}
#define    WFS_PTR_WRITETEXT                0x0001
#define    WFS_PTR_WRITEGRAPHICS            0x0002
#define    WFS_PTR_WRITEOCR                 0x0004
#define    WFS_PTR_WRITEMICR                0x0008
#define    WFS_PTR_WRITEMSF                 0x0010
#define    WFS_PTR_WRITEBARCODE             0x0020
#define    WFS_PTR_WRITESTAMP               0x0040
// xfs-sst-js:{name:"end"}

/* values of WFSPTRCAPS.fwExtents */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSPTRCAPS.fwExtents"], codeName:"XfsPtrExtent"}
#define    WFS_PTR_EXTHORIZONTAL            0x0001
#define    WFS_PTR_EXTVERTICAL              0x0002
// xfs-sst-js:{name:"end"}

/* values of WFSPTRCAPS.fwControl, dwMediaControl */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSPTRCAPS.fwControl", "WFSPTRRESET.dwMediaControl", "WFSPTRREADFORM.dwMediaControl", "WFSPTRPRINTFORM.dwMediaControl", "WFSPTCONTROLMEDIA.dwMediaControl"], codeName:"XfsPtrControl"}
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
// xfs-sst-js:{name:"end"}

/* values of WFSPTRCAPS.fwPaperSources,
             WFSFRMMEDIA.wPaperSources,
             WFSPTRPRINTFORM.wPaperSource and
             WFSPTRPAPERTHRESHOLD.wPaperSource   */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSPTRDISPENSEPAPER.wPaperSource", "WFSPTRDISPENSEPAPER.wPaperSource", "WFSPTRCAPS.fwPaperSources", "WFSFRMMEDIA.wPaperSources", "WFSPTRPRINTFORM.wPaperSource", "WFSPTRPAPERTHRESHOLD.wPaperSource"], codeName:"XfsPtrPaperSource"}
#define    WFS_PTR_PAPERANY                 0x0001
#define    WFS_PTR_PAPERUPPER               0x0002
#define    WFS_PTR_PAPERLOWER               0x0004
#define    WFS_PTR_PAPEREXTERNAL            0x0008
#define    WFS_PTR_PAPERAUX                 0x0010
#define    WFS_PTR_PAPERAUX2                0x0020
#define    WFS_PTR_PAPERPARK                0x0040
// xfs-sst-js:{name:"end"}

/* values of WFSPTRCAPS.fwImageType,
             WFSPTRIMAGEREQUEST.wFrontImageFormat and
             WFSPTRIMAGEREQUEST.wBackImageFormat */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSPTRCAPS.fwImageType", "WFSPTRIMAGEREQUEST.wFrontImageFormat", "WFSPTRIMAGEREQUEST.wBackImageFormat"], codeName:"XfsPtrImageType"}
#define    WFS_PTR_IMAGETIF                 0x0001
#define    WFS_PTR_IMAGEWMF                 0x0002
#define    WFS_PTR_IMAGEBMP                 0x0004
// xfs-sst-js:{name:"end"}

/* values of WFSPTRCAPS.fwFrontImageColorFormat,
             WFSPTRCAPS.fwBackImageColorFormat,
             WFSPTRIMAGEREQUEST.wFrontImageColorFormat and
             WFSPTRIMAGEREQUEST.wBackImageColorFormat */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSPTRCAPS.fwFrontImageColorFormat", "WFSPTRCAPS.fwBackImageColorFormat", "WFSPTRIMAGEREQUEST.wFrontImageColorFormat", "WFSPTRIMAGEREQUEST.wBackImageColorFormat", "WFSPTRIMAGEREQUEST.wBackImageColorFormat"], codeName:"XfsPtrColorFormat"}
#define    WFS_PTR_IMAGECOLORBINARY         0x0001
#define    WFS_PTR_IMAGECOLORGRAYSCALE      0x0002
#define    WFS_PTR_IMAGECOLORFULL           0x0004
// xfs-sst-js:{name:"end"}

/* values of WFSPTRCAPS.fwCodelineFormat and
             WFSPTRIMAGEREQUEST.wCodelineFormat */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSPTRCAPS.fwCodelineFormat", "WFSPTRIMAGEREQUEST.wCodelineFormat"], codeName:"XfsPtrCodelineFormat"}
#define    WFS_PTR_CODELINECMC7             0x0001
#define    WFS_PTR_CODELINEE13B             0x0002
#define    WFS_PTR_CODELINEOCR              0x0004
// xfs-sst-js:{name:"end"}

/* values of WFSPTRCAPS.fwImageSource,
             WFSPTRIMAGEREQUEST.fwImageSource and
             WFSPTRIMAGE.wImageSource */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSPTRCAPS.fwImageSource", "WFSPTRIMAGEREQUEST.fwImageSource", "WFSPTRIMAGE.wImageSource"], codeName:"XfsPtrImageSource"}
#define    WFS_PTR_IMAGEFRONT               0x0001
#define    WFS_PTR_IMAGEBACK                0x0002
#define    WFS_PTR_CODELINE                 0x0004
// xfs-sst-js:{name:"end"}

/* values of WFSPTRCAPS.fwCharSupport, WFSFRMHEADER.fwCharSupport  */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSPTRCAPS.fwCharSupport", "WFSFRMHEADER.fwCharSupport"], codeName:"XfsPtrCharSupport"}
#define    WFS_PTR_ASCII                    0x0001
#define    WFS_PTR_UNICODE                  0x0002
// xfs-sst-js:{name:"end"}

/* values of WFSFRMHEADER.wBase, WFSFRMMEDIA.wBase, WFSPTRMEDIAUNIT.wBase */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSFRMHEADER.wBase", "WFSFRMMEDIA.wBase", "WFSPTRMEDIAUNIT.wBase"], codeName:"XfsPtrBase"}
#define    WFS_FRM_INCH                     (0)
#define    WFS_FRM_MM                       (1)
#define    WFS_FRM_ROWCOLUMN                (2)
// xfs-sst-js:{name:"end"}

/* values of WFSFRMHEADER.wAlignment */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSFRMHEADER.wAlignment"], codeName:"XfsPtrAlignment"}
#define    WFS_FRM_TOPLEFT                  (0)
#define    WFS_FRM_TOPRIGHT                 (1)
#define    WFS_FRM_BOTTOMLEFT               (2)
#define    WFS_FRM_BOTTOMRIGHT              (3)
// xfs-sst-js:{name:"end"}

/* values of WFSFRMHEADER.wOrientation */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSFRMHEADER.wOrientation"], codeName:"XfsPtr"}
#define    WFS_FRM_PORTRAIT                 (0)
#define    WFS_FRM_LANDSCAPE                (1)
// xfs-sst-js:{name:"end"}

/* values of WFSFRMMEDIA.fwMediaType */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSFRMMEDIA.fwMediaType"], codeName:"XfsPtrMediaType"}
#define    WFS_FRM_MEDIAGENERIC             (0)
#define    WFS_FRM_MEDIAPASSBOOK            (1)
#define    WFS_FRM_MEDIAMULTIPART           (2)
// xfs-sst-js:{name:"end"}

/* values of WFSFRMMEDIA.fwFoldType */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSFRMMEDIA.fwFoldType"], codeName:"XfsPtrMediaFoldType"}
#define    WFS_FRM_FOLDNONE                 (0)
#define    WFS_FRM_FOLDHORIZONTAL           (1)
#define    WFS_FRM_FOLDVERTICAL             (2)
// xfs-sst-js:{name:"end"}

/* values of WFSFRMFIELD.fwType */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSFRMFIELD.fwType"], codeName:"XfsPtrFormFieldType"}
#define    WFS_FRM_FIELDTEXT                (0)
#define    WFS_FRM_FIELDMICR                (1)
#define    WFS_FRM_FIELDOCR                 (2)
#define    WFS_FRM_FIELDMSF                 (3)
#define    WFS_FRM_FIELDBARCODE             (4)
#define    WFS_FRM_FIELDGRAPHIC             (5)
#define    WFS_FRM_FIELDPAGEMARK            (6)
// xfs-sst-js:{name:"end"}

/* values of WFSFRMFIELD.fwClass */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSFRMFIELD.fwClass"], codeName:"XfsPtrFormFieldClass"}
#define    WFS_FRM_CLASSSTATIC              (0)
#define    WFS_FRM_CLASSOPTIONAL            (1)
#define    WFS_FRM_CLASSREQUIRED            (2)
// xfs-sst-js:{name:"end"}

/* values of WFSFRMFIELD.fwAccess */
// xfs-sst-js:{name:"nc", bitwise:true, applies:["WFSFRMFIELD.fwAccess"], codeName:"XfsPtrFormFieldAccess"}
#define    WFS_FRM_ACCESSREAD               0x0001
#define    WFS_FRM_ACCESSWRITE              0x0002
// xfs-sst-js:{name:"end"}

/* values of WFSFRMFIELD.fwOverflow */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSFRMFIELD.fwOverflow"], codeName:"XfsPtrFormFieldOverflow"}
#define    WFS_FRM_OVFTERMINATE             (0)
#define    WFS_FRM_OVFTRUNCATE              (1)
#define    WFS_FRM_OVFBESTFIT               (2)
#define    WFS_FRM_OVFOVERWRITE             (3)
#define    WFS_FRM_OVFWORDWRAP              (4)
// xfs-sst-js:{name:"end"}

/* values of WFSPTRFIELDFAIL.wFailure */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRFIELDFAIL.wFailure, WFSPTRFIELDWARNING.wFailure"], codeName:"XfsPtrFormFieldFailure"}
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
// xfs-sst-js:{name:"end"}

/* values of WFSPTRPRINTFORM.wAlignment */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRPRINTFORM.wAlignment"], codeName:"XfsPtrFormAlignment"}
#define    WFS_PTR_ALNUSEFORMDEFN           (0)
#define    WFS_PTR_ALNTOPLEFT               (1)
#define    WFS_PTR_ALNTOPRIGHT              (2)
#define    WFS_PTR_ALNBOTTOMLEFT            (3)
#define    WFS_PTR_ALNBOTTOMRIGHT           (4)
// xfs-sst-js:{name:"end"}

/* values of WFSPTRPRINTFORM.wOffsetX and WFSPTRPRINTFORM.wOffsetY */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRPRINTFORM.wOffsetX and WFSPTRPRINTFORM.wOffsetY"], codeName:"XfsPtrFormOffset"}
#define    WFS_PTR_OFFSETUSEFORMDEFN        0xffff
// xfs-sst-js:{name:"end"}

/* values of WFSPTRRAWDATA.wInputData */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRRAWDATA.wInputData"], codeName:"XfsPtrFormInputData"}
#define    WFS_PTR_NOINPUTDATA              (0)
#define    WFS_PTR_INPUTDATA                (1)
// xfs-sst-js:{name:"end"}

/* values of WFSPTRIMAGE.wStatus */
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSPTRIMAGE.wStatus"], codeName:"XfsPtrImageStatus"}
#define     WFS_PTR_DATAOK                  (0)
#define     WFS_PTR_DATASRCNOTSUPP          (1)
#define     WFS_PTR_DATASRCMISSING          (2)
// xfs-sst-js:{name:"end"}

/* XFS PTR Errors */ 
// xfs-sst-js:{name:"nc", bitwise:false, applies:["WFSRESULT.hResult"], codeName:"XfsErrorCode"}
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
// xfs-sst-js:{name:"end"}

/*=================================================================*/
/* PTR Info Command Structures */
/*=================================================================*/
// xfs-sst-js:{name:"data", type:"WFSPTRRETRACTBINS", codeName:"PtrRetractBins", leading:3, output:true, input:false, command:""}
typedef struct _wfs_ptr_retract_bins
{
   WORD      wRetractBin;                           // xfs-sst-js:{name:"data.field"}
   USHORT    usRetractCount;                        // xfs-sst-js:{name:"data.field"}
} WFSPTRRETRACTBINS, * LPWFSPTRRETRACTBINS;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRSTATUS", codeName:"PtrStatus", leading:3, output:true, input:false, command:"WFS_INF_PTR_STATUS"}
typedef struct _wfs_ptr_status        
{
    WORD            fwDevice;                       // xfs-sst-js:{name:"data.field"}
    WORD            fwMedia;                        // xfs-sst-js:{name:"data.field"}
    WORD            fwPaper[WFS_PTR_SUPPLYSIZE];    // xfs-sst-js:{name:"data.field", namedArray:true, namedArrayIndex:"WFSPTRSTATUS.fwPaper.index"}
    WORD            fwToner;                        // xfs-sst-js:{name:"data.field"}
    WORD            fwInk;                          // xfs-sst-js:{name:"data.field"}
    WORD            fwLamp;                         // xfs-sst-js:{name:"data.field"}
    LPWFSPTRRETRACTBINS *lppRetractBins;            // xfs-sst-js:{name:"data.field", ntArray:true}
    USHORT          usMediaOnStacker;               // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszExtra;                      // xfs-sst-js:{name:"data.field"}
} WFSPTRSTATUS, * LPWFSPTRSTATUS;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRCAPS", codeName:"PtrCaps", leading:3, output:true, input:false, command:"WFS_INF_PTR_CAPABILITIES"}
typedef struct _wfs_ptr_caps
{
    WORD            wClass;					  // xfs-sst-js:{name:"data.field"}
    WORD            fwType;                             // xfs-sst-js:{name:"data.field"}
    BOOL            bCompound;                          // xfs-sst-js:{name:"data.field"}
    WORD            wResolution;				  // xfs-sst-js:{name:"data.field"}
    WORD            fwReadForm;                         // xfs-sst-js:{name:"data.field"}
    WORD            fwWriteForm;                        // xfs-sst-js:{name:"data.field"}
    WORD            fwExtents;				  // xfs-sst-js:{name:"data.field"}
    WORD            fwControl;				  // xfs-sst-js:{name:"data.field"}
    USHORT          usMaxMediaOnStacker;                // xfs-sst-js:{name:"data.field"}
    BOOL            bAcceptMedia;				  // xfs-sst-js:{name:"data.field"}
    BOOL            bMultiPage;                         // xfs-sst-js:{name:"data.field"}
    WORD            fwPaperSources;                     // xfs-sst-js:{name:"data.field"}
    BOOL            bMediaTaken;                        // xfs-sst-js:{name:"data.field"}
    USHORT          usRetractBins;                      // xfs-sst-js:{name:"data.field"}
    LPUSHORT        lpusMaxRetract;                     // xfs-sst-js:{name:"data.field"}
    WORD            fwImageType;                        // xfs-sst-js:{name:"data.field"}
    WORD            fwFrontImageColorFormat;            // xfs-sst-js:{name:"data.field"}
    WORD            fwBackImageColorFormat;             // xfs-sst-js:{name:"data.field"}
    WORD            fwCodelineFormat;			  // xfs-sst-js:{name:"data.field"}
    WORD            fwImageSource;                      // xfs-sst-js:{name:"data.field"}
    WORD            fwCharSupport;                      // xfs-sst-js:{name:"data.field"}
    BOOL            bDispensePaper;                     // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszExtra;                          // xfs-sst-js:{name:"data.field"}
} WFSPTRCAPS, * LPWFSPTRCAPS;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSFRMHEADER", codeName:"PtrFormHeader", leading:3, output:true, input:false, command:"WFS_INF_PTR_QUERY_FORM"}
typedef struct _wfs_frm_header
{
    LPSTR           lpszFormName;				  // xfs-sst-js:{name:"data.field"}
    WORD            wBase;                              // xfs-sst-js:{name:"data.field"}
    WORD            wUnitX;                             // xfs-sst-js:{name:"data.field"}
    WORD            wUnitY;                             // xfs-sst-js:{name:"data.field"}
    WORD            wWidth;                             // xfs-sst-js:{name:"data.field"}
    WORD            wHeight;                            // xfs-sst-js:{name:"data.field"}
    WORD            wAlignment;                         // xfs-sst-js:{name:"data.field"}
    WORD            wOrientation;                       // xfs-sst-js:{name:"data.field"}
    WORD            wOffsetX;                           // xfs-sst-js:{name:"data.field"}
    WORD            wOffsetY;                           // xfs-sst-js:{name:"data.field"}
    WORD            wVersionMajor;                      // xfs-sst-js:{name:"data.field"}
    WORD            wVersionMinor;                      // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszUserPrompt;                     // xfs-sst-js:{name:"data.field"}
    WORD            fwCharSupport;                      // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszFields;                         // xfs-sst-js:{name:"data.field", ntStringList:true}
} WFSFRMHEADER, * LPWFSFRMHEADER;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSFRMMEDIA", codeName:"PtrFormMedia", leading:3, output:true, input:false, command:"WFS_INF_PTR_QUERY_MEDIA"}
typedef struct _wfs_frm_media
{
    WORD            fwMediaType;				  // xfs-sst-js:{name:"data.field"}
    WORD            wBase;                              // xfs-sst-js:{name:"data.field"}
    WORD            wUnitX;                             // xfs-sst-js:{name:"data.field"}
    WORD            wUnitY;                             // xfs-sst-js:{name:"data.field"}
    WORD            wSizeWidth;                         // xfs-sst-js:{name:"data.field"}
    WORD            wSizeHeight;                        // xfs-sst-js:{name:"data.field"}
    WORD            wPageCount;                         // xfs-sst-js:{name:"data.field"}
    WORD            wLineCount;                         // xfs-sst-js:{name:"data.field"}
    WORD            wPrintAreaX;                        // xfs-sst-js:{name:"data.field"}
    WORD            wPrintAreaY;                        // xfs-sst-js:{name:"data.field"}
    WORD            wPrintAreaWidth;                    // xfs-sst-js:{name:"data.field"}
    WORD            wPrintAreaHeight;                   // xfs-sst-js:{name:"data.field"}
    WORD            wRestrictedAreaX;                   // xfs-sst-js:{name:"data.field"}
    WORD            wRestrictedAreaY;                   // xfs-sst-js:{name:"data.field"}
    WORD            wRestrictedAreaWidth;               // xfs-sst-js:{name:"data.field"}
    WORD            wRestrictedAreaHeight;		  // xfs-sst-js:{name:"data.field"}
    WORD            wStagger;                           // xfs-sst-js:{name:"data.field"}
    WORD            wFoldType;                          // xfs-sst-js:{name:"data.field"}
    WORD            wPaperSources;                      // xfs-sst-js:{name:"data.field"}
} WFSFRMMEDIA, * LPWFSFRMMEDIA;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRQUERYFIELD", codeName:"PtrQueryField", leading:3, output:false, input:true, command:"WFS_INF_PTR_QUERY_FIELD"}
typedef struct _wfs_ptr_query_field
{
    LPSTR           lpszFormName;				  // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszFieldName;                      // xfs-sst-js:{name:"data.field", defaultValue:null}
} WFSPTRQUERYFIELD, * LPWFSPTRQUERYFIELD;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSFRMFIELD", codeName:"PtrFormField", leading:3, output:true, input:false, command:"WFS_INF_PTR_QUERY_FIELD", ntArray:true}
typedef struct _wfs_frm_field
{
    LPSTR           lpszFieldName;				  // xfs-sst-js:{name:"data.field"}
    WORD            wIndexCount;                        // xfs-sst-js:{name:"data.field"}
    WORD            fwType;                             // xfs-sst-js:{name:"data.field"}
    WORD            fwClass;                            // xfs-sst-js:{name:"data.field"}
    WORD            fwAccess;                           // xfs-sst-js:{name:"data.field"}
    WORD            fwOverflow;                         // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszInitialValue;                   // xfs-sst-js:{name:"data.field"}
    LPWSTR          lpszUNICODEInitialValue;            // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszFormat;                         // xfs-sst-js:{name:"data.field"}
    LPWSTR          lpszUNICODEFormat;			  // xfs-sst-js:{name:"data.field"}
} WFSFRMFIELD, * LPWFSFRMFIELD;
// xfs-sst-js:{name:"end"}


/*=================================================================*/
/* PTR Execute Command Structures */
/*=================================================================*/

// xfs-sst-js:{name:"data", type:"WFSPTRPRINTFORM", codeName:"PtrPrintForm", leading:3, output:false, input:true, command:"WFS_CMD_PTR_PRINT_FORM", sortFields:true}
typedef struct _wfs_ptr_print_form
{
    LPSTR           lpszFormName; 				  // xfs-sst-js:{name:"data.field", seq:0}
    LPSTR           lpszMediaName;                      // xfs-sst-js:{name:"data.field", seq:1}
    WORD            wAlignment;                         // xfs-sst-js:{name:"data.field", defaultValue:"WFS_PTR_ALNUSEFORMDEFN", seq:7}
    WORD            wOffsetX;                           // xfs-sst-js:{name:"data.field", defaultValue:0, seq:8}
    WORD            wOffsetY;                           // xfs-sst-js:{name:"data.field", defaultValue:0, seq:9}
    WORD            wResolution;                        // xfs-sst-js:{name:"data.field", defaultValue:"WFS_PTR_RESLOW", seq:10}
    DWORD           dwMediaControl;                     // xfs-sst-js:{name:"data.field", seq:4}
    LPSTR           lpszFields;                         // xfs-sst-js:{name:"data.field", kvGroups:true, seq:2, defaultValue:{}}
    LPWSTR          lpszUNICODEFields;                  // x!fs-sst-js:{name:"data.field", seq:3}
    WORD            wPaperSource;                       // xfs-sst-js:{name:"data.field", defaultValue:"WFS_PTR_PAPERANY", seq:6}
} WFSPTRPRINTFORM, * LPWFSPTRPRINTFORM;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRREADFORM", codeName:"PtrReadForm", leading:3, output:false, input:true, command:"WFS_CMD_PTR_READ_FORM"}
typedef struct _wfs_ptr_read_form
{
    LPSTR           lpszFormName;				   // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszFieldNames;                      // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszMediaName;                       // xfs-sst-js:{name:"data.field"}
    DWORD           dwMediaControl;                      // xfs-sst-js:{name:"data.field"}
} WFSPTRREADFORM, * LPWFSPTRREADFORM;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRREADFORMOUT", codeName:"PtrReadFormOut", leading:3, output:true, input:false, command:"WFS_CMD_PTR_READ_FORM"}
typedef struct _wfs_ptr_read_form_out
{	
    LPSTR           lpszFields;				  // xfs-sst-js:{name:"data.field"}
    LPWSTR          lpszUNICODEFields;                  // xfs-sst-js:{name:"data.field"}
} WFSPTRREADFORMOUT, * LPWFSPTRREADFORMOUT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRRAWDATA", codeName:"PtrRawData", leading:3, output:false, input:true, command:"WFS_CMD_PTR_RAW_DATA"}
typedef struct _wfs_ptr_raw_data
{
    WORD            wInputData;				  // xfs-sst-js:{name:"data.field", defaultValue:"WFS_PTR_NOINPUTDATA"}
    ULONG           ulSize;                             // xfs-sst-js:{name:"data.field", defaultValue:0}
    LPBYTE          lpbData;					  // xfs-sst-js:{name:"data.field", defaultValue:""}	
} WFSPTRRAWDATA, * LPWFSPTRRAWDATA;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRRAWDATAIN", codeName:"PtrRawDataIn", leading:3, output:true, input:false, command:"WFS_CMD_PTR_RAW_DATA"}
typedef struct _wfs_ptr_raw_data_in
{
    ULONG           ulSize;					  // xfs-sst-js:{name:"data.field"}
    LPBYTE          lpbData;                            // xfs-sst-js:{name:"data.field"}
} WFSPTRRAWDATAIN, * LPWFSPTRRAWDATAIN;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRMEDIAUNIT", codeName:"PtrMediaUit", leading:3, output:false, input:true, command:"WFS_CMD_PTR_MEDIA_EXTENTS"}
typedef struct _wfs_ptr_media_unit
{
    WORD            wBase;					  // xfs-sst-js:{name:"data.field", defaultValue:"WFS_FRM_INCH"}
    WORD            wUnitX;                             // xfs-sst-js:{name:"data.field", defaultValue:96}
    WORD            wUnitY;                             // xfs-sst-js:{name:"data.field", defaultValue:96}
} WFSPTRMEDIAUNIT, * LPWFSPTRMEDIAUNIT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRMEDIAEXT", codeName:"PtrMediaExt", leading:3, output:true, input:false, command:"WFS_CMD_PTR_MEDIA_EXTENTS"}
typedef struct _wfs_ptr_media_ext
{
    ULONG           ulSizeX;					  // xfs-sst-js:{name:"data.field"}
    ULONG           ulSizeY;                            // xfs-sst-js:{name:"data.field"}
} WFSPTRMEDIAEXT, * LPWFSPTRMEDIAEXT;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRIMAGEREQUEST", codeName:"PtrImageRequest", leading:3, output:false, input:true, command:"WFS_CMD_PTR_READ_IMAGE"}
typedef struct _wfs_ptr_image_request
{
    WORD           wFrontImageType;				  // xfs-sst-js:{name:"data.field"}
    WORD           wBackImageType;                      // xfs-sst-js:{name:"data.field"}
    WORD           wFrontImageColorFormat;              // xfs-sst-js:{name:"data.field"}
    WORD           wBackImageColorFormat;               // xfs-sst-js:{name:"data.field"}
    WORD           wCodelineFormat;                     // xfs-sst-js:{name:"data.field"}
    WORD           fwImageSource;                       // xfs-sst-js:{name:"data.field"}
    LPSTR          lpszFrontImageFile;                  // xfs-sst-js:{name:"data.field", defaultValue:null}
    LPSTR          lpszBackImageFile;                   // xfs-sst-js:{name:"data.field", defaultValue:null}
} WFSPTRIMAGEREQUEST, * LPWFSPTRIMAGEREQUEST;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRIMAGE", codeName:"PtrImage", leading:3, output:true, input:false, command:"WFS_CMD_PTR_READ_IMAGE", ntArray:true}
typedef struct _wfs_ptr_image
{
    WORD           wImageSource;				  // xfs-sst-js:{name:"data.field"}
    WORD           wStatus;                             // xfs-sst-js:{name:"data.field"}
    ULONG          ulDataLength;                        // xfs-sst-js:{name:"data.field"}
    LPBYTE         lpbData;                             // xfs-sst-js:{name:"data.field"}
} WFSPTRIMAGE, * LPWFSPTRIMAGE;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRRESET", codeName:"PtrReset", leading:3, output:false, input:true, command:"WFS_CMD_PTR_RESET"}
typedef struct _wfs_ptr_reset
{
    DWORD         dwMediaControl;				  // xfs-sst-js:{name:"data.field", defaultValue:"WFS_PTR_CTRLRETRACT"}
    USHORT        usRetractBinNumber;                   // xfs-sst-js:{name:"data.field", defaultValue:0}
} WFSPTRRESET, * LPWFSPTRRESET;
// xfs-sst-js:{name:"end"}


/*=================================================================*/
/* PTR Message Structures */
/*=================================================================*/

// xfs-sst-js:{name:"data", type:"WFSPTRFIELDFAIL", codeName:"PtrFieldFailure", leading:3, output:true, input:false, command:"WFS_EXEE_PTR_FIELDERROR"}
typedef struct _wfs_ptr_field_failure
{
    LPSTR           lpszFormName;				  // xfs-sst-js:{name:"data.field"}
    LPSTR           lpszFieldName;                      // xfs-sst-js:{name:"data.field"}
    WORD            wFailure;                           // xfs-sst-js:{name:"data.field"}
} WFSPTRFIELDFAIL, * LPWFSPTRFIELDFAIL;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRBINTHRESHOLD", codeName:"PtrBinThreshold", leading:3, output:true, input:false, command:"WFS_USRE_PTR_RETRACTBINTHRESHOLD"}
typedef struct _wfs_ptr_bin_threshold
{
    USHORT        usBinNumber;				  // xfs-sst-js:{name:"data.field"}
    WORD          wRetractBin;                          // xfs-sst-js:{name:"data.field"}
} WFSPTRBINTHRESHOLD, * LPWFSPTRBINTHRESHOLD;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRPAPERTHRESHOLD", codeName:"PtrPaperThreshold", leading:3, output:true, input:false, command:"WFS_USRE_PTR_PAPERTHRESHOLD"}
typedef struct _wfs_ptr_paper_threshold
{
     WORD          wPaperSource;				  // xfs-sst-js:{name:"data.field"}
     WORD          wPaperThreshold;                     // xfs-sst-js:{name:"data.field"}
} WFSPTRPAPERTHRESHOLD, * LPWFSPTRPAPERTHRESHOLD;
// xfs-sst-js:{name:"end"}

// xfs-sst-js:{name:"data", type:"WFSPTRMEDIADETECTED", codeName:"PtrMediaDected", leading:3, output:true, input:false, command:"WFS_SRVE_PTR_MEDIADETECTED"}
typedef struct _wfs_ptr_media_detected
{
    WORD          wPosition;					 // xfs-sst-js:{name:"data.field"}
    USHORT        usRetractBinNumber;                  // xfs-sst-js:{name:"data.field"}
} WFSPTRMEDIADETECTED, * LPWFSPTRMEDIADETECTED;
// xfs-sst-js:{name:"end"}

/*   restore alignment   */
#pragma pack(pop)

#ifdef __cplusplus
}       /*extern "C"*/
#endif
#endif    /* __INC_XFSPTR__H */
