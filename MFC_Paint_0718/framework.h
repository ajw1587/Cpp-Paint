#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 일부 CString 생성자는 명시적으로 선언됩니다.

// MFC의 공통 부분과 무시 가능한 경고 메시지에 대한 숨기기를 해제합니다.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
#include <afxext.h>         // MFC 확장입니다.





#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 공용 컨트롤에 대한 MFC 지원입니다.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows 공용 컨트롤에 대한 MFC 지원입니다.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC의 리본 및 컨트롤 막대 지원

#include <mysql.h>				// mysql 연결 지원

#include <afxsock.h>			// Socket 연결 지원

#define WM_CLIENT_LOGIN		WM_USER+2
#define WM_CLIENT_LOGOUT	WM_USER+3
#define WM_CLIENT_CHATTING	WM_USER+4
#define WM_CLIENT_JOIN		WM_USER+5
#define WM_CLIENT_IDCHECK	WM_USER+6
#define WM_CLIENT_JOINGAME	WM_USER+7
#define WM_CLIENT_DRAWING	WM_USER+8