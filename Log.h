#if !defined(AFX_LOG_H__BE79C22D_CD8A_4A59_BEC3_9D0E60BFC6F1__INCLUDED_)
#define AFX_LOG_H__BE79C22D_CD8A_4A59_BEC3_9D0E60BFC6F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Log.h : header file
//
#pragma once
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CLog dialog
enum OPT
{
	SELECT,
	UPDATE,
	INSERT,
	GETNUMBER
};
class CLog : public CDialog
{
// Construction
public:
	CLog(CWnd* pParent = NULL);   // standard constructor
	sqlite3 *db;
	CString Name;
// Dialog Data
	//{{AFX_DATA(CLog)
	enum { IDD = IDD_LOG };
	CStatic	m_pic;
	//}}AFX_DATA
	CEdit	m_ID;
	CRect	rID;
	CEdit	m_Pass;
	CRect	rPswd;
	CButton	m_LOG;
	
	CStatic m_Fl;
	CRect   rFl;
public:
	void Log();
	CString err;
	CString strID,strPassWord;
	int opt;
	CString dbResult;
 
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLog)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLog)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	afx_msg void OnLog();
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOG_H__BE79C22D_CD8A_4A59_BEC3_9D0E60BFC6F1__INCLUDED_)
