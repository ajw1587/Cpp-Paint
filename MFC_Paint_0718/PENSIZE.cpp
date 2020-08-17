// PENSIZE.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Paint_0718.h"
#include "PENSIZE.h"
#include "afxdialogex.h"


// PENSIZE 대화 상자

IMPLEMENT_DYNAMIC(PENSIZE, CDialogEx)

PENSIZE::PENSIZE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SIZE, pParent)
	, EditSize(0)
{

}

PENSIZE::~PENSIZE()
{
}

void PENSIZE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_GETSIZE, EditSize);
}


BEGIN_MESSAGE_MAP(PENSIZE, CDialogEx)
END_MESSAGE_MAP()


// PENSIZE 메시지 처리기


BOOL PENSIZE::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();

	EditSize = pDoc->PSize;

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}