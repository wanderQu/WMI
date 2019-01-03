// AssertPayable.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "AssertPayable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssertPayable dialog


CAssertPayable::CAssertPayable(CWnd* pParent /*=NULL*/)
	: CDialog(CAssertPayable::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAssertPayable)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "应付账款明细表";
}


void CAssertPayable::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAssertPayable)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAssertPayable, CDialog)
	//{{AFX_MSG_MAP(CAssertPayable)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssertPayable message handlers
