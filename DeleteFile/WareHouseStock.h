#if !defined(AFX_WAREHOUSESTOCK_H__3DCA9D04_79F7_449E_A755_28E11A373C9F__INCLUDED_)
#define AFX_WAREHOUSESTOCK_H__3DCA9D04_79F7_449E_A755_28E11A373C9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WareHouseStock.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWareHouseStock dialog

class CWareHouseStock : public CDialog
{
// Construction
public:
	CWareHouseStock(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CWareHouseStock)
	enum { IDD = IDD_WAREHOUSE_STOCK };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWareHouseStock)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWareHouseStock)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAREHOUSESTOCK_H__3DCA9D04_79F7_449E_A755_28E11A373C9F__INCLUDED_)
