// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 ELEMENTS_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// ELEMENTS_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef ELEMENTS_EXPORTS
#define ELEMENTS_API __declspec(dllexport)
#else
#define ELEMENTS_API __declspec(dllimport)
#endif
#pragma once

//font style
ELEMENTS_API enum{
	SongTi,
	HeiTi
};

//values of textPos
#define CENTER	0x001
#define LEFT	0x002
#define	RIGHT	0x003
#define TOP		0x004
#define BUTTOM	0x005

//the rect
ELEMENTS_API typedef struct TagCRectEx
{
	CRect		rect;
	CString		buffer;
	COLORREF	color;
	UINT		alignment;
	CString		imagePath;
}CRECT,*PCRECT;

//GDI object to print the view 
class CObjectOpt {
public:
	CObjectOpt(void);
	virtual ~CObjectOpt(void);
	// TODO:  在此添加您的方法。
	virtual CPen*	GetPen(int size, int type, COLORREF color);

	virtual CBrush* GetBrush(COLORREF color);

	virtual CFont*	GetFont(int size, UINT type = SongTi);
	virtual CFont*	GetFont(int size, CString strFont = L"宋体");
	virtual void	Release();

private:
	CGdiObject*		bufObject;
};

// CEDitEx

class ELEMENTS_API CEditEx : public CEdit
{
	DECLARE_DYNAMIC(CEditEx)

public:
	CEditEx();
	virtual ~CEditEx();

private:
	bool	status;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void SetEditStatus(bool status);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void InputError();
};


