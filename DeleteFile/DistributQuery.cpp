// DistributQuery.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "DistributQuery.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDistributQuery dialog


CDistributQuery::CDistributQuery(CWnd* pParent /*=NULL*/)
	: CDialog(CDistributQuery::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDistributQuery)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "≈‰ÀÕ√˜œ∏≤È—Ø";
}


void CDistributQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDistributQuery)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDistributQuery, CDialog)
	//{{AFX_MSG_MAP(CDistributQuery)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDistributQuery message handlers
