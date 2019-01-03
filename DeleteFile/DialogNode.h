#if !defined(AFX_DIALOGNODE_H__68E06BC9_1EF7_40D3_8A1D_7866C7FA855B__INCLUDED_)
#define AFX_DIALOGNODE_H__68E06BC9_1EF7_40D3_8A1D_7866C7FA855B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogNode.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogNode window

class CDialogNode : public CWnd
{
// Construction
public:
	CDialogNode();
//	CDialogNode(CWnd* t):info(t),next(0){}
// Attributes
public:
	CDialog*		info;
	CDialogNode*	next;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogNode)
	//}}AFX_VIRTUAL

// Implementation
public:
	CWnd* Get();
	virtual ~CDialogNode();

	// Generated message map functions
protected:
	//{{AFX_MSG(CDialogNode)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGNODE_H__68E06BC9_1EF7_40D3_8A1D_7866C7FA855B__INCLUDED_)
