#pragma once
#include "MFC_Paint_0718Doc.h"


// LeftView 폼 보기

class LeftView : public CFormView
{
	DECLARE_DYNCREATE(LeftView)

protected:
	LeftView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~LeftView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LeftView };
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

	CString UserID1;
	UINT UserLEVEL1;
	int UserPOINT1;

	CString UserID2;
	UINT UserLEVEL2;
	int UserPOINT2;

	CString UserID3;
	UINT UserLEVEL3;
	int UserPOINT3;

};


