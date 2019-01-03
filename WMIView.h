// WMIView.h : interface of the CWMIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WMIVIEW_H__EEE55C47_5770_40A7_AE22_3E6F9D20B91C__INCLUDED_)
#define AFX_WMIVIEW_H__EEE55C47_5770_40A7_AE22_3E6F9D20B91C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef _DEBUG // 内存泄漏检测支持。
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <malloc.h>    // 解决 malloc.h 与 crtdbg.h 顺序导致的 Debug Assertion Failed, "Corrupted pointer passed to _freea" 。
#include <crtdbg.h>
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG


#include "MyRes.h"
#include "Data.h"
#include "Distribute.h"
#include "Manage.h"
#include "Procurment.h"
#include "Set.h"
#include "Title.h"
#include "WareHouse.h"
#include "Log.h"
#include "ExternParent.h"

#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
//#include "Title.h"

class CWMIView : public CView
{
protected: // create from serialization only
	CWMIView();
	DECLARE_DYNCREATE(CWMIView)

// Attributes
public:
	CWMIDoc* GetDocument();	
	int				opt;
	CListCtrl		m_Critical;
	CString			result;
//	CBitmap tmpBitmap;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWMIView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL DestroyWindow();
	//}}AFX_VIRTUAL
	
// Implementation
public:
	void InitCriticalData(CString);
	void CloseDialog(int);

	virtual void InitProgram(CString);
	
//	virtual void PointOnMenu(int iTmp);
	virtual CRect CutRect(CRect rect,int top,int bottom,int left,int right);//剪裁矩形选区
	virtual CRect MoveRect(CRect rect, int xDistance,int yDistance);		//移动矩形选区
	virtual CRect MoveRect(CRect rc,CPoint ptSta,CPoint ptEnd);				//移动矩形区域，从矩形中的某个点移动到另一个点
	virtual CRect DrawXY(CDC *pDC);											//画坐标，及其表示
	virtual void SetAnnounce(CString str);									//设置公告内容
	virtual CRect DrawReport(CDC *pDC);										//出入库折线图
	virtual void DrawTitle(CDC *pDC);										//“标题栏”
	virtual void DrawQueue(CDC *pDC,unsigned percent);						//待处理业务
	virtual void DrawFounction(CDC *pDC);									//常用功能
	virtual void DrawAnnounce(CDC *pDC);									//公告
	virtual void DrawFounct(CDC *pDC);										//画功能区的边框
	virtual void InitFunctionRect();										//初始化功能区
	virtual void InitMenuRect();											//初始化菜单区
	virtual void DrawMenu(CDC *pDCp);										//绘制菜单区


	virtual ~CWMIView();
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
//将整个界面进行分区，后续操作就对这些区域进行操作就行
	CRect			rMenu[9];			//菜单区域
//	CRect rHome;						//首页
//	CRect rLogo;						//Logo
//	CRect rProcurement;					//采购
//	CRect rDistribution;				//配送
//	CRect rWareHouse;					//仓库
//	CRect rManagement;					//管理
//	CRect rData;						//资料
//	CRect rReport;						//资产报表
//	CRect rSet;							//设置
//	CRect rRest;						//菜单剩余区域

	CRect			rfAnnounce;			//公告
	CRect			rfQueue;			//待处理业务
	CRect			rfReport;			//支出折线
	CRect			rfRest;				//除了菜单外的区域,也是每次重绘刷新的区域
	CRect			rfFounction;		//功能设置
	CRect			rfTitle;			//标题栏区

//是否是首页,方便首页的绘图
	int				DialogVisible;
//	bool  ProcurementIsOn;
//	bool  DistributionIsOn;
//	bool  WareHouseIsOn;				//仓库
//	bool  ManagementIsOn;				//管理
//	bool  DataIsOn;						//资料
//	bool  ReportIsOn;					//资产报表
//	bool  SetIsOn;	

//	enum {mLogo = 0,mProcurment = 1,mDistribution,mWarehouse,mManagement,mData,mReport,mSet, //菜单
//			title,																			//标题栏
//			fQueue,fReport,fAnnounce,fFounction												//功能区
//		}pointAt;	
//	int pointAt;
//	int lastPoint;
//获取今天的日期,用处：绘制最近配送量
//GetDay()\GetMonth()\GetYear()获取日、月、年
	CTime			time;
//	CString			tm_Day,tm_Year,tm_Month;

//保存默认字体
	CFont			cfont;

//保存窗口大小
	CRect			rClient;

//公告内容
	CString			Announce;

//坐标精度
	int				iNum;

//各种窗口对象
	CProcurment		m_Procurment;		//采购
	CDistribute		m_Distribute;		//配送
	CManage			m_Manage;			//管理
	CWareHouse		m_WareHouse;		//仓库
	CSet			m_Set;				//设置
	CData			m_Data;				//资料
//	CAssets			m_Assets;			//报表
	CTitle			m_Title;			//标题
	CLog			m_Log;				//登录

	CExternParent	m_Parent;
//	CDialog	    **pDialog;
	CRect			rc[8];				//可点击区域
	//控件

	CImageList		m_SetLogo;
//	ChildText	m_ChildText;		//首页菜单子选项
//	Person		m_person;
//	Title       m_Title;

	CString			CompanyName;
	CString			UserName;
	
	CString			strQueue[5];
	CWnd*			Parent;
// Generated message map functions
	sqlite3			*db;


protected:
	//{{AFX_MSG(CWMIView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	
};

#ifndef _DEBUG  // debug version in WMIView.cpp
inline CWMIDoc* CWMIView::GetDocument()
   { return (CWMIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WMIVIEW_H__EEE55C47_5770_40A7_AE22_3E6F9D20B91C__INCLUDED_)
