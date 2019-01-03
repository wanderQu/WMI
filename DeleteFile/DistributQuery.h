#if !defined(AFX_DISTRIBUTQUERY_H__F9CC88BA_3D11_46EA_918C_D1FE05086CDA__INCLUDED_)
#define AFX_DISTRIBUTQUERY_H__F9CC88BA_3D11_46EA_918C_D1FE05086CDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DistributQuery.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDistributQuery dialog

class CDistributQuery : public CDialog
{
// Construction
public:
	CDistributQuery(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CDistributQuery)
	enum { IDD = IDD_DISTRIBUT_QUERY };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDistributQuery)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDistributQuery)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISTRIBUTQUERY_H__F9CC88BA_3D11_46EA_918C_D1FE05086CDA__INCLUDED_)
