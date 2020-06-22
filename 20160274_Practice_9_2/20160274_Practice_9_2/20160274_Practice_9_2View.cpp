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

// 20160274_Practice_9_2View.cpp : CMy20160274_Practice_9_2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20160274_Practice_9_2.h"
#endif

#include "20160274_Practice_9_2Doc.h"
#include "20160274_Practice_9_2View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20160274_Practice_9_2View

IMPLEMENT_DYNCREATE(CMy20160274_Practice_9_2View, CView)

BEGIN_MESSAGE_MAP(CMy20160274_Practice_9_2View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20160274_Practice_9_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy20160274_Practice_9_2View ����/�Ҹ�

CMy20160274_Practice_9_2View::CMy20160274_Practice_9_2View()
	: m_nCount(0)
	, m_strText(_T(""))
	, m_nObjectType(0)
	, m_bDrawing(false)
	, m_ptPrev(0)
	, m_fZoom(0)
	, m_bViewPoints(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_strText = _T("Hello, MFC Programming!");
	m_nObjectType = -1;

	afxGlobalData.fontRegular.GetLogFont(&m_lfFont);
	m_lfFont.lfHeight = 20;

	m_colorLine = RGB(0, 0, 0);
	m_colorFill = RGB(255, 255, 255);
	m_colorText = RGB(0, 0, 255);
	m_fZoom = 1.0f;
	m_bViewPoints = true;

}

CMy20160274_Practice_9_2View::~CMy20160274_Practice_9_2View()
{
}

BOOL CMy20160274_Practice_9_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20160274_Practice_9_2View �׸���

void CMy20160274_Practice_9_2View::OnDraw(CDC* pDC)
{
	CMy20160274_Practice_9_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CRect rc;
	GetClientRect(&rc);

	CPen pen, *pOldPen;
	CBrush brush, *pOldBrush;
	CFont font, *pOldFont;

	pen.CreatePen(PS_SOLID, 2, m_colorLine);
	brush.CreateSolidBrush(m_colorFill);
	font.CreateFontIndirect(&m_lfFont);

	pOldPen = pDC->SelectObject(&pen);
	pOldBrush = pDC->SelectObject(&brush);
	pOldFont = pDC->SelectObject(&font);

	switch (m_nObjectType)
	{
	case 0:
		DrawEllipse(pDC);			// Ÿ�� �׸���
		break;
	case 1:
		DrawPolygon(pDC);			// �ٰ��� �׸���
		break;
	}

	pDC->SetTextColor(m_colorText);
	pDC->DrawText(m_strText, &rc, DT_VCENTER | DT_CENTER | DT_SINGLELINE);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldFont);

	pen.DeleteObject();
	brush.DeleteObject();
	font.DeleteObject();
}


// CMy20160274_Practice_9_2View �μ�


void CMy20160274_Practice_9_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20160274_Practice_9_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20160274_Practice_9_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20160274_Practice_9_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy20160274_Practice_9_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20160274_Practice_9_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20160274_Practice_9_2View ����

#ifdef _DEBUG
void CMy20160274_Practice_9_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20160274_Practice_9_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20160274_Practice_9_2Doc* CMy20160274_Practice_9_2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20160274_Practice_9_2Doc)));
	return (CMy20160274_Practice_9_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20160274_Practice_9_2View �޽��� ó����


void CMy20160274_Practice_9_2View::DrawEllipse(CDC* pDC)
{
	if (!m_nCount)
		return;

	int x1, y1, x2, y2;
	if (m_nCount < 2) {
		x1 = (int)((float)m_ptPoints[0].x*m_fZoom);
		y1 = (int)((float)m_ptPoints[0].y*m_fZoom);
		if (m_bViewPoints)
			pDC->Ellipse(x1 - 4, y1 - 4, x1 + 4, y1 + 4);
	}
	else {
		x1 = (int)((float)m_ptPoints[0].x*m_fZoom);
		y1 = (int)((float)m_ptPoints[0].y*m_fZoom);
		x2 = (int)((float)m_ptPoints[1].x*m_fZoom);
		y2 = (int)((float)m_ptPoints[1].y*m_fZoom);
		pDC->Ellipse(x1, y1, x2, y2);
		if (m_bViewPoints) {
			pDC->Ellipse(x1 - 4, y1 - 4, x1 + 4, y1 + 4);
			pDC->Ellipse(x2 - 4, y2 - 4, x2 + 4, y2 + 4);
		}
	}
}


void CMy20160274_Practice_9_2View::DrawPolygon(CDC* pDC)
{
	CPoint pPoints[20];
	for (int i = 0; i < m_nCount; i++) {
		pPoints[i].x = (int)((float)m_ptPoints[i].x*m_fZoom);
		pPoints[i].y = (int)((float)m_ptPoints[i].y*m_fZoom);
	}

	// �ٰ��� �׸���
	if (m_bDrawing)
		pDC->Polyline(pPoints, m_nCount);
	else
		pDC->Polygon(pPoints, m_nCount);

	if (m_bViewPoints) {
		for (int i = 0; i < m_nCount; i++)
			pDC->Ellipse(pPoints[i].x - 4, pPoints[i].y - 4, pPoints[i].x + 4, pPoints[i].y + 4);
	}
}


void CMy20160274_Practice_9_2View::ResetZoom()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMFCRibbonSlider* pZoom = DYNAMIC_DOWNCAST(CMFCRibbonSlider, pFrame->GetRibbonBar()->FindByID(ID_SLIDER_ZOOM));
	pZoom->SetPos(100);

	m_fZoom = 1.0f;
	Invalidate();
}


void CMy20160274_Practice_9_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_nObjectType == 0) {
		if (m_nCount == 0 || m_nCount >= 2) {
			ResetZoom();
			m_nCount = 0;
			m_bDrawing = true;
		}
		m_ptPoints[m_nCount++] = point;
		if (m_nCount == 2)
			m_bDrawing = false;

		Invalidate();
	}
	else if (m_nObjectType == 1) {
		if (!m_bDrawing) {
			ResetZoom();
			m_nCount = 0;
			m_bDrawing = true;
		}
		m_ptPoints[m_nCount++] = point;
		Invalidate();
	}
	m_ptPrev = point;

	CView::OnLButtonDown(nFlags, point);
}


void CMy20160274_Practice_9_2View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_nObjectType == 1) {
		if (m_bDrawing)
			m_bDrawing = false;

		Invalidate();
	}

	CView::OnLButtonDblClk(nFlags, point);
}


void CMy20160274_Practice_9_2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_nCount < 1 || !m_bDrawing)
		return;

	CClientDC dc(this);
	switch (m_nObjectType)
	{
	case 0:
		DrawEllipse(&dc);		// Ÿ�� �׸���
		break;
	case 1:
		DrawPolygon(&dc);		// �ٰ��� �׸���
		break;
	}
	dc.SetROP2(R2_NOT);
	dc.MoveTo(m_ptPoints[m_nCount - 1]);
	dc.LineTo(m_ptPrev);

	dc.SetROP2(R2_COPYPEN);
	dc.MoveTo(m_ptPoints[m_nCount - 1]);
	dc.LineTo(point);

	m_ptPrev = point;

	CView::OnMouseMove(nFlags, point);
}
