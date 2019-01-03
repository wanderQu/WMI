// SetLog.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "SetLog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetLog dialog


CSetLog::CSetLog(CWnd* pParent /*=NULL*/)
	: CDialog(CSetLog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetLog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
//	strInfo = "系统日志";
}


void CSetLog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetLog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetLog, CDialog)
	//{{AFX_MSG_MAP(CSetLog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetLog message handlers
