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

// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "20160274_Practice_9_2.h"

#include "MainFrm.h"
#include "20160274_Practice_9_2Doc.h"
#include "20160274_Practice_9_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnUpdateApplicationLook)
	ON_COMMAND(ID_FILE_PRINT, &CMainFrame::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CMainFrame::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMainFrame::OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, &CMainFrame::OnUpdateFilePrintPreview)
	ON_COMMAND(ID_COMBO_OBJECT, &CMainFrame::OnComboObject)
	ON_COMMAND(ID_BUTTON_ERASER, &CMainFrame::OnButtonEraser)
	ON_COMMAND(ID_EDIT_TEXT, &CMainFrame::OnEditText)
	ON_COMMAND(ID_COMBO_FONT, &CMainFrame::OnComboFont)
	ON_COMMAND(ID_SPIN_SIZE, &CMainFrame::OnSpinSize)
	ON_COMMAND(ID_BUTTON_LINECOLOR, &CMainFrame::OnButtonLinecolor)
	ON_COMMAND(ID_BUTTON_FILLCOLOR, &CMainFrame::OnButtonFillcolor)
	ON_COMMAND(ID_BUTTON_TEXTCOLOR, &CMainFrame::OnButtonTextcolor)
	ON_COMMAND(ID_SLIDER_ZOOM, &CMainFrame::OnSliderZoom)
	ON_COMMAND(ID_CHECK_POINTS, &CMainFrame::OnCheckPoints)
	ON_UPDATE_COMMAND_UI(ID_CHECK_POINTS, &CMainFrame::OnUpdateCheckPoints)
END_MESSAGE_MAP()

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	theApp.m_nAppLook = theApp.GetInt(_T("ApplicationLook"), ID_VIEW_APPLOOK_OFF_2007_BLUE);
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	BOOL bNameValid;

	m_wndRibbonBar.Create(this);
	m_wndRibbonBar.LoadFromResource(IDR_RIBBON);

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}

	CString strTitlePane1;
	CString strTitlePane2;
	bNameValid = strTitlePane1.LoadString(IDS_STATUS_PANE1);
	ASSERT(bNameValid);
	bNameValid = strTitlePane2.LoadString(IDS_STATUS_PANE2);
	ASSERT(bNameValid);
	m_wndStatusBar.AddElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE1, strTitlePane1, TRUE), strTitlePane1);
	m_wndStatusBar.AddExtendedElement(new CMFCRibbonStatusBarPane(ID_STATUSBAR_PANE2, strTitlePane2, TRUE), strTitlePane2);

	// Visual Studio 2005 ��Ÿ�� ��ŷ â ������ Ȱ��ȭ�մϴ�.
	CDockingManager::SetDockingMode(DT_SMART);
	// Visual Studio 2005 ��Ÿ�� ��ŷ â �ڵ� ���� ������ Ȱ��ȭ�մϴ�.
	EnableAutoHidePanes(CBRS_ALIGN_ANY);
	// ������ ���� ���� ���־� ������ �� ��Ÿ���� �����մϴ�.
	OnApplicationLook(theApp.m_nAppLook);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}

// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG


// CMainFrame �޽��� ó����

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_VS_2008:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(TRUE);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
		m_wndRibbonBar.SetWindows7Look(FALSE);
	}

	RedrawWindow(NULL, NULL, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

	theApp.WriteInt(_T("ApplicationLook"), theApp.m_nAppLook);
}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}


void CMainFrame::OnFilePrint()
{
	if (IsPrintPreview())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_PRINT);
	}
}

void CMainFrame::OnFilePrintPreview()
{
	if (IsPrintPreview())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_CLOSE);  // �μ� �̸� ���� ��带 �ݽ��ϴ�.
	}
}

void CMainFrame::OnUpdateFilePrintPreview(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(IsPrintPreview());
}


void CMainFrame::OnComboObject()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMFCRibbonComboBox* pObject = DYNAMIC_DOWNCAST(CMFCRibbonComboBox, m_wndRibbonBar.FindByID(ID_COMBO_OBJECT));

	CMy20160274_Practice_9_2View* pView = (CMy20160274_Practice_9_2View*)GetActiveView();
	pView->m_nObjectType = pObject->GetCurSel();
}


