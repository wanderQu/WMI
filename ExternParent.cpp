// ExternParent.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "ExternParent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CExternParent dialog
bool g_lsEdit = false;

CExternParent::CExternParent(CWnd* pParent /*=NULL*/)
	: CDialog(CExternParent::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExternParent)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	count = -1;
	thisPos = -1;
	HaveTime = false;

//	m_this = new CExternParent;
//	DB_open(&db,".\\UserData\\database.db");
	m_font = new CFont;
	m_font->CreateFont(
		 16,				    	//height
		 8,							//wiidth
	     0,
		 0,							
		 FW_NORMAL,					 // nWeight    
         FALSE,                      // bItalic    斜体？
         FALSE,                     // bUnderline    
         0,                         // cStrikeOut    
         ANSI_CHARSET,              // nCharSet    
         OUT_DEFAULT_PRECIS,        // nOutPrecision    
         CLIP_DEFAULT_PRECIS,       // nClipPrecision    
         DEFAULT_QUALITY,           // nQuality    
         DEFAULT_PITCH,				// nPitchAndFamily    
         "宋体"						// lpszFac   
          ); 
//	pCreateCtrl = this->CreateCtrl;
//	memset(pDialog,0,sizeof(pDialog));
//
//	UINT utmp[35] = 
//	{
//		IDD_PROCUR_ORDER,IDD_PROCUR_QUERY,IDD_PROCUR_TRACK,IDD_PROCUR_RETURN,
//		IDD_PROCUR_INTELL,IDD_DISTRIBUT_LIST,IDD_DISTRIBUT_QUERY,
//		IDD_DISTRIBUT_TRACK,IDD_WAREHOUSE_REQUISITION,IDD_WAREHOUSE_IN,
//		IDD_WAREHOUSE_OUT,IDD_WAREHOUSE_STOCK,IDD_WAREHOUSE_CHNG,
//		IDD_WAREHOUSE_QUERY,IDD_MANAGE_CUS,IDD_MANAGE_SUPPLY,IDD_MANAGE_GOODS,
//		IDD_MANAGE_WAREHOUSE,IDD_MANAGE_ADDRESS,IDD_DATA_VOUCHER,
//		IDD_DATA_PAYMENT,IDD_DATA_OTHER_INCOM,IDD_DATA_OTHER_EXPEND,
//		IDD_DATA_TRANSFER,IDD_DATA_VERIFICATION,IDD_ASSERT_EXPENSE,
//		IDD_ASSERT_PAYABLE,IDD_ASSERT_RECEIVABLE,IDD_ASSERT_CUS_STATE,
//		IDD_ASSERT_VENDOR_STATE,IDD_ASSERT_OTHER_IN_AND_OUT,
//		IDD_ASSERT_INCOM_STATE,IDD_SET_SYS_PARAM,IDD_SET_PERMIS,IDD_SET_LOG
//	};
//
//	memcpy(DialogID,utmp,sizeof(utmp));
//	m_Child = new CTabDlg();
	DWORD dwStyle = WS_CHILD | WS_VISIBLE;

	dwEdStyle  = dwStyle | ES_AUTOVSCROLL|WS_BORDER;		//edit style
	edID = IDS_ED;

//	dwTxStyle[0] = dwStyle | SS_CENTER | SS_CENTERIMAGE;	//cstatic style
	dwTxStyle = dwStyle | SS_CENTER | SS_CENTERIMAGE;	//cstatic style
	txID = 0;

	dwCbStyle = dwStyle | CBS_DROPDOWN | LBS_SORT | CBS_SIMPLE;		//combo style
	cbID = IDS_CB;

	dwTmStyle = dwStyle;		//time style
	tmID = IDS_TM;

	dwLsStyle = dwStyle | LVS_REPORT;		//list style
	lsID = IDS_LS;

	dwBtStyle = dwStyle|BS_PUSHBUTTON;		//button style
	btID = IDS_BT;
	
	memset(iCtrl,0,sizeof(iCtrl));
	memset(iTemp,0,sizeof(iTemp));

	m_ed = new CEdit			[5];			
	m_tx = new CStatic			[10];			
	m_bt = new CButton			[10];		
	m_cb = new CComboBox		[5];
//	strCb = new CString			[5];
	m_ls = new CListCtrl		[3];		
	m_tm = new CDateTimeCtrl	[3];

	DB_open(&db,".\\UserData\\DataBase.db");
	DB_open(&db_ls,".\\UserData\\Data.db");

//	m_Add = new CDialogAdd;
}


void CExternParent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExternParent)
	DDX_Control(pDX, IDC_TAB1, m_Tab);
	//}}AFX_DATA_MAP
}

//	afx_msg void OnBtClick(UINT ID);
//  afx_msg void OnEditchangeCombo(UINT ID);

BEGIN_MESSAGE_MAP(CExternParent, CDialog)
	//{{AFX_MSG_MAP(CExternParent)
	ON_NOTIFY(NM_RCLICK, IDC_TAB1, OnRclickTab1)
	ON_WM_CLOSE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
//	ON_BN_CLICKED(IDS_BT,OnBtClick)
//	ON_BN_CLICKED(IDS_BT2,OnBtClick)
//	ON_BN_CLICKED(IDS_BT3,OnBtClick)
//	ON_BN_CLICKED(IDS_BT4,OnBtClick)
//	ON_BN_CLICKED(IDS_BT5,OnBtClick)
//	ON_BN_CLICKED(IDS_BT6,OnBtClick)
	ON_COMMAND_RANGE(IDS_BT,IDS_BT6,OnBtClick)
	ON_MESSAGE(WM_CREATE_WND, OnMyMessage)
	ON_MESSAGE(WM_USER + 1, Exit)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExternParent message handlers
LRESULT CExternParent::Exit(WPARAM wParam, LPARAM lParam)
{
	switch(wParam)
	{
	case 0:
		{	
			delete [] m_bt;	
			delete [] m_ls;	
			delete [] m_cb;		
			delete [] m_tx;	
			delete [] m_tm;
			delete [] m_ed;	
			delete m_font;	
			DB_close(db);
			DB_close(db_ls);
//			delete m_Add;
		}
	case 1:
		{
			//CDiaogAdd->saveSrc;			copy dialog list info;
//			for(int i = 0;i < num;i++)
	//		m_ls->InsertItem(
//			m_Add->isLsEmpty = -1;
//			for(int i = 0;i < m_Add->column;i++)
//				delete [] m_Add->list[i];
//			delete [] m_Add->list;
//			m_Add->m_Ls.DeleteAllItems();		//delete all item
	/*		int item = m_ls->GetItemCount();
			for(int i = item;i <= m_Add->item + item;i++)
			{
				m_ls->InsertItem(i,"");
				for(int j = 0;j <= m_Add->column;j++)
				{
					m_ls->SetItemText(i,j,m_Add->m_Ls.GetItemText(i,j));
				}
			}
			m_Add->column = 0;
			m_Add->item = -1;
			while(m_Add->m_Ls.DeleteColumn(0)); //delete all column*/
			Query();

		}
	case 2:
		{
			//CDialogAdd->cancleSrc;		nothing to do;
//			for(int i = 0;i < m_Add->column;i++)
//				delete [] m_Add->list[i];
//			delete [] m_Add->list;
//
//			m_Add->m_Ls.DeleteAllItems();
//			m_Add->isLsEmpty = -1;
	/*		m_Add->column = 0;
			m_Add->item = -1;
			while(m_Add->m_Ls.DeleteColumn(0));*/
//			m_Add->DestroyWindow();
//			CloseHandle(m_Add->GetSafeHwnd());

		}
	}
	return true;
}
LRESULT CExternParent::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	
	//always keep the dialog visible
	if(!this->IsWindowVisible())
	{
		ShowWindow(true);
	}
