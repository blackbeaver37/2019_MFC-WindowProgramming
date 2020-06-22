
// 20160274_Practice_14_1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.
#include "ServerSock.h"
#include "ClientSock.h"


// CMy20160274_Practice_14_1App:
// �� Ŭ������ ������ ���ؼ��� 20160274_Practice_14_1.cpp�� �����Ͻʽÿ�.
//

class CMy20160274_Practice_14_1App : public CWinApp
{
public:
	CMy20160274_Practice_14_1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public :
	CServerSock* m_pServer;
	CClientSock* m_pClient;
	void InitServer();
	void Accept();
	void CleanUp();
	void Connect(CString strIP);
	void ReceiveData();
	void SendData(CString strData);
	void CloseChild();
};

extern CMy20160274_Practice_14_1App theApp;