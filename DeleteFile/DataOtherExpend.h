#if !defined(AFX_DATAOTHEREXPEND_H__2E3B322F_A052_416D_A569_DF1C8059A68E__INCLUDED_)
#define AFX_DATAOTHEREXPEND_H__2E3B322F_A052_416D_A569_DF1C8059A68E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataOtherExpend.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataOtherExpend dialog

class CDataOtherExpend : public CDialog
{
// Construction
public:
	CDataOtherExpend(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CDataOtherExpend)
	enum { IDD = IDD_DATA_OTHER_EXPEND };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataOtherExpend)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDataOtherExpend)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAOTHEREXPEND_H__2E3B322F_A052_416D_A569_DF1C8059A68E__INCLUDED_)
