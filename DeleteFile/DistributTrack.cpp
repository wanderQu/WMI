// DistributTrack.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "DistributTrack.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDistributTrack dialog


CDistributTrack::CDistributTrack(CWnd* pParent /*=NULL*/)
	: CDialog(CDistributTrack::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDistributTrack)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "ÅäËÍ¸ú×Ù±í";
}


void CDistributTrack::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDistributTrack)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDistributTrack, CDialog)
	//{{AFX_MSG_MAP(CDistributTrack)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDistributTrack message handlers
