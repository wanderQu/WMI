#if !defined(AFX_ASSERTINCOMSTATE_H__F6DD6C88_C4FB_487F_80AC_860A99E0BA02__INCLUDED_)
#define AFX_ASSERTINCOMSTATE_H__F6DD6C88_C4FB_487F_80AC_860A99E0BA02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssertIncomState.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAssertIncomState dialog

class CAssertIncomState : public CDialog
{
// Construction
public:
	CAssertIncomState(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CAssertIncomState)
	enum { IDD = IDD_ASSERT_INCOM_STATE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssertIncomState)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAssertIncomState)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSERTINCOMSTATE_H__F6DD6C88_C4FB_487F_80AC_860A99E0BA02__INCLUDED_)
