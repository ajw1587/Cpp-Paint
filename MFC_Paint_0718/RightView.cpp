// RightView.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Paint_0718.h"
#include "RightView.h"


// RightView

IMPLEMENT_DYNCREATE(RightView, CFormView)

RightView::RightView()
	: CFormView(IDD_RightView)
	, UserID4(_T(""))
	, UserID5(_T(""))
	, UserID6(_T(""))
{

}

RightView::~RightView()
{
}

void RightView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_4USERID, UserID4);
	DDX_Text(pDX, IDC_EDIT_4USERLEVEL, UserLEVEL4);
	DDX_Text(pDX, IDC_EDIT_4USERPOINT, UserPOINT4);

	DDX_Text(pDX, IDC_EDIT_5USERID, UserID5);
	DDX_Text(pDX, IDC_EDIT_5USERLEVEL, UserLEVEL5);
	DDX_Text(pDX, IDC_EDIT_5USERPOINT, UserPOINT5);

	DDX_Text(pDX, IDC_EDIT_6USERID, UserID6);
	DDX_Text(pDX, IDC_EDIT_6USERLEVEL, UserLEVEL6);
	DDX_Text(pDX, IDC_EDIT_6USERPOINT, UserPOINT6);
}

BEGIN_MESSAGE_MAP(RightView, CFormView)
END_MESSAGE_MAP()


// RightView 진단

#ifdef _DEBUG
void RightView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void RightView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// RightView 메시지 처리기
