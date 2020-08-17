// LeftView.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Paint_0718.h"
#include "LeftView.h"
#include "SETTING.h"
// LeftView

IMPLEMENT_DYNCREATE(LeftView, CFormView)

LeftView::LeftView()
	: CFormView(IDD_LeftView)
	, UserID1(_T(""))
	, UserID2(_T(""))
	, UserID3(_T(""))
{

}

LeftView::~LeftView()
{
}

void LeftView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_1USERID, UserID1);
	DDX_Text(pDX, IDC_EDIT_1USERLEVEL, UserLEVEL1);
	DDX_Text(pDX, IDC_EDIT_1USERPOINT, UserPOINT1);

	DDX_Text(pDX, IDC_EDIT_2USERID, UserID2);
	DDX_Text(pDX, IDC_EDIT_2USERLEVEL, UserLEVEL2);
	DDX_Text(pDX, IDC_EDIT_2USERPOINT, UserPOINT2);

	DDX_Text(pDX, IDC_EDIT_3USERID, UserID3);
	DDX_Text(pDX, IDC_EDIT_3USERLEVEL, UserLEVEL3);
	DDX_Text(pDX, IDC_EDIT_3USERPOINT, UserPOINT3);
}

BEGIN_MESSAGE_MAP(LeftView, CFormView)

END_MESSAGE_MAP()


// LeftView 진단

#ifdef _DEBUG
void LeftView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void LeftView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG

CMFCPaint0718Doc* LeftView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCPaint0718Doc)));
	return (CMFCPaint0718Doc*)m_pDocument;
}

// LeftView 메시지 처리기