
// 20160274_Practice_9_1Dlg.h : ��� ����
//

#pragma once
#include "afxcolorbutton.h"
#include "afxfontcombobox.h"
#include "afxpropertygridctrl.h"
#include "NCardListBox.h"

typedef struct NameCard
{
	CString strCompany;
	CString strTitle;
	CString strName;
	CString strTelephone;
	CString strMobile;
	CString strEMail;
}NameCard;

// CMy20160274_Practice_9_1Dlg ��ȭ ����
class CMy20160274_Practice_9_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy20160274_Practice_9_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20160274_PRACTICE_9_1_DIALOG };
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
	NameCard m_pNameCards[20];
	int m_nCount;
	int m_nSelectedCard;
	void AddNameCard(CString strName);
	void SelectNameCard(int nIndex);
	void DeleteNameCard(int nIndex);
	CMFCColorButton m_cbtnBackgnd;
	CMFCColorButton m_cbtnText;
	CMFCFontComboBox m_fcbText;
//	CMFCPropertyGridCtrl m_pgCardInfo;
	CNCardListBox m_listNameCard;
	CMFCPropertyGridCtrl m_pgCardInfo;
	void InitializePropGrid(NameCard card);
	void DrawNameCard(NameCard card);

	afx_msg LRESULT OnPropertyChanged(WPARAM wParam, LPARAM lParam);
	afx_msg void OnClickedMfccolorbuttonBackgnd();
	afx_msg void OnClickedMfccolorbuttonText();
	afx_msg void OnSelchangeMfcfontcomboText();
};
