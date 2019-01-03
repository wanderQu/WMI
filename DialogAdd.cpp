// DialogAdd.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "DialogAdd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogAdd dialog


CDialogAdd::CDialogAdd(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogAdd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogAdd)
	//}}AFX_DATA_INIT
	isListEmpty = -1;
//	list = 0;
//	rcAdd = 0;
	item = -1;
}


void CDialogAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogAdd)
	DDX_Control(pDX, IDC_LIST1, m_Ls);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogAdd, CDialog)
	//{{AFX_MSG_MAP(CDialogAdd)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_MOUSEMOVE()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_WM_PAINT()
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_COMMAND(IDM_DELETE, OnDelete)
	ON_COMMAND(IDM_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogAdd message handlers

void CDialogAdd::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

	if(MessageBox("确定要退出吗？\r\n退出的话，将不会保存所有操作!","Warning",MB_OKCANCEL) == IDOK)
	{
		pWnd = FindWindow("#32770","功能模块");
		::SendMessage(pWnd->GetSafeHwnd(),WM_USER+1,2,0);

		CDialog::OnCancel();
	}
	DeleteAll();

}

BOOL CDialogAdd::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		if(isEdit)
		{
			m_Edit.SetWindowText("");
			m_Edit.ShowWindow(false);
		}
		else
			OnClose();
		return true;
	}
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if(isEdit)
		{
			m_Edit.GetWindowText(strTemp);
			m_Ls.SetItemText(ptClick.x,ptClick.y,strTemp);
			
			SetListWidth(strTemp,ptClick.y);
			m_Edit.SetWindowText("");
			m_Edit.ShowWindow(false);
			CheckState();
			isEdit = false;
		}
		else
			OnButton2();
		return true;
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CDialogAdd::OnButton2() 
{
	// TODO: Add your control notification handler code here
//	m_Ls.InsertColumn(0,"a",LVCFMT_LEFT,120,0);

	if(MessageBox("确定要保存吗？\r\n保存后数据将无法删除!","Warning",MB_OKCANCEL) == IDOK)
	{
		if(isEdit)
		{
			m_Edit.GetWindowText(strTemp);
			m_Ls.SetItemText(ptClick.x,ptClick.y,strTemp);
			
			SetListWidth(strTemp,ptClick.y);
			m_Edit.SetWindowText("");
			m_Edit.ShowWindow(false);
			isEdit = false;
		}
	
		Excute();
		DeleteAll();
	//	pWnd = FindWindow("#32770","功能模块");
	//	::SendMessage(pWnd->GetSafeHwnd(),WM_USER+1,1,0);
		CDialog::OnOK();
	}
}

void CDialogAdd::OnButton1() 
{
	// TODO: Add your control notification handler code here
	OnClose();
}


void CDialogAdd::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnMouseMove(nFlags, point);
}


BOOL CDialogAdd::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Ls.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	CImageList imagelist;
	imagelist.Create(1,24, ILC_COLOR, 1, 1); 
	m_Ls.SetImageList(&imagelist, LVSIL_SMALL);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDialogAdd::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	UNREFERENCED_PARAMETER(pResult);

	LPNMITEMACTIVATE pia = (LPNMITEMACTIVATE)pNMHDR;
	LVHITTESTINFO lvhti;

	// Clear the subitem text the user clicked on.
	lvhti.pt = pia->ptAction;
	m_Ls.SubItemHitTest(&lvhti);
	m_Ls.SetItemState(lvhti.iItem, 0, LVIS_SELECTED);
	m_Ls.SetSelectionMark(-1);
/*	if(lvhti.iItem == -1 && lvhti.iSubItem >= 0)
		for(int i = 0;i <= item;i++)
			if(m_Ls.GetItemText(i,lvhti.iSubItem) == "")
			{
				lvhti.iItem = i;
				break;
			}
*/
//	lvhti.iItem++;
	if(lvhti.iItem == -1 && lvhti.iSubItem >= 0)
		lvhti.iItem = 0;
	CString str;
	str.Format("%d,%d",lvhti.iItem,lvhti.iSubItem);
	MessageBox(str,"e");
	if(lvhti.iItem > -1 && lvhti.iSubItem >= 0)
	{
		//m_myListCtrl.SetItemText(lvhti.iItem, lvhti.iSubItem, NULL);
		//lvhti.iItem				行
		//lvhti.iSubItem			列
		
		if(isEdit == 1)
		{

			m_Edit.GetWindowText(strTemp);
			m_Ls.SetItemText(ptClick.x,ptClick.y,strTemp);
			
			SetListWidth(strTemp,ptClick.y);
			m_Edit.SetWindowText("");
			m_Edit.ShowWindow(false);
			CheckState();
		}

		ptClick.x = lvhti.iItem;
		ptClick.y = lvhti.iSubItem;
		m_Ls.GetSubItemRect(ptClick.x,ptClick.y,LVIR_LABEL,rcTemp);
		strTemp = m_Ls.GetItemText(ptClick.x,ptClick.y);
		if(m_Edit.m_hWnd == NULL)
		{
			m_Edit.Create(WS_CHILD|WS_VISIBLE|WS_BORDER|ES_AUTOHSCROLL,rcTemp,this,IDS_ADD_ED);
		}

		rcTemp.top += 2;
		rcTemp.left += 2;
		rcTemp.right -= 2;
		rcTemp.bottom -= 2;

		m_Edit.MoveWindow(rcTemp);
		m_Edit.SetWindowText(strTemp);
		m_Edit.ShowWindow(true);
		m_Edit.SetFocus();
		isEdit = true;
		
	}
	

}



