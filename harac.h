#if !defined(AFX_HARAC_H__574905B6_074A_4F21_8A2F_8A8FC7213DC5__INCLUDED_)
#define AFX_HARAC_H__574905B6_074A_4F21_8A2F_8A8FC7213DC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// harac.h : header file
//
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// Charac dialog


class Charac : public CDialog
{
// Construction
public:
	Charac(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	int opt;
	CString UserName;
	CString result;
	CString sql;
	CString tbName;
// Dialog Data
	//{{AFX_DATA(Charac)
	enum { IDD = IDD_ADD_CHARAC };
	CStatic	m_StaticContac;
	CStatic	m_StaticName;
	CComboBox	m_Opt;
	CEdit	m_Name;
	CListCtrl	m_Ls;
	CEdit	m_Contac;
	CEdit	m_Phone;
	CEdit	m_Account;
	CEdit	m_Address;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Charac)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Charac)
	afx_msg void OnAdd();
	afx_msg void OnOk();
	afx_msg void OnDelete();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeOpt();
	afx_msg void OnClose();
	afx_msg void OnChangeName();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HARAC_H__574905B6_074A_4F21_8A2F_8A8FC7213DC5__INCLUDED_)
