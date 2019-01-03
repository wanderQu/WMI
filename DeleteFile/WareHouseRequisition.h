#if !defined(AFX_WAREHOUSEREQUISITON_H__0428884D_0594_4F9D_A420_DF12D9BCBEFC__INCLUDED_)
#define AFX_WAREHOUSEREQUISITON_H__0428884D_0594_4F9D_A420_DF12D9BCBEFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WareHouseRequisiton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWareHouseRequisiton dialog

class CWareHouseRequisition : public CDialog
{
// Construction
public:
	CWareHouseRequisition(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CWareHouseRequisiton)
	enum { IDD = IDD_WAREHOUSE_REQUISITION };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWareHouseRequisiton)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWareHouseRequisiton)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAREHOUSEREQUISITON_H__0428884D_0594_4F9D_A420_DF12D9BCBEFC__INCLUDED_)
