#if !defined(AFX_WAREHOUSEOUT_H__1E4D493F_F1C9_4FA3_BDFA_59A35518AE58__INCLUDED_)
#define AFX_WAREHOUSEOUT_H__1E4D493F_F1C9_4FA3_BDFA_59A35518AE58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WareHouseOut.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWareHouseOut dialog

class CWareHouseOut : public CDialog
{
// Construction
public:
	CWareHouseOut(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CWareHouseOut)
	enum { IDD = IDD_WAREHOUSE_OUT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWareHouseOut)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWareHouseOut)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAREHOUSEOUT_H__1E4D493F_F1C9_4FA3_BDFA_59A35518AE58__INCLUDED_)
