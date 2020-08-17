// SettingColor.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Paint_0718.h"
#include "SettingColor.h"
#include "afxdialogex.h"


// SettingColor 대화 상자

IMPLEMENT_DYNAMIC(SettingColor, CDialogEx)

SettingColor::SettingColor(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_COLOR, pParent)
{

}

SettingColor::~SettingColor()
{
}

void SettingColor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_R, SliderR);
	DDX_Control(pDX, IDC_SLIDER_g, SliderG);
	DDX_Control(pDX, IDC_SLIDER_B, SliderB);
	DDX_Control(pDX, IDC_STATIC_SHOWCOLOR, ShowColor);
}


BEGIN_MESSAGE_MAP(SettingColor, CDialogEx)
//	ON_WM_CREATE()
ON_WM_HSCROLL()
ON_EN_CHANGE(IDC_EDIT_RCOLOR, &SettingColor::OnEnChangeEditRcolor)
ON_EN_CHANGE(IDC_EDIT_GCOLOR, &SettingColor::OnEnChangeEditGcolor)
ON_EN_CHANGE(IDC_EDIT_BCOLOR, &SettingColor::OnEnChangeEditBcolor)
//ON_WM_PAINT()
ON_WM_CTLCOLOR()
ON_WM_PAINT()
ON_BN_CLICKED(IDOK, &SettingColor::OnBnClickedOk)
END_MESSAGE_MAP()


// SettingColor 메시지 처리기


//int SettingColor::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
//		return -1;
//
//	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
//
//	return 0;
//}


BOOL SettingColor::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();

	// RGB값 설정
	Rgb = pDoc->color;
	RPos = pDoc->RColor;
	GPos = pDoc->GColor;
	BPos = pDoc->BColor;

	SliderR.SetRange(0, 255);
	SliderR.SetTicFreq(20);
	SliderR.SetPos(RPos);
	SliderR.SetLineSize(10);
	SliderR.SetPageSize(10);
	//RColor.GetDlgItemInt(IDC_EDIT_RCOLOR, &RPos);

	SliderG.SetRange(0, 255);
	SliderG.SetTicFreq(20);
	SliderG.SetPos(GPos);
	SliderG.SetLineSize(10);
	SliderG.SetPageSize(10);
	//GColor.GetDlgItemInt(IDC_EDIT_GCOLOR, &GPos);

	SliderB.SetRange(0, 255);
	SliderB.SetTicFreq(20);
	SliderB.SetPos(BPos);
	SliderB.SetLineSize(10);
	SliderB.SetPageSize(10);
	//BColor.GetDlgItemInt(IDC_EDIT_BCOLOR, &BPos);

	SetDlgItemInt(IDC_EDIT_RCOLOR, RPos);
	SetDlgItemInt(IDC_EDIT_GCOLOR, GPos);
	SetDlgItemInt(IDC_EDIT_BCOLOR, BPos);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void SettingColor::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	ShowColor.GetWindowRect(&rect);
	ScreenToClient(&rect);

	if (pScrollBar)
	{
		if (pScrollBar == (CScrollBar*)&SliderR || pScrollBar == (CScrollBar*)&SliderG || pScrollBar == (CScrollBar*)&SliderB)
		{
			RPos = SliderR.GetPos();
			GPos = SliderG.GetPos();
			BPos = SliderB.GetPos();

			SetDlgItemInt(IDC_EDIT_RCOLOR,RPos);
			SetDlgItemInt(IDC_EDIT_GCOLOR,GPos);
			SetDlgItemInt(IDC_EDIT_BCOLOR,BPos);
			Rgb = RGB(RPos, GPos, BPos);
			//UpdateData(FALSE); // 컨트롤로 변경된 값을 전송
			InvalidateRect(&rect);
		}
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void SettingColor::OnEnChangeEditRcolor()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SliderR.SetPos(RPos);
	Rgb = RGB(RPos, GPos, BPos);
}


void SettingColor::OnEnChangeEditGcolor()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SliderG.SetPos(GPos);
	Rgb = RGB(RPos, GPos, BPos);
}


void SettingColor::OnEnChangeEditBcolor()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SliderB.SetPos(BPos);
	Rgb = RGB(RPos, GPos, BPos);
}


HBRUSH SettingColor::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO:  여기서 DC의 특성을 변경합니다.

	return hbr;
}


void SettingColor::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	CRect rect;
	CClientDC rgbdc(GetDlgItem(IDC_STATIC_SHOWCOLOR));
	CStatic* pSRGB = (CStatic*)GetDlgItem(IDC_STATIC_SHOWCOLOR);
	pSRGB->GetClientRect(rect);
	rgbdc.FillSolidRect(rect, Rgb);
	pSRGB->ValidateRect(rect);
}


void SettingColor::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
	
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();
	pDoc->RColor = RPos;
	pDoc->GColor = GPos;
	pDoc->BColor = BPos;
	pDoc->color = Rgb;
}
