
// 20160274_Practice_11_1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "20160274_Practice_11_1.h"
#include "20160274_Practice_11_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern "C" __declspec(dllimport) void Calender(int year, int month, int *Days);

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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy20160274_Practice_11_1Dlg ��ȭ ����



CMy20160274_Practice_11_1Dlg::CMy20160274_Practice_11_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY20160274_PRACTICE_11_1_DIALOG, pParent)
	, m_nYear(0)
	, m_nMonth(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy20160274_Practice_11_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_nYear);
	DDX_Control(pDX, IDC_SPIN_YEAR, m_spinYear);
	DDX_Control(pDX, IDC_COMBO_MONTH, m_cbMonth);
}

BEGIN_MESSAGE_MAP(CMy20160274_Practice_11_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_YEAR, &CMy20160274_Practice_11_1Dlg::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO_MONTH, &CMy20160274_Practice_11_1Dlg::OnSelchangeComboMonth)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_YEAR, &CMy20160274_Practice_11_1Dlg::OnDeltaposSpinYear)
END_MESSAGE_MAP()


// CMy20160274_Practice_11_1Dlg �޽��� ó����

BOOL CMy20160274_Practice_11_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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
	// ������ ��¥�� �ҷ��ͼ� Combo Box�� Edit Box�� ǥ���Ͽ��ش�.
	CTime time = CTime::GetCurrentTime();
	m_nYear = time.GetYear();
	m_nMonth = time.GetMonth() - 1;

	m_cbMonth.SetCurSel(m_nMonth);
	m_spinYear.SetRange(1583, 4040);
	m_spinYear.SetPos(m_nYear);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMy20160274_Practice_11_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy20160274_Practice_11_1Dlg::OnPaint()
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
		// ��¥�� ������ ������ ������ �� ��� 0���� �ʱ�ȭ�Ѵ�.
		int m_nDays[6][7] = {0,};
		int i,j,x,y;

		x = 30;
		y = 105;	// ��ȭ���ڿ� ��Ʈ���� ��ġ�� ���� ����� �� �ִ�.

		CString m_WeekDays[7] = { _T("Sun"),_T("Mon") ,_T("Tue") ,_T("Wed") ,_T("Thu") ,_T("Fri") ,_T("Sat") };
		CString m_Number;

		CPaintDC dc(this);
		dc.SetBkColor(RGB(240, 238, 228));

		// ��ȭ��������� ���� ���ڸ� ���� ó�� �����Ͽ��ش�.
		for (i = 0; i < 7; i++)
		{
			dc.TextOut(x, y, m_WeekDays[i]);
			x += 35;
		}
		// DLL�� ������ �Լ��� ����Ѵ�.
		Calender(m_nYear, m_nMonth, &m_nDays[0][0]);

		// ��¥�� ǥ���Ͽ��ش�. �� ��¥ �����Ͱ� 0�� ���� ǥ������ �ʴ´�.
		for (i = 0; i < 6; i++)
		{
			x = 30;
			for (j = 0; j < 7; j++)
			{
				if (m_nDays[i][j] != 0)
				{
					m_Number.Format(_T("%d"), m_nDays[i][j]);
					dc.TextOut(x, y+20, m_Number);
				}
				x += 35;
			}
			y += 20;
		}
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMy20160274_Practice_11_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy20160274_Practice_11_1Dlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CMy20160274_Practice_11_1Dlg::OnSelchangeComboMonth()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ���� ���õ� �������� �� �������� ������ ���� ȭ���� �����Ѵ�.
	int nItem = m_cbMonth.GetCurSel();
	m_nMonth = nItem;
	Invalidate();
}


void CMy20160274_Practice_11_1Dlg::OnDeltaposSpinYear(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// �⵵�� �����Ѵ�.
	m_nYear += pNMUpDown->iDelta;
	// �ּ� �⵵�� �ְ� ������ ������ ����� �ʵ��� �����Ѵ�.
	if(m_nYear <= 1583)
		m_nYear = 1583;
	if(m_nYear > 4040)
		m_nYear = 4040;
	Invalidate();
	*pResult = 0;
}
