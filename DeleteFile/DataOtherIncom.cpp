// DataOtherIncom.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "DataOtherIncom.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataOtherIncom dialog


CDataOtherIncom::CDataOtherIncom(CWnd* pParent /*=NULL*/)
	: CDialog(CDataOtherIncom::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataOtherIncom)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "其他收入单";
}


void CDataOtherIncom::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataOtherIncom)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataOtherIncom, CDialog)
	//{{AFX_MSG_MAP(CDataOtherIncom)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataOtherIncom message handlers
