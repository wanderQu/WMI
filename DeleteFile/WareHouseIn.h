#if !defined(AFX_WAREHOUSEIN_H__C9F249A1_EBDC_4E5A_A6DF_389C60070B05__INCLUDED_)
#define AFX_WAREHOUSEIN_H__C9F249A1_EBDC_4E5A_A6DF_389C60070B05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WareHouseIn.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWareHouseIn dialog

class CWareHouseIn : public CDialog
{
// Construction
public:
	CWareHouseIn(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CWareHouseIn)
	enum { IDD = IDD_WAREHOUSE_IN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWareHouseIn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWareHouseIn)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAREHOUSEIN_H__C9F249A1_EBDC_4E5A_A6DF_389C60070B05__INCLUDED_)
