
// 20160274_Practice_10_1View.cpp : CMy20160274_Practice_10_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20160274_Practice_10_1.h"
#endif

#include "20160274_Practice_10_1Doc.h"
#include "20160274_Practice_10_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20160274_Practice_10_1View

IMPLEMENT_DYNCREATE(CMy20160274_Practice_10_1View, CFormView)

BEGIN_MESSAGE_MAP(CMy20160274_Practice_10_1View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON_OUTPUT, &CMy20160274_Practice_10_1View::OnClickedButtonOutput)
	ON_BN_CLICKED(IDC_BUTTON_COLOR, &CMy20160274_Practice_10_1View::OnClickedButtonColor)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CMy20160274_Practice_10_1View::OnClickedButtonReset)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_EDIT_RED, &CMy20160274_Practice_10_1View::OnChangeEditRed)
	ON_EN_CHANGE(IDC_EDIT_GREEN, &CMy20160274_Practice_10_1View::OnChangeEditGreen)
	ON_EN_CHANGE(IDC_EDIT_BLUE, &CMy20160274_Practice_10_1View::OnChangeEditBlue)
	ON_EN_CHANGE(IDC_EDIT_TEXT, &CMy20160274_Practice_10_1View::OnChangeEditText)
END_MESSAGE_MAP()

// CMy20160274_Practice_10_1View ����/�Ҹ�

CMy20160274_Practice_10_1View::CMy20160274_Practice_10_1View()
	: CFormView(IDD_MY20160274_PRACTICE_10_1_FORM)
	, m_strText(_T(""))
	, m_nRed(0)
	, m_nGreen(0)
	, m_nBlue(0)
	, m_nX(0)
	, m_nY(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_colorText = RGB(0, 0, 0);
	m_nX = 30;
	m_nY = 270;				// ��ȭ������ ũ��� ��ġ�� ��Ʈ�ѿ� ���� ����� �� �ִ�.
}

CMy20160274_Practice_10_1View::~CMy20160274_Practice_10_1View()
{
}

void CMy20160274_Practice_10_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
	DDX_Text(pDX, IDC_EDIT_RED, m_nRed);
	DDV_MinMaxInt(pDX, m_nRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT_GREEN, m_nGreen);
	DDV_MinMaxInt(pDX, m_nGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT_BLUE, m_nBlue);
	DDV_MinMaxInt(pDX, m_nBlue, 0, 255);
	DDX_Text(pDX, IDC_EDIT_X, m_nX);
	DDX_Text(pDX, IDC_EDIT_Y, m_nY);
	DDX_Control(pDX, IDC_SLIDER_X, m_sliderX);
	DDX_Control(pDX, IDC_SLIDER_Y, m_sliderY);
}

BOOL CMy20160274_Practice_10_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CMy20160274_Practice_10_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_sliderX.SetRange(20, 300);			// ������ ��ȭ������ ũ��� ��Ʈ���� ��ġ�� ����
	m_sliderY.SetRange(260, 500);
	m_sliderX.SetPos(30);
	m_sliderX.SetPos(270);
}

void CMy20160274_Practice_10_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20160274_Practice_10_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20160274_Practice_10_1View ����

#ifdef _DEBUG
void CMy20160274_Practice_10_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy20160274_Practice_10_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy20160274_Practice_10_1Doc* CMy20160274_Practice_10_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20160274_Practice_10_1Doc)));
	return (CMy20160274_Practice_10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20160274_Practice_10_1View �޽��� ó����


void CMy20160274_Practice_10_1View::OnClickedButtonOutput()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);		// �Էµ� ������ ���� �������� ����
	// �߸��� ������ ��� ���� �޽����� ������.
	if (m_nRed > 255 || m_nRed < 0 || m_nGreen>255 || m_nGreen < 0 || m_nBlue>255 || m_nBlue < 0) {
		AfxMessageBox(_T("�߸��� �����Դϴ�."));
	}
	else {
		Invalidate();
	}
}


void CMy20160274_Practice_10_1View::OnClickedButtonColor()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ���� ���̾�α׸� ����.
	CColorDialog colorDlg;
	if (colorDlg.DoModal() == IDOK) {
		m_colorText = colorDlg.GetColor();
	}
	// ������ ��Ÿ���� RGB EditBox�� �� ���� RGB���� �־��ش�.
	m_nRed = GetRValue(m_colorText);
	m_nGreen = GetGValue(m_colorText);
	m_nBlue = GetBValue(m_colorText);

	UpdateData(FALSE);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CMy20160274_Practice_10_1View::OnClickedButtonReset()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_strText.Empty();
	m_nRed = 0;
	m_nGreen = 0;
	m_nBlue = 0;
	m_nX = 0;
	m_nY = 0;
	m_sliderX.SetPos(30);
	m_sliderY.SetPos(270);
	UpdateData(FALSE);
	Invalidate();
	GetDocument()->OnNewDocument();
}


void CMy20160274_Practice_10_1View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int nX = m_sliderX.GetPos();
	int nY = m_sliderY.GetPos();

	if (pScrollBar->GetSafeHwnd() == m_sliderX.m_hWnd)
		m_nX = nX;
	else if (pScrollBar->GetSafeHwnd() == m_sliderY.m_hWnd)
		m_nY = nY;
	else
		return;

	UpdateData(FALSE);
	Invalidate();

	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMy20160274_Practice_10_1View::OnChangeEditRed()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CFormView::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CMy20160274_Practice_10_1View::OnChangeEditGreen()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CFormView::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CMy20160274_Practice_10_1View::OnChangeEditBlue()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CFormView::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CMy20160274_Practice_10_1View::OnChangeEditText()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CFormView::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	GetDocument()->SetModifiedFlag();
}


void CMy20160274_Practice_10_1View::OnDraw(CDC* pDC)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	pDC->SetTextColor(m_colorText);
	pDC->TextOut(m_nX, m_nY, m_strText);
	m_sliderX.SetPos(m_nX);
	m_sliderY.SetPos(m_nY);
}
