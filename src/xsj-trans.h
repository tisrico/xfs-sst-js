#ifndef __xsj_translate__h
#define __xsj_translate__h

#include "pseudo.h"
#include "xfsapi.h"
#include "xfsadmin.h"
#include "xfsceu.h"
#include "xfspin.h"
#include "xfsalm.h"
#include "xfschk.h"
#include "xfsptr.h"
#include "xfscim.h"
#include "xfssiu.h"
#include "xfsbcr.h"
#include "xfsconf.h"
#include "xfsspi.h"
#include "xfscam.h"
#include "xfsdep.h"
#include "xfsttu.h"
#include "xfscdm.h"
#include "xfsidc.h"
#include "xfsvdm.h"
#include "xfsapi_xsj.h"
#include "xfsadmin_xsj.h"
#include "xfsceu_xsj.h"
#include "xfspin_xsj.h"
#include "xfsalm_xsj.h"
#include "xfschk_xsj.h"
#include "xfsptr_xsj.h"
#include "xfscim_xsj.h"
#include "xfssiu_xsj.h"
#include "xfsbcr_xsj.h"
#include "xfsconf_xsj.h"
#include "xfsspi_xsj.h"
#include "xfscam_xsj.h"
#include "xfsdep_xsj.h"
#include "xfsttu_xsj.h"
#include "xfscdm_xsj.h"
#include "xfsidc_xsj.h"
#include "xfsvdm_xsj.h"

#include "nc.h"

#include "json.hpp"
using json = nlohmann::json;

//##############################################################################
//##############################################################################
template <typename T>
T* XSJTranslate(const json& j, XSJAllocator* a);

template <typename T>
json XSJTranslate(const T* p);


//##############################################################################
// GetXfsDevStatusName GetXfsDevStatusId 
//##############################################################################
#define ListXfsDevStatus(expr) \
	expr(WFS_STAT_DEVONLINE) \
	expr(WFS_STAT_DEVOFFLINE) \
	expr(WFS_STAT_DEVPOWEROFF) \
	expr(WFS_STAT_DEVNODEVICE) \
	expr(WFS_STAT_DEVHWERROR) \
	expr(WFS_STAT_DEVUSERERROR) \
	expr(WFS_STAT_DEVBUSY) \

DNICODE(XfsDevStatus);

//##############################################################################
// GetXfsErrorCodeName GetXfsErrorCodeId 
//##############################################################################
#define ListXfsErrorCode(expr) \
	expr(XSJ_INVALID_STATE) \
	expr(XSJ_INVALID_DATA) \
	expr(XSJ_COMMAND_NOT_FOUND) \
	expr(WFS_SUCCESS) \
	expr(WFS_ERR_ALREADY_STARTED) \
	expr(WFS_ERR_API_VER_TOO_HIGH) \
	expr(WFS_ERR_API_VER_TOO_LOW) \
	expr(WFS_ERR_CANCELED) \
	expr(WFS_ERR_CFG_INVALID_HKEY) \
	expr(WFS_ERR_CFG_INVALID_NAME) \
	expr(WFS_ERR_CFG_INVALID_SUBKEY) \
	expr(WFS_ERR_CFG_INVALID_VALUE) \
	expr(WFS_ERR_CFG_KEY_NOT_EMPTY) \
	expr(WFS_ERR_CFG_NAME_TOO_LONG) \
	expr(WFS_ERR_CFG_NO_MORE_ITEMS) \
	expr(WFS_ERR_CFG_VALUE_TOO_LONG) \
	expr(WFS_ERR_DEV_NOT_READY) \
	expr(WFS_ERR_HARDWARE_ERROR) \
	expr(WFS_ERR_INTERNAL_ERROR) \
	expr(WFS_ERR_INVALID_ADDRESS) \
	expr(WFS_ERR_INVALID_APP_HANDLE) \
	expr(WFS_ERR_INVALID_BUFFER) \
	expr(WFS_ERR_INVALID_CATEGORY) \
	expr(WFS_ERR_INVALID_COMMAND) \
	expr(WFS_ERR_INVALID_EVENT_CLASS) \
	expr(WFS_ERR_INVALID_HSERVICE) \
	expr(WFS_ERR_INVALID_HPROVIDER) \
	expr(WFS_ERR_INVALID_HWND) \
	expr(WFS_ERR_INVALID_HWNDREG) \
	expr(WFS_ERR_INVALID_POINTER) \
	expr(WFS_ERR_INVALID_REQ_ID) \
	expr(WFS_ERR_INVALID_RESULT) \
	expr(WFS_ERR_INVALID_SERVPROV) \
	expr(WFS_ERR_INVALID_TIMER) \
	expr(WFS_ERR_INVALID_TRACELEVEL) \
	expr(WFS_ERR_LOCKED) \
	expr(WFS_ERR_NO_BLOCKING_CALL) \
	expr(WFS_ERR_NO_SERVPROV) \
	expr(WFS_ERR_NO_SUCH_THREAD) \
	expr(WFS_ERR_NO_TIMER) \
	expr(WFS_ERR_NOT_LOCKED) \
	expr(WFS_ERR_NOT_OK_TO_UNLOAD) \
	expr(WFS_ERR_NOT_STARTED) \
	expr(WFS_ERR_NOT_REGISTERED) \
	expr(WFS_ERR_OP_IN_PROGRESS) \
	expr(WFS_ERR_OUT_OF_MEMORY) \
	expr(WFS_ERR_SERVICE_NOT_FOUND) \
	expr(WFS_ERR_SPI_VER_TOO_HIGH) \
	expr(WFS_ERR_SPI_VER_TOO_LOW) \
	expr(WFS_ERR_SRVC_VER_TOO_HIGH) \
	expr(WFS_ERR_SRVC_VER_TOO_LOW) \
	expr(WFS_ERR_TIMEOUT) \
	expr(WFS_ERR_UNSUPP_CATEGORY) \
	expr(WFS_ERR_UNSUPP_COMMAND) \
	expr(WFS_ERR_VERSION_ERROR_IN_SRVC) \
	expr(WFS_ERR_INVALID_DATA) \
	expr(WFS_ERR_SOFTWARE_ERROR) \
	expr(WFS_ERR_CONNECTION_LOST) \
	expr(WFS_ERR_USER_ERROR) \
	expr(WFS_ERR_UNSUPP_DATA) \
	expr(WFS_ERR_SP_CRASH) \
	expr(WFS_ERR_PTR_FORMNOTFOUND) \
	expr(WFS_ERR_PTR_FIELDNOTFOUND) \
	expr(WFS_ERR_PTR_NOMEDIAPRESENT) \
	expr(WFS_ERR_PTR_READNOTSUPPORTED) \
	expr(WFS_ERR_PTR_FLUSHFAIL) \
	expr(WFS_ERR_PTR_MEDIAOVERFLOW) \
	expr(WFS_ERR_PTR_FIELDSPECFAILURE) \
	expr(WFS_ERR_PTR_FIELDERROR) \
	expr(WFS_ERR_PTR_MEDIANOTFOUND) \
	expr(WFS_ERR_PTR_EXTENTNOTSUPPORTED) \
	expr(WFS_ERR_PTR_MEDIAINVALID) \
	expr(WFS_ERR_PTR_FORMINVALID) \
	expr(WFS_ERR_PTR_FIELDINVALID) \
	expr(WFS_ERR_PTR_MEDIASKEWED) \
	expr(WFS_ERR_PTR_RETRACTBINFULL) \
	expr(WFS_ERR_PTR_STACKERFULL) \
	expr(WFS_ERR_PTR_PAGETURNFAIL) \
	expr(WFS_ERR_PTR_MEDIATURNFAIL) \
	expr(WFS_ERR_PTR_SHUTTERFAIL) \
	expr(WFS_ERR_PTR_MEDIAJAMMED) \
	expr(WFS_ERR_PTR_FILE_IO_ERROR) \
	expr(WFS_ERR_PTR_CHARSETDATA) \
	expr(WFS_ERR_PTR_PAPERJAMMED) \
	expr(WFS_ERR_PTR_PAPEROUT) \
	expr(WFS_ERR_PTR_INKOUT) \
	expr(WFS_ERR_PTR_TONEROUT) \
	expr(WFS_ERR_PTR_LAMPINOP) \
	expr(WFS_ERR_PTR_SOURCEINVALID) \
	expr(WFS_ERR_PTR_SEQUENCEINVALID) \
	expr(WFS_ERR_PTR_MEDIASIZE) \
	expr(WFS_ERR_CDM_INVALIDCURRENCY) \
	expr(WFS_ERR_CDM_INVALIDTELLERID) \
	expr(WFS_ERR_CDM_CASHUNITERROR) \
	expr(WFS_ERR_CDM_INVALIDDENOMINATION) \
	expr(WFS_ERR_CDM_INVALIDMIXNUMBER) \
	expr(WFS_ERR_CDM_NOCURRENCYMIX) \
	expr(WFS_ERR_CDM_NOTDISPENSABLE) \
	expr(WFS_ERR_CDM_TOOMANYITEMS) \
	expr(WFS_ERR_CDM_UNSUPPOSITION) \
	expr(WFS_ERR_CDM_SAFEDOOROPEN) \
	expr(WFS_ERR_CDM_SHUTTERNOTOPEN) \
	expr(WFS_ERR_CDM_SHUTTEROPEN) \
	expr(WFS_ERR_CDM_SHUTTERCLOSED) \
	expr(WFS_ERR_CDM_INVALIDCASHUNIT) \
	expr(WFS_ERR_CDM_NOITEMS) \
	expr(WFS_ERR_CDM_EXCHANGEACTIVE) \
	expr(WFS_ERR_CDM_NOEXCHANGEACTIVE) \
	expr(WFS_ERR_CDM_SHUTTERNOTCLOSED) \
	expr(WFS_ERR_CDM_PRERRORNOITEMS) \
	expr(WFS_ERR_CDM_PRERRORITEMS) \
	expr(WFS_ERR_CDM_PRERRORUNKNOWN) \
	expr(WFS_ERR_CDM_ITEMSTAKEN) \
	expr(WFS_ERR_CDM_INVALIDMIXTABLE) \
	expr(WFS_ERR_CDM_OUTPUTPOS_NOT_EMPTY) \
	expr(WFS_ERR_CDM_INVALIDRETRACTPOSITION) \
	expr(WFS_ERR_CDM_NOTRETRACTAREA) \
	expr(WFS_ERR_CDM_NOCASHBOXPRESENT) \
	expr(WFS_ERR_CDM_AMOUNTNOTINMIXTABLE) \
	expr(WFS_ERR_CDM_ITEMSNOTTAKEN) \
	expr(WFS_ERR_CDM_ITEMSLEFT) \
	expr(WFS_ERR_IDC_MEDIAJAM) \
	expr(WFS_ERR_IDC_NOMEDIA) \
	expr(WFS_ERR_IDC_MEDIARETAINED) \
	expr(WFS_ERR_IDC_RETAINBINFULL) \
	expr(WFS_ERR_IDC_INVALIDDATA) \
	expr(WFS_ERR_IDC_INVALIDMEDIA) \
	expr(WFS_ERR_IDC_FORMNOTFOUND) \
	expr(WFS_ERR_IDC_FORMINVALID) \
	expr(WFS_ERR_IDC_DATASYNTAX) \
	expr(WFS_ERR_IDC_SHUTTERFAIL) \
	expr(WFS_ERR_IDC_SECURITYFAIL) \
	expr(WFS_ERR_IDC_PROTOCOLNOTSUPP) \
	expr(WFS_ERR_IDC_ATRNOTOBTAINED) \
	expr(WFS_ERR_IDC_INVALIDKEY) \
	expr(WFS_ERR_IDC_WRITE_METHOD) \
	expr(WFS_ERR_IDC_CHIPPOWERNOTSUPP) \
	expr(WFS_ERR_IDC_CARDTOOSHORT) \
	expr(WFS_ERR_IDC_CARDTOOLONG) \

DNICODE(XfsErrorCode);

//##############################################################################
// GetXfsMessageName GetXfsMessageId 
//##############################################################################
#define ListXfsMessage(expr) \
	expr(WFS_OPEN_COMPLETE) \
	expr(WFS_CLOSE_COMPLETE) \
	expr(WFS_LOCK_COMPLETE) \
	expr(WFS_UNLOCK_COMPLETE) \
	expr(WFS_REGISTER_COMPLETE) \
	expr(WFS_DEREGISTER_COMPLETE) \
	expr(WFS_GETINFO_COMPLETE) \
	expr(WFS_EXECUTE_COMPLETE) \
	expr(WFS_EXECUTE_EVENT) \
	expr(WFS_SERVICE_EVENT) \
	expr(WFS_USER_EVENT) \
	expr(WFS_SYSTEM_EVENT) \
	expr(WFS_TIMER_EVENT) \

DNICODE(XfsMessage);

//##############################################################################
// GetXfsEventClassName GetXfsEventClassId 
//##############################################################################
#define ListXfsEventClass(expr) \
	expr(SERVICE_EVENTS) \
	expr(USER_EVENTS) \
	expr(SYSTEM_EVENTS) \
	expr(EXECUTE_EVENTS) \

DBWNICODE(XfsEventClass);

//##############################################################################
// GetXfsSysEventName GetXfsSysEventId 
//##############################################################################
#define ListXfsSysEvent(expr) \
	expr(WFS_SYSE_UNDELIVERABLE_MSG) \
	expr(WFS_SYSE_HARDWARE_ERROR) \
	expr(WFS_SYSE_VERSION_ERROR) \
	expr(WFS_SYSE_DEVICE_STATUS) \
	expr(WFS_SYSE_APP_DISCONNECT) \
	expr(WFS_SYSE_SOFTWARE_ERROR) \
	expr(WFS_SYSE_USER_ERROR) \
	expr(WFS_SYSE_LOCK_REQUESTED) \

DNICODE(XfsSysEvent);

//##############################################################################
// GetXfsTraceLevelName GetXfsTraceLevelId 
//##############################################################################
#define ListXfsTraceLevel(expr) \
	expr(WFS_TRACE_API) \
	expr(WFS_TRACE_ALL_API) \
	expr(WFS_TRACE_SPI) \
	expr(WFS_TRACE_ALL_SPI) \
	expr(WFS_TRACE_MGR) \

DBWNICODE(XfsTraceLevel);

//##############################################################################
// GetXfsErrorActionName GetXfsErrorActionId 
//##############################################################################
#define ListXfsErrorAction(expr) \
	expr(WFS_ERR_ACT_NOACTION) \
	expr(WFS_ERR_ACT_RESET) \
	expr(WFS_ERR_ACT_SWERROR) \
	expr(WFS_ERR_ACT_CONFIG) \
	expr(WFS_ERR_ACT_HWCLEAR) \
	expr(WFS_ERR_ACT_HWMAINT) \
	expr(WFS_ERR_ACT_SUSPEND) \

DBWNICODE(XfsErrorAction);

//##############################################################################
// GetXfsServiceClassName GetXfsServiceClassId 
//##############################################################################
#define ListXfsServiceClass(expr) \
	expr(WFS_SERVICE_CLASS_PTR) \
	expr(WFS_SERVICE_CLASS_CDM) \
	expr(WFS_SERVICE_CLASS_IDC) \

DNICODE(XfsServiceClass);

//##############################################################################
// GetXfsClassVersionName GetXfsClassVersionId 
//##############################################################################
#define ListXfsClassVersion(expr) \
	expr(WFS_SERVICE_CLASS_VERSION_PTR) \
	expr(WFS_SERVICE_CLASS_VERSION_CDM) \
	expr(WFS_SERVICE_CLASS_VERSION_IDC) \

DNICODE(XfsClassVersion);

//##############################################################################
// GetXfsInfoCmdName GetXfsInfoCmdId 
//##############################################################################
#define ListXfsInfoCmd(expr) \
	expr(WFS_INF_PTR_STATUS) \
	expr(WFS_INF_PTR_CAPABILITIES) \
	expr(WFS_INF_PTR_FORM_LIST) \
	expr(WFS_INF_PTR_MEDIA_LIST) \
	expr(WFS_INF_PTR_QUERY_FORM) \
	expr(WFS_INF_PTR_QUERY_MEDIA) \
	expr(WFS_INF_PTR_QUERY_FIELD) \
	expr(WFS_INF_CDM_STATUS) \
	expr(WFS_INF_CDM_CAPABILITIES) \
	expr(WFS_INF_CDM_CASH_UNIT_INFO) \
	expr(WFS_INF_CDM_TELLER_INFO) \
	expr(WFS_INF_CDM_CURRENCY_EXP) \
	expr(WFS_INF_CDM_MIX_TYPES) \
	expr(WFS_INF_CDM_MIX_TABLE) \
	expr(WFS_INF_CDM_PRESENT_STATUS) \
	expr(WFS_INF_IDC_STATUS) \
	expr(WFS_INF_IDC_CAPABILITIES) \
	expr(WFS_INF_IDC_FORM_LIST) \
	expr(WFS_INF_IDC_QUERY_FORM) \

DNICODE(XfsInfoCmd);

