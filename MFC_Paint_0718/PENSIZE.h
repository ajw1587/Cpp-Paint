#pragma once
#include "MainFrm.h"

// PENSIZE 대화 상자

class PENSIZE : public CDialogEx
{
	DECLARE_DYNAMIC(PENSIZE)

public:
	PENSIZE(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~PENSIZE();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIZE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	UINT EditSize;
	virtual BOOL OnInitDialog();
};