//	if(m_font == NULL)
//		m_font = m_Tab.GetFont();
//	
	DealMessage(wParam,lParam);
	return 0;
}
int GetExtraInfo(void*data,int argc,char**argv,char**column)
{
	CExternParent* dlg = (CExternParent*)data;
	if(dlg->opt == GetNum)
	{
		argv[0] = U2G(argv[0]);
		dlg->result = argv[0];
		return false;
	}
	return false;
}
void CExternParent::OnBtClick(UINT id)
{
//	CWnd *p = GetFocus();
	CString str;
	GetDlgItem(id)->GetWindowText(str);
//	if(strcmp(str,"列表设置"))
//	{ 
//		//获取第一个列表的列名，然后弹出窗口进行设置？DoMadol结束，获取新的排序
//		//然后设置列表，但是
//
//	}
//	else 
	if(!strcmp(str,"新增"))
	{
		//首先要判断新增的对象，是~List对象的文本，还是关于List的数据
	
//		if(m_Add->m_hWnd == 0)
	//		m_Add->Create(IDD_DIALOG_ADD,this);
		

	//	m_Add->ShowWindow(true);
//		m_Add->isDate = isDate;
//		m_Add->tbName = tbName;
//		CopyLsData(&m_Add->m_Ls,m_ls); //通过地址操作

	//	m_Add->column = m_Add->m_Ls.GetHeaderCtrl()->GetItemCount();
	
	//	m_Add->m_Ls.InsertColumn(0,"操作",LVCFMT_CENTER,50,0);
		
	//	this->EnableWindow(false);
		if(tbName == "inventory")
		{
			AddGood dlg;
			dlg.UserName = UserName;
			dlg.DoModal();
			Query();
		}
		else if(tbName == "manaCus")
		{
			Charac cus;
			cus.tbName = tbName;
			cus.UserName = UserName;
			cus.DoModal();
			Query();
		}
		else if(tbName == "manaSup")
		{
			Charac sup;
			sup.tbName = tbName;
			sup.UserName = UserName;
			sup.DoModal();
			Query();
		}
		else if(tbName == "Employees")
		{
			Charac employee;
			employee.tbName = tbName;
			employee.UserName = UserName;
			employee.DoModal();
			Query();
		}
		else if(tbName == "manaWare")
		{
			/*directly insert into manaWare*/
		//	char sql[] = "insert "
			opt = GetNum;
			sql = "select count(*) from manaWare";
			DB_excute(db_ls,sql.GetBuffer(0),GetExtraInfo,this);
			sql.ReleaseBuffer();
			int num = atoi(result.GetBuffer(0));
			result.ReleaseBuffer();
			result.Format("%d",num + 1);
			for(int i = 0;i <= 5 - result.GetLength();i++)
				result = "0" + result;
			result = "W" + result;
			sql = "insert into manaWare values('" + result + "','可用')";
			DB_excuteNoCall(db_ls,sql.GetBuffer(0));
			sql.ReleaseBuffer();
			Query();
			sql = "insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),\
				(select 员工编号 from Employees where 员工名称 = '"
				+ UserName + "'),'" + UserName + "','添加','添加仓库" + result +"')";
			DB_excuteNoCall(db_ls,sql.GetBuffer(0));
			sql.ReleaseBuffer();
			
		}
		else if(tbName == "dataOtherExpend")
		{
			CAddOtherOut otherOut;
			otherOut.UserName = UserName;
			otherOut.DoModal();
			Query();
		}
		else if(tbName == "dataOtherIncome")
		{
			CAddOtherIn otherIn;
			otherIn.UserName = UserName;
			otherIn.DoModal();
			Query();;
		}
		else if(tbName == "dataPayment")
		{
			CAddPay pay;
			pay.UserName = UserName;
			pay.DoModal();
			Query();
		}
		else if(tbName == "dataVoucher")
		{
			CAddRecv recv;
			recv.UserName = UserName;
			recv.DoModal();
			Query();
		}
		else if(tbName == "distriTrack")
		{
			CAddDistri distri;
			distri.UserName = UserName;
			distri.DoModal();
			Query();
		}
		else if(tbName == "distriReturn")
		{
			CAddDistriReturn distriReturn;
			distriReturn.UserName = UserName;
			distriReturn.DoModal();
			Query();
		}
		else if(tbName == "proTrack")
		{
			CAddOrder pro;
			pro.UserName = UserName;
			pro.DoModal();
			Query();
		}
		else if(tbName == "proReturn")
		{
			CAddProReturn proReturn;
			proReturn.UserName = UserName;
			proReturn.DoModal();
			Query();
		}
		else if(tbName == "wareChng")
		{
			CAddWareAdj wareAdj;
			wareAdj.UserName = UserName;
			wareAdj.DoModal();
			Query();
		}
		else if(tbName == "wareIn")
		{
			CWareIn wareIn;
			wareIn.UserName = UserName;
			wareIn.DoModal();
			Query();
		}
		else if(tbName == "wareOut")
		{
			CWareOut wareOut;
			wareOut.UserName = UserName;
			wareOut.DoModal();
			Query();
		}
	
		
	}
	else if(!strcmp(str,"禁用"))
	{
		char str[50];
		//	memset(str,0,sizeof(str)*50);
		LVCOLUMN lvcolumn;

		lvcolumn.mask = LVCF_TEXT;
		lvcolumn.pszText = str;
		lvcolumn.cchTextMax = 50;
			                       
		m_ls->GetColumn(0,&lvcolumn);
		int item = m_ls->GetSelectionMark();
		CString sql = "update " + tbName + " set 状态 = '不可用' where " +
			str + " = '" + m_ls->GetItemText(item,0) + "'";
		DB_excuteNoCall(db_ls,sql);
		sql = "insert into setLog values(strftime('%Y-%m-%d %H:%M:%f','now','localtime'),\
			(select 员工编号 from Employees where 员工名称 = '"+UserName+"'),'"+UserName+"','禁用','禁用"
			+ str+":" + m_ls->GetItemText(item,0) + "')";
		DB_excuteNoCall(db_ls,sql);
		Query();
	}
	else if(!strcmp(str,"导出"))
	{
		PutOut();
	}
	else if(!strcmp(str,"修改"))
	{
		CAddWareAdj wareAdj;
		wareAdj.UserName = UserName;
		wareAdj.DoModal();
		Query();
			
	}
	else if(!strcmp(str,"查询"))
	{
		Query();
	}

}


void CExternParent::OnRclickTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

}

void CExternParent::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

	iDialog.RemoveAll();
	
//	delete m_Child;

	count = -1;
	thisPos = -1;
	memset(iTemp,0,sizeof(int) * 6);
	memset(iCtrl,0,sizeof(int) * 6);
//	DB_close(db);
//	DB_close(db_ls);
	this->DestroyWindow();

//	CDialog::OnClose();
}

int CExternParent::GetDlgPos(int n)
{
 //map the iDialog,find where the param/n located 
	for(int i = 0;i < count + 1;i++)
	{
 		if(n == iDialog.GetAt(i))
 			return i;
	}
	return -1;
}

 

void CExternParent::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
/*这是多静态窗口，界面切换，如果是动态的话，直接给自己发窗口创建的消息，也就是说，所有窗口的创建都在dealMessage中处理*/
//	//when the selection changed,get the position of child dialog
//	//
////	int pos = m_Tab.GetCurSel();
////	pos = GetDlgPos(iDialog.GetAt(pos));
//	
////	pDialog[LastDialogPos]->ShowWindow(false);
////	pDialog[pos]->ShowWindow(true);
////	LastDialogPos = pos;
//
//	//while tab page change,set dialog except current selection ShowWindow(false)
//	//make sure current selection visible
//	int pos = m_Tab.GetCurSel(); //get tab page that is focus on
//	//then get the dialog which is create at this page
//	pos = iDialog.GetAt(pos);
//
//	for(int i = 0;i < 35;i++)
//	{
//		if(i == pos)
//		{
//			pDialog[i]->ShowWindow(true);
//		}
//		else if(pDialog[i] != NULL && pDialog[i]->IsWindowVisible())
//			pDialog[i]->ShowWindow(false);
//	}
//	

	Show(5);

	memset(iTemp,0,sizeof(int) * 6);
	int pos = m_Tab.GetCurSel();

	if(thisPos != pos) //如果点击同一个地方，或者要生成同一个窗口
	{
//		//如果是，就什么也不干
//
//	}
//	//如果不是
//	else
//	{	
//		pos = GetDlgPos(iDialog.GetAt(pos)); //pos 现在就是要显示窗口的ID
		pos = iDialog.GetAt(pos);
		thisPos = pos;

//		m_Child->DestroyWindow();
//		m_Child->Create(IDD_TABDLG,&m_Tab);
//		m_Child->MoveWindow(m_TabRc);
		
		char itemName[50];
		memset(itemName,0,50);
		TCITEM tcItem;
		tcItem.mask = TCIF_TEXT;
		tcItem.pszText = itemName;
		tcItem.cchTextMax = 50;
	
		
		m_Tab.GetItem(pos,&tcItem);
		PageName = tcItem.pszText;

		switch(pos)
		{
			case 0:  CreateProOrder(m_TabRc);break;
			case 1:  CreateProTrack(m_TabRc);break;
			case 2:  CreateProReturn(m_TabRc);break;
			//case 3:  CreateProIntel(m_TabRc);break;

			case 4:  CreateDistriLs(m_TabRc);break;
			case 5:  CreateDistriTrack(m_TabRc);break;
			case 6:  CreateDistriReturn(m_TabRc);break;

			case 7:  CreateWareIn(m_TabRc);break;
			case 8:  CreateWareOut(m_TabRc);break;
			case 9:  CreateWareStock(m_TabRc);break;
			case 10:  CreateWareChng(m_TabRc);break;

			case 11:  CreateManaCus(m_TabRc);break;
			case 12:  CreateManaSup(m_TabRc);break;
			case 13:  CreateManaEmployees(m_TabRc);break;
			case 14:  CreateManaGoods(m_TabRc);break;
			case 15:  CreateManaWare(m_TabRc);break;

			case 16:  CreateDataVoucher(m_TabRc);break;
			case 17:  CreateDataPayment(m_TabRc);break;
			case 18:  CreateDataReceivable(m_TabRc);break;
			case 19:  CreateDataPayable(m_TabRc);break;
			case 20:  CreateDataOtherIncome(m_TabRc);break;
			case 21:  CreateDataOtherExpend(m_TabRc);break;

			case 22:  CreateSetLog(m_TabRc);


		}
	}

}