//##############################################################################
// GetXfsExecuteCmdName GetXfsExecuteCmdId 
//##############################################################################
#define ListXfsExecuteCmd(expr) \
	expr(WFS_CMD_PTR_CONTROL_MEDIA) \
	expr(WFS_CMD_PTR_PRINT_FORM) \
	expr(WFS_CMD_PTR_READ_FORM) \
	expr(WFS_CMD_PTR_RAW_DATA) \
	expr(WFS_CMD_PTR_MEDIA_EXTENTS) \
	expr(WFS_CMD_PTR_RESET_COUNT) \
	expr(WFS_CMD_PTR_READ_IMAGE) \
	expr(WFS_CMD_PTR_RESET) \
	expr(WFS_CMD_PTR_RETRACT_MEDIA) \
	expr(WFS_CMD_PTR_DISPENSE_PAPER) \
	expr(WFS_CMD_CDM_DENOMINATE) \
	expr(WFS_CMD_CDM_DISPENSE) \
	expr(WFS_CMD_CDM_PRESENT) \
	expr(WFS_CMD_CDM_REJECT) \
	expr(WFS_CMD_CDM_RETRACT) \
	expr(WFS_CMD_CDM_OPEN_SHUTTER) \
	expr(WFS_CMD_CDM_CLOSE_SHUTTER) \
	expr(WFS_CMD_CDM_SET_TELLER_INFO) \
	expr(WFS_CMD_CDM_SET_CASH_UNIT_INFO) \
	expr(WFS_CMD_CDM_START_EXCHANGE) \
	expr(WFS_CMD_CDM_END_EXCHANGE) \
	expr(WFS_CMD_CDM_OPEN_SAFE_DOOR) \
	expr(WFS_CMD_CDM_CALIBRATE_CASH_UNIT) \
	expr(WFS_CMD_CDM_SET_MIX_TABLE) \
	expr(WFS_CMD_CDM_RESET) \
	expr(WFS_CMD_CDM_TEST_CASH_UNITS) \
	expr(WFS_CMD_CDM_COUNT) \
	expr(WFS_CMD_IDC_READ_TRACK) \
	expr(WFS_CMD_IDC_WRITE_TRACK) \
	expr(WFS_CMD_IDC_EJECT_CARD) \
	expr(WFS_CMD_IDC_RETAIN_CARD) \
	expr(WFS_CMD_IDC_RESET_COUNT) \
	expr(WFS_CMD_IDC_SETKEY) \
	expr(WFS_CMD_IDC_READ_RAW_DATA) \
	expr(WFS_CMD_IDC_WRITE_RAW_DATA) \
	expr(WFS_CMD_IDC_CHIP_IO) \
	expr(WFS_CMD_IDC_RESET) \
	expr(WFS_CMD_IDC_CHIP_POWER) \
	expr(WFS_CMD_IDC_PARSE_DATA) \

DNICODE(XfsExecuteCmd);

//##############################################################################
// GetXfsEventName GetXfsEventId 
//##############################################################################
#define ListXfsEvent(expr) \
	expr(WFS_EXEE_PTR_NOMEDIA) \
	expr(WFS_EXEE_PTR_MEDIAINSERTED) \
	expr(WFS_EXEE_PTR_FIELDERROR) \
	expr(WFS_EXEE_PTR_FIELDWARNING) \
	expr(WFS_USRE_PTR_RETRACTBINTHRESHOLD) \
	expr(WFS_SRVE_PTR_MEDIATAKEN) \
	expr(WFS_USRE_PTR_PAPERTHRESHOLD) \
	expr(WFS_USRE_PTR_TONERTHRESHOLD) \
	expr(WFS_SRVE_PTR_MEDIAINSERTED) \
	expr(WFS_USRE_PTR_LAMPTHRESHOLD) \
	expr(WFS_USRE_PTR_INKTHRESHOLD) \
	expr(WFS_SRVE_PTR_MEDIADETECTED) \
	expr(WFS_SRVE_CDM_SAFEDOOROPEN) \
	expr(WFS_SRVE_CDM_SAFEDOORCLOSED) \
	expr(WFS_USRE_CDM_CASHUNITTHRESHOLD) \
	expr(WFS_SRVE_CDM_CASHUNITINFOCHANGED) \
	expr(WFS_SRVE_CDM_TELLERINFOCHANGED) \
	expr(WFS_EXEE_CDM_DELAYEDDISPENSE) \
	expr(WFS_EXEE_CDM_STARTDISPENSE) \
	expr(WFS_EXEE_CDM_CASHUNITERROR) \
	expr(WFS_SRVE_CDM_ITEMSTAKEN) \
	expr(WFS_EXEE_CDM_PARTIALDISPENSE) \
	expr(WFS_EXEE_CDM_SUBDISPENSEOK) \
	expr(WFS_SRVE_CDM_ITEMSPRESENTED) \
	expr(WFS_SRVE_CDM_COUNTS_CHANGED) \
	expr(WFS_EXEE_CDM_INCOMPLETEDISPENSE) \
	expr(WFS_EXEE_CDM_NOTEERROR) \
	expr(WFS_EXEE_CDM_MEDIADETECTED) \
	expr(WFS_SRVE_CDM_MEDIADETECTED) \
	expr(WFS_EXEE_IDC_INVALIDTRACKDATA) \
	expr(WFS_EXEE_IDC_MEDIAINSERTED) \
	expr(WFS_SRVE_IDC_MEDIAREMOVED) \
	expr(WFS_SRVE_IDC_CARDACTION) \
	expr(WFS_USRE_IDC_RETAINBINTHRESHOLD) \
	expr(WFS_EXEE_IDC_INVALIDMEDIA) \
	expr(WFS_EXEE_IDC_MEDIARETAINED) \
	expr(WFS_SRVE_IDC_MEDIADETECTED) \

DNICODE(XfsEvent);

//##############################################################################
// GetXfsPtrDevStatusName GetXfsPtrDevStatusId 
//##############################################################################
#define ListXfsPtrDevStatus(expr) \
	expr(WFS_PTR_DEVONLINE) \
	expr(WFS_PTR_DEVOFFLINE) \
	expr(WFS_PTR_DEVPOWEROFF) \
	expr(WFS_PTR_DEVNODEVICE) \
	expr(WFS_PTR_DEVHWERROR) \
	expr(WFS_PTR_DEVUSERERROR) \
	expr(WFS_PTR_DEVBUSY) \

DNICODE(XfsPtrDevStatus);

//##############################################################################
// GetXfsPtrMediaPostionName GetXfsPtrMediaPostionId 
//##############################################################################
#define ListXfsPtrMediaPostion(expr) \
	expr(WFS_PTR_MEDIAPRESENT) \
	expr(WFS_PTR_MEDIANOTPRESENT) \
	expr(WFS_PTR_MEDIAJAMMED) \
	expr(WFS_PTR_MEDIANOTSUPP) \
	expr(WFS_PTR_MEDIAUNKNOWN) \
	expr(WFS_PTR_MEDIAENTERING) \
	expr(WFS_PTR_MEDIARETRACTED) \

DNICODE(XfsPtrMediaPostion);

//##############################################################################
// GetXfsPtrPaperSupplyName GetXfsPtrPaperSupplyId 
//##############################################################################
#define ListXfsPtrPaperSupply(expr) \
	expr(WFS_PTR_SUPPLYUPPER) \
	expr(WFS_PTR_SUPPLYLOWER) \
	expr(WFS_PTR_SUPPLYEXTERNAL) \
	expr(WFS_PTR_SUPPLYAUX) \
	expr(WFS_PTR_SUPPLYAUX2) \
	expr(WFS_PTR_SUPPLYPARK) \

DNICODE(XfsPtrPaperSupply);

//##############################################################################
// GetXfsPtrPaperStatusName GetXfsPtrPaperStatusId 
//##############################################################################
#define ListXfsPtrPaperStatus(expr) \
	expr(WFS_PTR_PAPERFULL) \
	expr(WFS_PTR_PAPERLOW) \
	expr(WFS_PTR_PAPEROUT) \
	expr(WFS_PTR_PAPERNOTSUPP) \
	expr(WFS_PTR_PAPERUNKNOWN) \
	expr(WFS_PTR_PAPERJAMMED) \

DNICODE(XfsPtrPaperStatus);

//##############################################################################
// GetXfsPtrTonerSatusName GetXfsPtrTonerSatusId 
//##############################################################################
#define ListXfsPtrTonerSatus(expr) \
	expr(WFS_PTR_TONERFULL) \
	expr(WFS_PTR_TONERLOW) \
	expr(WFS_PTR_TONEROUT) \
	expr(WFS_PTR_TONERNOTSUPP) \
	expr(WFS_PTR_TONERUNKNOWN) \

DNICODE(XfsPtrTonerSatus);

//##############################################################################
// GetXfsPtrInkStatusName GetXfsPtrInkStatusId 
//##############################################################################
#define ListXfsPtrInkStatus(expr) \
	expr(WFS_PTR_INKFULL) \
	expr(WFS_PTR_INKLOW) \
	expr(WFS_PTR_INKOUT) \
	expr(WFS_PTR_INKNOTSUPP) \
	expr(WFS_PTR_INKUNKNOWN) \

DNICODE(XfsPtrInkStatus);

//##############################################################################
// GetXfsPtrLampStatusName GetXfsPtrLampStatusId 
//##############################################################################
#define ListXfsPtrLampStatus(expr) \
	expr(WFS_PTR_LAMPOK) \
	expr(WFS_PTR_LAMPFADING) \
	expr(WFS_PTR_LAMPINOP) \
	expr(WFS_PTR_LAMPNOTSUPP) \
	expr(WFS_PTR_LAMPUNKNOWN) \

DNICODE(XfsPtrLampStatus);

//##############################################################################
// GetXfsPtrRetractBinStatusName GetXfsPtrRetractBinStatusId 
//##############################################################################
#define ListXfsPtrRetractBinStatus(expr) \
	expr(WFS_PTR_RETRACTBINOK) \
	expr(WFS_PTR_RETRACTBINFULL) \
	expr(WFS_PTR_RETRACTNOTSUPP) \
	expr(WFS_PTR_RETRACTUNKNOWN) \
	expr(WFS_PTR_RETRACTBINHIGH) \

DNICODE(XfsPtrRetractBinStatus);

//##############################################################################
// GetXfsPtrTypeName GetXfsPtrTypeId 
//##############################################################################
#define ListXfsPtrType(expr) \
	expr(WFS_PTR_TYPERECEIPT) \
	expr(WFS_PTR_TYPEPASSBOOK) \
	expr(WFS_PTR_TYPEJOURNAL) \
	expr(WFS_PTR_TYPEDOCUMENT) \
	expr(WFS_PTR_TYPESCANNER) \

DBWNICODE(XfsPtrType);

//##############################################################################
// GetXfsPtrResolutionName GetXfsPtrResolutionId 
//##############################################################################
#define ListXfsPtrResolution(expr) \
	expr(WFS_PTR_RESLOW) \
	expr(WFS_PTR_RESMED) \
	expr(WFS_PTR_RESHIGH) \
	expr(WFS_PTR_RESVERYHIGH) \

DBWNICODE(XfsPtrResolution);

//##############################################################################
// GetXfsPtrFormReadCapName GetXfsPtrFormReadCapId 
//##############################################################################
#define ListXfsPtrFormReadCap(expr) \
	expr(WFS_PTR_READOCR) \
	expr(WFS_PTR_READMICR) \
	expr(WFS_PTR_READMSF) \
	expr(WFS_PTR_READBARCODE) \
	expr(WFS_PTR_READPAGEMARK) \
	expr(WFS_PTR_READIMAGE) \
	expr(WFS_PTR_READEMPTYLINE) \

DBWNICODE(XfsPtrFormReadCap);

//##############################################################################
// GetXfsPtrFormWriteCapName GetXfsPtrFormWriteCapId 
//##############################################################################
#define ListXfsPtrFormWriteCap(expr) \
	expr(WFS_PTR_WRITETEXT) \
	expr(WFS_PTR_WRITEGRAPHICS) \
	expr(WFS_PTR_WRITEOCR) \
	expr(WFS_PTR_WRITEMICR) \
	expr(WFS_PTR_WRITEMSF) \
	expr(WFS_PTR_WRITEBARCODE) \
	expr(WFS_PTR_WRITESTAMP) \

DBWNICODE(XfsPtrFormWriteCap);

//##############################################################################
// GetXfsPtrExtentName GetXfsPtrExtentId 
//##############################################################################
#define ListXfsPtrExtent(expr) \
	expr(WFS_PTR_EXTHORIZONTAL) \
	expr(WFS_PTR_EXTVERTICAL) \

DBWNICODE(XfsPtrExtent);

//##############################################################################
// GetXfsPtrControlName GetXfsPtrControlId 
//##############################################################################
#define ListXfsPtrControl(expr) \
	expr(WFS_PTR_CTRLEJECT) \
	expr(WFS_PTR_CTRLPERFORATE) \
	expr(WFS_PTR_CTRLCUT) \
	expr(WFS_PTR_CTRLSKIP) \
	expr(WFS_PTR_CTRLFLUSH) \
	expr(WFS_PTR_CTRLRETRACT) \
	expr(WFS_PTR_CTRLSTACK) \
	expr(WFS_PTR_CTRLPARTIALCUT) \
	expr(WFS_PTR_CTRLALARM) \
	expr(WFS_PTR_CTRLATPFORWARD) \
	expr(WFS_PTR_CTRLATPBACKWARD) \
	expr(WFS_PTR_CTRLTURNMEDIA) \
	expr(WFS_PTR_CTRLSTAMP) \
	expr(WFS_PTR_CTRLPARK) \

DBWNICODE(XfsPtrControl);

//##############################################################################
// GetXfsPtrPaperSourceName GetXfsPtrPaperSourceId 
//##############################################################################
#define ListXfsPtrPaperSource(expr) \
	expr(WFS_PTR_PAPERANY) \
	expr(WFS_PTR_PAPERUPPER) \
	expr(WFS_PTR_PAPERLOWER) \
	expr(WFS_PTR_PAPEREXTERNAL) \
	expr(WFS_PTR_PAPERAUX) \
	expr(WFS_PTR_PAPERAUX2) \
	expr(WFS_PTR_PAPERPARK) \

DBWNICODE(XfsPtrPaperSource);

//##############################################################################
// GetXfsPtrImageTypeName GetXfsPtrImageTypeId 
//##############################################################################
#define ListXfsPtrImageType(expr) \
	expr(WFS_PTR_IMAGETIF) \
	expr(WFS_PTR_IMAGEWMF) \
	expr(WFS_PTR_IMAGEBMP) \

DBWNICODE(XfsPtrImageType);

//##############################################################################
// GetXfsPtrColorFormatName GetXfsPtrColorFormatId 
//##############################################################################
#define ListXfsPtrColorFormat(expr) \
	expr(WFS_PTR_IMAGECOLORBINARY) \
	expr(WFS_PTR_IMAGECOLORGRAYSCALE) \
	expr(WFS_PTR_IMAGECOLORFULL) \

DBWNICODE(XfsPtrColorFormat);

//##############################################################################
// GetXfsPtrCodelineFormatName GetXfsPtrCodelineFormatId 
//##############################################################################
#define ListXfsPtrCodelineFormat(expr) \
	expr(WFS_PTR_CODELINECMC7) \
	expr(WFS_PTR_CODELINEE13B) \
	expr(WFS_PTR_CODELINEOCR) \

DBWNICODE(XfsPtrCodelineFormat);

//##############################################################################
// GetXfsPtrImageSourceName GetXfsPtrImageSourceId 
//##############################################################################
#define ListXfsPtrImageSource(expr) \
	expr(WFS_PTR_IMAGEFRONT) \
	expr(WFS_PTR_IMAGEBACK) \
	expr(WFS_PTR_CODELINE) \

DBWNICODE(XfsPtrImageSource);

//##############################################################################
// GetXfsPtrCharSupportName GetXfsPtrCharSupportId 
//##############################################################################
#define ListXfsPtrCharSupport(expr) \
	expr(WFS_PTR_ASCII) \
	expr(WFS_PTR_UNICODE) \

DBWNICODE(XfsPtrCharSupport);

//##############################################################################
// GetXfsPtrBaseName GetXfsPtrBaseId 
//##############################################################################
#define ListXfsPtrBase(expr) \
	expr(WFS_FRM_INCH) \
	expr(WFS_FRM_MM) \
	expr(WFS_FRM_ROWCOLUMN) \

DNICODE(XfsPtrBase);

//##############################################################################
// GetXfsPtrAlignmentName GetXfsPtrAlignmentId 
//##############################################################################
#define ListXfsPtrAlignment(expr) \
	expr(WFS_FRM_TOPLEFT) \
	expr(WFS_FRM_TOPRIGHT) \
	expr(WFS_FRM_BOTTOMLEFT) \
	expr(WFS_FRM_BOTTOMRIGHT) \

DNICODE(XfsPtrAlignment);

//##############################################################################
// GetXfsPtrName GetXfsPtrId 
//##############################################################################
#define ListXfsPtr(expr) \
	expr(WFS_FRM_PORTRAIT) \
	expr(WFS_FRM_LANDSCAPE) \

DNICODE(XfsPtr);

//##############################################################################
// GetXfsPtrMediaTypeName GetXfsPtrMediaTypeId 
//##############################################################################
#define ListXfsPtrMediaType(expr) \
	expr(WFS_FRM_MEDIAGENERIC) \
	expr(WFS_FRM_MEDIAPASSBOOK) \
	expr(WFS_FRM_MEDIAMULTIPART) \

DNICODE(XfsPtrMediaType);

//##############################################################################
// GetXfsPtrMediaFoldTypeName GetXfsPtrMediaFoldTypeId 
//##############################################################################
#define ListXfsPtrMediaFoldType(expr) \
	expr(WFS_FRM_FOLDNONE) \
	expr(WFS_FRM_FOLDHORIZONTAL) \
	expr(WFS_FRM_FOLDVERTICAL) \

DNICODE(XfsPtrMediaFoldType);

//##############################################################################
// GetXfsPtrFormFieldTypeName GetXfsPtrFormFieldTypeId 
//##############################################################################
#define ListXfsPtrFormFieldType(expr) \
	expr(WFS_FRM_FIELDTEXT) \
	expr(WFS_FRM_FIELDMICR) \
	expr(WFS_FRM_FIELDOCR) \
	expr(WFS_FRM_FIELDMSF) \
	expr(WFS_FRM_FIELDBARCODE) \
	expr(WFS_FRM_FIELDGRAPHIC) \
	expr(WFS_FRM_FIELDPAGEMARK) \

