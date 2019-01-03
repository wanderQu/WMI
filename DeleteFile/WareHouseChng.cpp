// WareHouseChng.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "WareHouseChng.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWareHouseChng dialog


CWareHouseChng::CWareHouseChng(CWnd* pParent /*=NULL*/)
	: CDialog(CWareHouseChng::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWareHouseChng)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "¿â´æµ÷Õû";
}


void CWareHouseChng::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWareHouseChng)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWareHouseChng, CDialog)
	//{{AFX_MSG_MAP(CWareHouseChng)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWareHouseChng message handlers
