
// 20160274_Practice_3_1View.h : CMy20160274_Practice_3_1View Ŭ������ �������̽�
//

#pragma once


class CMy20160274_Practice_3_1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy20160274_Practice_3_1View();
	DECLARE_DYNCREATE(CMy20160274_Practice_3_1View)

// Ư���Դϴ�.
public:
	CMy20160274_Practice_3_1Doc* GetDocument() const;

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
	virtual ~CMy20160274_Practice_3_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);		// OnCreate �ڵ鷯 �Լ�
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);	// OnLButtonDblClk �ڵ鷯 �Լ�
	afx_msg void OnDestroy();									// OnDestroy �ڵ鷯 �Լ�
};

#ifndef _DEBUG  // 20160274_Practice_3_1View.cpp�� ����� ����
inline CMy20160274_Practice_3_1Doc* CMy20160274_Practice_3_1View::GetDocument() const
   { return reinterpret_cast<CMy20160274_Practice_3_1Doc*>(m_pDocument); }
#endif

