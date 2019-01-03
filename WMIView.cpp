// WMIView.cpp : implementation of the CWMIView class
//

#include "stdafx.h"
#include "WMI.h"

#include "WMIDoc.h"
#include "WMIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWMIView

IMPLEMENT_DYNCREATE(CWMIView, CView)

BEGIN_MESSAGE_MAP(CWMIView, CView)
	//{{AFX_MSG_MAP(CWMIView)
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWMIView construction/destruction
//DEL LRESULT CWMIView::OnMyMessage(WPARAM wParam,LPARAM lParam)
//DEL {
//DEL 	switch(wParam)
//DEL 	{
//DEL 		m_Parent.~
//DEL 	}
//DEL }
CWMIView::CWMIView()
{
	// TODO: add construction code here
//	rMenu = new CRect;

//	CRect tmp[] = {rLogo,rProcurement,rDistribution,rWareHouse,rManagement,rData,rReport,rSet,rRest};
//	*rMenu = *tmp;
//	InitMenuRect();
/*
	if(m_Log.DoModal() == IDOK)
	{
		InitProgram();
	}
	else
	{

	}

*/	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_DEBUG );


	iNum = 7;
	
	time = CTime::GetCurrentTime();
	

	DialogVisible = -1;
	/*
	CWnd *pTmp[] = {&m_Procurment,&m_Distribute,&m_WareHouse,&m_Manage,&m_Data,&m_Assets,&m_Set,&m_Title};
	pDialog = pTmp;
	UINT DialogID[] = {IDD_PROCUR_CHILDTEXT,
		IDD_DISTRIBUT_CHILDTEXT,
		IDD_WAREHOUSE_CHILDTEXT,
		IDD_MANAGE_CHILDTEXT,
		IDD_DATA_CHILDTEXT,
		IDD_ASSETS_CHILDTEXT,
		IDD_SET_CHILDTEXT,
		IDD_TITLE_CHILDTEXT};
*/
//	for(int i = 0;i < 8;i++)
//		pDialog[i]->Create(DialogID[i],this);
	

//	rMenu = {rLogo,rProcurement,rDistribution,rWareHouse,rManagement,rData,rReport,rSet,rRest};
//	isHome = true;
	cfont.CreateFont(
		 18,				    	//height
		 9,							//wiidth
	     0,
		 0,							
		 FW_MEDIUM,					// nWeight    
         FALSE,                     // bItalic    斜体？
         FALSE,                     // bUnderline    
         0,                         // cStrikeOut    
         ANSI_CHARSET,              // nCharSet    
         OUT_DEFAULT_PRECIS,        // nOutPrecision    
         CLIP_DEFAULT_PRECIS,       // nClipPrecision    
         DEFAULT_QUALITY,           // nQuality    
         DEFAULT_PITCH,				// nPitchAndFamily    
         "宋体"						// lpszFac   
          ); 
//	isHome				= false;
//	ProcurementIsOn		= false;
//	DistributionIsOn	= false;
//	WareHouseIsOn		= false;		//仓库
//	ManagementIsOn		= false;		//管理
//	DataIsOn			= false;			//资料
//	ReportIsOn			= false;			//资产报表
//	SetIsOn				= false;
//	lastPoint = pointAt = -1;

	DB_open(&db,".\\UserData\\Data.db");
}

CWMIView::~CWMIView()
{
	DeleteObject(cfont);
	CompanyName.Empty();
	UserName.Empty();

	_CrtDumpMemoryLeaks();
}

/////////////////////////////////////////////////////////////////////////////
// CWMIView drawing

