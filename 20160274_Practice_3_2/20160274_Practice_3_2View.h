
// 20160274_Practice_3_2View.h : CMy20160274_Practice_3_2View Ŭ������ �������̽�
//

#pragma once


class CMy20160274_Practice_3_2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy20160274_Practice_3_2View();
	DECLARE_DYNCREATE(CMy20160274_Practice_3_2View)

// Ư���Դϴ�.
public:
	CMy20160274_Practice_3_2Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMy20160274_Practice_3_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	bool m_bTimerRun;
	bool m_bTimerType;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CString m_strTimer;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // 20160274_Practice_3_2View.cpp�� ����� ����
inline CMy20160274_Practice_3_2Doc* CMy20160274_Practice_3_2View::GetDocument() const
   { return reinterpret_cast<CMy20160274_Practice_3_2Doc*>(m_pDocument); }
#endif

