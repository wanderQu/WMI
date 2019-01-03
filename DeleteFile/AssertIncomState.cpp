// AssertIncomState.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "AssertIncomState.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssertIncomState dialog


CAssertIncomState::CAssertIncomState(CWnd* pParent /*=NULL*/)
	: CDialog(CAssertIncomState::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAssertIncomState)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "¿˚»Û±Ì";
}


void CAssertIncomState::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAssertIncomState)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAssertIncomState, CDialog)
	//{{AFX_MSG_MAP(CAssertIncomState)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssertIncomState message handlers
