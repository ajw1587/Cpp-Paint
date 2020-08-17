
// MFC_Paint_0718View.cpp: CMFCPaint0718View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_Paint_0718.h"
#endif

#include "MFC_Paint_0718Doc.h"
#include "MFC_Paint_0718View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCPaint0718View

IMPLEMENT_DYNCREATE(CMFCPaint0718View, CView)

BEGIN_MESSAGE_MAP(CMFCPaint0718View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCPaint0718View 생성/소멸

CMFCPaint0718View::CMFCPaint0718View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCPaint0718View::~CMFCPaint0718View()
{
}

BOOL CMFCPaint0718View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCPaint0718View 그리기

void CMFCPaint0718View::OnDraw(CDC* /*pDC*/)
{
	CMFCPaint0718Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	
	if (pDoc->PenButton && pDoc->MLBDown)
	{
		CClientDC dc(this);
		CPen pen;
		CPen* oldpen;
		pen.CreatePen(PS_SOLID, pDoc->PSize, pDoc->color);
		oldpen = dc.SelectObject(&pen);
		dc.MoveTo(pDoc->pos1.x, pDoc->pos1.y);
		dc.LineTo(pDoc->pos2.x, pDoc->pos2.y);

		pen.DeleteObject();
		dc.SelectObject(oldpen);
	}
}


// CMFCPaint0718View 진단

#ifdef _DEBUG
void CMFCPaint0718View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCPaint0718View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCPaint0718Doc* CMFCPaint0718View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCPaint0718Doc)));
	return (CMFCPaint0718Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCPaint0718View 메시지 처리기


void CMFCPaint0718View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonDown(nFlags, point);
	CMFCPaint0718Doc* pDoc = GetDocument();

	if (pDoc->PenButton)
	{
		pDoc->MLBDown = TRUE;
		pDoc->pos1.x = point.x;
		pDoc->pos1.y = point.y;
		pDoc->pos2.x = point.x;
		pDoc->pos2.y = point.y;
		Invalidate(FALSE);
	}
}


void CMFCPaint0718View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnMouseMove(nFlags, point);
	CMFCPaint0718Doc* pDoc = GetDocument();

	if (pDoc->PenButton && pDoc->MLBDown)
	{
		pDoc->pos2.x = pDoc->pos1.x;
		pDoc->pos2.y = pDoc->pos1.y;

		pDoc->pos1.x = point.x;
		pDoc->pos1.y = point.y;
		Invalidate(FALSE);
	}
}


void CMFCPaint0718View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnLButtonUp(nFlags, point);
	CMFCPaint0718Doc* pDoc = GetDocument();
	pDoc->MLBDown = FALSE;
	pDoc->pos1.x = NULL;
	pDoc->pos1.y = NULL;
	pDoc->pos2.x = NULL;
	pDoc->pos2.y = NULL;
}
