// SetPermis.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "SetPermis.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetPermis dialog


CSetPermis::CSetPermis(CWnd* pParent /*=NULL*/)
	: CDialog(CSetPermis::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetPermis)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "»®œﬁ…Ë÷√";
}


void CSetPermis::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetPermis)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetPermis, CDialog)
	//{{AFX_MSG_MAP(CSetPermis)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetPermis message handlers
