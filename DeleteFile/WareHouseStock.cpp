// WareHouseStock.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "WareHouseStock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWareHouseStock dialog


CWareHouseStock::CWareHouseStock(CWnd* pParent /*=NULL*/)
	: CDialog(CWareHouseStock::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWareHouseStock)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "ø‚¥Ê≈Ãµ„";
}


void CWareHouseStock::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWareHouseStock)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWareHouseStock, CDialog)
	//{{AFX_MSG_MAP(CWareHouseStock)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWareHouseStock message handlers
