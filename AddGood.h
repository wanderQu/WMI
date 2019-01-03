#if !defined(AFX_ADDGOOD_H__8D3D8BAD_DA87_4B10_851D_B712ADF6F989__INCLUDED_)
#define AFX_ADDGOOD_H__8D3D8BAD_DA87_4B10_851D_B712ADF6F989__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddGood.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AddGood dialog
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddDistri dialog

class AddGood : public CDialog
{
// Construction
public:
	AddGood(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	int opt;
	CString sql;
	CString UserName;
	CString result;
// Dialog Data
	//{{AFX_DATA(AddGood)
	enum { IDD = IDD_ADD_GOODS };
	CListCtrl	m_Ls;
	CEdit	m_Price;
	CEdit	m_Min;
	CEdit	m_Name;
	CComboBox	m_SupID;
	CComboBox	m_WareID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AddGood)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AddGood)
	afx_msg void OnDelete();
	afx_msg void OnOk();
	afx_msg void OnChangePrice();
	afx_msg void OnChangeMin();
	virtual BOOL OnInitDialog();
	afx_msg void OnEditchangeCombo1();
	afx_msg void OnEditchangeCombo2();
	afx_msg void OnAdd();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDGOOD_H__8D3D8BAD_DA87_4B10_851D_B712ADF6F989__INCLUDED_)
