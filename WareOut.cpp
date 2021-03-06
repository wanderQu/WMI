// WareOut.cpp : implementation file
//

#include "stdafx.h"
#include "wmi.h"
#include "WareOut.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWareOut dialog

CWareOut::CWareOut(CWnd* pParent /*=NULL*/)
	: CDialog(CWareOut::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWareOut)
	//}}AFX_DATA_INIT
	DB_open(&db,".\\UserData\\Data.db");
}


void CWareOut::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWareOut)
	DDX_Control(pDX, IDC_COMBO1, m_GoodID);
	DDX_Control(pDX, IDC_LIST2, m_Ls);
	DDX_Control(pDX, IDC_EDIT1, m_Num);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWareOut, CDialog)
	//{{AFX_MSG_MAP(CWareOut)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWareOut message handlers
int GetWareOut(void*data,int argc,char**argv,char**column)
{	
	CWareOut* wareOut = (CWareOut*)data;

	if(wareOut->opt == GetGOOD)
	{
		argv[0] = U2G(argv[0]);
		wareOut->m_GoodID.InsertString(wareOut->m_GoodID.GetCount(),argv[0]);
		return false;
	}
	if(wareOut->opt == GetNum)
	{
		argv[0] = U2G(argv[0]);
		wareOut->result = argv[0];
		return false;
	}
	if(wareOut->opt == GetLsHead)
	{
		argv[1] = U2G(argv[1]);
	//	::MessageBox(0,U2G(argv[0]),0,0);
		int i = wareOut->m_Ls.GetHeaderCtrl()->GetItemCount();
		if(strcmp(argv[1],"单据日期"))
			wareOut->m_Ls.InsertColumn(i,argv[1],LVCFMT_CENTER,130,0);
		return false;
	}
	if(wareOut->opt == InsertLs)
	{
		int item = wareOut->m_Ls.GetItemCount();
		wareOut->m_Ls.InsertItem(item,"");
		for(int i = 0;i < argc;i++)
		{
			argv[i] = U2G(argv[i]);
			wareOut->m_Ls.SetItemText(item,i,argv[i]);
		}
		return false;
	}
	return false;
}
void CWareOut::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Ls.GetSelectionMark();
	m_Ls.DeleteItem(pos);			
}

void CWareOut::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString str[2];

	m_GoodID.GetWindowText(str[0]);
	if(str[0].IsEmpty())
	{
		MessageBox("还没有选择商品呢","提示");
		m_GoodID.SetFocus();
		return;
	}
	m_Num.GetWindowText(str[1]);
	if(str[1].IsEmpty())
	{
		MessageBox("要出多少呢？","提示");
		m_Num.SetFocus();
		return;
	}
	sql = "select 在库量 from inventory where 商品名称 = '" + str[0] + "'";
	opt = GetNum;
	DB_excute(db,sql.GetBuffer(0),GetWareOut,this);
	int total = atoi(result.GetBuffer(0));
	result.ReleaseBuffer();
	if(total <= atoi(str[1].GetBuffer(0)))
	{
		MessageBox("出库商品数量大于商品在库量，禁止继续操作!","Warnning",MB_OK);
		return;
	}
	/*cheack is it over added*/
	int item = m_Ls.GetItemCount();
	CString tmp;
	for(int i= 0;i < item;i++)
	{
		tmp = m_Ls.GetItemText(i,1);
		if(str[0] == tmp)
		{
			m_Ls.SetSelectionMark(i);
			tmp = m_Ls.GetItemText(i,3);
			int count = atoi(tmp.GetBuffer(0)) + atoi(str[1].GetBuffer(0));
			tmp.ReleaseBuffer();
			str[1].ReleaseBuffer();
			if(count > total)
			{
				MessageBox("检测到已知清单列表中\r\n该商品的总出库数量大于在库量\r\n禁止继续操作","Warnning",MB_OK);
				return;
			}
			else
				str[1].Format("%d",count);
			m_Ls.SetItemText(i,3,str[1]);
			return;
		}
	}
	sql = "select 仓库编号,商品编号,商品名称 from inventory where 商品名称 = '" + str[0] + "'";
	opt = InsertLs;
	DB_excute(db,sql.GetBuffer(0),GetWareOut,this);
	sql.ReleaseBuffer();

	m_Ls.SetItemText(item,3,str[1]);	

}

void CWareOut::OnOk() 
{
	// TODO: Add your control notification handler code here
	int item = m_Ls.GetItemCount();
	for(int i = 0;i < item;i++)
	{
			/*insert new data*/
		sql = "insert into wareOut values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),'"
			+ m_Ls.GetItemText(i,0) + "','" + m_Ls.GetItemText(i,1) + "','"
			+ m_Ls.GetItemText(i,2) + "','" + m_Ls.GetItemText(i,3) + "')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
		/*update supply money*/
		sql.Format("update inventory set 在库量 = 在库量 - %s where 商品编号 = '%s'",
			m_Ls.GetItemText(i,3),m_Ls.GetItemText(i,1));
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
		/*insert user log*/
		sql = "insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),\
			(select 员工编号 from Employees where 员工名称 = '"+UserName+"'),'"+UserName+"','新增','新增出库单')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
	}
	while(m_Ls.DeleteItem(0));
}

void CWareOut::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	DB_close(db);
	while(m_Ls.DeleteItem(0));
	CDialog::OnClose();
}

BOOL CWareOut::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_Ls.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	CImageList imagelist;
	imagelist.Create(1,24, ILC_COLOR, 1, 1); 
	m_Ls.SetImageList(&imagelist, LVSIL_SMALL);	

	opt = GetLsHead;
	DB_selectTitle(db,GetWareOut,this,"wareOut");

	sql = "select 商品名称 from inventory where 状态 != '不可用'";
	opt = GetGOOD;
	DB_excute(db,sql.GetBuffer(0),GetWareOut,this);
	sql.ReleaseBuffer();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWareOut::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString str;
	m_Num.GetWindowText(str);
	if(str == "0")
		m_Num.SetWindowText("");	
}
