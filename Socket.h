// Socket.h: interface for the CSocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOCKET_H__1474B2F5_463A_4C87_AD83_69173C55A5FB__INCLUDED_)
#define AFX_SOCKET_H__1474B2F5_463A_4C87_AD83_69173C55A5FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<WinSock2.h>
#pragma comment (lib,"ws2_32.lib")  
#include<fstream>

class CSocket  
{
public:
	int Send(char*str);
	int Close();
	char* Recv();
	int Init();
	CSocket();
	virtual ~CSocket();

	int init;
	SOCKET LocalSocket;
	sockaddr_in Client_ADDR;
	HANDLE	hCon;

};

#endif // !defined(AFX_SOCKET_H__1474B2F5_463A_4C87_AD83_69173C55A5FB__INCLUDED_)
