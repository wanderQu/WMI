#pragma once
#include "stdafx.h"
class CLock
{
public:
	CLock();
	CLock(TCHAR *szMutexName);
	~CLock();
private:
	TCHAR	*MutexName;
	HANDLE	hMutex;
};
