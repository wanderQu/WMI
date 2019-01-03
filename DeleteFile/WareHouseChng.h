#if !defined(AFX_WAREHOUSECHNG_H__86102B04_AAF5_4B70_BF7E_07C778E17643__INCLUDED_)
#define AFX_WAREHOUSECHNG_H__86102B04_AAF5_4B70_BF7E_07C778E17643__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WareHouseChng.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWareHouseChng dialog

class CWareHouseChng : public CDialog
{
// Construction
public:
	CWareHouseChng(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CWareHouseChng)
	enum { IDD = IDD_WAREHOUSE_CHNG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWareHouseChng)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWareHouseChng)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAREHOUSECHNG_H__86102B04_AAF5_4B70_BF7E_07C778E17643__INCLUDED_)
