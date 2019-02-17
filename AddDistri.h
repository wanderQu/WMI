#if !defined(AFX_ADDDISTRI_H__4EC1C510_2FB4_43AB_ABA9_0DEBC393FF28__INCLUDED_)
#define AFX_ADDDISTRI_H__4EC1C510_2FB4_43AB_ABA9_0DEBC393FF28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddDistri.h : header file
//
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddDistri dialog

class CAddDistri : public CDialog
{
// Construction
public:
	CAddDistri(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	int opt;
	CString sql;
	CString UserName;
	CString result;
// Dialog Data
	//{{AFX_DATA(CAddDistri)
	enum { IDD = IDD_ADD_DISTRI };
	CEdit	m_Text;
	CListCtrl	m_Ls;
	CEdit	m_Num;
	CComboBox	m_GoodID;
	CComboBox	m_CusID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddDistri)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddDistri)
	afx_msg void OnAdd();
	afx_msg void OnOk();
	afx_msg void OnDelete();
	virtual BOOL OnInitDialog();
	afx_msg void OnEditchangeCombo1();
	afx_msg void OnEditchangeCombo2();
	afx_msg void OnChangeEdit1();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDISTRI_H__4EC1C510_2FB4_43AB_ABA9_0DEBC393FF28__INCLUDED_)
