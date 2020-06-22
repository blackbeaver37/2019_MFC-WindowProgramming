
// 20160274_Practice_9_1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "20160274_Practice_9_1.h"
#include "20160274_Practice_9_1Dlg.h"
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


// CMy20160274_Practice_9_1Dlg ��ȭ ����



CMy20160274_Practice_9_1Dlg::CMy20160274_Practice_9_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY20160274_PRACTICE_9_1_DIALOG, pParent)
	, m_nCount(0)
	, m_nSelectedCard(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy20160274_Practice_9_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON_BACKGND, m_cbtnBackgnd);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON_TEXT, m_cbtnText);
	DDX_Control(pDX, IDC_MFCFONTCOMBO_TEXT, m_fcbText);
	//  DDX_Control(pDX, IDC_MFCPROPERTYGRID_CARD, m_pgCardInfo);
	DDX_Control(pDX, IDC_MFCVSLISTBOX_CARDLIST, m_listNameCard);
	DDX_Control(pDX, IDC_MFCPROPERTYGRID_CARD, m_pgCardInfo);
}

BEGIN_MESSAGE_MAP(CMy20160274_Practice_9_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_REGISTERED_MESSAGE(AFX_WM_PROPERTY_CHANGED, OnPropertyChanged)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON_BACKGND, &CMy20160274_Practice_9_1Dlg::OnClickedMfccolorbuttonBackgnd)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON_TEXT, &CMy20160274_Practice_9_1Dlg::OnClickedMfccolorbuttonText)
	ON_CBN_SELCHANGE(IDC_MFCFONTCOMBO_TEXT, &CMy20160274_Practice_9_1Dlg::OnSelchangeMfcfontcomboText)
END_MESSAGE_MAP()


// CMy20160274_Practice_9_1Dlg �޽��� ó����

BOOL CMy20160274_Practice_9_1Dlg::OnInitDialog()
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
	// Color ��ư�� �ʱ�ȭ �Ѵ�.
	m_cbtnBackgnd.SetColor(RGB(255, 255, 255));
	m_cbtnText.SetColor(RGB(0, 0, 0));

	// Font Combo �ڽ��� �ʱ�ȭ �Ѵ�.
	LOGFONT lf;
	afxGlobalData.fontRegular.GetLogFont(&lf);
	m_fcbText.SelectFont(lf.lfFaceName);

	// ���� ����Ʈ �ڽ��� �ʱ�ȭ �Ѵ�.
	m_listNameCard.SetWindowText(_T("NameCard"));

	// ���� Property Grid�� �ʱ�ȭ �Ѵ�.
	InitializePropGrid(NameCard());		// �� �������� �ʱ�ȭ

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMy20160274_Practice_9_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy20160274_Practice_9_1Dlg::OnPaint()
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
HCURSOR CMy20160274_Practice_9_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy20160274_Practice_9_1Dlg::AddNameCard(CString strName)
{
	NameCard card;
	card.strName = strName;

	m_pNameCards[m_nCount++] = card;
	DrawNameCard(card);
	InitializePropGrid(card);
}


void CMy20160274_Practice_9_1Dlg::SelectNameCard(int nIndex)
{
	m_nSelectedCard = nIndex;
	DrawNameCard(m_pNameCards[nIndex]);
	InitializePropGrid(m_pNameCards[nIndex]);
}


void CMy20160274_Practice_9_1Dlg::DeleteNameCard(int nIndex)
{
	if (nIndex != (m_nCount - 1))
		memcpy(&m_pNameCards[nIndex], &m_pNameCards[nIndex + 1], sizeof(NameCard) * (m_nCount - nIndex + 1));
	m_nCount--;
}


void CMy20160274_Practice_9_1Dlg::InitializePropGrid(NameCard card)
{
	HDITEM item;
	item.cxy = 110;
	item.mask = HDI_WIDTH;
	m_pgCardInfo.GetHeaderCtrl().SetItem(0, &item);

	m_pgCardInfo.RemoveAll();
	m_pgCardInfo.EnableHeaderCtrl(FALSE);
	m_pgCardInfo.SetVSDotNetLook();
	m_pgCardInfo.EnableDescriptionArea();

	// 1. ���� �Ż� ����
	CMFCPropertyGridProperty* pGroupInfo = new CMFCPropertyGridProperty(_T("Information"));

	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Company"), card.strCompany, _T("ȸ���̸��� �Է��ϼ���."), 0));

	CMFCPropertyGridProperty* pTitle = new CMFCPropertyGridProperty(_T("Title"), card.strTitle, _T("��å�� �����ϼ���."), 1);
	pTitle->AddOption(_T("��ǥ�̻�"));
	pTitle->AddOption(_T("����"));
	pTitle->AddOption(_T("����"));
	pTitle->AddOption(_T("�븮"));
	pTitle->AddOption(_T("���"));
	pTitle->AllowEdit(FALSE);

	pGroupInfo->AddSubItem(pTitle);
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Name"),card.strName,_T("�̸��� �Է��ϼ���."),2));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Telephone"), card.strTelephone, _T("��ȭ��ȣ�� �Է��ϼ���."), 3));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("Mobile"), card.strMobile, _T("�ڵ��� ��ȣ�� �Է��ϼ���."), 4));
	pGroupInfo->AddSubItem(new CMFCPropertyGridProperty(_T("E-Mail"), card.strEMail, _T("�����ּҸ� �Է��ϼ���."), 5));
	m_pgCardInfo.AddProperty(pGroupInfo);

	m_pgCardInfo.UpdateData(FALSE);
}


