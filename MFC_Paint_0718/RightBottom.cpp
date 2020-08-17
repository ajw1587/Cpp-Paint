// RightBottom.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Paint_0718.h"
#include "RightBottom.h"


// RightBottom

IMPLEMENT_DYNCREATE(RightBottom, CFormView)

RightBottom::RightBottom()
	: CFormView(IDD_RightBottom)
{

}

RightBottom::~RightBottom()
{
}

void RightBottom::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(RightBottom, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_LOGOUT, &RightBottom::OnBnClickedButtonLogout)
END_MESSAGE_MAP()


// RightBottom 진단

#ifdef _DEBUG
void RightBottom::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void RightBottom::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// RightBottom 메시지 처리기


void RightBottom::OnBnClickedButtonLogout()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMFCPaint0718App* pApp = (CMFCPaint0718App*)AfxGetApp(); // MainApp 핸들
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();

	CString ID(_T(""));
	ID = pDoc->MYID;

	CString SendMsg(_T(""));
	SendMsg.Format(_T("%d\t%s\t%s"), WM_CLIENT_LOGOUT, ID, _T("LogOut"));

#ifdef _UNICODE
	pApp->m_Socket.Send(SendMsg, SendMsg.GetLength() * 2);
#else
	pApp->m_Socket.Send(SendMsg, SendMsg.GetLength());
#endif

	pDoc->MYID = _T("");

	AfxGetMainWnd()->PostMessageA(WM_CLOSE, 0, 0);
}
