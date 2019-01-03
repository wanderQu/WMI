// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "WMI.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.hMenu = NULL;
	cs.style &= ~WS_THICKFRAME; //去除可改变大小的边框
	cs.style |= WS_DLGFRAME; //增加不能改变大小的边框
//	cs.style &= WS_MAXIMIZE;
//	cs.style &= WS_CAPTION;
	//设置单文档标题
	cs.style &=~FWS_ADDTOTITLE;
	cs.lpszName = "小蘑菇库存管理系统";

	int cxScreen = ::GetSystemMetrics(SM_CXSCREEN);
	int cyScreen = ::GetSystemMetrics(SM_CYSCREEN);

//	CRect rect;
//	::GetWindowRect(NULL,&rect);

//	cs.x  = 60;
//	cs.y  = 40;
	cs.cy = 800;
	cs.cx = 1400;
//	cs.x = (rect.Width() - cs.cx) / 2;
//	cs.y = (rect.Height() - cs.cy) / 2;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

