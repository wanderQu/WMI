// AssertOtherInOut.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "AssertOtherInOut.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssertOtherInOut dialog


CAssertOtherInOut::CAssertOtherInOut(CWnd* pParent /*=NULL*/)
	: CDialog(CAssertOtherInOut::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAssertOtherInOut)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "其他支出明细表";
}


void CAssertOtherInOut::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAssertOtherInOut)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAssertOtherInOut, CDialog)
	//{{AFX_MSG_MAP(CAssertOtherInOut)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssertOtherInOut message handlers
