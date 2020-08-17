#pragma once

#include "MFC_Paint_0718Doc.h"
// SETTING 대화 상자

class SETTING : public CDialogEx
{
	DECLARE_DYNAMIC(SETTING)
public:

public:
	SETTING(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SETTING();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGSETTING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	COLORREF color;
	afx_msg void OnBnClickedButtoncolor();
	afx_msg void OnBnClickedButtonsize();
};
