
// 20160274_Practice_11_3Dlg.h : ��� ����
//

#pragma once
#include "CalculateRoot.h"


// CMy20160274_Practice_11_3Dlg ��ȭ ����
class CMy20160274_Practice_11_3Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy20160274_Practice_11_3Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20160274_PRACTICE_11_3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit2();
	CCalculateRoot m_calcRoot;
	afx_msg void OnClickedButtonCalcRoot();
	afx_msg void OnClickedButtonClear();
};
