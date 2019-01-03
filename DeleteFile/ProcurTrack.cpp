// ProcurTrack.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "ProcurTrack.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcurTrack dialog


CProcurTrack::CProcurTrack(CWnd* pParent /*=NULL*/)
	: CDialog(CProcurTrack::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcurTrack)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "²É¹º¸ú×Ù±í";
}


void CProcurTrack::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcurTrack)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProcurTrack, CDialog)
	//{{AFX_MSG_MAP(CProcurTrack)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcurTrack message handlers
