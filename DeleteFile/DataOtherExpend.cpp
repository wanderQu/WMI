// DataOtherExpend.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "DataOtherExpend.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataOtherExpend dialog


CDataOtherExpend::CDataOtherExpend(CWnd* pParent /*=NULL*/)
	: CDialog(CDataOtherExpend::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataOtherExpend)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "其他支出单";
}


void CDataOtherExpend::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataOtherExpend)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataOtherExpend, CDialog)
	//{{AFX_MSG_MAP(CDataOtherExpend)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataOtherExpend message handlers
