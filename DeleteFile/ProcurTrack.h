#if !defined(AFX_PROCURTRACK_H__DF152C65_A509_40B4_B3D7_467F78D85A14__INCLUDED_)
#define AFX_PROCURTRACK_H__DF152C65_A509_40B4_B3D7_467F78D85A14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProcurTrack.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProcurTrack dialog

class CProcurTrack : public CDialog
{
// Construction
public:
	CProcurTrack(CWnd* pParent = NULL);   // standard constructor
//	CString	strInfo;

// Dialog Data
	//{{AFX_DATA(CProcurTrack)
	enum { IDD = IDD_PROCUR_TRACK };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcurTrack)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProcurTrack)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCURTRACK_H__DF152C65_A509_40B4_B3D7_467F78D85A14__INCLUDED_)
