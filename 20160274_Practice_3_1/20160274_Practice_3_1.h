
// 20160274_Practice_3_1.h : 20160274_Practice_3_1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy20160274_Practice_3_1App:
// �� Ŭ������ ������ ���ؼ��� 20160274_Practice_3_1.cpp�� �����Ͻʽÿ�.
//

class CMy20160274_Practice_3_1App : public CWinAppEx
{
public:
	CMy20160274_Practice_3_1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy20160274_Practice_3_1App theApp;