DNICODE(XfsPtrFormFieldType);

//##############################################################################
// GetXfsPtrFormFieldClassName GetXfsPtrFormFieldClassId 
//##############################################################################
#define ListXfsPtrFormFieldClass(expr) \
	expr(WFS_FRM_CLASSSTATIC) \
	expr(WFS_FRM_CLASSOPTIONAL) \
	expr(WFS_FRM_CLASSREQUIRED) \

DNICODE(XfsPtrFormFieldClass);

//##############################################################################
// GetXfsPtrFormFieldAccessName GetXfsPtrFormFieldAccessId 
//##############################################################################
#define ListXfsPtrFormFieldAccess(expr) \
	expr(WFS_FRM_ACCESSREAD) \
	expr(WFS_FRM_ACCESSWRITE) \

DBWNICODE(XfsPtrFormFieldAccess);

//##############################################################################
// GetXfsPtrFormFieldOverflowName GetXfsPtrFormFieldOverflowId 
//##############################################################################
#define ListXfsPtrFormFieldOverflow(expr) \
	expr(WFS_FRM_OVFTERMINATE) \
	expr(WFS_FRM_OVFTRUNCATE) \
	expr(WFS_FRM_OVFBESTFIT) \
	expr(WFS_FRM_OVFOVERWRITE) \
	expr(WFS_FRM_OVFWORDWRAP) \

DNICODE(XfsPtrFormFieldOverflow);

//##############################################################################
// GetXfsPtrFormFieldFailureName GetXfsPtrFormFieldFailureId 
//##############################################################################
#define ListXfsPtrFormFieldFailure(expr) \
	expr(WFS_PTR_FIELDREQUIRED) \
	expr(WFS_PTR_FIELDSTATICOVWR) \
	expr(WFS_PTR_FIELDOVERFLOW) \
	expr(WFS_PTR_FIELDNOTFOUND) \
	expr(WFS_PTR_FIELDNOTREAD) \
	expr(WFS_PTR_FIELDNOTWRITE) \
	expr(WFS_PTR_FIELDHWERROR) \
	expr(WFS_PTR_FIELDTYPENOTSUPPORTED) \
	expr(WFS_PTR_FIELDGRAPHIC) \
	expr(WFS_PTR_CHARSETFORM) \

DNICODE(XfsPtrFormFieldFailure);

//##############################################################################
// GetXfsPtrFormAlignmentName GetXfsPtrFormAlignmentId 
//##############################################################################
#define ListXfsPtrFormAlignment(expr) \
	expr(WFS_PTR_ALNUSEFORMDEFN) \
	expr(WFS_PTR_ALNTOPLEFT) \
	expr(WFS_PTR_ALNTOPRIGHT) \
	expr(WFS_PTR_ALNBOTTOMLEFT) \
	expr(WFS_PTR_ALNBOTTOMRIGHT) \

DNICODE(XfsPtrFormAlignment);

//##############################################################################
// GetXfsPtrFormOffsetName GetXfsPtrFormOffsetId 
//##############################################################################
#define ListXfsPtrFormOffset(expr) \
	expr(WFS_PTR_OFFSETUSEFORMDEFN) \

DNICODE(XfsPtrFormOffset);

//##############################################################################
// GetXfsPtrFormInputDataName GetXfsPtrFormInputDataId 
//##############################################################################
#define ListXfsPtrFormInputData(expr) \
	expr(WFS_PTR_NOINPUTDATA) \
	expr(WFS_PTR_INPUTDATA) \

DNICODE(XfsPtrFormInputData);

//##############################################################################
// GetXfsPtrImageStatusName GetXfsPtrImageStatusId 
//##############################################################################
#define ListXfsPtrImageStatus(expr) \
	expr(WFS_PTR_DATAOK) \
	expr(WFS_PTR_DATASRCNOTSUPP) \
	expr(WFS_PTR_DATASRCMISSING) \

DNICODE(XfsPtrImageStatus);

//##############################################################################
// GetXfsCdmDevStatusName GetXfsCdmDevStatusId 
//##############################################################################
#define ListXfsCdmDevStatus(expr) \
	expr(WFS_CDM_DEVONLINE) \
	expr(WFS_CDM_DEVOFFLINE) \
	expr(WFS_CDM_DEVPOWEROFF) \
	expr(WFS_CDM_DEVNODEVICE) \
	expr(WFS_CDM_DEVHWERROR) \
	expr(WFS_CDM_DEVUSERERROR) \
	expr(WFS_CDM_DEVBUSY) \

DNICODE(XfsCdmDevStatus);

//##############################################################################
// GetXfsCdmSafeDoorName GetXfsCdmSafeDoorId 
//##############################################################################
#define ListXfsCdmSafeDoor(expr) \
	expr(WFS_CDM_DOORNOTSUPPORTED) \
	expr(WFS_CDM_DOOROPEN) \
	expr(WFS_CDM_DOORCLOSED) \
	expr(WFS_CDM_DOORUNKNOWN) \

DNICODE(XfsCdmSafeDoor);

//##############################################################################
// GetXfsCdmDispensorStatusName GetXfsCdmDispensorStatusId 
//##############################################################################
#define ListXfsCdmDispensorStatus(expr) \
	expr(WFS_CDM_DISPOK) \
	expr(WFS_CDM_DISPCUSTATE) \
	expr(WFS_CDM_DISPCUSTOP) \
	expr(WFS_CDM_DISPCUUNKNOWN) \

DNICODE(XfsCdmDispensorStatus);

//##############################################################################
// GetXfsCdmIntermediateStackerName GetXfsCdmIntermediateStackerId 
//##############################################################################
#define ListXfsCdmIntermediateStacker(expr) \
	expr(WFS_CDM_ISEMPTY) \
	expr(WFS_CDM_ISNOTEMPTY) \
	expr(WFS_CDM_ISNOTEMPTYCUST) \
	expr(WFS_CDM_ISNOTEMPTYUNK) \
	expr(WFS_CDM_ISUNKNOWN) \
	expr(WFS_CDM_ISNOTSUPPORTED) \

DNICODE(XfsCdmIntermediateStacker);

//##############################################################################
// GetXfsCdmShutterStatusName GetXfsCdmShutterStatusId 
//##############################################################################
#define ListXfsCdmShutterStatus(expr) \
	expr(WFS_CDM_SHTCLOSED) \
	expr(WFS_CDM_SHTOPEN) \
	expr(WFS_CDM_SHTJAMMED) \
	expr(WFS_CDM_SHTUNKNOWN) \
	expr(WFS_CDM_SHTNOTSUPPORTED) \

DNICODE(XfsCdmShutterStatus);

//##############################################################################
// GetXfsCdmPositionStatusName GetXfsCdmPositionStatusId 
//##############################################################################
#define ListXfsCdmPositionStatus(expr) \
	expr(WFS_CDM_PSEMPTY) \
	expr(WFS_CDM_PSNOTEMPTY) \
	expr(WFS_CDM_PSUNKNOWN) \
	expr(WFS_CDM_PSNOTSUPPORTED) \

DNICODE(XfsCdmPositionStatus);

//##############################################################################
// GetXfsCdmTransportStateName GetXfsCdmTransportStateId 
//##############################################################################
#define ListXfsCdmTransportState(expr) \
	expr(WFS_CDM_TPOK) \
	expr(WFS_CDM_TPINOP) \
	expr(WFS_CDM_TPUNKNOWN) \
	expr(WFS_CDM_TPNOTSUPPORTED) \

DNICODE(XfsCdmTransportState);

//##############################################################################
// GetXfsCdmTransportStatusName GetXfsCdmTransportStatusId 
//##############################################################################
#define ListXfsCdmTransportStatus(expr) \
	expr(WFS_CDM_TPSTATEMPTY) \
	expr(WFS_CDM_TPSTATNOTEMPTY) \
	expr(WFS_CDM_TPSTATNOTEMPTYCUST) \
	expr(WFS_CDM_TPSTATNOTEMPTY_UNK) \
	expr(WFS_CDM_TPSTATNOTSUPPORTED) \

DNICODE(XfsCdmTransportStatus);

//##############################################################################
// GetXfsCdmTypeName GetXfsCdmTypeId 
//##############################################################################
#define ListXfsCdmType(expr) \
	expr(WFS_CDM_TELLERBILL) \
	expr(WFS_CDM_SELFSERVICEBILL) \
	expr(WFS_CDM_TELLERCOIN) \
	expr(WFS_CDM_SELFSERVICECOIN) \

DNICODE(XfsCdmType);

//##############################################################################
// GetXfsCdmRetractAreaName GetXfsCdmRetractAreaId 
//##############################################################################
#define ListXfsCdmRetractArea(expr) \
	expr(WFS_CDM_RA_RETRACT) \
	expr(WFS_CDM_RA_TRANSPORT) \
	expr(WFS_CDM_RA_STACKER) \
	expr(WFS_CDM_RA_REJECT) \
	expr(WFS_CDM_RA_NOTSUPP) \

DNICODE(XfsCdmRetractArea);

//##############################################################################
// GetXfsCdmRetractStackerActionsName GetXfsCdmRetractStackerActionsId 
//##############################################################################
#define ListXfsCdmRetractStackerActions(expr) \
	expr(WFS_CDM_PRESENT) \
	expr(WFS_CDM_RETRACT) \
	expr(WFS_CDM_REJECT) \
	expr(WFS_CDM_NOTSUPP) \

DNICODE(XfsCdmRetractStackerActions);

//##############################################################################
// GetXfsCdmMoveItemsName GetXfsCdmMoveItemsId 
//##############################################################################
#define ListXfsCdmMoveItems(expr) \
	expr(WFS_CDM_FROMCU) \
	expr(WFS_CDM_TOCU) \
	expr(WFS_CDM_TOTRANSPORT) \

DNICODE(XfsCdmMoveItems);

//##############################################################################
// GetXfsCdmCashUnitTypeName GetXfsCdmCashUnitTypeId 
//##############################################################################
#define ListXfsCdmCashUnitType(expr) \
	expr(WFS_CDM_TYPENA) \
	expr(WFS_CDM_TYPEREJECTCASSETTE) \
	expr(WFS_CDM_TYPEBILLCASSETTE) \
	expr(WFS_CDM_TYPECOINCYLINDER) \
	expr(WFS_CDM_TYPECOINDISPENSER) \
	expr(WFS_CDM_TYPERETRACTCASSETTE) \
	expr(WFS_CDM_TYPECOUPON) \
	expr(WFS_CDM_TYPEDOCUMENT) \
	expr(WFS_CDM_TYPEREPCONTAINER) \
	expr(WFS_CDM_TYPERECYCLING) \

DNICODE(XfsCdmCashUnitType);

//##############################################################################
// GetXfsCdmCashUnitStatusName GetXfsCdmCashUnitStatusId 
//##############################################################################
#define ListXfsCdmCashUnitStatus(expr) \
	expr(WFS_CDM_STATCUOK) \
	expr(WFS_CDM_STATCUFULL) \
	expr(WFS_CDM_STATCUHIGH) \
	expr(WFS_CDM_STATCULOW) \
	expr(WFS_CDM_STATCUEMPTY) \
	expr(WFS_CDM_STATCUINOP) \
	expr(WFS_CDM_STATCUMISSING) \
	expr(WFS_CDM_STATCUNOVAL) \
	expr(WFS_CDM_STATCUNOREF) \
	expr(WFS_CDM_STATCUMANIP) \

DNICODE(XfsCdmCashUnitStatus);

//##############################################################################
// GetXfsCdmMixTypeName GetXfsCdmMixTypeId 
//##############################################################################
#define ListXfsCdmMixType(expr) \
	expr(WFS_CDM_MIXALGORITHM) \
	expr(WFS_CDM_MIXTABLE) \

DNICODE(XfsCdmMixType);

//##############################################################################
// GetXfsCdmMixNumberName GetXfsCdmMixNumberId 
//##############################################################################
#define ListXfsCdmMixNumber(expr) \
	expr(WFS_CDM_INDIVIDUAL) \

DNICODE(XfsCdmMixNumber);

//##############################################################################
// GetXfsCdmMixSubTypeName GetXfsCdmMixSubTypeId 
//##############################################################################
#define ListXfsCdmMixSubType(expr) \
	expr(WFS_CDM_MIX_MINIMUM_NUMBER_OF_BILLS) \
	expr(WFS_CDM_MIX_EQUAL_EMPTYING_OF_CASH_UNITS) \
	expr(WFS_CDM_MIX_MAXIMUM_NUMBER_OF_CASH_UNITS) \

DNICODE(XfsCdmMixSubType);

//##############################################################################
// GetXfsCdmPresentStatusName GetXfsCdmPresentStatusId 
//##############################################################################
#define ListXfsCdmPresentStatus(expr) \
	expr(WFS_CDM_PRESENTED) \
	expr(WFS_CDM_NOTPRESENTED) \
	expr(WFS_CDM_UNKNOWN) \

DNICODE(XfsCdmPresentStatus);

//##############################################################################
// GetXfsCdmDispensePositionName GetXfsCdmDispensePositionId 
//##############################################################################
#define ListXfsCdmDispensePosition(expr) \
	expr(WFS_CDM_POSNULL) \
	expr(WFS_CDM_POSLEFT) \
	expr(WFS_CDM_POSRIGHT) \
	expr(WFS_CDM_POSCENTER) \
	expr(WFS_CDM_POSTOP) \
	expr(WFS_CDM_POSBOTTOM) \
	expr(WFS_CDM_POSREJECT) \
	expr(WFS_CDM_POSFRONT) \
	expr(WFS_CDM_POSREAR) \

DBWNICODE(XfsCdmDispensePosition);

//##############################################################################
// GetXfsCdmInputPositionName GetXfsCdmInputPositionId 
//##############################################################################
#define ListXfsCdmInputPosition(expr) \
	expr(WFS_CDM_POSINLEFT) \
	expr(WFS_CDM_POSINRIGHT) \
	expr(WFS_CDM_POSINCENTER) \
	expr(WFS_CDM_POSINTOP) \
	expr(WFS_CDM_POSINBOTTOM) \
	expr(WFS_CDM_POSINFRONT) \
	expr(WFS_CDM_POSINREAR) \

DBWNICODE(XfsCdmInputPosition);

//##############################################################################
// GetXfsCdmExchangeTypeName GetXfsCdmExchangeTypeId 
//##############################################################################
#define ListXfsCdmExchangeType(expr) \
	expr(WFS_CDM_EXBYHAND) \
	expr(WFS_CDM_EXTOCASSETTES) \

DBWNICODE(XfsCdmExchangeType);

//##############################################################################
// GetXfsCdmTellerUpdateActionName GetXfsCdmTellerUpdateActionId 
//##############################################################################
#define ListXfsCdmTellerUpdateAction(expr) \
	expr(WFS_CDM_CREATE_TELLER) \
	expr(WFS_CDM_MODIFY_TELLER) \
	expr(WFS_CDM_DELETE_TELLER) \

DBWNICODE(XfsCdmTellerUpdateAction);

//##############################################################################
// GetXfsCdmMcuErrorsName GetXfsCdmMcuErrorsId 
//##############################################################################
#define ListXfsCdmMcuErrors(expr) \
	expr(WFS_CDM_CASHUNITEMPTY) \
	expr(WFS_CDM_CASHUNITERROR) \
	expr(WFS_CDM_CASHUNITFULL) \
	expr(WFS_CDM_CASHUNITLOCKED) \
	expr(WFS_CDM_CASHUNITINVALID) \
	expr(WFS_CDM_CASHUNITCONFIG) \

DBWNICODE(XfsCdmMcuErrors);

//##############################################################################
// GetXfsCdmNotesErrorName GetXfsCdmNotesErrorId 
//##############################################################################
#define ListXfsCdmNotesError(expr) \
	expr(WFS_CDM_DOUBLENOTEDETECTED) \
	expr(WFS_CDM_LONGNOTEDETECTED) \
	expr(WFS_CDM_SKEWEDNOTE) \
	expr(WFS_CDM_INCORRECTCOUNT) \
	expr(WFS_CDM_NOTESTOOCLOSE) \

DBWNICODE(XfsCdmNotesError);

//##############################################################################
// GetXfsIdcDevStatusName GetXfsIdcDevStatusId 
//##############################################################################
#define ListXfsIdcDevStatus(expr) \
	expr(WFS_IDC_DEVONLINE) \
	expr(WFS_IDC_DEVOFFLINE) \
	expr(WFS_IDC_DEVPOWEROFF) \
	expr(WFS_IDC_DEVNODEVICE) \
	expr(WFS_IDC_DEVHWERROR) \
	expr(WFS_IDC_DEVUSERERROR) \
	expr(WFS_IDC_DEVBUSY) \

DNICODE(XfsIdcDevStatus);

//##############################################################################
// GetXfsIdcMediaPositionName GetXfsIdcMediaPositionId 
//##############################################################################
#define ListXfsIdcMediaPosition(expr) \
	expr(WFS_IDC_MEDIAPRESENT) \
	expr(WFS_IDC_MEDIANOTPRESENT) \
	expr(WFS_IDC_MEDIAJAMMED) \
	expr(WFS_IDC_MEDIANOTSUPP) \
	expr(WFS_IDC_MEDIAUNKNOWN) \
	expr(WFS_IDC_MEDIAENTERING) \
	expr(WFS_IDC_MEDIALATCHED) \

DNICODE(XfsIdcMediaPosition);

