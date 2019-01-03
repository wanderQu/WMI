// DialogList.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "DialogList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CDialogList

CDialogList::CDialogList()
{

	iCount = 0;
}

CDialogList::~CDialogList()
{

}


BEGIN_MESSAGE_MAP(CDialogList, CWnd)
	//{{AFX_MSG_MAP(CDialogList)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDialogList message handlers


CWnd* CDialogList::Get(int n)
{
	if(n > iCount + 1 || n == 0 || iCount == 0)
		return NULL;
	else
	{
		CDialogNode* tmp = NULL;
		if(n == 1)
			return head->Get();
		else
			tmp = head;

		while(--n != 0)
		{
			tmp = tmp->next;
		}
		return tmp->Get();
	}
}

void CDialogList::Remove(int n)
{
	if(n > iCount + 1 || n == 0 || iCount == 0)
		return;
	else
	{
		CDialogNode* tmp = NULL;
		if(n == 1)
		{
			tmp = head->next;
			head = 0;
			head = tmp;
		}
		else
		{
			tmp  = head;
			while(--n != 1)
			{
				tmp = tmp->next;
			}
			CDialogNode* tmp2 = tmp->next->next;
			if(tmp2 == last->next)
			{
				last = 0;
				last = tmp;
			}
			else
			{
				tmp->next = NULL;
				tmp->next = tmp2;
			}
			tmp2 = NULL;
		}
		tmp = NULL;
		iCount--;
	}
}

void CDialogList::RemoveAll()
{
	if(iCount == 0)
		return;
	else
	{
		CDialogNode* tmp = head;
		while(head != last)
		{
			tmp = head->next;
			head = 0;
			head = tmp;
		}
		head = last = 0;
	}
	iCount = 0;
}

CWnd* CDialogList::GetHead()
{
	return head->Get();
}

CWnd* CDialogList::GetLast()
{
	return last->Get();
}

void CDialogList::Insert(CDialogNode* t, int n)
{
	if(n > iCount + 1 || n == 0)
		return;
	else
	{
		CDialogNode* tmp = head;
		if(n == 1)
		{
			head = t;
			head->next = tmp;
		}
		while(--n != 1)
		{
			tmp = tmp->next;
		}
		CDialogNode* tmp2 = tmp->next;
		if(tmp2 == last)
		{
			tmp->next = t;
			t->next = last;
		}
		else
		{
			tmp->next = t;
			t->next = tmp2;
		}

	}
	iCount++;
	
}

void CDialogList::Insert(CDialogNode* t)
{
	if(head == last)
	{
		head = t;
		head->next = last;
	}
	else
	{
		last->next = t;
	}
}

int CDialogList::GetCount()
{
	return iCount;
}


