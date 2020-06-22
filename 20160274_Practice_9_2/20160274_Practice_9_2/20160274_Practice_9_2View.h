// �� MFC ���� �ҽ� �ڵ�� MFC Microsoft Office Fluent ����� �������̽�("Fluent UI")�� 
// ����ϴ� ����� ���� �ָ�, MFC C++ ���̺귯�� ����Ʈ��� ���Ե� 
// Microsoft Foundation Classes Reference �� ���� ���� ������ ���� 
// �߰������� �����Ǵ� �����Դϴ�.  
// Fluent UI�� ����, ��� �Ǵ� �����ϴ� �� ���� ��� ����� ������ �����˴ϴ�.  
// Fluent UI ���̼��� ���α׷��� ���� �ڼ��� ������ 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// 20160274_Practice_9_2View.h : CMy20160274_Practice_9_2View Ŭ������ �������̽�
//

#pragma once
#include "atltypes.h"


class CMy20160274_Practice_9_2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy20160274_Practice_9_2View();
	DECLARE_DYNCREATE(CMy20160274_Practice_9_2View)

// Ư���Դϴ�.
public:
	CMy20160274_Practice_9_2Doc* GetDocument() const;

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
	virtual ~CMy20160274_Practice_9_2View();
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
	CPoint m_ptPoints[20];
	int m_nCount;
	CString m_strText;
	int m_nObjectType;
	bool m_bDrawing;
	CPoint m_ptPrev;
	LOGFONT m_lfFont;
	COLORREF m_colorLine;
	COLORREF m_colorFill;
	COLORREF m_colorText;
	float m_fZoom;
	bool m_bViewPoints;
	void DrawEllipse(CDC* pDC);
	void DrawPolygon(CDC* pDC);
	void ResetZoom();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 20160274_Practice_9_2View.cpp�� ����� ����
inline CMy20160274_Practice_9_2Doc* CMy20160274_Practice_9_2View::GetDocument() const
   { return reinterpret_cast<CMy20160274_Practice_9_2Doc*>(m_pDocument); }
#endif

