// WareHouseQuery.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "WareHouseQuery.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWareHouseQuery dialog


CWareHouseQuery::CWareHouseQuery(CWnd* pParent /*=NULL*/)
	: CDialog(CWareHouseQuery::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWareHouseQuery)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "¿â´æ×´Ì¬²éÑ¯";
}


void CWareHouseQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWareHouseQuery)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWareHouseQuery, CDialog)
	//{{AFX_MSG_MAP(CWareHouseQuery)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWareHouseQuery message handlers
