#if !defined(AFX_SET_H__B5412A8F_FE10_40B7_BE35_F58DAC8F31C4__INCLUDED_)
#define AFX_SET_H__B5412A8F_FE10_40B7_BE35_F58DAC8F31C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Set.h : header file
//
#include "ExternParent.h"
#include "SetSysParam.h"
#define WM_CREATE_WND  WM_USER + 100
/////////////////////////////////////////////////////////////////////////////
// CSet dialog

class CSet : public CDialog
{
// Construction
public:
	CSet(CWnd* pParent = NULL);   // standard constructor
	CBrush brush;
	CExternParent	m_Parent;
	CWnd			*pWnd;
	CSetSysParam	m_param;
	CString			UserName;
// Dialog Data
	//{{AFX_DATA(CSet)
	enum { IDD = IDD_SET_CHILDTEXT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSet)
	afx_msg void OnSysset();
	afx_msg void OnOperatlog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SET_H__B5412A8F_FE10_40B7_BE35_F58DAC8F31C4__INCLUDED_)
