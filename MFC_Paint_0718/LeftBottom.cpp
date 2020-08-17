// LeftBottom.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Paint_0718.h"
#include "LeftBottom.h"


// LeftBottom

IMPLEMENT_DYNCREATE(LeftBottom, CFormView)

LeftBottom::LeftBottom()
	: CFormView(IDD_LeftBottom)
{

}

LeftBottom::~LeftBottom()
{
}

void LeftBottom::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(LeftBottom, CFormView)
END_MESSAGE_MAP()


// LeftBottom 진단

#ifdef _DEBUG
void LeftBottom::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void LeftBottom::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// LeftBottom 메시지 처리기
