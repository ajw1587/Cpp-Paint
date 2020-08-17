// ClientSocket.cpp: 구현 파일
//

#include "pch.h"
#include "MFC_Paint_0718.h"
#include "ClientSocket.h"
#include "JoinDlg.h"

// ClientSocket

ClientSocket::ClientSocket()
{
}

ClientSocket::~ClientSocket()
{
}


// ClientSocket 멤버 함수


void ClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	TCHAR Rcv[1024];
	ZeroMemory(Rcv, sizeof(Rcv));
	CString ServerToClientMsg(_T(""));
	CString UserMsgID(_T(""));
	CString UserMsg2(_T(""));
	CMFCPaint0718App* pApp = (CMFCPaint0718App*)AfxGetApp();

	if (Receive(Rcv, sizeof(Rcv)) > 0)
	{
		AfxExtractSubString(ServerToClientMsg, Rcv, 0, '\t');
		AfxExtractSubString(UserMsgID, Rcv, 1, '\t');
		AfxExtractSubString(UserMsg2, Rcv, 2, '\t');

		/*핸들값 얻어오기*/
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		CMFCPaint0718Doc* pDoc = (CMFCPaint0718Doc*)pFrame->GetActiveDocument();
		CMFCPaint0718App* pApp = (CMFCPaint0718App*)AfxGetApp();

		/*LeftView, RightView, BottomView 핸들값 얻어오기*/
		LeftView* LV = (LeftView*)pFrame->m_splitter.GetPane(0, 0);
		RightView* RV = (RightView*)pFrame->m_splitter.GetPane(0, 2);
		BottomView* BV = (BottomView*)pFrame->m_splitter.GetPane(1, 1);

		switch (_ttoi(ServerToClientMsg))
		{
		case WM_CLIENT_JOINGAME: // UserMsg2 = Level, Point
		{
			/*LogIn 승인으로 인한 LogDlg 닫기*/
			pApp->LogDlg.EndDialog(pApp->LogDlgResult);
			
			/*LEVEL, POINT 정보 저장하기*/
			pDoc->UserID = UserMsgID;
			AfxExtractSubString(pDoc->UserLEVEL, UserMsg2, 0, ';');
			AfxExtractSubString(pDoc->UserPOINT, UserMsg2, 1, ';');
			LV->UpdateData(TRUE);
			RV->UpdateData(TRUE);

			if (LV->UserID1 == _T(""))
			{
				LV->UserID1 = pDoc->UserID;
				LV->UserLEVEL1 = _ttoi(pDoc->UserLEVEL);
				LV->UserPOINT1 = _ttoi(pDoc->UserPOINT);
				LV->UpdateData(FALSE);
			}
			else if (LV->UserID2 == _T(""))
			{
				LV->UserID2 = pDoc->UserID;
				LV->UserLEVEL2 = _ttoi(pDoc->UserLEVEL);
				LV->UserPOINT2 = _ttoi(pDoc->UserPOINT);
				LV->UpdateData(FALSE);
			}
			else if (LV->UserID3 == _T(""))
			{
				LV->UserID3 = pDoc->UserID;
				LV->UserLEVEL3 = _ttoi(pDoc->UserLEVEL);
				LV->UserPOINT3 = _ttoi(pDoc->UserPOINT);
				LV->UpdateData(FALSE);
			}
			else if (RV->UserID4 == _T(""))
			{
				RV->UserID4 = pDoc->UserID;
				RV->UserLEVEL4 = _ttoi(pDoc->UserLEVEL);
				RV->UserPOINT4 = _ttoi(pDoc->UserPOINT);
				RV->UpdateData(FALSE);
			}
			else if (RV->UserID5 == _T(""))
			{
				RV->UserID5 = pDoc->UserID;
				RV->UserLEVEL5 = _ttoi(pDoc->UserLEVEL);
				RV->UserPOINT5 = _ttoi(pDoc->UserPOINT);
				RV->UpdateData(FALSE);
			}
			else if (RV->UserID6 == _T(""))
			{
				RV->UserID6 = pDoc->UserID;
				RV->UserLEVEL6 = _ttoi(pDoc->UserLEVEL);
				RV->UserPOINT6 = _ttoi(pDoc->UserPOINT);
				RV->UpdateData(FALSE);
			}
			else
			{
				AfxMessageBox(_T("서버가 꽉찼습니다."));
			}

			pApp->LogDlg.EndDialog(0);
			break;
		}
		case WM_CLIENT_IDCHECK:
		{
			if (UserMsg2.Find(_T("TRUE")) != -1)
			{
				pApp->JDlg.IDCheck = TRUE;
				AfxMessageBox(_T("ID 사용 가능"));
			}
			else
			{
				AfxMessageBox(_T("ID 중복"));
			}
			break;
		}
		case WM_CLIENT_LOGOUT:
		{
			LV->UpdateData(TRUE);
			RV->UpdateData(TRUE);

			if (LV->UserID1 == UserMsgID)
			{
				LV->UserID1 = _T("");
				LV->UserLEVEL1 = 0;
				LV->UserPOINT1 = 0;
				LV->UpdateData(FALSE);
			}
			else if (LV->UserID2 == UserMsgID)
			{
				LV->UserID2 = _T("");
				LV->UserLEVEL2 = 0;
				LV->UserPOINT2 = 0;
				LV->UpdateData(FALSE);
			}
			else if (LV->UserID3 == UserMsgID)
			{
				LV->UserID3 = _T("");
				LV->UserLEVEL3 = 0;
				LV->UserPOINT3 = 0;
				LV->UpdateData(FALSE);
			}
			else if (RV->UserID4 == UserMsgID)
			{
				RV->UserID4 = _T("");
				RV->UserLEVEL4 = 0;
				RV->UserPOINT4 = 0;
				RV->UpdateData(FALSE);
			}
			else if (RV->UserID5 == UserMsgID)
			{
				RV->UserID5 = _T("");
				RV->UserLEVEL5 = 0;
				RV->UserPOINT5 = 0;
				RV->UpdateData(FALSE);
			}
			else if (RV->UserID6 == UserMsgID)
			{
				RV->UserID6 = _T("");
				RV->UserLEVEL6 = 0;
				RV->UserPOINT6 = 0;
				RV->UpdateData(FALSE);
			}
			else
			{
				AfxMessageBox(_T("User 목록 삭제 실패"));
			}

			break;
		}
		case WM_CLIENT_CHATTING:
		{
			CString Chatting;
			Chatting.Format(_T("%s : %s"), UserMsgID, UserMsg2);
			BV->m_ChatList.InsertString(-1, Chatting);						 // 채팅 List에 추가하기
			BV->m_ChatList.SetCurSel(BV->m_ChatList.GetCount() - 1);
			break;
		}
		}
	}

	CSocket::OnReceive(nErrorCode);
}


void ClientSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	this->ShutDown();
	this->Close();

	CSocket::OnClose(nErrorCode);
}
