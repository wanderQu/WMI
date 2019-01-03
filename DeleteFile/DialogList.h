#if !defined(AFX_DIALOGLIST_H__A7A6AF29_3ACF_4845_BEE9_37DBD318D890__INCLUDED_)
#define AFX_DIALOGLIST_H__A7A6AF29_3ACF_4845_BEE9_37DBD318D890__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogList.h : header file
//
#include "DialogNode.h"
/////////////////////////////////////////////////////////////////////////////
// CDialogList window

class CDialogList : public CWnd
{
// Construction
public:
	CDialogList();
// Attributes
public:
	CDialogNode*	head;
	CDialogNode*	last;

	int			iCount;
// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogList)
	//}}AFX_VIRTUAL

// Implementation
public:
	int GetCount();
	void Insert(CDialogNode*);
	void Insert(CDialogNode*,int n);
	CWnd* GetLast();
	CWnd* GetHead();
	void RemoveAll();
	void Remove(int n);
	CWnd* Get(int n);
	virtual ~CDialogList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDialogList)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGLIST_H__A7A6AF29_3ACF_4845_BEE9_37DBD318D890__INCLUDED_)
