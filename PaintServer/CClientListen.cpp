// CClientListen.cpp: 구현 파일
//

#include "pch.h"
#include "PaintServer.h"
#include "CClientListen.h"


// CClientListen

CClientListen::CClientListen()
{
}

CClientListen::~CClientListen()
{
}

void CClientListen::SetListen(CAsyncSocket* Listen) { m_ListenSocket = Listen; }


// CClientListen 멤버 함수


void CClientListen::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CAsyncSocket::OnReceive(nErrorCode);

	CString strIPAddress(_T("")); // Client ip주소
	UINT uPortNum(0);			  // Client port Number
	TCHAR strTemp[1024];		  // Client Message
	ZeroMemory(strTemp, sizeof(strTemp));
	CString MsgCode(_T(""));				  // Client Message Code
	CString MsgID(_T(""));		  // Client Message ID
	CString MsgText(_T(""));	  // Client Message Text
	CPaintServerDlg* pMainDlg = (CPaintServerDlg*)AfxGetMainWnd();
	CListenServer* ServerSocket = (CListenServer*)m_ListenSocket; // ListenSocket 얻어오기

	GetPeerName(strIPAddress, uPortNum);
	if (Receive(strTemp, sizeof(strTemp)) > 0)
	{
		AfxExtractSubString(MsgCode, strTemp, 0, '\t');
		AfxExtractSubString(MsgID, strTemp, 1, '\t');
		AfxExtractSubString(MsgText, strTemp, 2,'\t');

		switch (_ttoi(MsgCode))
		{
		case WM_CLIENT_LOGIN: // 로그인 했을때
		{
			if (pMainDlg->pCon->CorrectID(MsgID, MsgText/*PassWord*/))
			{
				/*Client 정보 저장*/
				ThisID = MsgID;									// ID
				ThisName = pMainDlg->pCon->WhatName(MsgID);		// 이름
				ThisLevel = pMainDlg->pCon->WhatLevel(MsgID);	// Level
				ThisPoint = pMainDlg->pCon->WhatPoint(MsgID);	// Point

				/*Server UserList에 추가하기*/
				pMainDlg->m_UserList.InsertItem(pMainDlg->column, ThisID);
				pMainDlg->m_UserList.SetItem(pMainDlg->column, 1, LVIF_TEXT, ThisName, 0, 0, 0, NULL);
				pMainDlg->column += 1;
				
				/*이미 접속해있는지 확인*/
				for (int i = 0; i < 6; i++)
				{
					if (ServerSocket->Player[i].ID == ThisName)
					{
						AfxMessageBox(_T("이미 접속 중 입니다."));
						return;
					}
				}

				/*Player 배열에 추가하기*/
				for (int i = 0; i < 6; i++)
				{
					if (ServerSocket->Player[i].ID == _T(""))
					{
						ServerSocket->Player[i].ID = ThisID;
						ServerSocket->Player[i].LEVEL = ThisLevel;
						ServerSocket->Player[i].POINT = ThisPoint;
						ArrayNumber = i;
					}
				}

				/*전체 Client에 JOINGAME Message Send하기*/
				CString LevelPoint(_T(""));
				LevelPoint.Format(_T("%s;%s"), ThisLevel, ThisPoint);

				CString ServerToClientMsg;
				ServerToClientMsg.Format(_T("%d\t%s\t%s"), WM_CLIENT_JOINGAME, MsgID, LevelPoint);

				ServerSocket->SendAllMessage(ServerToClientMsg);
			}
			else
			{
				AfxMessageBox(_T("아이디 및 비밀번호가 틀렸습니다."));
				return;
			}
			break;
		}

		case WM_CLIENT_JOIN:
		{
			CString PW = _T("");
			CString NAME = _T("");
			CString BIRTH = _T("");
			CString PHONE = _T("");
			CString ADDRESS = _T("");
			CString GENDER = _T("");
			CString MAIL = _T("");

			AfxMessageBox(MsgText);

			AfxExtractSubString(PW, MsgText, 0, ';');
			AfxExtractSubString(NAME, MsgText, 1, ';');
			AfxExtractSubString(BIRTH, MsgText, 2, ';');
			AfxExtractSubString(PHONE, MsgText, 3, ';');
			AfxExtractSubString(ADDRESS, MsgText, 4, ';');
			AfxExtractSubString(GENDER, MsgText, 5, ';');
			AfxExtractSubString(MAIL, MsgText, 6, ';');

			pMainDlg->pCon->InsertData(MsgID, PW, NAME, BIRTH, PHONE, ADDRESS, GENDER, MAIL);
			
			break;
		}

		case WM_CLIENT_IDCHECK:
		{
			if (pMainDlg->pCon->CanUseID(MsgID)) // CanUseID : TRUE
			{
				CString CanUseIDMsg(_T(""));
				CanUseIDMsg.Format(_T("%d\t%s\t%s"), WM_CLIENT_IDCHECK, MsgID, _T("TRUE"));
#ifdef _UNICODE
				this->Send(CanUseIDMsg, CanUseIDMsg.GetLength() * 2);
#else
				this->Send(CanUseIDMsg, CanUseIDMsg.GetLength());
#endif
			}
			else // CanUseID : FALSE
			{
				CString CanNotUseID(_T(""));
				CanNotUseID.Format(_T("%d\t%s\t%s"), WM_CLIENT_IDCHECK, MsgID, _T("FALSE"));
#ifdef _UNICODE
				this->Send(CanNotUseID, CanNotUseID.GetLength() * 2);
#else
				this->Send(CanNotUseID, CanNotUseID.GetLength());
#endif
			}
			break;
		}

		case WM_CLIENT_LOGOUT:
		{
			/*User List 내 정보 삭제*/
			int index = pMainDlg->m_UserList.GetItemCount();
			for (int i = 0; i < index; i++)
			{
				if (MsgID == pMainDlg->m_UserList.GetItemText(i, 0))
				{
					pMainDlg->m_UserList.DeleteItem(i);
				}
			}

			/*Player Array내 정보 삭제하기*/
			for (int i = 0; i < 6; i++)
			{
				if (ServerSocket->Player[i].ID == ThisID)
				{
					ServerSocket->Player[i].ID = _T("");
					ServerSocket->Player[i].LEVEL = _T("");
					ServerSocket->Player[i].POINT = _T("");
				}
			}

			/*로그아웃 정보를 모든 Client에 Send하기 (Client View내 정보 삭제를 위해)*/
			CString ServerToClient(_T(""));
			ServerToClient.Format(_T("%d\t%s\t%s"), WM_CLIENT_LOGOUT, MsgID, _T("LogOut"));
			AfxMessageBox(ServerToClient);
			ServerSocket->SendAllMessage(ServerToClient);
			
			/*접속중인 Client List내 정보 삭제하기*/
			ServerSocket->DeleteClient(this);

		}
			break;
		case WM_CLIENT_CHATTING:
		{
			CString ServerChatting(_T(""));
			ServerChatting.Format(_T("%s : %s"), MsgID, MsgText);
			pMainDlg->m_UserChatting.InsertString(-1, ServerChatting);

			CString ServerToClient(_T(""));
			ServerToClient.Format(_T("%d\t%s\t%s"), WM_CLIENT_CHATTING, MsgID, MsgText);
			AfxMessageBox(ServerToClient);
			ServerSocket->SendAllMessage(ServerToClient);
			break;
		}
		}
	}
}


void CClientListen::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CAsyncSocket::OnClose(nErrorCode);

	CListenServer* ServerSocket = (CListenServer*)m_ListenSocket;

	/*Listen Player Array 저장된 Client 정보 제거*/
	ServerSocket->Player[ArrayNumber].ID = _T("");
	ServerSocket->Player[ArrayNumber].LEVEL = _T("");
	ServerSocket->Player[ArrayNumber].POINT = _T("");

	ServerSocket->DeleteClient(this);
}