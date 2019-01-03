// AssertVendorState.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "AssertVendorState.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssertVendorState dialog


CAssertVendorState::CAssertVendorState(CWnd* pParent /*=NULL*/)
	: CDialog(CAssertVendorState::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAssertVendorState)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "供应商对账单";
}


void CAssertVendorState::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAssertVendorState)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAssertVendorState, CDialog)
	//{{AFX_MSG_MAP(CAssertVendorState)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssertVendorState message handlers
