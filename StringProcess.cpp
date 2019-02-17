#include "stdafx.h"
#include"StringProcess.h"
wstring AsciiToUnicode(const string& str) {
	// 预算-缓冲区中宽字节的长度    
	int unicodeLen = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, nullptr, 0);
	// 给指向缓冲区的指针变量分配内存    
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);
	// 开始向缓冲区转换字节    
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, pUnicode, unicodeLen);
	wstring ret_str = pUnicode;
	free(pUnicode);
	return ret_str;
}
string UnicodeToAscii(const wstring& wstr) {
	// 预算-缓冲区中多字节的长度    
	int ansiiLen = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	// 给指向缓冲区的指针变量分配内存    
	char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);
	// 开始向缓冲区转换字节    
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);
	string ret_str = pAssii;
	free(pAssii);
	return ret_str;
}
wstring Utf8ToUnicode(const string& str) {
	// 预算-缓冲区中宽字节的长度    
	int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
	// 给指向缓冲区的指针变量分配内存    
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);
	// 开始向缓冲区转换字节    
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, pUnicode, unicodeLen);
	wstring ret_str = pUnicode;
	free(pUnicode);
	return ret_str;
}
string UnicodeToUtf8(const wstring& wstr) {
	// 预算-缓冲区中多字节的长度    
	int ansiiLen = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	// 给指向缓冲区的指针变量分配内存    
	char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);
	// 开始向缓冲区转换字节    
	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);
	string ret_str = pAssii;
	free(pAssii);
	return ret_str;
}
string AsciiToUtf8(const string& str) {
	return UnicodeToUtf8(AsciiToUnicode(str));
}
string Utf8ToAscii(const string& str) {
	return UnicodeToAscii(Utf8ToUnicode(str));
}

// string 与 Int 互转  
int StringToInt(const string& str) {
	return atoi(str.c_str());
}
string IntToString(int i) {
	char ch[1024];
	memset(ch, 0, 1024);
	sprintf_s(ch, sizeof(ch), "%d", i);
	return ch;
}
string IntToString(char i) {
	char ch[1024];
	memset(ch, 0, 1024);
	sprintf_s(ch, sizeof(ch), "%c", i);
	return ch;
}
string IntToString(double i) {
	char ch[1024];
	memset(ch, 0, 1024);
	sprintf_s(ch, sizeof(ch), "%f", i);
	return ch;
}

wstring UpperNumber_zh_CN_Unicode(double num)
{
	wstring Upper[] = { L"零", L"壹", L"贰", L"叁", L"肆",
		L"伍", L"陆", L"柒", L"捌", L"玖" };//10
	wstring	Unit[] = { L"分", L"角", L"圆", L"", L"十",
		L"百", L"千", L"万", L"十万", L"百万",
		L"千万", L"亿", L"十亿", L"百亿", L"千亿",
		L"万亿" };
	wstring Number;
	//eg:1005007.02
	wstring number;
	char tNumber[20];
	sprintf(tNumber, "%.2f", num);
	number = AsciiToUnicode(tNumber);
	if (number == L"0.00")
	{
		Number = L"人民币 零圆";
		return Number;
	}
	for (size_t i = 0; i < number.size(); i++)
	{
		switch (number.at(i))
		{
		case '.':
			//Number += Upper[0];
			Number += Unit[number.size() - i - 1];
			break;
		case '0':
			Number += Upper[0];
			break;
		case '1':
			Number += Upper[1];
			Number += Unit[number.size() - i - 1];
			break;
		case '2':
			Number += Upper[2];
			Number += Unit[number.size() - i - 1];
			break;
		case '3':
			Number += Upper[3];
			Number += Unit[number.size() - i - 1];
			break;
		case '4':
			Number += Upper[4];
			Number += Unit[number.size() - i - 1];
			break;
		case '5':
			Number += Upper[5];
			Number += Unit[number.size() - i - 1];
			break;
		case '6':
			Number += Upper[6];
			Number += Unit[number.size() - i - 1];
			break;
		case '7':
			Number += Upper[7];
			Number += Unit[number.size() - i - 1];
			break;
		case '8':
			Number += Upper[8];
			Number += Unit[number.size() - i - 1];
			break;
		case '9':
			Number += Upper[9];
			Number += Unit[number.size() - i - 1];
			break;
		default:
			break;
		}
	}
	//eg:1005007.02
	//eg:壹百万零零伍千零零柒圆零贰分
	//							去掉多余的零
	//规则：
	//	整数位只有最后一个零有效，当没有小数的时候，最后一位需要加‘整’
	//	小数位由于位数限制为两位，所以不影响
	//	整数位、小数位分别只有一个零，没有零点零
	//basic_string& erase(size_type pos = 0, size_type len = npos);
	int pos = -1;
	bool isBitZero = false;
	int tPos = Number.find_first_of(L"圆");
	number = Number.substr(0, tPos);
	//如果个位是零，那么个位前面连续的零都应该被删除
	//如果前面第一个非零值前面第一个零应作为有效位零，且删除个位的零
	int i = tPos - 1;
	if (number.at(i) == Upper[0].at(0))
	{
		isBitZero = true;
		//去掉个位前连续的零，包括个位
		for (; i >= 0; i--)
		{
			if (number.at(i) == Upper[0].at(0))
			{
				number.erase(i, 1);
				Number.erase(i, 1);
			}
			else//如果不是零，那就是第一位非零值，不操作
			{
				isBitZero = false;
				break;//跳出这个循环
			}
		}
	}
	//遇到的第一个零作为有效位,isBitZero作为是否遇到非零值
	for (int j = i; j >= 0; j--)
	{
		if (isBitZero)
		{
			//遇到了非零值后
			if (number.at(j) == Upper[0].at(0))
			{
				number.erase(j, 1);
				Number.erase(j, 1);
			}
		}
		else
		{
			if (number.at(j) == Upper[0].at(0))
			{
				isBitZero = true;
			}
		}
	}
	//处理小数位
	tPos = Number.find_first_of(L"圆");
	number = Number.substr(tPos + 1, Number.size());
	if (number.at(number.size() - 1) == Upper[0].at(0))
	{
		Number.erase(Number.size() - 1, 1);
		if (number.at(0) == Upper[0].at(0))
		{
			Number.erase(tPos + 1, 1);
			Number += L"整";
		}
	}
	//处理
	//0.01 圆零壹分
	//0.00 圆整
	tPos = Number.find_first_of(L"圆");
	if (tPos == 0)
	{
		Number.erase(0, 1);
		tPos = Number.find_first_of(L"零");
		if (tPos == 0)
			Number.erase(0, 1);
	}

	Number = L"人民币" + Number;
	return Number;
}

string UpperNumber_zh_CN_Ascii(double num)
{
	return UnicodeToAscii(UpperNumber_zh_CN_Unicode(num));
}