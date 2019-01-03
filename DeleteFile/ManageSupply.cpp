// ManageSupply.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "ManageSupply.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManageSupply dialog


CManageSupply::CManageSupply(CWnd* pParent /*=NULL*/)
	: CDialog(CManageSupply::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManageSupply)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "供应商管理";
}


void CManageSupply::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManageSupply)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManageSupply, CDialog)
	//{{AFX_MSG_MAP(CManageSupply)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManageSupply message handlers