void CWMIView::OnDraw(CDC* pDC)
{
	CWMIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	/*
	CDialog *pTmp[] = {&m_Procurment,&m_Distribute,&m_WareHouse,&m_Manage,&m_Data,&m_Assets,&m_Set,&m_Title};
	pDialog = pTmp;
	UINT DialogID[] = {IDD_PROCUR_CHILDTEXT,
		IDD_DISTRIBUT_CHILDTEXT,
		IDD_WAREHOUSE_CHILDTEXT,
		IDD_MANAGE_CHILDTEXT,
		IDD_DATA_CHILDTEXT,
		IDD_ASSETS_CHILDTEXT,
		IDD_SET_CHILDTEXT,
		IDD_TITLE_CHILDTEXT};

	for(int i = 0;i < 8;i++)
	{
		if(pDialog[i]->m_hWnd == NULL)
			pDialog[i]->Create(DialogID[i],this);
	//	pDialog[i]->GetWindowRect(&rc[i]); //老铁，不要加&啊!难怪报错，也就是说，pDialog是可以存放窗口指针的!;
		pDialog[i]->GetWindowRect(rc[i]);
	}*/
/**************************************************************************/
	if(m_Parent.m_hWnd == NULL)						//qus：为什么m_Tab要点击两次才生效？
	{
		m_Parent.Create(IDD_EXTERN_PARENT,this);
		CRect tRc;
		m_Parent.GetClientRect(tRc);
		tRc = CRect(tRc.left,tRc.top,tRc.left + 1120,tRc.top + 600);
		ClientToScreen(&tRc);
		m_Parent.MoveWindow(tRc);
		m_Parent.UserName = UserName;
	}
/***************************************************************************/

	if(m_Procurment.m_hWnd == NULL)
	{
		m_Procurment.Create(IDD_PROCUR_CHILDTEXT,this);		//采购
		m_Procurment.UserName = UserName;
	}

	if(m_Distribute.m_hWnd == NULL)
	{
		m_Distribute.Create(IDD_DISTRIBUT_CHILDTEXT,this);	//配送
		m_Distribute.UserName = UserName;
	}
	if(m_Manage.m_hWnd == NULL)
	{
		m_Manage.Create(IDD_MANAGE_CHILDTEXT,this);			//管理
		m_Manage.UserName = UserName;
	}
	if(m_WareHouse.m_hWnd == NULL)
	{
		m_WareHouse.Create(IDD_WAREHOUSE_CHILDTEXT,this);	//仓库
		m_WareHouse.UserName = UserName;
	}
	if(m_Set.m_hWnd == NULL)
	{
		m_Set.Create(IDD_SET_CHILDTEXT,this);				//设置
		m_Set.UserName = UserName;
	}
	if(m_Data.m_hWnd == NULL)
	{
		m_Data.Create(IDD_DATA_CHILDTEXT,this);				//资料
		m_Data.UserName = UserName;
	}
//	if(m_Assets.m_hWnd == NULL)
//		m_Assets.Create(IDD_ASSETS_CHILDTEXT,this);			//报表

	if(m_Title.m_hWnd == NULL)
	{
		m_Title.Create(IDD_TITLE_CHILDTEXT,this);			//标题
		m_Title.UserName = UserName;
	}
//由于开始弄的时候，并没有理解到指针储存窗口对象的内在规则，暂时这样，如果要改也很麻烦

	m_Procurment.GetWindowRect(&rc[0]);						//采购
	m_Distribute.GetWindowRect(&rc[1]);						//配送
	m_WareHouse.GetWindowRect(&rc[2]);						//仓库
	m_Manage.GetWindowRect(&rc[3]);							//管理
	m_Data.GetWindowRect(&rc[4]);							//资料
//	m_Assets.GetWindowRect(&rc[5]);							//报表
//	m_Set.GetWindowRect(&rc[6]);							//设置
	m_Set.GetWindowRect(&rc[5]);							//设置
	m_Title.GetWindowRect(&rc[7]);							//标题

	GetClientRect(&rClient);
	CBrush brush;
//	CBitmap bmp;
	
//	bmp.LoadBitmap(IDB_BITMAP1);
//	if(bmp.LoadBitmap(IDB_BITMAP1))
//		MessageBox("df",MB_OK);
	brush.CreateSolidBrush(WHITESMOKE);

	CDC *MemDC = new CDC();
//	CDC *pOldDC = new CDC;

//	pOldDC->CreateCompatibleDC(pDC);
	MemDC->CreateCompatibleDC(pDC);
	CBitmap MemBitMap;
	MemBitMap.CreateCompatibleBitmap(pDC,rClient.Width(),rClient.Height());

	MemDC->SelectObject(MemBitMap);
//	pOldDC->SelectObject(tmpBitmap);
	MemDC->FillRect(&rClient,&brush);
//	MemDC->BitBlt(0,0,140,60,pOldDC,0,0,SRCCOPY);


	InitMenuRect();
	DrawMenu(MemDC);

	InitFunctionRect();
	DrawFounct(MemDC);


	pDC->BitBlt(rClient.left,rClient.top,rClient.Width(),rClient.Height(),MemDC,0,0,SRCCOPY);
	

	delete MemDC;
	MemDC = 0;
//	MemDC->DeleteDC();
//	::DeleteObject(pOldDC);
	DeleteObject(MemBitMap);
}

/////////////////////////////////////////////////////////////////////////////
// CWMIView diagnostics

#ifdef _DEBUG
void CWMIView::AssertValid() const
{
	CView::AssertValid();
}

void CWMIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWMIDoc* CWMIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWMIDoc)));
	return (CWMIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWMIView message handlers



void CWMIView::InitMenuRect()
{
	//获取客户端大小
//	CRect rClient;
//	GetClientRect(&rClient);

	for(int i = 0;i < 8;i++)
	{
		rMenu[i].left = 0;
		rMenu[i].right = 160;
		rMenu[i].top = 60 * i + 20;
		if(i != 7)
			if(i == 0)
				rMenu[i].bottom = rMenu[i].top + 90;
			else
				rMenu[i].bottom = rMenu[i].top + 60;
		else
			rMenu[i].bottom = rClient.bottom;
	}
}

void CWMIView::DrawMenu(CDC *pDC)
{
	CString strMenu[] = {"采购","配送","仓库","管理","资料","设置"};

	CDC *pMemDC = new CDC();
	CBitmap tBitmap;
	CBrush brush[2];
	CFont font;
	CFont font2;
	
	pMemDC->CreateCompatibleDC(pDC);

	brush[0].CreateSolidBrush(BLACK);
	brush[1].CreateSolidBrush(RGB(20,20,20));

	tBitmap.LoadBitmap(IDB_LOGO_BLAK);
	pMemDC->SelectObject(tBitmap);

	//设置字体属性

	font.CreateFont(
		 26,						//height
		 13,						//wiidth
	     0,
		 0,							
		 FW_BOLD,					 // nWeight    
         FALSE,                      // bItalic    斜体？
         FALSE,                     // bUnderline    
         0,                         // cStrikeOut    
         ANSI_CHARSET,              // nCharSet    
         OUT_DEFAULT_PRECIS,        // nOutPrecision    
         CLIP_DEFAULT_PRECIS,       // nClipPrecision    
         DEFAULT_QUALITY,           // nQuality    
         DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily    
         "宋体"						// lpszFac   
          ); 

//	pDC->StretchBlt(0,0,160,90,pMemDC,0,0,640,320,SRCCOPY);
	pDC->BitBlt(0,0,160,80,pMemDC,0,0,SRCCOPY);
	
	pDC->SelectObject(font);

	//设置输出字体背景透明
	pDC->SetBkMode(TRANSPARENT);
	//设置输出字体颜色
	pDC->SetTextColor(WHITE);

	pDC->TextOut(rMenu[0].left+40,rMenu[0].top ,"小蘑菇");
	//二次create报错，所以不能这样操作、、、、
	font2.CreateFont(
		 40,						//height
		 20,						//wiidth
	     0,
		 0,							
		 FW_BOLD,					 // nWeight    
         FALSE,                      // bItalic    斜体？
         FALSE,                     // bUnderline    
         0,                         // cStrikeOut    
         ANSI_CHARSET,              // nCharSet    
         OUT_DEFAULT_PRECIS,        // nOutPrecision    
         CLIP_DEFAULT_PRECIS,       // nClipPrecision    
         DEFAULT_QUALITY,           // nQuality    
         DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily    
         "宋体"						// lpszFac   
          ); 
	pDC->SelectObject(font2);
	
	
	
	for(int i = 1;i < 8;i++)
	{
		pDC->FillRect(&rMenu[i],&brush[(i + 1 )%2]);

		if(i <= 6)
		{
			pDC->TextOut(rMenu[i].left + 35,rMenu[i].bottom - 50,strMenu[i - 1]);
			strMenu[i - 1].Empty();
		}
	}
	


	//delete [] pMemDC;
	delete pMemDC;
	pMemDC = 0;
	
//	delete strMenu;
	//pMemDC->DeleteDC();
	DeleteObject(font);
	DeleteObject(font2);
	DeleteObject(brush);
	DeleteObject(tBitmap);
}

void CWMIView::InitFunctionRect()
{
	//重新设置值
	rfTitle.top = rClient.top;
	rfTitle.left = rMenu[0].left + 160;
	rfTitle.right = rClient.right;
	rfTitle.bottom = rClient.top + 50;
//都是基于公告矩形区域的相对位置来设置其他区域大小
	rfAnnounce.right = rClient.right - 10;
	rfAnnounce.top = rClient.top + 60;
	rfAnnounce.bottom = rfAnnounce.top + 200;
	rfAnnounce.left = rClient.right - 260;

	rfFounction.top = rfAnnounce.bottom + 20;
	rfFounction.bottom = rClient.bottom - 10;
	rfFounction.left = rfAnnounce.left;
	rfFounction.right = rfAnnounce.right;

	rfQueue.top = rfAnnounce.top;
	rfQueue.bottom = rfAnnounce.bottom;
	rfQueue.right = rfAnnounce.left - 20;
	rfQueue.left = rMenu[0].right + 10;

	rfReport.top = rfQueue.bottom + 20;
	rfReport.left = rfQueue.left;
	rfReport.right = rfQueue.right;
	rfReport.bottom = rClient.bottom - 10;

	rfRest.bottom = rClient.bottom;
	rfRest.top = rClient.top;
	rfRest.left = rMenu[0].right;
	rfRest.right = rClient.right;

}

void CWMIView::DrawFounct(CDC *pDC)
{

	CBrush brush;
//	CBrush WhiteBrush;
	brush.CreateSolidBrush(SNOW);
//	WhiteBrush.CreateSolidBrush(WHITE);

	pDC->FillRect(&rfTitle,&brush);
	pDC->FillRect(&rfAnnounce,&brush);
	pDC->FillRect(&rfFounction,&brush);
	pDC->FillRect(&rfReport,&brush);
	pDC->FillRect(&rfQueue,&brush);

	pDC->SelectObject(cfont);
	pDC->SetTextColor(BLACK);
	pDC->SetBkMode(TRANSPARENT);
	

	DrawAnnounce(pDC);
	DrawFounction(pDC);
	DrawReport(pDC);
	DrawTitle(pDC);
	DrawQueue(pDC,0);

	DeleteObject(brush);

}

void CWMIView::DrawAnnounce(CDC *pDC)
{
	pDC->TextOut(rfAnnounce.left + rfAnnounce.Width() / 2 - 15,rfAnnounce.top + 10,"公告");
	CBrush brush[2];
	CRect rect;

	rect.top = rfAnnounce.top + 30;
	rect.left = rfAnnounce.left + 10;
	rect.bottom = rfAnnounce.bottom - 10;
	rect.right = rfAnnounce.right - 10;

	brush[0].CreateSolidBrush(GRAY);
	pDC->FillRect(&rect,&brush[0]);
	DeleteObject(brush[0]);

	rect.bottom -= 5;
	rect.right -= 5;

	
	brush[1].CreateSolidBrush(WHITESMOKE);
	pDC->FillRect(&rect,&brush[1]);
	DeleteObject(brush[1]);

	if(Announce.IsEmpty())
	{
		pDC->TextOut(rect.left + 20,rect.top + 20 ,"暂无公告");
	}
	else
		pDC->TextOut(rect.left + 20,rect.top + 20,Announce);

}

void CWMIView::DrawFounction(CDC *pDC)
{
//	CBrush brush;
/*	CRect rTmp;

	int height = rfFounction.Height() / 9;

	brush.CreateSolidBrush(WHITE);
	rTmp.top = rfFounction.top + 30;
	rTmp.left = rfFounction.left + 15;
	rTmp.bottom = rfFounction.bottom - 15;
	rTmp.right = rfFounction.right - 15;

	pDC->FillRect(&rTmp,&brush);

	pDC->SetTextColor(BLACK);

	pDC->TextOut(rfFounction.left + 10,rfFounction.top + 10,"关键数据");
	CString strDataTitle[] = {"库存总量：","库存成本：","现金：","银行存款：","客户欠款：","供应商欠款：","销售收入(本月)：","采购金额(本月)："};
	
	pDC->MoveTo(rfFounction.left + 5,rfFounction.top + 30);
	pDC->LineTo(rfFounction.right - 5,rfFounction.top + 30);

	for(int i = 0;i < 4;i++)
	{
		pDC->TextOut(rfFounction.left + 25,rfFounction.top + height * (i * 2 + 1),strDataTitle[i * 2]);
		pDC->TextOut(rfFounction.left + 25,rfFounction.top + height * (i *2 + 1) + 40,strDataTitle[i * 2 + 1]);
	}
//	::DeleteObject(brush);
*/
	CRect rc;
	rc.left = rfFounction.left;
	rc.top = rfFounction.top + 50;
	rc.right = rfFounction.right;
	rc.bottom = rfFounction.bottom;

	pDC->TextOut(rfFounction.left + 10,rfFounction.top + 20,"库存预警");
	pDC->MoveTo(rfFounction.left,rfFounction.top + 45);
	pDC->LineTo(rfFounction.right,rfFounction.top + 45);

	if(m_Critical.m_hWnd == NULL)
	{
		DWORD dwStyle = LVS_NOSORTHEADER | LVS_REPORT ;
		m_Critical.Create(dwStyle,rc,this,IDC_CLIST);
		m_Critical.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_GRIDLINES);
		m_Critical.SetFont(&cfont,true);
		m_Critical.InsertColumn(1,"商品编号",LVCFMT_CENTER,rc.Width() / 2,0);
		m_Critical.InsertColumn(2,"在库量",LVCFMT_CENTER,rc.Width() / 2,0);
		m_Critical.ShowWindow(true);
	}
	else
		m_Critical.MoveWindow(rc);
	

}

