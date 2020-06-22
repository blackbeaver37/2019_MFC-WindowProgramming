
// 20160274_Practice_10_1Doc.cpp : CMy20160274_Practice_10_1Doc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20160274_Practice_10_1.h"
#endif

#include "20160274_Practice_10_1Doc.h"
#include "20160274_Practice_10_1View.h"
#include "MainFrm.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy20160274_Practice_10_1Doc

IMPLEMENT_DYNCREATE(CMy20160274_Practice_10_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy20160274_Practice_10_1Doc, CDocument)
END_MESSAGE_MAP()


// CMy20160274_Practice_10_1Doc ����/�Ҹ�

CMy20160274_Practice_10_1Doc::CMy20160274_Practice_10_1Doc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CMy20160274_Practice_10_1Doc::~CMy20160274_Practice_10_1Doc()
{
}

BOOL CMy20160274_Practice_10_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CMy20160274_Practice_10_1Doc serialization

void CMy20160274_Practice_10_1Doc::Serialize(CArchive& ar)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20160274_Practice_10_1View* pView = (CMy20160274_Practice_10_1View*)pFrame->GetActiveView();
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		ar << pView->m_nX;
		ar << pView->m_nY;
		ar << pView->m_nRed;
		ar << pView->m_nGreen;
		ar << pView->m_nBlue;
		ar << pView->m_strText;
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
		ar >> pView->m_nX;
		ar >> pView->m_nY;
		ar >> pView->m_nRed;
		ar >> pView->m_nGreen;
		ar >> pView->m_nBlue;
		ar >> pView->m_strText;
		pView->m_colorText = RGB(pView->m_nRed, pView->m_nGreen, pView->m_nBlue);
		UpdateAllViews(NULL);
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CMy20160274_Practice_10_1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CMy20160274_Practice_10_1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMy20160274_Practice_10_1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy20160274_Practice_10_1Doc ����

#ifdef _DEBUG
void CMy20160274_Practice_10_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy20160274_Practice_10_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy20160274_Practice_10_1Doc ���
