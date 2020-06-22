
// 20160274_Practice_13_1View.cpp : CMy20160274_Practice_13_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20160274_Practice_13_1.h"
#endif

#include "20160274_Practice_13_1Doc.h"
#include "20160274_Practice_13_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20160274_Practice_13_1View

IMPLEMENT_DYNCREATE(CMy20160274_Practice_13_1View, CView)

BEGIN_MESSAGE_MAP(CMy20160274_Practice_13_1View, CView)
	// ǥ�� �μ� �����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20160274_Practice_13_1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_DRAW_BEZIER, &CMy20160274_Practice_13_1View::OnDrawBezier)
	ON_COMMAND(ID_VIEW_POLYGON, &CMy20160274_Practice_13_1View::OnViewPolygon)
	ON_UPDATE_COMMAND_UI(ID_VIEW_POLYGON, &CMy20160274_Practice_13_1View::OnUpdateViewPolygon)
	ON_COMMAND(ID_VIEW_CURVE, &CMy20160274_Practice_13_1View::OnViewCurve)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CURVE, &CMy20160274_Practice_13_1View::OnUpdateViewCurve)
	ON_COMMAND(ID_CURVE_RES_8, &CMy20160274_Practice_13_1View::OnCurveRes8)
	ON_COMMAND(ID_CURVE_RES_16, &CMy20160274_Practice_13_1View::OnCurveRes16)
	ON_COMMAND(ID_CURVE_RES_32, &CMy20160274_Practice_13_1View::OnCurveRes32)
	ON_COMMAND(ID_SELECT_POINT, &CMy20160274_Practice_13_1View::OnSelectPoint)
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy20160274_Practice_13_1View ����/�Ҹ�

CMy20160274_Practice_13_1View::CMy20160274_Practice_13_1View()
	: m_nMode(0)
	, m_bStart(false)
	, m_ptOrigin(0)
	, m_ptPrev(0)
	, m_bVisiblePolygon(false)
	, m_bVisibleCurve(false)
	, m_nCtrlPointNum(0)
	, m_nResolution(0)
	, m_bSelectedPoint(false)
	, m_nSelectedPointIndex(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_nCtrlPointNum = 0;
	m_colorPolygon = RGB(200, 200, 200);	// ��Ʈ�� �������� ���� - ���� ȸ��
	m_colorCurve = RGB(255, 0, 0);			// ������ ��� ���� ���� - ������
	m_colorPoint = RGB(0, 0, 255);			// ��Ʈ�� ����Ʈ�� ���� - �Ķ���
	m_bStart = FALSE;
	m_nMode = NONE_MODE;					// ���α׷� ��带 �ʱ� ���·� ����

	m_bVisiblePolygon = TRUE;				// ��Ʈ�� �������� ���̵��� ����
	m_bVisibleCurve = TRUE;					// ������ ��� ���̵��� ����

	for(int i=0; i<50; i++)					// ��Ʈ�� ����Ʈ�� ��ǥ �迭 �ʱ�ȭ
		m_ptControl[i] = 0;

	m_nResolution = 16;
	m_bSelectedPoint = FALSE;
}

CMy20160274_Practice_13_1View::~CMy20160274_Practice_13_1View()
{
}

BOOL CMy20160274_Practice_13_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20160274_Practice_13_1View �׸���

void CMy20160274_Practice_13_1View::OnDraw(CDC* pDC)		// �ּ� ����
{
	CMy20160274_Practice_13_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	DrawControlPolygon(pDC, m_bVisiblePolygon);
	DrawBezierCurve(pDC, m_bVisibleCurve);
}


// CMy20160274_Practice_13_1View �μ�


void CMy20160274_Practice_13_1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20160274_Practice_13_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20160274_Practice_13_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20160274_Practice_13_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy20160274_Practice_13_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20160274_Practice_13_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
//	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20160274_Practice_13_1View ����

