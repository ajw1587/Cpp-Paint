#pragma once
#include "MFC_Paint_0718Doc.h"
#include "MainFrm.h"
// SettingColor 대화 상자

class SettingColor : public CDialogEx
{
	DECLARE_DYNAMIC(SettingColor)

public:
	SettingColor(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SettingColor();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COLOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int RPos;
	int GPos;
	int BPos;
	COLORREF Rgb;
	CSliderCtrl SliderR;
	CSliderCtrl SliderG;
	CSliderCtrl SliderB;
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeEditRcolor();
	afx_msg void OnEnChangeEditGcolor();
	afx_msg void OnEnChangeEditBcolor();
	CStatic ShowColor;
	CBrush cbr;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
};
