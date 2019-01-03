// WareHouseIn.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "WareHouseIn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWareHouseIn dialog


CWareHouseIn::CWareHouseIn(CWnd* pParent /*=NULL*/)
	: CDialog(CWareHouseIn::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWareHouseIn)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "Èë¿âµ¥";
}


void CWareHouseIn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWareHouseIn)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWareHouseIn, CDialog)
	//{{AFX_MSG_MAP(CWareHouseIn)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWareHouseIn message handlers
