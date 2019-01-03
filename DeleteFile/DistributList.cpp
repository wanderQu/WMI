// DistributList.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "DistributList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDistributList dialog


CDistributList::CDistributList(CWnd* pParent /*=NULL*/)
	: CDialog(CDistributList::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDistributList)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "≈‰ÀÕªıµ•";
}


void CDistributList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDistributList)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDistributList, CDialog)
	//{{AFX_MSG_MAP(CDistributList)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDistributList message handlers
