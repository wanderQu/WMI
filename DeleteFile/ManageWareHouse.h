#if !defined(AFX_MANAGEWAREHOUSE_H__39D847C1_3579_4CD0_9EC6_C1D3A69616A6__INCLUDED_)
#define AFX_MANAGEWAREHOUSE_H__39D847C1_3579_4CD0_9EC6_C1D3A69616A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ManageWareHouse.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CManageWareHouse dialog

class CManageWareHouse : public CDialog
{
// Construction
public:
	CManageWareHouse(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CManageWareHouse)
	enum { IDD = IDD_MANAGE_WAREHOUSE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManageWareHouse)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManageWareHouse)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEWAREHOUSE_H__39D847C1_3579_4CD0_9EC6_C1D3A69616A6__INCLUDED_)
