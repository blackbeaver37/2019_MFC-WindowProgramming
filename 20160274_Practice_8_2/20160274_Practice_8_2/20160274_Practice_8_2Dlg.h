
// 20160274_Practice_8_2Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxdtctl.h"
#include "afxwin.h"


// CMy20160274_Practice_8_2Dlg ��ȭ ����
class CMy20160274_Practice_8_2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy20160274_Practice_8_2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY20160274_PRACTICE_8_2_DIALOG };
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
	int m_nTransmitRate;
	CIPAddressCtrl m_addrSenderIP;
	CIPAddressCtrl m_addrReceiver;
	CProgressCtrl m_prgsTransmit;
	CDateTimeCtrl m_timeTransmit;
	int m_nData;
	CEdit m_edSummary;
	CSpinButtonCtrl m_spinData;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedButtonTransmit();
};
