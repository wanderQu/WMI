#pragma once
#include"CLock.h"
#define SHARE_MEMORY_NAME TEXT("shareMemoryName")
#define SHARE_MEMORY_SIZE_NAME TEXT("shareMemorySizeName")

typedef enum
{
	LX_OK = 0,						// 正常返回
	LX_SHAREDMEMORY_EXISTS = 1,		// 共享内存已经存在
	LX_INVALID_SHAREDMEMORY = 2,	// 共享内存错误返回
	LX_INVALID_SIZE = 3				// 共享内存大小错误
}LX_RETURN_VALUE;

class CShareMemory
{
public:
	CShareMemory();
	~CShareMemory();

	// 创建共享内存
	LX_RETURN_VALUE CreateSharedMemory(UINT nSize);
	// 释放共享内存
	LX_RETURN_VALUE ReleaseSharedMemory();
	// 得到共享内存大小
	LX_RETURN_VALUE GetSharedMemorySize(UINT& nSize);
	// 向共享内存写入数据
	LX_RETURN_VALUE WriteToSharedMemory(void *pData, UINT nSize);
	// 从共享内存读取数据
	LX_RETURN_VALUE ReadFromSharedMemory(void *pData, UINT nSize);

	LX_RETURN_VALUE rv;

};

