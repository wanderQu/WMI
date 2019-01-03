#if !defined(AFX_ADDDISTRIRETURN_H__66BE5823_CCEA_4A27_AD60_07F100A1392A__INCLUDED_)
#define AFX_ADDDISTRIRETURN_H__66BE5823_CCEA_4A27_AD60_07F100A1392A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddDistriReturn.h : header file
//
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddDistriReturn dialog

class CAddDistriReturn : public CDialog
{
// Construction
public:
	CAddDistriReturn(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	int opt;
	CString UserName;
	CString result;
	CString sql;
	CString tbName;

// Dialog Data
	//{{AFX_DATA(CAddDistriReturn)
	enum { IDD = IDD_ADD_DISTRI_RETURN };
	CEdit	m_Text;
	CListCtrl	m_Ls;
	CEdit	m_Num;
	CComboBox	m_GoodID;
	CComboBox	m_CusID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddDistriReturn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddDistriReturn)
	afx_msg void OnDelete();
	afx_msg void OnAdd();
	afx_msg void OnOk();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDISTRIRETURN_H__66BE5823_CCEA_4A27_AD60_07F100A1392A__INCLUDED_)
