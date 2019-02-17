#if !defined(AFX_EXTERNPARENT_H__32807AFB_4300_4FBE_9138_D2EFE24C1000__INCLUDED_)
#define AFX_EXTERNPARENT_H__32807AFB_4300_4FBE_9138_D2EFE24C1000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExternParent.h : header file
//

#define WM_CREATE_WND WM_USER + 100

#include <AfxTempl.h> //carray head file
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
//	 0		1		2		3	  4		5
//	edit->combo->button->text->time->list
#define ed		0
#define cb		1
#define bt		2
#define	tx		3
#define tm		4
#define ls		5
#include "DialogAdd.h"
#include "excel.h"
#include "AddOrder.h"
#include "AddDistri.h"
#include "harac.h"//charactor
#include "AddOtherIn.h"
#include "AddOtherOut.h"
#include "AddGood.h"
#include "AddPay.h"
#include "AddRecv.h"
#include "AddDistriReturn.h"
#include "AddProReturn.h"
#include "WareIn.h"
#include "WareOut.h"
#include "AddWareAdj.h"
#include "ShareMemory.h"
/////////////////////////////////////////////////////////////////////////////
// CExternParent dialog

class CExternParent : public CDialog
{
// Construction
public:
	void CreateWareStock(CRect rc);
	void CreateWareOut(CRect rc);
	void CreateWareIn(CRect rc);
	void CreateWareChng(CRect rc);
	void CreateSetLog(CRect rc);
	void CreateSetPermis(CRect rc);
	void CreateProTrack(CRect rc);
	void CreateProReturn(CRect rc);
	void CreateProOrder(CRect rc);
	void CreateManaWare(CRect rc);
	void CreateManaGoods(CRect rc);
	void CreateManaSup(CRect rc);
	void CreateManaCus(CRect rc);
	void CreateManaAddress(CRect rc);
	void CreateDistriTrack(CRect rc);
	void CreateDistriLs(CRect rc);

	void CreateDataVoucher(CRect rc);
//	void CreateDataTransfer(CRect rc);
	void CreateDataPayment(CRect rc);
	void CreateDataOtherIncome(CRect rc);
	void CreateDataOtherExpend(CRect rc);


	void DealMessage(WPARAM wParam,LPARAM lParam);
	CExternParent(CWnd* pParent = NULL);   // standard constructor

public:
	CFont				*m_font;
	int					count;
	CRect				m_TabRc;
	CString				PageName;
//	CDialog				*pDialog[35];
//	UINT				DialogID[35];
//	CDialog				*pTmpDlg; //上一个显示的窗口
	
	int					thisPos;
//	CTabDlg				*m_Child;
	DWORD				dwEdStyle;		//edit style
	UINT				edID;

	DWORD				dwTxStyle;	//cstatic style
	UINT				txID;

	DWORD				dwCbStyle;		//combo style
	UINT				cbID;

	DWORD				dwTmStyle;		//time style
	UINT				tmID;

	DWORD				dwLsStyle;		//list style
	UINT				lsID;

	DWORD				dwBtStyle;		//button style
	UINT				btID;

//储存当前控件的数量，如果小于之前的控件数量就调用ShowWindow，如果大于就create
	int					iTemp[6];		//如果对应iCtrl的值大于iTemp就调用create，反之调用GetDlgItem(ID)->ShowWindow(true)
										//在切换窗口时，要重置，炸窗口关闭时重置清空
	
//储存当前每个控件的数量，方便ID管理。在运行中创建控件，窗口切换中在后台显示，需要时调用
	int					iCtrl[6];		//如果对应iTemp的值小于iCtrl就调用GetDlgItem(ID)->ShowWindow(true)，反之调用Create
										//在切换窗口时，不重置，在窗口关闭时重置清空

//储存每个窗口所有控件的ID，方便之后管理
	CArray<UINT,UINT>	uCtrl;			//每次ShowWindow或者Create时，将该ID储存起来
										//在切换窗口时，遍历uCtrl获取控件ID，然后调用GetDlgItem(ID)->ShowWindow(false);

//窗口的代号容器,窗口的所在位置	
	CArray<int,int>		iDialog;

	sqlite3				*db;
	sqlite3				*db_ls;

	CEdit				*m_ed;
	CStatic				*m_tx;
	CButton				*m_bt;
	CComboBox			*m_cb;
	CListCtrl			*m_ls;
	CDateTimeCtrl		*m_tm;

	CString				tbName;
	CString				searchString;
	CString				searchMoney;
	UINT				lsNameNumber;
	UINT				lsHeadNumber;		
	bool				isDesc;
	CShareMemory		csm;

	bool				isDate;
	CString				UserName;
	int					opt;
	CString				sql;
	CString				result;
	bool				HaveTime;
	CString				CompanyName;
// Dialog Data
	//{{AFX_DATA(CExternParent)
	enum { IDD = IDD_EXTERN_PARENT };
	CTabCtrl	m_Tab;

	//}}AFX_DATA
public:
	void CreateDataPayable(CRect rc);
	void CreateDataReceivable(CRect rc);
	void CreateManaEmployees(CRect rc);
	void CreateDistriReturn(CRect rc);
	void Query();
	void PutOut();
	CString GetLsHeadText(int i,CListCtrl*);
	void CopyLsData(CListCtrl *dest,CListCtrl *src);
	int Show(int i);
	CRect MoveRect(CRect rc,int l ,int t,int r,int b);
	void CreateTx(CString strText,CRect rc);
	void CreateTm(CString strText,CRect rc);
	void CreateCb(CString strText,CRect rc);
	void CreateBt(CString strText,CRect rc);
	void CreateLs(CString strText,CRect rc);
	void CreateEd(CString strText,CRect rc);


	void MoveWnd(CWnd* wd,int l,int t);
	int GetDlgPos(int n);
	enum ListName
	{
		proOrder,
		proDetails,
		proReturn,

		distriOrder,
		distriDetails,
		distriReturn,

		wareIn,
		wareOut,
		wareStock,
		wareAdjust,

		dataRecv,
		dataPay,
		dataRecable,
		dataPayable,
		dataOtherIn,
		dataOtherOut
	};
	typedef struct tagCOPYDATA
	{
		UINT	listName; //list name:like 采购订单？采购明细
		char	compName[100]; //company name
		char	printer[100];//who operate
		char	dateTime[100];//when:格式 where between
		char	object[100];//who ：格式 and who = ,if null,object = NULL
		char	fileName[MAX_PATH];
	}COPYDATA, *PCOPYDATA;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExternParent)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(CExternParent)
	afx_msg void OnRclickTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	afx_msg void OnBtClick(UINT);
	afx_msg void OnDropdownCombo1(UINT);
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT Exit(WPARAM wParam,LPARAM lParam);
	afx_msg void OnColumnclickList2(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
};
static int CreateCtrl(void *data,int argc,char **argv,char **azColName);
static int CompetLs(void *data,int argc,char **argv,char **colum);

//static int CreateCtrl(void *data,int argc,char **argv,char **azColName);
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXTERNPARENT_H__32807AFB_4300_4FBE_9138_D2EFE24C1000__INCLUDED_)
