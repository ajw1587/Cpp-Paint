// JoinDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Paint_0718.h"
#include "JoinDlg.h"
#include "afxdialogex.h"


// JoinDlg 대화 상자

IMPLEMENT_DYNAMIC(JoinDlg, CDialogEx)

JoinDlg::JoinDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_JOIN, pParent)
	, m_JoinID(_T(""))
	, m_JoinPW(_T(""))
	, m_JoinNAME(_T(""))
	, m_JoinBIRTH(COleDateTime::GetCurrentTime())
	, m_JoinPHONE1(_T(""))
	, m_JoinPHONE2(_T(""))
	, m_JoinPHONE3(_T(""))
	, m_JoinADD(_T(""))
	, m_JoinGender(_T("남자"))
	, m_JoinMAILACC(_T(""))
	, m_JoinMAILDOM(_T(""))
	, IDCheck(FALSE)
{
}

JoinDlg::~JoinDlg()
{
}

void JoinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_JOINID, m_JoinID);
	DDX_Text(pDX, IDC_EDIT_JOINPW, m_JoinPW);
	DDX_Text(pDX, IDC_EDIT_JOINNAME, m_JoinNAME);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_JOIN, m_JoinBIRTH);
	DDX_CBString(pDX, IDC_COMBO_PHONE1, m_JoinPHONE1);
	DDX_Text(pDX, IDC_EDIT_PHONE2, m_JoinPHONE2);
	DDX_Text(pDX, IDC_EDIT_PHONE3, m_JoinPHONE3);
	DDX_Text(pDX, IDC_EDIT_JOINADD, m_JoinADD);
	DDX_Text(pDX, IDC_EDIT_JOINMAILACC, m_JoinMAILACC);
	DDX_CBString(pDX, IDC_COMBO_JOINMAILDOM, m_JoinMAILDOM);
}


BEGIN_MESSAGE_MAP(JoinDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO_MALE, &JoinDlg::OnBnClickedRadioMale)
	ON_BN_CLICKED(IDC_RADIO_FEMALE, &JoinDlg::OnBnClickedRadioFemale)
	ON_BN_CLICKED(IDC_BUTTON_USERAPPEND, &JoinDlg::OnBnClickedButtonUserappend)
	ON_BN_CLICKED(IDC_BUTTON_IDCHECK, &JoinDlg::OnBnClickedButtonIdcheck)
	ON_BN_CLICKED(IDC_BUTTON_IDCHECK, &JoinDlg::OnBnClickedButtonIdcheck)
END_MESSAGE_MAP()


// JoinDlg 메시지 처리기


void JoinDlg::OnBnClickedRadioMale()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_JoinGender = _T("남자");
}
void JoinDlg::OnBnClickedRadioFemale()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_JoinGender = _T("여자");
}


void JoinDlg::OnBnClickedButtonUserappend() // 가입
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	if ((m_JoinID == _T("")) || (m_JoinPW == _T("")))
	{
		AfxMessageBox(_T("정보를 입력하여 주십시오."));
	}

	if (IDCheck)
	{
		/*Phone 번호*/
		CString PhoneNum;
		PhoneNum.Format(_T("%s-%s-%s"), m_JoinPHONE1, m_JoinPHONE2, m_JoinPHONE3);
		
		/*Birth 구해오기*/
		CString Birth;
		Birth = m_JoinBIRTH.Format(_T("%Y-%m-%d"));

		/*E-Mail*/
		CString email;
		email.Format(_T("%s@%s"), m_JoinMAILACC, m_JoinMAILDOM);

		/*Join User 정보*/
		CString UserInfo(_T(""));
		UserInfo.Format(_T("%s;%s;%s;%s;%s;%s;%s"),
			m_JoinPW, m_JoinNAME, Birth, PhoneNum, m_JoinADD, m_JoinGender, email);

		/*메시지 보내기*/
		CMFCPaint0718App* pApp = (CMFCPaint0718App*)AfxGetApp();
		CString SendMessage(_T(""));
		SendMessage.Format(_T("%d\t%s\t%s"), WM_CLIENT_JOIN, m_JoinID, UserInfo);

#ifdef _UNICODE
		pApp->m_Socket.Send(SendMessage, SendMessage.GetLength() * 2);
#else
		pApp->m_Socket.Send(SendMessage, SendMessage.GetLength());
#endif

		EndDialog(0);
	}
	else
	{
		AfxMessageBox(_T("ID 중복검사를 해주세요."));
	}
}


void JoinDlg::OnBnClickedButtonIdcheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString IDCheckMsg(_T(""));
	IDCheckMsg.Format(_T("%d\t%s\t%s"), WM_CLIENT_IDCHECK, m_JoinID, _T(""));

	CMFCPaint0718App* pApp = (CMFCPaint0718App*)AfxGetApp();

#ifdef _UNICODE
	pApp->m_Socket.Send(IDCheckMsg, IDCheckMsg.GetLength() * 2);
#else
	pApp->m_Socket.Send(IDCheckMsg, IDCheckMsg.GetLength());
#endif
}