// WMIView.h : interface of the CWMIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WMIVIEW_H__EEE55C47_5770_40A7_AE22_3E6F9D20B91C__INCLUDED_)
#define AFX_WMIVIEW_H__EEE55C47_5770_40A7_AE22_3E6F9D20B91C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef _DEBUG // �ڴ�й©���֧�֡�
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <malloc.h>    // ��� malloc.h �� crtdbg.h ˳���µ� Debug Assertion Failed, "Corrupted pointer passed to _freea" ��
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
	virtual CRect CutRect(CRect rect,int top,int bottom,int left,int right);//���þ���ѡ��
	virtual CRect MoveRect(CRect rect, int xDistance,int yDistance);		//�ƶ�����ѡ��
	virtual CRect MoveRect(CRect rc,CPoint ptSta,CPoint ptEnd);				//�ƶ��������򣬴Ӿ����е�ĳ�����ƶ�����һ����
	virtual CRect DrawXY(CDC *pDC);											//�����꣬�����ʾ
	virtual void SetAnnounce(CString str);									//���ù�������
	virtual CRect DrawReport(CDC *pDC);										//���������ͼ
	virtual void DrawTitle(CDC *pDC);										//����������
	virtual void DrawQueue(CDC *pDC,unsigned percent);						//������ҵ��
	virtual void DrawFounction(CDC *pDC);									//���ù���
	virtual void DrawAnnounce(CDC *pDC);									//����
	virtual void DrawFounct(CDC *pDC);										//���������ı߿�
	virtual void InitFunctionRect();										//��ʼ��������
	virtual void InitMenuRect();											//��ʼ���˵���
	virtual void DrawMenu(CDC *pDCp);										//���Ʋ˵���


	virtual ~CWMIView();
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
//������������з��������������Ͷ���Щ������в�������
	CRect			rMenu[9];			//�˵�����
//	CRect rHome;						//��ҳ
//	CRect rLogo;						//Logo
//	CRect rProcurement;					//�ɹ�
//	CRect rDistribution;				//����
//	CRect rWareHouse;					//�ֿ�
//	CRect rManagement;					//����
//	CRect rData;						//����
//	CRect rReport;						//�ʲ�����
//	CRect rSet;							//����
//	CRect rRest;						//�˵�ʣ������

	CRect			rfAnnounce;			//����
	CRect			rfQueue;			//������ҵ��
	CRect			rfReport;			//֧������
	CRect			rfRest;				//���˲˵��������,Ҳ��ÿ���ػ�ˢ�µ�����
	CRect			rfFounction;		//��������
	CRect			rfTitle;			//��������

//�Ƿ�����ҳ,������ҳ�Ļ�ͼ
	int				DialogVisible;
//	bool  ProcurementIsOn;
//	bool  DistributionIsOn;
//	bool  WareHouseIsOn;				//�ֿ�
//	bool  ManagementIsOn;				//����
//	bool  DataIsOn;						//����
//	bool  ReportIsOn;					//�ʲ�����
//	bool  SetIsOn;	

//	enum {mLogo = 0,mProcurment = 1,mDistribution,mWarehouse,mManagement,mData,mReport,mSet, //�˵�
//			title,																			//������
//			fQueue,fReport,fAnnounce,fFounction												//������
//		}pointAt;	
//	int pointAt;
//	int lastPoint;
//��ȡ���������,�ô����������������
//GetDay()\GetMonth()\GetYear()��ȡ�ա��¡���
	CTime			time;
//	CString			tm_Day,tm_Year,tm_Month;

//����Ĭ������
	CFont			cfont;

//���洰�ڴ�С
	CRect			rClient;

//��������
	CString			Announce;

//���꾫��
	int				iNum;

//���ִ��ڶ���
	CProcurment		m_Procurment;		//�ɹ�
	CDistribute		m_Distribute;		//����
	CManage			m_Manage;			//����
	CWareHouse		m_WareHouse;		//�ֿ�
	CSet			m_Set;				//����
	CData			m_Data;				//����
//	CAssets			m_Assets;			//����
	CTitle			m_Title;			//����
	CLog			m_Log;				//��¼

	CExternParent	m_Parent;
//	CDialog	    **pDialog;
	CRect			rc[8];				//�ɵ������
	//�ؼ�

	CImageList		m_SetLogo;
//	ChildText	m_ChildText;		//��ҳ�˵���ѡ��
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
