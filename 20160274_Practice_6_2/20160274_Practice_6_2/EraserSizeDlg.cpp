// EraserSizeDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "20160274_Practice_6_2.h"
#include "EraserSizeDlg.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "20160274_Practice_6_2Doc.h"
#include "20160274_Practice_6_2View.h"


// CEraserSizeDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CEraserSizeDlg, CDialogEx)

CEraserSizeDlg::CEraserSizeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_ERASER, pParent)
	, m_nEraserSize(0)
{

}

CEraserSizeDlg::~CEraserSizeDlg()
{
}

void CEraserSizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_ERASER, m_nEraserSize);
	DDX_Control(pDX, IDC_SPIN_ERASER, m_spinEraser);
	DDX_Text(pDX, IDC_EDIT_ERASER, m_nEraserSize);
}


BEGIN_MESSAGE_MAP(CEraserSizeDlg, CDialogEx)
END_MESSAGE_MAP()


// CEraserSizeDlg �޽��� ó�����Դϴ�.


BOOL CEraserSizeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CMy20160274_Practice_6_2View *pView = (CMy20160274_Practice_6_2View*)pFrame->GetActiveView();

	m_spinEraser.SetRange(2, 20);
	m_nEraserSize = pView->m_nEraserSize;
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
