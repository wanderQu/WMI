// AddDistri.cpp : implementation file
//

#include "stdafx.h"
#include "wmi.h"
#include "AddDistri.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddDistri dialog


CAddDistri::CAddDistri(CWnd* pParent /*=NULL*/)
	: CDialog(CAddDistri::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddDistri)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	DB_open(&db,".\\UserData\\Data.db");
}


void CAddDistri::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddDistri)
	DDX_Control(pDX, IDC_LIST2, m_Ls);
	DDX_Control(pDX, IDC_EDIT1, m_Num);
	DDX_Control(pDX, IDC_COMBO2, m_GoodID);
	DDX_Control(pDX, IDC_COMBO1, m_CusID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddDistri, CDialog)
	//{{AFX_MSG_MAP(CAddDistri)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	ON_CBN_EDITCHANGE(IDC_COMBO2, OnEditchangeCombo2)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddDistri message handlers
int GetDistri(void* data,int argc,char** argv,char** column)
{
	CAddDistri* m_Dis = (CAddDistri*)data;
	if(m_Dis->opt == GetCus)
	{
		argv[0] = U2G(argv[0]);
		m_Dis->m_CusID.InsertString(m_Dis->m_CusID.GetCount(),argv[0]);
		return false;
	}
	if(m_Dis->opt == GetGOOD)
	{
		argv[0] = U2G(argv[0]);
		m_Dis->m_GoodID.InsertString(m_Dis->m_GoodID.GetCount(),argv[0]);
		return false;
	}
	if(m_Dis->opt == GetNum)
	{
		argv[0] = U2G(argv[0]);
		m_Dis->result = argv[0];
		return false;
	}
	if(m_Dis->opt == InsertLs1)
	{
		int item = m_Dis->m_Ls.GetItemCount();
		m_Dis->m_Ls.InsertItem(item,"");
		for(int i = 0;i < argc;i++)
		{
			argv[i] = U2G(argv[i]);
			m_Dis->m_Ls.SetItemText(item,i,argv[i]);
		}
	}
	if(m_Dis->opt == InsertLs2)
	{
		int item = m_Dis->m_Ls.GetItemCount() - 1;
		for(int i = 0;i < argc;i++)
		{
			argv[i] = U2G(argv[i]);
			m_Dis->m_Ls.SetItemText(item,i + 2,argv[i]);
		}
	}
	if(m_Dis->opt == GetLsHead)
	{
		argv[1] = U2G(argv[1]);
	//	::MessageBox(0,U2G(argv[0]),0,0);
		int i = m_Dis->m_Ls.GetHeaderCtrl()->GetItemCount();
		if(strcmp(argv[1],"单据日期") && strcmp(argv[1],"配送状态"))
			m_Dis->m_Ls.InsertColumn(i,argv[1],LVCFMT_CENTER,130,0);
		return false;
	}
	return false;
}
//enum{GetCus,GetGood,GetNum,InsertLs1};
void CAddDistri::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString tmp,tmp2,tmp3,tmp4[2];
	m_CusID.GetWindowText(tmp);
	if(tmp.IsEmpty())
	{
		MessageBox("还没有选择配送对象呢~","提示");
		m_CusID.SetFocus();
		return;
	}
