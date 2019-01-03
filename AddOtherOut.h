#if !defined(AFX_ADDOTHEROUT_H__3365126B_6B4C_4CAE_970D_996E809EB5F7__INCLUDED_)
#define AFX_ADDOTHEROUT_H__3365126B_6B4C_4CAE_970D_996E809EB5F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddOtherOut.h : header file
//
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddOtherOut dialog

class CAddOtherOut : public CDialog
{
// Construction
public:
	CAddOtherOut(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	CString UserName;
	CString sql;
// Dialog Data
	//{{AFX_DATA(CAddOtherOut)
	enum { IDD = IDD_ADD_OTHEROUT };
	CListCtrl	m_Ls;
	CEdit	m_Text;
	CEdit	m_Money;
	CComboBox	m_MoneyType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddOtherOut)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddOtherOut)
	afx_msg void OnDelete();
	afx_msg void OnAdd();
	afx_msg void OnOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDOTHEROUT_H__3365126B_6B4C_4CAE_970D_996E809EB5F7__INCLUDED_)
