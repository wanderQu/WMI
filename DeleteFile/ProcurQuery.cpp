// ProcurQuery.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "ProcurQuery.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcurQuery dialog


CProcurQuery::CProcurQuery(CWnd* pParent /*=NULL*/)
	: CDialog(CProcurQuery::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcurQuery)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "²É¹ºÃ÷Ï¸²éÑ¯";
}


void CProcurQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcurQuery)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProcurQuery, CDialog)
	//{{AFX_MSG_MAP(CProcurQuery)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcurQuery message handlers
