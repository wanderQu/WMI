// AddWareAdj.cpp : implementation file
//

#include "stdafx.h"
#include "wmi.h"
#include "AddWareAdj.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddWareAdj dialog


CAddWareAdj::CAddWareAdj(CWnd* pParent /*=NULL*/)
	: CDialog(CAddWareAdj::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddWareAdj)
	//}}AFX_DATA_INIT
	DB_open(&db,".\\UserData\\Data.db");
}


void CAddWareAdj::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddWareAdj)
	DDX_Control(pDX, IDC_COMBO2, m_GoodID);
	DDX_Control(pDX, IDC_EDIT3, m_Text);
	DDX_Control(pDX, IDC_EDIT2, m_RePrice);
	DDX_Control(pDX, IDC_EDIT1, m_ReNum);
	DDX_Control(pDX, IDC_LIST2, m_Ls);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddWareAdj, CDialog)
	//{{AFX_MSG_MAP(CAddWareAdj)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddWareAdj message handlers
int GetWareAdj(void*data,int argc,char**argv,char**column)
{
	CAddWareAdj* wareAdj = (CAddWareAdj*)data;
	if(wareAdj->opt == InsertLs)
	{
		int item = wareAdj->m_Ls.GetItemCount() - 1;
        wareAdj->m_Ls.SetItemText(item,0,U2G(argv[0]));
		wareAdj->m_Ls.SetItemText(item,1,U2G(argv[1]));
		wareAdj->m_Ls.SetItemText(item,2,U2G(argv[2]));
		wareAdj->m_Ls.SetItemText(item,4,U2G(argv[3]));
	/*	for(int i = 0;i< argc;i++)
		{
			argv[i] = U2G(argv[i]); 
			if(i == 3)
				wareAdj->m_Ls.SetItemText(item,i + 1,argv[i]);
			else
				wareAdj->m_Ls.SetItemText(item,i,argv[i]);
			return false;
		}*/
	}
	if(wareAdj->opt == GetLsHead)
	{
		argv[1] = U2G(argv[1]);
		int i = wareAdj->m_Ls.GetHeaderCtrl()->GetItemCount();
		if(strcmp(argv[1],"日期"))
			wareAdj->m_Ls.InsertColumn(i,argv[1],LVCFMT_CENTER,130,0);
		return false;
	}
	if(wareAdj->opt == GetNum)
	{
		wareAdj->result = U2G(argv[0]);
		return false;
	}
	if(wareAdj->opt == GetGOOD)
	{
		argv[0] = U2G(argv[0]);
		wareAdj->m_GoodID.InsertString(wareAdj->m_GoodID.GetCount(),argv[0]);
		return false;
	}
	return false;
}
void CAddWareAdj::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString str[4];
	bool	isChanged = false;
	m_GoodID.GetWindowText(str[0]);
	if(str[0].IsEmpty())
	{
		MessageBox("还没有选择商品哦~","提示");
		m_GoodID.SetFocus();
		return;
	}
	m_ReNum.GetWindowText(str[1]);
	if(!str[1].IsEmpty())
	{
		isChanged = true;
	}
	m_RePrice.GetWindowText(str[2]);
	if(!str[2].IsEmpty())
	{
		isChanged = true;
	}
	m_Text.GetWindowText(str[3]);
	if(str[3].IsEmpty())
	{
		str[3] = "无";
	}
	if(isChanged)
	{
		int item = m_Ls.GetItemCount();
		for(int i = 0;i< item;i++)
		{
			if(m_Ls.GetItemText(i,0) == str[0])
			{
				MessageBox("检测到相同对象，以自动替换","提示");
				if(!str[1].IsEmpty())
					m_Ls.SetItemText(i,5,str[1]);
				if(!str[2].IsEmpty())
					m_Ls.SetItemText(i,3,str[2]);
				if(!str[3].IsEmpty())
					m_Ls.SetItemText(i,6,str[3]);
				m_Ls.SetSelectionMark(i);
				m_ReNum.SetWindowText("");
				m_RePrice.SetWindowText("");
				m_Text.SetWindowText("");
				return;
			}
		}
		sql = "select 商品编号,商品名称,商品单价,在库量 from inventory where 商品编号 = '"+str[0]+"'";
		opt = InsertLs;
		m_Ls.InsertItem(item,"");
		DB_excute(db,sql.GetBuffer(0),GetWareAdj,this);
		sql.ReleaseBuffer();
		if(!str[2].IsEmpty())
			m_Ls.SetItemText(item,3,str[2]);
		else
			m_Ls.SetItemText(item,3,m_Ls.GetItemText(item,2));

		if(!str[1].IsEmpty())
			m_Ls.SetItemText(item,5,str[1]);
		else
			m_Ls.SetItemText(item,5,m_Ls.GetItemText(item,4));

		m_Ls.SetItemText(item,6,str[3]);
		
		m_ReNum.SetWindowText("");
		m_RePrice.SetWindowText("");
		m_Text.SetWindowText("");
		return;
	}
	else
	{
		MessageBox("至少修改任意一个属性吧","提示");
		return;
	}
}

