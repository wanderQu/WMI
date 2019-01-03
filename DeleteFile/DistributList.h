#if !defined(AFX_DISTRIBUTLIST_H__445AB7AB_1222_437C_B7F9_237CBE77BF3C__INCLUDED_)
#define AFX_DISTRIBUTLIST_H__445AB7AB_1222_437C_B7F9_237CBE77BF3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DistributList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDistributList dialog

class CDistributList : public CDialog
{
// Construction
public:
	CDistributList(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CDistributList)
	enum { IDD = IDD_DISTRIBUT_LIST };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDistributList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDistributList)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISTRIBUTLIST_H__445AB7AB_1222_437C_B7F9_237CBE77BF3C__INCLUDED_)
