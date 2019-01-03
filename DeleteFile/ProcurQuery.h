#if !defined(AFX_PROCURQUERY_H__11721145_BCE2_48FB_9F38_419A7D8A3275__INCLUDED_)
#define AFX_PROCURQUERY_H__11721145_BCE2_48FB_9F38_419A7D8A3275__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProcurQuery.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProcurQuery dialog

class CProcurQuery : public CDialog
{
// Construction
public:
	CProcurQuery(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CProcurQuery)
	enum { IDD = IDD_PROCUR_QUERY };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcurQuery)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProcurQuery)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCURQUERY_H__11721145_BCE2_48FB_9F38_419A7D8A3275__INCLUDED_)
