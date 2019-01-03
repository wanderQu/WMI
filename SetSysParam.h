#if !defined(AFX_SETSYSPARAM_H__E3AD2C1A_A29B_4E68_970C_0A8278D08EC9__INCLUDED_)
#define AFX_SETSYSPARAM_H__E3AD2C1A_A29B_4E68_970C_0A8278D08EC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetSysParam.h : header file
//
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CSetSysParam dialog

class CSetSysParam : public CDialog
{
// Construction
public:
	CRect rcPaint;
	CSetSysParam(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;
/*	char companyName[50];
	char companyAdd[50];
	char companyPhone[50];
	char companyMail[50];
	char front[50];
	char behind[50];
	char num[50];*/
	CString			UserName;
	CString			info[4];
	sqlite3			*db;
// Dialog Data
	//{{AFX_DATA(CSetSysParam)
	enum { IDD = IDD_SET_SYS_PARAM };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetSysParam)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetSysParam)
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusEdit1();
	afx_msg void OnKillfocusEdit2();
	afx_msg void OnKillfocusEdit3();
	afx_msg void OnKillfocusEdit4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETSYSPARAM_H__E3AD2C1A_A29B_4E68_970C_0A8278D08EC9__INCLUDED_)