void CWMIView::DrawQueue(CDC *pDC, unsigned int percent)
{
//	pDC->TextOut(rfQueue.left + 10,rfQueue.top + 10,"待处理业务");
	CString strTitle[] = {"库存预警","昨日收款笔数","昨日付款笔数","昨日配送笔数","昨日采购笔数"};

//	CDC *tDC;
//	CPen pen;
//	pen.CreatePen(PS_SOLID,9,WHITE);
//	pDC->SelectObject(pen);
/*	CFont font;

	tDC = pDC;
	font.CreateFont(
		18,						//height
		9,						//wiidth
	    0,
		0,							
		FW_BOLD,					 // nWeight    
        FALSE,                      // bItalic    斜体？
        FALSE,                     // bUnderline    
        0,                         // cStrikeOut    
        ANSI_CHARSET,              // nCharSet    
        OUT_DEFAULT_PRECIS,        // nOutPrecision    
        CLIP_DEFAULT_PRECIS,       // nClipPrecision    
        DEFAULT_QUALITY,           // nQuality    
        DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily    
        "宋体"						// lpszFac   
        ); 
	tDC->SelectObject(font);
	tDC->SetBkMode(TRANSPARENT);
//	tDC->SetTextColor(WHITE);
*/
	CRect rect[5];
	CBrush brush[10];

	brush[0].CreateSolidBrush(RGB(240,150,110));
	brush[1].CreateSolidBrush(RGB(230,140,100));
	brush[2].CreateSolidBrush(RGB(240,200,100));
	brush[3].CreateSolidBrush(RGB(230,190,90));
	brush[4].CreateSolidBrush(RGB(230,240,120));
	brush[5].CreateSolidBrush(RGB(220,230,110));
	brush[6].CreateSolidBrush(RGB(170,230,100));
	brush[7].CreateSolidBrush(RGB(160,220,90));
	brush[8].CreateSolidBrush(RGB(80,220,170));
	brush[9].CreateSolidBrush(RGB(70,210,160));


	rect[0].top = rfQueue.top + 10;
	rect[1].top = rect[0].top;
	rect[2].top = rect[0].top; 
	rect[3].top = rect[0].top; 
	rect[4].top = rect[0].top; 

	rect[0].bottom = rfQueue.bottom - 10;
	rect[1].bottom = rect[0].bottom;
	rect[2].bottom = rect[0].bottom;
	rect[3].bottom = rect[0].bottom;
	rect[4].bottom = rect[0].bottom;

	int width= (rfQueue.Width() - 10) / 5 - 10;
	rect[0].left = rfQueue.left + 10;
	rect[0].right = width + rect[0].left;
	
	rect[1].left = rect[0].right + 10;
	rect[1].right = width + rect[1].left;

	rect[2].left = rect[1].right + 10;
	rect[2].right = width + rect[2].left;
	
	rect[3].left = rect[2].right + 10;
	rect[3].right = width + rect[3].left;

	rect[4].left = rect[3].right + 10;
	rect[4].right = width + rect[4].left;

//	rect[5] = CRect(rect[0].left,rect[0].top,rect[0].left + strlen(strTi),rect[0].top + 40);
	
	pDC->SetTextColor(BLACK);
	
	for(int i = 0;i < 5;i++)
	{
		pDC->FillRect(&rect[i],&brush[i * 2]);
		pDC->FillRect(&CRect(rect[i].left,rect[i].top,rect[i].left + strTitle[i].GetLength() * 10,rect[i].top + 40),&brush[i * 2+1]);
		pDC->TextOut(rect[i].left + 5,rect[i].top + 10,strTitle[i]);
		strTitle[i].Empty();
		DeleteObject(brush[i * 2]);
		DeleteObject(brush[i * 2 + 1]);
	}
	CFont font;
	font.CreateFont(
		100,						//height
		65,						//wiidth
	    0,
		0,							
		FW_BOLD,					 // nWeight    
        FALSE,                      // bItalic    斜体？
        FALSE,                     // bUnderline    
        0,                         // cStrikeOut    
        ANSI_CHARSET,              // nCharSet    
        OUT_DEFAULT_PRECIS,        // nOutPrecision    
        CLIP_DEFAULT_PRECIS,       // nClipPrecision    
        DEFAULT_QUALITY,           // nQuality    
        DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily    
        "宋体"						// lpszFac   
        ); 
	pDC->SelectObject(font);
	pDC->SetTextColor(RGB(240,240,240));
	for(int j = 0;j < 5;j++)
		pDC->TextOut(rect[j].left + 50,rect[j].top+40,strQueue[j]);
	font.DeleteObject();
}

CRect CWMIView::DrawReport(CDC *pDC)
{
	pDC->TextOut(rfReport.left + 10,rfReport.top + 20,"最近出入库");
	pDC->MoveTo(rfReport.left,rfReport.top + 45);
	pDC->LineTo(rfReport.right,rfReport.top + 45);

	return DrawXY(pDC);
}

BOOL CWMIView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;
}


