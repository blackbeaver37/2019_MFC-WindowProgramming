
// 20160274_Practice_12_1View.cpp : CMy20160274_Practice_12_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "20160274_Practice_12_1.h"
#endif

#include "20160274_Practice_12_1Doc.h"
#include "20160274_Practice_12_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy20160274_Practice_12_1View

IMPLEMENT_DYNCREATE(CMy20160274_Practice_12_1View, CFormView)

BEGIN_MESSAGE_MAP(CMy20160274_Practice_12_1View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FIRST_RECORD, &CMy20160274_Practice_12_1View::OnFirstRecord)
	ON_COMMAND(ID_PREV_RECORD, &CMy20160274_Practice_12_1View::OnPrevRecord)
	ON_COMMAND(ID_NEXT_RECORD, &CMy20160274_Practice_12_1View::OnNextRecord)
	ON_COMMAND(ID_LAST_RECORD, &CMy20160274_Practice_12_1View::OnLastRecord)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMy20160274_Practice_12_1View::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CMy20160274_Practice_12_1View::OnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMy20160274_Practice_12_1View::OnClickedButtonDelete)
	ON_CBN_SELCHANGE(IDC_COMBO_SEEKBY, &CMy20160274_Practice_12_1View::OnSelchangeComboSeekby)
	ON_BN_CLICKED(IDC_BUTTON_SEEK, &CMy20160274_Practice_12_1View::OnClickedButtonSeek)
END_MESSAGE_MAP()

// CMy20160274_Practice_12_1View ����/�Ҹ�

CMy20160274_Practice_12_1View::CMy20160274_Practice_12_1View()
	: CFormView(IDD_MY20160274_PRACTICE_12_1_FORM)
	, m_bMoveRecord(false)
	, m_nTotal(0)
	, m_nMoveCount(0)
	, m_strBook(_T(""))
	, m_strCheckOut(_T(""))
	, m_strHakbun(_T(""))
	, m_strMajor(_T(""))
	, m_strName(_T(""))
	, m_strReturn(_T(""))
	, m_nAddMode(0)
	, m_nSelectedItem(0)
	, m_strSeekText(_T(""))
	, m_nSeekMode(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_nAddMode = ADD_READY;
	m_nSeekMode= SEEK_READY;
}

CMy20160274_Practice_12_1View::~CMy20160274_Practice_12_1View()
{
}

void CMy20160274_Practice_12_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BOOK, m_strBook);
	DDX_Text(pDX, IDC_EDIT_CHECKOUT, m_strCheckOut);
	DDX_Text(pDX, IDC_EDIT_HAKBUN, m_strHakbun);
	DDX_Text(pDX, IDC_EDIT_MAJOR, m_strMajor);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_RETURN, m_strReturn);
	DDX_Text(pDX, IDC_EDIT_STRING, m_strSeekText);
}

BOOL CMy20160274_Practice_12_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CMy20160274_Practice_12_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CString strQuery;
	strQuery.Format(_T("SELECT * FROM card"));
	m_command.Close();
	if(m_dbSet.Query(strQuery, &m_command))
	{
		// ��ü ���ڵ� ���� ���ϱ�
		m_nTotal = 0;
		while(m_command.MoveNext() == S_OK)
		{
			m_nTotal++;
		}
		m_nMoveCount = 1;
		GetDataFromDb(MOVE_FIRST_RECORD);
		m_bMoveRecord = true;
	}
}

void CMy20160274_Practice_12_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy20160274_Practice_12_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy20160274_Practice_12_1View ����

#ifdef _DEBUG
void CMy20160274_Practice_12_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy20160274_Practice_12_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy20160274_Practice_12_1Doc* CMy20160274_Practice_12_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy20160274_Practice_12_1Doc)));
	return (CMy20160274_Practice_12_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy20160274_Practice_12_1View �޽��� ó����


void CMy20160274_Practice_12_1View::OnFirstRecord()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	if (m_nSeekMode == SEEK_READY)				// �˻����� �ƴ� ��
	{
		CString strQuery;
		strQuery.Format(_T("SELECT * FROM card"));
		m_command.Close();
		if(m_dbSet.Query(strQuery, &m_command))
		{
			// ��ü ���ڵ� ���� ���ϱ�
			m_nTotal = 0;
			while(m_command.MoveNext() == S_OK)
			{
				m_nTotal++;
			}
			m_nMoveCount = 1;
			GetDataFromDb(MOVE_FIRST_RECORD);
		}
	}
	else if (m_nSeekMode == SEEK_FREE)				// �˻� ���� ��
	{
		m_nMoveCount = 1;
		GetDataFromDb(MOVE_FIRST_RECORD);
	}
	m_bMoveRecord = true;
	UpdateData(FALSE);
}


void CMy20160274_Practice_12_1View::OnPrevRecord()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	if (!m_bMoveRecord)
	{
		return;
	}
	else
	{
		if(m_nMoveCount==1)
		{
			return;
		}
		m_nMoveCount--;
		GetDataFromDb(MOVE_PREV_RECORD);
	}
	UpdateData(FALSE);
}


void CMy20160274_Practice_12_1View::OnNextRecord()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	if (!m_bMoveRecord)
	{
		return;
	}
	else
	{
		if (m_nMoveCount == m_nTotal)
		{
			return;
		}
		m_nMoveCount++;
		GetDataFromDb(MOVE_NEXT_RECORD);
	}
	UpdateData(FALSE);
}


void CMy20160274_Practice_12_1View::OnLastRecord()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	if (m_nSeekMode == SEEK_READY)				// �˻� ���� �ƴ� ��
	{
		CString strQuery;
		strQuery.Format(_T("SELECT * FROM card"));
		m_command.Close();
		if (m_dbSet.Query(strQuery, &m_command))
		{
			m_nTotal = 0;
			while (m_command.MoveNext() == S_OK)
			{
				m_nTotal++;
			}
			m_nMoveCount = m_nTotal;
			GetDataFromDb(MOVE_LAST_RECORD);
		}
	}
	else if (m_nSeekMode == SEEK_FREE)			// �˻� ���� ��
	{
		m_nMoveCount = m_nTotal;
		GetDataFromDb(MOVE_LAST_RECORD);
	}
	m_bMoveRecord = true;
	UpdateData(FALSE);
}


void CMy20160274_Practice_12_1View::GetDataFromDb(int nMoveRecord)
{
	switch (nMoveRecord)
	{
	case MOVE_FIRST_RECORD :
		m_command.MoveFirst();
		break;
	case MOVE_PREV_RECORD :
		m_command.MovePrev();
		break;
	case MOVE_NEXT_RECORD :
		m_command.MoveNext();
		break;
	case MOVE_LAST_RECORD :
		m_command.MoveLast();
		break;
	}
	m_strMajor = m_command.GetString(2);
	m_strHakbun = m_command.GetString(3);
	m_strName = m_command.GetString(4);
	m_strBook = m_command.GetString(5);
	m_strCheckOut = m_command.GetString(6);
	m_strReturn = m_command.GetString(7);

	UpdateData(FALSE);
}


void CMy20160274_Practice_12_1View::OnClickedButtonAdd()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_nAddMode == ADD_READY) 					// Edit �ڽ� �ʱ�ȭ
	{
		m_strMajor.Empty();
		m_strHakbun.Empty();
		m_strName.Empty();
		m_strBook.Empty();
		m_strCheckOut.Empty();
		m_strReturn.Empty();
		UpdateData(FALSE);

		(GetDlgItem(IDC_BUTTON_ADD))->SetWindowText(_T("�߰� �Ϸ�"));
		m_nAddMode = ADD_OK;
	}
	else if (m_nAddMode == ADD_OK) 					// ���ڵ� �߰�
	{
		UpdateData(TRUE);
		CString strQuery;
		strQuery.Format(_T("INSERT INTO card(major, hakbun, sname, booktitle, checkout, returnday) VALUES('%s', '%s', '%s', '%s', '%s', '%s'); "), m_strMajor, m_strHakbun, m_strName, m_strBook, m_strCheckOut, m_strReturn);
		m_command.Close();
		if (m_dbSet.Query(strQuery, &m_command))
		{
			AfxMessageBox(_T("�߰��Ǿ����ϴ�."));
		}
		(GetDlgItem(IDC_BUTTON_ADD))->SetWindowText(_T("�߰�"));
		m_nAddMode = ADD_READY;

		OnFirstRecord();							// ó�� ���ڵ�� �̵�
	}
}


