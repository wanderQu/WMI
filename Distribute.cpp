// Distribute.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "Distribute.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDistribute dialog


CDistribute::CDistribute(CWnd* pParent /*=NULL*/)
	: CDialog(CDistribute::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDistribute)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	brush.CreateSolidBrush(RGB(255,255,255));
}


void CDistribute::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDistribute)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDistribute, CDialog)
	//{{AFX_MSG_MAP(CDistribute)
	ON_BN_CLICKED(IDC_DISTRIBUT, OnDistribut)
	ON_BN_CLICKED(IDC_TACKING, OnTacking)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_RETURN, OnReturn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDistribute message handlers

void CDistribute::OnDistribut() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("配送货单");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,4,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

//DEL void CDistribute::OnDetailquery() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	pWnd = FindWindow("#32770","功能模块");
//DEL 	if(pWnd	== NULL)
//DEL 	{
//DEL 		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
//DEL 		m_Parent.ShowWindow(true);
//DEL 	}
//DEL 	CString *str = new CString("配送明细查询");
//DEL 	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,6,LPARAM(str)) == 0)
//DEL 	{
//DEL 		ShowWindow(false);
//DEL 		delete str;
//DEL 	}
//DEL }

void CDistribute::OnTacking() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("配送明细表");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,5,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

HBRUSH CDistribute::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	pDC->SetBkColor(RGB(255,255,255));
	pDC->SetBkMode(TRANSPARENT);
	// TODO: Return a different brush if the default is not desired
	return brush;
}

void CDistribute::OnReturn() 
{
	// TODO: Add your control notification handler code here
		pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("配送退货单");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,6,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}