void CWMIView::SetAnnounce(CString str)
{
	Announce = str;
	str.Empty();
}
int GetViewData(void*data,int argc,char**argv,char**column)
{
	CWMIView* dlg = (CWMIView*)data;
	if(dlg->opt == GETDATA)
	{
		int item = dlg->m_Critical.GetItemCount();
		dlg->m_Critical.InsertItem(item,"");
		dlg->m_Critical.SetItemText(item,0,U2G(argv[0]));
		dlg->m_Critical.SetItemText(item,1,U2G(argv[1]));
		return false;
	}
	if(dlg->opt == GetNum)
	{
		argv[0] = U2G(argv[0]);
		dlg->result = argv[0];
		return false;
	}

	return false;
}
CRect CWMIView::DrawXY(CDC *pDC)
{
//	CDC  *pDC;
///	pDC = GetDC();

	CRect tmp;

	tmp = CutRect(rfReport,40,20,50,50);
	CPoint center(tmp.left + 50,tmp.bottom - 50);

	CPen pen;
	pen.CreatePen(PS_SOLID,4,PURPLE);
	CBrush brush;
	brush.CreateSolidBrush(RGB(255,240,240));

	pDC->SelectObject(pen);
	pDC->MoveTo(center);
	pDC->LineTo(center.x,tmp.top + 50);
	int h = center.y - tmp.top - 45;

	int per = h / 20;
	for(int index = 1;index <= 20;index++)
	{
		pDC->MoveTo(center.x - 1 ,center.y - index * per);
		if(index % 5 == 0)
			pDC->LineTo(center.x + 15,center.y - index * per);
		else
			pDC->LineTo(center.x + 9,center.y - index * per);
		
	}

	pDC->MoveTo(center);
	pDC->LineTo(tmp.right,center.y);
	pDC->TextOut(center.x - 10,center.y + 5 ,"0");

	int width = (tmp.right - center.x) / (iNum * 2.5 + 0.5);
	CRect cfRect(center.x + 0.5* width,tmp.top + 50,center.x + 1.5 * width,center.y - 2);

	int wareIn[7],wareOut[7],sum;
	int max[2] = {0,0};
	int min[2] = {0,0};
	CString sql;
	CTime tTime = time;
	for(int i = 0;i < iNum;i++)
	{
		tmp = MoveRect(cfRect,width * 2.5 * i,0);
		tmp.right = tmp.right + width;
		pDC->FillRect(&tmp,&brush);
//get time and TextOut()!
		CTime t = tTime - CTimeSpan(1,0,0,0);
	//	CString strTime = t.Format("%m/%d");
	/* select last week the number of wareIn And wareOut */
		//Get data
		opt = GetNum;
		sql = "select count(*) from wareIn where 单据日期 between '" + 
			t.Format("%Y-%m-%d") + "' and '" + 
			tTime.Format("%Y-%m-%d")+ "'";
		DB_excute(db,sql,GetViewData,this);
		wareIn[i] = atoi(result.GetBuffer(0));
		result.ReleaseBuffer();
		sum += wareIn[i];

		if(wareIn[i] > max[0])
			max[0] = wareIn[i];
		else if(wareIn[i] < min[0])
			min[0] = wareIn[i];

		sql = "select count(*) from wareOut where 单据日期 between '" + 
			t.Format("%Y-%m-%d") + "' and '" + 
			tTime.Format("%Y-%m-%d")+ "'";
		DB_excute(db,sql,GetViewData,this);
		wareOut[i] = atoi(result.GetBuffer(0));
		result.ReleaseBuffer();
		sum = wareOut[i];

		if(wareOut[i] > max[1])
			max[1] = wareOut[i];
		else if(wareOut[i] < min[1])
			min[1] = wareOut[i];

		tTime = t;

	//	pDC->TextOut(tmp.left,tmp.bottom+10,strTime);
	//	strTime.Empty();
	}
	/* search in database, and draw the rect */
	/* select last week the number of wareIn And wareOut */
	// darw Y
	if(max[0] < max[1])
		max[0] = max[1];
	if(min[0] > min[1])
		min[0] = min[1];
	
	//最低精度 [1 , 20]
	if(max[0] < 20)
		per = 1;
	else 
	{
		per = max[0] / 20;
		if(per * 20 < max[0])
			per = per + 1;
	}
	CString strInt;
	int k = 1;
	for(;k < 5;k++)
	{
		strInt.Format("%d",per * 5 * k);
		pDC->TextOut(center.x - strInt.GetLength() * 12,center.y - h / 4 * k,strInt);
	}

	h = h / 20;
	CString strTime;
	CBrush brush1;
	brush1.CreateSolidBrush(GREEN);
	for(k = 0 ;k < iNum; k++)
	{
		tmp = MoveRect(cfRect,width * 2.5 * k,0);
		tmp.top = tmp.bottom - wareIn[6-k] / per * h;
		pDC->FillRect(&tmp,&brush1);
		CTime t = time - CTimeSpan(iNum - k,0,0,0);
		strTime = t.Format("%m/%d");
		pDC->TextOut(tmp.left + 20,tmp.bottom+10,strTime);
	}

	CBrush brush2;
	brush2.CreateSolidBrush(GOLD);
	for(k = 0 ;k < iNum; k++)
	{
		tmp = MoveRect(cfRect,width * (2.5 * k+1),0);
		tmp.top = tmp.bottom - wareOut[6-k] / per * h;
		pDC->FillRect(&tmp,&brush2);
	}
	
	for(k = 0; k<iNum; k++)
	{
		strInt.Format("入库：%d",wareIn[6-k]);
		tmp = MoveRect(cfRect,width * 2.5 * k,0);
		pDC->TextOut(tmp.left+3,tmp.top + 10,strInt);
		strInt.Format("出库：%d",wareOut[6-k]);
		pDC->TextOut(tmp.left+3,tmp.top + 30,strInt);
		
	}
//	DeleteObject(pDC);
	DeleteObject(pen);
	DeleteObject(brush);

	return CRect(center.x,tmp.top + 50,center.x + width,center.y);
}

CRect CWMIView::MoveRect(CRect rect, int xDistance,int yDistance)
{
	CRect tmp;

	tmp.top = rect.top +yDistance;
	tmp.bottom = rect.bottom + yDistance;
	tmp.left = rect.left + xDistance;
	tmp.right =rect.right +  xDistance;

	return tmp;

}

CRect CWMIView::CutRect(CRect rect, int top, int bottom, int left, int right)
{
	CRect tmp;

	tmp.top = rect.top + top;
	tmp.bottom = rect.bottom - bottom;
	tmp.left = rect.left + left;
	tmp.right =rect.right -  right;

	return tmp;
	
}



