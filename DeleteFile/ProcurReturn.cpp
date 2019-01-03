// ProcurReturn.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "ProcurReturn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcurReturn dialog


CProcurReturn::CProcurReturn(CWnd* pParent /*=NULL*/)
	: CDialog(CProcurReturn::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcurReturn)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "ÍË»õµ¥";
}


void CProcurReturn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcurReturn)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProcurReturn, CDialog)
	//{{AFX_MSG_MAP(CProcurReturn)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcurReturn message handlers
