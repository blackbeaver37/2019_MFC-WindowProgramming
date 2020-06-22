
// 20160274_Practice_10_3View.cpp : CMy20160274_Practice_10_3View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20160274_Practice_10_3.h"
#endif

#include "20160274_Practice_10_3Doc.h"
#include "20160274_Practice_10_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20160274_Practice_10_3View

IMPLEMENT_DYNCREATE(CMy20160274_Practice_10_3View, CFormView)

BEGIN_MESSAGE_MAP(CMy20160274_Practice_10_3View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMy20160274_Practice_10_3View::OnClickedButtonSave)
END_MESSAGE_MAP()

// CMy20160274_Practice_10_3View ����/�Ҹ�

CMy20160274_Practice_10_3View::CMy20160274_Practice_10_3View()
	: CFormView(IDD_MY20160274_PRACTICE_10_3_FORM)
	, m_strInput(_T(""))
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20160274_Practice_10_3View::~CMy20160274_Practice_10_3View()
{
}

void CMy20160274_Practice_10_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strInput);
}

BOOL CMy20160274_Practice_10_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CMy20160274_Practice_10_3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

void CMy20160274_Practice_10_3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20160274_Practice_10_3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20160274_Practice_10_3View ����

#ifdef _DEBUG
void CMy20160274_Practice_10_3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy20160274_Practice_10_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy20160274_Practice_10_3Doc* CMy20160274_Practice_10_3View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20160274_Practice_10_3Doc)));
	return (CMy20160274_Practice_10_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20160274_Practice_10_3View �޽��� ó����


void CMy20160274_Practice_10_3View::OnClickedButtonSave()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CMy20160274_Practice_10_3Doc* pDoc = GetDocument();

	UpdateData(TRUE);
	pDoc->m_strSaveInput = m_strInput;
}
