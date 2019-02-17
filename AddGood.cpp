// AddGood.cpp : implementation file
//

#include "stdafx.h"
#include "wmi.h"
#include "AddGood.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AddGood dialog


AddGood::AddGood(CWnd* pParent /*=NULL*/)
	: CDialog(AddGood::IDD, pParent)
{
	//{{AFX_DATA_INIT(AddGood)
	//}}AFX_DATA_INIT
	DB_open(&db,".\\UserData\\Data.db");
}


void AddGood::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AddGood)
	DDX_Control(pDX, IDC_ID, m_GoodID);
	DDX_Control(pDX, IDC_PRICE, m_Price);
	DDX_Control(pDX, IDC_LIST2, m_Ls);
	DDX_Control(pDX, IDC_MIN, m_Min);
	DDX_Control(pDX, IDC_GOODNAME, m_Name);
	DDX_Control(pDX, IDC_COMBO2, m_SupID);
	DDX_Control(pDX, IDC_COMBO1, m_WareID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AddGood, CDialog)
	//{{AFX_MSG_MAP(AddGood)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_EN_CHANGE(IDC_PRICE, OnChangePrice)
	ON_EN_CHANGE(IDC_MIN, OnChangeMin)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	ON_CBN_EDITCHANGE(IDC_COMBO2, OnEditchangeCombo2)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AddGood message handlers
int GetGood(void*data,int argc,char**argv,char**column)
{
	AddGood* m_Good = (AddGood*)data;
	if(m_Good->opt == GetWare)
	{
		argv[0] = U2G(argv[0]);
		m_Good->m_WareID.InsertString(m_Good->m_WareID.GetCount(),argv[0]);
		return false;
	}
	if(m_Good->opt == GetSup)
	{
		argv[0] = U2G(argv[0]);
		m_Good->m_SupID.InsertString(m_Good->m_SupID.GetCount(),argv[0]);
		return false;
	}
	if(m_Good->opt == GetNum)
	{
		argv[0] = U2G(argv[0]);
		m_Good->result = argv[0];
		return false;
	}
	if(m_Good->opt == InsertLs)
	{
		int item = m_Good->m_Ls.GetItemCount() - 1;
		for(int i = 0;i < argc;i++)
		{
			argv[i] = U2G(argv[i]);
			m_Good->m_Ls.SetItemText(item,i + 6,argv[i]);
		}
		return false;
	}
	if(m_Good->opt == GetLsHead)
	{
		argv[1] = U2G(argv[1]);
	//	::MessageBox(0,U2G(argv[0]),0,0);
		int i = m_Good->m_Ls.GetHeaderCtrl()->GetItemCount();
		if(strcmp(argv[1],"状态"))
			m_Good->m_Ls.InsertColumn(i,argv[1],LVCFMT_CENTER,130,0);
		return false;
	}
	return false;
}
void AddGood::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Ls.GetSelectionMark();
	m_Ls.DeleteItem(pos);	
	
}

void AddGood::OnOk() 
{
	// TODO: Add your control notification handler code here
	int item = m_Ls.GetItemCount();
//	sql = "select count(*) from inventory";
//	opt = GetNum;
//	DB_excute(db,sql.GetBuffer(0),GetGood,this);
//	sql.ReleaseBuffer();
//	int num = atoi(result.GetBuffer(0));
//	result.ReleaseBuffer();

	for(int j = 0;j < item;j++)
	{
//		result.Format("%d",num + 1);
//		for(int i = 0;i <= 5 - result.GetLength();i++)
//			result = "0" + result;
//		result = "G" + result;
//		num++;
		sql = "insert into inventory values('"+ m_Ls.GetItemText(j,0) +"','"
			+ m_Ls.GetItemText(j,1) +"','"+ m_Ls.GetItemText(j,2) 
			+ "','" + m_Ls.GetItemText(j,5) + "','0','0','" + m_Ls.GetItemText(j,3) 
			+ "','" + m_Ls.GetItemText(j,6) + "','" + m_Ls.GetItemText(j,7) +"','可用')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();

		sql = "insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),(select 员工编号 from Employees where 员工名称 = '"
			+ UserName + "'),'" + UserName + "','添加','添加商品" + m_Ls.GetItemText(j,0) +"')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
	}
	while(m_Ls.DeleteItem(0));
}

void AddGood::OnChangePrice() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString str;
	m_Price.GetWindowText(str);
	if(str.GetLength() >0)
	{
		if(str == "0")
			str="";
		else 
		{
			while(str.Right(1).GetAt(0) < '0' || str.Right(1).GetAt(0) > '9')
			{
				if(str.Right(1).GetAt(0) == '.')
				{
					if(str.Find(".") != str.GetLength() - 1 || str.GetAt(0) == '.')
					{
						str.Delete(str.GetLength() - 1);
						m_Price.SetWindowText(str);
						m_Price.SetSel(-1);
					}
					else
						break;
				}
				else
				{
					
					str.Delete(str.GetLength() - 1);
					m_Price.SetWindowText(str);
					m_Price.SetSel(-1);
					if(str.GetLength()==0)
						break;
				}
			
			}
		}
		
	}

}

