#include "stdafx.h"
#include "ClientSock.h"
#include "20160274_Practice_14_1.h"


CClientSock::CClientSock()
{
}


CClientSock::~CClientSock()
{
}


void CClientSock::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	((CMy20160274_Practice_14_1App*)AfxGetApp())->ReceiveData();

	CAsyncSocket::OnReceive(nErrorCode);
}


void CClientSock::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	((CMy20160274_Practice_14_1App*)AfxGetApp())->CloseChild();

	CAsyncSocket::OnClose(nErrorCode);
}
