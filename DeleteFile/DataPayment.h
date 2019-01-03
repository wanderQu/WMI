#if !defined(AFX_DATAPAYMENT_H__5037D530_665F_4371_88D6_F7D7B63EA85F__INCLUDED_)
#define AFX_DATAPAYMENT_H__5037D530_665F_4371_88D6_F7D7B63EA85F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataPayment.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataPayment dialog

class CDataPayment : public CDialog
{
// Construction
public:
	CDataPayment(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CDataPayment)
	enum { IDD = IDD_DATA_PAYMENT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataPayment)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDataPayment)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAPAYMENT_H__5037D530_665F_4371_88D6_F7D7B63EA85F__INCLUDED_)
