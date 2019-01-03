#if !defined(AFX_SETLOG_H__B2EA6598_2B03_424A_80B5_D827D3E0D5AA__INCLUDED_)
#define AFX_SETLOG_H__B2EA6598_2B03_424A_80B5_D827D3E0D5AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetLog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetLog dialog

class CSetLog : public CDialog
{
// Construction
public:
	CSetLog(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CSetLog)
	enum { IDD = IDD_SET_LOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetLog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetLog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETLOG_H__B2EA6598_2B03_424A_80B5_D827D3E0D5AA__INCLUDED_)