//##############################################################################
// GetXfsIdcRetainBinName GetXfsIdcRetainBinId 
//##############################################################################
#define ListXfsIdcRetainBin(expr) \
	expr(WFS_IDC_RETAINBINOK) \
	expr(WFS_IDC_RETAINNOTSUPP) \
	expr(WFS_IDC_RETAINBINFULL) \
	expr(WFS_IDC_RETAINBINHIGH) \

DNICODE(XfsIdcRetainBin);

//##############################################################################
// GetXfsIdcSecurityName GetXfsIdcSecurityId 
//##############################################################################
#define ListXfsIdcSecurity(expr) \
	expr(WFS_IDC_SECNOTSUPP) \
	expr(WFS_IDC_SECNOTREADY) \
	expr(WFS_IDC_SECOPEN) \

DNICODE(XfsIdcSecurity);

//##############################################################################
// GetXfsIdcChipPowerName GetXfsIdcChipPowerId 
//##############################################################################
#define ListXfsIdcChipPower(expr) \
	expr(WFS_IDC_CHIPONLINE) \
	expr(WFS_IDC_CHIPPOWEREDOFF) \
	expr(WFS_IDC_CHIPBUSY) \
	expr(WFS_IDC_CHIPNODEVICE) \
	expr(WFS_IDC_CHIPHWERROR) \
	expr(WFS_IDC_CHIPNOCARD) \
	expr(WFS_IDC_CHIPNOTSUPP) \
	expr(WFS_IDC_CHIPUNKNOWN) \
	expr(WFS_IDC_CHIPPOWERCOLD) \
	expr(WFS_IDC_CHIPPOWERWARM) \
	expr(WFS_IDC_CHIPPOWEROFF) \

DNICODE(XfsIdcChipPower);

//##############################################################################
// GetXfsIdcTypeName GetXfsIdcTypeId 
//##############################################################################
#define ListXfsIdcType(expr) \
	expr(WFS_IDC_TYPEMOTOR) \
	expr(WFS_IDC_TYPESWIPE) \
	expr(WFS_IDC_TYPEDIP) \
	expr(WFS_IDC_TYPECONTACTLESS) \
	expr(WFS_IDC_TYPELATCHEDDIP) \
	expr(WFS_IDC_TYPEPERMANENT) \

DNICODE(XfsIdcType);

//##############################################################################
// GetXfsIdcTrackName GetXfsIdcTrackId 
//##############################################################################
#define ListXfsIdcTrack(expr) \
	expr(WFS_IDC_NOTSUPP) \
	expr(WFS_IDC_TRACK1) \
	expr(WFS_IDC_TRACK2) \
	expr(WFS_IDC_TRACK3) \

DBWNICODE(XfsIdcTrack);

//##############################################################################
// GetXfsIdcDataSourceName GetXfsIdcDataSourceId 
//##############################################################################
#define ListXfsIdcDataSource(expr) \
	expr(WFS_IDC_CHIP) \
	expr(WFS_IDC_SECURITY) \
	expr(WFS_IDC_FLUXINACTIVE) \
	expr(WFS_IDC_TRACK_WM) \

DBWNICODE(XfsIdcDataSource);

//##############################################################################
// GetXfsIdcChipProtocolName GetXfsIdcChipProtocolId 
//##############################################################################
#define ListXfsIdcChipProtocol(expr) \
	expr(WFS_IDC_CHIPT0) \
	expr(WFS_IDC_CHIPT1) \
	expr(WFS_IDC_CHIPT2) \
	expr(WFS_IDC_CHIPT3) \
	expr(WFS_IDC_CHIPT4) \
	expr(WFS_IDC_CHIPT5) \
	expr(WFS_IDC_CHIPT6) \
	expr(WFS_IDC_CHIPT7) \
	expr(WFS_IDC_CHIPT8) \
	expr(WFS_IDC_CHIPT9) \
	expr(WFS_IDC_CHIPT10) \
	expr(WFS_IDC_CHIPT11) \
	expr(WFS_IDC_CHIPT12) \
	expr(WFS_IDC_CHIPT13) \
	expr(WFS_IDC_CHIPT14) \
	expr(WFS_IDC_CHIPT15) \

DBWNICODE(XfsIdcChipProtocol);

//##############################################################################
// GetXfsIdcSecTypeName GetXfsIdcSecTypeId 
//##############################################################################
#define ListXfsIdcSecType(expr) \
	expr(WFS_IDC_SECNOTSUPP) \
	expr(WFS_IDC_SECMMBOX) \
	expr(WFS_IDC_SECCIM86) \

DNICODE(XfsIdcSecType);

//##############################################################################
// GetXfsIdcPowerOptionName GetXfsIdcPowerOptionId 
//##############################################################################
#define ListXfsIdcPowerOption(expr) \
	expr(WFS_IDC_NOACTION) \
	expr(WFS_IDC_EJECT) \
	expr(WFS_IDC_RETAIN) \
	expr(WFS_IDC_EJECTTHENRETAIN) \
	expr(WFS_IDC_READPOSITION) \

DNICODE(XfsIdcPowerOption);

//##############################################################################
// GetXfsIdcWriteMethodName GetXfsIdcWriteMethodId 
//##############################################################################
#define ListXfsIdcWriteMethod(expr) \
	expr(WFS_IDC_UNKNOWN) \
	expr(WFS_IDC_LOCO) \
	expr(WFS_IDC_HICO) \
	expr(WFS_IDC_AUTO) \

DBWNICODE(XfsIdcWriteMethod);

//##############################################################################
// GetXfsIdcFormActionName GetXfsIdcFormActionId 
//##############################################################################
#define ListXfsIdcFormAction(expr) \
	expr(WFS_IDC_ACTIONREAD) \
	expr(WFS_IDC_ACTIONWRITE) \

DNICODE(XfsIdcFormAction);

//##############################################################################
// GetXfsIdcCardTrackStatusName GetXfsIdcCardTrackStatusId 
//##############################################################################
#define ListXfsIdcCardTrackStatus(expr) \
	expr(WFS_IDC_DATAOK) \
	expr(WFS_IDC_DATAMISSING) \
	expr(WFS_IDC_DATAINVALID) \
	expr(WFS_IDC_DATATOOLONG) \
	expr(WFS_IDC_DATATOOSHORT) \
	expr(WFS_IDC_DATASRCNOTSUPP) \
	expr(WFS_IDC_DATASRCMISSING) \

DNICODE(XfsIdcCardTrackStatus);

//##############################################################################
// GetXfsIdcCardActionName GetXfsIdcCardActionId 
//##############################################################################
#define ListXfsIdcCardAction(expr) \
	expr(WFS_IDC_CARDRETAINED) \
	expr(WFS_IDC_CARDEJECTED) \
	expr(WFS_IDC_CARDREADPOSITION) \
	expr(WFS_IDC_CARDJAMMED) \

DNICODE(XfsIdcCardAction);

//##############################################################################
// GetXfsIdcSecLevelName GetXfsIdcSecLevelId 
//##############################################################################
#define ListXfsIdcSecLevel(expr) \
	expr(WFS_IDC_SEC_READLEVEL1) \
	expr(WFS_IDC_SEC_READLEVEL2) \
	expr(WFS_IDC_SEC_READLEVEL3) \
	expr(WFS_IDC_SEC_READLEVEL4) \
	expr(WFS_IDC_SEC_READLEVEL5) \
	expr(WFS_IDC_SEC_BADREADLEVEL) \
	expr(WFS_IDC_SEC_NODATA) \
	expr(WFS_IDC_SEC_DATAINVAL) \
	expr(WFS_IDC_SEC_HWERROR) \
	expr(WFS_IDC_SEC_NOINIT) \

DNICODE(XfsIdcSecLevel);

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSRESULT* p) {
	json j;
	if(!p) return j;

	j["requestID"] = (p->RequestID);
	j["service"] = (p->hService);
	j["timestamp"] = XSJ_SystemTime2String(p->tsTimestamp);
	j["result"] = GetXfsErrorCodeName((p->hResult));

	return j;
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSVERSION* p) {
	json j;
	if(!p) return j;

	j["version"] = (p->wVersion);
	j["lowVersion"] = (p->wLowVersion);
	j["highVersion"] = (p->wHighVersion);
	j["description"] = (p->szDescription);
	j["systemStatus"] = (p->szSystemStatus);

	return j;
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSDEVSTATUS* p) {
	json j;
	if(!p) return j;

	j["physicalName"] = XSJ_Stringify(p->lpszPhysicalName);
	j["workstationName"] = XSJ_Stringify(p->lpszWorkstationName);
	j["state"] = GetXfsDevStatusName((p->dwState));

	return j;
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSUNDEVMSG* p) {
	json j;
	if(!p) return j;

	j["logicalName"] = XSJ_Stringify(p->lpszLogicalName);
	j["workstationName"] = XSJ_Stringify(p->lpszWorkstationName);
	j["appID"] = XSJ_Stringify(p->lpszAppID);
	j["size"] = (p->dwSize);
	j["description"] = XSJ_Stringify(p->lpbDescription);
	j["msg"] = (p->dwMsg);
	j["wfsResult"] = XSJTranslate<WFSRESULT>((p->lpWFSResult));

	return j;
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSAPPDISC* p) {
	json j;
	if(!p) return j;

	j["logicalName"] = XSJ_Stringify(p->lpszLogicalName);
	j["workstationName"] = XSJ_Stringify(p->lpszWorkstationName);
	j["appID"] = XSJ_Stringify(p->lpszAppID);

	return j;
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSHWERROR* p) {
	json j;
	if(!p) return j;

	j["logicalName"] = XSJ_Stringify(p->lpszLogicalName);
	j["physicalName"] = XSJ_Stringify(p->lpszPhysicalName);
	j["workstationName"] = XSJ_Stringify(p->lpszWorkstationName);
	j["appID"] = XSJ_Stringify(p->lpszAppID);
	j["action"] = GetXfsErrorActionName((p->dwAction));
	j["size"] = (p->dwSize);
	j["description"] = XSJ_Stringify(p->lpbDescription);

	return j;
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSVRSNERROR* p) {
	json j;
	if(!p) return j;

	j["logicalName"] = XSJ_Stringify(p->lpszLogicalName);
	j["workstationName"] = XSJ_Stringify(p->lpszWorkstationName);
	j["appID"] = XSJ_Stringify(p->lpszAppID);
	j["size"] = (p->dwSize);
	j["description"] = XSJ_Stringify(p->lpbDescription);
	j["wfsVersion"] = XSJTranslate<WFSVERSION>((p->lpWFSVersion));

	return j;
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRRETRACTBINS* p) {
	json j;
	if(!p) return j;

	j["retractBin"] = GetXfsPtrRetractBinStatusName((p->wRetractBin));
	j["retractCount"] = (p->usRetractCount);

	return j;
}

//##############################################################################
// WFS_INF_PTR_STATUS, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRSTATUS* p) {
	json j;
	if(!p) return j;

	j["device"] = GetXfsPtrDevStatusName((p->fwDevice));
	j["media"] = GetXfsPtrMediaPostionName((p->fwMedia));
	j["paper"] = XSJ_ListArray(p->fwPaper, GetXfsPtrPaperStatusName, GetXfsPtrPaperSupplyName, WFS_PTR_SUPPLYSIZE);
	j["toner"] = GetXfsPtrTonerSatusName((p->fwToner));
	j["ink"] = GetXfsPtrInkStatusName((p->fwInk));
	j["lamp"] = GetXfsPtrLampStatusName((p->fwLamp));
	j["retractBins"] = XSJ_ListNullTerminatedPointers((const WFSPTRRETRACTBINS **)p->lppRetractBins, XSJTranslate<WFSPTRRETRACTBINS>);
	j["mediaOnStacker"] = (p->usMediaOnStacker);
	j["extra"] = XSJ_Stringify(p->lpszExtra);

	return j;
}

//##############################################################################
// WFS_INF_PTR_CAPABILITIES, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRCAPS* p) {
	json j;
	if(!p) return j;

	j["class"] = GetXfsServiceClassName((p->wClass));
	j["type"] = GetXfsPtrTypeName((p->fwType));
	j["compound"] = (p->bCompound);
	j["resolution"] = GetXfsPtrResolutionName((p->wResolution));
	j["readForm"] = GetXfsPtrFormReadCapName((p->fwReadForm));
	j["writeForm"] = GetXfsPtrFormWriteCapName((p->fwWriteForm));
	j["extents"] = GetXfsPtrExtentName((p->fwExtents));
	j["control"] = GetXfsPtrControlName((p->fwControl));
	j["maxMediaOnStacker"] = (p->usMaxMediaOnStacker);
	j["acceptMedia"] = (p->bAcceptMedia);
	j["multiPage"] = (p->bMultiPage);
	j["paperSources"] = GetXfsPtrPaperSourceName((p->fwPaperSources));
	j["mediaTaken"] = (p->bMediaTaken);
	j["retractBins"] = (p->usRetractBins);
	j["maxRetract"] = (p->lpusMaxRetract);
	j["imageType"] = GetXfsPtrImageTypeName((p->fwImageType));
	j["frontImageColorFormat"] = GetXfsPtrColorFormatName((p->fwFrontImageColorFormat));
	j["backImageColorFormat"] = GetXfsPtrColorFormatName((p->fwBackImageColorFormat));
	j["codelineFormat"] = GetXfsPtrCodelineFormatName((p->fwCodelineFormat));
	j["imageSource"] = GetXfsPtrImageSourceName((p->fwImageSource));
	j["charSupport"] = GetXfsPtrCharSupportName((p->fwCharSupport));
	j["dispensePaper"] = (p->bDispensePaper);
	j["extra"] = XSJ_Stringify(p->lpszExtra);

	return j;
}

//##############################################################################
// WFS_INF_PTR_QUERY_FORM, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSFRMHEADER* p) {
	json j;
	if(!p) return j;

	j["formName"] = XSJ_Stringify(p->lpszFormName);
	j["base"] = GetXfsPtrBaseName((p->wBase));
	j["unitX"] = (p->wUnitX);
	j["unitY"] = (p->wUnitY);
	j["width"] = (p->wWidth);
	j["height"] = (p->wHeight);
	j["alignment"] = GetXfsPtrAlignmentName((p->wAlignment));
	j["orientation"] = GetXfsPtrName((p->wOrientation));
	j["offsetX"] = (p->wOffsetX);
	j["offsetY"] = (p->wOffsetY);
	j["versionMajor"] = (p->wVersionMajor);
	j["versionMinor"] = (p->wVersionMinor);
	j["userPrompt"] = XSJ_Stringify(p->lpszUserPrompt);
	j["charSupport"] = GetXfsPtrCharSupportName((p->fwCharSupport));
	j["fields"] = XSJ_List2Strings(p->lpszFields);

	return j;
}

//##############################################################################
// WFS_INF_PTR_QUERY_MEDIA, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSFRMMEDIA* p) {
	json j;
	if(!p) return j;

	j["mediaType"] = GetXfsPtrMediaTypeName((p->fwMediaType));
	j["base"] = GetXfsPtrBaseName((p->wBase));
	j["unitX"] = (p->wUnitX);
	j["unitY"] = (p->wUnitY);
	j["sizeWidth"] = (p->wSizeWidth);
	j["sizeHeight"] = (p->wSizeHeight);
	j["pageCount"] = (p->wPageCount);
	j["lineCount"] = (p->wLineCount);
	j["printAreaX"] = (p->wPrintAreaX);
	j["printAreaY"] = (p->wPrintAreaY);
	j["printAreaWidth"] = (p->wPrintAreaWidth);
	j["printAreaHeight"] = (p->wPrintAreaHeight);
	j["restrictedAreaX"] = (p->wRestrictedAreaX);
	j["restrictedAreaY"] = (p->wRestrictedAreaY);
	j["restrictedAreaWidth"] = (p->wRestrictedAreaWidth);
	j["restrictedAreaHeight"] = (p->wRestrictedAreaHeight);
	j["stagger"] = (p->wStagger);
	j["foldType"] = (p->wFoldType);
	j["paperSources"] = GetXfsPtrPaperSourceName((p->wPaperSources));

	return j;
}

//##############################################################################
// WFS_INF_PTR_QUERY_FIELD, in:true, out:false
//##############################################################################
template <>
inline WFSPTRQUERYFIELD* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTRQUERYFIELD>();

	if (j.find("formName") != j.end() && !j["formName"].is_null())
		p->lpszFormName = a->Get(j["formName"].get<std::string>());

	if (j.find("fieldName") != j.end() && !j["fieldName"].is_null())
		p->lpszFieldName = a->Get(j["fieldName"].get<std::string>());


	return (WFSPTRQUERYFIELD*)a->Get();
}

//##############################################################################
// WFS_INF_PTR_QUERY_FIELD, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSFRMFIELD* p) {
	json j;
	if(!p) return j;

	j["fieldName"] = XSJ_Stringify(p->lpszFieldName);
	j["indexCount"] = (p->wIndexCount);
	j["type"] = GetXfsPtrFormFieldTypeName((p->fwType));
	j["class"] = GetXfsPtrFormFieldClassName((p->fwClass));
	j["access"] = GetXfsPtrFormFieldAccessName((p->fwAccess));
	j["overflow"] = GetXfsPtrFormFieldOverflowName((p->fwOverflow));
	j["initialValue"] = XSJ_Stringify(p->lpszInitialValue);
	j["uNICODEInitialValue"] = XSJ_Stringify(p->lpszUNICODEInitialValue);
	j["format"] = XSJ_Stringify(p->lpszFormat);
	j["uNICODEFormat"] = XSJ_Stringify(p->lpszUNICODEFormat);

	return j;
}

