// TabDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "TabDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabDlg dialog


CTabDlg::CTabDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTabDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTabDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTabDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTabDlg, CDialog)
	//{{AFX_MSG_MAP(CTabDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabDlg message handlers

BOOL CTabDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
//	DWORD dwStyle = WS_VISIBLE|WS_CHILD|WS_BORDER;
//
//	UINT IDC_EXTRA = 0;
//	m_edit.Create(dwStyle,CRect(0,0,200,20),this,IDC_EXTRA);
//	m_edit.ShowWindow(false);
//
//	CTime tm;
//	tm = CTime::GetCurrentTime();
//
//	int count = sizeof(m_tm)/sizeof(CDateTimeCtrl);
//	while(--count != 0)
//	{
//	
//		m_tm[count].Create(dwStyle,CRect(0,0,100,20),this,IDS_TMSTA+count);
//		m_tm[count].SetFormat("yyyy-mm-dd");
//		m_tm[count].SetTime(&tm);
//		m_tm[count].ShowWindow(false);
//	}
//
//	count = 0;
//	CString str[] = {"查询","打印","导出","新增","删除","列表设置"};
//	CRect rc = CRect(0,0,80,25);
//	while(count != 6)
//	{
//		m_bt[count].Create(str[count],dwStyle,rc,this,IDS_BT_SERCH+count);
//		str[count].Empty();
//		m_bt[count++].ShowWindow(false);
//	}
//
//	CString str2[] = {"客户类别","客户","供应商类别","供应商","-","单据日期","总计:","总计:","时间"};
//	count = 0;
//	while(count != 9)
//	{
//		if(count > 5)
//			m_tx[count].Create(str2[count],dwStyle|SS_CENTER|SS_CENTERIMAGE,CRect(0,0,150,20),this,IDC_EXTRA+count);
//		else
//			m_tx[count].Create(str2[count],dwStyle|SS_CENTER|SS_CENTERIMAGE,CRect(0,0,8 * str2[count].GetLength(),20),this,IDC_EXTRA+count);
//		m_tx[count].ShowWindow(false);
//		str2[count++].Empty();
//	}
//	
//	count = 0;
//	CFont font;
//	font.CreateFont(20,10,0,0, 
//		 FW_BOLD,					// nWeight    
//         FALSE,                     // bItalic    斜体？
//         FALSE,                     // bUnderline    
//         0,                         // cStrikeOut    
//         ANSI_CHARSET,              // nCharSet    
//         OUT_DEFAULT_PRECIS,        // nOutPrecision    
//         CLIP_DEFAULT_PRECIS,       // nClipPrecision    
//         DEFAULT_QUALITY,           // nQuality    
//         DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily    
//         "宋体");					// lpszFac   }
//	while(count != 2)
//	{
//		
//		m_ls[count].Create(dwStyle|LVS_REPORT|LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_ONECLICKACTIVATE|LVS_EX_GRIDLINES,
//						CRect(0,0,750,380),this,IDS_LS1+count);
//		m_ls[count].SetFont(&font,true);
//		m_ls[count++].ShowWindow(false);
//	}
//	DeleteObject(font);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