void CMainFrame::OnButtonEraser()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMy20160274_Practice_9_2View* pView = (CMy20160274_Practice_9_2View*)GetActiveView();
	pView->m_nCount = 0;
	pView->Invalidate();
}


void CMainFrame::OnEditText()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMFCRibbonEdit* pText = DYNAMIC_DOWNCAST(CMFCRibbonEdit, m_wndRibbonBar.FindByID(ID_EDIT_TEXT));
	CMy20160274_Practice_9_2View* pView = (CMy20160274_Practice_9_2View*)GetActiveView();
	pView->m_strText = pText->GetEditText();
	pView->Invalidate();
}


void CMainFrame::OnComboFont()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMFCRibbonFontComboBox* pFont = DYNAMIC_DOWNCAST(CMFCRibbonFontComboBox, m_wndRibbonBar.FindByID(ID_COMBO_FONT));
	CMy20160274_Practice_9_2View* pView = (CMy20160274_Practice_9_2View*)GetActiveView();
	lstrcpyn(pView->m_lfFont.lfFaceName, pFont->GetFontDesc()->m_strName, LF_FACESIZE);
	pView->Invalidate();
}


void CMainFrame::OnSpinSize()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMFCRibbonEdit* pSize = DYNAMIC_DOWNCAST(CMFCRibbonEdit, m_wndRibbonBar.FindByID(ID_SPIN_SIZE));
	CMy20160274_Practice_9_2View* pView = (CMy20160274_Practice_9_2View*)GetActiveView();
	pView->m_lfFont.lfHeight = (int)_wtoi(pSize->GetEditText());
	pView->Invalidate();
}


void CMainFrame::OnButtonLinecolor()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMFCRibbonColorButton* pColor = DYNAMIC_DOWNCAST(CMFCRibbonColorButton, m_wndRibbonBar.FindByID(ID_BUTTON_LINECOLOR));
	CMy20160274_Practice_9_2View* pView = (CMy20160274_Practice_9_2View*)GetActiveView();
	pView->m_colorLine = pColor->GetColor();
	pView->Invalidate();
}


void CMainFrame::OnButtonFillcolor()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMFCRibbonColorButton* pColor = DYNAMIC_DOWNCAST(CMFCRibbonColorButton, m_wndRibbonBar.FindByID(ID_BUTTON_FILLCOLOR));
	CMy20160274_Practice_9_2View* pView = (CMy20160274_Practice_9_2View*)GetActiveView();
	pView->m_colorFill = pColor->GetColor();
	pView->Invalidate();
}


void CMainFrame::OnButtonTextcolor()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMFCRibbonColorButton* pColor = DYNAMIC_DOWNCAST(CMFCRibbonColorButton, m_wndRibbonBar.FindByID(ID_BUTTON_TEXTCOLOR));
	CMy20160274_Practice_9_2View* pView = (CMy20160274_Practice_9_2View*)GetActiveView();
	pView->m_colorText = pColor->GetColor();
	pView->Invalidate();
}


void CMainFrame::OnSliderZoom()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMFCRibbonSlider* pZoom = DYNAMIC_DOWNCAST(CMFCRibbonSlider, m_wndRibbonBar.FindByID(ID_SLIDER_ZOOM));
	CMy20160274_Practice_9_2View* pView = (CMy20160274_Practice_9_2View*)GetActiveView();
	pView->m_fZoom = (float)pZoom->GetPos() / 100.0f;
	pView->Invalidate();
}


void CMainFrame::OnCheckPoints()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMFCRibbonCheckBox* pViewPoint = DYNAMIC_DOWNCAST(CMFCRibbonCheckBox, m_wndRibbonBar.FindByID(ID_CHECK_POINTS));
	CMy20160274_Practice_9_2View* pView = (CMy20160274_Practice_9_2View*)GetActiveView();
	pView->m_bViewPoints = !pView->m_bViewPoints;
	pView->Invalidate();
}


void CMainFrame::OnUpdateCheckPoints(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	CMy20160274_Practice_9_2View* pView = (CMy20160274_Practice_9_2View*)GetActiveView();
	pCmdUI->SetCheck(pView->m_bViewPoints);
}
