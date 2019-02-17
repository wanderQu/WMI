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
	UINT	listName; //list name:like �ɹ��������ɹ���ϸ
	char	compName[100]; //company name
	char	printer[100];//who operate
	char	dateTime[100];//when:��ʽ where between
	char	object[100];//who ����ʽ and who = ,if null,object = NULL
	char	fileName[MAX_PATH];
}COPYDATA, *PCOPYDATA;

//PDFLib��ӡ�����optList
typedef struct tagOptList
{
	int			fontSize;	//�����С
	float		lineSpace; //�о� eg:2���о�
							//			0.5��fontsize�߶�
							// ����		1.0��fontsize�߶�
							//			0.5��fontsize�߶�

			//��Ӧ�� boxsize.width = fontLenth * fontsize / 2;
			//		 boxsize.height = fontsize * lineSpace;

			//��Ӧ�� fontStyle = left center;
//	RECT		boxSize;
	int			boxWidth;
	int			boxHeight;
	bool		showBorder;
	TextStyle	textStyle;
}OPTLIST,*POPTLIST;

//PcdData �����ںͽ�ɫ��λ��
typedef struct tagPcdIndex
{
	int			time;	//pcd->data��ʱ���λ��,���û����Ϊ-1��
	int			obj;	//pcd->data�ж����λ��,���û����Ϊ-1��
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

	void	InitPDF();			//��ʼ��PDFLib����ַ���ļ���
	void	PrintOrderNumber(wstring obj = L"",wstring time = L"");	//��ӡ���ݱ��
	void	PrintTitle();		//��ӡ��ͷ����˾����/��������
	void	PrintListHead(size_t, size_t);	//��ӡ�б�ͷ
	void	PrintList(size_t, size_t);		//��ӡ�б�����
	void	PrintExtra(size_t sta, size_t end);		//��ӡ������Щ
	void	PrintTime();		//��ӡ��ӡʱ��ɶ��
	void	PrintChrac();		//��ӡ���˭��ӡ�ģ�˭���etc
	void	PrintPage();		//��ӡҳ��

	void	GetData();			//��ȡ��ѯ���

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
	wostringstream				strBuf;	//��ӡ���ݵĻ���
	wostringstream				optBuf;	//optlist���ݵĻ���
	vector<wstring>::iterator	it;

private://sqlite3 operator
	sqlite3						*db;

private://about PCD information	
	PCOPYDATA					pcd;
	PPCDINDEX					pPcdIndex;

private://others
	SYSTEMTIME					tm;
	
};