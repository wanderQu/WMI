// WMIDoc.cpp : implementation of the CWMIDoc class
//

#include "stdafx.h"
#include "WMI.h"

#include "WMIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWMIDoc

IMPLEMENT_DYNCREATE(CWMIDoc, CDocument)

BEGIN_MESSAGE_MAP(CWMIDoc, CDocument)
	//{{AFX_MSG_MAP(CWMIDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWMIDoc construction/destruction

CWMIDoc::CWMIDoc()
{
	// TODO: add one-time construction code here

}

CWMIDoc::~CWMIDoc()
{
}

BOOL CWMIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
//	SetTitle("小蘑菇供应商库存管理系统");
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWMIDoc serialization

void CWMIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWMIDoc diagnostics

#ifdef _DEBUG
void CWMIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWMIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWMIDoc commands
