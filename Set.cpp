// Set.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSet dialog


CSet::CSet(CWnd* pParent /*=NULL*/)
	: CDialog(CSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	brush.CreateSolidBrush(RGB(255,255,255));
}


void CSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSet)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSet, CDialog)
	//{{AFX_MSG_MAP(CSet)
	ON_BN_CLICKED(IDC_SYSSET, OnSysset)
	ON_BN_CLICKED(IDC_OPERATLOG, OnOperatlog)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSet message handlers

void CSet::OnSysset() 
{
	// TODO: Add your control notification handler code here
//	pWnd = FindWindow("#32770","功能模块");
//	if(pWnd	== NULL)
//	{
//		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
//		m_Parent.ShowWindow(true);
//	}
//	CString *str = new CString("系统参数设置");
//	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,34,LPARAM(str)) == 0)
//	{
//		ShowWindow(false);
//		delete str;
//	}
	pWnd = FindWindow("#32770","系统参数设置");
	if(pWnd == NULL)
	{
		pWnd = FindWindow("Afx:400000:b:10003:6:141001","小蘑菇库存管理系统");
		m_param.Create(IDD_SET_SYS_PARAM,pWnd);
		m_param.ShowWindow(true);
	}
	else
	{
		pWnd->ShowWindow(true);
	}
	ShowWindow(false);
	
}

//DEL void CSet::OnPerminsset() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	pWnd = FindWindow("#32770","功能模块");
//DEL 	if(pWnd	== NULL)
//DEL 	{
//DEL 		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
//DEL 		m_Parent.ShowWindow(true);
//DEL 	}
//DEL 	CString *str = new CString("权限设置");
//DEL 	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,22,LPARAM(str)) == 0)
//DEL 	{
//DEL 		ShowWindow(false);
//DEL 		delete str;
//DEL 	}
//DEL }

void CSet::OnOperatlog() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","功能模块");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("操作日志");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,22,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

HBRUSH CSet::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	pDC->SetBkColor(RGB(255,255,255));
	pDC->SetBkMode(TRANSPARENT);
	// TODO: Return a different brush if the default is not desired
	return brush;
}


