
// 20160274_Practice_7_1Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CMy20160274_Practice_7_1Dlg ��ȭ ����
class CMy20160274_Practice_7_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy20160274_Practice_7_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20160274_PRACTICE_7_1_DIALOG };
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
	CListCtrl m_listStudent;
//	CString m_strSelectedItem;
	CString m_strName;
	CString m_strSelectedItem;
	CString m_strID;
	CString m_strDept;
	afx_msg void OnClickedButtonInsert();
	int m_nSelectedItem;
	afx_msg void OnItemchangedListStudent(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedButtonModify();
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnClickedButtonReset();
	afx_msg void OnSelchangeComboStyle();
};
