// WMPrinter.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"WMPrinter.h"
WMPrinter::WMPrinter()
{
	DB_open(&db, ".\\UserData\\data.db");
	page = 1;
	listNeed = -1;
	//this->pcd = new COPYDATA;
}
WMPrinter::~WMPrinter()
{
	
	//delete this->pcd;
}
wstring UTF_8ToUnicode(const char* str)
{
	int len;

	len = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	if (len == 0)
	{
		return L"";
	}

	wchar_t *pRes = new wchar_t[len];
	if (pRes == NULL)
	{
		return L"";
	}
	MultiByteToWideChar(CP_UTF8, 0, str, -1, pRes, len);
	pRes[len - 1] = L'\0';
	std::wstring result = pRes;
	delete[] pRes;

	return result;

}
wstring ASCIIToUnicode(const char* str)
{
	int len = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
	if (len == 0)
	{
		return L"";
	}
	wchar_t *pRes = new wchar_t[len];
	if (pRes == NULL)
	{
		return L"";
	}

	MultiByteToWideChar(CP_ACP, 0, str, -1, pRes, len);
	pRes[len - 1] = L'\0';
	std::wstring result = pRes;
	delete[] pRes;

	return result;

}
wstring UpperNumber_zh_CN(double num, wstring Number)
{
	wstring Upper[] = { L"��",  L"Ҽ", L"��",	L"��",   L"��",
						L"��",  L"½", L"��",	L"��",   L"��" };//10
	wstring	Unit[] = {	L"��",  L"��", L"Բ",   L"",	 L"ʮ",
						L"��",  L"ǧ", L"��",	L"ʮ��", L"����", 
						L"ǧ��",L"��", L"ʮ��", L"����", L"ǧ��",
						L"����" };

	wstring number;
	char tNumber[20];
	sprintf(tNumber, "%.2f", num);
	number = ASCIIToUnicode(tNumber);
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
	tPos = Number.find_first_of(L"Բ");
	if (tPos == 0)
	{
		Number.erase(0, 1);
		tPos = Number.find_first_of(L"��");
		if (tPos == 0)
			Number.erase(0, 1);
	}

	Number = L"����� " + Number;
	return Number;
}
void WMPrinter::Insert_UTF_8_Data(const char* str, size_t item, size_t col)
{

	if (item >= data.size())
	{
		vector<wstring> vec;
		vec.push_back(UTF_8ToUnicode(str));
		data.push_back(vec);
	}
	else if (item >= 0)
	{
		if (col >= data.at(item).size())
		{
			data.at(item).push_back(UTF_8ToUnicode(str));
		}
		else
		{
			it = data.at(item).begin() + col;
			data.at(item).insert(it, UTF_8ToUnicode(str));
		}
	}

}
void WMPrinter::Insert_ASCII_Data(const char* str, size_t item, size_t col)
{

	if (item >= data.size())
	{
		vector<wstring> vec;
		vec.push_back(ASCIIToUnicode(str));
		data.push_back(vec);
	}
	else if (item >= 0)
	{
		if (col >= data.at(item).size())
		{
			data.at(item).push_back(ASCIIToUnicode(str));
		}
		else
		{
			it = data.at(item).begin() + col;
			data.at(item).insert(it, ASCIIToUnicode(str));
		}
	}
}


BOOL WMPrinter::StartPrint(PCOPYDATA pcd)
{
	this->pcd = pcd;
	//Ҫ�Ȼ�ȡ���ݲ��У�Ȼ����Ū�ļ�����Щ��fitting��
	this->GetData();
	InitPDF();//��ʼ��·�����ļ���

	//�ֽ����ݶ���
	if (pcd->listName != proOrder || pcd->listName != distriOrder)
	{
		//��ʼ��ʱ��
		Print(0, data.size());
	}
	else //if (pcd->listName == proOrder)
	{
		//����data���ݷֵ�
		if (strlen(pcd->object) != 0)//ֻ��һ�����󣬾ʹ�ӡ������
		{
			Print(0, data.size());
		}
		else//�кܶ������Ҫ����ӡ��Ҫ�ֿ���ӡ
		{
			size_t sta = 1,end = 1;//��Ϊ��һ���Ǳ�ͷ��
			while (end < data.size())
			{
				if (data.at(end).at(0) != data.at(sta).at(0))
				{
					Print(sta, end);
					sta = end;
				}
				end++;
			}
		}
	}
	return 0;
}

