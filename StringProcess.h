#pragma once
#include<Windows.h>
#include<string>
using namespace std;

// ASCII��Unicode��ת  
wstring AsciiToUnicode(const string& str);  
string  UnicodeToAscii(const wstring& wstr);  
// UTF8��Unicode��ת  
wstring Utf8ToUnicode(const string& str);  
string  UnicodeToUtf8(const wstring& wstr);  
// ASCII��UTF8��ת  
string  AsciiToUtf8(const string& str);  
string  Utf8ToAscii(const string& str);  

/************string-int***************/  
// string ת Int  
int StringToInt(const string& str);  
string IntToString(int i);  
string IntToString(char i);  
string IntToString(double i);  
/************int-MONEY***************/
// ���ֽ�� ת ���Ľ���д 
//ע�⣬�����漰�����ģ�����Ҫת���ɿ��ַ�Ȼ���ٴ����㡱
string UpperNumber_zh_CN_Ascii(double num);
wstring UpperNumber_zh_CN_Unicode(double num);