void AddGood::OnChangeMin() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString str;
	m_Min.GetWindowText(str);
	if(str == "0")
		m_Min.SetWindowText("");
}

BOOL AddGood::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_Ls.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	CImageList imagelist;
	imagelist.Create(1,24, ILC_COLOR, 1, 1); 
	m_Ls.SetImageList(&imagelist, LVSIL_SMALL);	

	// TODO: Add extra initialization here
	sql = "select 供应商名称 from manaSup where 状态 != '不可用'";
	opt = GetSup;
	DB_excute(db,sql.GetBuffer(0),GetGood,this);
	sql.ReleaseBuffer();
	
	sql = "select 仓库编号 from manaWare where 状态 != '不可用'";
	opt = GetWare;
	DB_excute(db,sql.GetBuffer(0),GetGood,this);
	sql.ReleaseBuffer();

	opt = GetLsHead;
	DB_selectTitle(db,GetGood,this,"manaGoods");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void AddGood::OnEditchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	
}

void AddGood::OnEditchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	
}

void AddGood::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString str[5],ID;
	m_GoodID.GetWindowText(ID);
	if(ID.IsEmpty())
	{
		MessageBox("商品编号不能为空","error");
		m_GoodID.SetFocus();
		return;
	}
	m_Name.GetWindowText(str[0]);
	if(str[0].IsEmpty())
	{
		MessageBox("商品名称不能为空","error");
		m_Name.SetFocus();
		return;
	}
	opt=GetNum;
	sql = "select count(*) from Inventory where 商品名称 = '" + str[0] + "' or 商品编号 = '"+ID+"' and 状态 != '不可用'";
	DB_excute(db,sql.GetBuffer(0),GetGood,this);
	sql.ReleaseBuffer();

	if(result != "0")
	{
		MessageBox("该商品已经添加进数据库","error");
		return;
	}
	m_Price.GetWindowText(str[1]);
	if(str[1].IsEmpty())
	{
		MessageBox("商品单价不能为空","error");
		m_Price.SetFocus();
		return;
	}
	m_Min.GetWindowText(str[2]);
	if(str[2].IsEmpty())
	{
		MessageBox("最低库存不能为0，默认值为1","error");
	}
	m_WareID.GetWindowText(str[3]);
	if(str[3].IsEmpty())
	{
		MessageBox("还没有选择仓库","error");
		m_WareID.SetFocus();
		return;
	}
	m_SupID.GetWindowText(str[4]);
	if(str[4].IsEmpty())
	{
		MessageBox("还没有选择供应商","error");
		m_SupID.SetFocus();
		return;
	}

	int item = m_Ls.GetItemCount();

	for(int i = 0;i < item;i++)
	{
		result = m_Ls.GetItemText(i,0);
		if(result == ID)
		{
			if(MessageBox("添加编号，列表已经存在，是否覆盖？","提示",MB_OKCANCEL) == IDOK)
			{
//				for(int j = 1;j < 5;j++)
//				{
//					m_Ls.SetItemText(i,j,str[i]);
//				}
//				sql = "select 供应商编号,供应商名称 from manaSup where 供应商名称 = '" + str[4] +"'";
//				opt = InsertLs;
//				DB_excute(db,sql.GetBuffer(0),GetGood,this);
//				return;
				m_Ls.DeleteItem(i);
				item = item - 1;
				break;
			}
			else
			{
				m_Name.SetWindowText("");
				m_Price.SetWindowText("");
				m_Min.SetWindowText("1");
				return;
			}
			
		}
	}
	m_Ls.InsertItem(item,"");
	m_Ls.SetItemText(item,0,ID);
	m_Ls.SetItemText(item,1,str[0]);
	m_Ls.SetItemText(item,2,str[1]);
	m_Ls.SetItemText(item,3,str[2]);
	m_Ls.SetItemText(item,4,"0");
	m_Ls.SetItemText(item,5,str[3]);
	sql = "select 供应商编号,供应商名称 from manaSup where 供应商名称 = '" + str[4] +"'";
	opt = InsertLs;
	DB_excute(db,sql.GetBuffer(0),GetGood,this);
	sql.ReleaseBuffer();
	m_Name.SetWindowText("");
	m_Price.SetWindowText("");
	m_Min.SetWindowText("1");
}

void AddGood::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	DB_close(db);
	while(m_Ls.DeleteItem(0));
	CDialog::OnClose();
}
