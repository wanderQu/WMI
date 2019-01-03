// AssertExpense.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "AssertExpense.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAssertExpense dialog


CAssertExpense::CAssertExpense(CWnd* pParent /*=NULL*/)
	: CDialog(CAssertExpense::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAssertExpense)
	//}}AFX_DATA_INIT
//	strInfo = "支出报表";

}


void CAssertExpense::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAssertExpense)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAssertExpense, CDialog)
	//{{AFX_MSG_MAP(CAssertExpense)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAssertExpense message handlers
