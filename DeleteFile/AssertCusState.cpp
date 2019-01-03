// AssertCusState.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "AssertCusState.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssertCusState dialog


CAssertCusState::CAssertCusState(CWnd* pParent /*=NULL*/)
	: CDialog(CAssertCusState::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAssertCusState)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "客户对账单";
}


void CAssertCusState::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAssertCusState)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAssertCusState, CDialog)
	//{{AFX_MSG_MAP(CAssertCusState)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssertCusState message handlers
