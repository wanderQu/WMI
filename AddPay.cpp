// AddPay.cpp : implementation file
//

#include "stdafx.h"
#include "wmi.h"
#include "AddPay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddPay dialog


CAddPay::CAddPay(CWnd* pParent /*=NULL*/)
	: CDialog(CAddPay::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddPay)
	//}}AFX_DATA_INIT
	DB_open(&db,".\\UserData\\Data.db");
}


void CAddPay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddPay)
	DDX_Control(pDX, IDC_EDIT2, m_DelPay);
	DDX_Control(pDX, IDC_EDIT1, m_Pay);
	DDX_Control(pDX, IDC_COMBO1, m_SupID);
	DDX_Control(pDX, IDC_LIST2, m_Ls);
	DDX_Control(pDX, IDC_EDIT3, m_Text);
	DDX_Control(pDX, IDC_COMBO2, m_MoneyType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddPay, CDialog)
	//{{AFX_MSG_MAP(CAddPay)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddPay message handlers
int GetPay(void*data,int argc,char**argv,char**column)
{
	CAddPay* dlg = (CAddPay*)data;
	if(dlg->opt == GetSup)
	{
		argv[0] = U2G(argv[0]);
		dlg->m_SupID.InsertString(dlg->m_SupID.GetCount(),argv[0]);
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
void CAddPay::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString str[5];
	m_SupID.GetWindowText(str[0]);
	if(str[0].IsEmpty())
	{
		MessageBox("还没有选择供应商呢","提示");
		m_SupID.SetFocus();
		return;
	}
	m_MoneyType.GetWindowText(str[1]);
	m_Pay.GetWindowText(str[2]);
	if(str[2].IsEmpty())
	{
		MessageBox("还没有输入付款金额啊~","提示");
		m_Pay.SetFocus();
		return;
	}
	m_DelPay.GetWindowText(str[3]);
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

					m_Pay.SetWindowText("0");
					m_DelPay.SetWindowText("0");
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
	sql = "select 供应商编号,供应商名称 from manaSup where 供应商名称 = '"+ str[0] + "'";
	opt = InsertLs;
	DB_excute(db,sql.GetBuffer(0),GetPay,this);
	sql.ReleaseBuffer();
	m_Ls.SetItemText(item,2,str[1]);
	m_Ls.SetItemText(item,3,str[2]);
	m_Ls.SetItemText(item,4,str[3]);
	m_Ls.SetItemText(item,5,str[4]);
/*	int iCount = atoi(str[3].GetBuffer(0)) + atoi(str[4].GetBuffer(0));
	str[3].ReleaseBuffer();
	str[4].ReleaseBuffer();
	str[3].Format("%d",iCount);
	m_Ls.SetItemText(item,6,str[3]);*/
	m_Pay.SetWindowText("0");
	m_DelPay.SetWindowText("0");
	m_Text.SetWindowText("");
}

void CAddPay::OnOk() 
{
	// TODO: Add your control notification handler code here
	/*check the total money ,as if over the payable*/
	int item = m_Ls.GetItemCount();
	for(int i =0; i < item;i++)
	{
		sql = "insert into dataPayment values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),'"
			+ m_Ls.GetItemText(i,0) + "','" + m_Ls.GetItemText(i,1) + "','"
			+ m_Ls.GetItemText(i,2) + "','" + m_Ls.GetItemText(i,3) + "','"
			+ m_Ls.GetItemText(i,4) + "','" + m_Ls.GetItemText(i,5) + "')";
		DB_excute(db,sql.GetBuffer(0),GetPay,this);
		sql.ReleaseBuffer();
		/*Insert SetLog*/

		sql = "insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),(select 员工编号 from Employees where 员工名称 = '"
			+ UserName + "'),'" + UserName + "','新增','新增付款单')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();	

		sql = "update dataPayable set 应付账款金额 = 应付账款金额 - "
			+ m_Ls.GetItemText(i,3) + " - " + m_Ls.GetItemText(i,4) 
			+ ",优惠金额累计 = 优惠金额累计 + " + m_Ls.GetItemText(i,4)
			+ " where 供应商编号 = '" + m_Ls.GetItemText(i,0) + "'";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();		
	}
	while(m_Ls.DeleteItem(0));	
}

void CAddPay::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Ls.GetSelectionMark();
	m_Ls.DeleteItem(pos);		
}

BOOL CAddPay::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_Ls.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	CImageList imagelist;
	imagelist.Create(1,24, ILC_COLOR, 1, 1); 
	m_Ls.SetImageList(&imagelist, LVSIL_SMALL);	

	opt = GetSup;
	sql = "select 供应商名称 from manaSup";
	DB_excute(db,sql.GetBuffer(0),GetPay,this);
	sql.ReleaseBuffer();

	opt = GetLsHead;
	DB_selectTitle(db,GetPay,this,"dataPayment");

	m_MoneyType.SetWindowText("银行转账");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddPay::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	DB_close(db);
	while(m_Ls.DeleteItem(0));
	CDialog::OnClose();
}

void CAddPay::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString str;
	m_Pay.GetWindowText(str);
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
						m_Pay.SetWindowText(str);
						m_Pay.SetSel(-1);
					}
					else
						break;
				}
				else
				{
					
					str.Delete(str.GetLength() - 1);
					m_Pay.SetWindowText(str);
					m_Pay.SetSel(-1);
					if(str.GetLength()==0)
						break;
				}
			
			}
		}
		
	}
}

void CAddPay::OnChangeEdit2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here

	CString str;
	m_DelPay.GetWindowText(str);
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
						m_DelPay.SetWindowText(str);
						m_DelPay.SetSel(-1);
					}
					else
						break;
				}
				else
				{
					
					str.Delete(str.GetLength() - 1);
					m_DelPay.SetWindowText(str);
					m_DelPay.SetSel(-1);
					if(str.GetLength()==0)
						break;
				}
			
			}
		}
		
	}
}
