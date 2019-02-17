#pragma once
#include "stdafx.h"
#include<iostream>
#include<vector>
#include<time.h>
#include ".\\include\\pdflib.hpp"
#pragma comment(lib,".\\libary\\pdflib")
#include".\\include\\sqlite_dll.h"
#pragma comment(lib,".\\libary\\sqlite_dll.lib")
using namespace std;
using namespace pdflib;

enum ListName
{
	proOrder,
	proDetails,
	proReturn,

	distriOrder,
	distriDetails,
	distriReturn,

	wareIn,
	wareOut,
	wareStock,
	wareAdjust,

	dataRecv,
	dataPay,
	dataRecable,
	dataPayable,
	dataOtherIn,
	dataOtherOut
};
enum Opt
{
	Normal,
	Specific
};

enum Charac
{
	Customer,
	Supplier,
	Employee,
	Warehouse,
	Goods,
	Money
};
enum TextStyle
{
	Left_Top,
	Left_Center,
	Left_Bottom,
	Right_Top,
	Right_Center,
	Right_Bottom,
	Center_Top,
	Center_Center,
	Center_Bottom,
	Auto_Fit
};
typedef struct tagCOPYDATA
{
	UINT	listName; //list name:like 采购订单？采购明细
	char	compName[100]; //company name
	char	printer[100];//who operate
	char	dateTime[100];//when:格式 where between
	char	object[100];//who ：格式 and who = ,if null,object = NULL
	char	fileName[MAX_PATH];
}COPYDATA, *PCOPYDATA;

//PDFLib打印所需的optList
typedef struct tagOptList
{
	int			fontSize;	//字体大小
	float		lineSpace; //行距 eg:2倍行距
							//			0.5倍fontsize高度
							// 文字		1.0倍fontsize高度
							//			0.5倍fontsize高度

			//对应的 boxsize.width = fontLenth * fontsize / 2;
			//		 boxsize.height = fontsize * lineSpace;

			//对应的 fontStyle = left center;
//	RECT		boxSize;
	int			boxWidth;
	int			boxHeight;
	bool		showBorder;
	TextStyle	textStyle;
}OPTLIST,*POPTLIST;

//PcdData 中日期和角色的位置
typedef struct tagPcdIndex
{
	int			time;	//pcd->data中时间的位置,如果没有则为-1；
	int			obj;	//pcd->data中对象的位置,如果没有则为-1；
	Charac		objType;
}PCDINDEX,*PPCDINDEX;

int 
GetData(
	void*, int argc, char**argv, char**column);

//utf-8 to unicode
wstring 
UTF_8ToUnicode(
	const char* str);

//ascii to unicode
wstring
ASCIIToUnicode(
	const char* str);

wstring
UpperNumber_zh_CN(
	double num, wstring Number);
class WMPrinter
{
public:
	WMPrinter();
	~WMPrinter();
public:
	BOOL	StartPrint(PCOPYDATA);
	void	ShutDownLocal();
	void	Insert_UTF_8_Data(const char* str, size_t item, size_t col);
	void	Insert_ASCII_Data(const char* str, size_t item, size_t col);
	void	Print(size_t, size_t);
	wstring ResetTime(wstring, bool needTime = false);
protected:

	void	InitPDF();			//初始化PDFLib：地址及文件名
	void	PrintOrderNumber(wstring obj = L"",wstring time = L"");	//打印单据编号
	void	PrintTitle();		//打印表单头：公司名称/单据名称
	void	PrintListHead(size_t, size_t);	//打印列表头
	void	PrintList(size_t, size_t);		//打印列表数据
	void	PrintExtra(size_t sta, size_t end);		//打印条例哪些
	void	PrintTime();		//打印打印时间啥的
	void	PrintChrac();		//打印人物：谁打印的，谁审核etc
	void	PrintPage();		//打印页码

	void	GetData();			//获取查询语句

	void	SetOptList(int fontSize,int boxWidth,bool showBorder, 
		TextStyle textStyle, float lineSpace = 1.5);
	wstring	GetOptList();

public:
	vector<vector<wstring>>		data;

private://about PDF printer
	int							fontThin;
	int							fontBold;
	int							pageWidth;
	int							pageHeight;
	int							pageMarginsX;
	int							pageMarginsY;
	int							list;
	int							listNeed;
	int							page;

	RECT						rc;
	POINT						point;
	PDFlib						pdf;
	OPTLIST						optList;
	vector<size_t>				textSize;

private://about string/wstring
	string						sql;
	wstring						time;
	wstring						obj;
	wstring						listName;
	wstring						tmp;
	wstring						result;
	wostringstream				strBuf;	//打印数据的缓冲
	wostringstream				optBuf;	//optlist数据的缓冲
	vector<wstring>::iterator	it;

private://sqlite3 operator
	sqlite3						*db;

private://about PCD information	
	PCOPYDATA					pcd;
	PPCDINDEX					pPcdIndex;

private://others
	SYSTEMTIME					tm;
	
};