void CDialogAdd::AutoInsertInfo()
{
	for(int i = 0;i < item;i++)
		for(int j = 0;j < column;j++)
			if(m_Ls.GetItemText(i,j) == "")
			{
				NMLISTVIEW nmListView; 
				nmListView.iItem = i; //告诉响应函数选中的是第几行，如果为-1则为不选中 
				nmListView.hdr.code = NM_CLICK; 
				nmListView.hdr.idFrom = IDC_LIST1; 
				nmListView.hdr.hwndFrom = m_Ls.m_hWnd; 
				::SendMessage(m_Ls.m_hWnd,WM_NOTIFY,NULL,(LPARAM)&nmListView);
				return;
			}
}

void CDialogAdd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	isEdit = false;
	column = m_Ls.GetHeaderCtrl()->GetItemCount();
	if(item == -1)
		item = m_Ls.InsertItem(0,"");
}

void CDialogAdd::SetListWidth(CString str,int col)
{
	SIZE fSize;
	::GetTextExtentPoint32(::GetDC(this->m_Ls.m_hWnd),str,str.GetLength(),&fSize);
	if(m_Ls.GetColumnWidth(col) < fSize.cx)
		m_Ls.SetColumnWidth(col,fSize.cx + 30);		
}



void CDialogAdd::CheckState()
{	
	for(int i = 0;i < column;i++)
		if(m_Ls.GetItemText(item,i) == "")
			return;
	item = m_Ls.InsertItem(item + 1,"");
}

void CDialogAdd::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	CPoint pt;
	GetCursorPos(&pt);
	ScreenToClient(&pt);

	m_Ls.GetClientRect(&rcTemp);
	if(isEdit)
	{
		m_Edit.ShowWindow(false);
		m_Edit.SetWindowText("");
	}
	if(m_Ls.GetColumnWidth(0) + rcTemp.left < pt.x)
	{
		m_Ls.GetItemRect(item,&rcTemp,LVIR_LABEL);
		if(rcTemp.bottom > pt.y)
		{
			m_Ls.GetItemRect(0,&rcTemp,LVIR_LABEL);
			if(rcTemp.top < pt.y)
			{
				ClientToScreen(&pt);
				CMenu menu;
				menu.LoadMenu(IDR_DELETE);
				CMenu *pMenu;
				pMenu = menu.GetSubMenu(0);
				pMenu->TrackPopupMenu(TPM_RIGHTBUTTON|TPM_LEFTALIGN,pt.x,pt.y,this,NULL);
				menu.DestroyMenu();
			}
		}
	}
	
}



void CDialogAdd::OnDelete() 
{
	// TODO: Add your command handler code here
	if(item == 0)
	{
		for(int i = 0;i < column;i++)
			m_Ls.SetItemText(item,i,"");
	}
	else
	{
		m_Ls.DeleteItem(m_Ls.GetSelectionMark());
		item--;
	}
}

void CDialogAdd::OnCancel() 
{
	// TODO: Add your command handler code here
//	m_Ls.SetItemState(m_Ls.GetSelectionMark(), 0,-1);
	
	m_Edit.DestroyWindow();
}


CString CDialogAdd::ProTrack(CString time,CString str1, CString str2)
{

	CString addSQL = //proTrack have no colum named 单据日期？why？
		"insert into proTrack values('"+ time +	"',(select 商品编号 from inventory where 商品名称 = '" + str1 +
		"'),'" + str1 + 
		"','" + str2 + 
		"', (select 供应商编号 from inventory where 商品名称 = '" + str1 + 
		"'),(select 供应商名称 from inventory where 商品名称 = '" + str1 + 
		"'),'在途');\
		insert into dataPayable values((select 供应商编号 from inventory where 商品名称 = '" + str1 + 
		"'),(select 供应商名称 from inventory where 商品名称 = '" + str1 + 
		"'),(select 商品单价 from inventory where 商品名称 = '" + str1 + 
		"') * " + str2 + ")";

	return addSQL;
}

void CDialogAdd::Excute()
{
	CString strTime;
	CTime time;
	time = CTime::GetCurrentTime();
	strTime = time.Format("%Y/%m/%d");

	sqlite3 *db;
	DB_open(&db,".\\UserData\\data.db");

	int i = 0;
	int item = m_Ls.GetItemCount() - 1;
	int col = m_Ls.GetHeaderCtrl()->GetItemCount();
	if(tbName == "proTrack")
	{
		for(;i < item;i++)
		{
			CString str = ProTrack(strTime,m_Ls.GetItemText(i,0),m_Ls.GetItemText(i,1));
			DB_excuteNoCall(db,str);
			MessageBox(str,"e");
		}
	}
	DB_close(db);
}

void CDialogAdd::DeleteAll()
{
	while(m_Ls.DeleteColumn(0));
	while(m_Ls.DeleteItem(0));
	column = item = 0;
}
