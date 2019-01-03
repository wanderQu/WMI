// ManageWareHouse.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "ManageWareHouse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManageWareHouse dialog


CManageWareHouse::CManageWareHouse(CWnd* pParent /*=NULL*/)
	: CDialog(CManageWareHouse::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManageWareHouse)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "≤÷ø‚π‹¿Ì";
}


void CManageWareHouse::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManageWareHouse)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManageWareHouse, CDialog)
	//{{AFX_MSG_MAP(CManageWareHouse)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManageWareHouse message handlers
