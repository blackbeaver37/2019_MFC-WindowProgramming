
// 20160274_Practice_5_4.h : 20160274_Practice_5_4 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy20160274_Practice_5_4App:
// �� Ŭ������ ������ ���ؼ��� 20160274_Practice_5_4.cpp�� �����Ͻʽÿ�.
//

class CMy20160274_Practice_5_4App : public CWinAppEx
{
public:
	CMy20160274_Practice_5_4App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy20160274_Practice_5_4App theApp;
