#if !defined(AFX_ASSERTEXPENSE_H__7892DD3E_0A48_4CEC_AB31_436E377FFC14__INCLUDED_)
#define AFX_ASSERTEXPENSE_H__7892DD3E_0A48_4CEC_AB31_436E377FFC14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssertExpense.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAssertExpense dialog

class CAssertExpense : public CDialog
{
// Construction
public:
	CAssertExpense(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CAssertExpense)
	enum { IDD = IDD_ASSERT_EXPENSE };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssertExpense)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAssertExpense)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSERTEXPENSE_H__7892DD3E_0A48_4CEC_AB31_436E377FFC14__INCLUDED_)