void CMy20160274_Practice_12_1View::OnClickedButtonModify()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	CString strQuery;
	strQuery.Format(_T("UPDATE card SET major='%s', hakbun='%s', sname='%s',booktitle = '%s', checkout = '%s', returnday = '%s' WHERE major = '%s'"), m_strMajor, m_strHakbun, m_strName, m_strBook, m_strCheckOut, m_strReturn, m_command.GetString(2));
	m_command.Close();
	if (m_dbSet.Query(strQuery, &m_command))
	{
		AfxMessageBox(_T("�����Ǿ����ϴ�."));
		OnFirstRecord();							// ó�� ���ڵ�� �̵�
	}
}


void CMy20160274_Practice_12_1View::OnClickedButtonDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ���ڵ� ����
	UpdateData(TRUE);
	CString strQuery;
	strQuery.Format(_T("DELETE * FROM card WHERE major='%s' AND hakbun='%s' AND sname = '%s' AND booktitle = '%s' AND checkout = '%s'AND returnday = '%s' "), m_strMajor, m_strHakbun, m_strName, m_strBook, m_strCheckOut, m_strReturn);
	m_command.Close();
	if (m_dbSet.Query(strQuery, &m_command))
	{
		AfxMessageBox(_T("�����Ǿ����ϴ�."));
		OnFirstRecord();							// ó�� ���ڵ�� �̵�
	}
}


void CMy20160274_Practice_12_1View::OnSelchangeComboSeekby()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nSelectedItem = ((CComboBox *)GetDlgItem(IDC_COMBO_SEEKBY))->GetCurSel();
}


void CMy20160274_Practice_12_1View::OnClickedButtonSeek()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if (m_nSeekMode == SEEK_READY)				// �˻� ����
	{
		CString strQuery;
		switch (m_nSelectedItem)				// �˻� �ɼǿ� ����
		{
		case 0:
			strQuery.Format(_T("SELECT * FROM card WHERE hakbun = '%s'"), m_strSeekText);
			break;
		case 1:
			strQuery.Format(_T("SELECT * FROM card WHERE sname = '%s'"), m_strSeekText);
			break;
		case 2:
			strQuery.Format(_T("SELECT * FROM card WHERE major = '%s'"), m_strSeekText);
			break;
		case 3:
			strQuery.Format(_T("SELECT * FROM card WHERE booktitle = '%s'"), m_strSeekText);
			break;
		}
		m_command.Close();
		if (m_dbSet.Query(strQuery, &m_command))
		{
			// ��ü ���ڵ� ���� ���
			while (m_command.MoveNext() == S_OK)
			{
				m_nTotal++;
			}
			AfxMessageBox(_T("�˻��Ǿ����ϴ�."));
			GetDataFromDb(MOVE_FIRST_RECORD);
		}
		GetDlgItem(IDC_BUTTON_SEEK)->SetWindowText(_T("�˻�����"));
		m_nSeekMode = SEEK_FREE;
	}
	else if (m_nSeekMode == SEEK_FREE)				// �˻�����
	{
		m_strSeekText.Empty();
		GetDlgItem(IDC_BUTTON_SEEK)->SetWindowText(_T("�˻�"));
		m_nSeekMode = SEEK_READY;

		OnFirstRecord();							// ó�� ���ڵ�� �̵�
	}
	UpdateData(FALSE);
}
