
// 20160274_Practice_2_2View.cpp : CMy20160274_Practice_2_2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20160274_Practice_2_2.h"
#endif

#include "20160274_Practice_2_2Doc.h"
#include "20160274_Practice_2_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20160274_Practice_2_2View

IMPLEMENT_DYNCREATE(CMy20160274_Practice_2_2View, CView)

BEGIN_MESSAGE_MAP(CMy20160274_Practice_2_2View, CView)
	// ǥ�� �μ� �����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20160274_Practice_2_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy20160274_Practice_2_2View ����/�Ҹ�

CMy20160274_Practice_2_2View::CMy20160274_Practice_2_2View()
	: m_strWindowSize(_T(""))
	, m_strOutput(_T(""))
	, m_bDrag(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20160274_Practice_2_2View::~CMy20160274_Practice_2_2View()
{
}

BOOL CMy20160274_Practice_2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20160274_Practice_2_2View �׸���

void CMy20160274_Practice_2_2View::OnDraw(CDC* pDC)			// �ּ�ó�� ����
{
	CMy20160274_Practice_2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	// ������ ũ�⸦ ��Ÿ���� ���ڿ��� ������ ���� ���(10, 10)�� ���
	pDC->TextOut(10, 10, m_strWindowSize);
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strOutput, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CMy20160274_Practice_2_2View �μ�


void CMy20160274_Practice_2_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20160274_Practice_2_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20160274_Practice_2_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20160274_Practice_2_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy20160274_Practice_2_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20160274_Practice_2_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20160274_Practice_2_2View ����

#ifdef _DEBUG
void CMy20160274_Practice_2_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20160274_Practice_2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20160274_Practice_2_2Doc* CMy20160274_Practice_2_2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20160274_Practice_2_2Doc)));
	return (CMy20160274_Practice_2_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20160274_Practice_2_2View �޽��� ó����


void CMy20160274_Practice_2_2View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// ������ ũ�Ⱑ ����� �� ������ ũ�⸦ ��Ÿ���� ���ڿ� ����
	m_strWindowSize.Format(_T("������ ũ��� ���� %d, ���� %d�Դϴ�."), cx, cy);
	// ȭ�� ����
	Invalidate();
}


void CMy20160274_Practice_2_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_bDrag = TRUE;
	m_strOutput = _T("���� ���콺 ��ư�� �������ϴ�.");
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CMy20160274_Practice_2_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_strOutput = _T("������ ���콺 ��ư�� �������ϴ�.");
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


void CMy20160274_Practice_2_2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	m_strOutput = _T("Ű���带 �������ϴ�.");
	Invalidate();
}


void CMy20160274_Practice_2_2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	if (m_bDrag == TRUE)							// ���콺�� Ŭ���� �����϶�
	{
		m_strOutput = _T("���콺�� �巡���ϰ� �ֽ��ϴ�.");
	}
	else											// ���콺�� Ŭ������ ���� ������ ��
	{
		m_strOutput = _T("���콺�� �̵� �� �Դϴ�.");
	}
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMy20160274_Practice_2_2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_bDrag = FALSE;

	CView::OnLButtonUp(nFlags, point);
}