// WMI.h : main header file for the WMI application
//

#if !defined(AFX_WMI_H__4B220075_659B_4B67_A7E8_AD2C03D8F270__INCLUDED_)
#define AFX_WMI_H__4B220075_659B_4B67_A7E8_AD2C03D8F270__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "Log.h"
/////////////////////////////////////////////////////////////////////////////
// CWMIApp:
// See WMI.cpp for the implementation of this class
//

class CWMIApp : public CWinApp
{
public:
	CWMIApp();
	CLog m_Log;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWMIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWMIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMI_H__4B220075_659B_4B67_A7E8_AD2C03D8F270__INCLUDED_)