void WMPrinter::GetData()
{
	//���ںͶ����˳��
	//����+type
	switch (pcd->listName)
	{
	case proOrder:
		listName = L"�ɹ�����";
		sql =
			"SELECT \
					[proTrack].[����ʱ��],\
					[proTrack].[��Ӧ�̱��],\
					[proTrack].[��Ӧ������],\
					[manaSup].[��ַ],\
					[manaSup].[��ϵ��],\
					[manaSup].[��ϵ��ʽ],\
					[proTrack].[��Ʒ���],\
					[proTrack].[��Ʒ����],\
					[inventory].[��Ʒ����],\
					[proTrack].[��Ʒ����],\
					[proTrack].[����ܼ�]\
					[proTrack].[��ע]\
			FROM([proTrack]\
					INNER JOIN[inventory] ON[proTrack].[��Ʒ���] = [inventory].[��Ʒ���])\
					INNER JOIN[manaSup] ON[proTrack].[��Ӧ�̱��] = [manaSup].[��Ӧ�̱��] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [proTrack]." + pcd->object;
		sql +=
			" ORDER  BY\
				    [proTrack].[��Ӧ�̱��],\
				    [proTrack].[��������]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Supplier;
		break;
	case proDetails:
		listName = L"�ɹ���ϸ��";
		sql =
			"SELECT \
					[����ʱ��],\
					[��Ӧ�̱��],\
					[��Ӧ������],\
					[��Ʒ���],\
					[��Ʒ����],\
					[��Ʒ����],\
					[����ܼ�]\
					[��ע]\
			FROM[proTrack] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [proTrack]." + pcd->object;
		sql +=
			" ORDER  BY\
				    [��Ӧ�̱��],\
				    [��������]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Supplier;
		break;
	case proReturn:
		listName = L"�ɹ��˻���";
		sql =
			"SELECT \
					[��������],\
					[��Ӧ�̱��],\
					[��Ӧ������],\
					[��Ʒ���],\
					[��Ʒ����],\
					[��Ʒ�˻�����],\
					[�˻����],\
					[�˻�ԭ��]\
			FROM[proReturn] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [proReturn]." + pcd->object;
		sql +=
			" ORDER  BY\
					[��Ӧ�̱��],\
					[��������]; ";
		
		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Supplier;
		break;
	case distriOrder:
		listName = L"���ͻ���";
		sql =
			"SELECT \
					[distriTrack].[��������],\
					[distriTrack].[�ͻ����],\
					[distriTrack].[�ͻ�����],\
					[manaCus].[��ַ],\
					[manaCus].[��ϵ��],\
					[manaCus].[��ϵ��ʽ],\
					[distriTrack].[��Ʒ���],\
					[distriTrack].[��Ʒ����],\
					[inventory].[��Ʒ����],\
					[distriTrack].[��Ʒ����],\
					[distriTrack].[����ܼ�],\
					[distriTrack].[��ע]\
			FROM([distriTrack]\
					INNER JOIN[inventory] ON[distriTrack].[��Ʒ���] = [inventory].[��Ʒ���])\
					INNER JOIN[manaCus]   ON[manaCus].[�ͻ����]     = [distriTrack].[�ͻ����] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [distriTrack]." + pcd->object;
		sql +=
			" ORDER  BY\
					[distriTrack].[�ͻ����],\
					[distriTrack].[��������]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Customer;
		break;
	case distriDetails:
		listName = L"������ϸ��";
		sql =
			"SELECT \
					[��������],\
					[�ͻ����],\
					[�ͻ�����],\
					[��Ʒ���],\
					[��Ʒ����],\
					[��Ʒ����],\
					[����ܼ�],\
					[��ע]\
			FROM[distriTrack] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [distriTrack]." + pcd->object;
		sql +=
			" ORDER BY\
					[�ͻ����],\
					[��������];";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Customer;
		break;
	case distriReturn:
		listName = L"�����˻���";
		sql =
			"SELECT \
					[��������],\
					[�ͻ����],\
					[�ͻ�����],\
					[��Ʒ���],\
					[��Ʒ����],\
					[��Ʒ�˻�����],\
					[�˻����],\
					[�˻�ԭ��]\
			FROM[distriReturn] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [distriReturn]." + pcd->object;
		sql +=
			" ORDER BY\
					[�ͻ����],\
					[��������]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Customer;
		break;
	case wareIn:
		listName = L"��ⵥ";
		sql =
			"SELECT \
					[��������],\
					[�ֿ���],\
					[��Ʒ���],\
					[��Ʒ����],\
					[��Ʒ����]\
			FROM[wareIn] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [wareIn]." + pcd->object;
		sql +=
			" ORDER BY\
					[�ֿ���],\
				    [��������]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Warehouse;
		break;
	case wareOut:
		listName = L"���ⵥ";
		sql =
			"SELECT \
					[��������],\
					[�ֿ���],\
					[��Ʒ���],\
					[��Ʒ����],\
					[��Ʒ����]\
			FROM[wareOut] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [wareOut]." + pcd->object;
		sql +=
			" ORDER  BY \
					[�ֿ���],\
				    [��������]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Warehouse;
		break;
	case wareStock:
		listName = L"����̵�";
		sql =
			"SELECT \
					[�ֿ���],\
					[��Ʒ���],\
					[��Ʒ����],\
					[�ڿ���]\
			FROM[wareStock]; ";
		if (strlen(pcd->object) != 0)
			sql = sql + " WHERE [wareStock].";
		sql = sql + pcd->object +
			" ORDER  BY\
				    [�ֿ���]; ";

		pPcdIndex->time = -1;
		pPcdIndex->obj = 0;
		pPcdIndex->objType = Warehouse;
		break;
	case wareAdjust:
		listName = L"��������";
		sql =
			"SELECT \
					[����],\
					[��Ʒ���],\
					[��Ʒ����],\
					[��Ʒ����],\
					[ʵ�ʵ���],\
					[�ڿ���],\
					[ʵ���ڿ���],\
					[��ע]\
			FROM[wareChng] ";
		if (strlen(pcd->object) != 0)
			sql = sql + " WHERE [wareAdjust].";
		sql = sql + pcd->object +
			" ORDER  BY\
				    [��Ʒ���],\
				    [����]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Goods;
		break;
	case dataRecv:
		listName = L"�տ";
		sql = 
			"SELECT \
					[��������],\
					[�ͻ����],\
					[�ͻ�����],\
					[�ʽ����],\
					[�տ���],\
					[�Żݽ��],\
					[��ע]\
			FROM[dataVoucher]";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object)!=0)
			sql = sql + " AND [dataVoucher].";
		sql = sql + pcd->object +
			" ORDER  BY\
					[�ͻ����],\
					[��������]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Customer;
		break;
	case dataPay:
		listName = L"���";
		sql = 
			"SELECT \
					[��������],\
					[��Ӧ�̱��],\
					[��Ӧ������],\
					[�ʽ����],\
					[�տ���],\
					[�Żݽ��],\
					[��ע]\
			FROM[dataVoucher]";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object)!=0)
			sql = sql + " AND [dataPayment].";
		sql = sql + pcd->object +
			" ORDER  BY\
					[��Ӧ�̱��],\
					[��������]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Supplier;
		break;
	case dataRecable:
		listName = L"Ӧ���˿";
		sql = 
			"SELECT \
					[�ͻ����],\
					[�ͻ�����],\
					[Ӧ���˿���],\
					[�Żݽ���ۼ�]\
		FROM[dataReceivable]";
		if (strlen(pcd->object) != 0)
			sql = sql + " WHERE [dataReceivable].";
		sql = sql + pcd->object +
			" ORDER  BY\
					[�ͻ����]; ";

		pPcdIndex->time = -1;
		pPcdIndex->obj = 0;
		pPcdIndex->objType = Customer;
		break;
	case dataPayable:
		listName = L"Ӧ���˿";
		sql = 
			"SELECT \
					[��Ӧ�̱��],\
					[��Ӧ������],\
					[Ӧ���˿���],\
					[�Żݽ���ۼ�]\
		FROM[dataPayable]";
		if (strlen(pcd->object) != 0)
			sql = sql + " WHERE [dataPayable].";
		sql = sql + pcd->object +
			" ORDER  BY\
					[��Ӧ�̱��]; ";

		pPcdIndex->time = -1;
		pPcdIndex->obj = 0;
		pPcdIndex->objType = Supplier;
		break;
	case dataOtherIn:
		listName = L"�������뵥";
		sql = 
			"SELECT \
					[��������],\
					[�ʽ����],\
					[����ܼ�],\
					[��ע]\
		FROM[dataOtherIncome]";
		sql = sql + pcd->dateTime +
			" ORDER  BY\
					[�ʽ����],\
					[��������]; ";

		pPcdIndex->time = -1;
		pPcdIndex->obj = -1;
		pPcdIndex->objType = Money;
		break;
	case dataOtherOut:
		listName = L"����֧����";
		sql = 
			"SELECT \
					[��������],\
					[�ʽ����],\
					[����ܼ�],\
					[��ע]\
		FROM[dataOtherExpend]";
		sql = sql + pcd->dateTime +
			" ORDER  BY\
					[�ʽ����],\
					[��������]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = -1;
		pPcdIndex->objType = Money;
		break;
	}
	DB_excute(db, sql.c_str(), ::GetData, this);
}
int GetData(void* data, int argc, char**argv, char**column)
{
	WMPrinter* wmp = (WMPrinter*)data;
	if (wmp->data.size() == 0)
	{
		for (int i = 0; i < argc; i++)
			wmp->Insert_UTF_8_Data(column[i], 0, i);
	}

	int item = wmp->data.size();
	for (int i = 0; i < argc; i++)
		wmp->Insert_UTF_8_Data(argv[i], item, i);
	return false;
}