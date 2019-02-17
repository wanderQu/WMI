#if !defined(AFX_ADDORDER_H__257B4CE2_D110_4865_B564_8596B3FAF840__INCLUDED_)
#define AFX_ADDORDER_H__257B4CE2_D110_4865_B564_8596B3FAF840__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddOrder.h : header file
//
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddOrder dialog

class CAddOrder : public CDialog
{
// Construction
public:
	CAddOrder(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	int opt;
	CString UserName;
	CString result;
// Dialog Data
	//{{AFX_DATA(CAddOrder)
	enum { IDD = IDD_ADD_ORDER };
	CEdit	m_Text;
	CEdit	m_Num;
	CListCtrl	m_Ls;
	CComboBox	m_GoodId;
	//}}AFX_DATA



// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddOrder)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddOrder)
	virtual BOOL OnInitDialog();
	afx_msg void OnOk();
	afx_msg void OnAdd();
	afx_msg void OnClose();
	afx_msg void OnChangeEdit1();
	afx_msg void OnEditchangeCombo1();
	afx_msg void OnCancel();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDORDER_H__257B4CE2_D110_4865_B564_8596B3FAF840__INCLUDED_)
