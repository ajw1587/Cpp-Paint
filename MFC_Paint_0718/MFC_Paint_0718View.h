
// MFC_Paint_0718View.h: CMFCPaint0718View 클래스의 인터페이스
//

#pragma once
#include "MFC_Paint_0718Doc.h"

class CMFCPaint0718View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCPaint0718View() noexcept;
	DECLARE_DYNCREATE(CMFCPaint0718View)

// 특성입니다.
public:
	CMFCPaint0718Doc* GetDocument() const;
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CMFCPaint0718View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_Paint_0718View.cpp의 디버그 버전
inline CMFCPaint0718Doc* CMFCPaint0718View::GetDocument() const
   { return reinterpret_cast<CMFCPaint0718Doc*>(m_pDocument); }
#endif

