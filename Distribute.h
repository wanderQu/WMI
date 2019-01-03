#if !defined(AFX_DISTRIBUTE_H__410492AC_F581_43E7_B3C1_4A7A6F13ACEA__INCLUDED_)
#define AFX_DISTRIBUTE_H__410492AC_F581_43E7_B3C1_4A7A6F13ACEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Distribute.h : header file
//
#include "ExternParent.h"
#define WM_CREATE_WND  WM_USER + 100
/////////////////////////////////////////////////////////////////////////////
// CDistribute dialog

class CDistribute : public CDialog
{
// Construction
public:
	CDistribute(CWnd* pParent = NULL);   // standard constructor
	CBrush brush;
	CExternParent	m_Parent;
	CWnd			*pWnd;
	CString			UserName;
// Dialog Data
	//{{AFX_DATA(CDistribute)
	enum { IDD = IDD_DISTRIBUT_CHILDTEXT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDistribute)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDistribute)
	afx_msg void OnDistribut();
	afx_msg void OnTacking();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnReturn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISTRIBUTE_H__410492AC_F581_43E7_B3C1_4A7A6F13ACEA__INCLUDED_)
