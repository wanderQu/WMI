#if !defined(AFX_MANAGESUPPLY_H__D51A2260_F7A9_4B23_A9EB_9250EB38D13C__INCLUDED_)
#define AFX_MANAGESUPPLY_H__D51A2260_F7A9_4B23_A9EB_9250EB38D13C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ManageSupply.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CManageSupply dialog

class CManageSupply : public CDialog
{
// Construction
public:
	CManageSupply(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CManageSupply)
	enum { IDD = IDD_MANAGE_SUPPLY };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManageSupply)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManageSupply)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGESUPPLY_H__D51A2260_F7A9_4B23_A9EB_9250EB38D13C__INCLUDED_)
