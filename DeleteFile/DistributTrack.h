#if !defined(AFX_DISTRIBUTTRACK_H__F3D8CAA0_DE65_4E03_AC4A_4E4EF909F7F9__INCLUDED_)
#define AFX_DISTRIBUTTRACK_H__F3D8CAA0_DE65_4E03_AC4A_4E4EF909F7F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DistributTrack.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDistributTrack dialog

class CDistributTrack : public CDialog
{
// Construction
public:
	CDistributTrack(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CDistributTrack)
	enum { IDD = IDD_DISTRIBUT_TRACK };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDistributTrack)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDistributTrack)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISTRIBUTTRACK_H__F3D8CAA0_DE65_4E03_AC4A_4E4EF909F7F9__INCLUDED_)
