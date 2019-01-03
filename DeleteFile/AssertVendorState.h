#if !defined(AFX_ASSERTVENDORSTATE_H__43AA31EB_3EBE_4AEA_A3DB_3810AB150810__INCLUDED_)
#define AFX_ASSERTVENDORSTATE_H__43AA31EB_3EBE_4AEA_A3DB_3810AB150810__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssertVendorState.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAssertVendorState dialog

class CAssertVendorState : public CDialog
{
// Construction
public:
	CAssertVendorState(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CAssertVendorState)
	enum { IDD = IDD_ASSERT_VENDOR_STATE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssertVendorState)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAssertVendorState)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSERTVENDORSTATE_H__43AA31EB_3EBE_4AEA_A3DB_3810AB150810__INCLUDED_)
