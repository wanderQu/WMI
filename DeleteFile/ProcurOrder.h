#if !defined(AFX_PROCURORDER_H__C19C7999_1F57_4C01_8387_86CA0C717858__INCLUDED_)
#define AFX_PROCURORDER_H__C19C7999_1F57_4C01_8387_86CA0C717858__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProcurOrder.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProcurOrder dialog

class CProcurOrder : public CDialog
{
// Construction
public:
	CProcurOrder(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CProcurOrder)
	enum { IDD = IDD_PROCUR_ORDER };
	CEdit	m_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcurOrder)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProcurOrder)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCURORDER_H__C19C7999_1F57_4C01_8387_86CA0C717858__INCLUDED_)
