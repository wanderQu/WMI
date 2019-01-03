// WareHouseOut.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "WareHouseOut.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWareHouseOut dialog


CWareHouseOut::CWareHouseOut(CWnd* pParent /*=NULL*/)
	: CDialog(CWareHouseOut::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWareHouseOut)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "³ö¿âµ¥";
}


void CWareHouseOut::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWareHouseOut)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWareHouseOut, CDialog)
	//{{AFX_MSG_MAP(CWareHouseOut)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWareHouseOut message handlers
