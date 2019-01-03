// ManageGoods.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "ManageGoods.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManageGoods dialog


CManageGoods::CManageGoods(CWnd* pParent /*=NULL*/)
	: CDialog(CManageGoods::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManageGoods)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "商品管理";
}


void CManageGoods::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManageGoods)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManageGoods, CDialog)
	//{{AFX_MSG_MAP(CManageGoods)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManageGoods message handlers
