#if !defined(AFX_WAREHOUSE_H__161FEF74_B8A2_43E0_9DD5_694323247CD1__INCLUDED_)
#define AFX_WAREHOUSE_H__161FEF74_B8A2_43E0_9DD5_694323247CD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WareHouse.h : header file
//

#include "ExternParent.h"
#define WM_CREATE_WND  WM_USER + 100

/////////////////////////////////////////////////////////////////////////////
// CWareHouse dialog

class CWareHouse : public CDialog
{
// Construction
public:
	CWareHouse(CWnd* pParent = NULL);   // standard constructor
	CBrush brush;
	CExternParent	m_Parent;
	CWnd			*pWnd;
	CString			UserName;

//	HWND			hWnd;
// Dialog Data
	//{{AFX_DATA(CWareHouse)
	enum { IDD = IDD_WAREHOUSE_CHILDTEXT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWareHouse)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWareHouse)
	afx_msg void OnGodownentry();
	afx_msg void OnExitls();
	afx_msg void OnStocking();
	afx_msg void OnAdjustment();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAREHOUSE_H__161FEF74_B8A2_43E0_9DD5_694323247CD1__INCLUDED_)
