#pragma once
#include "MFC_Paint_0718Doc.h"
#include "MainFrm.h"
// BottomView 폼 보기

class BottomView : public CFormView
{
	DECLARE_DYNCREATE(BottomView)

protected:
	BottomView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~BottomView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BottomView };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CMFCPaint0718Doc* GetDocument() const;
	afx_msg void OnBnClickedButtonBpen();
	afx_msg void OnBnClickedButtonBsetting();
	CEdit Chat;
	CListBox m_ChatList; // Talk List
	CString Text;
	afx_msg void OnBnClickedButtonEnter();
	virtual void OnInitialUpdate();
	CMFCButton BlackButton;
	CMFCButton WhiteButton;
	CMFCButton RedButton;
	CMFCButton BlueButton;
	CMFCButton GreenButton;
	CMFCButton YellowButton;
	afx_msg void OnBnClickedMfcbuttonBlack();
	afx_msg void OnBnClickedMfcbuttonWhite();
	afx_msg void OnBnClickedMfcbuttonRed();
	afx_msg void OnBnClickedMfcbuttonBlue();
	afx_msg void OnBnClickedMfcbuttonGreen();
	afx_msg void OnBnClickedMfcbuttonYellow();
	CSliderCtrl SizeSlider;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};


