#if !defined(AFX_ADDRECV_H__2F5C2F9F_5DE5_4619_ACA9_78BA39D5A6A6__INCLUDED_)
#define AFX_ADDRECV_H__2F5C2F9F_5DE5_4619_ACA9_78BA39D5A6A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddRecv.h : header file
//
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddRecv dialog

class CAddRecv : public CDialog
{
// Construction
public:
	CAddRecv(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	int opt;
	CString UserName;
	CString result;
	CString sql;
// Dialog Data
	//{{AFX_DATA(CAddRecv)
	enum { IDD = IDD_ADD_RECV };
	CListCtrl	m_Ls;
	CEdit	m_DelRecv;
	CEdit	m_Recv;
	CEdit	m_Text;
	CComboBox	m_MoneyType;
	CComboBox	m_CusID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddRecv)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddRecv)
	afx_msg void OnAdd();
	afx_msg void OnOk();
	afx_msg void OnDelete();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDRECV_H__2F5C2F9F_5DE5_4619_ACA9_78BA39D5A6A6__INCLUDED_)
