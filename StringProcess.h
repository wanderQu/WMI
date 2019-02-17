#pragma once
#include<Windows.h>
#include<string>
using namespace std;

// ASCII与Unicode互转  
wstring AsciiToUnicode(const string& str);  
string  UnicodeToAscii(const wstring& wstr);  
// UTF8与Unicode互转  
wstring Utf8ToUnicode(const string& str);  
string  UnicodeToUtf8(const wstring& wstr);  
// ASCII与UTF8互转  
string  AsciiToUtf8(const string& str);  
string  Utf8ToAscii(const string& str);  

/************string-int***************/  
// string 转 Int  
int StringToInt(const string& str);  
string IntToString(int i);  
string IntToString(char i);  
string IntToString(double i);  
/************int-MONEY***************/
// 数字金额 转 中文金额大写 
//注意，由于涉及到中文，所以要转换成宽字符然后再处理“零”
string UpperNumber_zh_CN_Ascii(double num);
wstring UpperNumber_zh_CN_Unicode(double num);