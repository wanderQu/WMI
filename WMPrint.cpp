#include "stdafx.h"
#include"WMPrinter.h"
void WMPrinter::ShutDownLocal()
{
	pdf.end_document(L"");
	exit(0);
}
wstring WMPrinter::ResetTime(wstring tmpTime, bool needTime)
{
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
	//2 0 1 9 - 0 2 - 2 2 \0  2 4  :  0  0  :  0  0
	//2 0 1 9 0 2 2 2 2 4 0 0 0 0
	time = tmpTime;
	size_t place[] = { 4, 7, 10, 13, 16 };
	for (int i = 0; i < 5; i++)
		time.replace(place[i], place[i], L"");
	if (!needTime)
	{
		time.erase(8, 12);
	}
	return time;
}
void WMPrinter::InitPDF()
{
	//  This means we must check return values of load_font() etc.
	pdf.set_option(L"errorpolicy=return");
	// Set the search path for fonts and PDF files
	
	strBuf.str(L"");
	string strPath = pcd->fileName;
	strBuf << L"searchpath={{" << ASCIIToUnicode(strPath.substr(0, strPath.find_last_of("/\\")).c_str()) << L"}}";
	pdf.set_option(strBuf.str());
	
	/* Set an output path according to the name of the topic */
	strBuf.str(L"");
	strBuf << ASCIIToUnicode(strPath.substr(strPath.find_last_of("/\\") + 1).c_str());
	if (pdf.begin_document(strBuf.str(), L"") == -1) {
		wcerr << L"Error: " << pdf.get_errmsg() << endl;
		ShutDownLocal();
	}
	pdf.set_info(L"Creator", L"小蘑菇打印机");
	pdf.set_info(L"Title", ASCIIToUnicode(pcd->compName));
	pdf.set_info(L"Author", L"WL_15_Q");
	
	fontThin = pdf.load_font(L"STSong-Light", L"GB-EUC-H", L"");
	if (fontThin == -1)
	{
		wcerr << L"Error: " << pdf.get_errmsg() << endl;
		ShutDownLocal();
	}
	fontBold = pdf.load_font(L"Helvetica-Bold", L"winansi", L"");
	if (fontBold == -1)
	{
		wcerr << L"Error: " << pdf.get_errmsg() << endl;
		ShutDownLocal();
	}
	GetLocalTime(&tm);
	pageMarginsX = 45;
	pageMarginsY = pageMarginsX;
}
void WMPrinter::SetOptList(int fontSize, int boxWidth,
	bool showBorder, TextStyle textStyle, float lineSpace)
{
	optList = { 0 };
	optList.fontSize = fontSize;
	optList.lineSpace = lineSpace;
	optList.boxWidth = boxWidth;
	optList.boxHeight = lineSpace * fontSize;
	optList.showBorder = showBorder;
	optList.textStyle = textStyle;
}
wstring WMPrinter::GetOptList()
{
	optBuf.str(L"");

	optBuf << " boxsize={ " << optList.boxWidth << " " << optList.boxHeight << "}"
		<< " fontSize=" << optList.fontSize;

	switch (optList.textStyle)
	{
	case Left_Top:
		optBuf << " position = { left top }";
		break;
	case Left_Center:
		optBuf << " position = { left center}";
		break;
	case Left_Bottom:
		optBuf << " position = { left bottom}";
		break;
	case Right_Top:
		optBuf << " position = { right top}";
		break;
	case Right_Center:
		optBuf << " position = { right center}";
		break;
	case Right_Bottom:
		optBuf << " position = { right bottom}";
		break;
	case Center_Top:
		optBuf << " position = { center top}";
		break;
	case Center_Center:
		optBuf << " position = { center center}";
		break;
	case Center_Bottom:
		optBuf << " position = { center bottom}";
		break;
	case Auto_Fit:
		optBuf << " fitmethod = auto";
		break;
	}
	if (optList.showBorder)
		optBuf << " showborder";
	return optBuf.str();
}
/*obj = type+ ID(4)*/
void WMPrinter::PrintOrderNumber(wstring obj,wstring time)
{
	//a4.width = 600,a4.height = 840;
	this->obj = obj;
	this->time = time;
	if (pcd->listName == proOrder || pcd->listName == distriOrder)
	{
		pdf.begin_page_ext(0, 0, L"width=a4.width height=a4.height");
		pageWidth = 600;
		pageHeight = 840;
	}
	else
	{
		pdf.begin_page_ext(0, 0, L"width=a4.height height=a4.width");
		pageWidth = 840;
		pageHeight = 600;
	}
	pdf.setfont(fontThin, 11);
	strBuf.str(L"");

	if (time.size() == 0)
	{			
		strBuf << tm.wYear << tm.wMonth << tm.wDay
			<< tm.wHour << tm.wMinute << tm.wSecond;
	}
	else
		strBuf << time;//以外部时间为主
	if (obj != L"")
	{
		strBuf << obj;
	}
	switch (pcd->listName)
	{
	case proOrder:
		strBuf << "01";
		break;
	case proDetails:
		strBuf << "02";
		break;
	case proReturn:
		strBuf << "03";
		break;
	case distriOrder:
		strBuf << "04";
		break;
	case distriDetails:
		strBuf << "05";
		break;
	case distriReturn:
		strBuf << "06";
		break;
	case wareIn:
		strBuf << "07";
		break;
	case wareOut:
		strBuf << "08";
		break;
	case wareStock:
		strBuf << "09";
		break;
	case wareAdjust:
		strBuf << "10";
		break;
	case dataRecv:
		strBuf << "11";
		break;
	case dataPay:
		strBuf << "12";
		break;
	case dataRecable:
		strBuf << "13";
		break;
	case dataPayable:
		strBuf << "14";
		break;
	case dataOtherIn:
		strBuf << "15";
		break;
	case dataOtherOut:
		strBuf << "16";
		break;
	}
	optList = { 0 };
	optList.fontSize = 11;
	optList.showBorder = false;
	
	point.x = pageWidth - fontThin / 2 * strBuf.str().size();
	point.y = pageHeight - fontThin * 2;

	pdf.fit_textline(strBuf.str(), point.x, point.y, GetOptList());
}
void WMPrinter::PrintTitle()
{
	pdf.setfont(fontBold, 24);
	strBuf.str(L"");
	strBuf << ASCIIToUnicode(pcd->compName);

	SetOptList(24, pageWidth - 2 * pageMarginsX, false, Center_Center);
	
	point.x = pageWidth - pageMarginsX;
	point.y = pageHeight - pageMarginsY - optList.boxHeight;

	pdf.fit_textline(strBuf.str(), point.x, point.y, GetOptList());

	pdf.setfont(fontBold, 22);
	strBuf.str(L"");
	strBuf << listName;

	SetOptList(22, pageWidth - 2 * pageMarginsX, false, Center_Center);

	point.x = pageMarginsX;
	point.y = point.y - optList.boxHeight;

	pdf.fit_textline(strBuf.str(), point.x, point.y, GetOptList());

}
void WMPrinter::PrintListHead(size_t sta, size_t end)
{
	list = -1;
	if (pcd->listName == proOrder || pcd->listName == distriOrder)
	{			
		pdf.setfont(fontBold, 12);
		point.y = point.y - 20;
		pdf.set_text_pos(pageMarginsX, point.y);
		if (pcd->listName == distriOrder)
		{
			pdf.show(L"需      方：" + data.at(sta).at(2));
			pdf.continue_text(L"需方联系人：" + data.at(sta).at(4));
			optBuf << L"colwidth = 40 %";
			if (end - sta < 6)
				listNeed = 6 - (end - sta);
		}
		else
		{
			pdf.show(L"供      方：" + data.at(sta).at(2));
			pdf.continue_text(L"供方联系人：" + data.at(sta).at(4));
			optBuf << L"colwidth = 40 %";
			if (end - sta < 6)
				listNeed = 10 - (end - sta);

		}
		pdf.set_text_pos(pageWidth / 2, point.y);
		pdf.show(L"地址：" + data.at(sta).at(3));
		pdf.continue_text(L"电话：" + data.at(sta).at(5));
		point.y = point.y - 40;

		pdf.setfont(fontThin, 12);
		optBuf.str(L"");
		
		list = pdf.add_table_cell(list, 1, 1, L"序号", optBuf.str());
		list = pdf.add_table_cell(list, 1, 2, L"商品编号", optBuf.str());
		list = pdf.add_table_cell(list, 1, 3, L"商品名称", optBuf.str());
		list = pdf.add_table_cell(list, 1, 4, L"单价/元", optBuf.str());
		list = pdf.add_table_cell(list, 1, 5, L"数量", optBuf.str());
		list = pdf.add_table_cell(list, 1, 6, L"金额/元", optBuf.str());
		list = pdf.add_table_cell(list, 1, 7, L"备注", optBuf.str());
		return;
	}
	pdf.setfont(fontThin, 12);
	optBuf.str(L"");
	optBuf << L"colwidth = 20 %";// << end - sta;
	list = pdf.add_table_cell(list, 1, 1, L"序号", optBuf.str());
	for (size_t i = 0; i < data.at(0).size(); i++)
		list = pdf.add_table_cell(list, i + 1, 1, data.at(0).at(i), optBuf.str());
	if (end - sta < 12)
		listNeed = 12 - (end - sta);

}
void WMPrinter::PrintList(size_t sta, size_t end)
{
	pdf.setfont(fontThin, 11);
	for (size_t i = sta; i < end; i++)
	{
		if (pcd->listName == proOrder || pcd->listName == distriOrder)
		{
			for (size_t j = 6; j < data.at(0).size(); j++)
			{
				if (j == 6)
				{
					strBuf.str(L"");
					strBuf << i + 1 - sta;//序号
					list = pdf.add_table_cell(list, 1, i + 1, strBuf.str(), L"colwidth = 20 %");
				}
				list = pdf.add_table_cell(list, j - 4, i + 1, data.at(i).at(j), L"colwidth = 20 %");
			}
		}
		else
		{
			for (size_t j = 0; j < data.at(0).size(); j++)
			{
				if (j == 0)
				{
					strBuf.str(L"");
					strBuf << i + 1 - sta;//序号
					list = pdf.add_table_cell(list, 1, i + 1, strBuf.str(), L"colwidth = 20 %");
				}
				list = pdf.add_table_cell(list, j + 2, i + 1, data.at(i).at(j), L"colwidth = 20 %");
			}
		}
	}
	

}
void WMPrinter::PrintExtra(size_t sta,size_t end)
{
	if (listNeed != -1)
	{
		for (int i = 0; i < listNeed; i++)
		{
			for (int j = 0; j < data.at(0).size(); j++)
				pdf.add_table_cell(list, j, end + i, L"", optBuf.str());
		}
	}

	int col = -1;//那一列是金额所在
	double money = -1.0;
	wostringstream upperMoney;
	switch (pcd->listName)
	{
	case proOrder:
		col = 10;
		//if (end - sta < 6)
		//	listNumber = 6;
		//else
		//	listNumber = end - sta;
		break;
	case proDetails:
		col = 6;
		//listNumber = end - sta;
		break;
	case proReturn:
		col = 6;
		//listNumber = end - sta;
		break;
	case distriOrder:
		col = 10;
		//if (end - sta < 10)
		//	listNumber = 10;
		//else
		//	listNumber = end - sta;
		break;
	case distriDetails:
		col = 6;
		//listNumber = end - sta;
		break;
	case distriReturn:
		col = 6;
		//listNumber = end - sta;
		break;
	case dataRecv:
	//	col = 45;
		col = 4;
		//listNumber = end - sta;
		break;
	case dataPay:
	//	col = 45;
		col = 4;
		//listNumber = end - sta;
		break;
	case dataOtherIn:
		col = 2;
		//listNumber = end - sta;
		break;
	case dataOtherOut:
		col = 2;
		//listNumber = end - sta;
		break;
	}
	if (col != -1)
	{	
		money = 0.0;
		//小于等于10说明，金额位置唯一
		for (size_t index = sta; index < end; index++)
		{
			money += _ttof(data.at(index).at(col).c_str());
		}

	}
	if (money > 0)
	{
		//绘制
		UpperNumber_zh_CN(money, tmp);
		strBuf << L"金额合计(大写)：" << tmp;
		while (strBuf.str().size() < 24)
			strBuf << " ";
		strBuf << L"金额合计(小写)：￥ " << money;
		list = pdf.add_table_cell(list, 1, 1, strBuf.str(), L"");
	}


	////绘制条例
	//if (pcd->listName == proOrder)
	//{

	//}




	bool first = true;
	do{
		PrintOrderNumber(obj, time);
		optBuf.str(L"");
		optBuf << L"header=1 rowheightdefault=" << 15
			<< L" fill={{area=row1 fillcolor={gray 0.9}}}";
		if (first)
			result = pdf.fit_table(list,
			pageMarginsX, pageMarginsY,
			pageWidth - pageMarginsX, point.y,
			optBuf.str());
		else
			result = pdf.fit_table(list,
			pageMarginsX, pageMarginsY,
			pageWidth - pageMarginsX, pageHeight - pageMarginsY,
			optBuf.str());
		first = false;
		if (result == L"_error") {
			wcerr << L"Couldn't place table: " << pdf.get_errmsg() << endl;
			ShutDownLocal();
			return;
		}
		PrintPage();
		pdf.end_page_ext(L"");
	} while (result == L"_boxfull");
}
void WMPrinter::PrintTime()
{
	pdf.setfont(fontThin, 11);
}
void WMPrinter::PrintChrac()
{
	pdf.setfont(fontBold, 11);
}
void WMPrinter::PrintPage()
{
	pdf.setfont(fontThin, 11);
	strBuf << page;
	SetOptList(11, pageWidth, false, Center_Center);
	pdf.fit_textline(strBuf.str(), 0, 10, GetOptList());
	page++;
}
void WMPrinter::Print(size_t sta, size_t end)
{
	/*int iTmp = -1;
	if (pcd->listName == proOrder || pcd->listName == distriOrder)
	{
		wstring time = data.at(sta).at(0);
		iTmp = sta;
		for (int i = sta; i < end; i++)
		{
			if (time != data.at(i).at(0))
			{
				PrintOrderNumber();
				PrintTitle();
				PrintListHead(iTmp, i);
				PrintList(iTmp, i);
				PrintExtra(iTmp, i);
				PrintChrac();
				PrintTime();
				PrintPage();
				iTmp = i;
			}
		}
		
	}	
	else
	{*/
		PrintOrderNumber();
		PrintTitle();
		PrintListHead(sta, end);
		PrintList(sta, end);
		PrintExtra(sta, end);
		PrintChrac();
		PrintTime();
		PrintPage();
	//}

	

}