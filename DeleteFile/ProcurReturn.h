#if !defined(AFX_PROCURRETURN_H__D9B16E61_7E43_4671_B9EA_2B9FE528EF3D__INCLUDED_)
#define AFX_PROCURRETURN_H__D9B16E61_7E43_4671_B9EA_2B9FE528EF3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProcurReturn.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProcurReturn dialog

class CProcurReturn : public CDialog
{
// Construction
public:
	CProcurReturn(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CProcurReturn)
	enum { IDD = IDD_PROCUR_RETURN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcurReturn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProcurReturn)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCURRETURN_H__D9B16E61_7E43_4671_B9EA_2B9FE528EF3D__INCLUDED_)
