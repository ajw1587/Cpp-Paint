#pragma once
#include "MainFrm.h"
#include "MFC_Paint_0718Doc.h"
#include "LoginDlg.h"

// ClientSocket 명령 대상

class ClientSocket : public CSocket
{
public:
	ClientSocket();
	virtual ~ClientSocket();
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};


