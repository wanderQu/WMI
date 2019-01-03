// WareHouseRequisiton.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "WareHouseRequisition.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWareHouseRequisiton dialog


CWareHouseRequisition::CWareHouseRequisition(CWnd* pParent /*=NULL*/)
	: CDialog(CWareHouseRequisition::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWareHouseRequisition)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "µ÷²¦µ¥";
}


void CWareHouseRequisition::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWareHouseRequisition)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWareHouseRequisition, CDialog)
	//{{AFX_MSG_MAP(CWareHouseRequisition)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWareHouseRequisiton message handlers
