// AddDistriReturn.cpp : implementation file
//

#include "stdafx.h"
#include "wmi.h"
#include "AddDistriReturn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddDistriReturn dialog


CAddDistriReturn::CAddDistriReturn(CWnd* pParent /*=NULL*/)
	: CDialog(CAddDistriReturn::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddDistriReturn)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	DB_open(&db,".\\UserData\\Data.db");
}


void CAddDistriReturn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddDistriReturn)
	DDX_Control(pDX, IDC_EDIT2, m_Text);
	DDX_Control(pDX, IDC_LIST2, m_Ls);
	DDX_Control(pDX, IDC_EDIT1, m_Num);
	DDX_Control(pDX, IDC_COMBO2, m_GoodID);
	DDX_Control(pDX, IDC_COMBO1, m_CusID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddDistriReturn, CDialog)
	//{{AFX_MSG_MAP(CAddDistriReturn)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddDistriReturn message handlers
int GetDistriReturn(void* data,int argc,char** argv,char** column)
{
	CAddDistriReturn* m_Dis = (CAddDistriReturn*)data;
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
		if(strcmp(argv[1],"��������"))
			m_Dis->m_Ls.InsertColumn(i,argv[1],LVCFMT_CENTER,130,0);
		return false;
	}
	return false;
}
void CAddDistriReturn::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int pos = m_Ls.GetSelectionMark();
	m_Ls.DeleteItem(pos);	
}

void CAddDistriReturn::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CString tmp,tmp2,tmp3,tmp4[2];
	m_CusID.GetWindowText(tmp);
	if(tmp.IsEmpty())
	{
		MessageBox("˭�����ǵķ��������أ�~","��ʾ");
		m_CusID.SetFocus();
		return;
	}
/*	else
	{
		opt = GetNum;
		sql.Format("select count(*) from manaCus where �ͻ���� = '%s'",tmp);
		DB_excute(db,sql.GetBuffer(1),GetDistri,this);
		sql.ReleaseBuffer();
		if(result == "0")
		{
			if(MessageBox("���ݿ��������û�иÿͻ�\t\r�Ƿ�ȥ��ӣ�","������ʾ",MB_OKCANCEL) == IDOK)
			{
		/*		HWND hOtherWnd = ::FindWindow(NULL,"AddCharactor");
				if(hOtherWnd == NULL)
				{
					STARTUPINFO startInfo = {0};
					PROCESS_INFORMATION processInfo = {0};
					CreateProcess(".\\excute\\AddCharactor.exe",NULL,NULL,NULL,false,NULL,NULL,NULL,&startInfo,&processInfo);
				}
				
				CString t =  UserName + ",�ͻ�,0";
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
		MessageBox("Ҫѡ�˻�������ƷŶ~","��ʾ");
		m_GoodID.SetFocus();
		return;
	}
/*-	else
	{
		opt = GetNum;
		sql.Format("select count(*) from inventory where ��Ʒ��� = '%s'",tmp);
		DB_excute(db,sql.GetBuffer(1),GetDistri,this);
		sql.ReleaseBuffer();
		if(result == "0")
		{
			if(MessageBox("���ݿ��������û�������Ʒ\t\r�Ƿ�ȥ��������Ʒ��","������ʾ",MB_OKCANCEL) == IDOK)
			{
				;
			}
		}
	}*/
	m_Num.GetWindowText(tmp3);
	if(tmp3.IsEmpty())
	{
		MessageBox("��Ʒ��������Ϊ�յĹ�","��ʾ");
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
				sql.Format("select %s * (select ��Ʒ���� from inventory where ��Ʒ��� = '%s')",tmp3,tmp2);
				DB_excute(db,sql.GetBuffer(0),GetDistriReturn,this);
				sql.ReleaseBuffer();
				m_Ls.SetItemText(i,5,result);
				return;
			}	
		}
	}
	opt = InsertLs1;
	sql = "select ��Ʒ���,��Ʒ���� from inventory where ��Ʒ��� = '" + tmp2 + "'";
	DB_excute(db,sql.GetBuffer(0),GetDistriReturn,this);
	sql.ReleaseBuffer();
	opt = InsertLs2;
	sql = "select �ͻ����,�ͻ����� from manaCus where �ͻ���� = '" + tmp + "'";
	DB_excute(db,sql.GetBuffer(0),GetDistriReturn,this);
	sql.ReleaseBuffer();
	int item = m_Ls.GetItemCount() - 1;
	m_Ls.SetItemText(item,4,tmp3);
	
	opt = GetNum;
	sql.Format("select %s * (select ��Ʒ���� from inventory where ��Ʒ��� = '%s')",tmp3,tmp2);
	DB_excute(db,sql.GetBuffer(0),GetDistriReturn,this);
	sql.ReleaseBuffer();
	m_Ls.SetItemText(item,5,result);
	
	m_Text.GetWindowText(tmp4[0]);
	if(tmp4[0].IsEmpty())
	{
		tmp4[0] = "��";
	}
	m_Ls.SetItemText(item,6,tmp4[0]);
	return;	
}

void CAddDistriReturn::OnOk() 
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
		sql = "insert into distriReturn values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),'"+str+"')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
		/*update supply money*/
		sql.Format("update dataReceivable set Ӧ���˿��� = Ӧ���˿��� - %s where �ͻ���� = '%s'",
			m_Ls.GetItemText(i,5),m_Ls.GetItemText(i,2));
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
		/*insert user log*/
		sql = "insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),\
			(select Ա����� from Employees where Ա������ = '"+UserName+"'),'"+UserName+"','����','���������˻���')";
		DB_excuteNoCall(db,sql.GetBuffer(0));
		sql.ReleaseBuffer();
	}
	while(m_Ls.DeleteItem(0));		
}

void CAddDistriReturn::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	DB_close(db);
	while(m_Ls.DeleteItem(0));
	CDialog::OnClose();
}

BOOL CAddDistriReturn::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Ls.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	CImageList imagelist;
	imagelist.Create(1,24, ILC_COLOR, 1, 1); 
	m_Ls.SetImageList(&imagelist, LVSIL_SMALL);

	sql = "select �ͻ���� from manaCus where ״̬ != '������'";
	opt = GetCus;
	DB_excute(db,sql.GetBuffer(0),GetDistriReturn,this);
	sql.ReleaseBuffer();

	sql = "select ��Ʒ��� from inventory where ״̬ != '������'";
	opt = GetGOOD;
	DB_excute(db,sql.GetBuffer(0),GetDistriReturn,this);
	sql.ReleaseBuffer();

	opt = GetLsHead;
	DB_selectTitle(db,GetDistriReturn,this,"distriReturn");	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddDistriReturn::OnChangeEdit1() 
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
