// DataVerification.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "DataVerification.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataVerification dialog


CDataVerification::CDataVerification(CWnd* pParent /*=NULL*/)
	: CDialog(CDataVerification::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataVerification)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "ºËÏúµ¥";
}


void CDataVerification::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataVerification)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataVerification, CDialog)
	//{{AFX_MSG_MAP(CDataVerification)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataVerification message handlers
