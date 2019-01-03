#if !defined(AFX_DATATRANSFER_H__4D027F3B_7A22_4CF8_9E2E_E386B8B28F87__INCLUDED_)
#define AFX_DATATRANSFER_H__4D027F3B_7A22_4CF8_9E2E_E386B8B28F87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataTransfer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataTransfer dialog

class CDataTransfer : public CDialog
{
// Construction
public:
	CDataTransfer(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CDataTransfer)
	enum { IDD = IDD_DATA_TRANSFER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataTransfer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDataTransfer)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATATRANSFER_H__4D027F3B_7A22_4CF8_9E2E_E386B8B28F87__INCLUDED_)
