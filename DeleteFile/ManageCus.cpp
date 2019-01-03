// ManageCus.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "ManageCus.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManageCus dialog


CManageCus::CManageCus(CWnd* pParent /*=NULL*/)
	: CDialog(CManageCus::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManageCus)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "客户管理";
}


void CManageCus::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManageCus)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManageCus, CDialog)
	//{{AFX_MSG_MAP(CManageCus)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManageCus message handlers
