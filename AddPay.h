#if !defined(AFX_ADDPAY_H__6CBF1D4E_80EB_4919_8C77_D43BFB89D78C__INCLUDED_)
#define AFX_ADDPAY_H__6CBF1D4E_80EB_4919_8C77_D43BFB89D78C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddPay.h : header file
//
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddPay dialog

class CAddPay : public CDialog
{
// Construction
public:
	CAddPay(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	int opt;
	CString UserName;
	CString result;
	CString sql;
// Dialog Data
	//{{AFX_DATA(CAddPay)
	enum { IDD = IDD_ADD_PAY };
	CEdit	m_DelPay;
	CEdit	m_Pay;
	CComboBox	m_SupID;
	CListCtrl	m_Ls;
	CEdit	m_Text;
	CComboBox	m_MoneyType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddPay)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddPay)
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

#endif // !defined(AFX_ADDPAY_H__6CBF1D4E_80EB_4919_8C77_D43BFB89D78C__INCLUDED_)
