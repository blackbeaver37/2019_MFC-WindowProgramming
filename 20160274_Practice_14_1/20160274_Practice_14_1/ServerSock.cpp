#include "stdafx.h"
#include "ServerSock.h"
#include "20160274_Practice_14_1.h"


CServerSock::CServerSock()
{
}


CServerSock::~CServerSock()
{
}


void CServerSock::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	((CMy20160274_Practice_14_1App*)AfxGetApp())->Accept();

	CAsyncSocket::OnAccept(nErrorCode);
}
