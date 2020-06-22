
// 20160274_Practice_14_1.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
//

#include "stdafx.h"
#include "20160274_Practice_14_1.h"
#include "20160274_Practice_14_1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20160274_Practice_14_1App

BEGIN_MESSAGE_MAP(CMy20160274_Practice_14_1App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMy20160274_Practice_14_1App ����

CMy20160274_Practice_14_1App::CMy20160274_Practice_14_1App()
	: m_pServer(NULL)
	, m_pClient(NULL)
{
	// �ٽ� ���� ������ ����
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}


// ������ CMy20160274_Practice_14_1App ��ü�Դϴ�.

CMy20160274_Practice_14_1App theApp;


// CMy20160274_Practice_14_1App �ʱ�ȭ

BOOL CMy20160274_Practice_14_1App::InitInstance()
{
	// ���� ���α׷� �Ŵ��佺Ʈ�� ComCtl32.dll ���� 6 �̻��� ����Ͽ� ���־� ��Ÿ����
	// ����ϵ��� �����ϴ� ���, Windows XP �󿡼� �ݵ�� InitCommonControlsEx()�� �ʿ��մϴ�.
	// InitCommonControlsEx()�� ������� ������ â�� ���� �� �����ϴ�.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ���� ���α׷����� ����� ��� ���� ��Ʈ�� Ŭ������ �����ϵ���
	// �� �׸��� �����Ͻʽÿ�.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}


	AfxEnableControlContainer();

	// ��ȭ ���ڿ� �� Ʈ�� �� �Ǵ�
	// �� ��� �� ��Ʈ���� ���ԵǾ� �ִ� ��� �� �����ڸ� ����ϴ�.
	CShellManager *pShellManager = new CShellManager;

	// MFC ��Ʈ���� �׸��� ����ϱ� ���� "Windows ����" ���־� ������ Ȱ��ȭ
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ǥ�� �ʱ�ȭ
	// �̵� ����� ������� �ʰ� ���� ���� ������ ũ�⸦ ���̷���
	// �Ʒ����� �ʿ� ���� Ư�� �ʱ�ȭ
	// ��ƾ�� �����ؾ� �մϴ�.
	// �ش� ������ ����� ������Ʈ�� Ű�� �����Ͻʽÿ�.
	// TODO: �� ���ڿ��� ȸ�� �Ǵ� ������ �̸��� ����
	// ������ �������� �����ؾ� �մϴ�.
	SetRegistryKey(_T("���� ���� ���α׷� �����翡�� ������ ���� ���α׷�"));

	CMy20160274_Practice_14_1Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ���⿡ [Ȯ��]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ���⿡ [���]�� Ŭ���Ͽ� ��ȭ ���ڰ� ������ �� ó����
		//  �ڵ带 ��ġ�մϴ�.
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "���: ��ȭ ���ڸ� ������ �������Ƿ� ���� ���α׷��� ����ġ �ʰ� ����˴ϴ�.\n");
		TRACE(traceAppMsg, 0, "���: ��ȭ ���ڿ��� MFC ��Ʈ���� ����ϴ� ��� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS�� ������ �� �����ϴ�.\n");
	}

	// ������ ���� �� �����ڸ� �����մϴ�.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// ��ȭ ���ڰ� �������Ƿ� ���� ���α׷��� �޽��� ������ �������� �ʰ�  ���� ���α׷��� ���� �� �ֵ��� FALSE��
	// ��ȯ�մϴ�.
	return FALSE;
}



void CMy20160274_Practice_14_1App::InitServer()
{
	m_pServer = new CServerSock;
	m_pServer->Create(7777);
	m_pServer->Listen();
}


void CMy20160274_Practice_14_1App::Accept()
{
	if (m_pClient == NULL)
	{
		m_pClient = new CClientSock;
		m_pServer->Accept(*m_pClient);
		CString strSock;
		UINT nPort;
		m_pClient->GetPeerName(strSock,nPort);
		((CMy20160274_Practice_14_1Dlg*)m_pMainWnd)->Accept(strSock);
	}
}


void CMy20160274_Practice_14_1App::CleanUp()
{
	if(m_pServer)
		delete m_pServer;

	if(m_pClient)
		delete m_pClient;
}


void CMy20160274_Practice_14_1App::Connect(CString strIP)
{
	m_pClient = new CClientSock;
	m_pClient->Create();
	m_pClient->Connect(strIP, 7777);
}


void CMy20160274_Practice_14_1App::ReceiveData()
{
	wchar_t temp[MAX_PATH];
	m_pClient->Receive(temp, sizeof(temp));
	((CMy20160274_Practice_14_1Dlg*)m_pMainWnd)->ReceiveData(temp);
}


void CMy20160274_Practice_14_1App::SendData(CString strData)
{
	if (m_pClient)
	{
		m_pClient->Send((LPCTSTR)strData, sizeof(TCHAR)*(strData.GetLength()+1));
	}
}


void CMy20160274_Practice_14_1App::CloseChild()
{
	AfxMessageBox(_T("���� ���� ����"));
	delete m_pClient;
	m_pClient = NULL;
}
