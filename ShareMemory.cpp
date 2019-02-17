#include "stdafx.h"
#include "ShareMemory.h"


CShareMemory::CShareMemory()
{

}


CShareMemory::~CShareMemory()
{

}

LX_RETURN_VALUE CShareMemory::CreateSharedMemory(UINT nSize)
{
	// 创建共享内存块
	HANDLE hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, nSize, SHARE_MEMORY_NAME);

	// 创建错误
	if ((hFileMapping == NULL) || (hFileMapping == INVALID_HANDLE_VALUE))
		return LX_INVALID_SHAREDMEMORY;

	// 共享内存已经存在
	if (GetLastError() == ERROR_ALREADY_EXISTS)
		return LX_SHAREDMEMORY_EXISTS;

	// 创建另外一块内存存放共享内存的大小
	HANDLE hSize = CreateFileMapping(NULL, NULL, PAGE_READWRITE, 0, sizeof(UINT), SHARE_MEMORY_SIZE_NAME);

	if ((hSize == NULL) || (hSize == INVALID_HANDLE_VALUE) || (GetLastError() == ERROR_ALREADY_EXISTS))
		return LX_INVALID_SHAREDMEMORY;

	// 得到存放共享内存大小的指针
	UINT *pSize = (UINT *)MapViewOfFile(hSize, FILE_MAP_WRITE, 0, 0, sizeof(UINT));

	if (pSize == NULL)
		return LX_INVALID_SHAREDMEMORY;

	// 写入共享内存的大小
	memcpy(pSize, &nSize, sizeof(UINT));

	UnmapViewOfFile(pSize);

	return LX_OK;
}

LX_RETURN_VALUE CShareMemory::ReleaseSharedMemory()
{
	CLock lock;
	// 打开共享内存
	HANDLE hFileMapping = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, SHARE_MEMORY_NAME);

	// 关闭共享内存
	if (hFileMapping != NULL)
		CloseHandle(hFileMapping);

	// 打开存放共享内存大小的文件映射
	HANDLE hSize = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, SHARE_MEMORY_SIZE_NAME);

	// 关闭存放共享内存大小的文件映射
	if (hSize != NULL)
		CloseHandle(hSize);

	return LX_OK;
}

LX_RETURN_VALUE CShareMemory::GetSharedMemorySize(UINT& nSize)
{
	CLock lock;

	HANDLE hSize = OpenFileMapping(FILE_MAP_READ, FALSE, SHARE_MEMORY_SIZE_NAME);

	if (hSize == NULL)
		return LX_INVALID_SHAREDMEMORY;

	UINT *pSize = (UINT *)MapViewOfFile(hSize, FILE_MAP_READ, 0, 0, sizeof(UINT));

	if (pSize == NULL)
		return LX_INVALID_SHAREDMEMORY;

	// 得到共享内存的大小
	memcpy(&nSize, pSize, sizeof(UINT));

	return LX_OK;
}

LX_RETURN_VALUE CShareMemory::WriteToSharedMemory(void *pDate, UINT nSize)
{
	UINT nSharedMemorySize = 0;

	// 得到共享内存的大小
	if (GetSharedMemorySize(nSharedMemorySize) != LX_OK)
		return LX_INVALID_SHAREDMEMORY;

	// 检查共享内存的大小
	if (nSize > nSharedMemorySize)
		return LX_INVALID_SIZE;

	CLock lock;

	HANDLE hFileMapping = OpenFileMapping(FILE_MAP_WRITE, FALSE, SHARE_MEMORY_NAME);

	if (hFileMapping == NULL)
		return LX_INVALID_SHAREDMEMORY;

	void *pMapView = MapViewOfFile(hFileMapping, FILE_MAP_WRITE, 0, 0, nSize);

	if (pMapView == NULL)
		return LX_INVALID_SHAREDMEMORY;

	// 清空共享内存
	memset(pMapView, 0, nSharedMemorySize);

	// 将数据写入共享内存
	memcpy(pMapView, pDate, nSize);

	UnmapViewOfFile(pMapView);

	return LX_OK;
}

LX_RETURN_VALUE CShareMemory::ReadFromSharedMemory(void *pData, UINT nSize)
{
	UINT nSharedMemorySize = 0;

	if (GetSharedMemorySize(nSharedMemorySize) != LX_OK)
		return LX_INVALID_SHAREDMEMORY;

	if (nSize > nSharedMemorySize)
		return LX_INVALID_SIZE;

	CLock lock;

	HANDLE hFileMapping = OpenFileMapping(FILE_MAP_READ, FALSE, SHARE_MEMORY_NAME);

	if (hFileMapping == NULL)
		return LX_INVALID_SHAREDMEMORY;

	void *pMapView = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, nSize);

	if (pMapView == NULL)
		return LX_INVALID_SHAREDMEMORY;

	// 从共享内存读取数据
	memcpy(pData, pMapView, nSize);
	UnmapViewOfFile(pMapView);

	return LX_OK;
}