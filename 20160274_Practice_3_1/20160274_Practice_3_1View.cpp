
// 20160274_Practice_3_1View.cpp : CMy20160274_Practice_3_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20160274_Practice_3_1.h"
#endif

#include "20160274_Practice_3_1Doc.h"
#include "20160274_Practice_3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20160274_Practice_3_1View

IMPLEMENT_DYNCREATE(CMy20160274_Practice_3_1View, CView)

BEGIN_MESSAGE_MAP(CMy20160274_Practice_3_1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()														// WM_CREATE �޽��� ��ũ��
	ON_WM_LBUTTONDBLCLK()												// WM_LBUTTONDBLCLK �޽��� ��ũ��
	ON_WM_DESTROY()														// WM_DESTROY �޽��� ��ũ��
END_MESSAGE_MAP()

// CMy20160274_Practice_3_1View ����/�Ҹ�

CMy20160274_Practice_3_1View::CMy20160274_Practice_3_1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20160274_Practice_3_1View::~CMy20160274_Practice_3_1View()
{
}

BOOL CMy20160274_Practice_3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20160274_Practice_3_1View �׸���

void CMy20160274_Practice_3_1View::OnDraw(CDC* /*pDC*/)
{
	CMy20160274_Practice_3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy20160274_Practice_3_1View �μ�

BOOL CMy20160274_Practice_3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20160274_Practice_3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20160274_Practice_3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy20160274_Practice_3_1View ����

#ifdef _DEBUG
void CMy20160274_Practice_3_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20160274_Practice_3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20160274_Practice_3_1Doc* CMy20160274_Practice_3_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20160274_Practice_3_1Doc)));
	return (CMy20160274_Practice_3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20160274_Practice_3_1View �޽��� ó����


int CMy20160274_Practice_3_1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	/// �����찡 ������ �� �޽��� �ڽ� ���
	AfxMessageBox(_T( "�����찡 �����Ǿ����ϴ�." ),
		MB_OKCANCEL | MB_ICONINFORMATION);


	return 0;
}


void CMy20160274_Practice_3_1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// ���� ���콺�� ���� Ŭ���� �� �޽��� �ڽ� ���
	AfxMessageBox(_T("���� ���콺�� ����Ŭ�� �߽��ϱ�?"),
		MB_YESNO | MB_ICONQUESTION);

	CView::OnLButtonDblClk(nFlags, point);
}


void CMy20160274_Practice_3_1View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �����찡 ����� �� �޽��� �ڽ� ���
	AfxMessageBox(_T("�����찡 ����Ǿ����ϴ�."), MB_YESNO | MB_ICONWARNING);
}
