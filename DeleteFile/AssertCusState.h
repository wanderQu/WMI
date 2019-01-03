#if !defined(AFX_ASSERTCUSSTATE_H__35CDEB52_A848_4BFE_B491_133932F26C39__INCLUDED_)
#define AFX_ASSERTCUSSTATE_H__35CDEB52_A848_4BFE_B491_133932F26C39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssertCusState.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAssertCusState dialog

class CAssertCusState : public CDialog
{
// Construction
public:
	CAssertCusState(CWnd* pParent = NULL);   // standard constructor
//	char	strInfo[20];
// Dialog Data
	//{{AFX_DATA(CAssertCusState)
	enum { IDD = IDD_ASSERT_CUS_STATE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssertCusState)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAssertCusState)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSERTCUSSTATE_H__35CDEB52_A848_4BFE_B491_133932F26C39__INCLUDED_)
