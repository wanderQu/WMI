// DataVoucher.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "DataVoucher.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataVoucher dialog


CDataVoucher::CDataVoucher(CWnd* pParent /*=NULL*/)
	: CDialog(CDataVoucher::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataVoucher)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "�տ";
}


void CDataVoucher::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataVoucher)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataVoucher, CDialog)
	//{{AFX_MSG_MAP(CDataVoucher)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataVoucher message handlers
