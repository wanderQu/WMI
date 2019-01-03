// DataTransfer.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "DataTransfer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataTransfer dialog


CDataTransfer::CDataTransfer(CWnd* pParent /*=NULL*/)
	: CDialog(CDataTransfer::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataTransfer)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "资金转账单";
}


void CDataTransfer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataTransfer)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataTransfer, CDialog)
	//{{AFX_MSG_MAP(CDataTransfer)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataTransfer message handlers
