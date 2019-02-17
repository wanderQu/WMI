// WMPrinter.cpp : 定义控制台应用程序的入口点。
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
	wstring Upper[] = { L"零",  L"壹", L"贰",	L"叁",   L"肆",
						L"伍",  L"陆", L"柒",	L"捌",   L"玖" };//10
	wstring	Unit[] = {	L"分",  L"角", L"圆",   L"",	 L"十",
						L"百",  L"千", L"万",	L"十万", L"百万", 
						L"千万",L"亿", L"十亿", L"百亿", L"千亿",
						L"万亿" };

	wstring number;
	char tNumber[20];
	sprintf(tNumber, "%.2f", num);
	number = ASCIIToUnicode(tNumber);
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
	tPos = Number.find_first_of(L"圆");
	if (tPos == 0)
	{
		Number.erase(0, 1);
		tPos = Number.find_first_of(L"零");
		if (tPos == 0)
			Number.erase(0, 1);
	}

	Number = L"人民币 " + Number;
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
	//要先获取数据才行，然后在弄文件名那些，fitting！
	this->GetData();
	InitPDF();//初始化路径及文件名

	//分解数据对象
	if (pcd->listName != proOrder || pcd->listName != distriOrder)
	{
		//初始化时间
		Print(0, data.size());
	}
	else //if (pcd->listName == proOrder)
	{
		//按照data数据分单
		if (strlen(pcd->object) != 0)//只有一个对象，就打印完整的
		{
			Print(0, data.size());
		}
		else//有很多对象需要被打印，要分开打印
		{
			size_t sta = 1,end = 1;//因为第一行是表头。
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
	//日期和对象的顺序
	//日期+type
	switch (pcd->listName)
	{
	case proOrder:
		listName = L"采购订单";
		sql =
			"SELECT \
					[proTrack].[单据时间],\
					[proTrack].[供应商编号],\
					[proTrack].[供应商名称],\
					[manaSup].[地址],\
					[manaSup].[联系人],\
					[manaSup].[联系方式],\
					[proTrack].[商品编号],\
					[proTrack].[商品名称],\
					[inventory].[商品单价],\
					[proTrack].[商品数量],\
					[proTrack].[金额总计]\
					[proTrack].[备注]\
			FROM([proTrack]\
					INNER JOIN[inventory] ON[proTrack].[商品编号] = [inventory].[商品编号])\
					INNER JOIN[manaSup] ON[proTrack].[供应商编号] = [manaSup].[供应商编号] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [proTrack]." + pcd->object;
		sql +=
			" ORDER  BY\
				    [proTrack].[供应商编号],\
				    [proTrack].[单据日期]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Supplier;
		break;
	case proDetails:
		listName = L"采购明细表";
		sql =
			"SELECT \
					[单据时间],\
					[供应商编号],\
					[供应商名称],\
					[商品编号],\
					[商品名称],\
					[商品数量],\
					[金额总计]\
					[备注]\
			FROM[proTrack] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [proTrack]." + pcd->object;
		sql +=
			" ORDER  BY\
				    [供应商编号],\
				    [单据日期]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Supplier;
		break;
	case proReturn:
		listName = L"采购退货单";
		sql =
			"SELECT \
					[单据日期],\
					[供应商编号],\
					[供应商名称],\
					[商品编号],\
					[商品名称],\
					[商品退货数量],\
					[退货金额],\
					[退货原因]\
			FROM[proReturn] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [proReturn]." + pcd->object;
		sql +=
			" ORDER  BY\
					[供应商编号],\
					[单据日期]; ";
		
		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Supplier;
		break;
	case distriOrder:
		listName = L"配送货单";
		sql =
			"SELECT \
					[distriTrack].[单据日期],\
					[distriTrack].[客户编号],\
					[distriTrack].[客户名称],\
					[manaCus].[地址],\
					[manaCus].[联系人],\
					[manaCus].[联系方式],\
					[distriTrack].[商品编号],\
					[distriTrack].[商品名称],\
					[inventory].[商品单价],\
					[distriTrack].[商品数量],\
					[distriTrack].[金额总计],\
					[distriTrack].[备注]\
			FROM([distriTrack]\
					INNER JOIN[inventory] ON[distriTrack].[商品编号] = [inventory].[商品编号])\
					INNER JOIN[manaCus]   ON[manaCus].[客户编号]     = [distriTrack].[客户编号] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [distriTrack]." + pcd->object;
		sql +=
			" ORDER  BY\
					[distriTrack].[客户编号],\
					[distriTrack].[单据日期]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Customer;
		break;
	case distriDetails:
		listName = L"配送明细表";
		sql =
			"SELECT \
					[单据日期],\
					[客户编号],\
					[客户名称],\
					[商品编号],\
					[商品名称],\
					[商品数量],\
					[金额总计],\
					[备注]\
			FROM[distriTrack] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [distriTrack]." + pcd->object;
		sql +=
			" ORDER BY\
					[客户编号],\
					[单据日期];";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Customer;
		break;
	case distriReturn:
		listName = L"配送退货单";
		sql =
			"SELECT \
					[单据日期],\
					[客户编号],\
					[客户名称],\
					[商品编号],\
					[商品名称],\
					[商品退货数量],\
					[退货金额],\
					[退货原因]\
			FROM[distriReturn] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [distriReturn]." + pcd->object;
		sql +=
			" ORDER BY\
					[客户编号],\
					[单据日期]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Customer;
		break;
	case wareIn:
		listName = L"入库单";
		sql =
			"SELECT \
					[单据日期],\
					[仓库编号],\
					[商品编号],\
					[商品名称],\
					[商品数量]\
			FROM[wareIn] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [wareIn]." + pcd->object;
		sql +=
			" ORDER BY\
					[仓库编号],\
				    [单据日期]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Warehouse;
		break;
	case wareOut:
		listName = L"出库单";
		sql =
			"SELECT \
					[单据日期],\
					[仓库编号],\
					[商品编号],\
					[商品名称],\
					[商品数量]\
			FROM[wareOut] ";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object) != 0)
			sql = sql + " AND [wareOut]." + pcd->object;
		sql +=
			" ORDER  BY \
					[仓库编号],\
				    [单据日期]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Warehouse;
		break;
	case wareStock:
		listName = L"库存盘点";
		sql =
			"SELECT \
					[仓库编号],\
					[商品编号],\
					[商品名称],\
					[在库量]\
			FROM[wareStock]; ";
		if (strlen(pcd->object) != 0)
			sql = sql + " WHERE [wareStock].";
		sql = sql + pcd->object +
			" ORDER  BY\
				    [仓库编号]; ";

		pPcdIndex->time = -1;
		pPcdIndex->obj = 0;
		pPcdIndex->objType = Warehouse;
		break;
	case wareAdjust:
		listName = L"库存调整单";
		sql =
			"SELECT \
					[日期],\
					[商品编号],\
					[商品名称],\
					[商品单价],\
					[实际单价],\
					[在库量],\
					[实际在库量],\
					[备注]\
			FROM[wareChng] ";
		if (strlen(pcd->object) != 0)
			sql = sql + " WHERE [wareAdjust].";
		sql = sql + pcd->object +
			" ORDER  BY\
				    [商品编号],\
				    [日期]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Goods;
		break;
	case dataRecv:
		listName = L"收款单";
		sql = 
			"SELECT \
					[单据日期],\
					[客户编号],\
					[客户名称],\
					[资金类别],\
					[收款金额],\
					[优惠金额],\
					[备注]\
			FROM[dataVoucher]";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object)!=0)
			sql = sql + " AND [dataVoucher].";
		sql = sql + pcd->object +
			" ORDER  BY\
					[客户编号],\
					[单据日期]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Customer;
		break;
	case dataPay:
		listName = L"付款单";
		sql = 
			"SELECT \
					[单据日期],\
					[供应商编号],\
					[供应商名称],\
					[资金类别],\
					[收款金额],\
					[优惠金额],\
					[备注]\
			FROM[dataVoucher]";
		sql = sql + pcd->dateTime;
		if (strlen(pcd->object)!=0)
			sql = sql + " AND [dataPayment].";
		sql = sql + pcd->object +
			" ORDER  BY\
					[供应商编号],\
					[单据日期]; ";

		pPcdIndex->time = 0;
		pPcdIndex->obj = 1;
		pPcdIndex->objType = Supplier;
		break;
	case dataRecable:
		listName = L"应收账款单";
		sql = 
			"SELECT \
					[客户编号],\
					[客户名称],\
					[应收账款金额],\
					[优惠金额累计]\
		FROM[dataReceivable]";
		if (strlen(pcd->object) != 0)
			sql = sql + " WHERE [dataReceivable].";
		sql = sql + pcd->object +
			" ORDER  BY\
					[客户编号]; ";

		pPcdIndex->time = -1;
		pPcdIndex->obj = 0;
		pPcdIndex->objType = Customer;
		break;
	case dataPayable:
		listName = L"应付账款单";
		sql = 
			"SELECT \
					[供应商编号],\
					[供应商名称],\
					[应付账款金额],\
					[优惠金额累计]\
		FROM[dataPayable]";
		if (strlen(pcd->object) != 0)
			sql = sql + " WHERE [dataPayable].";
		sql = sql + pcd->object +
			" ORDER  BY\
					[供应商编号]; ";

		pPcdIndex->time = -1;
		pPcdIndex->obj = 0;
		pPcdIndex->objType = Supplier;
		break;
	case dataOtherIn:
		listName = L"其他收入单";
		sql = 
			"SELECT \
					[单据日期],\
					[资金类别],\
					[金额总计],\
					[备注]\
		FROM[dataOtherIncome]";
		sql = sql + pcd->dateTime +
			" ORDER  BY\
					[资金类别],\
					[单据日期]; ";

		pPcdIndex->time = -1;
		pPcdIndex->obj = -1;
		pPcdIndex->objType = Money;
		break;
	case dataOtherOut:
		listName = L"其他支出单";
		sql = 
			"SELECT \
					[单据日期],\
					[资金类别],\
					[金额总计],\
					[备注]\
		FROM[dataOtherExpend]";
		sql = sql + pcd->dateTime +
			" ORDER  BY\
					[资金类别],\
					[单据日期]; ";

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