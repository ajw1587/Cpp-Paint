// CListenServer.cpp: 구현 파일
//

#include "pch.h"
#include "PaintServer.h"
#include "CListenServer.h"
#include "CClientListen.h"
#include "PaintServerDlg.h"

// CListenServer

CListenServer::CListenServer()
{
	for (int i = 0; i < 6; i++)
	{
		Player[i].ID = _T("");
		Player[i].LEVEL = _T("");
		Player[i].POINT = _T("");
	}
}

CListenServer::~CListenServer()
{
}

// CListenServer 멤버 함수

void CListenServer::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CClientListen* pClient = new CClientListen;
	
	if (Accept(*pClient))
	{
		pClient->SetListen(this);
		m_ClientSocketList.AddTail(pClient);
	}
	else
	{
		delete pClient;
		AfxMessageBox(_T("Failed to Accept Server"));
		TRACE0("Failed to Accept Server");
		return;
	}

	CAsyncSocket::OnAccept(nErrorCode);
}

void CListenServer::DeleteClient(CSocket* pClient)
{
	POSITION pos;
	pos = m_ClientSocketList.Find(pClient);

	if (pos != NULL)
	{
		pClient->ShutDown();
		pClient->Close();
	}
	// Server Client 리스트내 삭제된 Client 찾아서 삭제하기
}

void CListenServer::SendAllMessage(CString Text)
{
	POSITION pos;
	pos = m_ClientSocketList.GetHeadPosition();
	CClientListen* pClient = NULL;
	int Size = 0;

#ifdef _UNICODE
	Size = 2;
#else
	Size = 1;
#endif
	while(pos != NULL)
	{
		pClient = (CClientListen*)m_ClientSocketList.GetNext(pos);
		if (pClient != NULL)
		{
			int Length = pClient->Send(Text, Text.GetLength() * Size);
			CString length;
			length.Format(_T("%d, %d"), Length, Text.GetLength() * Size);
			AfxMessageBox(length);

			if (Length != Text.GetLength() * Size)
			{

				AfxMessageBox(_T("메시지 데이터 손실"));
			}
		}
	}
}