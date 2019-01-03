// hangePass.cpp : implementation file
//

#include "stdafx.h"
#include "wmi.h"
#include "hangePass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ChangePass dialog


ChangePass::ChangePass(CWnd* pParent /*=NULL*/)
	: CDialog(ChangePass::IDD, pParent)
{
	//{{AFX_DATA_INIT(ChangePass)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	DB_open(&db,".\\UserData\\Data.db");
}


void ChangePass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ChangePass)
	DDX_Control(pDX, IDC_STATIC1, m_Text);
	DDX_Control(pDX, IDC_EDIT3, m_Confirm);
	DDX_Control(pDX, IDC_EDIT2, m_NewPass);
	DDX_Control(pDX, IDC_EDIT1, m_OldPass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ChangePass, CDialog)
	//{{AFX_MSG_MAP(ChangePass)
	ON_EN_SETFOCUS(IDC_EDIT2, OnSetfocusEdit2)
	ON_EN_SETFOCUS(IDC_EDIT3, OnSetfocusEdit3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ChangePass message handlers
int GetChng(void*data,int argc,char**argv,char**column)
{
	ChangePass *dlg = (ChangePass*)data;
	if(dlg->opt == GetNum)
	{
		argv[0] = U2G(argv[0]);
		dlg->result = argv[0];
		return false;
	}
	return false;
}
void ChangePass::OnOK() 
{
	// TODO: Add extra validation here
	CString str[2];
	m_OldPass.GetWindowText(str[0]);
	sql = "select count(*) from Employees where Ա������ = '"
		+ UserName + "' and �˻����� = '" + str[0] + "'";
	opt = GetNum;
	DB_excute(db,sql.GetBuffer(0),GetChng,this);
	sql.ReleaseBuffer();
	if(result == "0")
	{
		m_Text.SetWindowText("�������!");
		m_Text.ShowWindow(true);
		m_OldPass.SetFocus();
		return;
	}
	m_NewPass.GetWindowText(str[0]);
	m_Confirm.GetWindowText(str[1]);
	if(str[0] != str[1])
	{
		m_Text.SetWindowText("���벻һ��");
		m_Text.ShowWindow(true);
		m_Confirm.SetFocus();
		return;
	}
	sql = "update Employees set �˻����� = '" + str[0] 
		+ "' where Ա������ = '" + UserName + "'";
	DB_excuteNoCall(db,sql.GetBuffer(0));
	sql.ReleaseBuffer();

	sql = "insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),\
		(select Ա����� from Employees where Ա������ = '"	+ UserName + "'),'" 
		+ UserName + "','�޸�','�޸ĸ�������')";
	DB_excuteNoCall(db,sql.GetBuffer(0));
	sql.ReleaseBuffer();
	CDialog::OnOK();
}

void ChangePass::OnCancel() 
{
	// TODO: Add extra cleanup here
	DB_close(db);
	CDialog::OnCancel();
}

void ChangePass::OnSetfocusEdit2() 
{
	// TODO: Add your control notification handler code here
	CString str;
	m_OldPass.GetWindowText(str);
	if(str.IsEmpty())
	{
		m_Text.SetWindowText("��û�����������");
		m_Text.ShowWindow(true);
		m_OldPass.SetFocus();
		return;
	}
	sql = "select count(*) from Employees where Ա������ = '"
		+ UserName + "' and �˻����� = '" + str + "'";
	opt = GetNum;
	DB_excute(db,sql.GetBuffer(0),GetChng,this);
	sql.ReleaseBuffer();
	if(result == "0")
	{
		m_Text.SetWindowText("�������!");
		m_Text.ShowWindow(true);
		m_OldPass.SetFocus();
		return;
	}
}

BOOL ChangePass::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Text.ShowWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ChangePass::OnSetfocusEdit3() 
{
	// TODO: Add your control notification handler code here
	CString str;
	m_OldPass.GetWindowText(str);
	if(str.IsEmpty())
	{
		m_Text.SetWindowText("��û�����������");
		m_Text.ShowWindow(true);
		m_OldPass.SetFocus();
		return;
	}
	sql = "select count(*) from Employees where Ա������ = '"
		+ UserName + "' and �˻����� = '" + str + "'";
	opt = GetNum;
	DB_excute(db,sql.GetBuffer(0),GetChng,this);
	sql.ReleaseBuffer();
	if(result == "0")
	{
		m_Text.SetWindowText("�������!");
		m_Text.ShowWindow(true);
		m_OldPass.SetFocus();
		return;
	}	
}