void CExternParent::DealMessage(WPARAM wParam,LPARAM lParam)
{
	//get Tab control rect,and move child to fit it
	m_Tab.GetClientRect(m_TabRc);
	m_TabRc.top += 25;
	
	CString *str = (CString*)lParam;
	PageName = *str;
/*这里是多静态窗口的生成，根据之后的设计，需要动态调整窗口，也就是在一个窗口中移动控件，只需要取消注释一次就行*/
//	switch(wParam)
//	{
//case 0: 
////while the dialog didnt create,create it and move it,
////insert the name into tab page,set current selection
//	if(pDialog[wParam] == NULL)
//	{
//		pDialog[wParam] = new CProcurOrder();
//		pDialog[wParam]->Create(IDD_PROCUR_ORDER,&m_Tab);
//		pDialog[wParam]->MoveWindow(&m_TabRc);
//		m_Tab.InsertItem(++count,*str);
////
////save the dialog "ID",for search which page was it created
//		iDialog.Add(0);
//	
////if the tab control was the first time to show,the SelChange message will not respond
////so we just adjust the iDialog.GetData(1) is or isnt empty (== NULL)，if it is! show the window ---error
////correct in 2018-08-08:we saved the num of dialog which was created ,and the count is start at -1,
////when we create first ,count equals 0,so if count == 0,that the Tab is first time visible
//		if(count == 0) //that SelChange didnt respond this,so、、-x:just because the SetCurSel!
//			pDialog[wParam]->ShowWindow(true);
////the diffrent between SetCurSel and SetCurFocus is that
////SetCurSel just let the page up，SetCurSel just let the page change
////one more important thing is that it should set focus at end,because of we are deal the
////showWindow() at selchange
////xxx	m_Tab.SetCurSel(count);
////so ,set focus and deal with showwindow in SelChange message! 
//		m_Tab.SetCurFocus(count);
//		
//
//	}
////while the dialog was created ,that mean the customer was reclicked the same menu founction
////or  clicked , created another page, so we just set selection on this
//	else
//	{
////get the pos use dialog "ID" in iDialog
//		i = GetDlgPos(wParam);
//		m_Tab.SetCurSel(i); // then the m_tab may respond SelChange 
//	
////but the SelChang didnt respond,so we will show the dialog
//		pDialog[i]->ShowWindow(true);
//		m_Tab.SetCurFocus(i);
//	}
//	break;
//case 1: if(pDialog[wParam] == NULL){pDialog[wParam] = new CProcurQuery();pDialog[wParam]->Create(IDD_PROCUR_QUERY,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(1);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 2: if(pDialog[wParam] == NULL){pDialog[wParam] = new CProcurTrack();pDialog[wParam]->Create(IDD_PROCUR_TRACK,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(2);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 3: if(pDialog[wParam] == NULL){pDialog[wParam] = new CProcurReturn();pDialog[wParam]->Create(IDD_PROCUR_RETURN,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(3);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 4: if(pDialog[wParam] == NULL){pDialog[wParam] = new CProcurIntell();pDialog[wParam]->Create(IDD_PROCUR_INTELL,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(4);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 5: if(pDialog[wParam] == NULL){pDialog[wParam] = new CDistributList();pDialog[wParam]->Create(IDD_DISTRIBUT_LIST,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(5);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 6: if(pDialog[wParam] == NULL){pDialog[wParam] = new CDistributQuery();pDialog[wParam]->Create(IDD_DISTRIBUT_QUERY,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(6);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 7: if(pDialog[wParam] == NULL){pDialog[wParam] = new CDistributTrack();pDialog[wParam]->Create(IDD_DISTRIBUT_TRACK,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(7);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 8: if(pDialog[wParam] == NULL){pDialog[wParam] = new CWareHouseRequisition();pDialog[wParam]->Create(IDD_WAREHOUSE_REQUISITION,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(8);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 9: if(pDialog[wParam] == NULL){pDialog[wParam] = new CWareHouseIn();pDialog[wParam]->Create(IDD_WAREHOUSE_IN,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(9);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 10: if(pDialog[wParam] == NULL){pDialog[wParam] = new CWareHouseOut();pDialog[wParam]->Create(IDD_WAREHOUSE_OUT,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(10);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 11: if(pDialog[wParam] == NULL){pDialog[wParam] = new CWareHouseStock();pDialog[wParam]->Create(IDD_WAREHOUSE_STOCK,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(11);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 12: if(pDialog[wParam] == NULL){pDialog[wParam] = new CWareHouseChng();pDialog[wParam]->Create(IDD_WAREHOUSE_CHNG,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(12);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 13: if(pDialog[wParam] == NULL){pDialog[wParam] = new CWareHouseQuery();pDialog[wParam]->Create(IDD_WAREHOUSE_QUERY,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(13);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 14: if(pDialog[wParam] == NULL){pDialog[wParam] = new CManageCus();pDialog[wParam]->Create(IDD_MANAGE_CUS,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(14);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 15: if(pDialog[wParam] == NULL){pDialog[wParam] = new CManageSupply();pDialog[wParam]->Create(IDD_MANAGE_SUPPLY,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(15);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 16: if(pDialog[wParam] == NULL){pDialog[wParam] = new CManageGoods();pDialog[wParam]->Create(IDD_MANAGE_GOODS,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(16);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 17: if(pDialog[wParam] == NULL){pDialog[wParam] = new CManageWareHouse();pDialog[wParam]->Create(IDD_MANAGE_WAREHOUSE,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(17);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 18: if(pDialog[wParam] == NULL){pDialog[wParam] = new CManageAddress();pDialog[wParam]->Create(IDD_MANAGE_ADDRESS,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(18);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 19: if(pDialog[wParam] == NULL){pDialog[wParam] = new CDataVoucher();pDialog[wParam]->Create(IDD_DATA_VOUCHER,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(19);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 20: if(pDialog[wParam] == NULL){pDialog[wParam] = new CDataPayment();pDialog[wParam]->Create(IDD_DATA_PAYMENT,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(20);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 21: if(pDialog[wParam] == NULL){pDialog[wParam] = new CDataVerification();pDialog[wParam]->Create(IDD_DATA_VERIFICATION,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(21);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 22: if(pDialog[wParam] == NULL){pDialog[wParam] = new CDataOtherIncom();pDialog[wParam]->Create(IDD_DATA_OTHER_INCOM,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(22);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 23: if(pDialog[wParam] == NULL){pDialog[wParam] = new CDataOtherExpend();pDialog[wParam]->Create(IDD_DATA_OTHER_EXPEND,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(23);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 24: if(pDialog[wParam] == NULL){pDialog[wParam] = new CDataTransfer();pDialog[wParam]->Create(IDD_DATA_TRANSFER,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(24);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 25: if(pDialog[wParam] == NULL){pDialog[wParam] = new CAssertExpense();pDialog[wParam]->Create(IDD_ASSERT_EXPENSE,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(25);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 26: if(pDialog[wParam] == NULL){pDialog[wParam] = new CAssertPayable();pDialog[wParam]->Create(IDD_ASSERT_PAYABLE,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(26);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 27: if(pDialog[wParam] == NULL){pDialog[wParam] = new CAssertReceivable();pDialog[wParam]->Create(IDD_ASSERT_RECEIVABLE,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(27);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 28: if(pDialog[wParam] == NULL){pDialog[wParam] = new CAssertCusState();pDialog[wParam]->Create(IDD_ASSERT_CUS_STATE,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(28);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 29: if(pDialog[wParam] == NULL){pDialog[wParam] = new CAssertVendorState();pDialog[wParam]->Create(IDD_ASSERT_VENDOR_STATE,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(29);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 30: if(pDialog[wParam] == NULL){pDialog[wParam] = new CAssertOtherInOut();pDialog[wParam]->Create(IDD_ASSERT_OTHER_IN_AND_OUT,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(30);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 31: if(pDialog[wParam] == NULL){pDialog[wParam] = new CAssertIncomState();pDialog[wParam]->Create(IDD_ASSERT_INCOM_STATE,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(31);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 32: if(pDialog[wParam] == NULL){pDialog[wParam] = new CSetSysParam();pDialog[wParam]->Create(IDD_SET_SYS_PARAM,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(32);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 33: if(pDialog[wParam] == NULL){pDialog[wParam] = new CSetPermis();pDialog[wParam]->Create(IDD_SET_PERMIS,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);
//	m_Tab.InsertItem(++count,*str);iDialog.Add(33);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//case 34: if(pDialog[wParam] == NULL){pDialog[wParam] = new CSetLog();pDialog[wParam]->Create(IDD_SET_LOG,&m_Tab);pDialog[wParam]->MoveWindow(&m_TabRc);m_Tab.InsertItem(++count,*str);iDialog.Add(34);if(count == 0)pDialog[wParam]->ShowWindow(true);m_Tab.SetCurFocus(count);}else{i = GetDlgPos(wParam);m_Tab.SetCurFocus(i);};break;
//	}
//	str->Empty();
////create and show the child dialog if it is not created
////then add the ID into (CArray)iDialog
////	//finaly show the window and set current selection
////	if(pDialog[wParam]->m_hWnd == NULL)
////	{
////		pDialog[wParam]->Create(DialogID[wParam],&m_Tab);
////		pDialog[wParam]->MoveWindow(m_TabRc);
////		iDialog.Add(wParam);
////		m_Tab.InsertItem(++count,*str);
////		m_Tab.SetCurSel(count);
////		pDialog[wParam]->ShowWindow(true);
////
////	}
////if the child dialog is created
////get the num which page is create
////then just show it
////	else
////	{
////		i = GetDlgPos(wParam);
////		pDialog[LastDialogPos]->ShowWindow(false);
////		pDialog[i]->ShowWindow(true);
////		LastDialogPos = i;
////		m_Tab.SetCurSel(i);
////		pDialog[i]->ShowWindow(true);
////	}
////
/******************动态调整窗口******************/
//通过调用createxxxxx(),调整tabdlg窗口里面的控件.
//那么问题来了，我为什么不把控件生成在tab control里面？
//	int pos;
//	switch(wParam)
//	{
//	
//	case 0:  
//		//判断窗口是否第一次打开，count是否为-1
//		//如果是：SetFocus不会响应，要手动创建窗口并ShowWindow，且不用销毁上一个窗口，还要在iDialog中插入自己的ID
//		//也要在page中插入自己的string
//		if(count == -1) //dialog havent create
//		{
//			m_Child->Create(IDD_TABDLG,&m_Tab);
//			iDialog.Add(wParam);
//			CreateProOrder(m_TabRc);
//			m_Tab.InsertItem(++count,*str); //此时，count不为-1，在父窗口销毁前，都不会进入此语句
//			m_Child->MoveWindow(m_TabRc);
//			m_Child->ShowWindow(true);
//		}
//		
//		//如果不是：SetFocus会响应，在SelChange中销毁上一个窗口，显示当前窗口
//		else
//		{
//			//判断窗口字符串是插入进page，条件GetDlgPos（ID）返回-1
//			pos = GetDlgPos(wParam);
//			//如果没有插入，就插入字符串，iDialog中也要插入自己的ID，然后设置焦点到此,count++;
//			if(pos == -1)
//			{
//				m_Tab.InsertItem(++count,*str);
//				iDialog.Add(wParam);
//				m_Tab.SetCurFocus(count);
//			}
//			//如果已经插入，就将焦点设置到pos
//			else
//			{
//				m_Tab.SetCurFocus(pos);
//			}
//
//		}
//		thisPos = 0;break;
//case 1:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateProQuery(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =1;break;
//case 2:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateProTrack(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =2;break;
//case 3:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateProReturn(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =3;break;
//case 4:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateProIntel(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =4;break;
//
//case 5:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateDistriLs(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =5;break;
//case 6:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateDistriQuery(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =6;break;
//case 7:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateDistriTrack(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =7;break;
//
//case 8:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateWareRequis(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =8;break;
//case 9:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateWareIn(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =9;break;
//case 10:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateWareOut(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =10;break;
//case 11:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateWareStock(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =11;break;
//case 12:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateWareChng(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =12;break;
//case 13:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateWareQuery(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =13;break;
//
//case 14:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateManaCus(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =14;break;
//case 15:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateManaSup(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =15;break;
//case 16:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateManaGoods(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =16;break;
//case 17:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateManaWare(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =17;break;
//case 18:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateManaAddress(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =18;break;
//
//case 19:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateDataVoucher(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =19;break;
//case 20:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateDataPayment(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =20;break;
//case 21:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateDataVerification(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =21;break;
//case 22:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateDataOtherIncome(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =22;break;
//case 23:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateDataOtherExpend(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =23;break;
//case 24:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateDataTransfer(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =24;break;
//
//case 25:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateAssertIncome(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =25;break;
//case 26:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateAssertExpense(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =26;break;
//case 27:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateAssertPayable(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =27;break;
//case 28:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateAssertReceive(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =28;break;
//case 29:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateAssertCusState(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =29;break;
//case 30:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateAssertVendorState(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =30;break;
//case 31:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateAssertOtherInOut(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =31;break;
//case 32:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateAssertIncomeState(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =32;break;
//
//case 34:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateSetPermis(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =34;break;
//case 35:if(count == -1){m_Child->Create(IDD_TABDLG,&m_Tab);iDialog.Add(wParam);CreateSetLog(m_TabRc);m_Tab.InsertItem(++count,*str);m_Child->MoveWindow(m_TabRc);m_Child->ShowWindow(true);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =35;break;
//
//	}	
// create control in tabdlg !just do it!
	int pos;
//	CString str;
	
	switch(wParam)
	{
	
	case 0:  
		//判断窗口是否第一次打开，count是否为-1
		//如果是：SetFocus不会响应，要手动创建窗口并ShowWindow，且不用销毁上一个窗口，还要在iDialog中插入自己的ID
		//也要在page中插入自己的string
		if(count == -1) //dialog havent create
		{
			iDialog.Add(wParam);
			CreateProOrder(m_TabRc);
			m_Tab.InsertItem(++count,*str); //此时，count不为-1，在父窗口销毁前，都不会进入此语句
		//	MessageBox("1",MB_OK);
		}
		//如果不是：SetFocus会响应，在SelChange中销毁上一个窗口，显示当前窗口
		else
		{
			//判断窗口字符串是插入进page，条件GetDlgPos（ID）返回-1
			pos = GetDlgPos(wParam);
			//如果没有插入，就插入字符串，iDialog中也要插入自己的ID，然后设置焦点到此,count++;
			if(pos == -1)
			{
				m_Tab.InsertItem(++count,*str);
				iDialog.Add(wParam);
				m_Tab.SetCurFocus(count);
			//	MessageBox("2",MB_OK);
			}
			//如果已经插入，就将焦点设置到pos
			else
			{
				m_Tab.SetCurFocus(pos);
		//		MessageBox("3",MB_OK);
			}

		}
		thisPos = 0;break;
		case 1:if(count == -1){iDialog.Add(wParam);CreateProTrack(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =1;break;
		case 2:if(count == -1){iDialog.Add(wParam);CreateProReturn(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =2;break;
//		case 3:if(count == -1){iDialog.Add(wParam);CreateProIntel(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =3;break;

		case 4:if(count == -1){iDialog.Add(wParam);CreateDistriLs(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =4;break;
		case 5:if(count == -1){iDialog.Add(wParam);CreateDistriTrack(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =5;break;
		case 6:if(count == -1){iDialog.Add(wParam);CreateDistriReturn(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =6;break;

		case 7:if(count == -1){iDialog.Add(wParam);CreateWareIn(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =7;break;
		case 8:if(count == -1){iDialog.Add(wParam);CreateWareOut(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =8;break;
		case 9:if(count == -1){iDialog.Add(wParam);CreateWareStock(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =9;break;
		case 10:if(count == -1){iDialog.Add(wParam);CreateWareChng(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =10;break;

		case 11:if(count == -1){iDialog.Add(wParam);CreateManaCus(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =11;break;
		case 12:if(count == -1){iDialog.Add(wParam);CreateManaSup(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =12;break;
		case 13:if(count == -1){iDialog.Add(wParam);CreateManaEmployees(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =13;break;
		case 14:if(count == -1){iDialog.Add(wParam);CreateManaGoods(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =14;break;
		case 15:if(count == -1){iDialog.Add(wParam);CreateManaWare(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =15;break;

		case 16:if(count == -1){iDialog.Add(wParam);CreateDataVoucher(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =16;break;
		case 17:if(count == -1){iDialog.Add(wParam);CreateDataPayment(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =17;break;
		case 18:if(count == -1){iDialog.Add(wParam);CreateDataReceivable(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =18;break;
		case 19:if(count == -1){iDialog.Add(wParam);CreateDataPayable(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =19;break;
		case 20:if(count == -1){iDialog.Add(wParam);CreateDataOtherIncome(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =20;break;
		case 21:if(count == -1){iDialog.Add(wParam);CreateDataOtherExpend(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =21;break;

		case 22:if(count == -1){iDialog.Add(wParam);CreateSetLog(m_TabRc);m_Tab.InsertItem(++count,*str);}else{pos = GetDlgPos(wParam);if(pos == -1){m_Tab.InsertItem(++count,*str);iDialog.Add(wParam);m_Tab.SetCurFocus(count);}else{m_Tab.SetCurFocus(pos);}}thisPos =22;break;
	}
}


int InsertComboBox(void*data,int argc,char** argv,char**column)
{
	CExternParent* dlg = (CExternParent*)data;
	dlg->m_cb[dlg->opt].InsertString(dlg->m_cb[dlg->opt].GetCount(),U2G(argv[0]));

	return false;
}
void CExternParent::CreateDataOtherExpend(CRect rc)
{

	DB_select(db,CreateCtrl,this,"dataOtherExpend");
	DB_selectTitle(db_ls,CompetLs,m_ls,"dataOtherExpend");
	tbName = "dataOtherExpend";
}

void CExternParent::CreateDataOtherIncome(CRect rc)
{

	DB_select(db,CreateCtrl,this,"dataOtherIncome");
	DB_selectTitle(db_ls,CompetLs,m_ls,"dataOtherIncome");
	tbName = "dataOtherIncome";

}

void CExternParent::CreateDataPayment(CRect rc)
{

	DB_select(db,CreateCtrl,this,"dataPayment");
	DB_selectTitle(db_ls,CompetLs,m_ls,"dataPayment");
	tbName = "dataPayment";

	char sql[] = "select 供应商编号 from manaSup where 状态 != '不可用'";
	opt = 0;
	DB_excute(db_ls,sql,InsertComboBox,this);
}

void CExternParent::CreateDataVoucher(CRect rc)
{

	DB_select(db,CreateCtrl,this,"dataVoucher");
	DB_selectTitle(db_ls,CompetLs,m_ls,"dataVoucher");
	tbName = "dataVoucher";
	
	char sql[] = "select 客户编号 from manaCus where 状态 != '不可用'";
	opt = 0;
	DB_excute(db_ls,sql,InsertComboBox,this);

}

void CExternParent::CreateDistriLs(CRect rc)
{

	DB_select(db,CreateCtrl,this,"distriLs");
	DB_selectTitle(db_ls,CompetLs,m_ls,"distriLs");
	tbName = "distriTrack";
	opt = 0;
	char sql[] = "select 商品编号 from inventory where 状态 != '不可用'";
	DB_excute(db_ls,sql,InsertComboBox,this);

}


void CExternParent::CreateDistriTrack(CRect rc)
{

	DB_select(db,CreateCtrl,this,"distriTrack");
	DB_selectTitle(db_ls,CompetLs,m_ls,"distriTrack");
	tbName = "distriTrack";
	opt = 0;
	char sql[] = "select 客户编号 from manaCus where 状态 != '不可用'";
	DB_excute(db_ls,sql,InsertComboBox,this);

}

void CExternParent::CreateManaAddress(CRect rc)
{

	DB_select(db,CreateCtrl,this,"manaAddress");
	DB_selectTitle(db_ls,CompetLs,m_ls,"manaAddress");
	tbName = "manaAddress";


}

void CExternParent::CreateManaCus(CRect rc)
{

	DB_select(db,CreateCtrl,this,"manaCus");
	DB_selectTitle(db_ls,CompetLs,m_ls,"manaCus");
	tbName = "manaCus";
	Query();


}

void CExternParent::CreateManaSup(CRect rc)
{

	DB_select(db,CreateCtrl,this,"manaSup");
	DB_selectTitle(db_ls,CompetLs,m_ls,"manaSup");
	tbName = "manaSup";
	Query();

}

void CExternParent::CreateManaGoods(CRect rc)
{

	DB_select(db,CreateCtrl,this,"manaGoods");
	DB_selectTitle(db_ls,CompetLs,m_ls,"manaGoods");
	tbName = "inventory";
	Query();

}

void CExternParent::CreateManaWare(CRect rc)
{

	DB_select(db,CreateCtrl,this,"manaWare");
	DB_selectTitle(db_ls,CompetLs,m_ls,"manaWare");
	tbName = "manaWare";
	Query();
}

void CExternParent::CreateProOrder(CRect rc)
{

	//这里要传入this指针，确保是对该窗口操作，虽然回调函数中强制转换了一个对象
	//但是传入的却是NULL，强制转换后也只能作为一个局部变量，然后里面对这个局部变量进行操作
	//而不是该窗口。
	DB_select(db,CreateCtrl,this,"proOrder");
	DB_selectTitle(db_ls,CompetLs,m_ls,"proOrder");
	tbName = "proTrack";
	
	opt = 0;
	char sql[] = "select 商品编号 from inventory where 状态 != '不可用'";
	DB_excute(db_ls,sql,InsertComboBox,this);
}


void CExternParent::CreateProReturn(CRect rc)
{

	DB_select(db,CreateCtrl,this,"proReturn");
	DB_selectTitle(db_ls,CompetLs,m_ls,"proReturn");
	tbName = "proReturn";
	opt = 0;
	char sql[] = "select 供应商编号 from manaSup where 状态 != '不可用'";
	DB_excute(db_ls,sql,InsertComboBox,this);

}

void CExternParent::CreateProTrack(CRect rc)
{

	DB_select(db,CreateCtrl,this,"proTrack");
	DB_selectTitle(db_ls,CompetLs,m_ls,"proTrack");
	tbName = "proTrack";
	char sql[] = "select 供应商编号 from manaSup where 状态 != '不可用'";
	opt = 0;
	DB_excute(db_ls,sql,InsertComboBox,this);

}
void CExternParent::CreateWareChng(CRect rc)
{

	DB_select(db,CreateCtrl,this,"wareChng");
	DB_selectTitle(db_ls,CompetLs,m_ls,"wareChng");
	tbName = "wareChng";

	char sql[] = "select 仓库编号 from manaWare where 状态 != '不可用'";
	opt = 0;
	DB_excute(db_ls,sql,InsertComboBox,this);

	strcpy(sql, "select 商品名称 from inventory where 状态 != '不可用'");
	opt = 1;
	DB_excute(db_ls,sql,InsertComboBox,this);

}

void CExternParent::CreateWareIn(CRect rc)
{

	DB_select(db,CreateCtrl,this,"wareIn");
	DB_selectTitle(db_ls,CompetLs,m_ls,"wareIn");
	tbName = "wareIn";

	char sql[] = "select 仓库编号 from manaWare where 状态 != '不可用'";
	opt = 0;
	DB_excute(db_ls,sql,InsertComboBox,this);

}

void CExternParent::CreateWareOut(CRect rc)
{

	DB_select(db,CreateCtrl,this,"wareOut");
	DB_selectTitle(db_ls,CompetLs,m_ls,"wareOut");
	tbName = "wareOut";

	char sql[] = "select 仓库编号 from manaWare where 状态 != '不可用'";
	opt = 0;
	DB_excute(db_ls,sql,InsertComboBox,this);

}

void CExternParent::CreateWareStock(CRect rc)
{

	DB_select(db,CreateCtrl,this,"wareStock");
	DB_selectTitle(db_ls,CompetLs,m_ls,"wareStock");
	tbName = "inventory";

	char sql[] = "select 仓库编号 from manaWare where 状态 != '不可用'";
	opt = 0;
	DB_excute(db_ls,sql,InsertComboBox,this);

	strcpy(sql, "select 商品名称 from inventory where 状态 != '不可用'");
	opt = 1;
	DB_excute(db_ls,sql,InsertComboBox,this);

}

void CExternParent::CreateSetPermis(CRect rc)
{

	DB_select(db,CreateCtrl,this,"setPermis");
	DB_selectTitle(db_ls,CompetLs,m_ls,"setPermis");

}

void CExternParent::CreateSetLog(CRect rc)
{

	DB_select(db,CreateCtrl,this,"setLog");
	DB_selectTitle(db_ls,CompetLs,m_ls,"setLog");
	tbName = "setLog";
	char sql[] = "select 员工名称 from Employees where 状态 != '不可用'";
	opt = 0;
	DB_excute(db_ls,sql,InsertComboBox,this);
	m_cb[1].InsertString(0,"新增");
	m_cb[1].InsertString(1,"修改");
	m_cb[1].InsertString(2,"添加");
	m_cb[1].InsertString(3,"调整");
	m_cb[1].InsertString(4,"禁用");

}

void CExternParent::MoveWnd(CWnd *wd, int l, int t)
{
	CRect rc;
	wd->GetClientRect(rc);
	rc.left = l;
	rc.top = t;
	rc.right = l + rc.Width();
	rc.bottom = t + rc.Height();
	wd->MoveWindow(rc);
}

//	 0		1		2		3	  4		5
//	edit->combo->button->text->time->list
//#define ed		0
//#define cb		1
//#define bt		2
//#define tx		3
//#define tm		4
//#define ls		5
//					//储存当前控件的数量，如果小于之前的控件数量就调用ShowWindow，如果大于就create
//	iTemp[6];		//如果对应iCtrl的值小于iTemp就调用create，反之调用GetDlgItem(ID)->ShowWindow(true)
//					//在切换窗口时，要重置，炸窗口关闭时重置清空
//	
//					//储存当前每个控件的数量，方便ID管理。在运行中创建控件，窗口切换中在后台显示，需要时调用
//	iCtrl[6];		//如果对应iTemp的值小于iCtrl就调用GetDlgItem(ID)->ShowWindow(true)，反之调用Create
//					//在切换窗口时，不重置，在窗口关闭时重置清空
//
//					//储存每个窗口所有控件的ID，方便之后管理
//	uCtrl;			//每次ShowWindow或者Create时，将该ID储存起来
//					//在切换窗口时，遍历uCtrl获取控件ID，然后调用GetDlgItem(ID)->ShowWindow(false),然后重置清空
//
void CExternParent::CreateBt(CString strText, CRect rc)
{
	rc = MoveRect(rc,10,30,0,30);
//	if(iTemp[bt] >= iCtrl[bt])
//	{
//		MessageBox("cBt",strText,MB_OK);
		m_bt[iTemp[bt]].Create(strText,dwBtStyle,rc,this,btID+iTemp[bt]);
//		iCtrl[bt]++;
//	}
//	uCtrl.Add(btID+iTemp[bt]);
//	else
//	{
//		MessageBox("sBt",strText,MB_OK);
//		m_bt[iTemp[bt]].MoveWindow(rc);
//		m_bt[iTemp[bt]].SetWindowText(strText);
//	}
	m_bt[iTemp[bt]].ShowWindow(true);
	m_bt[iTemp[bt]].SetFont(m_font);
	iTemp[bt]++;

}

void CExternParent::CreateEd(CString strText, CRect rc)
{
	rc = MoveRect(rc,3,30,0,30);
//	if(iTemp[ed] >= iCtrl[ed])
//	{
//		MessageBox("cEd",strText,MB_OK);
		m_ed[iTemp[ed]].Create(dwEdStyle,rc,this,edID+iTemp[ed]);
//		iCtrl[ed]++;
//	}
//	uCtrl.Add(edID+iTemp[ed]);
	m_ed[iTemp[ed]].ShowWindow(true);
	m_ed[iTemp[ed]].SetFont(m_font);

	iTemp[ed]++;
}

void CExternParent::CreateLs(CString strText, CRect rc)
{
	rc = MoveRect(rc,5,30,-5,30);


//	if(iTemp[ls] >= iCtrl[ls])
//	{
//		MessageBox("cLs",strText,MB_OK);
		m_ls[iTemp[ls]].Create(dwLsStyle,rc,this,lsID+iTemp[ls]);
//		iCtrl[ls]++;
//	}
//	uCtrl.Add(lsID+iTemp[ls]);
	m_ls[iTemp[ls]].SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_ls[iTemp[ls]].ShowWindow(true);
	m_ls[iTemp[ls]].SetFont(m_font);
	CImageList imagelist;
	imagelist.Create(1,24, ILC_COLOR, 1, 1); 
	m_ls[iTemp[ls]].SetImageList(&imagelist, LVSIL_SMALL);
//	m_ls[iTemp[ls]].SetImageList(&imageLs,LVSIL_SMALL);
	iTemp[ls]++;
}

void CExternParent::CreateCb(CString strText, CRect rc)
{
	rc = MoveRect(rc,0,30,0,30);
//	rc.bottom += 100;
//	if(iTemp[cb] >= iCtrl[cb])
//	{
//		MessageBox("cCb",strText,MB_OK);
		m_cb[iTemp[cb]].Create(dwCbStyle,rc,this,cbID+iTemp[cb]);
//		iCtrl[cb]++;
//	}
//	uCtrl.Add(cbID+iTemp[cb]);
	m_cb[iTemp[cb]].ShowWindow(true);
//	m_cb[iTemp[cb]]
//  m_cb[iTemp[cb]].SetFont(&m_font);
//	m_tx[iTemp[tx] - 1].GetWindowText(strCb[iTemp[cb]]);
//	MessageBox(strCb[iTemp[cb]],0);
	iTemp[cb]++;
}

void CExternParent::CreateTm(CString strText, CRect rc)
{
	rc = MoveRect(rc,0,30,0,30);
//	if(iTemp[tm] >= iCtrl[tm])
//	{
//		MessageBox("cTm",strText,MB_OK);
		m_tm[iTemp[tm]].Create(dwTmStyle,rc,&m_Tab,tmID+iTemp[tm]);
	m_tm[iTemp[tm]].SetFormat("yyyy-MM-dd");
//		iCtrl[tm]++;
//	}
//	uCtrl.Add(tmID+iTemp[tm]);
	m_tm[iTemp[tm]].ShowWindow(true);
//	m_tm[iTemp[tm]].SetFont(&m_font);

	iTemp[tm]++;
}

void CExternParent::CreateTx(CString strText, CRect rc)
{
	rc = MoveRect(rc,0,30,0,30);
//	if(iTemp[tx] >= iCtrl[tx])
//	{
//		MessageBox("cTx",strText,MB_OK);
		m_tx[iTemp[tx]].Create(strText,dwTxStyle,rc,&m_Tab,txID+iTemp[tx]);
		if(strText == "单据日期")
		{
			if(m_tm[1].m_hWnd != 0 && m_tm[0].m_hWnd != 0)
			{
				CString str;
				CTime time;
				m_tm[0].GetTime(time);
				str = time.Format("%y/%m/%d");
				m_tm[1].GetTime(time);
				str = str + "至" + time.Format("%y/%m/%d");
				m_tx[iTemp[tx]].SetWindowText(str);
				str.Empty();
				
			}
		}
//		iCtrl[tx]++;
//	}
//	uCtrl.Add(txID+iTemp[tx]);
//	else
//	{
//		MessageBox("sTx",strText,MB_OK);
//		m_tx[iTemp[tx]].MoveWindow(rc);
//		m_tx[iTemp[tx]].SetWindowText(strText);
//	}
	m_tx[iTemp[tx]].SetFont(m_font,false);
	m_tx[iTemp[tx]].ShowWindow(true);

	iTemp[tx]++;
}
//由于sqlite的判定机制（SQLITE_OK = false = 0）,所以最后要返回false/0
int CreateCtrl(void *data, int argc, char **argv, char **azColName)
{
	//数据库中存放的数据title -》ID ，ctrName,ctrlText,l,t,r,b;
//在一个数组中存放窗口位置，一个CString储存控件文本，然后判断该控件类型，然后create
	CExternParent *m_this = (CExternParent*) data;
	int pos[4];
//	CString strName,strText;
//	bool	isWindowCreate = true;
//	DWORD	WndStyle;
//	UINT	ID;
//	int		WndType;
//	m_this = new CExternParent;
	
	for(int i = 3;i < argc;i++)
	{
		pos[i-3] = atoi(argv[i]);
	}
	CRect rCtrl(pos[0],pos[1],pos[2],pos[3]);
//	ScreenToClient(&rCtrl);
//	strName = argv[2];
//
//					//储存当前控件的数量，如果小于之前的控件数量就调用ShowWindow，如果大于就create
//	iTemp[6];		//如果对应iCtrl的值小于iTemp就调用create，反之调用GetDlgItem(ID)->ShowWindow(true)
//					//在切换窗口时，要重置，炸窗口关闭时重置清空
//	
//					//储存当前每个控件的数量，方便ID管理。在运行中创建控件，窗口切换中在后台显示，需要时调用
//	iCtrl[6];		//如果对应iTemp的值小于iCtrl就调用GetDlgItem(ID)->ShowWindow(true)，反之调用Create
//					//在切换窗口时，不重置，在窗口关闭时重置清空
//
//					//储存每个窗口所有控件的ID，方便之后管理
//	uCtrl;			//每次ShowWindow或者Create时，将该ID储存起来
//					//在切换窗口时，遍历uCtrl获取控件ID，然后调用GetDlgItem(ID)->ShowWindow(false),然后重置清空
//
//	 0		1		2		3	  4		5
//	edit->combo->button->text->time->list
//#define ed		0
//#define cb		1
//#define bt		2
//#define tx		3
//#define tm		4
//#define ls		5
//if control is created and find the ctrl number in 
	argv[1] = U2G(argv[1]);
	argv[2] = U2G(argv[2]);

	if(strcmp(argv[1],"edit") == 0)
	{
	//	::MessageBox(0,"a",NULL,MB_OK);
		m_this->CreateEd(argv[2],rCtrl);
//		strText = "CEdit";
//		WndType = ed;
//		ID = IDS_ED + iTemp[ed]++;
	}
	else
		if(strcmp(argv[1],"combo") == 0)
		{
			m_this->CreateCb(argv[2],rCtrl);
//			strText = "CComboBox";
//			WndType = cb;
//			ID = IDS_CB + iTemp[cb]++;
		}
	else
		if(strcmp(argv[1],"bt") == 0)
		{
			m_this->CreateBt(argv[2],rCtrl);
//			strText = "CButton";
//			WndType = bt;
//			ID = IDS_CB + iTemp[bt]++;
		}
	else
		if(strcmp(argv[1],"text") == 0)
		{
			m_this->CreateTx(argv[2],rCtrl);
//			strText = "CStatic";
//			WndType = tx;
//			ID = IDS_CB + iTemp[tx]++;
		}
	else
		if(strcmp(argv[1],"time") == 0)
		{
			m_this->CreateTm(argv[2],rCtrl);
//			strText = "CDateTimeCtrl";
//			WndType = tm;
//			ID = IDS_CB + iTemp[tm]++;
		}
	else
		if(strcmp(argv[1],"ls") == 0)
		{
			m_this->CreateLs(argv[2],rCtrl);
//			strText = "CListCtrl";
//			WndType = ls;
//			ID = IDS_CB + iTemp[ls]++;
		}

//	if(iTemp[0] > iCtrl[0])
//	{
//		isWindowCreate = true;
//		iCtrl[WndType] = iTemp[WndType];
//	}
//	else
//		isWindowCreate = false;
//
//	uCtrl.Add(ID);
//
//	if(isWindowCreate)
//		CWnd::Create(strName,strText,WndStyle,rCtrl,&m_Tab,ID);
//	else
//	{
//		GetDlgItem(ID)->ShowWindow(true);
//		GetDlgItem(ID)->MoveWindow(&rCtrl);
//	}

//	strName.Empty();
//	strText.Empty();

	return false;
}

int CompetLs(void *data,int argc,char **argv,char **colum)
{
	CListCtrl *p = (CListCtrl*) data;
	argv[1] = U2G(argv[1]);
//	::MessageBox(0,U2G(argv[0]),0,0);
	int i = p->GetHeaderCtrl()->GetItemCount();
	if(strcmp(argv[1],"ID"))
		p->InsertColumn(i,argv[1],LVCFMT_CENTER,130,0);
	else if(g_lsEdit)
		p->InsertColumn(0,"",LVCFMT_LEFT,50,0);
	return false;
}
CRect CExternParent::MoveRect(CRect rc, int l, int t, int r, int b)
{
	rc.left += l;
	rc.right += r;
	rc.bottom += b;
	rc.top += t;
	return rc;
}

//	 0		1		2		3	  4		5
//	edit->combo->button->text->time->list

int CExternParent::Show(int i)
{
	int sta = 0;
	switch(i)
	{
	case 0:
		while(m_ed[sta].m_hWnd != 0)
		{
//			MessageBox("0",MB_OK);
//			m_ed[sta].ShowWindow(false);
			m_ed[sta].DestroyWindow();
			m_ed[sta].m_hWnd = NULL;
			sta++;
		}
		break;
	case 1:
		while(m_cb[sta].m_hWnd != 0)
		{
	//		MessageBox("1",MB_OK);
	//		m_cb[sta].ShowWindow(false);
//			strCb[sta] = "";
			m_cb[sta].DestroyWindow();
			m_cb[sta].m_hWnd = 0;
			sta++;
		}
		return Show(i-1);
		break;
	case 2:
		while(m_bt[sta].m_hWnd != 0)
		{
//			MessageBox("2",MB_OK);
//			m_bt[sta].ShowWindow(false);
			m_bt[sta].DestroyWindow();
			m_bt[sta].m_hWnd = 0;
			sta++;
		}
		return Show(i-1);
		break;
	case 3:
		while(m_tx[sta].m_hWnd != 0)
		{
//			MessageBox("3",MB_OK);
//			m_tx[sta].ShowWindow(false);
			m_tx[sta].DestroyWindow();
			m_tx[sta].m_hWnd = 0;
			sta++;
		}
		return Show(i-1);
		break;
	case 4:
		while(m_tm[sta].m_hWnd != 0)
		{
//			MessageBox("4",MB_OK);
//			m_tm[sta].ShowWindow(false);
			m_tm[sta].DestroyWindow();
			m_tm[sta].m_hWnd = 0;
			sta++;
		}
		return Show(i-1);
		break;
	case 5:
		while(m_ls[sta].m_hWnd != 0)
		{
//			MessageBox("5",MB_OK);
//			m_ls[sta].ShowWindow(false);
			m_ls[sta].DestroyWindow();
			m_ls[sta].m_hWnd = 0;
			sta++;
		}
		return Show(i-1);
		break;
	}
	return true;

}

HBRUSH CExternParent::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here

//
//	pDC->SelectObject(m_font);
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CExternParent::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
	{
		OnClose();
	}
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
		return true;
	return CDialog::PreTranslateMessage(pMsg);
}

void CExternParent::CopyLsData(CListCtrl *dest,CListCtrl *src)
{
	
	char str[50];
//	memset(str,0,sizeof(str)*50);
	LVCOLUMN lvcolumn;

	lvcolumn.mask = LVCF_TEXT;
	lvcolumn.pszText = str;
	lvcolumn.cchTextMax = 50;
	isDate = 0;
	int num = src->GetHeaderCtrl()->GetItemCount();
	for(int i = 0;i < num;i++)
	{
		src->GetColumn(i,&lvcolumn);
		if(strcmp(str,"单据日期") == 0)
		{
			isDate = 1;
		}
		else
			dest->InsertColumn(i - isDate,str,LVCFMT_CENTER,strlen(str)*12,0);
	}
}

CString CExternParent::GetLsHeadText(int i,CListCtrl *src)
{
	char str[50];
	LVCOLUMN lvcolumn = {0};

	lvcolumn.mask = LVCF_TEXT|LVCF_WIDTH;
	lvcolumn.pszText = str;
	lvcolumn.cchTextMax = 50;
	src->GetColumn(i,&lvcolumn);
//	MessageBox(str,0);
	return str;
}
//
//typedef struct PRINTINFO{
//	HDC			hDC;
//	CListCtrl  *pList;
//	int			iWidth;
//	int			iHeight;
//	int			iItem;
//	int			iColumn;
//}PRINTINFO,*pPRINTINFO;

//DWORD CALLBACK PrintLs(LPVOID lpParam)
//{
//
//	return 0L;
//}

//DEL void CExternParent::PrintList()
//DEL {
//DEL 	CPrintDialog m_print(false);
//DEL 	if(m_print.DoModal() == IDOK)
//DEL 	{
//DEL 		int Copies  = m_print.GetCopies();   //获取需要打印多少份
//DEL 		HDC hDC	    = m_print.GetPrinterDC();
//DEL 		
//DEL 	//	CFont *font = m_ls->GetFont();
//DEL 	//	SelectObject(hDC,&font);
//DEL 		
//DEL 
//DEL 		int PixX   = GetDeviceCaps(hDC,LOGPIXELSX);
//DEL 		int PixY   = GetDeviceCaps(hDC,LOGPIXELSY);
//DEL //默认A4纸，纵向，210 x 297,x - 10; y - 17;实际宽度  200 x 280;
//DEL 
//DEL 		//		字号 	毫米 
//DEL 		//		七号 	1.84
//DEL 		//		小六号 	2.46
//DEL 		//		六号 	2.8
//DEL 		//		小五号 	3.15
//DEL 		//		五号 	3.67
//DEL 		//		小四号 	4.2
//DEL 		//		四号 	4.81
//DEL 		//		三号 	5.62
//DEL 		//		小二号 	6.36
//DEL 		//		二号 	7.35
//DEL 		//		小一号 	8.5
//DEL 		//		一号 	9.63
//DEL 		//		小初号 	12.6
//DEL 		//		初号 	14.7
//DEL 
//DEL 		
//DEL 		int XScale = PixX * 10 / 254 * 4;
//DEL 		int YScale = PixY * 10 / 254 * 4;
//DEL 
//DEL //		LPDEVMODE	pDevmode = m_print.GetDevMode();
//DEL 		
//DEL 		int item   = m_ls->GetItemCount();
//DEL 		int column = m_ls->GetHeaderCtrl()->GetItemCount();
//DEL 			
//DEL //		PRINTINFO pInfo;
//DEL //		pInfo.hDC		= hDC;
//DEL //		pInfo.iItem		= item;
//DEL //		pInfo.iColumn	= column;
//DEL //		pInfo.iWidth	= PageX;
//DEL //		pInfo.iHeight	= PageY;
//DEL //		pInfo.pList		= m_ls;
//DEL 
//DEL //		HANDLE	hThread = CreateThread( 0,0,PrintLs,&pInfo,0,0);
//DEL //		CloseHandle(hThread);
//DEL 		DOCINFO   doc;
//DEL 
//DEL 		memset(&doc,0,sizeof(doc));
//DEL 		doc.cbSize = sizeof(doc);
//DEL 		doc.lpszDocName = "CDC::StartDoc";
//DEL 
//DEL //		pPRINTINFO	pInfo = (pPRINTINFO)	lpParam;
//DEL 		CDC *pDC = NULL;
//DEL 		pDC->Attach(hDC);
//DEL 		CFont *font;
//DEL 		font->CreateFont(
//DEL 			 160,				    	//height
//DEL 			 80,							//wiidth
//DEL 			 0,
//DEL 			 0,							
//DEL 			 FW_NORMAL,					 // nWeight    
//DEL 			 FALSE,                      // bItalic    斜体？
//DEL 			 FALSE,                     // bUnderline    
//DEL 			 0,                         // cStrikeOut    
//DEL 			 ANSI_CHARSET,              // nCharSet    
//DEL 			 OUT_DEFAULT_PRECIS,        // nOutPrecision    
//DEL 			 CLIP_DEFAULT_PRECIS,       // nClipPrecision    
//DEL 			 DEFAULT_QUALITY,           // nQuality    
//DEL 			 DEFAULT_PITCH,				// nPitchAndFamily    
//DEL 			 "宋体"); 
//DEL 		pDC->SelectObject(font);
//DEL 
//DEL 		if(pDC->StartDoc(&doc) < 0)
//DEL 		{
//DEL 			MessageBox("打印机出现错误","err",MB_ICONHAND);
//DEL 			return;
//DEL 		}
//DEL 		else
//DEL 		{
//DEL 			//画表格，就像在view视图中那样画
//DEL 			
//DEL 			pDC->TextOut(1 * XScale,1 * YScale,"小蘑菇供应商库存管理系统",strlen("小蘑菇供应商库存管理系统"));
//DEL //			TextOut(hDC,1 * XScale,1 * YScale,"小蘑菇供应商库存管理系统",strlen("小蘑菇供应商库存管理系统"));
//DEL //			TextOut(hDC,30 * XScale,5 * YScale,PageName,PageName.GetLength());
//DEL //	
//DEL 
//DEL //			m_Tab.GetWindowText(str);
//DEL //			TextOut(hDC,PageX,100,str,str.GetLength());
//DEL 		}
//DEL 		
//DEL 		EndPage(hDC);
//DEL 		EndDoc(hDC);
//DEL 
//DEL 	}
//DEL 		
//DEL }



void CExternParent::PutOut()
{
	//http://www.cnblogs.com/wlsandwho/p/4512840.html
	//内嵌Excel in single document interface
/*	_Application app;  //Excel应用程序接口

    _Workbook book;
    Workbooks books;

	_Worksheet sheet;
    Worksheets sheets;

    Range range;
 	Font font;
 	Range cols;
//    CString tem,stri,strA,strB;

//	CoInitialize(NULL);
    COleVariant covOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR);
    if (!app.CreateDispatch(_T("Excel.Application")))
    {
           this->MessageBox(_T("无法创建Excel应用！"));
           return;
    }

    books = app.GetWorkbooks();    //获取工作薄集合
    book = books.Add(covOptional);  //添加一个工作薄

    sheets = book.GetWorksheets();    //获取工作表集合
    sheet = sheets.GetItem(COleVariant((short)1));        //获取第一个工作表

/////////////////////////第一列/////////////////////////////////////////////////

    //设置列名

//    range = sheet.GetRange(COleVariant(_T("A1")),  COleVariant(_T("A1")));    //选择工作表中A1:A1单元格区域
//
////    range.SetValue2(COleVariant(_T("序号")));   //A1:A1中填入“序号”
//
//           //设置字体为粗体
//
//    font = range.GetFont();
//
//    font.SetBold(COleVariant((short)TRUE));

    //写入数据

  //  arr1.RemoveAll();    //清空数组（用数组存该列的所有数据）

 //   int line=m_ls.GetItemCount();    //查询clistctrl控件中记录数

  //  CString str_line;

  //  str_line.Format("%d",line+1);   

//    for(int i=0;i < m_ls.GetItemCount();i++)
//
//    {
//
//        tem=m_ls.GetItemText(i,0);
//		arr1.Add(tem); 
//
//    }

//    for(i=1;i<=line;i++)          //循环将数组的内容写到Excel中
//    {
//           stri.Format("%d",i+1);
//           strA="A"+stri;
//           strB="A"+str_line; 
//           range = sheet.GetRange(COleVariant(_T(strA)),  COleVariant(_T(strB)));        //确定表的范围
//           range.SetValue2(COleVariant(_T(arr1[i-1])));
//    }

     //选择整列，并设置宽度为自适应

	int item = m_ls->GetItemCount();
	int column = m_ls->GetHeaderCtrl()->GetItemCount();
	CString str;
	
	//		  A       B        C       D       E       F       G
	// 1	************************XXXX表*************************   //暂时不能实现，merge报错
	// 2	title1   title2  title3  title4  title5  title6  title7
	// 3	  x			x		x		x		x		x		x

//	str.Format("%c1",'A'+column - 1); //column = 6
	range = sheet.GetRange(COleVariant("A1"),COleVariant("A6")); 
 	range.Merge(COleVariant((short)1));//SetMergeCells
//	
//	range.SetValue2(COleVariant(PageName));
//
//	font = range.GetFont();
//	font.SetBold(COleVariant((short)TRUE));
//	font.SetSize(COleVariant((short)15));

	char strHead[50];
//	memset(str,0,sizeof(str)*50);
	LVCOLUMN lvcolumn;
	lvcolumn.mask = LVCF_TEXT;
	lvcolumn.pszText = strHead;
	lvcolumn.cchTextMax = 50;


	for(int i = 0;i < column;i++)
	{
		m_ls->GetColumn(i,&lvcolumn);
		if(i == 0)
			range = sheet.GetRange(COleVariant("A1"),COleVariant("A1"));
		else 
			range = range.GetNext();
		
		range.SetValue2(COleVariant(strHead));
	}
	for(int iIndex = 0;iIndex < item; iIndex++)
	{
		str.Format("A%d",iIndex+2);
		range = sheet.GetRange(COleVariant(str),COleVariant(str));
		range.SetValue2(COleVariant(m_ls->GetItemText(iIndex,0)));
	
		for(int jIndex = 1;jIndex < column;jIndex++)
		{
			range = range.GetNext();
			range.SetValue2(COleVariant(m_ls->GetItemText(iIndex,jIndex)));
		}
	}

    cols = range.GetEntireColumn();
    cols.AutoFit();
	
//后面几列处理方法相同，省略。

    app.SetVisible(TRUE);  //显示表格
	app.SetUserControl(TRUE);
*/

}
int FillLs(void* data,int argv,char **argc,char **azCol)
{
	CExternParent *cls = (CExternParent*) data;
	if(cls->opt == InsertLs)
	{
		int item = cls->m_ls->GetItemCount();
		cls->m_ls->InsertItem(item,"");
		int width = 0;
		for(int i = 0;i < argv;i++)
		{
			argc[i] = U2G(argc[i]);
			if(i == 0 && cls->HaveTime)
			{
				CString time;
				time.Format("%s",argc[0]);
				time = time.Left(10);
				cls->m_ls->SetItemText(item,i,time);
			}
			else
				cls->m_ls->SetItemText(item,i,argc[i]);		
		}
		return false;
	}
	if(cls->opt == GetNum)
	{
		argc[0] = U2G(argc[0]);
		cls->result = argc[0];
		return false;
	}


	return false;
}
void CExternParent::Query()
{
/*	
	CEdit				*m_ed;
	CStatic				*m_tx;
	CButton				*m_bt;
	CComboBox			*m_cb;
	CString				*strCb;
	CListCtrl			*m_ls;
	CDateTimeCtrl		*m_tm;
*/
	while(m_ls->DeleteItem(0));
	CString condition = "";

	int i = 0;
	int cbNumber = 0;
	bool bNeedCount = false;
	while(m_tx[i].m_hWnd != NULL)
	{
		CString str;
		CString tmp = condition;
		m_tx[i].GetWindowText(str);
		if(str == "—")
			;
		else if(str == "单据日期" || str == "日期")
		{
			CString time[2];
			m_tm[0].GetWindowText(time[0]);
			m_tm[1].GetWindowText(time[1]);
			condition.Format("%s %s Between '%s 00:00:00' and '%s 24:00:00' and ",tmp,str,time[0],time[1]);
			HaveTime = true;
		}
		else if(str.Left(4) == "金额")
		{
			bNeedCount = true;
		}
		else 
		{
			CString charac = "";
			m_cb[cbNumber].GetWindowText(charac);
			if(!charac.IsEmpty())
				condition.Format("%s %s = '%s' and ",tmp,str,charac);
			cbNumber++;
		}
		i++;
	}
	condition = condition.Left(condition.GetLength() - 5);
	CString temp = "select ";
	int len = m_ls->GetHeaderCtrl()->GetItemCount();
	for(int j = 0;j < len;j++)
	{
		temp = temp + GetLsHeadText(j,m_ls);
		if(j <len - 1)
			temp += ",";
	}
	if(!condition.IsEmpty())
	{
		condition = "where " + condition;
		if(tbName.Left(4) == "mana" || tbName == "inventory" || tbName == "Employees")
			condition = condition + " and 状态 != '不可用'";
		
	}
	else
	{
	
		if(tbName.Left(4) == "mana" || tbName == "inventory" || tbName == "Employees")
			condition = " where 状态 != '不可用'";
	}
	opt = InsertLs;
	searchString.Format("%s from %s %s",temp,tbName,condition);
	DB_excute(db_ls,searchString,FillLs,this);

	/**金额总计**/
	if(bNeedCount)
	{
		if(tbName == "dataPayment" )
		{
			searchString = "select sum(付款金额) from " + tbName + " " + condition; 
		}
		else if(tbName == "dataVoucher")
		{
			searchString = "select sum(收款金额) from " + tbName + " " + condition; 
		}
		else if(tbName == "distriReturn" || tbName == "proReturn")
		{
			searchString = "select sum(退货金额) from " + tbName + " " + condition; 
		}
		
		else
			searchString = "select sum(金额总计) from " + tbName + " " + condition;
		opt = GetNum;
		DB_excute(db_ls,searchString,FillLs,this);

		if(result.Right(1) != "?")
			result = "金额总计：" + result;
		else
			result = "金额总计：0";
		m_tx[i-1].SetWindowText(result);
	}
}

void CExternParent::CreateDistriReturn(CRect rc)
{
	DB_select(db,CreateCtrl,this,"distriReturn");
	DB_selectTitle(db_ls,CompetLs,m_ls,"distriReturn");
	tbName = "distriReturn";

	opt = 0;
	char sql[] = "select 客户编号 from manaCus where 状态 != '不可用'";
	DB_excute(db_ls,sql,InsertComboBox,this);
}

void CExternParent::CreateManaEmployees(CRect rc)
{
	DB_select(db,CreateCtrl,this,"manaEmployees");
	DB_selectTitle(db_ls,CompetLs,m_ls,"manaEmployees");
	tbName = "Employees";
	Query();

}


void CExternParent::CreateDataReceivable(CRect rc)
{
	DB_select(db,CreateCtrl,this,"dataReceivable");
	DB_selectTitle(db_ls,CompetLs,m_ls,"dataReceivable");
	tbName = "dataReceivable";
	char sql[] = "select 客户编号 from manaCus where 状态 != '不可用'";
	opt = 0;
	DB_excute(db_ls,sql,InsertComboBox,this);

}

void CExternParent::CreateDataPayable(CRect rc)
{
	DB_select(db,CreateCtrl,this,"dataPayable");
	DB_selectTitle(db_ls,CompetLs,m_ls,"dataPayable");
	tbName = "dataPayable";
	char sql[] = "select 供应商编号 from manaSup where 状态 != '不可用'";
	opt = 0;
	DB_excute(db_ls,sql,InsertComboBox,this);

}
