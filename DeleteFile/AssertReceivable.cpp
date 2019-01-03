// AssertReceivable.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "AssertReceivable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssertReceivable dialog


CAssertReceivable::CAssertReceivable(CWnd* pParent /*=NULL*/)
	: CDialog(CAssertReceivable::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAssertReceivable)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "应收账款明细表";
}


void CAssertReceivable::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAssertReceivable)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAssertReceivable, CDialog)
	//{{AFX_MSG_MAP(CAssertReceivable)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssertReceivable message handlers