//##############################################################################
// WFS_CMD_PTR_PRINT_FORM, in:true, out:false
//##############################################################################
template <>
inline WFSPTRPRINTFORM* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTRPRINTFORM>();

	if (j.find("formName") != j.end() && !j["formName"].is_null())
		p->lpszFormName = a->Get(j["formName"].get<std::string>());

	if (j.find("mediaName") != j.end() && !j["mediaName"].is_null())
		p->lpszMediaName = a->Get(j["mediaName"].get<std::string>());

	if (j.find("fields") != j.end() && !j["fields"].is_null())
		p->lpszFields = XSJDecodePtrFields(j["fields"], a);

	if (j.find("mediaControl") != j.end() && !j["mediaControl"].is_null())
		p->dwMediaControl = (DWORD)GetXfsPtrControlId(j["mediaControl"]);

	if (j.find("paperSource") != j.end() && !j["paperSource"].is_null())
		p->wPaperSource = (WORD)GetXfsPtrPaperSourceId(j["paperSource"]);

	if (j.find("alignment") != j.end() && !j["alignment"].is_null())
		p->wAlignment = (WORD)GetXfsPtrFormAlignmentId(j["alignment"]);

	if (j.find("offsetX") != j.end() && !j["offsetX"].is_null())
		p->wOffsetX = (WORD)j["offsetX"];

	if (j.find("offsetY") != j.end() && !j["offsetY"].is_null())
		p->wOffsetY = (WORD)j["offsetY"];

	if (j.find("resolution") != j.end() && !j["resolution"].is_null())
		p->wResolution = (WORD)GetXfsPtrResolutionId(j["resolution"]);


	return (WFSPTRPRINTFORM*)a->Get();
}

//##############################################################################
// WFS_CMD_PTR_READ_FORM, in:true, out:false
//##############################################################################
template <>
inline WFSPTRREADFORM* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTRREADFORM>();

	if (j.find("formName") != j.end() && !j["formName"].is_null())
		p->lpszFormName = a->Get(j["formName"].get<std::string>());

	if (j.find("fieldNames") != j.end() && !j["fieldNames"].is_null())
		p->lpszFieldNames = a->Get(j["fieldNames"].get<std::string>());

	if (j.find("mediaName") != j.end() && !j["mediaName"].is_null())
		p->lpszMediaName = a->Get(j["mediaName"].get<std::string>());

	if (j.find("mediaControl") != j.end() && !j["mediaControl"].is_null())
		p->dwMediaControl = (DWORD)GetXfsPtrControlId(j["mediaControl"]);


	return (WFSPTRREADFORM*)a->Get();
}

//##############################################################################
// WFS_CMD_PTR_READ_FORM, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRREADFORMOUT* p) {
	json j;
	if(!p) return j;

	j["fields"] = XSJ_Stringify(p->lpszFields);
	j["uNICODEFields"] = XSJ_Stringify(p->lpszUNICODEFields);

	return j;
}

//##############################################################################
// WFS_CMD_PTR_RAW_DATA, in:true, out:false
//##############################################################################
template <>
inline WFSPTRRAWDATA* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTRRAWDATA>();

	if (j.find("inputData") != j.end() && !j["inputData"].is_null())
		p->wInputData = (WORD)GetXfsPtrFormInputDataId(j["inputData"]);

	if (j.find("size") != j.end() && !j["size"].is_null())
		p->ulSize = (ULONG)j["size"];

	if (j.find("data") != j.end() && !j["data"].is_null())
		p->lpbData = (LPBYTE)a->Get(j["data"].get<std::string>());


	return (WFSPTRRAWDATA*)a->Get();
}

//##############################################################################
// WFS_CMD_PTR_RAW_DATA, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRRAWDATAIN* p) {
	json j;
	if(!p) return j;

	j["size"] = (p->ulSize);
	j["data"] = XSJ_Stringify(p->lpbData);

	return j;
}

//##############################################################################
// WFS_CMD_PTR_MEDIA_EXTENTS, in:true, out:false
//##############################################################################
template <>
inline WFSPTRMEDIAUNIT* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTRMEDIAUNIT>();

	if (j.find("base") != j.end() && !j["base"].is_null())
		p->wBase = (WORD)GetXfsPtrBaseId(j["base"]);

	if (j.find("unitX") != j.end() && !j["unitX"].is_null())
		p->wUnitX = (WORD)j["unitX"];

	if (j.find("unitY") != j.end() && !j["unitY"].is_null())
		p->wUnitY = (WORD)j["unitY"];


	return (WFSPTRMEDIAUNIT*)a->Get();
}

//##############################################################################
// WFS_CMD_PTR_MEDIA_EXTENTS, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRMEDIAEXT* p) {
	json j;
	if(!p) return j;

	j["sizeX"] = (p->ulSizeX);
	j["sizeY"] = (p->ulSizeY);

	return j;
}

//##############################################################################
// WFS_CMD_PTR_READ_IMAGE, in:true, out:false
//##############################################################################
template <>
inline WFSPTRIMAGEREQUEST* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTRIMAGEREQUEST>();

	if (j.find("frontImageType") != j.end() && !j["frontImageType"].is_null())
		p->wFrontImageType = (WORD)j["frontImageType"];

	if (j.find("backImageType") != j.end() && !j["backImageType"].is_null())
		p->wBackImageType = (WORD)j["backImageType"];

	if (j.find("frontImageColorFormat") != j.end() && !j["frontImageColorFormat"].is_null())
		p->wFrontImageColorFormat = (WORD)GetXfsPtrColorFormatId(j["frontImageColorFormat"]);

	if (j.find("backImageColorFormat") != j.end() && !j["backImageColorFormat"].is_null())
		p->wBackImageColorFormat = (WORD)GetXfsPtrColorFormatId(j["backImageColorFormat"]);

	if (j.find("codelineFormat") != j.end() && !j["codelineFormat"].is_null())
		p->wCodelineFormat = (WORD)GetXfsPtrCodelineFormatId(j["codelineFormat"]);

	if (j.find("imageSource") != j.end() && !j["imageSource"].is_null())
		p->fwImageSource = (WORD)GetXfsPtrImageSourceId(j["imageSource"]);

	if (j.find("frontImageFile") != j.end() && !j["frontImageFile"].is_null())
		p->lpszFrontImageFile = a->Get(j["frontImageFile"].get<std::string>());

	if (j.find("backImageFile") != j.end() && !j["backImageFile"].is_null())
		p->lpszBackImageFile = a->Get(j["backImageFile"].get<std::string>());


	return (WFSPTRIMAGEREQUEST*)a->Get();
}

//##############################################################################
// WFS_CMD_PTR_READ_IMAGE, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRIMAGE* p) {
	json j;
	if(!p) return j;

	j["imageSource"] = GetXfsPtrImageSourceName((p->wImageSource));
	j["status"] = GetXfsPtrImageStatusName((p->wStatus));
	j["dataLength"] = (p->ulDataLength);
	j["data"] = XSJ_Stringify(p->lpbData);

	return j;
}

//##############################################################################
// WFS_CMD_PTR_RESET, in:true, out:false
//##############################################################################
template <>
inline WFSPTRRESET* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTRRESET>();

	if (j.find("mediaControl") != j.end() && !j["mediaControl"].is_null())
		p->dwMediaControl = (DWORD)GetXfsPtrControlId(j["mediaControl"]);

	if (j.find("retractBinNumber") != j.end() && !j["retractBinNumber"].is_null())
		p->usRetractBinNumber = (USHORT)j["retractBinNumber"];


	return (WFSPTRRESET*)a->Get();
}

//##############################################################################
// WFS_EXEE_PTR_FIELDERROR, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRFIELDFAIL* p) {
	json j;
	if(!p) return j;

	j["formName"] = XSJ_Stringify(p->lpszFormName);
	j["fieldName"] = XSJ_Stringify(p->lpszFieldName);
	j["failure"] = GetXfsPtrFormFieldFailureName((p->wFailure));

	return j;
}

//##############################################################################
// WFS_USRE_PTR_RETRACTBINTHRESHOLD, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRBINTHRESHOLD* p) {
	json j;
	if(!p) return j;

	j["binNumber"] = (p->usBinNumber);
	j["retractBin"] = GetXfsPtrRetractBinStatusName((p->wRetractBin));

	return j;
}

//##############################################################################
// WFS_USRE_PTR_PAPERTHRESHOLD, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRPAPERTHRESHOLD* p) {
	json j;
	if(!p) return j;

	j["paperSource"] = GetXfsPtrPaperSourceName((p->wPaperSource));
	j["paperThreshold"] = GetXfsPtrPaperStatusName((p->wPaperThreshold));

	return j;
}

//##############################################################################
// WFS_SRVE_PTR_MEDIADETECTED, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRMEDIADETECTED* p) {
	json j;
	if(!p) return j;

	j["position"] = GetXfsPtrMediaPostionName((p->wPosition));
	j["retractBinNumber"] = (p->usRetractBinNumber);

	return j;
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMOUTPOS* p) {
	json j;
	if(!p) return j;

	j["position"] = GetXfsCdmDispensePositionName((p->fwPosition));
	j["shutter"] = GetXfsCdmShutterStatusName((p->fwShutter));
	j["positionStatus"] = GetXfsCdmPositionStatusName((p->fwPositionStatus));
	j["transport"] = GetXfsCdmTransportStateName((p->fwTransport));
	j["transportStatus"] = GetXfsCdmTransportStatusName((p->fwTransportStatus));

	return j;
}

//##############################################################################
// WFS_INF_CDM_STATUS, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMSTATUS* p) {
	json j;
	if(!p) return j;

	j["device"] = GetXfsCdmDevStatusName((p->fwDevice));
	j["safeDoor"] = GetXfsCdmSafeDoorName((p->fwSafeDoor));
	j["dispenser"] = GetXfsCdmDispensorStatusName((p->fwDispenser));
	j["intermediateStacker"] = GetXfsCdmIntermediateStackerName((p->fwIntermediateStacker));
	j["positions"] = XSJ_ListNullTerminatedPointers((const WFSCDMOUTPOS **)p->lppPositions, XSJTranslate<WFSCDMOUTPOS>);
	j["extra"] = XSJ_Stringify(p->lpszExtra);

	return j;
}

//##############################################################################
// WFS_INF_CDM_CAPABILITIES, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMCAPS* p) {
	json j;
	if(!p) return j;

	j["class"] = GetXfsServiceClassName((p->wClass));
	j["type"] = GetXfsCdmTypeName((p->fwType));
	j["maxDispenseItems"] = (p->wMaxDispenseItems);
	j["compound"] = (p->bCompound);
	j["shutter"] = (p->bShutter);
	j["shutterControl"] = (p->bShutterControl);
	j["retractAreas"] = GetXfsCdmRetractAreaName((p->fwRetractAreas));
	j["retractTransportActions"] = GetXfsCdmRetractStackerActionsName((p->fwRetractTransportActions));
	j["retractStackerActions"] = GetXfsCdmRetractStackerActionsName((p->fwRetractStackerActions));
	j["safeDoor"] = (p->bSafeDoor);
	j["cashBox"] = (p->bCashBox);
	j["intermediateStacker"] = (p->bIntermediateStacker);
	j["itemsTakenSensor"] = (p->bItemsTakenSensor);
	j["positions"] = GetXfsCdmDispensePositionName((p->fwPositions));
	j["moveItems"] = GetXfsCdmMoveItemsName((p->fwMoveItems));
	j["exchangeType"] = GetXfsCdmExchangeTypeName((p->fwExchangeType));
	j["extra"] = XSJ_Stringify(p->lpszExtra);

	return j;
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMPHCU* p) {
	json j;
	if(!p) return j;

	j["physicalPositionName"] = XSJ_Stringify(p->lpPhysicalPositionName);
	j["unitID"] = std::string(p->cUnitID, p->cUnitID + 5);
	j["initialCount"] = (p->ulInitialCount);
	j["count"] = (p->ulCount);
	j["rejectCount"] = (p->ulRejectCount);
	j["maximum"] = (p->ulMaximum);
	j["pStatus"] = GetXfsCdmCashUnitStatusName((p->usPStatus));
	j["hardwareSensor"] = (p->bHardwareSensor);

	return j;
}
//##############################################################################
//##############################################################################
template <>
inline WFSCDMPHCU* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMPHCU>();

	if (j.find("physicalPositionName") != j.end() && !j["physicalPositionName"].is_null())
		p->lpPhysicalPositionName = a->Get(j["physicalPositionName"].get<std::string>());

	if (j.find("unitID") != j.end() && !j["unitID"].is_null())
		std::strncpy(p->cUnitID, j["unitID"].get<std::string>().c_str(), 5);

	if (j.find("initialCount") != j.end() && !j["initialCount"].is_null())
		p->ulInitialCount = (ULONG)j["initialCount"];

	if (j.find("count") != j.end() && !j["count"].is_null())
		p->ulCount = (ULONG)j["count"];

	if (j.find("rejectCount") != j.end() && !j["rejectCount"].is_null())
		p->ulRejectCount = (ULONG)j["rejectCount"];

	if (j.find("maximum") != j.end() && !j["maximum"].is_null())
		p->ulMaximum = (ULONG)j["maximum"];

	if (j.find("pStatus") != j.end() && !j["pStatus"].is_null())
		p->usPStatus = (USHORT)GetXfsCdmCashUnitStatusId(j["pStatus"]);

	if (j.find("hardwareSensor") != j.end() && !j["hardwareSensor"].is_null())
		p->bHardwareSensor = (BOOL)j["hardwareSensor"];


	return (WFSCDMPHCU*)a->Get();
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMCASHUNIT* p) {
	json j;
	if(!p) return j;

	j["number"] = (p->usNumber);
	j["type"] = GetXfsCdmCashUnitTypeName((p->usType));
	j["cashUnitName"] = XSJ_Stringify(p->lpszCashUnitName);
	j["unitID"] = std::string(p->cUnitID, p->cUnitID + 5);
	j["currencyID"] = std::string(p->cCurrencyID, p->cCurrencyID + 3);
	j["values"] = (p->ulValues);
	j["initialCount"] = (p->ulInitialCount);
	j["count"] = (p->ulCount);
	j["rejectCount"] = (p->ulRejectCount);
	j["minimum"] = (p->ulMinimum);
	j["maximum"] = (p->ulMaximum);
	j["appLock"] = (p->bAppLock);
	j["status"] = GetXfsCdmCashUnitStatusName((p->usStatus));
	j["numPhysicalCUs"] = (p->usNumPhysicalCUs);
	j["physical"] = XSJ_ListNullTerminatedPointers((const WFSCDMPHCU **)p->lppPhysical, XSJTranslate<WFSCDMPHCU>);

	return j;
}
//##############################################################################
//##############################################################################
template <>
inline WFSCDMCASHUNIT* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMCASHUNIT>();

	if (j.find("number") != j.end() && !j["number"].is_null())
		p->usNumber = (USHORT)j["number"];

	if (j.find("type") != j.end() && !j["type"].is_null())
		p->usType = (USHORT)GetXfsCdmCashUnitTypeId(j["type"]);

	if (j.find("cashUnitName") != j.end() && !j["cashUnitName"].is_null())
		p->lpszCashUnitName = a->Get(j["cashUnitName"].get<std::string>());

	if (j.find("unitID") != j.end() && !j["unitID"].is_null())
		std::strncpy(p->cUnitID, j["unitID"].get<std::string>().c_str(), 5);

	if (j.find("currencyID") != j.end() && !j["currencyID"].is_null())
		std::strncpy(p->cCurrencyID, j["currencyID"].get<std::string>().c_str(), 3);

	if (j.find("values") != j.end() && !j["values"].is_null())
		p->ulValues = (ULONG)j["values"];

	if (j.find("initialCount") != j.end() && !j["initialCount"].is_null())
		p->ulInitialCount = (ULONG)j["initialCount"];

	if (j.find("count") != j.end() && !j["count"].is_null())
		p->ulCount = (ULONG)j["count"];

	if (j.find("rejectCount") != j.end() && !j["rejectCount"].is_null())
		p->ulRejectCount = (ULONG)j["rejectCount"];

	if (j.find("minimum") != j.end() && !j["minimum"].is_null())
		p->ulMinimum = (ULONG)j["minimum"];

	if (j.find("maximum") != j.end() && !j["maximum"].is_null())
		p->ulMaximum = (ULONG)j["maximum"];

	if (j.find("appLock") != j.end() && !j["appLock"].is_null())
		p->bAppLock = (BOOL)j["appLock"];

	if (j.find("status") != j.end() && !j["status"].is_null())
		p->usStatus = (USHORT)GetXfsCdmCashUnitStatusId(j["status"]);

	if (j.find("numPhysicalCUs") != j.end() && !j["numPhysicalCUs"].is_null())
		p->usNumPhysicalCUs = (USHORT)j["numPhysicalCUs"];

	if (j.find("physical") != j.end() && !j["physical"].is_null())
		if(j["physical"].is_array())
			p->lppPhysical = a->AllocateArrayPointersNT<WFSCDMPHCU>(j["physical"]);


	return (WFSCDMCASHUNIT*)a->Get();
}

//##############################################################################
// WFS_INF_CDM_CASH_UNIT_INFO, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMCUINFO* p) {
	json j;
	if(!p) return j;

	j["tellerID"] = (p->usTellerID);
	j["count"] = (p->usCount);
	j["list"] = XSJ_ListArray(p->lppList, XSJTranslate<WFSCDMCASHUNIT>, (std::string(*)(const int))nullptr, p->usCount);

	return j;
}

//##############################################################################
// WFS_CMD_CDM_SET_CASH_UNIT_INFO, in:true, out:false
//##############################################################################
template <>
inline WFSCDMCUINFO* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMCUINFO>();

	if (j.find("tellerID") != j.end() && !j["tellerID"].is_null())
		p->usTellerID = (USHORT)j["tellerID"];

	if (j.find("count") != j.end() && !j["count"].is_null())
		p->usCount = (USHORT)j["count"];

	if (j.find("list") != j.end() && !j["list"].is_null())
		if(j["list"].is_array())
			p->lppList = a->AllocateArrayPointers<WFSCDMCASHUNIT>(j["list"], p->usCount);


	return (WFSCDMCUINFO*)a->Get();
}

