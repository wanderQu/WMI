#if !defined(AFX_WAREOUT_H__C8D45097_9EEF_4609_B515_C12BD16DF374__INCLUDED_)
#define AFX_WAREOUT_H__C8D45097_9EEF_4609_B515_C12BD16DF374__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WareOut.h : header file
//

#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CWareOut dialog

class CWareOut : public CDialog
{
// Construction
public:
	CWareOut(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	int opt;
	CString UserName;
	CString result;
	CString sql;
	CString tbName;
// Dialog Data
	//{{AFX_DATA(CWareOut)
	enum { IDD = IDD_ADD_WAREOUT };
	CComboBox	m_GoodID;
	CListCtrl	m_Ls;
	CEdit	m_Num;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWareOut)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWareOut)
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

#endif // !defined(AFX_WAREOUT_H__C8D45097_9EEF_4609_B515_C12BD16DF374__INCLUDED_)
