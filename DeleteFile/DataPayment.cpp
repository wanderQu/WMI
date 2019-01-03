// DataPayment.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "DataPayment.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataPayment dialog


CDataPayment::CDataPayment(CWnd* pParent /*=NULL*/)
	: CDialog(CDataPayment::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataPayment)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "¸¶¿îµ¥";
}


void CDataPayment::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataPayment)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataPayment, CDialog)
	//{{AFX_MSG_MAP(CDataPayment)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataPayment message handlers
