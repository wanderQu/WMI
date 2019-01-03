#if !defined(AFX_ASSETS_H__CE5CAB79_0081_4D54_AABB_D04D0490E172__INCLUDED_)
#define AFX_ASSETS_H__CE5CAB79_0081_4D54_AABB_D04D0490E172__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Assets.h : header file
//
#include "ExternParent.h"
#define WM_CREATE_WND  WM_USER + 100
/////////////////////////////////////////////////////////////////////////////
// CAssets dialog

class CAssets : public CDialog
{
// Construction
public:
	CAssets(CWnd* pParent = NULL);   // standard constructor
	CBrush			brush;
	CExternParent	m_Parent;
	CWnd			*pWnd;
// Dialog Data
	//{{AFX_DATA(CAssets)
	enum { IDD = IDD_ASSETS_CHILDTEXT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssets)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAssets)
	afx_msg void OnExpense();
	afx_msg void OnSchedulepay();
	afx_msg void OnSchedulereceive();
	afx_msg void OnCusstatement();
	afx_msg void OnVendorstatment();
	afx_msg void OnOtherincome();
	afx_msg void OnIncomestatement();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnIncome();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSETS_H__CE5CAB79_0081_4D54_AABB_D04D0490E172__INCLUDED_)
