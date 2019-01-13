// AddOrder.cpp : implementation file
//

#include "stdafx.h"
#include "wmi.h"
#include "AddOrder.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddOrder dialog


CAddOrder::CAddOrder(CWnd* pParent /*=NULL*/)
	: CDialog(CAddOrder::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddOrder)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	DB_open(&db,".\\UserData\\Data.db");
}


void CAddOrder::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddOrder)
	DDX_Control(pDX, IDC_EDIT1, m_Num);
	DDX_Control(pDX, IDC_LIST2, m_Ls);
	DDX_Control(pDX, IDC_COMBO1, m_GoodId);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddOrder, CDialog)
	//{{AFX_MSG_MAP(CAddOrder)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddOrder message handlers
int GetData(void* data,int argc,char** argv,char** column)
{
	CAddOrder* addOrder = (CAddOrder*) data;

	if(addOrder->opt == GetLsHead)
	{
		argv[1] = U2G(argv[1]);
		int i = addOrder->m_Ls.GetHeaderCtrl()->GetItemCount();
		if(strcmp(argv[1],"��������") && strcmp(argv[1],"�ɹ�״̬"))
			addOrder->m_Ls.InsertColumn(i,argv[1],LVCFMT_CENTER,130,0);
		return false;
	}
	if(addOrder->opt == GetType)
	{
		argv[0] = U2G(argv[0]);	
		addOrder->m_GoodId.InsertString(addOrder->m_GoodId.GetCount(),argv[0]);
	}
	else if(addOrder->opt == GetNumber)
	{ 
		argv[0] = U2G(argv[0]);
		addOrder->result = argv[0];
	}
	else if(addOrder->opt == LsInsert)
	{
		int item = addOrder->m_Ls.GetItemCount();
		addOrder->m_Ls.InsertItem(item,"");
		for(int i = 0;i<argc;i++)
		{
			argv[i] = U2G(argv[i]);
			addOrder->m_Ls.SetItemText(item,i,argv[i]);
		}
	}
	return false;
}

BOOL CAddOrder::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	char str[] = "select ��Ʒ��� from Inventory where ״̬ != '������'";
	opt = GetType;
	DB_excute(db,str,GetData,this);

	m_Ls.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	CImageList imagelist;
	imagelist.Create(1,24, ILC_COLOR, 1, 1); 
	m_Ls.SetImageList(&imagelist, LVSIL_SMALL);

	opt = GetLsHead;
	DB_selectTitle(db,GetData,this,"proTrack");
/*	m_Ls.InsertColumn(0,"��Ʒ���"	,LVCFMT_LEFT,130,0);
	m_Ls.InsertColumn(1,"��Ʒ����"	,LVCFMT_LEFT,130,1);
	m_Ls.InsertColumn(2,"��Ʒ����"	,LVCFMT_LEFT,130,4);
	m_Ls.InsertColumn(3,"��Ӧ�̱��",LVCFMT_LEFT,130,2);
	m_Ls.InsertColumn(4,"��Ӧ������",LVCFMT_LEFT,130,3);
	m_Ls.InsertColumn(5,"��Ʒ����"	,LVCFMT_LEFT,130,4);
*/
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddOrder::OnOk() 
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
		sql = "insert into proTrack values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),'"+str+"')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
		/*update supply money*/
	/*	sql.Format("update dataPayable set Ӧ���˿��� = \
			Ӧ���˿��� + (select ��Ʒ���� from inventory where ��Ʒ��� = '%s') * %s \
			where ��Ӧ�̱�� = '%s'",m_Ls.GetItemText(i,0),m_Ls.GetItemText(i,4),m_Ls.GetItemText(i,2));*/
		sql.Format("update dataPayable set Ӧ���˿��� = Ӧ���˿��� + %s where ��Ӧ�̱�� = '%s'",
			m_Ls.GetItemText(i,5),m_Ls.GetItemText(i,2));
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
		/*insert user log*/
		sql = "insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),\
			(select Ա����� from Employees where Ա������ = '"	+ UserName + "'),'" 
			+ UserName + "','����','�����ɹ�����')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
		sql = "update inventory set �ɹ��ڶ��� = �ɹ��ڶ��� + '"+m_Ls.GetItemText(i,4)+"'";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
	}
	while(m_Ls.DeleteItem(0));
}

