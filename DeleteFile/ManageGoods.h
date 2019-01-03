#if !defined(AFX_MANAGEGOODS_H__51AC5D7B_7AC3_48FC_AA48_F1D4BC0AC1A8__INCLUDED_)
#define AFX_MANAGEGOODS_H__51AC5D7B_7AC3_48FC_AA48_F1D4BC0AC1A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ManageGoods.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CManageGoods dialog

class CManageGoods : public CDialog
{
// Construction
public:
	CManageGoods(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CManageGoods)
	enum { IDD = IDD_MANAGE_GOODS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManageGoods)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManageGoods)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEGOODS_H__51AC5D7B_7AC3_48FC_AA48_F1D4BC0AC1A8__INCLUDED_)
