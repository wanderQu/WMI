// DialogNode.cpp : implementation file
//

#include "stdafx.h"
#include "WMI.h"
#include "DialogNode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogNode

CDialogNode::CDialogNode()
{
	info = 0;
	next = 0;
}

CDialogNode::~CDialogNode()
{
}


BEGIN_MESSAGE_MAP(CDialogNode, CWnd)
	//{{AFX_MSG_MAP(CDialogNode)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDialogNode message handlers

CWnd* CDialogNode::Get()
{
	return info;
}
