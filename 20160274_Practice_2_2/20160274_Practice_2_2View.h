
// 20160274_Practice_2_2View.h : CMy20160274_Practice_2_2View Ŭ������ �������̽�
//

#pragma once


class CMy20160274_Practice_2_2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy20160274_Practice_2_2View();
	DECLARE_DYNCREATE(CMy20160274_Practice_2_2View)

// Ư���Դϴ�.
public:
	CMy20160274_Practice_2_2Doc* GetDocument() const;

	void OnSize(UINT nType, int cx, int cy);

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
	virtual ~CMy20160274_Practice_2_2View();
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
	CString m_strWindowSize;
	CString m_strOutput;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	bool m_bDrag;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 20160274_Practice_2_2View.cpp�� ����� ����
inline CMy20160274_Practice_2_2Doc* CMy20160274_Practice_2_2View::GetDocument() const
   { return reinterpret_cast<CMy20160274_Practice_2_2Doc*>(m_pDocument); }
#endif
