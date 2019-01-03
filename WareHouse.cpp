// WareHouse.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "WareHouse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWareHouse dialog


CWareHouse::CWareHouse(CWnd* pParent /*=NULL*/)
	: CDialog(CWareHouse::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWareHouse)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	brush.CreateSolidBrush(RGB(255,255,255));
}


void CWareHouse::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWareHouse)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWareHouse, CDialog)
	//{{AFX_MSG_MAP(CWareHouse)
	ON_BN_CLICKED(IDC_GODOWNENTRY, OnGodownentry)
	ON_BN_CLICKED(IDC_EXITLS, OnExitls)
	ON_BN_CLICKED(IDC_STOCKING, OnStocking)
	ON_BN_CLICKED(IDC_ADJUSTMENT, OnAdjustment)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWareHouse message handlers

//void CWareHouse::OnRequisition() 
//{
//	// TODO: Add your control notification handler code here
//	pWnd = FindWindow("#32770","功能模块");
//	if(pWnd	== NULL)
//	{
//		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
//		m_Parent.ShowWindow(true);
//	}
//	CString *str = new CString("调拨单");
//	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,8,LPARAM(str)) == 0)
//	{
//		ShowWindow(false);
//		delete str;
//	}
//}

void CWareHouse::OnGodownentry() 
{
	// TODO: Add your control notification handler code here
//	WPARAM wParam = 1;
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("入库单");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,7,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
//	m_P = (CExternParent*)AfxGetApp()->GetMainWnd();
	
///	CRect rc;
//	m_P->m_Tab.GetClientRect(rc);
//	if(!m_P->IsWindowVisible())
//		m_P->ShowWindow(true);
//	if(m_In.m_hWnd == NULL)
//		m_In.Create(IDD_WAREHOUSE_IN,&m_P->m_Tab);

//	m_P->m_Tab.InsertItem(0,"入库单");
//	m_In.ShowWindow(true);
//	m_In.MoveWindow(&rc);
}

void CWareHouse::OnExitls() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("出库单");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,8,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

void CWareHouse::OnStocking() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("库存盘点");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,9,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

void CWareHouse::OnAdjustment() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("库存调整");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,10,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

//void CWareHouse::OnStatusquery() 
//{
//	// TODO: Add your control notification handler code here
//	pWnd = FindWindow("#32770","功能模块");
//	if(pWnd	== NULL)
//	{
//		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
//		m_Parent.ShowWindow(true);
//	}
//	CString *str = new CString("库存状态查询");
//	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,13,LPARAM(str)) == 0)
//	{
//		ShowWindow(false);
//		delete str;
//	}
//}

HBRUSH CWareHouse::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetBkColor(RGB(255,255,255));
	// TODO: Return a different brush if the default is not desired
	return brush;
}


