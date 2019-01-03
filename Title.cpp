// Title.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "Title.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTitle dialog


CTitle::CTitle(CWnd* pParent /*=NULL*/)
	: CDialog(CTitle::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTitle)
	//}}AFX_DATA_INIT
	brush.CreateSolidBrush(RGB(240,240,240));
	Parent = pParent;

}


void CTitle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTitle)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTitle, CDialog)
	//{{AFX_MSG_MAP(CTitle)
	ON_BN_CLICKED(IDC_PERSON_LOG, OnPersonLog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_LOGOUT, OnLogout)
	ON_BN_CLICKED(IDC_ChangePass, OnChangePass)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTitle message handlers

void CTitle::OnPersonLog() 
{
	// TODO: Add your control notification handler code here
	
}

HBRUSH CTitle::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	pDC->SetBkColor(RGB(240,240,240));
	pDC->SetBkMode(TRANSPARENT);
	// TODO: Return a different brush if the default is not desired
//	return (HBRUSH)GetStockObject(HOLLOW_BRUSH);	//	´°ÌåÍ¸Ã÷
	return brush;
}



void CTitle::OnLogout() 
{
	// TODO: Add your control notification handler code here
	exit(0);

}

void CTitle::OnChangePass() 
{
	// TODO: Add your control notification handler code here
	ChangePass dlg;
	this->ShowWindow(false);
	dlg.UserName = UserName;
	dlg.DoModal();
}
