
// MainFrm.h : CMainFrame Ŭ������ �������̽�
//

#pragma once

#include "20160274_Practice_10_3Doc.h"			// ��ť��Ʈ Ŭ������ ������� �߰�
#include "20160274_Practice_10_3View.h"			// �� �� Ŭ������ ������� �߰�
#include "SecondView.h"							// �Ϲ� �� Ŭ������ ������� �߰�
#define FIRST_VIEW		1						// �� �信 ���� ��� �� ����
#define SECOND_VIEW		2						// �Ϲ� �信 ���� ��� �� ����

class CMainFrame : public CFrameWndEx
{
	
protected: // serialization������ ��������ϴ�.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:
	CMy20160274_Practice_10_3View *m_pFirstView;		// �ΰ��� �� Ŭ������ ����
	CSecondView *m_pSecondView;							// ��ü�� ����Ѵ�.

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// �����Դϴ�.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ��Ʈ�� ������ ���Ե� ����Դϴ�.
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;

// ������ �޽��� �� �Լ�
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnViewChange();
	int m_nViewFlag;
	void FirstView();
	void SecondView();
};