#ifdef _DEBUG
void CMy20160274_Practice_13_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20160274_Practice_13_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20160274_Practice_13_1Doc* CMy20160274_Practice_13_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20160274_Practice_13_1Doc)));
	return (CMy20160274_Practice_13_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20160274_Practice_13_1View �޽��� ó����


void CMy20160274_Practice_13_1View::DrawControlPolygon(CDC* pDC, bool bDrawLine)
{
	CRect rectPoint;
	CPen CtrlPointPen, PolygonPen, *OldPen;

	CtrlPointPen.CreatePen(PS_SOLID, 3, m_colorPoint);
	PolygonPen.CreatePen(PS_SOLID, 1, m_colorPolygon);
	OldPen = pDC->SelectObject(&CtrlPointPen);

	if (bDrawLine)
	{
		for(int i=0; i<m_nCtrlPointNum; i++)
		{
			rectPoint = CRect(m_ptControl[i].x-4, m_ptControl[i].y-4, m_ptControl[i].x+4, m_ptControl[i].y+4);
			pDC->SelectObject(&CtrlPointPen);
			pDC->Ellipse(&rectPoint);
		}
		pDC->SelectObject(&PolygonPen);
		pDC->Polyline(m_ptControl, m_nCtrlPointNum);
	}
	pDC->SelectObject(OldPen);
	DeleteObject(CtrlPointPen);
	DeleteObject(PolygonPen);
}


CPoint CMy20160274_Practice_13_1View::ComputeCurvePoint(int nDegree, CPoint AryCtrlPoint[], float fDelta)
{
	CPoint fAryCtrlPoint[30];

	float fDelta_T;
	fDelta_T = 1.0f - fDelta;

	for (int i = 0; i <= nDegree; i++)
	{
		fAryCtrlPoint[i] = AryCtrlPoint[i];
	}

	for (int r = 1; r <= nDegree; r++)
	{
		for (int i = 0; i <= nDegree-r; i++)
		{
			fAryCtrlPoint[i].x = (int)(fDelta_T * (float)fAryCtrlPoint[i].x + fDelta * (float)fAryCtrlPoint[i+1].x);
			fAryCtrlPoint[i].y = (int)(fDelta_T * (float)fAryCtrlPoint[i].y + fDelta * (float)fAryCtrlPoint[i+1].y);
		}
	}

	return fAryCtrlPoint[0];
}


void CMy20160274_Practice_13_1View::CreateCurvePoint(int nDegree, int nPointNum, CPoint ptControl[], CPoint ptCurve[])
{
	float fDelta, t;

	fDelta = 1.0f/(float)(nPointNum);
	t = 0.0f;
	for (int i = 0; i <= nPointNum; i++)
	{
		ptCurve[i] = ComputeCurvePoint(nDegree, ptControl, t);
		t = t + fDelta;
	}
}


void CMy20160274_Practice_13_1View::DrawBezierCurve(CDC* pDC, bool bLine)
{
	CPen CurvePen, *OldPen;
	CurvePen.CreatePen(PS_SOLID, 1, m_colorCurve);
	OldPen = pDC->SelectObject(&CurvePen);

	if (m_nCtrlPointNum>1)
	{
		// �Ű� ������ 20�� m_nResolution���� ����
		CreateCurvePoint(m_nCtrlPointNum-1, m_nResolution, m_ptControl, m_ptCurve);

		if (bLine)
		{
			// �Ű� ������ 21�� m_nResolution+1 �� ����
			pDC->Polyline(m_ptCurve, m_nResolution+1);
		}
	}

	pDC->SelectObject(OldPen);
	DeleteObject(CurvePen);
}


void CMy20160274_Practice_13_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_nMode == DRAW_MODE)				// ���� �׸��� ����̸�
	{
		// �ٽ� �׸��� �Ǵ� ó�� �׸��� ��� : �ʱ�ȭ
		if (m_bStart == FALSE)
		{
			m_nCtrlPointNum = 0;
			for(int i=0; i<50; i++)
				m_ptControl[i] = 0;
			Invalidate();					// �並 �����Ѵ�.
		}
		CRect rectPoint(point.x - 4, point.y -4, point.x + 4, point.y + 4);

		// ������ ������ ��Ʈ�� ����Ʈ�� �׸���.
		CClientDC dc(this);
		CPen NewPen, *OldPen;
		NewPen.CreatePen(PS_SOLID, 3, m_colorPoint);
		OldPen = dc.SelectObject(&NewPen);
		dc.Ellipse(&rectPoint);
		dc.SelectObject(OldPen);
		DeleteObject(NewPen);

		m_ptOrigin = m_ptPrev = point;			// ������� ������ ���� �ӽ� ����
		m_ptControl[m_nCtrlPointNum++] = point;	// ���� ��ǥ ���� �迭�� ����

		// ���콺 ĸ��
		SetCapture();
		RECT rectClient;
		GetClientRect(&rectClient);
		ClientToScreen(&rectClient);
		// ���콺 �̵� ������ Ŭ���̾�Ʈ �������� ����
		::ClipCursor(&rectClient);
		m_bStart = TRUE;						// ���� �׸��� ���������� ����
	}

	if (m_nMode == MOVE_MODE)					// ���� ���� ���� �� �̵� ����̸�
	{
		// �ݺ����� ���� �迭 �ȿ� ���� ��ǥ�� �˻��Ѵ�.
		for (int i = 0; i < m_nCtrlPointNum; i++)
		{
			// �� ��ǥ�κ��� ���� ������ �����Ѵ�.(�簢�� ����ü)
			CRect rectPoint(m_ptControl[i].x - 4, m_ptControl[i].y - 4,
				m_ptControl[i].x + 4, m_ptControl[i].y + 4);

			// ������ ������ �簢�� ������ ���� �ִٸ�
			if (rectPoint.PtInRect(point))
			{
				m_bSelectedPoint = TRUE;		// ���� ���õǾ����� ����
				m_nSelectedPointIndex = i;		// ���õ� ���� �ε����� ����

				// ���콺�� ĸ���ϰ� ���콺 �̵� ������ Ŭ���̾�Ʈ �������� �����Ѵ�.
				SetCapture();
				RECT rectClient;
				GetClientRect(&rectClient);
				ClientToScreen(&rectClient);
				::ClipCursor(&rectClient);
				Invalidate();					// �並 �����Ѵ�.
			}
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CMy20160274_Practice_13_1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	if (m_nMode == DRAW_MODE)					// ���� �׸��� ����̸�
	{
		// ������� ������ ���۵Ǿ�����
		if (m_bStart)
		{
			dc.SetROP2(R2_NOT);
			dc.MoveTo(m_ptOrigin);
			dc.LineTo(m_ptPrev);

			dc.MoveTo(m_ptOrigin);
			dc.LineTo(point);

			m_ptPrev = point;
		}
	}

	if (m_nMode == MOVE_MODE)			// ���� ���� ���� �� �̵� ����̸�
	{
		CRect rectClient;
		GetClientRect(&rectClient);
		// ���� ���콺 ��ư���� ���� ���õǾ��ٸ�
		if (m_bSelectedPoint)
		{
			// ���õ� ���� ��ǥ�� ���� ��ǥ������ ġȯ
			m_ptControl[m_nSelectedPointIndex] = point;
			// ���� ����
			InvalidateRect(&rectClient, TRUE);
		}
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy20160274_Practice_13_1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_nMode == DRAW_MODE)						// ���� �� �׸��� ����̸�
	{
		// ���� ����� ������ ���� PolyBezier()�Լ��� �䱸�ϴ� ���� ������ �����ϸ�
		if (m_nCtrlPointNum > 1)
		{
			if(m_bStart)							// �� �׸��Ⱑ ���۵Ǿ��ٸ�
			{
				// �������� ������ ������ ���� ����
				m_ptControl[m_nCtrlPointNum++] = point;

				// ������ ���� ��Ʈ�� ����Ʈ�� �׸���.
				CRect rectPoint(point.x - 4, point.y - 4, point.x + 4, point.y + 4);
				CClientDC dc(this);
				CPen NewPen, *OldPen;
				NewPen.CreatePen(PS_SOLID, 3, m_colorPoint);
				OldPen = dc.SelectObject(&NewPen);
				dc.Ellipse(&rectPoint);
				dc.SelectObject(OldPen);
				DeleteObject(NewPen);

				// ��� ��Ʈ�ѷ� �������� �׸���.
				DrawControlPolygon(&dc, m_bVisiblePolygon);

				// ������ ��� �ϼ��Ѵ�.
				DrawBezierCurve(&dc, m_bVisibleCurve);
				//dc.PolyBezier(m_PointArray, m_nPointNum);

				// �׸��� �۾��� ���� �����Ѵ�.
				m_bStart = FALSE;
				// ���콺 ĸ�Ŀ� ������ �����Ѵ�.
				::ReleaseCapture();
				::ClipCursor(NULL);
			}
		}
		else
		{
			AfxMessageBox(_T("��� 2�� �̻��� ��Ʈ�� ����Ʈ�� �־�� �մϴ�."));
		}
	}

	CView::OnRButtonDown(nFlags, point);
}


void CMy20160274_Practice_13_1View::OnDrawBezier()
{
	// TODO: ���⿡ ���� ó���� �ڵ带 �߰��մϴ�.
	m_nCtrlPointNum = 0;
	m_bStart = FALSE;

	for(int i=0; i<50; i++)
		m_ptControl[i] = 0;

	m_nMode = DRAW_MODE;
	Invalidate();
}


void CMy20160274_Practice_13_1View::OnViewPolygon()
{
	// TODO: ���⿡ ���� ó���� �ڵ带 �߰��մϴ�.
	m_bVisiblePolygon = !m_bVisiblePolygon;
	Invalidate();
}


void CMy20160274_Practice_13_1View::OnUpdateViewPolygon(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ���� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(m_bVisiblePolygon);
}


void CMy20160274_Practice_13_1View::OnViewCurve()
{
	// TODO: ���⿡ ���� ó���� �ڵ带 �߰��մϴ�.
	m_bVisibleCurve = !m_bVisibleCurve;
	Invalidate();
}


void CMy20160274_Practice_13_1View::OnUpdateViewCurve(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ���� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(m_bVisibleCurve);
}


void CMy20160274_Practice_13_1View::OnCurveRes8()
{
	// TODO: ���⿡ ���� ó���� �ڵ带 �߰��մϴ�.
	m_nResolution = 8;
	Invalidate();
}


void CMy20160274_Practice_13_1View::OnCurveRes16()
{
	// TODO: ���⿡ ���� ó���� �ڵ带 �߰��մϴ�.
	m_nResolution = 16;
	Invalidate();
}


void CMy20160274_Practice_13_1View::OnCurveRes32()
{
	// TODO: ���⿡ ���� ó���� �ڵ带 �߰��մϴ�.
	m_nResolution = 32;
	Invalidate();
}


void CMy20160274_Practice_13_1View::OnSelectPoint()
{
	// TODO: ���⿡ ���� ó���� �ڵ带 �߰��մϴ�.
	m_nMode = MOVE_MODE;
	m_bVisiblePolygon = TRUE;
	Invalidate();
}


void CMy20160274_Practice_13_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	if (m_nMode == MOVE_MODE)					// ���� ���� ���� �� �̵� ����̸�
	{
		// ���� ���� ���õǾ��� �ִٸ�
		if (m_bSelectedPoint)
		{
			// ���õ� ���� ��ǥ�� ���� ��ǥ ������ ġȯ
			m_ptControl[m_nSelectedPointIndex] = point;
			dc.SetROP2(R2_COPYPEN);

			DrawControlPolygon(&dc, m_bVisiblePolygon);	//��Ʈ�� �������� �׸�
			DrawBezierCurve(&dc, m_bVisibleCurve);		// ������ ��� �׸�

			m_bSelectedPoint = FALSE;
			::ReleaseCapture();							// ���콺 ĸ�ĸ� ����
			::ClipCursor(NULL);							// ���콺 Ŭ���� ����
			Invalidate();								// �並 ����
		}
	}

	CView::OnLButtonUp(nFlags, point);
}