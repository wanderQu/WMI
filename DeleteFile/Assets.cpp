// Assets.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "Assets.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssets dialog


CAssets::CAssets(CWnd* pParent /*=NULL*/)
	: CDialog(CAssets::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAssets)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	brush.CreateSolidBrush(RGB(255,255,255));
}


void CAssets::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAssets)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAssets, CDialog)
	//{{AFX_MSG_MAP(CAssets)
	ON_BN_CLICKED(IDC_EXPENSE, OnExpense)
	ON_BN_CLICKED(IDC_SCHEDULEPAY, OnSchedulepay)
	ON_BN_CLICKED(IDC_SCHEDULERECEIVE, OnSchedulereceive)
	ON_BN_CLICKED(IDC_CUSSTATEMENT, OnCusstatement)
	ON_BN_CLICKED(IDC_VENDORSTATMENT, OnVendorstatment)
	ON_BN_CLICKED(IDC_OTHERINCOME, OnOtherincome)
	ON_BN_CLICKED(IDC_INCOMESTATEMENT, OnIncomestatement)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_INCOME, OnIncome)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssets message handlers

void CAssets::OnExpense() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("支出报表");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,26,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
//	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,25,LPARAM(str)) == 0)
//		delete str;

}

void CAssets::OnSchedulepay() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("应付账款明细表"); 
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,27,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

void CAssets::OnSchedulereceive() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("应收账款明细表");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,28,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

void CAssets::OnCusstatement() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("客户对账单");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,29,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}

}

void CAssets::OnVendorstatment() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("供应商对账单");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,30,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}

}

void CAssets::OnOtherincome() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("其他支出明细表");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,31,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}

}

void CAssets::OnIncomestatement() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("利润表");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,32,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}

}

HBRUSH CAssets::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
//	pDC->SetTextColor(RGB(255,255,255));
	pDC->SetBkColor(RGB(255,255,255));
	pDC->SetBkMode(TRANSPARENT);
	// TODO: Return a different brush if the default is not desired
	return brush;
}

void CAssets::OnIncome() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("收入报表");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,25,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}
