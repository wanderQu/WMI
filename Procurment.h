#if !defined(AFX_PROCURMENT_H__F1A57055_4A3E_4266_9C73_FEE8692E6315__INCLUDED_)
#define AFX_PROCURMENT_H__F1A57055_4A3E_4266_9C73_FEE8692E6315__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Procurment.h : header file
//
#include "ExternParent.h"
#define WM_CREATE_WND  WM_USER + 100
/////////////////////////////////////////////////////////////////////////////
// CProcurment dialog

class CProcurment : public CDialog
{
// Construction
public:
	CProcurment(CWnd* pParent = NULL);   // standard constructor
	CBrush brush;
	CExternParent	m_Parent;
	CWnd			*pWnd;
	CString			UserName;
// Dialog Data
	//{{AFX_DATA(CProcurment)
	enum { IDD = IDD_PROCUR_CHILDTEXT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcurment)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProcurment)
	afx_msg void OnOder();
	afx_msg void OnTracking();
	afx_msg void OnReturn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCURMENT_H__F1A57055_4A3E_4266_9C73_FEE8692E6315__INCLUDED_)