//##############################################################################
// WFS_INF_CDM_TELLER_INFO, in:true, out:false
//##############################################################################
template <>
inline WFSCDMTELLERINFO* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMTELLERINFO>();

	if (j.find("tellerID") != j.end() && !j["tellerID"].is_null())
		p->usTellerID = (USHORT)j["tellerID"];

	if (j.find("currencyID") != j.end() && !j["currencyID"].is_null())
		std::strncpy(p->cCurrencyID, j["currencyID"].get<std::string>().c_str(), 3);


	return (WFSCDMTELLERINFO*)a->Get();
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMTELLERTOTALS* p) {
	json j;
	if(!p) return j;

	j["currencyID"] = std::string(p->cCurrencyID, p->cCurrencyID + 3);
	j["itemsReceived"] = (p->ulItemsReceived);
	j["itemsDispensed"] = (p->ulItemsDispensed);
	j["coinsReceived"] = (p->ulCoinsReceived);
	j["coinsDispensed"] = (p->ulCoinsDispensed);
	j["cashBoxReceived"] = (p->ulCashBoxReceived);
	j["cashBoxDispensed"] = (p->ulCashBoxDispensed);

	return j;
}
//##############################################################################
//##############################################################################
template <>
inline WFSCDMTELLERTOTALS* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMTELLERTOTALS>();

	if (j.find("currencyID") != j.end() && !j["currencyID"].is_null())
		std::strncpy(p->cCurrencyID, j["currencyID"].get<std::string>().c_str(), 3);

	if (j.find("itemsReceived") != j.end() && !j["itemsReceived"].is_null())
		p->ulItemsReceived = (ULONG)j["itemsReceived"];

	if (j.find("itemsDispensed") != j.end() && !j["itemsDispensed"].is_null())
		p->ulItemsDispensed = (ULONG)j["itemsDispensed"];

	if (j.find("coinsReceived") != j.end() && !j["coinsReceived"].is_null())
		p->ulCoinsReceived = (ULONG)j["coinsReceived"];

	if (j.find("coinsDispensed") != j.end() && !j["coinsDispensed"].is_null())
		p->ulCoinsDispensed = (ULONG)j["coinsDispensed"];

	if (j.find("cashBoxReceived") != j.end() && !j["cashBoxReceived"].is_null())
		p->ulCashBoxReceived = (ULONG)j["cashBoxReceived"];

	if (j.find("cashBoxDispensed") != j.end() && !j["cashBoxDispensed"].is_null())
		p->ulCashBoxDispensed = (ULONG)j["cashBoxDispensed"];


	return (WFSCDMTELLERTOTALS*)a->Get();
}

//##############################################################################
// WFS_INF_CDM_TELLER_INFO, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMTELLERDETAILS* p) {
	json j;
	if(!p) return j;

	j["tellerID"] = (p->usTellerID);
	j["inputPosition"] = GetXfsCdmInputPositionName((p->ulInputPosition));
	j["outputPosition"] = GetXfsCdmDispensePositionName((p->fwOutputPosition));
	j["tellerTotals"] = XSJ_ListNullTerminatedPointers((const WFSCDMTELLERTOTALS **)p->lppTellerTotals, XSJTranslate<WFSCDMTELLERTOTALS>);

	return j;
}

//##############################################################################
//##############################################################################
template <>
inline WFSCDMTELLERDETAILS* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMTELLERDETAILS>();

	if (j.find("tellerID") != j.end() && !j["tellerID"].is_null())
		p->usTellerID = (USHORT)j["tellerID"];

	if (j.find("inputPosition") != j.end() && !j["inputPosition"].is_null())
		p->ulInputPosition = (ULONG)GetXfsCdmInputPositionId(j["inputPosition"]);

	if (j.find("outputPosition") != j.end() && !j["outputPosition"].is_null())
		p->fwOutputPosition = (WORD)GetXfsCdmDispensePositionId(j["outputPosition"]);

	if (j.find("tellerTotals") != j.end() && !j["tellerTotals"].is_null())
		if(j["tellerTotals"].is_array())
			p->lppTellerTotals = a->AllocateArrayPointersNT<WFSCDMTELLERTOTALS>(j["tellerTotals"]);


	return (WFSCDMTELLERDETAILS*)a->Get();
}

//##############################################################################
// WFS_INF_CDM_CURRENCY_EXP, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMCURRENCYEXP* p) {
	json j;
	if(!p) return j;

	j["currencyID"] = std::string(p->cCurrencyID, p->cCurrencyID + 3);
	j["exponent"] = (p->sExponent);

	return j;
}

//##############################################################################
// WFS_INF_CDM_MIX_TYPES, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMMIXTYPE* p) {
	json j;
	if(!p) return j;

	j["mixNumber"] = (p->usMixNumber);
	j["mixType"] = (p->usMixType);
	j["subType"] = GetXfsCdmMixSubTypeName((p->usSubType));
	j["name"] = XSJ_Stringify(p->lpszName);

	return j;
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMMIXROW* p) {
	json j;
	if(!p) return j;

	j["amount"] = (p->ulAmount);
	j["mixture"] = (p->lpusMixture);

	return j;
}
//##############################################################################
//##############################################################################
template <>
inline WFSCDMMIXROW* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMMIXROW>();

	if (j.find("amount") != j.end() && !j["amount"].is_null())
		p->ulAmount = (ULONG)j["amount"];


	return (WFSCDMMIXROW*)a->Get();
}

//##############################################################################
// WFS_INF_CDM_MIX_TABLE, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMMIXTABLE* p) {
	json j;
	if(!p) return j;

	j["mixNumber"] = (p->usMixNumber);
	j["name"] = XSJ_Stringify(p->lpszName);
	j["rows"] = (p->usRows);
	j["cols"] = (p->usCols);
	j["mixHeader"] = XSJ_ListArray(p->lpulMixHeader, (json(*)(const int))nullptr, (std::string(*)(const int))nullptr, p->usCols);
	j["mixRows"] = XSJ_ListNullTerminatedPointers((const WFSCDMMIXROW **)p->lppMixRows, XSJTranslate<WFSCDMMIXROW>);

	return j;
}

//##############################################################################
// WFS_CMD_CDM_SET_MIX_TABLE, in:true, out:false
//##############################################################################
template <>
inline WFSCDMMIXTABLE* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMMIXTABLE>();

	if (j.find("mixNumber") != j.end() && !j["mixNumber"].is_null())
		p->usMixNumber = (USHORT)j["mixNumber"];

	if (j.find("name") != j.end() && !j["name"].is_null())
		p->lpszName = a->Get(j["name"].get<std::string>());

	if (j.find("rows") != j.end() && !j["rows"].is_null())
		p->usRows = (USHORT)j["rows"];

	if (j.find("cols") != j.end() && !j["cols"].is_null())
		p->usCols = (USHORT)j["cols"];

	if (j.find("mixHeader") != j.end() && !j["mixHeader"].is_null())
		if(j["mixHeader"].is_array())
			p->lpulMixHeader = a->AllocateArray<ULONG>(j["mixHeader"], p->usCols);

	if (j.find("mixRows") != j.end() && !j["mixRows"].is_null())
		if(j["mixRows"].is_array())
			p->lppMixRows = a->AllocateArrayPointersNT<WFSCDMMIXROW>(j["mixRows"]);


	return (WFSCDMMIXTABLE*)a->Get();
}

//##############################################################################
// WFS_EXEE_CDM_SUBDISPENSEOK, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMDENOMINATION* p) {
	json j;
	if(!p) return j;

	j["currencyID"] = std::string(p->cCurrencyID, p->cCurrencyID + 3);
	j["amount"] = (p->ulAmount);
	j["count"] = (p->usCount);
	j["values"] = XSJ_ListArray(p->lpulValues, (json(*)(const int))nullptr, (std::string(*)(const int))nullptr, p->usCount);
	j["cashBox"] = (p->ulCashBox);

	return j;
}

//##############################################################################
//##############################################################################
template <>
inline WFSCDMDENOMINATIONIN* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMDENOMINATIONIN>();

	if (j.find("currencyID") != j.end() && !j["currencyID"].is_null())
		std::strncpy(p->cCurrencyID, j["currencyID"].get<std::string>().c_str(), 3);

	if (j.find("amount") != j.end() && !j["amount"].is_null())
		p->ulAmount = (ULONG)j["amount"];

	if (j.find("count") != j.end() && !j["count"].is_null())
		p->usCount = (USHORT)j["count"];

	if (j.find("values") != j.end() && !j["values"].is_null())
		if(j["values"].is_array())
			p->lpulValues = a->AllocateArray<ULONG>(j["values"], p->usCount);

	if (j.find("cashBox") != j.end() && !j["cashBox"].is_null())
		p->ulCashBox = (ULONG)j["cashBox"];


	return (WFSCDMDENOMINATIONIN*)a->Get();
}

//##############################################################################
// WFS_INF_CDM_PRESENT_STATUS, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMPRESENTSTATUS* p) {
	json j;
	if(!p) return j;

	j["denomination"] = XSJTranslate<WFSCDMDENOMINATION>((p->lpDenomination));
	j["presentState"] = GetXfsCdmPresentStatusName((p->wPresentState));
	j["extra"] = XSJ_Stringify(p->lpszExtra);

	return j;
}

//##############################################################################
// WFS_CMD_CDM_DENOMINATE, in:true, out:false
//##############################################################################
template <>
inline WFSCDMDENOMINATE* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMDENOMINATE>();

	if (j.find("tellerID") != j.end() && !j["tellerID"].is_null())
		p->usTellerID = (USHORT)j["tellerID"];

	if (j.find("mixNumber") != j.end() && !j["mixNumber"].is_null())
		p->usMixNumber = (USHORT)j["mixNumber"];

	if (j.find("denomination") != j.end() && !j["denomination"].is_null())
		p->lpDenomination =  XSJTranslate<WFSCDMDENOMINATIONIN>(j["denomination"], a);


	return (WFSCDMDENOMINATE*)a->Get();
}

//##############################################################################
// WFS_CMD_CDM_DISPENSE, in:true, out:false
//##############################################################################
template <>
inline WFSCDMDISPENSE* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMDISPENSE>();

	if (j.find("tellerID") != j.end() && !j["tellerID"].is_null())
		p->usTellerID = (USHORT)j["tellerID"];

	if (j.find("mixNumber") != j.end() && !j["mixNumber"].is_null())
		p->usMixNumber = (USHORT)j["mixNumber"];

	if (j.find("position") != j.end() && !j["position"].is_null())
		p->fwPosition = (WORD)GetXfsCdmDispensePositionId(j["position"]);

	if (j.find("present") != j.end() && !j["present"].is_null())
		p->bPresent = (BOOL)j["present"];

	if (j.find("denomination") != j.end() && !j["denomination"].is_null())
		p->lpDenomination =  XSJTranslate<WFSCDMDENOMINATIONIN>(j["denomination"], a);


	return (WFSCDMDISPENSE*)a->Get();
}

//##############################################################################
// WFS_CMD_CDM_COUNT, in:true, out:false
//##############################################################################
template <>
inline WFSCDMPHYSICALCU* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMPHYSICALCU>();

	if (j.find("emptyAll") != j.end() && !j["emptyAll"].is_null())
		p->bEmptyAll = (BOOL)j["emptyAll"];

	if (j.find("position") != j.end() && !j["position"].is_null())
		p->fwPosition = (WORD)GetXfsCdmDispensePositionId(j["position"]);

	if (j.find("physicalPositionName") != j.end() && !j["physicalPositionName"].is_null())
		p->lpPhysicalPositionName = a->Get(j["physicalPositionName"].get<std::string>());


	return (WFSCDMPHYSICALCU*)a->Get();
}

//##############################################################################
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMCOUNTEDPHYSCU* p) {
	json j;
	if(!p) return j;

	j["physicalPositionName"] = XSJ_Stringify(p->lpPhysicalPositionName);
	j["unitId"] = std::string(p->cUnitId, p->cUnitId + 5);
	j["dispensed"] = (p->ulDispensed);
	j["counted"] = (p->ulCounted);
	j["pStatus"] = GetXfsCdmCashUnitStatusName((p->usPStatus));

	return j;
}

//##############################################################################
// WFS_CMD_CDM_COUNT, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMCOUNT* p) {
	json j;
	if(!p) return j;

	j["numPhysicalCUs"] = (p->usNumPhysicalCUs);
	j["countedPhysCUs"] = XSJ_ListNullTerminatedPointers((const WFSCDMCOUNTEDPHYSCU **)p->lppCountedPhysCUs, XSJTranslate<WFSCDMCOUNTEDPHYSCU>);

	return j;
}

//##############################################################################
// WFS_CMD_CDM_RETRACT, in:true, out:false
//##############################################################################
template <>
inline WFSCDMRETRACT* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMRETRACT>();

	if (j.find("outputPosition") != j.end() && !j["outputPosition"].is_null())
		p->fwOutputPosition = (WORD)j["outputPosition"];

	if (j.find("retractArea") != j.end() && !j["retractArea"].is_null())
		p->usRetractArea = (USHORT)GetXfsCdmRetractAreaId(j["retractArea"]);

	if (j.find("index") != j.end() && !j["index"].is_null())
		p->usIndex = (USHORT)j["index"];


	return (WFSCDMRETRACT*)a->Get();
}

//##############################################################################
// WFS_CMD_CDM_SET_TELLER_INFO, in:true, out:false
//##############################################################################
template <>
inline WFSCDMTELLERUPDATE* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMTELLERUPDATE>();

	if (j.find("action") != j.end() && !j["action"].is_null())
		p->usAction = (USHORT)GetXfsCdmTellerUpdateActionId(j["action"]);

	if (j.find("tellerDetails") != j.end() && !j["tellerDetails"].is_null())
		p->lpTellerDetails =  XSJTranslate<WFSCDMTELLERDETAILS>(j["tellerDetails"], a);


	return (WFSCDMTELLERUPDATE*)a->Get();
}

//##############################################################################
// WFS_CMD_CDM_START_EXCHANGE, in:true, out:false
//##############################################################################
template <>
inline WFSCDMSTARTEX* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMSTARTEX>();

	if (j.find("exchangeType") != j.end() && !j["exchangeType"].is_null())
		p->fwExchangeType = (WORD)GetXfsCdmExchangeTypeId(j["exchangeType"]);

	if (j.find("tellerID") != j.end() && !j["tellerID"].is_null())
		p->usTellerID = (USHORT)j["tellerID"];

	if (j.find("cUNumList") != j.end() && !j["cUNumList"].is_null())
		if(j["cUNumList"].is_array())
			p->lpusCUNumList = a->AllocateArray<USHORT>(j["cUNumList"], p->usCount);


	return (WFSCDMSTARTEX*)a->Get();
}

//##############################################################################
// WFS_CMD_CDM_RESET, in:true, out:false
//##############################################################################
template <>
inline WFSCDMITEMPOSITION* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMITEMPOSITION>();

	if (j.find("number") != j.end() && !j["number"].is_null())
		p->usNumber = (USHORT)j["number"];

	if (j.find("retractArea") != j.end() && !j["retractArea"].is_null())
		p->lpRetractArea =  XSJTranslate<WFSCDMRETRACT>(j["retractArea"], a);

	if (j.find("outputPosition") != j.end() && !j["outputPosition"].is_null())
		p->fwOutputPosition = (WORD)j["outputPosition"];


	return (WFSCDMITEMPOSITION*)a->Get();
}

//##############################################################################
// WFS_INF_CDM_PRESENT_STATUS, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMCALIBRATE* p) {
	json j;
	if(!p) return j;


	return j;
}

//##############################################################################
// WFS_EXEE_CDM_CASHUNITERROR, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMCUERROR* p) {
	json j;
	if(!p) return j;

	j["failure"] = GetXfsCdmMcuErrorsName((p->wFailure));
	j["cashUnit"] = XSJTranslate<WFSCDMCASHUNIT>((p->lpCashUnit));

	return j;
}

//##############################################################################
// WFS_SRVE_CDM_COUNTS_CHANGED, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMCOUNTSCHANGED* p) {
	json j;
	if(!p) return j;

	j["cUNumList"] = XSJ_ListArray(p->lpusCUNumList, (json(*)(const int))nullptr, (std::string(*)(const int))nullptr, p->usCount);

	return j;
}

//##############################################################################
// WFS_INF_IDC_STATUS, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCSTATUS* p) {
	json j;
	if(!p) return j;

	j["device"] = GetXfsIdcDevStatusName((p->fwDevice));
	j["media"] = GetXfsIdcMediaPositionName((p->fwMedia));
	j["retainBin"] = GetXfsIdcRetainBinName((p->fwRetainBin));
	j["security"] = GetXfsIdcSecurityName((p->fwSecurity));
	j["cards"] = (p->usCards);
	j["chipPower"] = GetXfsIdcChipPowerName((p->fwChipPower));
	j["extra"] = XSJ_Stringify(p->lpszExtra);

	return j;
}

