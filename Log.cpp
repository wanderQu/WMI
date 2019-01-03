// Log.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "Log.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLog dialog


CLog::CLog(CWnd* pParent /*=NULL*/)
	: CDialog(CLog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	DB_open(&db,".\\UserData\\data.db");
}


void CLog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLog)
	DDX_Control(pDX, IDC_STATIC1, m_pic);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLog, CDialog)
	//{{AFX_MSG_MAP(CLog)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_LOG, OnLog)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLog message handlers
//IDC_LOG		: Log
//IDC_ID		: UserID
//IDC_PASSWORD	: UserPassWord
int GetLog(void *data, int argc, char **argv, char **azColName)
{
	char* str = U2G(argv[argc - 1]);
	CLog * log = (CLog*)data;
	if(log->opt == GETNUMBER)
	{
		log->dbResult = str;
		return false;
	}
	log->Name = str;
	log->Log();
	return false;
} 
void CLog::OnLog() 
{
	// TODO: Add your control notification handler code here
	if(Name.IsEmpty())
	{
		CString str[2];
		m_ID.GetWindowText(str[0]);
		m_Pass.GetWindowText(str[1]);
		CString tStr;
		err = "";
	
		if(str[0].IsEmpty())
		{
			err = "账号不能为空";
			goto there;
		}
		else
		{
			tStr.Format("select count(*) from Employees where 员工编号 = '%s'",str[0]);
			opt = GETNUMBER;
			DB_excute(db,tStr.GetBuffer(1),GetLog,this);
			tStr.ReleaseBuffer();
			if(dbResult == "0")
			{
				err = "没有此用户";
				goto there;
			}
		}

		if(str[1].IsEmpty())
		{
			err = "密码不能为空";
			goto there;
		}
		else
		{
			tStr.Format("select count(*) from Employees where 员工编号 = '%s' and 账户密码 = '%s'",str[0],str[1]);
			opt = GETNUMBER;
			DB_excute(db,tStr.GetBuffer(1),GetLog,this);
			tStr.ReleaseBuffer();
			if(dbResult == "0")
			{
				err = "密码错误";
				goto there;
			}
		}	
		opt = 0;
		tStr.Format("select 员工名称 from Employees where 员工编号 = '%s'",str[0]);	
		DB_excute(db,tStr.GetBuffer(1),GetLog,this);
		tStr.ReleaseBuffer();
		CDialog::OnOK();
	
		there:
		m_Fl.SetWindowText(err);
		m_Fl.ShowWindow(true);
	}
	else
	{
		
		CDialog::OnOK();
	}
		

}

BOOL CLog::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		OnClose();
		return 0;
	}
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		OnLog();
		return 0;
	}
	if(pMsg->message == WM_KEYDOWN)
	{
		if(m_Fl.IsWindowVisible())
			m_Fl.ShowWindow(false);
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CLog::Log()
{
	OnLog();
}

BOOL CLog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect rc;
	GetClientRect(rc);
	m_pic.MoveWindow(rc);

	int x = rc.Width() / 2;
	int y = rc.Height() / 2 + 30;
	int w = rc.Width() * 12 / 35 / 2;

	rID = CRect(x - w,y - 30,x + w,y - 5);
	rPswd = CRect(x - w,y + 5,x + w,y + 30);
	rFl = CRect(x - w,y + 35,x + w,y + 55);

	m_ID.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP,rID,this,IDC_ID);
	m_Pass.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | WS_TABSTOP,rPswd,this,IDC_PASSWORD);
	m_LOG.Create("登录",BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP,CRect(x - w,y + 60,x + w,y + 85),this,IDC_LOG);


	m_Fl.Create("",WS_CHILD|WS_VISIBLE |SS_CENTERIMAGE|SS_CENTER,rFl,this,0);
	m_Fl.ShowWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CLog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetTextColor(RGB(255,0,0));
	}
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetBkColor(RGB(255,255,255));
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
