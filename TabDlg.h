#if !defined(AFX_TABDLG_H__07AAD9AB_84B8_4E10_A082_2BB78983486B__INCLUDED_)
#define AFX_TABDLG_H__07AAD9AB_84B8_4E10_A082_2BB78983486B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TabDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTabDlg dialog

class CTabDlg : public CDialog
{
// Construction
public:
	CTabDlg(CWnd* pParent = NULL);   // standard constructor
//
//	CEdit			m_edit;
//	CButton			m_bt[6]; //查询、打印、导出、新增、删除，列表设置
//	CStatic			m_tx[9]; //客户类别、客户、供应商类别、供应商、-、单据日期：总计1，总计2、时间
//	CListCtrl		m_ls[2]; //最上面一个、最下面
//	CDateTimeCtrl	m_tm[2]; //开始、结束
// Dialog Data
	//{{AFX_DATA(CTabDlg)
	enum { IDD = IDD_TABDLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTabDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABDLG_H__07AAD9AB_84B8_4E10_A082_2BB78983486B__INCLUDED_)
