// BottomView.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Paint_0718.h"
#include "BottomView.h"
#include "SETTING.h"

// BottomView

IMPLEMENT_DYNCREATE(BottomView, CFormView)

BottomView::BottomView()
	: CFormView(IDD_BottomView)
{
}

BottomView::~BottomView()
{
}

void BottomView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CHAT, Chat);
	DDX_Control(pDX, IDC_LIST_CHATTING, m_ChatList);
	DDX_Control(pDX, IDC_MFCBUTTON_BLACK, BlackButton);
	DDX_Control(pDX, IDC_MFCBUTTON_WHITE, WhiteButton);
	DDX_Control(pDX, IDC_MFCBUTTON_RED, RedButton);
	DDX_Control(pDX, IDC_MFCBUTTON_BLUE, BlueButton);
	DDX_Control(pDX, IDC_MFCBUTTON_GREEN, GreenButton);
	DDX_Control(pDX, IDC_MFCBUTTON_YELLOW, YellowButton);
	DDX_Control(pDX, IDC_SLIDER_SIZE, SizeSlider);
}

BEGIN_MESSAGE_MAP(BottomView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_BPEN, &BottomView::OnBnClickedButtonBpen)
	ON_BN_CLICKED(IDC_BUTTON_BSETTING, &BottomView::OnBnClickedButtonBsetting)
	ON_BN_CLICKED(IDC_BUTTON_ENTER, &BottomView::OnBnClickedButtonEnter)
	ON_BN_CLICKED(IDC_MFCBUTTON_BLACK, &BottomView::OnBnClickedMfcbuttonBlack)
	ON_BN_CLICKED(IDC_MFCBUTTON_WHITE, &BottomView::OnBnClickedMfcbuttonWhite)
	ON_BN_CLICKED(IDC_MFCBUTTON_RED, &BottomView::OnBnClickedMfcbuttonRed)
	ON_BN_CLICKED(IDC_MFCBUTTON_BLUE, &BottomView::OnBnClickedMfcbuttonBlue)
	ON_BN_CLICKED(IDC_MFCBUTTON_GREEN, &BottomView::OnBnClickedMfcbuttonGreen)
	ON_BN_CLICKED(IDC_MFCBUTTON_YELLOW, &BottomView::OnBnClickedMfcbuttonYellow)
	ON_WM_HSCROLL()
//	ON_WM_CHAR()
//ON_WM_KEYDOWN()
//ON_WM_CHAR()
END_MESSAGE_MAP()


// BottomView 진단

#ifdef _DEBUG
void BottomView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void BottomView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

CMFCPaint0718Doc* BottomView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCPaint0718Doc)));
	return (CMFCPaint0718Doc*)m_pDocument;
}

// BottomView 메시지 처리기

void BottomView::OnBnClickedButtonBsetting()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SETTING Dlg;
	Dlg.DoModal();
}

void BottomView::OnBnClickedButtonBpen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMFCPaint0718Doc* pDoc = GetDocument();
	pDoc->PenButton = !(pDoc->PenButton);
}

void BottomView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();

	// RGB값 초기화	
	BlackButton.SetFaceColor(RGB(0,0,0));
	WhiteButton.SetFaceColor(RGB(255,255,255));
	RedButton.SetFaceColor(RGB(255,0,0));
	BlueButton.SetFaceColor(RGB(0,0,255));
	GreenButton.SetFaceColor(RGB(0,255,0));
	YellowButton.SetFaceColor(RGB(255,228,0));

	//Size Slider 초기화
	SizeSlider.SetRange(1, 100);
	SizeSlider.SetTicFreq(1);
	SizeSlider.SetPos(pDoc->PSize);
	SizeSlider.SetLineSize(10);
	SizeSlider.SetPageSize(10);
}

void BottomView::OnBnClickedMfcbuttonBlack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();

	pDoc->RColor = 0;
	pDoc->GColor = 0;
	pDoc->BColor = 0;
	pDoc->color = RGB(0, 0, 0);
}

void BottomView::OnBnClickedMfcbuttonWhite()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();

	pDoc->RColor = 255;
	pDoc->GColor = 255;
	pDoc->BColor = 255;
	pDoc->color = RGB(255, 255, 255);
}

void BottomView::OnBnClickedMfcbuttonRed()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();

	pDoc->RColor = 255;
	pDoc->GColor = 0;
	pDoc->BColor = 0;
	pDoc->color = RGB(255, 0, 0);
}

void BottomView::OnBnClickedMfcbuttonBlue()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();

	pDoc->RColor = 0;
	pDoc->GColor = 0;
	pDoc->BColor = 255;
	pDoc->color = RGB(0, 0, 255);
}

void BottomView::OnBnClickedMfcbuttonGreen()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();

	pDoc->RColor = 0;
	pDoc->GColor = 255;
	pDoc->BColor = 0;
	pDoc->color = RGB(0, 255, 0);
}

void BottomView::OnBnClickedMfcbuttonYellow()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();

	pDoc->RColor = 255;
	pDoc->GColor = 228;
	pDoc->BColor = 0;
	pDoc->color = RGB(255, 228, 0);
}

void BottomView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();

	if (pScrollBar == (CScrollBar*)&SizeSlider)
	{
		pDoc->PSize = SizeSlider.GetPos();
	}

	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void BottomView::OnBnClickedButtonEnter()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();
	CMFCPaint0718App* pApp = (CMFCPaint0718App*)AfxGetApp(); // App내 Socket 사용하기 위해 핸들 얻어오기
	
	GetDlgItemText(IDC_EDIT_CHAT, Text);					 //	채팅 Text 얻어오기
	CString SendMsg(_T(""));								 // Server에 보낼 Buffer
	SendMsg.Format(_T("%d\t%s\t%s"), WM_CLIENT_CHATTING, pDoc->MYID, Text);
	Chat.SetWindowTextA(_T(""));

#ifdef _UNICODE
	pApp->m_Socket.Send(SendMsg, SendMsg.GetLength()*2);
#else
	pApp->m_Socket.Send(SendMsg, SendMsg.GetLength());
#endif

	//m_ChatList.InsertString(-1, Text);						 // 채팅 List에 추가하기
	//SetDlgItemText(IDC_EDIT_CHAT, _T(""));					 // 채팅 Text 초기화
}

BOOL BottomView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
			CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();
			CMFCPaint0718App* pApp = (CMFCPaint0718App*)AfxGetApp(); // App내 Socket 사용하기 위해 핸들 얻어오기

			GetDlgItemText(IDC_EDIT_CHAT, Text);					 //	채팅 Text 얻어오기
			CString SendMsg(_T(""));								 // Server에 보낼 Buffer
			SendMsg.Format(_T("%d\t%s\t%s"), WM_CLIENT_CHATTING, pDoc->MYID, Text);
			Chat.SetWindowTextA(_T(""));

#ifdef _UNICODE
			pApp->m_Socket.Send(SendMsg, SendMsg.GetLength() * 2);
#else
			pApp->m_Socket.Send(SendMsg, SendMsg.GetLength());
#endif
		}
	}
	return CFormView::PreTranslateMessage(pMsg);
}
