#if !defined(AFX_DATAVOUCHER_H__EAD3FB78_A7F5_4D9D_9E8E_B1C8F692055C__INCLUDED_)
#define AFX_DATAVOUCHER_H__EAD3FB78_A7F5_4D9D_9E8E_B1C8F692055C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataVoucher.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataVoucher dialog

class CDataVoucher : public CDialog
{
// Construction
public:
	CDataVoucher(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CDataVoucher)
	enum { IDD = IDD_DATA_VOUCHER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataVoucher)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDataVoucher)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAVOUCHER_H__EAD3FB78_A7F5_4D9D_9E8E_B1C8F692055C__INCLUDED_)
