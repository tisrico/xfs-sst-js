/******************************************************************************
*                                                                             *
* xfsspi.h      XFS - SPI functions, types, and definitions                   *
*                                                                             *
*               Version 3.30  (March 19 2015)                                 *
*                                                                             *
******************************************************************************/

#ifndef __inc_xfsspi__h
#define __inc_xfsspi__h

#ifdef __cplusplus
extern "C" {
#endif

#include <xfsapi.h>

	typedef HANDLE HPROVIDER;

#include <xfsconf.h>
#include <xfsadmin.h>

	/*   be aware of alignment   */
#pragma pack(push,1)

	/****** SPI functions ********************************************************/

	HRESULT extern WINAPI WFPCancelAsyncRequest(HSERVICE hService, REQUESTID RequestID);

	HRESULT extern WINAPI WFPClose(HSERVICE hService, HWND hWnd, REQUESTID ReqID);

	HRESULT extern WINAPI WFPDeregister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, REQUESTID ReqID);

	HRESULT extern WINAPI WFPExecute(HSERVICE hService, DWORD dwCommand, LPVOID lpCmdData, DWORD dwTimeOut, HWND hWnd, REQUESTID ReqID);

	HRESULT extern WINAPI WFPGetInfo(HSERVICE hService, DWORD dwCategory, LPVOID lpQueryDetails, DWORD dwTimeOut, HWND hWnd, REQUESTID ReqID);

	HRESULT extern WINAPI WFPLock(HSERVICE hService, DWORD dwTimeOut, HWND hWnd, REQUESTID ReqID);

	HRESULT extern WINAPI WFPOpen(HSERVICE hService, LPSTR lpszLogicalName, HAPP hApp, LPSTR lpszAppID, DWORD dwTraceLevel, DWORD dwTimeOut, HWND hWnd, REQUESTID ReqID, HPROVIDER hProvider, DWORD dwSPIVersionsRequired, LPWFSVERSION lpSPIVersion, DWORD dwSrvcVersionsRequired, LPWFSVERSION lpSrvcVersion);

	HRESULT extern WINAPI WFPRegister(HSERVICE hService, DWORD dwEventClass, HWND hWndReg, HWND hWnd, REQUESTID ReqID);

	HRESULT extern WINAPI WFPSetTraceLevel(HSERVICE hService, DWORD dwTraceLevel);

	HRESULT extern WINAPI WFPUnloadService();

	HRESULT extern WINAPI WFPUnlock(HSERVICE hService, HWND hWnd, REQUESTID ReqID);


	/*   restore alignment   */
#pragma pack(pop)

#ifdef __cplusplus
}    /*extern "C"*/
#endif

#endif  /* __inc_xfsspi__h */