//##############################################################################
// WFS_INF_IDC_CAPABILITIES, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCCAPS* p) {
	json j;
	if(!p) return j;

	j["class"] = (p->wClass);
	j["type"] = GetXfsIdcTypeName((p->fwType));
	j["compound"] = (p->bCompound);
	j["readTracks"] = GetXfsIdcTrackName((p->fwReadTracks));
	j["writeTracks"] = GetXfsIdcTrackName((p->fwWriteTracks));
	j["chipProtocols"] = GetXfsIdcChipProtocolName((p->fwChipProtocols));
	j["cards"] = (p->usCards);
	j["secType"] = GetXfsIdcSecTypeName((p->fwSecType));
	j["powerOnOption"] = GetXfsIdcPowerOptionName((p->fwPowerOnOption));
	j["powerOffOption"] = GetXfsIdcPowerOptionName((p->fwPowerOffOption));
	j["fluxSensorProgrammable"] = (p->bFluxSensorProgrammable);
	j["readWriteAccessFollowingEject"] = (p->bReadWriteAccessFollowingEject);
	j["writeMode"] = GetXfsIdcWriteMethodName((p->fwWriteMode));
	j["chipPower"] = GetXfsIdcChipPowerName((p->fwChipPower));
	j["extra"] = XSJ_Stringify(p->lpszExtra);

	return j;
}

//##############################################################################
// WFS_INF_IDC_QUERY_FORM, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCFORM* p) {
	json j;
	if(!p) return j;

	j["formName"] = XSJ_Stringify(p->lpszFormName);
	j["fieldSeparatorTrack1"] = (p->cFieldSeparatorTrack1);
	j["fieldSeparatorTrack2"] = (p->cFieldSeparatorTrack2);
	j["fieldSeparatorTrack3"] = (p->cFieldSeparatorTrack3);
	j["action"] = GetXfsIdcFormActionName((p->fwAction));
	j["tracks"] = XSJ_Stringify(p->lpszTracks);
	j["secure"] = (p->bSecure);
	j["track1Fields"] = XSJ_List2Strings(p->lpszTrack1Fields);
	j["track2Fields"] = XSJ_List2Strings(p->lpszTrack2Fields);
	j["track3Fields"] = XSJ_List2Strings(p->lpszTrack3Fields);

	return j;
}

//##############################################################################
// WFS_CMD_IDC_WRITE_TRACK, in:true, out:false
//##############################################################################
template <>
inline WFSIDCWRITETRACK* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSIDCWRITETRACK>();

	if (j.find("formName") != j.end() && !j["formName"].is_null())
		p->lpstrFormName = a->Get(j["formName"].get<std::string>());

	if (j.find("trackData") != j.end() && !j["trackData"].is_null())
		p->lpstrTrackData = a->Get(j["trackData"].get<std::string>());

	if (j.find("writeMethod") != j.end() && !j["writeMethod"].is_null())
		p->fwWriteMethod = (WORD)GetXfsIdcWriteMethodId(j["writeMethod"]);


	return (WFSIDCWRITETRACK*)a->Get();
}

//##############################################################################
// WFS_CMD_IDC_RETAIN_CARD, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCRETAINCARD* p) {
	json j;
	if(!p) return j;

	j["count"] = (p->usCount);
	j["position"] = GetXfsIdcMediaPositionName((p->fwPosition));

	return j;
}

//##############################################################################
// WFS_CMD_IDC_SETKEY, in:true, out:false
//##############################################################################
template <>
inline WFSIDCSETKEY* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSIDCSETKEY>();

	if (j.find("keyLen") != j.end() && !j["keyLen"].is_null())
		p->usKeyLen = (USHORT)j["keyLen"];

	if (j.find("keyValue") != j.end() && !j["keyValue"].is_null())
		p->lpbKeyValue = (LPBYTE)a->Get(j["keyValue"].get<std::string>());


	return (WFSIDCSETKEY*)a->Get();
}

//##############################################################################
// WFS_CMD_IDC_READ_RAW_DATA, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCCARDDATA* p) {
	json j;
	if(!p) return j;

	j["dataSource"] = GetXfsIdcTrackName((p->wDataSource));
	j["status"] = GetXfsIdcCardTrackStatusName((p->wStatus));
	j["dataLength"] = (p->ulDataLength);
	j["data"] = XSJ_Stringify(p->lpbData);
	j["writeMethod"] = GetXfsIdcWriteMethodName((p->fwWriteMethod));

	return j;
}

//##############################################################################
// WFS_CMD_IDC_CHIP_IO, in:true, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCCHIPIO* p) {
	json j;
	if(!p) return j;

	j["chipProtocol"] = GetXfsIdcChipProtocolName((p->wChipProtocol));
	j["chipDataLength"] = (p->ulChipDataLength);
	j["chipData"] = XSJ_Stringify(p->lpbChipData);

	return j;
}
//##############################################################################
// WFS_CMD_IDC_CHIP_IO, in:true, out:true
//##############################################################################
template <>
inline WFSIDCCHIPIO* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSIDCCHIPIO>();

	if (j.find("chipProtocol") != j.end() && !j["chipProtocol"].is_null())
		p->wChipProtocol = (WORD)GetXfsIdcChipProtocolId(j["chipProtocol"]);

	if (j.find("chipDataLength") != j.end() && !j["chipDataLength"].is_null())
		p->ulChipDataLength = (ULONG)j["chipDataLength"];

	if (j.find("chipData") != j.end() && !j["chipData"].is_null())
		p->lpbChipData = (LPBYTE)a->Get(j["chipData"].get<std::string>());


	return (WFSIDCCHIPIO*)a->Get();
}

//##############################################################################
// WFS_CMD_IDC_CHIP_POWER, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCCHIPPOWEROUT* p) {
	json j;
	if(!p) return j;

	j["chipDataLength"] = (p->ulChipDataLength);
	j["chipData"] = XSJ_Stringify(p->lpbChipData);

	return j;
}

//##############################################################################
// WFS_CMD_IDC_WRITE_RAW_DATA, in:true, out:false
//##############################################################################
template <>
inline WFSIDCCARDDATARAWINPUT* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSIDCCARDDATARAWINPUT>();

	if (j.find("dataSource") != j.end() && !j["dataSource"].is_null())
		p->wDataSource = (WORD)GetXfsIdcTrackId(j["dataSource"]);

	if (j.find("dataLength") != j.end() && !j["dataLength"].is_null())
		p->ulDataLength = (ULONG)j["dataLength"];

	if (j.find("data") != j.end() && !j["data"].is_null())
		p->lpbData = (LPBYTE)a->Get(j["data"].get<std::string>());

	if (j.find("writeMethod") != j.end() && !j["writeMethod"].is_null())
		p->fwWriteMethod = (WORD)GetXfsIdcWriteMethodId(j["writeMethod"]);


	return (WFSIDCCARDDATARAWINPUT*)a->Get();
}

//##############################################################################
// WFS_CMD_IDC_PARSE_DATA, in:true, out:false
//##############################################################################
template <>
inline WFSIDCPARSEDATA* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSIDCPARSEDATA>();

	if (j.find("formName") != j.end() && !j["formName"].is_null())
		p->lpstrFormName = a->Get(j["formName"].get<std::string>());

	if (j.find("cardData") != j.end() && !j["cardData"].is_null())
		if(j["cardData"].is_array())
			p->lppCardData = a->AllocateArrayPointersNT<WFSIDCCARDDATARAWINPUT>(j["cardData"]);


	return (WFSIDCPARSEDATA*)a->Get();
}

//##############################################################################
// WFS_EXEE_IDC_INVALIDTRACKDATA, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCTRACKEVENT* p) {
	json j;
	if(!p) return j;

	j["status"] = GetXfsIdcCardTrackStatusName((p->fwStatus));
	j["track"] = XSJ_Stringify(p->lpstrTrack);
	j["data"] = XSJ_Stringify(p->lpstrData);

	return j;
}

//##############################################################################
// WFS_SRVE_IDC_CARDACTION, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCCARDACT* p) {
	json j;
	if(!p) return j;


	return j;
}

//##############################################################################
// WFS_INF_PTR_QUERY_FORM, in:true, out:false
//##############################################################################
template <>
inline WFSPTRFORMNAME* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTRFORMNAME>();

	if (j.find("formName") != j.end() && !j["formName"].is_null())
		std::strncpy(p->szFormName, j["formName"].get<std::string>().c_str(), 1024);


	return (WFSPTRFORMNAME*)a->Get();
}

//##############################################################################
// WFS_INF_PTR_QUERY_MEDIA, in:true, out:false
//##############################################################################
template <>
inline WFSPTRMEDIANAME* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTRMEDIANAME>();

	if (j.find("mediaName") != j.end() && !j["mediaName"].is_null())
		std::strncpy(p->szMediaName, j["mediaName"].get<std::string>().c_str(), 1024);


	return (WFSPTRMEDIANAME*)a->Get();
}

//##############################################################################
// WFS_INF_PTR_FORM_LIST, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRFORMLIST* p) {
	json j;
	if(!p) return j;

	j["formList"] = XSJ_List2Strings(p->lpszFormList);

	return j;
}

//##############################################################################
// WFS_INF_PTR_MEDIA_LIST, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRMEDIALIST* p) {
	json j;
	if(!p) return j;

	j["mediaList"] = XSJ_List2Strings(p->lpszMediaList);

	return j;
}

//##############################################################################
// WFS_CMD_PTR_CONTROL_MEDIA, in:true, out:false
//##############################################################################
template <>
inline WFSPTCONTROLMEDIA* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTCONTROLMEDIA>();

	if (j.find("mediaControl") != j.end() && !j["mediaControl"].is_null())
		p->dwMediaControl = (DWORD)GetXfsPtrControlId(j["mediaControl"]);


	return (WFSPTCONTROLMEDIA*)a->Get();
}

//##############################################################################
// WFS_CMD_PTR_RESET_COUNT, in:true, out:false
//##############################################################################
template <>
inline WFSPTRRESETCOUNT* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTRRESETCOUNT>();

	if (j.find("binNumber") != j.end() && !j["binNumber"].is_null())
		p->usBinNumber = (USHORT)j["binNumber"];


	return (WFSPTRRESETCOUNT*)a->Get();
}

//##############################################################################
// WFS_CMD_PTR_RETRACT_MEDIA, in:true, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRRETRACTMEDIA* p) {
	json j;
	if(!p) return j;

	j["binNumber"] = (p->usBinNumber);

	return j;
}
//##############################################################################
// WFS_CMD_PTR_RETRACT_MEDIA, in:true, out:true
//##############################################################################
template <>
inline WFSPTRRETRACTMEDIA* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTRRETRACTMEDIA>();

	if (j.find("binNumber") != j.end() && !j["binNumber"].is_null())
		p->usBinNumber = (USHORT)j["binNumber"];


	return (WFSPTRRETRACTMEDIA*)a->Get();
}

//##############################################################################
// WFS_CMD_PTR_DISPENSE_PAPER, in:true, out:false
//##############################################################################
template <>
inline WFSPTRDISPENSEPAPER* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSPTRDISPENSEPAPER>();

	if (j.find("paperSource") != j.end() && !j["paperSource"].is_null())
		p->wPaperSource = (WORD)GetXfsPtrPaperSourceId(j["paperSource"]);


	return (WFSPTRDISPENSEPAPER*)a->Get();
}

//##############################################################################
// WFS_EXEE_PTR_NOMEDIA, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRNOMEDIA* p) {
	json j;
	if(!p) return j;

	j["userPrompt"] = XSJ_Stringify(p->lpszUserPrompt);

	return j;
}

//##############################################################################
// WFS_EXEE_PTR_FIELDWARNING, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRFIELDWARNING* p) {
	json j;
	if(!p) return j;

	j["formName"] = XSJ_Stringify(p->lpszFormName);
	j["fieldName"] = XSJ_Stringify(p->lpszFieldName);
	j["failure"] = (p->wFailure);

	return j;
}

//##############################################################################
// WFS_USRE_PTR_TONERTHRESHOLD, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRTONERTHRESHOLD* p) {
	json j;
	if(!p) return j;

	j["tonerThreshold"] = GetXfsPtrTonerSatusName((p->lpwTonerThreshold));

	return j;
}

//##############################################################################
// WFS_USRE_PTR_LAMPTHRESHOLD, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRLAMPTHRESHOLD* p) {
	json j;
	if(!p) return j;

	j["lampThreshold"] = GetXfsPtrLampStatusName((p->wLampThreshold));

	return j;
}

//##############################################################################
// WFS_USRE_PTR_INKTHRESHOLD, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSPTRINKTHRESHOLD* p) {
	json j;
	if(!p) return j;

	j["inkThreshold"] = GetXfsPtrInkStatusName((p->wInkThreshold));

	return j;
}

//##############################################################################
// WFS_INF_CDM_MIX_TABLE, in:true, out:false
//##############################################################################
template <>
inline WFSCDMMIXEDNUMBER* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMMIXEDNUMBER>();

	if (j.find("mixNumber") != j.end() && !j["mixNumber"].is_null())
		p->usMixNumber = (USHORT)j["mixNumber"];


	return (WFSCDMMIXEDNUMBER*)a->Get();
}

//##############################################################################
// WFS_INF_CDM_PRESENT_STATUS, in:true, out:false
//##############################################################################
template <>
inline WFSCDMPRESENTSTATUSIN* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMPRESENTSTATUSIN>();

	if (j.find("position") != j.end() && !j["position"].is_null())
		p->fwPosition = (WORD)GetXfsCdmDispensePositionId(j["position"]);


	return (WFSCDMPRESENTSTATUSIN*)a->Get();
}

//##############################################################################
// WFS_CMD_CDM_PRESENT, in:true, out:false
//##############################################################################
template <>
inline WFSCDMPRESENTPOSITION* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMPRESENTPOSITION>();

	if (j.find("position") != j.end() && !j["position"].is_null())
		p->fwPosition = (WORD)GetXfsCdmDispensePositionId(j["position"]);


	return (WFSCDMPRESENTPOSITION*)a->Get();
}

//##############################################################################
// WFS_CMD_CDM_REJECT, in:true, out:false
//##############################################################################
template <>
inline WFSCDMREJECT* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMREJECT>();


	return (WFSCDMREJECT*)a->Get();
}

//##############################################################################
// WFS_CMD_CDM_CLOSE_SHUTTER, in:true, out:false
//##############################################################################
template <>
inline WFSCDMCLOSESHUTTER* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCDMCLOSESHUTTER>();

	if (j.find("position") != j.end() && !j["position"].is_null())
		p->fwPosition = (WORD)GetXfsCdmDispensePositionId(j["position"]);


	return (WFSCDMCLOSESHUTTER*)a->Get();
}

//##############################################################################
// WFS_SRVE_CDM_TELLERINFOCHANGED, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMTELLERINFOCHANGED* p) {
	json j;
	if(!p) return j;

	j["tellerID"] = (p->usTellerID);

	return j;
}

//##############################################################################
// WFS_EXEE_CDM_DELAYEDDISPENSE, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMDELAYDISPENSE* p) {
	json j;
	if(!p) return j;

	j["delay"] = (p->ulDelay);

	return j;
}

//##############################################################################
// WFS_EXEE_CDM_STARTDISPENSE, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMSTARTDISPENSE* p) {
	json j;
	if(!p) return j;

	j["reqID"] = (p->hReqID);

	return j;
}

//##############################################################################
// WFS_SRVE_CDM_ITEMSTAKEN, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMITEMTAKEN* p) {
	json j;
	if(!p) return j;

	j["position"] = (p->fwPosition);

	return j;
}

//##############################################################################
// WFS_EXEE_CDM_PARTIALDISPENSE, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMPARTIALDISPENSE* p) {
	json j;
	if(!p) return j;

	j["dispNum"] = (p->usDispNum);

	return j;
}

//##############################################################################
// WFS_EXEE_CDM_NOTEERROR, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSCDMNOTEERROR* p) {
	json j;
	if(!p) return j;

	j["reason"] = GetXfsCdmNotesErrorName((p->fuReason));

	return j;
}

//##############################################################################
// WFS_INF_IDC_QUERY_FORM, in:true, out:false
//##############################################################################
template <>
inline WFSIDCFORMNAME* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSIDCFORMNAME>();

	if (j.find("formName") != j.end() && !j["formName"].is_null())
		std::strncpy(p->szFormName, j["formName"].get<std::string>().c_str(), 1024);


	return (WFSIDCFORMNAME*)a->Get();
}

//##############################################################################
// WFS_CMD_IDC_READ_TRACK, in:true, out:false
//##############################################################################
template <>
inline WFSIDCREADTRACKFORMNAME* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSIDCREADTRACKFORMNAME>();

	if (j.find("formName") != j.end() && !j["formName"].is_null())
		std::strncpy(p->szFormName, j["formName"].get<std::string>().c_str(), 1024);


	return (WFSIDCREADTRACKFORMNAME*)a->Get();
}

//##############################################################################
// WFS_CMD_IDC_READ_TRACK, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCREADTRACKDATA* p) {
	json j;
	if(!p) return j;

	j["trackData"] = XSJ_Stringify(p->lpstrTrackData);

	return j;
}

//##############################################################################
// WFS_CMD_IDC_READ_RAW_DATA, in:true, out:false
//##############################################################################
template <>
inline WFSREADRAWDATA* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSREADRAWDATA>();

	if (j.find("readData") != j.end() && !j["readData"].is_null())
		p->wReadData = (WORD)GetXfsIdcTrackId(j["readData"]);


	return (WFSREADRAWDATA*)a->Get();
}

//##############################################################################
// WFS_CMD_IDC_CHIP_IO, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCCHIPIOOUT* p) {
	json j;
	if(!p) return j;

	j["chipProtocol"] = (p->wChipProtocol);
	j["chipDataLength"] = (p->ulChipDataLength);
	j["chipData"] = XSJ_Stringify(p->lpbChipData);

	return j;
}

//##############################################################################
// WFS_CMD_IDC_CHIP_POWER, in:true, out:false
//##############################################################################
template <>
inline WFSCHIPPOWER* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSCHIPPOWER>();

	if (j.find("chipPower") != j.end() && !j["chipPower"].is_null())
		p->wChipPower = (WORD)GetXfsIdcChipPowerId(j["chipPower"]);


	return (WFSCHIPPOWER*)a->Get();
}

