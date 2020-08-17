#pragma once
#include "ClientSocket.h"
#include "framework.h"
// LoginDlg 대화 상자

class LoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LoginDlg)

public:
	LoginDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~LoginDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOGINDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonEnd();
	CString EditID;
	CString EditPW;
	afx_msg void OnBnClickedButtonJoin();
	afx_msg void OnBnClickedButtonLogin();
};