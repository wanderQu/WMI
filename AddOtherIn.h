#if !defined(AFX_ADDOTHERIN_H__2D708FA5_A2DA_426A_B183_44910B103E54__INCLUDED_)
#define AFX_ADDOTHERIN_H__2D708FA5_A2DA_426A_B183_44910B103E54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddOtherIn.h : header file
//
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddOtherIn dialog

class CAddOtherIn : public CDialog
{
// Construction
public:
	CAddOtherIn(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	CString UserName;
	CString sql;
// Dialog Data
	//{{AFX_DATA(CAddOtherIn)
	enum { IDD = IDD_ADD_OTHERIN };
	CListCtrl	m_Ls;
	CEdit	m_Text;
	CEdit	m_Money;
	CComboBox	m_MoneyType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddOtherIn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddOtherIn)
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

#endif // !defined(AFX_ADDOTHERIN_H__2D708FA5_A2DA_426A_B183_44910B103E54__INCLUDED_)
