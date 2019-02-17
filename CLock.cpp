#include "stdafx.h"
#include"CLock.h"
CLock::CLock()
{
	hMutex = CreateMutex(NULL, false, "mutex");
	WaitForSingleObject(hMutex, INFINITE);
}
CLock::CLock(TCHAR *szMutexName)
{
	hMutex = CreateMutex(NULL, false, MutexName);
	WaitForSingleObject(hMutex, INFINITE);
}
CLock::~CLock()
{
	ReleaseMutex(hMutex);
	CloseHandle(hMutex);
}
