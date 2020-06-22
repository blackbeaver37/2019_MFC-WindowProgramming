
// 20160274_Practice_4_1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "20160274_Practice_4_1.h"
#include "20160274_Practice_4_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnButtonDelete();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_COMMAND(IDC_BUTTON_DELETE, &CAboutDlg::OnButtonDelete)
END_MESSAGE_MAP()


// CMy20160274_Practice_4_1Dlg ��ȭ ����



CMy20160274_Practice_4_1Dlg::CMy20160274_Practice_4_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY20160274_PRACTICE_4_1_DIALOG, pParent)
	, m_strEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	// ���� �ʱ�ȭ
	m_bChecked[0] = m_bChecked[1] = FALSE;
}

void CMy20160274_Practice_4_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STRING, m_strEdit);
	DDX_Control(pDX, IDC_LIST_OUTPUT, m_listBox);
	DDX_Control(pDX, IDC_COMBO_AUTO, m_cbListItem);
}

BEGIN_MESSAGE_MAP(CMy20160274_Practice_4_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO1, &CMy20160274_Practice_4_1Dlg::OnRadio1)
	ON_COMMAND(IDC_RADIO2, &CMy20160274_Practice_4_1Dlg::OnRadio2)
	ON_BN_CLICKED(IDC_CHECK1, &CMy20160274_Practice_4_1Dlg::OnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMy20160274_Practice_4_1Dlg::OnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMy20160274_Practice_4_1Dlg::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CMy20160274_Practice_4_1Dlg::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMy20160274_Practice_4_1Dlg::OnClickedButtonDelete)
END_MESSAGE_MAP()


// CMy20160274_Practice_4_1Dlg �޽��� ó����

BOOL CMy20160274_Practice_4_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ���� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMy20160274_Practice_4_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMy20160274_Practice_4_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMy20160274_Practice_4_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy20160274_Practice_4_1Dlg::UpdateComboBox()
{
	int nCnt = m_listBox.GetCount();		// ����Ʈ �ڽ��� �������� ���� ��ȯ
	m_cbListItem.ResetContent();			// �޺� �ڽ��� ��� ������ ����

	for (int i = 0; i < nCnt; i++)
	{
		CString strItem;
		strItem.Format(_T("����Ʈ �׸� : %d"), i + 1);
		m_cbListItem.AddString(strItem);
	}
}


void CMy20160274_Practice_4_1Dlg::OnRadio1()
{
	// TODO: ���⿡ ���� ó���� �ڵ带 �߰��մϴ�.
	m_listBox.AddString(_T("1�� ���� ��ư ����"));
	UpdateComboBox();
}


void CMy20160274_Practice_4_1Dlg::OnRadio2()
{
	// TODO: ���⿡ ���� ó���� �ڵ带 �߰��մϴ�.
	m_listBox.AddString(_T("2�� ���� ��ư ����"));
	UpdateComboBox();
}


void CMy20160274_Practice_4_1Dlg::OnClickedCheck1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bChecked[0] == FALSE)
	{
		m_bChecked[0] = TRUE;
		m_listBox.AddString(_T("1�� üũ �ڽ� ���� TRUE"));
	}
	else
	{
		m_bChecked[0] = FALSE;
		m_listBox.AddString(_T("1�� üũ �ڽ� ���� FLASE"));
	}
	UpdateComboBox();
}


void CMy20160274_Practice_4_1Dlg::OnClickedCheck2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_bChecked[1] == FALSE)
	{
		m_bChecked[1] = TRUE;
		m_listBox.AddString(_T("2�� üũ �ڽ� ���� TRUE"));
	}
	else
	{
		m_bChecked[1] = FALSE;
		m_listBox.AddString(_T("2�� üũ �ڽ� ���� FLASE"));
	}
	UpdateComboBox();
}


void CMy20160274_Practice_4_1Dlg::OnClickedButtonAdd()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if (m_strEdit.IsEmpty() == FALSE)
	{
		m_listBox.AddString(m_strEdit);
		m_strEdit.Empty();
	}
	else
	{
		AfxMessageBox(_T("����Ʈ ���ڿ� ���ڿ��� �����ϴ�."));
	}
	UpdateData(FALSE);
	UpdateComboBox();
}


void CMy20160274_Practice_4_1Dlg::OnClickedButtonInsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString strSelText;
	int index = m_cbListItem.GetCurSel();
	if (index != CB_ERR)					// �������� ���õǾ��� ���
	{
		m_listBox.GetText(index, strSelText);
		m_listBox.AddString(strSelText);
		UpdateComboBox();
	}
	else									// �������� ���õ��� �ʾ��� ���
	{
		AfxMessageBox(_T("�޺� �ڽ����� ������ �������� �����ϼ���."));
	}
}

void CMy20160274_Practice_4_1Dlg::OnClickedButtonDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int index = m_cbListItem.GetCurSel();
	if (index != CB_ERR)
	{
		m_listBox.DeleteString(index);
		UpdateComboBox();
	}
	else
	{
		AfxMessageBox(_T("�޺� �ڽ����� ������ �������� �����ϼ���."));
	}
}