#pragma once



// RightView 폼 보기

class RightView : public CFormView
{
	DECLARE_DYNCREATE(RightView)

protected:
	RightView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~RightView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RightView };
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

	CString UserID4;
	UINT UserLEVEL4;
	int UserPOINT4;

	CString UserID5;
	UINT UserLEVEL5;
	int UserPOINT5;

	CString UserID6;
	UINT UserLEVEL6;
	int UserPOINT6;
};


