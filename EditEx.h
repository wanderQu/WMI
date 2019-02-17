#if !defined(AFX_EDITEX_H__5A00BDF0_B82D_44E1_84B9_D5BC7D18CD82__INCLUDED_)
#define AFX_EDITEX_H__5A00BDF0_B82D_44E1_84B9_D5BC7D18CD82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditEx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditEx window

class CEditEx : public CEdit
{
// Construction
public:
	CEditEx();

private:
	bool	status;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditEx)
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	void InputError();
	void SetEditStatus(bool status);
	virtual ~CEditEx();

	// Generated message map functions
protected:
	//{{AFX_MSG(CEditEx)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITEX_H__5A00BDF0_B82D_44E1_84B9_D5BC7D18CD82__INCLUDED_)
