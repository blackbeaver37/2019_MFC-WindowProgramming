
// 20160274_Practice_5_4View.cpp : CMy20160274_Practice_5_4View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20160274_Practice_5_4.h"
#endif

#include "20160274_Practice_5_4Doc.h"
#include "20160274_Practice_5_4View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20160274_Practice_5_4View

IMPLEMENT_DYNCREATE(CMy20160274_Practice_5_4View, CView)

BEGIN_MESSAGE_MAP(CMy20160274_Practice_5_4View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy20160274_Practice_5_4View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CMy20160274_Practice_5_4View ����/�Ҹ�

CMy20160274_Practice_5_4View::CMy20160274_Practice_5_4View()
	: m_strOutput(_T(""))
	, m_nTextWidth(0)
	, m_nTextHeight(0)
	, m_ptPosition(0)
	, m_bFont(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20160274_Practice_5_4View::~CMy20160274_Practice_5_4View()
{
}

BOOL CMy20160274_Practice_5_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20160274_Practice_5_4View �׸���

void CMy20160274_Practice_5_4View::OnDraw(CDC* pDC)			// �ּ� ó�� ����
{
	CMy20160274_Practice_5_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	// ���� �۲� ������ �����Ѵ�.
	CFont *oldFont, *currentFont, newFont;

	if (m_bFont == TRUE)							// ��Ʈ ��ȭ���ڿ��� ������ �۲��� ���� �۲÷� ����
	{
		newFont.CreateFontIndirect(&m_logFont);
		oldFont = pDC->SelectObject(&newFont);
	}
	else											// ��Ʈ ��ȭ���ڿ��� �۲��� �������� ������ ���� �۲��� ���
	{
		currentFont = pDC->GetCurrentFont();
		oldFont = pDC->SelectObject(currentFont);
	}

	// ���� ��ȭ���ڿ��� ������ ������ �ؽ�Ʈ �������� ����
	pDC->SetTextColor(m_colorText);

	// ������ ��ġ�� ���ڿ� ���
	pDC->TextOut(m_ptPosition.x, m_ptPosition.y, m_strOutput);

	// ��µǴ� ���ڿ��� �ʺ�� ���̸� ����
	CSize sizeText;
	sizeText = pDC->GetTextExtent(m_strOutput);
	m_nTextWidth = sizeText.cx;
	m_nTextHeight = sizeText.cy;

	// �۲��� ����
	pDC->SelectObject(oldFont);
}


// CMy20160274_Practice_5_4View �μ�


void CMy20160274_Practice_5_4View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy20160274_Practice_5_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20160274_Practice_5_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20160274_Practice_5_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMy20160274_Practice_5_4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20160274_Practice_5_4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20160274_Practice_5_4View ����

#ifdef _DEBUG
void CMy20160274_Practice_5_4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20160274_Practice_5_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20160274_Practice_5_4Doc* CMy20160274_Practice_5_4View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20160274_Practice_5_4Doc)));
	return (CMy20160274_Practice_5_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20160274_Practice_5_4View �޽��� ó����


void CMy20160274_Practice_5_4View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (nChar)							// ����Ű �ڵ� ���� ����
	{
	case VK_LEFT:							// ���� ȭ��ǥ Ű�� ���� ��
		m_ptPosition.x -= 10;				// �������� 10 �̵�
		break;
	case VK_RIGHT:							// ������ ȭ��ǥ Ű�� ���� ��
		m_ptPosition.x += 10;				// ���������� 10 �̵�
		break;
	case VK_UP:								// ���� ȭ��ǥ Ű�� ���� ��
		m_ptPosition.y -= 10;				// �������� 10 �̵�
		break;
	case VK_DOWN:							// �Ʒ��� ȭ��ǥ Ű�� ���� ��
		m_ptPosition.y += 10;				// �Ʒ������� 10 �̵�
		break;

	}
	if (m_ptPosition.x < 0)					// ���ڿ��� ���� ��輱�� �����ϸ�
	{
		m_ptPosition.x = 0;					// m_ptPosition.x = 0���� �ʱ�ȭ
		AfxMessageBox(_T("�������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if (m_ptPosition.y < 0)					// ���ڿ��� ���� ��輱�� �����ϸ�
	{
		m_ptPosition.y = 0;					// m_ptPosition.y = 0���� �ʱ�ȭ
		AfxMessageBox(_T("�������� �� �̻� �̵��� �� �����ϴ�."));
	}
	RECT rect;
	GetClientRect(&rect);
	if (m_ptPosition.x > rect.right - m_nTextWidth)		// ���ڿ� ���� ������ ��輱�� �����ϸ�
	{
		m_ptPosition.x = rect.right - m_nTextWidth;
		AfxMessageBox(_T("���������� �� �̻� �̵��� �� �����ϴ�."));
	}
	if (m_ptPosition.y > rect.bottom - m_nTextHeight)	// ���ڿ� ���� �Ʒ��� ��輱�� �����ϸ�
	{
		m_ptPosition.y = rect.bottom - m_nTextHeight;
		AfxMessageBox(_T("�Ʒ������� �� �̻� �̵��� �� �����ϴ�."));
	}
	// ����� ���ڿ��� ��ǥ ���� ��ŷ ���� X, Y Edit Control�� �ݿ��Ѵ�.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->m_paneTextOut.m_ctrlTextOut.SetDlgItemInt(IDC_EDIT_X, m_ptPosition.x);
	pFrame->m_paneTextOut.m_ctrlTextOut.SetDlgItemInt(IDC_EDIT_Y, m_ptPosition.y);
	Invalidate();							// ȭ�� ����

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
