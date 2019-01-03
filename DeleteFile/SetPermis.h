#if !defined(AFX_SETPERMIS_H__D8505BC4_F0D1_43AE_81BE_CA75443A17C8__INCLUDED_)
#define AFX_SETPERMIS_H__D8505BC4_F0D1_43AE_81BE_CA75443A17C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetPermis.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetPermis dialog

class CSetPermis : public CDialog
{
// Construction
public:
	CSetPermis(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CSetPermis)
	enum { IDD = IDD_SET_PERMIS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetPermis)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetPermis)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETPERMIS_H__D8505BC4_F0D1_43AE_81BE_CA75443A17C8__INCLUDED_)
