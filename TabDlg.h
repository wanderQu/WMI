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
//	CButton			m_bt[6]; //��ѯ����ӡ��������������ɾ�����б�����
//	CStatic			m_tx[9]; //�ͻ���𡢿ͻ�����Ӧ����𡢹�Ӧ�̡�-���������ڣ��ܼ�1���ܼ�2��ʱ��
//	CListCtrl		m_ls[2]; //������һ����������
//	CDateTimeCtrl	m_tm[2]; //��ʼ������
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
