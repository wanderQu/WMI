// AddOtherIn.cpp : implementation file
//

#include "stdafx.h"
#include "wmi.h"
#include "AddOtherIn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddOtherIn dialog


CAddOtherIn::CAddOtherIn(CWnd* pParent /*=NULL*/)
	: CDialog(CAddOtherIn::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddOtherIn)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	DB_open(&db,".\\UserData\\Data.db");
}


void CAddOtherIn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddOtherIn)
	DDX_Control(pDX, IDC_LIST2, m_Ls);
	DDX_Control(pDX, IDC_TEXT, m_Text);
	DDX_Control(pDX, IDC_EDIT1, m_Money);
	DDX_Control(pDX, IDC_COMBO1, m_MoneyType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddOtherIn, CDialog)
	//{{AFX_MSG_MAP(CAddOtherIn)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddOtherIn message handlers

void CAddOtherIn::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString str[3];
	m_MoneyType.GetWindowText(str[0]);
	m_Money.GetWindowText(str[1]);
	if(str[1].IsEmpty())
	{
		MessageBox("还没有输入其他收入金额","提示");
		return;
	}
	m_Text.GetWindowText(str[2]);
	if(str[2].IsEmpty())
	{
		str[2] = "无";
	}
	int item = m_Ls.GetItemCount();
	m_Ls.InsertItem(item,"");
	m_Ls.SetItemText(item,0,str[0]);
	m_Ls.SetItemText(item,1,str[1]);
	m_Ls.SetItemText(item,2,str[2]);
}

void CAddOtherIn::OnOk() 
{
	// TODO: Add your control notification handler code here
	int item  = m_Ls.GetItemCount();
	for(int i = 0;i < item; i++)
	{
		sql = "Insert into dataOtherIncome values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),'"+m_Ls.GetItemText(i,0)
			+"','"+m_Ls.GetItemText(i,1)+"','"+m_Ls.GetItemText(i,2)+"')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
		sql = "Insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),(select 员工编号 from Employees where 员工名称 = '"
			+UserName+"'),'"+UserName+"','新增','新增其他收入单')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
	}
	while(m_Ls.DeleteItem(0));	
}

void CAddOtherIn::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Ls.GetSelectionMark();
	m_Ls.DeleteItem(pos);		
}

void CAddOtherIn::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	DB_close(db);
	while(m_Ls.DeleteItem(0));
	CDialog::OnClose();
}

BOOL CAddOtherIn::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_Ls.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	CImageList imagelist;
	imagelist.Create(1,24, ILC_COLOR, 1, 1); 
	m_Ls.SetImageList(&imagelist, LVSIL_SMALL);	

	m_MoneyType.SetWindowText("现金");
	m_Ls.InsertColumn(0,"资金类别",LVCFMT_CENTER,130,0);
	m_Ls.InsertColumn(1,"金额",LVCFMT_CENTER,130,0);
	m_Ls.InsertColumn(2,"备注",LVCFMT_CENTER,130,0);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddOtherIn::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString str;
	m_Money.GetWindowText(str);
	if(str == "0")
		m_Money.SetWindowText("");
}