void CWMIView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
/*	
	if(point.x < rMenu[0].right)
	{
		
		if(point.y < rMenu[1].bottom && point.y > rMenu[0].bottom)
		{
			pointAt = 1;
			PointOnMenu(pointAt);
	
		}
		else if(point.y < rMenu[2].bottom && point.y > rMenu[1].bottom)
		{
			pointAt = 2;	
			PointOnMenu(pointAt);

		}
		else if(point.y < rMenu[3].bottom && point.y > rMenu[2].bottom)
		{
			pointAt = 3;
			PointOnMenu(pointAt);

		}
		else if(point.y < rMenu[4].bottom && point.y > rMenu[3].bottom)
		{
			pointAt = 4;
			PointOnMenu(pointAt);

		}
		else if(point.y < rMenu[5].bottom && point.y > rMenu[4].bottom)
		{
			pointAt = 5;
			PointOnMenu(pointAt);
		}
		else if(point.y < rMenu[6].bottom && point.y > rMenu[5].bottom)
		{
			pointAt = 6;
			PointOnMenu(pointAt);
		}
		else if(point.y < rMenu[7].bottom && point.y > rMenu[6].bottom)
		{
			pointAt = 7;
			PointOnMenu(pointAt);
		}
		else if(m_ChildText.m_hWnd != NULL)
		{
			m_ChildText.DestroyWindow();
		}

	}
	else
	{
		if(rfTitle.PtInRect(point) && point.x < (strlen(logoName) * 10 + rfTitle.right - 200) && point.x > rfTitle.right - 200)
		{
			if(m_person.m_hWnd == NULL)
			{
				m_person.Create(IDD_PERSON,this);
				m_person.MoveWindow(&CRect(rfTitle.right - 200,rfTitle.top + 50,rfTitle.right - 200 + strlen(logoName) * 10 + 20,rfTitle.bottom + 70));
				m_person.ShowWindow(true);
			}
			else
				m_person.ShowWindow(true);
		}
		else if(rfQueue.PtInRect(point))
		{

		}
		else if(rfAnnounce.PtInRect(point))
		{

		}
	}

	if(m_person.m_hWnd != NULL)
	{
		CRect trPerson1(rfTitle.right - 200,rfTitle.top,rfTitle.right - 200 + strlen(logoName) * 10 + 20,rfTitle.top + 70);
		CRect trPerson2;
		m_person.GetWindowRect(&trPerson2);
		if(trPerson1.PtInRect(point) || trPerson2.PtInRect(point))
		{

		}
		else
			m_person.DestroyWindow();
	}
*/
/*	//如果鼠标移动到菜单区域，----xxxxxxxxxxxxxxxxxxx基类Dialog指针并不能调用getwindowrect----xxxxx这句可能是错的！2018-7-28-23.50；
	if(point.x < rMenu[0].right)
	{
		for(int i = 0;i < 7;i++)
			if(rMenu[i + 1].PtInRect(point))
			{
				if(DialogVisible != -1 && DialogVisible != i)
				{
					pDialog[DialogVisible]->ShowWindow(false);
				}
				DialogVisible = i;      
			//	CRect rc;
			//	pDialog[i]->GetWindowRect(&rc);
//				if(!pDialog[i]->IsWindowVisible())
//				{
					pDialog[i]->ShowWindow(true);
					if(i == 1)
					{
						pDialog[i]->MoveWindow(MoveRect(rc[i],
							CPoint(rc[i].left,rc[i].top),
							CPoint(rMenu[i + 1].right,rMenu[i + 1].top)));
					}
					else 
					{

						pDialog[i]->MoveWindow(MoveRect(rc[i],
							CPoint(rc[i].left,rc[i].top + rc[i].Height() / 2),
							CPoint(rMenu[i + 1].right,rMenu[i].top + rMenu[i + 1].Height() / 2)));
					//	switch(i)
					//	{
					//	case 2:
					//		{
					//
					//		};break;
					//	case 3:;break;
					//	case 4:;break;
					//	case 5:;break;
					//	case 6:;break;
					//	case 7:;break;
					//	}
						
//					}
					

				}
				return;
			}
			else
			{
			//	if(WhichMenuVisible > 0)
					
			}
	}
	*/	

