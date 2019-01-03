// Procurment.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "Procurment.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcurment dialog


CProcurment::CProcurment(CWnd* pParent /*=NULL*/)
	: CDialog(CProcurment::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcurment)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	brush.CreateSolidBrush(RGB(255,255,255));
}


void CProcurment::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcurment)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProcurment, CDialog)
	//{{AFX_MSG_MAP(CProcurment)
	ON_BN_CLICKED(IDC_ODER, OnOder)
	ON_BN_CLICKED(IDC_TRACKING, OnTracking)
	ON_BN_CLICKED(IDC_RETURN, OnReturn)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcurment message handlers

void CProcurment::OnOder() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","����ģ��");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}

	//pWnd(1),Dialog(2),this(3)

	//postMessage: ����Ϣ�ŵ���Ϣ����Ȼ�󷵻أ��ɹ���1����ʧ�ܣ�0��-����Ϣ��������1w

	CString *str = new CString("�ɹ�����");
//	if(::PostMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,0,LPARAM(str)) == 1)
//	{
//		ShowWindow(false);
//	str->Empty();
//	}
	//SendMessage:����Ϣ�ŵ����У�Ȼ��ȴ���Ϣ��������ٷ���
	//result:	 1-2-3
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,0,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
	
}

//DEL void CProcurment::OnQuery() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	pWnd = FindWindow("#32770","����ģ��");
//DEL 	if(pWnd	== NULL)
//DEL 	{
//DEL 		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
//DEL 		m_Parent.ShowWindow(true);
//DEL 	}
//DEL 	CString *str = new CString("�ɹ���ϸ��ѯ");
//DEL 	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,1,LPARAM(str)) == 0)
//DEL 	{
//DEL 		ShowWindow(false);
//DEL 		delete str;
//DEL 	}
//DEL }

void CProcurment::OnTracking() 
{
	// TODO: Add your control notification handler code here
	
	pWnd = FindWindow("#32770","����ģ��");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("�ɹ���ϸ��");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,1,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}

void CProcurment::OnReturn() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","����ģ��");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("�ɹ��˻���");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,2,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}
/*
void CProcurment::OnIntelpurchas() 
{
	// TODO: Add your control notification handler code here
	pWnd = FindWindow("#32770","����ģ��");
	if(pWnd	== NULL)
	{
		m_Parent.Create(IDD_EXTERN_PARENT,NULL);			//Tab_Controll
		m_Parent.UserName = UserName;
		m_Parent.ShowWindow(true);
	}
	CString *str = new CString("���ܲɹ�");
	if(::SendMessage(pWnd->GetSafeHwnd(),WM_CREATE_WND,3,LPARAM(str)) == 0)
	{
		ShowWindow(false);
		delete str;
	}
}
*/
HBRUSH CProcurment::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	pDC->SetBkColor(RGB(255,255,255));
	pDC->SetBkMode(TRANSPARENT);
	// TODO: Return a different brush if the default is not desired
	return brush;
}
