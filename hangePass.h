#if !defined(AFX_HANGEPASS_H__53B8E638_5A1D_4EE3_8E4E_F3E41CE26EEA__INCLUDED_)
#define AFX_HANGEPASS_H__53B8E638_5A1D_4EE3_8E4E_F3E41CE26EEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// hangePass.h : header file
//
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// ChangePass dialog

class ChangePass : public CDialog
{
// Construction
public:
	ChangePass(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	int opt;
	CString UserName;
	CString sql;
	CString result;
// Dialog Data
	//{{AFX_DATA(ChangePass)
	enum { IDD = IDD_CHANGEPASS };
	CStatic	m_Text;
	CEdit	m_Confirm;
	CEdit	m_NewPass;
	CEdit	m_OldPass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChangePass)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ChangePass)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnSetfocusEdit2();
	virtual BOOL OnInitDialog();
	afx_msg void OnSetfocusEdit3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HANGEPASS_H__53B8E638_5A1D_4EE3_8E4E_F3E41CE26EEA__INCLUDED_)
