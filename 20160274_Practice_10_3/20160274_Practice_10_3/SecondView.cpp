// SecondView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "20160274_Practice_10_3.h"
#include "SecondView.h"
#include "20160274_Practice_10_3Doc.h"


// CSecondView

IMPLEMENT_DYNCREATE(CSecondView, CView)

CSecondView::CSecondView()
{

}

CSecondView::~CSecondView()
{
}

BEGIN_MESSAGE_MAP(CSecondView, CView)
END_MESSAGE_MAP()


// CSecondView �׸����Դϴ�.

void CSecondView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	CMy20160274_Practice_10_3Doc* pDoc2 = (CMy20160274_Practice_10_3Doc*)GetDocument();

	pDC->TextOut(1, 1, pDoc2->m_strSaveInput);
}


// CSecondView �����Դϴ�.

#ifdef _DEBUG
void CSecondView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CSecondView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSecondView �޽��� ó�����Դϴ�.
