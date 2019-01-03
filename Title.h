#if !defined(AFX_TITLE_H__F9CC4D45_9191_4B05_927F_BC6D372126D0__INCLUDED_)
#define AFX_TITLE_H__F9CC4D45_9191_4B05_927F_BC6D372126D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Title.h : header file
//
#include "hangePass.h"
/////////////////////////////////////////////////////////////////////////////
// CTitle dialog

class CTitle : public CDialog
{
// Construction
public:
	CTitle(CWnd* pParent = NULL);   // standard constructor
	CBrush brush;
	CWnd* Parent;
	CString			UserName;
//	int i;
// Dialog Data
	//{{AFX_DATA(CTitle)
	enum { IDD = IDD_TITLE_CHILDTEXT };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTitle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTitle)
	afx_msg void OnPersonLog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLogout();
	afx_msg void OnChangePass();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TITLE_H__F9CC4D45_9191_4B05_927F_BC6D372126D0__INCLUDED_)
