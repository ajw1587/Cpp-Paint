// LoginDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Paint_0718.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "JoinDlg.h"

// LoginDlg 대화 상자

IMPLEMENT_DYNAMIC(LoginDlg, CDialogEx)

LoginDlg::LoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOGINDLG, pParent)
	, EditID(_T(""))
	, EditPW(_T(""))
{

}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, EditID);
	DDX_Text(pDX, IDC_EDIT_PW, EditPW);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_END, &LoginDlg::OnBnClickedButtonEnd)
	ON_BN_CLICKED(IDC_BUTTON_JOIN, &LoginDlg::OnBnClickedButtonJoin)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &LoginDlg::OnBnClickedButtonLogin)
END_MESSAGE_MAP()


// LoginDlg 메시지 처리기


BOOL LoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void LoginDlg::OnBnClickedButtonEnd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}

void LoginDlg::OnBnClickedButtonJoin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CMFCPaint0718App* pApp = (CMFCPaint0718App*)AfxGetApp();
	pApp->JDlg.DoModal();
}

void LoginDlg::OnBnClickedButtonLogin() // 로그인 버튼 눌렀을때 승인과 유저의 데이터를 얻어옴
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	// Server 연결을 위한 MainApp Socket 얻어오기
	CMFCPaint0718App* pApp = (CMFCPaint0718App*)AfxGetApp();

	// Socket을 이용해 Server에 메시지 전달
	UpdateData(TRUE);
	
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();
	pDoc->MYID = EditID;
	int MsgCode(0);
	CString SendMsg(_T(""));

	SendMsg.Format(_T("%d\t%s\t%s"), WM_CLIENT_LOGIN, EditID, EditPW); // %d:%s:%s

#ifdef _UNICODE
	pApp->m_Socket.Send(SendMsg, SendMsg.GetLength() * 2);
#else
	pApp->m_Socket.Send(SendMsg, SendMsg.GetLength());
#endif
	EditID = _T("");
	EditPW = _T("");
	UpdateData(FALSE);
}