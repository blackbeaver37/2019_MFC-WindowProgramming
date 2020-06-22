
// 20160274_Practice_3_2View.cpp : CMy20160274_Practice_3_2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20160274_Practice_3_2.h"
#endif

#include "20160274_Practice_3_2Doc.h"
#include "20160274_Practice_3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20160274_Practice_3_2View

IMPLEMENT_DYNCREATE(CMy20160274_Practice_3_2View, CView)

BEGIN_MESSAGE_MAP(CMy20160274_Practice_3_2View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
//	ON_WM_LBUTTONDBLCLK()
ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMy20160274_Practice_3_2View ����/�Ҹ�

CMy20160274_Practice_3_2View::CMy20160274_Practice_3_2View()
	: m_bTimerRun(false)
	, m_bTimerType(true)
	, m_strTimer(_T(""))
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy20160274_Practice_3_2View::~CMy20160274_Practice_3_2View()
{
}

BOOL CMy20160274_Practice_3_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy20160274_Practice_3_2View �׸���

void CMy20160274_Practice_3_2View::OnDraw(CDC* pDC)			// �ּ� ó�� ����
{
	CMy20160274_Practice_3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CRect rect;
	GetClientRect(&rect);									// ������ Ŭ���̾�Ʈ ������ ��´�.
	// �������� �߾ӿ� Ÿ�̸Ӹ� ���
	pDC->DrawText(m_strTimer, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CMy20160274_Practice_3_2View �μ�

BOOL CMy20160274_Practice_3_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy20160274_Practice_3_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy20160274_Practice_3_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy20160274_Practice_3_2View ����

#ifdef _DEBUG
void CMy20160274_Practice_3_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy20160274_Practice_3_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy20160274_Practice_3_2Doc* CMy20160274_Practice_3_2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20160274_Practice_3_2Doc)));
	return (CMy20160274_Practice_3_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20160274_Practice_3_2View �޽��� ó����


int CMy20160274_Practice_3_2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	SetTimer(0, 1000, NULL);							// Ÿ�̸� ����
	m_bTimerRun = TRUE;									// Ÿ�̸� ����

	return 0;
}


void CMy20160274_Practice_3_2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int hour;
	CString str;
	CTime timer;									// Ÿ�̸� ���� ����
	timer = CTime::GetCurrentTime();				// ���� �ð��� ����

	if (m_bTimerType)
	{
		m_strTimer.Format(_T("����� %d�� %d�� %d�� %d�� %d�� %d��"),
			timer.GetYear(), timer.GetMonth(), timer.GetDay(),
			timer.GetHour(), timer.GetMinute(), timer.GetSecond());
	}
	else
	{
		hour = timer.GetHour();
		if (hour >= 12)
		{
			str = _T("PM");
			if (hour >= 13)
				hour = hour - 12;
		}
		else
		{
			str = _T("AM");
		}
		m_strTimer.Format(_T("������ %s %d�� %d�� %d��"), str, hour,
			timer.GetMinute(), timer.GetSecond());
	}
	Invalidate();

	CView::OnTimer(nIDEvent);
}


void CMy20160274_Practice_3_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bTimerType)									// ��, ��, ��, ��, ��, �� ���·� ��� ��
	{
		if (AfxMessageBox(_T("��, ��, ��, ���·� ǥ���Ͻðڽ��ϱ�?"),
			MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			m_bTimerType = false;
		}
	}
	else
	{													// ��, ��, �� ���·� ��� ��
		if (AfxMessageBox(_T("��, ��, ��, ��, ��, ��, ���·� ǥ���Ͻðڽ��ϱ�?"),
			MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			m_bTimerType = true;
		}
	}

	CView::OnLButtonDown(nFlags, point);
}


void CMy20160274_Practice_3_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bTimerRun == false)								// Ÿ�̸Ӱ� ���� �� �� �� �޽��� �ڽ� ���
	{
		if (AfxMessageBox(_T("�����нð踦 ���۽�Ű�ڽ��ϱ�?"),
			MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			SetTimer(0, 1000, NULL);						// Ÿ�̸� ����
			m_bTimerRun = TRUE;								// Ÿ�̸� ���� => true
		}
	}
	else                                                    // Ÿ�̸Ӱ� ���� ���� �� �޽��� �ڽ� ���
	{
		if (AfxMessageBox(_T("������ �����нð� ������ ���߰ڽ��ϱ�?"),
			MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			KillTimer(0);									// Ÿ�̸� ����
			m_bTimerRun = false;								// Ÿ�̸� ���� => false
		}
	}

	CView::OnRButtonDown(nFlags, point);
}


void CMy20160274_Practice_3_2View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_bTimerRun)
		KillTimer(0);										// Ÿ�̸� ����
}
