#if !defined(AFX_ADDPRORETURN_H__F1D1BE72_5223_4FCD_B571_7002F6EFF47F__INCLUDED_)
#define AFX_ADDPRORETURN_H__F1D1BE72_5223_4FCD_B571_7002F6EFF47F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddProReturn.h : header file
//
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddProReturn dialog

class CAddProReturn : public CDialog
{
// Construction
public:
	CAddProReturn(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	int opt;
	CString UserName;
	CString result;
// Dialog Data
	//{{AFX_DATA(CAddProReturn)
	enum { IDD = IDD_ADD_ORDER_RETURN };
	CComboBox	m_GoodId;
	CListCtrl	m_Ls;
	CEdit	m_Text;
	CEdit	m_Num;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddProReturn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddProReturn)
	afx_msg void OnOk();
	afx_msg void OnDelete();
	afx_msg void OnAdd();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDPRORETURN_H__F1D1BE72_5223_4FCD_B571_7002F6EFF47F__INCLUDED_)