void CMy20160274_Practice_9_1Dlg::DrawNameCard(NameCard card)
{
	CRect rc;
	CFont font, *pOldFont;
	CDC* pDC = GetDlgItem(IDC_STATIC_NAMECARD)->GetDC();
	GetDlgItem(IDC_STATIC_NAMECARD)->GetClientRect(&rc);

	// ���
	pDC->FillSolidRect(&rc, m_cbtnBackgnd.GetColor());
	pDC->SetBkColor(m_cbtnBackgnd.GetColor());

	LOGFONT lf;
	CMFCFontInfo* pInfo = m_fcbText.GetSelFont();
	afxGlobalData.fontRegular.GetLogFont(&lf);

	lf.lfCharSet = pInfo->m_nCharSet;
	lf.lfPitchAndFamily = pInfo->m_nPitchAndFamily;
	lstrcpyn(lf.lfFaceName, pInfo->m_strName, LF_FACESIZE);
	lf.lfHeight = 50;

	font.CreateFontIndirect(&lf);
	pOldFont = pDC->SelectObject(&font);
	pDC->SetTextColor(m_cbtnText.GetColor());

	pDC->TextOut(15, 15, card.strCompany);		// ȸ�� �̸�

	CRect rcTitle(rc);
	rcTitle.right = rc.CenterPoint().x;
	pDC->DrawText(card.strTitle, &rcTitle, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);

	CRect rcName(rc);
	rcName.left = rc.CenterPoint().x;
	pDC->DrawText(card.strName, &rcName, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	pDC->SelectObject(pOldFont);
	font.DeleteObject();

	lf.lfCharSet = pInfo->m_nCharSet;
	lf.lfPitchAndFamily = pInfo->m_nPitchAndFamily;
	lstrcpyn(lf.lfFaceName, pInfo->m_strName, LF_FACESIZE);
	lf.lfHeight = 15;

	font.CreateFontIndirect(&lf);
	pOldFont = pDC->SelectObject(&font);
	pDC->SetTextColor(m_cbtnText.GetColor());

	CString str;
	CRect rcMail(rc);

	rcMail.right = rcMail.right - 6;
	rcMail.bottom = rcMail.bottom - 6;
	str.Format(_T("���ڸ��� : %s"), card.strEMail);
	int nHeight = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	str.Format(_T("������ȭ : %s"), card.strMobile);
	rcMail.bottom = rcMail.bottom - lf.lfHeight;
	nHeight = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	str.Format(_T("��ǥ��ȭ : %s"), card.strTelephone);
	rcMail.bottom = rcMail.bottom - lf.lfHeight;
	nHeight = pDC->DrawText(str, &rcMail, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	pDC->SelectObject(pOldFont);
	font.DeleteObject();
}

LRESULT CMy20160274_Practice_9_1Dlg::OnPropertyChanged(WPARAM wParam, LPARAM lParam)
{
	// wParam - control id, lParam - a pointer to property that changed
	CMFCPropertyGridProperty* pProperty = (CMFCPropertyGridProperty*)lParam;

	switch (pProperty->GetData())
	{
	case 0:
		m_pNameCards[m_nSelectedCard].strCompany = pProperty->GetValue();
		break;
	case 1:
		m_pNameCards[m_nSelectedCard].strTitle = pProperty->GetValue();
		break;
	case 2:
		m_pNameCards[m_nSelectedCard].strName = pProperty->GetValue();
		break;
	case 3:
		m_pNameCards[m_nSelectedCard].strTelephone = pProperty->GetValue();
		break;
	case 4:
		m_pNameCards[m_nSelectedCard].strMobile = pProperty->GetValue();
		break;
	case 5:
		m_pNameCards[m_nSelectedCard].strEMail = pProperty->GetValue();
		break;
	}
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
	return 0L;
}

void CMy20160274_Practice_9_1Dlg::OnClickedMfccolorbuttonBackgnd()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
}


void CMy20160274_Practice_9_1Dlg::OnClickedMfccolorbuttonText()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
}


void CMy20160274_Practice_9_1Dlg::OnSelchangeMfcfontcomboText()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DrawNameCard(m_pNameCards[m_nSelectedCard]);
}
