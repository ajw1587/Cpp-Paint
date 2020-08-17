#pragma once

// CListenServer 명령 대상

struct PlayerINFO
{
	CString ID;
	CString LEVEL;
	CString POINT;
};

class CListenServer : public CAsyncSocket
{
public:
	CListenServer();
	virtual ~CListenServer();
	virtual void OnAccept(int nErrorCode);
	void DeleteClient(CSocket* pClient);
	void SendAllMessage(CString Text);
	CPtrList m_ClientSocketList; // 접속중인 Client 리스트
	PlayerINFO Player[6];		 // Player 정보 배열
};