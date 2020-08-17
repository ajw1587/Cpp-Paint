#pragma once
#include "CListenServer.h"
#include "PaintServerDlg.h"
// CClientListen 명령 대상

class CClientListen : public CSocket
{
public:
	CClientListen();
	virtual ~CClientListen();

	CAsyncSocket* m_ListenSocket;
	void SetListen(CAsyncSocket* Listen);
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);

	/*접속한 유저 정보*/
	CString ThisID;
	CString ThisName;
	CString ThisLevel;
	CString ThisPoint;
	int ArrayNumber;
};