void CAddOrder::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString str,tmp,tmp2;
	m_GoodId.GetWindowText(tmp);
	if(tmp.IsEmpty())
	{
		MessageBox("����û��ѡ����Ʒ��~","������ʾ");
		m_GoodId.SetFocus();
		return;
	}
/*	else
	{
		opt = GetNumber;
		str.Format("select count(*) from inventory where ��Ʒ��� = '%s'",tmp);
		DB_excute(db,str.GetBuffer(1),GetData,this);
		str.ReleaseBuffer();
		if(result == "0")
		{
			if(MessageBox("���ݿ��������û�������Ʒ\t\r�Ƿ�ȥ��������Ʒ��","������ʾ",MB_YESNO) == IDOK)
			{
				;
			}
		}
	}*/
	m_Num.GetWindowText(tmp2);
	if(tmp2.IsEmpty())
	{
		MessageBox("��Ʒ��������Ϊ��Ŷ~","������ʾ");
		m_Num.SetFocus();
		return;
	}
	for(int i = 0;i < m_Ls.GetItemCount();i++)
	{
		CString tmp3 = m_Ls.GetItemText(i,0);
	
		if(tmp == tmp3)
		{
			tmp3 = m_Ls.GetItemText(i,4);
			int iCount = atoi(tmp2.GetBuffer(0)) + atoi(tmp3.GetBuffer(0));
			tmp2.ReleaseBuffer();
			tmp3.ReleaseBuffer();
			tmp2.Format("%d",iCount);
			m_Ls.SetItemText(i,4,tmp2);
			opt = GetNumber;
			str.Format("select %s * (select ��Ʒ���� from inventory where ��Ʒ��� = '%s')",tmp2,tmp);
			DB_excute(db,str.GetBuffer(0),GetData,this);
			str.ReleaseBuffer();
			m_Ls.SetItemText(i,5,result);
			return;
		}
	}
	opt = LsInsert;
	str.Format("select ��Ʒ���,��Ʒ����,��Ӧ�̱��,��Ӧ������ from inventory where ��Ʒ��� = '%s'",tmp);
	DB_excute(db,str.GetBuffer(0),GetData,this);
	str.ReleaseBuffer();
	int item = m_Ls.GetItemCount() - 1;
	m_Ls.SetItemText(item,4,tmp2);

	opt = GetNumber;
	str.Format("select %s * (select ��Ʒ���� from inventory where ��Ʒ��� = '%s')",tmp2,tmp);
	DB_excute(db,str.GetBuffer(0),GetData,this);
	str.ReleaseBuffer();
	m_Ls.SetItemText(item,5,result);

}

void CAddOrder::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	DB_close(db);
	while(m_Ls.DeleteItem(0));
	CDialog::OnClose();
}

void CAddOrder::OnChangeEdit1() 
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

void CAddOrder::OnEditchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CString str;
	m_GoodId.GetWindowText(str);
	if(str.IsEmpty())
	{
		m_GoodId.ShowDropDown(false);
		return;
	}
	
	CString sql;
	result = "0";
	sql= "select count(*) from inventory where ��Ʒ��� like '%"+str+"%'";
	opt = GetNumber;
	DB_excute(db,sql.GetBuffer(1),GetData,this);
	sql.ReleaseBuffer();
	if(result != "0")
	{
		m_GoodId.ResetContent();
		sql.Format("select ��Ʒ��� from inventory where ��Ʒ��� like '%s%s%s'","%",str,"%");
		opt = GetType;
		DB_excute(db,sql.GetBuffer(1),GetData,this);
		sql.ReleaseBuffer();
	}

//	int item = m_GoodId.FindStringExact(0,str);
	m_GoodId.ShowDropDown(true);
//	if(item >= 0)
//		m_GoodId.SetTopIndex(item);

/*	m_GoodId.ShowDropDown(true);
	int iCount = arr.GetUpperBound();
	CString tmp;
	for(int i = 0;i < iCount;i++)
	{
		tmp = arr.GetAt(i);
		if(tmp.Find(str) != -1)
		{
			m_GoodId.SetTopIndex(i);
		}
		else
		{
			m_GoodId.DeleteString(i);
		}
	}
*/
}

void CAddOrder::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}


void CAddOrder::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Ls.GetSelectionMark();
	m_Ls.DeleteItem(pos);
}