/*	else
	{
		opt = GetNum;
		sql.Format("select count(*) from manaCus where 客户编号 = '%s'",tmp);
		DB_excute(db,sql.GetBuffer(1),GetDistri,this);
		sql.ReleaseBuffer();
		if(result == "0")
		{
			if(MessageBox("数据库里面好像没有该客户\t\r是否去添加？","友情提示",MB_OKCANCEL) == IDOK)
			{
		/*		HWND hOtherWnd = ::FindWindow(NULL,"AddCharactor");
				if(hOtherWnd == NULL)
				{
					STARTUPINFO startInfo = {0};
					PROCESS_INFORMATION processInfo = {0};
					CreateProcess(".\\excute\\AddCharactor.exe",NULL,NULL,NULL,false,NULL,NULL,NULL,&startInfo,&processInfo);
				}
				
				CString t =  UserName + ",客户,0";
				CString *sendBuffer =new CString(t);
				COPYDATASTRUCT cds;
				cds.dwData = 0;
				cds.cbData = sendBuffer.GetLength() * sizeof(TCHAR);
				cds.lpData = (void*)sendBuffer.GetBuffer(0);
				sendBuffer.ReleaseBuffer();
				Sleep(100);
				hOtherWnd = ::FindWindow(NULL,"AddCharactor");
				if(hOtherWnd != NULL)
				{
					if(::SendMessage(hOtherWnd,WM_USER+1,0,LPARAM(sendBuffer)) == 0)
						delete sendBuffer;
//				};
			}
		}
		return;
	}*/
	m_GoodID.GetWindowText(tmp2);
	if(tmp2.IsEmpty())
	{
		MessageBox("要选择配送的商品哦~","提示");
		m_GoodID.SetFocus();
		return;
	}
/*-	else
	{
		opt = GetNum;
		sql.Format("select count(*) from inventory where 商品编号 = '%s'",tmp);
		DB_excute(db,sql.GetBuffer(1),GetDistri,this);
		sql.ReleaseBuffer();
		if(result == "0")
		{
			if(MessageBox("数据库里面好像没有这个商品\t\r是否去添加这个商品？","友情提示",MB_OKCANCEL) == IDOK)
			{
				;
			}
		}
	}*/
	m_Num.GetWindowText(tmp3);
	if(tmp3.IsEmpty())
	{
		MessageBox("商品数量不能为空的哈","提示");
		m_Num.SetFocus();
		return;
	}
	for(int i = 0;i < m_Ls.GetItemCount();i++)
	{
		tmp4[0] = m_Ls.GetItemText(i,0);
	
		if(tmp2 == tmp4[0])
		{
	/*		tmp3 = m_Ls.GetItemText(i,4);
			int iCount = atoi(tmp2.GetBuffer(0)) + atoi(tmp3.GetBuffer(0));
			tmp2.ReleaseBuffer();
			tmp3.ReleaseBuffer();
			tmp2.Format("%d",iCount);
			m_Ls.SetItemText(i,4,tmp2);*/
			tmp4[1] = m_Ls.GetItemText(i,2);
			if(tmp == tmp4[1])
			{
				CString tmp5 = m_Ls.GetItemText(i,4);
				int iCount = atoi(tmp5.GetBuffer(0)) + atoi(tmp3.GetBuffer(0));
				tmp3.Format("%d",iCount);
				m_Ls.SetItemText(i,4,tmp3);
				opt = GetNum;
				sql.Format("select %s * (select 商品单价 from inventory where 商品编号 = '%s')",tmp3,tmp2);
				DB_excute(db,sql.GetBuffer(0),GetDistri,this);
				sql.ReleaseBuffer();
				m_Ls.SetItemText(i,5,result);
				return;
			}	
		}
	}
	opt = InsertLs1;
	sql = "select 商品编号,商品名称 from inventory where 商品编号 = '" + tmp2 + "'";
	DB_excute(db,sql.GetBuffer(0),GetDistri,this);
	sql.ReleaseBuffer();
	opt = InsertLs2;
	sql = "select 客户编号,客户名称,地址 from manaCus where 客户编号 = '" + tmp + "'";
	DB_excute(db,sql.GetBuffer(0),GetDistri,this);
	sql.ReleaseBuffer();
	int item = m_Ls.GetItemCount() - 1;
	m_Ls.SetItemText(item,5,tmp3);
	
	opt = GetNum;
	sql.Format("select %s * (select 商品单价 from inventory where 商品编号 = '%s')",tmp3,tmp2);
	DB_excute(db,sql.GetBuffer(0),GetDistri,this);
	sql.ReleaseBuffer();
	m_Ls.SetItemText(item,6,result);
	return;

}

