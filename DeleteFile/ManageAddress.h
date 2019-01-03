#if !defined(AFX_MANAGEADDRESS_H__3678488A_CC8D_42EC_BC8C_B08E86E9AA34__INCLUDED_)
#define AFX_MANAGEADDRESS_H__3678488A_CC8D_42EC_BC8C_B08E86E9AA34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ManageAddress.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CManageAddress dialog

class CManageAddress : public CDialog
{
// Construction
public:
	CManageAddress(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CManageAddress)
	enum { IDD = IDD_MANAGE_ADDRESS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManageAddress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManageAddress)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEADDRESS_H__3678488A_CC8D_42EC_BC8C_B08E86E9AA34__INCLUDED_)
