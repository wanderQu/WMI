#if !defined(AFX_ASSERTRECEIVABLE_H__926BA078_7491_4EB8_B34E_651F8C81D4CE__INCLUDED_)
#define AFX_ASSERTRECEIVABLE_H__926BA078_7491_4EB8_B34E_651F8C81D4CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssertReceivable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAssertReceivable dialog

class CAssertReceivable : public CDialog
{
// Construction
public:
	CAssertReceivable(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CAssertReceivable)
	enum { IDD = IDD_ASSERT_RECEIVABLE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssertReceivable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAssertReceivable)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSERTRECEIVABLE_H__926BA078_7491_4EB8_B34E_651F8C81D4CE__INCLUDED_)