//筛选条件：当鼠标移动到CMenu和CTitle范围内
//判断前提：其他窗口并没有ShowWindow(true)；			
	if(point.x < rMenu[0].right)
	{

		if(rMenu[1].PtInRect(point))
		{
			if(DialogVisible != -1 && DialogVisible != 1)
			{
				CloseDialog(DialogVisible);
			}
			if(!m_Procurment.IsWindowVisible())
			{
				m_Procurment.ShowWindow(true);
			}
			if(rc[0].TopLeft() != CPoint(rMenu[1].right,rMenu[1].top))
			{
				m_Procurment.MoveWindow(MoveRect(rc[0],CPoint(rc[0].left,rc[0].top),CPoint(rMenu[1].right,rMenu[1].top)));
			}
			DialogVisible = 1;
		}
		else if(rMenu[2].PtInRect(point))
		{
			if(DialogVisible != -1 && DialogVisible != 2)
			{
				CloseDialog(DialogVisible);
			}
			if(!m_Distribute.IsWindowVisible())
			{
				m_Distribute.ShowWindow(true);
			}
			if(CPoint(rc[1].left,rc[1].top + rc[1].Height() / 2) != CPoint(rMenu[2].right,rMenu[2].top + rMenu[2].Height() / 2))
			{
				m_Distribute.MoveWindow(MoveRect(rc[1],CPoint(rc[1].left,rc[1].top + rc[1].Height() / 2),
										CPoint(rMenu[2].right,rMenu[2].top + rMenu[2].Height() / 2)));
			}
			DialogVisible = 2;
		}
		else if(rMenu[3].PtInRect(point))
		{
			if(DialogVisible != -1 && DialogVisible != 3)
			{
				CloseDialog(DialogVisible);
			}
			if(!m_WareHouse.IsWindowVisible())
			{
				m_WareHouse.ShowWindow(true);
			}
			if(CPoint(rc[2].left,rc[2].top + rc[2].Height() / 2) != CPoint(rMenu[3].right,rMenu[3].top + rMenu[3].Height() / 2))
			{
				m_WareHouse.MoveWindow(MoveRect(rc[2],CPoint(rc[2].left,rc[2].top + rc[2].Height() / 2),
										CPoint(rMenu[3].right,rMenu[3].top + rMenu[3].Height() / 2)));
			}
			DialogVisible = 3;
		}
		else if(rMenu[4].PtInRect(point))
		{
			if(DialogVisible != -1 && DialogVisible != 4)
			{
				CloseDialog(DialogVisible);
			}
			if(!m_Manage.IsWindowVisible())
			{
				m_Manage.ShowWindow(true);
			}
			if(CPoint(rc[3].left,rc[3].top + rc[3].Height() / 2) != CPoint(rMenu[4].right,rMenu[4].top + rMenu[4].Height() / 2))
			{
				m_Manage.MoveWindow(MoveRect(rc[3],CPoint(rc[3].left,rc[3].top + rc[3].Height() / 2),
									CPoint(rMenu[4].right,rMenu[4].top + rMenu[4].Height() / 2)));
			}
			DialogVisible = 4;
		}
		else if(rMenu[5].PtInRect(point))
		{
			if(DialogVisible != -1 && DialogVisible != 5)
			{
				CloseDialog(DialogVisible);
			}
			if(!m_Data.IsWindowVisible())
			{
				m_Data.ShowWindow(true);
			}
			if(CPoint(rc[4].left,rc[4].top + rc[4].Height() / 2) != CPoint(rMenu[5].right,rMenu[5].top + rMenu[5].Height() / 2))
			{
				m_Data.MoveWindow(MoveRect(rc[4],CPoint(rc[4].left,rc[4].top + rc[4].Height() / 2),
									CPoint(rMenu[5].right,rMenu[5].top + rMenu[5].Height() / 2)));
			}
			DialogVisible = 5;
		}
		else if(rMenu[6].PtInRect(point))
		{
			if(DialogVisible != -1 && DialogVisible != 6)
			{
				CloseDialog(DialogVisible);
			}
			if(!m_Set.IsWindowVisible())
			{
				m_Set.ShowWindow(true);
			}
			if(CPoint(rc[5].left,rc[5].top + rc[5].Height() / 2) != CPoint(rMenu[6].right,rMenu[6].top + rMenu[6].Height() / 2))
			{
				m_Set.MoveWindow(MoveRect(rc[5],CPoint(rc[5].left,rc[5].top + rc[5].Height() / 2),
									CPoint(rMenu[6].right,rMenu[6].top + rMenu[6].Height() / 2)));
			}
			DialogVisible = 6;
		}
//		else if(rMenu[7].PtInRect(point))
//		{
//			if(DialogVisible != -1 && DialogVisible != 7)
//			{
//				CloseDialog(DialogVisible);
//			}
//			if(!m_Set.IsWindowVisible())
//			{
//				m_Set.ShowWindow(true);
//			}
//			if(CPoint(rc[6].left,rc[6].top + rc[6].Height() / 2) != CPoint(rMenu[7].right,rMenu[7].top + rMenu[7].Height() / 2))
//			{
//				m_Set.MoveWindow(MoveRect(rc[6],CPoint(rc[6].left,rc[6].top + rc[6].Height() / 2),
//									CPoint(rMenu[7].right,rMenu[7].top + rMenu[7].Height() / 2)));
//			}
//			DialogVisible =7;
//		}
		else
		{
		}

	}

	else if(point.y < rfTitle.bottom)
	{
		if(point.x > rfTitle.right - 200 && point.x <  rfTitle.right - 150)
		{
			if(DialogVisible != -1 && DialogVisible != 8)
			{
				CloseDialog(DialogVisible);
			}
			if(!m_Title.IsWindowVisible())
			{
				m_Title.ShowWindow(true);
			}
			if(CPoint(rc[7].left,rc[7].top) != CPoint(rfTitle.right - 250,rfTitle.bottom))
			{
				m_Title.MoveWindow(MoveRect(rc[7],CPoint(rc[7].left,rc[7].top),CPoint(rfTitle.right - 240,rfTitle.bottom)));
			}
			DialogVisible = 8;
		}
		else if(m_Title.IsWindowVisible())
			m_Title.ShowWindow(false);
	}
	else
	{
		if(DialogVisible != -1)
			CloseDialog(DialogVisible);
	}

	CView::OnMouseMove(nFlags, point);
}

/*
void CWMIView::PointOnMenu(int iTmp)
{
	int typeNum[7] = {5,3,6,5,6,7,3};
	int width[7] = {6,6,6,6,5,7,6};
	if(lastPoint != iTmp)
	{
		if(lastPoint != -1)
		{
			m_ChildText.DestroyWindow();

		}
	//窗口竟然是随便移动的，可见，创建的窗口并没有和视图完全融合在一起
		//而是分为两层
	//	CDC *pDC;
	//	pDC = GetDC();
	//	OnDraw(pDC);
	//m_ChildText.ShowWindow(true);
	
		if(m_ChildText.m_hWnd == NULL)				
		//	Sleep(250);  //难道CWnd::Create是单独创建一个线程？
			m_ChildText.Create(IDD_CHILDTEXT,this);
		
		if(iTmp == 1)
			m_ChildText.MoveWindow(
				&CRect(rMenu[iTmp].right,
				rMenu[iTmp].top,
				rMenu[iTmp].right + 20 * width[iTmp - 1] + 20,
				rMenu[iTmp].top + 50 + 50 * typeNum[iTmp - 1]));
		else
			m_ChildText.MoveWindow(
				&CRect(rMenu[iTmp].right,
				rMenu[iTmp].top  + 40 - 25 * typeNum[iTmp - 1],
				rMenu[iTmp].right + 20 * width[iTmp - 1] + 20,
				rMenu[iTmp].top + 50 + 25 * typeNum[iTmp - 1]));
		m_ChildText.initDialog(typeNum[iTmp - 1],iTmp - 1);
		lastPoint = iTmp;
		m_ChildText.ShowWindow(true);
	}
	else
	{
		if(m_ChildText.m_hWnd == NULL)
		{
		//	Sleep(250);
			m_ChildText.Create(IDD_CHILDTEXT,this);
			
			
		
			if(iTmp == 1)
				m_ChildText.MoveWindow(
					&CRect(rMenu[iTmp].right,
					rMenu[iTmp].top,
					rMenu[iTmp].right + 20 * width[iTmp - 1] + 20,
					rMenu[iTmp].top + 50 + 40 * typeNum[iTmp - 1]));
			else
				m_ChildText.MoveWindow(
					&CRect(rMenu[iTmp].right,
					rMenu[iTmp].top  + 30 - 20 * typeNum[iTmp - 1],
					rMenu[iTmp].right + 20 * width[iTmp - 1] + 20,
					rMenu[iTmp].top + 50 + 20 * typeNum[iTmp - 1]));
			m_ChildText.initDialog(typeNum[iTmp - 1],iTmp - 1);
			m_ChildText.ShowWindow(true);
		}
	
	}

}
*/
BOOL CWMIView::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	//当m_childText窗口存在时响应，其他事件并不影响
/*	if(m_ChildText.m_hWnd != 0)
	{
		CRect rc;
		m_ChildText.GetWindowRect(&rc);
//		CRect menu(rProcurement.left,rProcurement.top,rSet.right,rSet.bottom);

		if(rc.PtInRect(pMsg->pt) || pMsg->pt.x < rc.left)
		{
			
		}
		else 
		{
			m_ChildText.DestroyWindow();
		//	Sleep(1000);
		}

	}
	*/
	return CView::PreTranslateMessage(pMsg);
}

