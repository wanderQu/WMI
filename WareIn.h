#if !defined(AFX_WAREIN_H__93F7E41D_3142_4E14_B8A2_A198B77499DF__INCLUDED_)
#define AFX_WAREIN_H__93F7E41D_3142_4E14_B8A2_A198B77499DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WareIn.h : header file
//

#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CWareIn dialog

class CWareIn : public CDialog
{
// Construction
public:
	CWareIn(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	int opt;
	CString UserName;
	CString result;
	CString sql;
	CString tbName;
// Dialog Data
	//{{AFX_DATA(CWareIn)
	enum { IDD = IDD_ADD_WAREIN };
	CComboBox	m_GoodID;
	CListCtrl	m_Ls;
	CEdit	m_Num;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWareIn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWareIn)
	afx_msg void OnAdd();
	afx_msg void OnOk();
	afx_msg void OnDelete();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAREIN_H__93F7E41D_3142_4E14_B8A2_A198B77499DF__INCLUDED_)
