// ProcurOrder.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "ProcurOrder.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcurOrder dialog


CProcurOrder::CProcurOrder(CWnd* pParent /*=NULL*/)
	: CDialog(CProcurOrder::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcurOrder)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

//	strInfo = "²É¹º¶©µ¥";
}


void CProcurOrder::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcurOrder)
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProcurOrder, CDialog)
	//{{AFX_MSG_MAP(CProcurOrder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcurOrder message handlers


