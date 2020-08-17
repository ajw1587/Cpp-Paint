// SETTING.cpp: 구현 파일
//


#include "pch.h"
#include "MFC_Paint_0718.h"
#include "SETTING.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "PENSIZE.h"
#include "SettingColor.h"

// SETTING 대화 상자

IMPLEMENT_DYNAMIC(SETTING, CDialogEx)

SETTING::SETTING(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGSETTING, pParent)
{
	color = RGB(0, 0, 0);
}

SETTING::~SETTING()
{
}

void SETTING::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(SETTING, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTONCOLOR, &SETTING::OnBnClickedButtoncolor)
	ON_BN_CLICKED(IDC_BUTTONSIZE, &SETTING::OnBnClickedButtonsize)
END_MESSAGE_MAP()

// SETTING 메시지 처리기

void SETTING::OnBnClickedButtoncolor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SettingColor color;
	// 만들어져 있는 색 Dialog
	// CColorDialog colorDlg;
	// 
	// if (colorDlg.DoModal() == IDOK)
	// {
	// 	this->color = colorDlg.GetColor();
	// 	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)(pFrame->GetActiveDocument());
	// 	pDoc->color = this->color;
	// 	EndDialog(TRUE);
	// }

	color.DoModal();
}


void SETTING::OnBnClickedButtonsize()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PENSIZE pensize;
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

	if (pensize.DoModal() == IDOK)
	{
		CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)(pFrame->GetActiveDocument());
		pDoc->PSize = pensize.EditSize;

		BottomView* BView = (BottomView*)pFrame->GetActiveView();
		BView->SizeSlider.SetPos(pDoc->PSize);

		EndDialog(TRUE);
	}
}