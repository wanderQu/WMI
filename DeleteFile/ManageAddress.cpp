// ManageAddress.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "ManageAddress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManageAddress dialog


CManageAddress::CManageAddress(CWnd* pParent /*=NULL*/)
	: CDialog(CManageAddress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManageAddress)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "≈‰ÀÕµÿ÷∑π‹¿Ì";
}


void CManageAddress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManageAddress)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManageAddress, CDialog)
	//{{AFX_MSG_MAP(CManageAddress)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManageAddress message handlers
