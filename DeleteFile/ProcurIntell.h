#if !defined(AFX_PROCURINTELL_H__3FA98229_FD6E_40C5_9F2B_78C3702BD661__INCLUDED_)
#define AFX_PROCURINTELL_H__3FA98229_FD6E_40C5_9F2B_78C3702BD661__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProcurIntell.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProcurIntell dialog

class CProcurIntell : public CDialog
{
// Construction
public:
	CProcurIntell(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CProcurIntell)
	enum { IDD = IDD_PROCUR_INTELL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcurIntell)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProcurIntell)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCURINTELL_H__3FA98229_FD6E_40C5_9F2B_78C3702BD661__INCLUDED_)