//##############################################################################
// WFS_INF_IDC_FORM_LIST, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCFORMLIST* p) {
	json j;
	if(!p) return j;

	j["formList"] = XSJ_List2Strings(p->lpszFormList);

	return j;
}

//##############################################################################
// WFS_CMD_IDC_EJECT_CARD, in:true, out:false
//##############################################################################
template <>
inline WFSIDCEJECTCARD* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSIDCEJECTCARD>();


	return (WFSIDCEJECTCARD*)a->Get();
}

//##############################################################################
// WFS_CMD_IDC_RESET_COUNT, in:true, out:false
//##############################################################################
template <>
inline WFSIDCRESETCOUNT* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSIDCRESETCOUNT>();


	return (WFSIDCRESETCOUNT*)a->Get();
}

//##############################################################################
// WFS_CMD_IDC_RESET, in:true, out:false
//##############################################################################
template <>
inline WFSIDCRESETIN* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSIDCRESETIN>();

	if (j.find("resetIn") != j.end() && !j["resetIn"].is_null())
		p->wResetIn = (WORD)j["resetIn"];


	return (WFSIDCRESETIN*)a->Get();
}

//##############################################################################
// WFS_CMD_IDC_CHIP_POWER, in:true, out:false
//##############################################################################
template <>
inline WFSIDCCHIPPOWER* XSJTranslate(const json& j, XSJAllocator* a) {
	XSJAllocator allocator;
	if(nullptr==a){
		a = &allocator;
	}
	auto p = a->Get<WFSIDCCHIPPOWER>();

	if (j.find("chipPower") != j.end() && !j["chipPower"].is_null())
		p->wChipPower = (WORD)GetXfsIdcChipPowerId(j["chipPower"]);


	return (WFSIDCCHIPPOWER*)a->Get();
}

//##############################################################################
// WFS_CMD_IDC_PARSE_DATA, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIPARSEDATAOUT* p) {
	json j;
	if(!p) return j;

	j["parseData"] = XSJ_Stringify(p->lpParseData);

	return j;
}

//##############################################################################
// WFS_USRE_IDC_RETAINBINTHRESHOLD, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCRETAINBIN* p) {
	json j;
	if(!p) return j;

	j["retainBin"] = GetXfsIdcRetainBinName((p->wRetainBin));

	return j;
}

//##############################################################################
// WFS_SRVE_IDC_MEDIADETECTED, in:false, out:true
//##############################################################################
template <>
inline json XSJTranslate(const WFSIDCRESETOUT* p) {
	json j;
	if(!p) return j;

	j["resetOut"] = GetXfsIdcCardActionName((p->wResetOut));

	return j;
}

inline Translator* GetTranslators(int& size) {
	static Translator transators[] = {
		{
			"WFS_INF_PTR_STATUS", 
			"PtrStatus", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSPTRSTATUS)p); })
		},
		{
			"WFS_INF_PTR_CAPABILITIES", 
			"PtrCaps", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSPTRCAPS)p); })
		},
		{
			"WFS_INF_PTR_QUERY_FORM", 
			"PtrFormHeader", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSFRMHEADER)p); })
		},
		{
			"WFS_INF_PTR_QUERY_MEDIA", 
			"PtrFormMedia", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSFRMMEDIA)p); })
		},
		{
			"WFS_INF_PTR_QUERY_FIELD", 
			"PtrQueryField", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTRQUERYFIELD>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_INF_PTR_QUERY_FIELD", 
			"PtrFormField", 
			nullptr, 
			([](const LPVOID p){ return XSJ_ListNullTerminatedPointers((const WFSFRMFIELD**)p, XSJTranslate<WFSFRMFIELD>); })
		},
		{
			"WFS_CMD_PTR_PRINT_FORM", 
			"PtrPrintForm", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTRPRINTFORM>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_PTR_READ_FORM", 
			"PtrReadForm", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTRREADFORM>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_PTR_READ_FORM", 
			"PtrReadFormOut", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSPTRREADFORMOUT)p); })
		},
		{
			"WFS_CMD_PTR_RAW_DATA", 
			"PtrRawData", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTRRAWDATA>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_PTR_RAW_DATA", 
			"PtrRawDataIn", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSPTRRAWDATAIN)p); })
		},
		{
			"WFS_CMD_PTR_MEDIA_EXTENTS", 
			"PtrMediaUit", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTRMEDIAUNIT>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_PTR_MEDIA_EXTENTS", 
			"PtrMediaExt", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSPTRMEDIAEXT)p); })
		},
		{
			"WFS_CMD_PTR_READ_IMAGE", 
			"PtrImageRequest", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTRIMAGEREQUEST>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_PTR_READ_IMAGE", 
			"PtrImage", 
			nullptr, 
			([](const LPVOID p){ return XSJ_ListNullTerminatedPointers((const WFSPTRIMAGE**)p, XSJTranslate<WFSPTRIMAGE>); })
		},
		{
			"WFS_CMD_PTR_RESET", 
			"PtrReset", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTRRESET>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_EXEE_PTR_FIELDERROR", 
			"PtrFieldFailure", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSPTRFIELDFAIL)p); })
		},
		{
			"WFS_EXEE_PTR_FIELDWARNING", 
			"PtrFieldFailure", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSPTRFIELDFAIL)p); })
		},
		{
			"WFS_USRE_PTR_RETRACTBINTHRESHOLD", 
			"PtrBinThreshold", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSPTRBINTHRESHOLD)p); })
		},
		{
			"WFS_USRE_PTR_PAPERTHRESHOLD", 
			"PtrPaperThreshold", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSPTRPAPERTHRESHOLD)p); })
		},
		{
			"WFS_SRVE_PTR_MEDIADETECTED", 
			"PtrMediaDected", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSPTRMEDIADETECTED)p); })
		},
		{
			"WFS_INF_CDM_STATUS", 
			"CdmStatus", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMSTATUS)p); })
		},
		{
			"WFS_INF_CDM_CAPABILITIES", 
			"CdmCaps", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMCAPS)p); })
		},
		{
			"WFS_USRE_CDM_CASHUNITTHRESHOLD", 
			"CdmCashUnit", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMCASHUNIT)p); })
		},
		{
			"WFS_INF_CDM_CASH_UNIT_INFO", 
			"CdmCashUnitInfo", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMCUINFO)p); })
		},
		{
			"WFS_CMD_CDM_SET_CASH_UNIT_INFO", 
			"CdmCashUnitInfo", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMCUINFO>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_START_EXCHANGE", 
			"CdmCashUnitInfo", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMCUINFO>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_END_EXCHANGE", 
			"CdmCashUnitInfo", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMCUINFO>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_TEST_CASH_UNITS", 
			"CdmCashUnitInfo", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMCUINFO)p); })
		},
		{
			"WFS_INF_CDM_TELLER_INFO", 
			"CdmTellerInfo", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMTELLERINFO>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_INF_CDM_TELLER_INFO", 
			"CdmTellerDetails", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMTELLERDETAILS)p); })
		},
		{
			"WFS_INF_CDM_CURRENCY_EXP", 
			"CdmCurrencyExp", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMCURRENCYEXP)p); })
		},
		{
			"WFS_INF_CDM_MIX_TYPES", 
			"CdmMixType", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMMIXTYPE)p); })
		},
		{
			"WFS_INF_CDM_MIX_TABLE", 
			"CdmMixTable", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMMIXTABLE)p); })
		},
		{
			"WFS_CMD_CDM_SET_MIX_TABLE", 
			"CdmMixTable", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMMIXTABLE>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_EXEE_CDM_SUBDISPENSEOK", 
			"CdmDenomination", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMDENOMINATION)p); })
		},
		{
			"WFS_CMD_CDM_DISPENSE", 
			"CdmDenomination", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMDENOMINATION)p); })
		},
		{
			"WFS_EXEE_CDM_INCOMPLETEDISPENSE", 
			"CdmDenomination", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMDENOMINATION)p); })
		},
		{
			"WFS_INF_CDM_PRESENT_STATUS", 
			"CdmPresentStatus", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMPRESENTSTATUS)p); })
		},
		{
			"WFS_CMD_CDM_DENOMINATE", 
			"CdmDenominate", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMDENOMINATE>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_DISPENSE", 
			"CdmDispense", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMDISPENSE>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_COUNT", 
			"CdmPhysicalCu", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMPHYSICALCU>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_COUNT", 
			"CdmCount", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMCOUNT)p); })
		},
		{
			"WFS_CMD_CDM_RETRACT", 
			"CdmRetract", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMRETRACT>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_SET_TELLER_INFO", 
			"CdmUpdateTellorInfo", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMTELLERUPDATE>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_START_EXCHANGE", 
			"CdmStartEx", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMSTARTEX>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_RESET", 
			"CdmReset", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMITEMPOSITION>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_TEST_CASH_UNITS", 
			"CdmReset", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMITEMPOSITION>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_INF_CDM_PRESENT_STATUS", 
			"CdmPresentStatus", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMCALIBRATE)p); })
		},
		{
			"WFS_EXEE_CDM_CASHUNITERROR", 
			"CdmCashUnitError", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMCUERROR)p); })
		},
		{
			"WFS_SRVE_CDM_COUNTS_CHANGED", 
			"CdmCountsChanged", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMCOUNTSCHANGED)p); })
		},
		{
			"WFS_INF_IDC_STATUS", 
			"IdcStatus", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSIDCSTATUS)p); })
		},
		{
			"WFS_INF_IDC_CAPABILITIES", 
			"IdcCpas", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSIDCCAPS)p); })
		},
		{
			"WFS_INF_IDC_QUERY_FORM", 
			"IdcForm", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSIDCFORM)p); })
		},
		{
			"WFS_CMD_IDC_WRITE_TRACK", 
			"IdcWriteTrack", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSIDCWRITETRACK>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_IDC_RETAIN_CARD", 
			"IdcRetainCard", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSIDCRETAINCARD)p); })
		},
		{
			"WFS_CMD_IDC_SETKEY", 
			"IdcSetKey", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSIDCSETKEY>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_IDC_READ_RAW_DATA", 
			"IdcCardData", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSIDCCARDDATA)p); })
		},
		{
			"WFS_CMD_IDC_CHIP_IO", 
			"IdcChipIo", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSIDCCHIPIO>(j, nullptr); }), 
			([](const LPVOID p){ return XSJTranslate((LPWFSIDCCHIPIO)p); })
		},
		{
			"WFS_CMD_IDC_CHIP_POWER", 
			"IdcChipPowerOut", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSIDCCHIPPOWEROUT)p); })
		},
		{
			"WFS_CMD_IDC_WRITE_RAW_DATA", 
			"IdcWriteRawData", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSIDCCARDDATARAWINPUT>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_IDC_PARSE_DATA", 
			"IdcParseData", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSIDCPARSEDATA>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_EXEE_IDC_INVALIDTRACKDATA", 
			"IdcTrackEvent", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSIDCTRACKEVENT)p); })
		},
		{
			"WFS_SRVE_IDC_CARDACTION", 
			"IdcCardAct", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSIDCCARDACT)p); })
		},
		{
			"WFS_INF_PTR_QUERY_FORM", 
			"PtrQueryForm", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTRFORMNAME>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_INF_PTR_QUERY_MEDIA", 
			"PtrQueryMedia", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTRMEDIANAME>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_INF_PTR_FORM_LIST", 
			"PtrFormlist", 
			nullptr, 
			([](const LPVOID p){ WFSPTRFORMLIST ns = {(LPSTR)p}; return XSJTranslate(&ns); })
		},
		{
			"WFS_INF_PTR_MEDIA_LIST", 
			"PtrMedialist", 
			nullptr, 
			([](const LPVOID p){ WFSPTRMEDIALIST ns = {(LPSTR)p}; return XSJTranslate(&ns); })
		},
		{
			"WFS_CMD_PTR_CONTROL_MEDIA", 
			"PtrControlMedia", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTCONTROLMEDIA>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_PTR_RESET_COUNT", 
			"PtrResetCount", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTRRESETCOUNT>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_PTR_RETRACT_MEDIA", 
			"PtrRetractMedia", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTRRETRACTMEDIA>(j, nullptr); }), 
			([](const LPVOID p){ return XSJTranslate((LPWFSPTRRETRACTMEDIA)p); })
		},
		{
			"WFS_CMD_PTR_DISPENSE_PAPER", 
			"PtrDispensePaper", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSPTRDISPENSEPAPER>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_EXEE_PTR_NOMEDIA", 
			"PtrNoMedia", 
			nullptr, 
			([](const LPVOID p){ WFSPTRNOMEDIA ns = {(LPSTR)p}; return XSJTranslate(&ns); })
		},
		{
			"WFS_EXEE_PTR_FIELDWARNING", 
			"PtrFieldWarning", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSPTRFIELDWARNING)p); })
		},
		{
			"WFS_USRE_PTR_TONERTHRESHOLD", 
			"PtrTonerThreshold", 
			nullptr, 
			([](const LPVOID p){ WFSPTRTONERTHRESHOLD ns = {(WORD)*(LPWORD)p}; return XSJTranslate(&ns); })
		},
		{
			"WFS_USRE_PTR_LAMPTHRESHOLD", 
			"PtrLampThreshold", 
			nullptr, 
			([](const LPVOID p){ WFSPTRLAMPTHRESHOLD ns = {(WORD)*(LPWORD)p}; return XSJTranslate(&ns); })
		},
		{
			"WFS_USRE_PTR_INKTHRESHOLD", 
			"PtrInkThreshold", 
			nullptr, 
			([](const LPVOID p){ WFSPTRINKTHRESHOLD ns = {(WORD)*(LPWORD)p}; return XSJTranslate(&ns); })
		},
		{
			"WFS_INF_CDM_MIX_TABLE", 
			"CdmMixedNumber", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMMIXEDNUMBER>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_INF_CDM_PRESENT_STATUS", 
			"CdmPresentStatus", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMPRESENTSTATUSIN>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_PRESENT", 
			"CdmPresent", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMPRESENTPOSITION>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_REJECT", 
			"CdmReject", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMREJECT>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_CDM_CLOSE_SHUTTER", 
			"CdmPresent", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCDMCLOSESHUTTER>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_SRVE_CDM_TELLERINFOCHANGED", 
			"CdmTellerInfoChanged", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMTELLERINFOCHANGED)p); })
		},
		{
			"WFS_EXEE_CDM_DELAYEDDISPENSE", 
			"CdmDelayDispense", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMDELAYDISPENSE)p); })
		},
		{
			"WFS_EXEE_CDM_STARTDISPENSE", 
			"CdmStartDispense", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMSTARTDISPENSE)p); })
		},
		{
			"WFS_SRVE_CDM_ITEMSTAKEN", 
			"CdmItemTaken", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMITEMTAKEN)p); })
		},
		{
			"WFS_EXEE_CDM_PARTIALDISPENSE", 
			"CdmPartialDispense", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMPARTIALDISPENSE)p); })
		},
		{
			"WFS_EXEE_CDM_NOTEERROR", 
			"CdmNoteError", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSCDMNOTEERROR)p); })
		},
		{
			"WFS_INF_IDC_QUERY_FORM", 
			"IDCQueryForm", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSIDCFORMNAME>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_IDC_READ_TRACK", 
			"IDCReadTrack", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSIDCREADTRACKFORMNAME>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_IDC_READ_TRACK", 
			"IDCReadTrack", 
			nullptr, 
			([](const LPVOID p){ WFSIDCREADTRACKDATA ns = {(LPSTR)p}; return XSJTranslate(&ns); })
		},
		{
			"WFS_CMD_IDC_READ_RAW_DATA", 
			"IDCReadRawData", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSREADRAWDATA>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_IDC_CHIP_IO", 
			"IdcChipIoOut", 
			nullptr, 
			([](const LPVOID p){ return XSJTranslate((LPWFSIDCCHIPIOOUT)p); })
		},
		{
			"WFS_CMD_IDC_CHIP_POWER", 
			"IdcChipPower", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSCHIPPOWER>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_INF_IDC_FORM_LIST", 
			"IdcFormlist", 
			nullptr, 
			([](const LPVOID p){ WFSIDCFORMLIST ns = {(LPSTR)p}; return XSJTranslate(&ns); })
		},
		{
			"WFS_CMD_IDC_EJECT_CARD", 
			"IdcEjectCard", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSIDCEJECTCARD>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_IDC_RESET_COUNT", 
			"IdcRestCount", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSIDCRESETCOUNT>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_IDC_RESET", 
			"IdcReset", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSIDCRESETIN>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_IDC_CHIP_POWER", 
			"IdcReset", 
			([](const json& j){ return (LPVOID)XSJTranslate<WFSIDCCHIPPOWER>(j, nullptr); }), 
			nullptr
		},
		{
			"WFS_CMD_IDC_PARSE_DATA", 
			"IDCReadTrack", 
			nullptr, 
			([](const LPVOID p){ WFSIPARSEDATAOUT ns = {(LPSTR)p}; return XSJTranslate(&ns); })
		},
		{
			"WFS_USRE_IDC_RETAINBINTHRESHOLD", 
			"IdcRetainBin", 
			nullptr, 
			([](const LPVOID p){ WFSIDCRETAINBIN ns = {(WORD)*(LPWORD)p}; return XSJTranslate(&ns); })
		},
		{
			"WFS_SRVE_IDC_MEDIADETECTED", 
			"IdcRetainBin", 
			nullptr, 
			([](const LPVOID p){ WFSIDCRESETOUT ns = {(WORD)*(LPWORD)p}; return XSJTranslate(&ns); })
		},
	};
	size = sizeof(transators)/sizeof(Translator);
	return transators;
}


#endif
