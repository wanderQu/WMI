// ProcurIntell.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "ProcurIntell.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcurIntell dialog


CProcurIntell::CProcurIntell(CWnd* pParent /*=NULL*/)
	: CDialog(CProcurIntell::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcurIntell)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "ÖÇÄÜ²É¹º";
}


void CProcurIntell::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcurIntell)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProcurIntell, CDialog)
	//{{AFX_MSG_MAP(CProcurIntell)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcurIntell message handlers
