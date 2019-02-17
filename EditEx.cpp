// EditEx.cpp : implementation file
//

#include "stdafx.h"
#include "wmi.h"
#include "EditEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditEx

CEditEx::CEditEx()
{
}

CEditEx::~CEditEx()
{
}


BEGIN_MESSAGE_MAP(CEditEx, CEdit)
	//{{AFX_MSG_MAP(CEditEx)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditEx message handlers

void CEditEx::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	GetWindowText(str);
	if (status)
	{
		if ('.' == nChar)//小数点只能输入一次
		{
			if ("" == str)
			{
				//CEdit::OnChar(nChar, nRepCnt, nFlags);
				SetWindowText("0.");
				SetSel(2, 2);
			}
			else if (-1 != str.Find('.'))
			{
			}
			else
			{
				CEdit::OnChar(nChar, nRepCnt, nFlags);
			}
		}
		//数字、backspace、delete键处理
		else if (('0' <= nChar && '9' >= nChar) || (0x08 == nChar) || (0x2E == nChar))
		{
			if (str == "0" && nChar == '0')
			{

			}
			else
				CEdit::OnChar(nChar, nRepCnt, nFlags);
		}
		else
		{
		}
	}
}

BOOL CEditEx::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (cs.style & ES_NUMBER)
		SetEditStatus(true);
	return CEdit::PreCreateWindow(cs);
}

void CEditEx::SetEditStatus(bool status)
{
	this->status = status;
}

void CEditEx::InputError()
{
//窗口抖动
	CRect rc;
	GetWindowRect(&rc);
	rc.top += 10;
	rc.bottom += 10;
	this->MoveWindow(rc);
	Sleep(50);

	rc.top -= 10;
	rc.bottom -= 10;
	this->MoveWindow(rc);
	Sleep(50);

	rc.top += 10;
	rc.bottom += 10;
	this->MoveWindow(rc);
	Sleep(50);

	rc.top -= 10;
	rc.bottom -= 10;
	this->MoveWindow(rc);
	Sleep(50);

	rc.top += 10;
	rc.bottom += 10;
	this->MoveWindow(rc);
	Sleep(50);

	rc.top -= 10;
	rc.bottom -= 10;
	this->MoveWindow(rc);

	this->SetFocus();
}
