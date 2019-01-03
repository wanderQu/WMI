// Manage.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "Manage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManage dialog


CManage::CManage(CWnd* pParent /*=NULL*/)
	: CDialog(CManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	brush.CreateSolidBrush(RGB(255,255,255));
}


void CManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManage, CDialog)
	//{{AFX_MSG_MAP(CManage)
	ON_BN_CLICKED(IDC_CUSMANAGE, OnCusmanage)
	ON_BN_CLICKED(IDC_SUPPLYMANAGE, OnSupplymanage)
	ON_BN_CLICKED(IDC_GODSMANAGE, OnGodsmanage)
	ON_BN_CLICKED(IDC_WAREHOUSEMANAGE, OnWarehousemanage)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_Employ, OnEmploy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManage message handlers

void CManage::OnCusmanage() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","����ģ��");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("�ͻ�����");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,11,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

void CManage::OnSupplymanage() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","����ģ��");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("��Ӧ�̹���");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,12,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

void CManage::OnGodsmanage() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","����ģ��");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("��Ʒ����");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,14,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

void CManage::OnWarehousemanage() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","����ģ��");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("�ֿ����");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,15,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

//DEL void CManage::OnAddressmanage() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	pWnd = FindWindow("#32770","����ģ��");
//DEL 	if(pWnd	== NULL)
//DEL 	{
//DEL 		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
//DEL 		m_Parent.ShowWindow(true);
//DEL 	}
//DEL 	CString *str = new CString("���͵�ַ����");
//DEL 	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,18,LPARAM(str)) == 0)
//DEL 	{
//DEL 		ShowWindow(false);
//DEL 		delete str;
//DEL 	}
//DEL }

HBRUSH CManage::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetBkColor(RGB(255,255,255));
	// TODO: Return a different brush if the default is not desired
	return brush;
}

void CManage::OnEmploy() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","����ģ��");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("Ա������");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,13,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}
