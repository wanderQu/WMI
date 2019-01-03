#if !defined(AFX_ASSERTPAYABLE_H__9CEDB52C_21C8_4559_90F0_3F04F305854E__INCLUDED_)
#define AFX_ASSERTPAYABLE_H__9CEDB52C_21C8_4559_90F0_3F04F305854E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssertPayable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAssertPayable dialog

class CAssertPayable : public CDialog
{
// Construction
public:
	CAssertPayable(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CAssertPayable)
	enum { IDD = IDD_ASSERT_PAYABLE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssertPayable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAssertPayable)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSERTPAYABLE_H__9CEDB52C_21C8_4559_90F0_3F04F305854E__INCLUDED_)
