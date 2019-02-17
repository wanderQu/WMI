// harac.cpp : implementation file
//

#include "stdafx.h"
#include "wmi.h"
#include "harac.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Charac dialog


Charac::Charac(CWnd* pParent /*=NULL*/)
	: CDialog(Charac::IDD, pParent)
{
	//{{AFX_DATA_INIT(Charac)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	DB_open(&db,".\\UserData\\Data.db");

}


void Charac::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Charac)
	DDX_Control(pDX, IDC_STATIC_CONTAC, m_StaticContac);
	DDX_Control(pDX, IDC_STATIC_NAME, m_StaticName);
	DDX_Control(pDX, IDC_OPT, m_Opt);
	DDX_Control(pDX, IDC_NAME, m_Name);
	DDX_Control(pDX, IDC_LIST2, m_Ls);
	DDX_Control(pDX, IDC_Contacts, m_Contac);
	DDX_Control(pDX, IDC_PHONE, m_Phone);
	DDX_Control(pDX, IDC_COUNT, m_Account);
	DDX_Control(pDX, IDC_ADDRESS, m_Address);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Charac, CDialog)
	//{{AFX_MSG_MAP(Charac)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_CBN_SELCHANGE(IDC_OPT, OnSelchangeOpt)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_NAME, OnChangeName)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST2, OnColumnclickList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Charac message handlers
int GetCharac(void* data,int argc,char** argv,char** column)
{
	Charac* dlg = (Charac*)data;
	if(dlg->opt == InsertLsHead)
	{
		argv[1] = U2G(argv[1]);
		//	::MessageBox(0,U2G(argv[0]),0,0);
		int i = dlg->m_Ls.GetHeaderCtrl()->GetItemCount();
		if(strcmp(argv[0],"0") && strcmp(argv[1],"状态"))
			dlg->m_Ls.InsertColumn(i,argv[1],LVCFMT_CENTER,130,0);
		return false;
	}
	if(dlg->opt == GetNum)
	{
		dlg->result = U2G(argv[0]);
		return false;
	}
	return false;
}
void Charac::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString str[5],tmp;
	m_Opt.GetWindowText(tmp);
	if(tmp.IsEmpty())
	{
		MessageBox("还没有选择操作对象","提示");
		return;
	}
	m_Name.GetWindowText(str[0]);
	if(str[0].IsEmpty())
	{
		m_Opt.GetWindowText(str[0]);
		str[0] = str[0] + "总得有个名字吧";
		MessageBox(str[0],"提示");
		m_Name.SetFocus();
		return;
	}
	result = "0";
	if(tmp == "供应商")
		sql = "select count(*) from manaSup where 供应商名称 = '" + str[0] + "' and 状态 != '不可用'";
	else if(tmp == "客户")
		sql = "select count(*) from manaCus where 客户名称 = '" + str[0] + "' and 状态 != '不可用'";
	opt = GetNum;
	DB_excute(db,sql.GetBuffer(0),GetCharac,this);
	sql.ReleaseBuffer();
	if(result != "0")
	{
		MessageBox("数据库里面已经有该对象，不允许重复添加","error");
		return;
	}
	
	m_Phone.GetWindowText(str[1]);
	m_Account.GetWindowText(str[2]);
	m_Address.GetWindowText(str[3]);
	m_Phone.SetWindowText("");
	m_Account.SetWindowText("");
	m_Address.SetWindowText("");
	if(m_Contac.IsWindowVisible())
	{
		m_Contac.GetWindowText(str[4]);
		m_Contac.SetWindowText("");
	}
	for(int i = 0;i < m_Ls.GetItemCount();i++)
	{
		tmp = m_Ls.GetItemText(i,0);
		if(str[0] == tmp)
		{
			if(MessageBox("该名称对象以添加，是否修改对象属性？","提示",MB_OKCANCEL) == IDOK)
			{
				for(int index = 1;index < m_Ls.GetHeaderCtrl()->GetItemCount();index++)
				{
					if(!str[index].IsEmpty())
						m_Ls.SetItemText(i,index,str[index]);
				}			
			}
			return;
		}
	}
	int h = m_Ls.GetItemCount();
	m_Ls.InsertItem(h,"");
	for(int index2 = 0;index2 < m_Ls.GetHeaderCtrl()->GetItemCount();index2++)
	{
		if(!str[index2].IsEmpty())
			m_Ls.SetItemText(h,index2,str[index2]);
		else
			m_Ls.SetItemText(h,index2," ");
	}
	m_Name.SetWindowText("");

}

