#if !defined(AFX_MANAGECUS_H__52A14A26_058C_4EB6_BA5E_13899472D0C5__INCLUDED_)
#define AFX_MANAGECUS_H__52A14A26_058C_4EB6_BA5E_13899472D0C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ManageCus.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CManageCus dialog

class CManageCus : public CDialog
{
// Construction
public:
	CManageCus(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CManageCus)
	enum { IDD = IDD_MANAGE_CUS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManageCus)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManageCus)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGECUS_H__52A14A26_058C_4EB6_BA5E_13899472D0C5__INCLUDED_)