void CAddDistri::OnOk() 
{
	// TODO: Add your control notification handler code here
	CString str;
	CString sql;
	for(int i = 0;i < m_Ls.GetItemCount();i++)
	{
		str = m_Ls.GetItemText(i,0);
		int wNum = m_Ls.GetHeaderCtrl()->GetItemCount();
		for(int j = 1;j < wNum;j++)
		{
			str = str + "','" + m_Ls.GetItemText(i,j) ;
		}
		/*insert new data*/
		sql = "insert into distriTrack values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),'"+str+"')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
		/*update supply money*/
		sql.Format("update dataReceivable set 应收账款金额 = 应收账款金额 + %s where 客户编号 = '%s'",
			m_Ls.GetItemText(i,6),m_Ls.GetItemText(i,2));
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
		/*insert user log*/
		sql = "insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),\
			(select 员工编号 from Employees where 员工名称 = '"+UserName+"'),'"+UserName+"','新增','新增配送订单')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
	}
	while(m_Ls.DeleteItem(0));	
}

void CAddDistri::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Ls.GetSelectionMark();
	m_Ls.DeleteItem(pos);
}

BOOL CAddDistri::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_Ls.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	CImageList imagelist;
	imagelist.Create(1,24, ILC_COLOR, 1, 1); 
	m_Ls.SetImageList(&imagelist, LVSIL_SMALL);

	opt = GetLsHead;
	DB_selectTitle(db,GetDistri,this,"distriTrack");

	sql = "select 客户编号 from manaCus where 状态 != '不可用'";
	opt = GetCus;
	DB_excute(db,sql.GetBuffer(0),GetDistri,this);
	sql.ReleaseBuffer();

	sql = "select 商品编号 from inventory where 状态 != '不可用'";
	opt = GetGOOD;
	DB_excute(db,sql.GetBuffer(0),GetDistri,this);
	sql.ReleaseBuffer();

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddDistri::OnEditchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CString str;
	m_CusID.GetWindowText(str);
	if(str.IsEmpty())
	{
		m_CusID.ShowDropDown(false);
		return;
	}
	result = "0";
	sql= "select count(*) from manaCus where 客户编号 like '%"+str+"%'";
	opt = GetNum;
	DB_excute(db,sql.GetBuffer(1),GetDistri,this);
	sql.ReleaseBuffer();
	if(result != "0")
	{
		m_CusID.ResetContent();
		sql.Format("select 客户编号 from manaCus where 客户编号 like '%s%s%s'","%",str,"%");
		opt = GetCus;
		DB_excute(db,sql.GetBuffer(1),GetDistri,this);
		sql.ReleaseBuffer();
	}

//	int item = m_GoodId.FindStringExact(0,str);
	m_CusID.ShowDropDown(true);
	
}

void CAddDistri::OnEditchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	CString str;
	m_GoodID.GetWindowText(str);
	if(str.IsEmpty())
	{
		m_GoodID.ShowDropDown(false);
		return;
	}
	result = "0";
	sql= "select count(*) from inventory where 商品编号 like '%"+str+"%'";
	opt = GetNum;
	DB_excute(db,sql.GetBuffer(1),GetDistri,this);
	sql.ReleaseBuffer();
	if(result != "0")
	{
		m_GoodID.ResetContent();
		sql.Format("select 商品编号 from inventory where 商品编号 like '%s%s%s'","%",str,"%");
		opt = GetGOOD;
		DB_excute(db,sql.GetBuffer(1),GetDistri,this);
		sql.ReleaseBuffer();
	}

//	int item = m_GoodId.FindStringExact(0,str);
	m_GoodID.ShowDropDown(true);
}

void CAddDistri::OnChangeEdit1() 
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

void CAddDistri::OnClose() 
{
	// TODO: Add your message handler code here and/or call default	
	DB_close(db);
	while(m_Ls.DeleteItem(0));	
	CDialog::OnClose();
}
