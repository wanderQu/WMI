// AddRecv.cpp : implementation file
//

#include "stdafx.h"
#include "wmi.h"
#include "AddRecv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddRecv dialog


CAddRecv::CAddRecv(CWnd* pParent /*=NULL*/)
	: CDialog(CAddRecv::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddRecv)
	//}}AFX_DATA_INIT
	DB_open(&db,".\\UserData\\Data.db");
}


void CAddRecv::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddRecv)
	DDX_Control(pDX, IDC_LIST2, m_Ls);
	DDX_Control(pDX, IDC_EDIT2, m_DelRecv);
	DDX_Control(pDX, IDC_EDIT1, m_Recv);
	DDX_Control(pDX, IDC_EDIT3, m_Text);
	DDX_Control(pDX, IDC_COMBO2, m_MoneyType);
	DDX_Control(pDX, IDC_COMBO1, m_CusID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddRecv, CDialog)
	//{{AFX_MSG_MAP(CAddRecv)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddRecv message handlers
int GetRecv(void*data,int argc,char**argv,char**column)
{
	CAddRecv* dlg = (CAddRecv*)data;
	if(dlg->opt == GetCus)
	{
		argv[0] = U2G(argv[0]);
		dlg->m_CusID.InsertString(dlg->m_CusID.GetCount(),argv[0]);
		return false;
	}
	if(dlg->opt == GetLsHead)
	{
		argv[1] = U2G(argv[1]);
	//	::MessageBox(0,U2G(argv[0]),0,0);
		int i = dlg->m_Ls.GetHeaderCtrl()->GetItemCount();
		if(strcmp(argv[1],"单据日期"))
			dlg->m_Ls.InsertColumn(i,argv[1],LVCFMT_CENTER,130,0);
		return false;
	}
	if(dlg->opt == InsertLs)
	{
		int item = dlg->m_Ls.GetItemCount() - 1;
		for(int i = 0;i < argc;i++)
		{
			argv[i] = U2G(argv[i]);
			dlg->m_Ls.SetItemText(item,i,argv[i]);
		}
		return false;
	}
	return false;
}
void CAddRecv::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString str[5];
	m_CusID.GetWindowText(str[0]);
	if(str[0].IsEmpty())
	{
		MessageBox("还没有选择客户呢","提示");
		m_CusID.SetFocus();
		return;
	}
	m_MoneyType.GetWindowText(str[1]);
	m_Recv.GetWindowText(str[2]);
	if(str[2].IsEmpty())
	{
		MessageBox("还没有输入收款金额啊~","提示");
		m_Recv.SetFocus();
		return;
	}
	m_DelRecv.GetWindowText(str[3]);
	if(str[3].IsEmpty())
	{
		str[3] = "0";
	}
	int item = m_Ls.GetItemCount();
	for(int i = 0;i < item;i++)
	{
		if(str[0] == m_Ls.GetItemText(i,0))
		{
			if(str[1] == m_Ls.GetItemText(i,2))
			{
				if(MessageBox("列表中有相同的数据，是否合并？","提示",MB_OKCANCEL) == IDOK)
				{
					CString tmp[2];
					tmp[0] = m_Ls.GetItemText(i,3);
					tmp[1] = m_Ls.GetItemText(i,4);
					int count[2];
					count[0] = atoi(tmp[0].GetBuffer(0)) + atoi(str[2].GetBuffer(0));
					count[1] = atoi(tmp[1].GetBuffer(0)) + atoi(str[3].GetBuffer(0));
					tmp[0].ReleaseBuffer();
					tmp[1].ReleaseBuffer();
					str[2].ReleaseBuffer();
					str[3].ReleaseBuffer();
					tmp[0].Format("%d",count[0]);
					m_Ls.SetItemText(i,3,tmp[0]);
					tmp[0].Format("%d",count[1]);
					m_Ls.SetItemText(i,4,tmp[0]);

					m_Recv.SetWindowText("0");
					m_DelRecv.SetWindowText("0");
					m_Text.SetWindowText("");
					return;
				}
			}
		}
	}
	m_Text.GetWindowText(str[4]);
	if(str[4].IsEmpty())
	{
		str[4] = "无";
	}
	m_Ls.InsertItem(item,"");
	sql = "select 客户编号,客户名称 from manaCus where 客户编号 = '"+ str[0] + "'";
	opt = InsertLs;
	DB_excute(db,sql.GetBuffer(0),GetRecv,this);
	sql.ReleaseBuffer();
	m_Ls.SetItemText(item,2,str[1]);
	m_Ls.SetItemText(item,3,str[2]);
	m_Ls.SetItemText(item,4,str[3]);
	m_Ls.SetItemText(item,5,str[4]);
	m_Recv.SetWindowText("0");
	m_DelRecv.SetWindowText("0");
	m_Text.SetWindowText("");
}

void CAddRecv::OnOk() 
{
	// TODO: Add your control notification handler code here
	int item = m_Ls.GetItemCount();
	for(int i =0; i < item;i++)
	{
		sql = "insert into dataVoucher values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),'"
			+ m_Ls.GetItemText(i,0) + "','" + m_Ls.GetItemText(i,1) + "','"
			+ m_Ls.GetItemText(i,2) + "','" + m_Ls.GetItemText(i,3) + "','"
			+ m_Ls.GetItemText(i,4) + "','" + m_Ls.GetItemText(i,5) + "')";
		DB_excute(db,sql.GetBuffer(0),GetRecv,this);
		sql.ReleaseBuffer();
		/*Insert SetLog*/

		sql = "insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),\
			(select 员工编号 from Employees where 员工名称 = '"
			+ UserName + "'),'" + UserName + "','新增','新增收款单')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();	

		sql = "update dataReceivable set 应收账款金额 = 应收账款金额 - "
			+ m_Ls.GetItemText(i,3) + " - " + m_Ls.GetItemText(i,4) 
			+ ",优惠金额累计 = 优惠金额累计 + " + m_Ls.GetItemText(i,4)
			+ " where 客户编号 = '" + m_Ls.GetItemText(i,0) + "'";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
	}
}

void CAddRecv::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Ls.GetSelectionMark();
	m_Ls.DeleteItem(pos);		
}

BOOL CAddRecv::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_Ls.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	CImageList imagelist;
	imagelist.Create(1,24, ILC_COLOR, 1, 1); 
	m_Ls.SetImageList(&imagelist, LVSIL_SMALL);	

	opt = GetCus;
	sql = "select 客户编号 from manaCus";
	DB_excute(db,sql.GetBuffer(0),GetRecv,this);
	sql.ReleaseBuffer();

	opt = GetLsHead;
	DB_selectTitle(db,GetRecv,this,"dataVoucher");
	m_MoneyType.SetWindowText("银行转账");	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddRecv::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	DB_close(db);
	while(m_Ls.DeleteItem(0));
	CDialog::OnClose();
}

void CAddRecv::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString str;
	m_Recv.GetWindowText(str);
	if(str == "0")
		m_Recv.SetWindowText("");	
}

void CAddRecv::OnChangeEdit2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString str;
	m_DelRecv.GetWindowText(str);
	if(str == "0")
		m_DelRecv.SetWindowText("");	
}
