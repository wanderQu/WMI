#if !defined(AFX_ADDWAREADJ_H__512C476C_7643_4CD1_9546_8388A232C354__INCLUDED_)
#define AFX_ADDWAREADJ_H__512C476C_7643_4CD1_9546_8388A232C354__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddWareAdj.h : header file
//

#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CAddWareAdj dialog

class CAddWareAdj : public CDialog
{
// Construction
public:
	CAddWareAdj(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	int opt;
	CString sql;
	CString UserName;
	CString result;
// Dialog Data
	//{{AFX_DATA(CAddWareAdj)
	enum { IDD = IDD_ADD_WARE_ADJ };
	CComboBox	m_GoodID;
	CEdit	m_Text;
	CEdit	m_RePrice;
	CEdit	m_ReNum;
	CListCtrl	m_Ls;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddWareAdj)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddWareAdj)
	afx_msg void OnAdd();
	afx_msg void OnOk();
	afx_msg void OnDelete();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDWAREADJ_H__512C476C_7643_4CD1_9546_8388A232C354__INCLUDED_)
