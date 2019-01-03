// SetSysParam.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "SetSysParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetSysParam dialog


CSetSysParam::CSetSysParam(CWnd* pParent /*=NULL*/)
	: CDialog(CSetSysParam::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetSysParam)
	//}}AFX_DATA_INIT
//	strInfo = "系统参数设置";
//	rcPaint = CRect(0,0,0,0);
	DB_open(&db,".\\UserData\\info.db");
}


void CSetSysParam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetSysParam)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetSysParam, CDialog)
	//{{AFX_MSG_MAP(CSetSysParam)
	ON_EN_KILLFOCUS(IDC_EDIT1, OnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT2, OnKillfocusEdit2)
	ON_EN_KILLFOCUS(IDC_EDIT3, OnKillfocusEdit3)
	ON_EN_KILLFOCUS(IDC_EDIT4, OnKillfocusEdit4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetSysParam message handlers

//DEL HBRUSH CSetSysParam::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
//DEL {
//DEL 	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
//DEL 	
//DEL 	// TODO: Change any attributes of the DC here
//DEL 	pDC->SetBkColor(RGB(255,255,255));
//DEL 	// TODO: Return a different brush if the default is not desired
//DEL 	return (HBRUSH)GetStockObject(WHITE_BRUSH);
//DEL }

//DEL void CSetSysParam::OnPaint() 
//DEL {
//DEL 	CPaintDC dc(this); // device context for painting
//DEL //	CRect rc[2];
//DEL ///	GetDlgItem(IDC_PARAM)->GetClientRect(&rc[0]);
//DEL //	GetClientRect(&rc[1]);
//DEL //	dc.FillSolidRect(&rcPaint,RGB(255,255,255));
//DEL 	// TODO: Add your message handler code here
//DEL 	//dc.MoveTo()
//DEL 	// Do not call CDialog::OnPaint() for painting messages
//DEL }
int GetInfo(void*data,int argc,char**argv,char**column)
{
	CSetSysParam* dlg = (CSetSysParam*)data;
	for(int i = 0;i<argc;i++)
		dlg->info[i] = U2G(argv[i]);
	return false;
}
BOOL CSetSysParam::OnInitDialog() 
{
	CDialog::OnInitDialog();

	char sql[] = "select 公司名称,公司地址,电话,邮箱 from CoInfo limit 1";
	DB_excute(db,sql,GetInfo,this);
	GetDlgItem(IDC_EDIT1)->SetWindowText(info[0]);
	GetDlgItem(IDC_EDIT2)->SetWindowText(info[1]);
	GetDlgItem(IDC_EDIT3)->SetWindowText(info[2]);
	GetDlgItem(IDC_EDIT4)->SetWindowText(info[3]);
	
/*	CFile file;
	CString str;
	char path[MAX_PATH];
	::GetCurrentDirectory(MAX_PATH,path);

/*	str = path;
	str += ".\\UserData\\Config.ini";
	if(-1 == GetFileAttributes(str))
	{
		//request company infomation
		file.Open(str,CFile::modeCreate|CFile::modeWrite);
*/	
/*		strcpy(companyName,"国美电器（成都）");
		strcpy(companyAdd,"四川省成都市双流区九源路银桥幼儿园北100米");
		strcpy(companyPhone,"028-84342488 ");
		strcpy(companyMail,"282505738@qq.com");*/

/*		strcpy(front,"日期");
		strcpy(behind,"默认");
		strcpy(num,"7");
*/

/*		WritePrivateProfileString("基础属性","公司名称",companyName	,str);
		WritePrivateProfileString("基础属性","公司地址",companyAdd	,str);
		WritePrivateProfileString("基础属性","公司电话",companyPhone,str);
		WritePrivateProfileString("基础属性","公司邮箱",companyMail	,str);
		
/*		WritePrivateProfileString("系统参数","格式前缀",front	,str);
		WritePrivateProfileString("系统参数","格式后缀",behind	,str);	
		WritePrivateProfileString("系统参数","显示数量",num		,str);
*/

/*	}
	else
	{
		file.Open(str,CFile::modeRead);
	
		GetPrivateProfileString("基础属性","公司名称","",companyName ,20	,str);
		GetPrivateProfileString("基础属性","公司地址","",companyAdd  ,20	,str);
		GetPrivateProfileString("基础属性","公司电话","",companyPhone,20	,str);
		GetPrivateProfileString("基础属性","公司邮编","",companyMail ,20	,str);

/*		GetPrivateProfileString("系统参数","格式前缀","",front	,20	,str);
		GetPrivateProfileString("系统参数","格式后缀","",behind	,20	,str);	
		GetPrivateProfileString("系统参数","显示数量","",num	,20	,str);
*/

/*		companyName.ReleaseBuffer();
		companyAdd.ReleaseBuffer();
		companyPhone.ReleaseBuffer();
		companyMail.ReleaseBuffer();
		front.ReleaseBuffer();
		behind.ReleaseBuffer();
		num.ReleaseBuffer();
		
		MessageBox(companyName,"e");
		companyName		= companyName.Left(companyName.GetLength()-1);
		companyAdd		= companyAdd.Left(companyName.GetLength()-1);
		companyPhone	= companyPhone.Left(companyName.GetLength()-1);
		companyMail		= companyMail.Left(companyName.GetLength()-1);
		front			= front.Left(companyName.GetLength()-1);
		behind			= behind.Left(companyName.GetLength()-1);
		num				= num.Left(companyName.GetLength()-1);
*/		
//	}

//	GetDlgItem(IDC_EDIT1)->SetWindowText(companyName);
//	GetDlgItem(IDC_EDIT2)->SetWindowText(companyAdd);
//	GetDlgItem(IDC_EDIT3)->SetWindowText(companyPhone);
//	GetDlgItem(IDC_EDIT4)->SetWindowText(companyMail);
/*
	GetDlgItem(IDC_COMBO3)->SetWindowText(front);
	GetDlgItem(IDC_COMBO4)->SetWindowText(behind);
	GetDlgItem(IDC_COMBO6)->SetWindowText(num);
*/

//	file.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//DEL void CSetSysParam::OnChangeEdit1() 
//DEL {
//DEL 	// TODO: If this is a RICHEDIT control, the control will not
//DEL 	// send this notification unless you override the CDialog::OnInitDialog()
//DEL 	// function and call CRichEditCtrl().SetEventMask()
//DEL 	// with the ENM_CHANGE flag ORed into the mask.
//DEL 	
//DEL 	// TODO: Add your control notification handler code here
//DEL 	GetDlgItem(IDC_EDIT1)->GetWindowText(info[0]);
//DEL }

void CSetSysParam::OnKillfocusEdit1() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT1)->GetWindowText(info[0]);
	CString sql = "update CoInfo set 公司名称 = '" + info[0] + "'";
	DB_excuteNoCall(db,sql);
//	m_Info.ShowWindow(true);
}

void CSetSysParam::OnKillfocusEdit2() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT2)->GetWindowText(info[1]);	
	CString sql = "update CoInfo set 公司地址 = '" + info[1] + "'";
	DB_excuteNoCall(db,sql);
}

void CSetSysParam::OnKillfocusEdit3() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT3)->GetWindowText(info[2]);
	CString sql = "update CoInfo set 电话 = '" + info[2] + "'";
	DB_excuteNoCall(db,sql);
}

void CSetSysParam::OnKillfocusEdit4() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_EDIT4)->GetWindowText(info[3]);
	CString sql = "update CoInfo set 邮箱 = '" + info[3] + "'";
	DB_excuteNoCall(db,sql);
}
