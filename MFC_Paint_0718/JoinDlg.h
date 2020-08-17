#pragma once

// JoinDlg 대화 상자

class JoinDlg : public CDialogEx
{
	DECLARE_DYNAMIC(JoinDlg)

public:
	JoinDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~JoinDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_JOIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_JoinID;
	CString m_JoinPW;
	CString m_JoinNAME;
	COleDateTime m_JoinBIRTH;
	CString m_JoinPHONE1;
	CString m_JoinPHONE2;
	CString m_JoinPHONE3;
	CString m_JoinADD;
	afx_msg void OnBnClickedRadioMale();
	afx_msg void OnBnClickedRadioFemale();
	CString m_JoinGender;
	CString m_JoinMAILACC;
	CString m_JoinMAILDOM;
	afx_msg void OnBnClickedButtonUserappend();
	
	afx_msg void OnBnClickedButtonIdcheck();
	BOOL IDCheck;
	LoginDlg* LogDlg;
};
