// Socket.cpp: implementation of the CSocket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WMI.h"
#include "Socket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSocket::CSocket()
{
	init = 0;
}

CSocket::~CSocket()
{
	Close();
	closesocket(LocalSocket);
}

int CSocket::Init()
{
	std::ifstream in(".\\UserData\\Server.txt");
	char IP[20];
	in >> IP;
	in.close();
	int iResult = 0;
	WSADATA wsaData;
	LocalSocket = INVALID_SOCKET;
	unsigned int port = 10000;
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR){
		return 1;
	}
	LocalSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (LocalSocket == INVALID_SOCKET)
	{
	//	printf("socket failed with error:%d\n", WSAGetLastError());
		return 1;
	}
	Client_ADDR.sin_family = AF_INET;
	Client_ADDR.sin_port = port;
	Client_ADDR.sin_addr.S_un.S_addr = inet_addr(IP);
	
	init = 1;
	return 0;
}
char* CSocket::Recv()
{
	char rcvBuf[1024];
	int iResult = recv(LocalSocket, rcvBuf, 1024, 0);
	if (iResult > 0)
	{
		
		if (strcmp(rcvBuf, "over") == 0)
			return NULL;
		else
			return rcvBuf;
	}
	else if (iResult == 0)
		return NULL;
	
	else
	{
	//	printf("rcv failed : %d\n", WSAGetLastError());
		return NULL;
	}
	return NULL;
}

int CSocket::Close()
{
	closesocket(LocalSocket);
	WSACleanup();
	return 1;
}

int CSocket::Send(char *str)
{
	if (!init)
	{
		if (Init())
		{
			return 1;
		}	
	}
	int iResult = connect(LocalSocket, (SOCKADDR*)&Client_ADDR, sizeof(Client_ADDR));
	if (iResult == SOCKET_ERROR){
		closesocket(LocalSocket);
	//	printf("unable to connect to server:%d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	send(LocalSocket,str,strlen(str), 0);
	Sleep(10);

	WSACleanup();
	return 0;
}
