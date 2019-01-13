// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� ELEMENTS_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// ELEMENTS_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
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
	// TODO:  �ڴ�������ķ�����
	virtual CPen*	GetPen(int size, int type, COLORREF color);

	virtual CBrush* GetBrush(COLORREF color);

	virtual CFont*	GetFont(int size, UINT type = SongTi);
	virtual CFont*	GetFont(int size, CString strFont = L"����");
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


