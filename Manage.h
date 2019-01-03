#if !defined(AFX_MANAGE_H__C78BB12F_7D10_4A49_8E14_97799F46DAD6__INCLUDED_)
#define AFX_MANAGE_H__C78BB12F_7D10_4A49_8E14_97799F46DAD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Manage.h : header file
//
#include "ExternParent.h"
#define WM_CREATE_WND  WM_USER + 100
/////////////////////////////////////////////////////////////////////////////
// CManage dialog

class CManage : public CDialog
{
// Construction
public:
	CManage(CWnd* pParent = NULL);   // standard constructor
	CBrush brush;
	CExternParent	m_Parent;
	CWnd			*pWnd;
	CString			UserName;
// Dialog Data
	//{{AFX_DATA(CManage)
	enum { IDD = IDD_MANAGE_CHILDTEXT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManage)
	afx_msg void OnCusmanage();
	afx_msg void OnSupplymanage();
	afx_msg void OnGodsmanage();
	afx_msg void OnWarehousemanage();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnEmploy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGE_H__C78BB12F_7D10_4A49_8E14_97799F46DAD6__INCLUDED_)