void Charac::OnOk() 
{
	// TODO: Add your control notification handler code here
	int item = m_Ls.GetItemCount();
	CString tmp,tb,Opt;
	if(item == 0)
		return;
	m_Opt.GetWindowText(Opt);

	if(Opt == "员工")
	{
		sql = "select count(*) from Employees";
		tmp = "E";
		tb = "Employees";
	}
	if(Opt == "供应商")
	{
		sql = "select count(*) from manaSup";
		tmp = "S";
		tb = "manaSup";
	}
	if(Opt == "客户")
	{
		sql = "select count(*) from manaCus";
		tmp = "C";
		tb = "manaCus";
	}
	opt = GetNum;
	DB_excute(db,sql.GetBuffer(0),GetCharac,this);
	sql.ReleaseBuffer();

	int num = atoi(result.GetBuffer(0)) + 1;
	result.ReleaseBuffer();
	

	int w = m_Ls.GetHeaderCtrl()->GetItemCount();
	CString str;
	for(int index = 0;index < item;index++)
	{
		str = "";
		for(int jndex = 0;jndex < w;jndex++)
		{
			str = str + "'" + m_Ls.GetItemText(index,jndex) + "',";
		}

/*		
		opt = GetNum;
		sql = "select count(*) from " + tb + "where " + Opt + "名称 = '"+ m_Ls.GetItemText(index,0) +"'";
		DB_excute(db,sql.GetBuffer(0),GetData,this);
		sql.ReleaseBuffer(0);

		if(result == "0")
		{*/
		result.Format("%d",num);
		for(int i = 0;i <= 5 - result.GetLength();i++)
			result = "0" + result;
		result = tmp + result;
		if(Opt == "员工")
		{
			sql = "insert into " + tb + " values('" + result + "','"+ result + "'," + str + "'任职中')";
			DB_excuteNoCall(db,sql.GetBuffer(0));
			sql.ReleaseBuffer();
		}
		else			
		{
			sql = "insert into " + tb + " values('" + result + "'," + str + "'合作中')";
			DB_excuteNoCall(db,sql.GetBuffer(0));
			sql.ReleaseBuffer();


			if(Opt == "供应商")	
				sql = "insert into dataPayable values('"+result +"','"+m_Ls.GetItemText(index,0)+"','0','0')";
			else if(Opt == "客户")
				sql = "insert into dataReceivable values('"+result +"','"+m_Ls.GetItemText(index,0)+"','0','0')";
			DB_excuteNoCall(db,sql.GetBuffer(0));
			sql.ReleaseBuffer(0);
		}

		sql = "insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),\
			(select 员工编号 from Employees where 员工名称 = '" + UserName +"'),'" + 
			UserName +"','添加','添加" + Opt + m_Ls.GetItemText(index,0) +"')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer(0);
		num++;	
	}
	while(m_Ls.DeleteItem(0));	
}

void Charac::OnDelete() 
{
	// TODO: Add your control notification handler code here

	int pos = m_Ls.GetSelectionMark();
	m_Ls.DeleteItem(pos);	
}

BOOL Charac::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_Ls.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	CImageList imagelist;
	imagelist.Create(1,24, ILC_COLOR, 1, 1); 
	m_Ls.SetImageList(&imagelist, LVSIL_SMALL);

	// TODO: Add extra initialization here
//	CString str;

//	m_Opt.GetWindowText(str);
	if(tbName == "Employees")
	{
		m_Opt.SelectString(0,"员工");
		m_StaticName.SetWindowText("员工姓名");
		m_StaticContac.ShowWindow(false);
		m_Contac.ShowWindow(false);
//		while(m_Ls.DeleteColumn(0));
		opt = InsertLsHead;
		DB_selectTitle(db,GetCharac,this,"manaEmployees");
	}
	else if(tbName == "manaSup")
	{
		m_Opt.SelectString(0,"供应商");
		m_StaticName.SetWindowText("供应商名称");
		m_StaticContac.ShowWindow(true);
		m_Contac.ShowWindow(true);
		opt = InsertLsHead;
		DB_selectTitle(db,GetCharac,this,"manaSup");
	}
	else if(tbName == "manaCus")
	{
		m_Opt.SelectString(0,"客户");
		m_StaticName.SetWindowText("客户名称");
		m_StaticContac.ShowWindow(true);
		m_Contac.ShowWindow(true);
		opt = InsertLsHead;
		DB_selectTitle(db,GetCharac,this,"manaCus");
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Charac::OnSelchangeOpt() 
{
	// TODO: Add your control notification handler code here
	CString str;
	//m_Opt.GetWindowText(str);
	m_Opt.GetLBText(m_Opt.GetCurSel(),str);
	while(m_Ls.DeleteColumn(0));
	if(str == "员工")
	{
		m_StaticName.SetWindowText("员工姓名");
		m_StaticContac.ShowWindow(false);
		m_Contac.ShowWindow(false);
		while(m_Ls.DeleteColumn(0));
		while(m_Ls.DeleteItem(0));
		opt = InsertLsHead;
		DB_selectTitle(db,GetCharac,this,"manaEmployees");
	}
	else if(str == "供应商")
	{
		m_StaticName.SetWindowText("供应商名称");
		m_StaticContac.ShowWindow(true);
		m_Contac.ShowWindow(true);
		while(m_Ls.DeleteColumn(0));
		while(m_Ls.DeleteItem(0));
		opt = InsertLsHead;
		DB_selectTitle(db,GetCharac,this,"manaSup");
	}
	else if(str == "客户")
	{
		m_StaticName.SetWindowText("客户名称");
		m_StaticContac.ShowWindow(true);
		m_Contac.ShowWindow(true);
		while(m_Ls.DeleteColumn(0));
		while(m_Ls.DeleteItem(0));
		opt = InsertLsHead;
		DB_selectTitle(db,GetCharac,this,"manaCus");
	}		
}

void Charac::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	DB_close(db);
	while(m_Ls.DeleteItem(0));
	CDialog::OnClose();
}

void Charac::OnChangeName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
		CString str;
	m_Name.GetWindowText(str);
	if(str == " ")
		m_Name.SetWindowText("");
}

void Charac::OnColumnclickList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}
