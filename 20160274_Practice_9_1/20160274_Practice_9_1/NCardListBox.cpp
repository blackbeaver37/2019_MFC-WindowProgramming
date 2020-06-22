// NCardListBox.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "20160274_Practice_9_1.h"
#include "NCardListBox.h"
#include "20160274_Practice_9_1Dlg.h"


// CNCardListBox

IMPLEMENT_DYNAMIC(CNCardListBox, CVSListBox)

CNCardListBox::CNCardListBox()
{

}

CNCardListBox::~CNCardListBox()
{
}


BEGIN_MESSAGE_MAP(CNCardListBox, CVSListBox)
END_MESSAGE_MAP()



// CNCardListBox �޽��� ó�����Դϴ�.




void CNCardListBox::OnAfterAddItem(int nIndex)
{
	// ���� ������ �߰��ϱ�
	CMy20160274_Practice_9_1Dlg* pParent = (CMy20160274_Practice_9_1Dlg*)GetParent();
	pParent->AddNameCard(GetItemText(nIndex));
}


void CNCardListBox::OnSelectionChanged()
{
	int nItem;
	if ((nItem = GetSelItem()) < 0)
		return;

	// ���� ������ �����ϱ�
	CMy20160274_Practice_9_1Dlg* pParent = (CMy20160274_Practice_9_1Dlg*)GetParent();
	pParent->SelectNameCard(nItem);
}


BOOL CNCardListBox::OnBeforeRemoveItem(int nIndex)
{
	// ���� ������ �����ϱ�
	CMy20160274_Practice_9_1Dlg* pParent = (CMy20160274_Practice_9_1Dlg*)GetParent();
	pParent->DeleteNameCard(GetSelItem());
	return TRUE;
}