void CAddWareAdj::OnOk() 
{
	// TODO: Add your control notification handler code here
	int item = m_Ls.GetItemCount();
	for(int i = 0;i < item;i++)
	{
		/*insert value into wareChng*/
		sql = "insert into wareChng values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),'" +
			m_Ls.GetItemText(i,0) + "','" + m_Ls.GetItemText(i,1) + "','" + 
			m_Ls.GetItemText(i,2) + "','" + m_Ls.GetItemText(i,3) + "','" + 
			m_Ls.GetItemText(i,4) + "','" + m_Ls.GetItemText(i,5) + "','" + 
			m_Ls.GetItemText(i,6) + "')" ;
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
		/*insert value into setLog*/
		sql = "insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),\
			(select 员工编号 from Employees where 员工名称 = '" + UserName +"'),'" + 
			UserName +"','调整','调整" + m_Ls.GetItemText(i,1) +"属性')";
		DB_excuteNoCall(db,sql.GetBuffer(0));          
		sql.ReleaseBuffer();
		/*insert value into dataOtherExpend to banlance the cost*/
		int count,price[2],num[2];
		/* if num or price havent change ,the number will be zero,then cause count = 0 */
		/* if num or price not equeals 0, then we should update the inventory table data */
		result = m_Ls.GetItemText(i,3);//实际金额
		
			price[0] =  atoi(result.GetBuffer(0));
			result.ReleaseBuffer();
			result = m_Ls.GetItemText(i,2);
			price[1] = atoi(result.GetBuffer(0));//商品单价
			result.ReleaseBuffer();
	/*	if(price[1] == 0)
		{
			price[1] = price[0];
		}*/
		
		result = m_Ls.GetItemText(i,5);//实际库存
	
			num[0] =  atoi(result.GetBuffer(0));
			result.ReleaseBuffer();
			result = m_Ls.GetItemText(i,6);
			num[1] = atoi(result.GetBuffer(0));//在库量
			result.ReleaseBuffer();
	
	/*	if(num[1] == 0)
		{
			num[1] = num[0];
		}*/
		if(price[0] == price[1])
		{
			if(num[0] == num[1])
				count = 0;
			else
				count = price[0] * (num[1] - num[0]);
		}
		else
		{
			if(num[0] == num[1])
				count = price[1] - price[0];
			else
				count = (price[1] - price[0]) * (num[1] - num[0]);
		}
		result.Format("%d",count);
		if(count < 0)
		{
			count *= -1;
			result.Format("%d",count);
			sql = "insert into dataOtherExpend values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),'现金','" +
				result + "','库存调整:平衡" + m_Ls.GetItemText(i,1) + "库存')";
		}
		else if(count > 0)
		{
			result.Format("%d",count);
			sql = "insert into dataOtherIncome values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),'现金','" +
				result + "','库存调整:平衡" + m_Ls.GetItemText(i,1) + "库存')";
		}
		DB_excuteNoCall(db,sql.GetBuffer(0));          
		sql.ReleaseBuffer();
		
		/* update inventory date */
		sql = "update inventory ";
		if(price[0] != price[1])
		{
			sql = sql + "set 商品单价 = '" + m_Ls.GetItemText(i,3) + "'"; 
			if(num[0] != num[1])
			{
				sql = sql + ",set 在库量 = '" + m_Ls.GetItemText(i,5) + "'";
			}
			sql = sql + " where 商品编号 = '" + m_Ls.GetItemText(i,0) + "'";
			DB_excuteNoCall(db,sql.GetBuffer(0));          
			sql.ReleaseBuffer();
		}
		else
		{
			if(num[0] != num[1])
			{
				sql = sql + "set 在库量 = '" + m_Ls.GetItemText(i,5) + "' where 商品编号 = '"
					+ m_Ls.GetItemText(i,0) + "'";
				DB_excuteNoCall(db,sql.GetBuffer(0));          
				sql.ReleaseBuffer();
			}
		}
		

	}
	while(m_Ls.DeleteItem(0));
}

void CAddWareAdj::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Ls.GetSelectionMark();
	m_Ls.DeleteItem(pos);

}

void CAddWareAdj::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	DB_close(db);
	while(m_Ls.DeleteItem(0));	
	CDialog::OnClose();
}

BOOL CAddWareAdj::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_Ls.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	CImageList imagelist;
	imagelist.Create(1,24, ILC_COLOR, 1, 1); 
	m_Ls.SetImageList(&imagelist, LVSIL_SMALL);

	opt = GetLsHead;
	//DB_selectTitle(db,GetWareAdj,this,"wareChng");
	sql = "PRAGMA TABLE_INFO (wareChng)";
	DB_excute(db,sql.GetBuffer(0),GetWareAdj,this);
	sql.ReleaseBuffer();
	
	sql = "select 商品编号 from inventory where 状态 != '不可用'";
	opt = GetGOOD;
	DB_excute(db,sql.GetBuffer(0),GetWareAdj,this);
	sql.ReleaseBuffer();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddWareAdj::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString str;
	m_ReNum.GetWindowText(str);
	if(str == "0")
		m_ReNum.SetWindowText("");
}

void CAddWareAdj::OnChangeEdit2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString str;
	m_RePrice.GetWindowText(str);
	if(str == "0")
		m_RePrice.SetWindowText("");
}
