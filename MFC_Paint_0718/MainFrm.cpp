
// MainFrm.cpp: CMainFrame 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "MFC_Paint_0718.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame() noexcept
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	cs.cx = 1400;
	cs.cy = 950;

	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (!m_splitter.CreateStatic(this, 2, 3))
	{
		TRACE0("Fail to Splitter Window");
		return FALSE;
	}

	m_splitter.CreateView(0, 0, RUNTIME_CLASS(LeftView), CSize(250,650), pContext); // 유저창
	m_splitter.CreateView(0, 1, RUNTIME_CLASS(CMFCPaint0718View), CSize(850,650), pContext); // 그리기창
	m_splitter.CreateView(0, 2, RUNTIME_CLASS(RightView), CSize(250,650), pContext); //유저창

	m_splitter.CreateView(1, 0, RUNTIME_CLASS(LeftBottom), CSize(250,300), pContext);// 시간초, 제시어창
	m_splitter.CreateView(1, 1, RUNTIME_CLASS(BottomView), CSize(850,300), pContext);// 채팅 및 그리기도구
	m_splitter.CreateView(1, 2, RUNTIME_CLASS(RightBottom), CSize(250,300), pContext);// 나가기, 추방, 신고

	return TRUE;
}

void CMainFrame::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMFCPaint0718App* pApp = (CMFCPaint0718App*)AfxGetApp();
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();

	CString SendMsg(_T(""));
	SendMsg.Format(_T("%d\t%s\%s"), WM_CLIENT_LOGOUT, pDoc->MYID, _T(""));

#ifdef _UNICODE
	pApp->m_Socket.Send(SendMsg, SendMsg.GetLength()*2);
#else
	pApp->m_Socket.Send(SendMsg, SendMsg.GetLength());
#endif

	CFrameWnd::OnClose();
}
