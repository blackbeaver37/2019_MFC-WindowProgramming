
// 20160274_Practice_10_3View.h : CMy20160274_Practice_10_3View Ŭ������ �������̽�
//

#pragma once


class CMy20160274_Practice_10_3View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CMy20160274_Practice_10_3View();
	DECLARE_DYNCREATE(CMy20160274_Practice_10_3View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY20160274_PRACTICE_10_3_FORM };
#endif

// Ư���Դϴ�.
public:
	CMy20160274_Practice_10_3Doc* GetDocument() const;

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
	virtual ~CMy20160274_Practice_10_3View();
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
	CString m_strInput;
	afx_msg void OnClickedButtonSave();
};

#ifndef _DEBUG  // 20160274_Practice_10_3View.cpp�� ����� ����
inline CMy20160274_Practice_10_3Doc* CMy20160274_Practice_10_3View::GetDocument() const
   { return reinterpret_cast<CMy20160274_Practice_10_3Doc*>(m_pDocument); }
#endif

