#include "stdafx.h"
#include"StringProcess.h"
wstring AsciiToUnicode(const string& str) {
	// Ԥ��-�������п��ֽڵĳ���    
	int unicodeLen = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, nullptr, 0);
	// ��ָ�򻺳�����ָ����������ڴ�    
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);
	// ��ʼ�򻺳���ת���ֽ�    
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, pUnicode, unicodeLen);
	wstring ret_str = pUnicode;
	free(pUnicode);
	return ret_str;
}
string UnicodeToAscii(const wstring& wstr) {
	// Ԥ��-�������ж��ֽڵĳ���    
	int ansiiLen = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	// ��ָ�򻺳�����ָ����������ڴ�    
	char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);
	// ��ʼ�򻺳���ת���ֽ�    
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);
	string ret_str = pAssii;
	free(pAssii);
	return ret_str;
}
wstring Utf8ToUnicode(const string& str) {
	// Ԥ��-�������п��ֽڵĳ���    
	int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
	// ��ָ�򻺳�����ָ����������ڴ�    
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);
	// ��ʼ�򻺳���ת���ֽ�    
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, pUnicode, unicodeLen);
	wstring ret_str = pUnicode;
	free(pUnicode);
	return ret_str;
}
string UnicodeToUtf8(const wstring& wstr) {
	// Ԥ��-�������ж��ֽڵĳ���    
	int ansiiLen = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	// ��ָ�򻺳�����ָ����������ڴ�    
	char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);
	// ��ʼ�򻺳���ת���ֽ�    
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

// string �� Int ��ת  
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
	wstring Upper[] = { L"��", L"Ҽ", L"��", L"��", L"��",
		L"��", L"½", L"��", L"��", L"��" };//10
	wstring	Unit[] = { L"��", L"��", L"Բ", L"", L"ʮ",
		L"��", L"ǧ", L"��", L"ʮ��", L"����",
		L"ǧ��", L"��", L"ʮ��", L"����", L"ǧ��",
		L"����" };
	wstring Number;
	//eg:1005007.02
	wstring number;
	char tNumber[20];
	sprintf(tNumber, "%.2f", num);
	number = AsciiToUnicode(tNumber);
	if (number == L"0.00")
	{
		Number = L"����� ��Բ";
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
	//eg:Ҽ����������ǧ������Բ�㷡��
	//							ȥ���������
	//����
	//	����λֻ�����һ������Ч����û��С����ʱ�����һλ��Ҫ�ӡ�����
	//	С��λ����λ������Ϊ��λ�����Բ�Ӱ��
	//	����λ��С��λ�ֱ�ֻ��һ���㣬û�������
	//basic_string& erase(size_type pos = 0, size_type len = npos);
	int pos = -1;
	bool isBitZero = false;
	int tPos = Number.find_first_of(L"Բ");
	number = Number.substr(0, tPos);
	//�����λ���㣬��ô��λǰ���������㶼Ӧ�ñ�ɾ��
	//���ǰ���һ������ֵǰ���һ����Ӧ��Ϊ��Чλ�㣬��ɾ����λ����
	int i = tPos - 1;
	if (number.at(i) == Upper[0].at(0))
	{
		isBitZero = true;
		//ȥ����λǰ�������㣬������λ
		for (; i >= 0; i--)
		{
			if (number.at(i) == Upper[0].at(0))
			{
				number.erase(i, 1);
				Number.erase(i, 1);
			}
			else//��������㣬�Ǿ��ǵ�һλ����ֵ��������
			{
				isBitZero = false;
				break;//�������ѭ��
			}
		}
	}
	//�����ĵ�һ������Ϊ��Чλ,isBitZero��Ϊ�Ƿ���������ֵ
	for (int j = i; j >= 0; j--)
	{
		if (isBitZero)
		{
			//�����˷���ֵ��
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
	//����С��λ
	tPos = Number.find_first_of(L"Բ");
	number = Number.substr(tPos + 1, Number.size());
	if (number.at(number.size() - 1) == Upper[0].at(0))
	{
		Number.erase(Number.size() - 1, 1);
		if (number.at(0) == Upper[0].at(0))
		{
			Number.erase(tPos + 1, 1);
			Number += L"��";
		}
	}
	//����
	//0.01 Բ��Ҽ��
	//0.00 Բ��
	tPos = Number.find_first_of(L"Բ");
	if (tPos == 0)
	{
		Number.erase(0, 1);
		tPos = Number.find_first_of(L"��");
		if (tPos == 0)
			Number.erase(0, 1);
	}

	Number = L"�����" + Number;
	return Number;
}

string UpperNumber_zh_CN_Ascii(double num)
{
	return UnicodeToAscii(UpperNumber_zh_CN_Unicode(num));
}