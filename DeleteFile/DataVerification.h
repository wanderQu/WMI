#if !defined(AFX_DATAVERIFICATION_H__7DBDD976_F3EB_4D07_A9A6_5C236F61D2D1__INCLUDED_)
#define AFX_DATAVERIFICATION_H__7DBDD976_F3EB_4D07_A9A6_5C236F61D2D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataVerification.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataVerification dialog

class CDataVerification : public CDialog
{
// Construction
public:
	CDataVerification(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CDataVerification)
	enum { IDD = IDD_DATA_VERIFICATION };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataVerification)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDataVerification)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAVERIFICATION_H__7DBDD976_F3EB_4D07_A9A6_5C236F61D2D1__INCLUDED_)
