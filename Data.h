#if !defined(AFX_DATA_H__B7BB350A_FAB8_436D_96CF_C7C5E4F2DA63__INCLUDED_)
#define AFX_DATA_H__B7BB350A_FAB8_436D_96CF_C7C5E4F2DA63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Data.h : header file
//
#include "ExternParent.h"
#define WM_CREATE_WND  WM_USER + 100
/////////////////////////////////////////////////////////////////////////////
// CData dialog

class CData : public CDialog
{
// Construction
public:
	CData(CWnd* pParent = NULL);   // standard constructor
	CBrush brush;
	CExternParent	m_Parent;
	CWnd			*pWnd;
	CString			UserName;
// Dialog Data
	//{{AFX_DATA(CData)
	enum { IDD = IDD_DATA_CHILDTEXT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CData)
	afx_msg void OnVoucher();
	afx_msg void OnPayment();
	afx_msg void OnOtherincome();
	afx_msg void OnExpenditure();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnRecvable();
	afx_msg void OnPayable();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATA_H__B7BB350A_FAB8_436D_96CF_C7C5E4F2DA63__INCLUDED_)
