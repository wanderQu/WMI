#if !defined(AFX_DIALOGADD_H__71B284FF_17A2_4A8F_9D43_C164D2A064B3__INCLUDED_)
#define AFX_DIALOGADD_H__71B284FF_17A2_4A8F_9D43_C164D2A064B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogAdd.h : header file
//
#include ".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
/////////////////////////////////////////////////////////////////////////////
// CDialogAdd dialog
#include <AfxTempl.h> //carray head file

class CDialogAdd : public CDialog
{
// Construction
public:
	void AutoInsertInfo();
	CDialogAdd(CWnd* pParent = NULL);   // standard constructor

public:
	void DeleteAll();
	void Excute();
	CString ProTrack(CString,CString str1,CString str2);
	CString	tbName;
	void CheckState();
	void SetListWidth(CString str,int col);

	CWnd			*pWnd;

/****************** Control *************************/
	CEdit			m_Edit;
	CComboBox		m_Comb;

/*************** Control Rect ***********************/
	CRect			rcEdit;

/******************* param **************************/
	bool			isEdit;			// list is in editing?

	int				isListEmpty;	// == 0: list is empty, and need to "paint" a "+" in (0,0);
									// > 0 : list is not empty,now it is the item`s total num;
									// and this value is the "+" locat pos

	CPoint			ptClick;		// save the last clicked point, if clicked anywhere,but is editing
									// default is to set List Text,then move to clicked just now

//	int				list[20];		//to save that where is edit or not;because the list item number is dynamic changed
//									//so ,the list array room is requset at out of this file,request at who called
//									//and also delete at outside 
	int				column;			//record the column number
	int				item;			//save the list item number 

	CRect			rcTemp;
	CString			strTemp;

	bool			isDate;
	CString			*SQL;
	int				ctrlSql;

// Dialog Data
	//{{AFX_DATA(CDialogAdd)
	enum { IDD = IDD_DIALOG_ADD };
	CListCtrl	m_Ls;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogAdd)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogAdd)
	afx_msg void OnClose();
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDelete();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGADD_H__71B284FF_17A2_4A8F_9D43_C164D2A064B3__INCLUDED_)