void CWMIView::DrawTitle(CDC *pDC)
{
	pDC->TextOut(rfTitle.left + 40,rfTitle.top + 20,CompanyName);
	pDC->TextOut(rfTitle.right - 200,rfTitle.top + 20,UserName);

}

void CWMIView::InitProgram(CString Name)
{
	SetTimer(1,20000,NULL);
	UserName =  Name;
	InvalidateRect(rfTitle);
	if(m_Parent.m_hWnd != NULL)					
	{
		m_Parent.UserName = UserName;
	}
	if(m_Title.m_hWnd != NULL)					
	{
		m_Title.UserName = UserName;
	}
	CTime t = time - CTimeSpan(1,0,0,0);
	CString strTime;
	strTime = " where 单据日期 between '" + t.Format("%Y-%m-%d") +"' and '" + time.Format("%Y-%m-%d") + "'";

	CString sql;
	sql = "select 商品编号,在库量 from inventory where 在库量 + 采购在订量 < 最低库存 and 状态 != '不可用'";
	opt = GETDATA;
	DB_excute(db,sql.GetBuffer(0),GetViewData,this);
	sql.ReleaseBuffer();
	strQueue[0].Format("%d",m_Critical.GetItemCount());

	sql = "select count(*) from dataVoucher " + strTime;
	opt = GetNum;
	DB_excute(db,sql.GetBuffer(0),GetViewData,this);
	sql.ReleaseBuffer();
	strQueue[1] = result;

	sql = "select count(*) from dataPayment " + strTime;
	opt = GetNum;
	DB_excute(db,sql.GetBuffer(0),GetViewData,this);
	sql.ReleaseBuffer();
	strQueue[2] = result;

	sql = "select count(*) from distriTrack " + strTime;
	opt = GetNum;
	DB_excute(db,sql.GetBuffer(0),GetViewData,this);
	sql.ReleaseBuffer();
	strQueue[3] = result;

	sql = "select count(*) from proTrack " + strTime;
	opt = GetNum;
	DB_excute(db,sql.GetBuffer(0),GetViewData,this);
	sql.ReleaseBuffer();
	strQueue[4] = result;

	sqlite3 *db_Info;
	DB_open(&db_Info,".\\UserData\\info.db");
	sql = "select 公司名称 from CoInfo limit 1";
	DB_excute(db_Info,sql.GetBuffer(0),GetViewData,this);
	sql.ReleaseBuffer();
	CompanyName = result;
	DB_close(db_Info);
	InvalidateRect(rfQueue);
	InvalidateRect(rfTitle);
}

CRect CWMIView::MoveRect(CRect rc, CPoint ptSta, CPoint ptEnd)
{
//	if(ptSta.x < ptEnd.x)
//	{
//		if(ptSta.y < ptEnd.y)
//		{
	return MoveRect(rc,ptEnd.x - ptSta.x,ptEnd.y - ptSta.y);
//		}
//		else
//			return 
//	}
}

void CWMIView::CloseDialog(int type)
{
	//{&m_Procurment,&m_Distribute,&m_WareHouse,&m_Manage,&m_Data,&m_Assets,&m_Set,&m_Title};
	switch(type)
	{
	case 1:		m_Procurment.ShowWindow(false);		DialogVisible = -1;	break;
	case 2:		m_Distribute.ShowWindow(false);		DialogVisible = -1;	break;
	case 3:		m_WareHouse.ShowWindow(false);		DialogVisible = -1;	break;
	case 4:		m_Manage.ShowWindow(false);			DialogVisible = -1;	break;
	case 5:		m_Data.ShowWindow(false);			DialogVisible = -1;	break;
//	case 6:		m_Assets.ShowWindow(false);			DialogVisible = -1;	break;
//	case 7:		m_Set.ShowWindow(false);			DialogVisible = -1;	break;
	case 6:		m_Set.ShowWindow(false);			DialogVisible = -1;	break;
	case 8:		m_Title.ShowWindow(false);			DialogVisible = -1;	break;
	}
}

void CWMIView::InitCriticalData(CString str)
{
	str.Empty();
}

BOOL CWMIView::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	CWnd *pWnd = FindWindow("#32770","功能模块");
	if(pWnd != NULL)
	{
		::SendMessage(pWnd->GetSafeHwnd(),WM_USER+1,0,0);
	}
	KillTimer(1);
	return CView::DestroyWindow();
}



void CWMIView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case 1:
		{
			CString sql;
			sql = "select 商品编号,在库量 from inventory where 在库量 < 最低库存";
			opt = GETDATA;
			while(m_Critical.DeleteItem(0));
			DB_excute(db,sql.GetBuffer(0),GetViewData,this);
			sql.ReleaseBuffer();
			strQueue[0].Format("%d",m_Critical.GetItemCount());
			InvalidateRect(rfQueue,true);
		}
		break;
	}
	CView::OnTimer(nIDEvent);
}
