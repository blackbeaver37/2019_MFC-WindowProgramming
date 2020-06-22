
// 20160274_Practice_12_1View.h : CMy20160274_Practice_12_1View Ŭ������ �������̽�
//

#pragma once
#include "DataSet.h"
#include "resource.h"

#define MOVE_FIRST_RECORD	1
#define MOVE_PREV_RECORD	2
#define MOVE_NEXT_RECORD	3
#define MOVE_LAST_RECORD	4
#define ADD_READY			5
#define ADD_OK				6
#define SEEK_READY			7
#define SEEK_FREE			8


class CMy20160274_Practice_12_1View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CMy20160274_Practice_12_1View();
	DECLARE_DYNCREATE(CMy20160274_Practice_12_1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY20160274_PRACTICE_12_1_FORM };
#endif

// Ư���Դϴ�.
public:
	CMy20160274_Practice_12_1Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CMy20160274_Practice_12_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CDataSet m_dbSet;
	DbCommand m_command;
	bool m_bMoveRecord;
	int m_nTotal;
	int m_nMoveCount;
	afx_msg void OnFirstRecord();
	afx_msg void OnPrevRecord();
	afx_msg void OnNextRecord();
	afx_msg void OnLastRecord();
	void GetDataFromDb(int nMoveRecord);
	CString m_strBook;
	CString m_strCheckOut;
	CString m_strHakbun;
	CString m_strMajor;
	CString m_strName;
	CString m_strReturn;
	afx_msg void OnClickedButtonAdd();
	int m_nAddMode;
	afx_msg void OnClickedButtonModify();
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnSelchangeComboSeekby();
	int m_nSelectedItem;
	CString m_strSeekText;
	afx_msg void OnClickedButtonSeek();
	int m_nSeekMode;
};

#ifndef _DEBUG  // 20160274_Practice_12_1View.cpp�� ����� ����
inline CMy20160274_Practice_12_1Doc* CMy20160274_Practice_12_1View::GetDocument() const
   { return reinterpret_cast<CMy20160274_Practice_12_1Doc*>(m_pDocument); }
#endif

