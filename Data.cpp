// Data.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "Data.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CData dialog


CData::CData(CWnd* pParent /*=NULL*/)
	: CDialog(CData::IDD, pParent)
{
	//{{AFX_DATA_INIT(CData)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	brush.CreateSolidBrush(RGB(255,255,255));
}


void CData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CData)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CData, CDialog)
	//{{AFX_MSG_MAP(CData)
	ON_BN_CLICKED(IDC_VOUCHER, OnVoucher)
	ON_BN_CLICKED(IDC_PAYMENT, OnPayment)
	ON_BN_CLICKED(IDC_OTHERINCOME, OnOtherincome)
	ON_BN_CLICKED(IDC_EXPENDITURE, OnExpenditure)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_Recvable, OnRecvable)
	ON_BN_CLICKED(IDC_Payable, OnPayable)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CData message handlers

void CData::OnVoucher() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("收款单");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,16,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}

}

void CData::OnPayment() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("付款单");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,17,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}
//
//void CData::OnVerification() 
//{
//	// TODO: Add your control notification handler code here
//	pWnd = FindWindow("#32770","功能模块");
//	if(pWnd	== NULL)
//	{
//		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
//		m_Parent.ShowWindow(true);
//	}
//	CString *str = new CString("核销单");
//	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,21,LPARAM(str)) == 0)
//	{
//		ShowWindow(false);
//		delete str;
//	}
//
//}

void CData::OnOtherincome() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("其他收入单");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,20,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

void CData::OnExpenditure() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("其他支出单");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,21,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}

}

//DEL void CData::OnTransfer() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	pWnd = FindWindow("#32770","功能模块");
//DEL 	if(pWnd	== NULL)
//DEL 	{
//DEL 		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
//DEL 		m_Parent.ShowWindow(true);
//DEL 	}
//DEL 	CString *str = new CString("资金转账单");
//DEL 	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,24,LPARAM(str)) == 0)
//DEL 	{
//DEL 		ShowWindow(false);
//DEL 		delete str;
//DEL 	}
//DEL 
//DEL }

HBRUSH CData::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	pDC->SetBkColor(RGB(255,255,255));
	pDC->SetBkMode(TRANSPARENT);
	// TODO: Return a different brush if the default is not desired
	return brush;
}

void CData::OnRecvable() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("应收账款");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,18,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}	
}

void CData::OnPayable() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("应付账款");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,19,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}	
}
