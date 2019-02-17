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
	// ���������ڴ��
	HANDLE hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, nSize, SHARE_MEMORY_NAME);

	// ��������
	if ((hFileMapping == NULL) || (hFileMapping == INVALID_HANDLE_VALUE))
		return LX_INVALID_SHAREDMEMORY;

	// �����ڴ��Ѿ�����
	if (GetLastError() == ERROR_ALREADY_EXISTS)
		return LX_SHAREDMEMORY_EXISTS;

	// ��������һ���ڴ��Ź����ڴ�Ĵ�С
	HANDLE hSize = CreateFileMapping(NULL, NULL, PAGE_READWRITE, 0, sizeof(UINT), SHARE_MEMORY_SIZE_NAME);

	if ((hSize == NULL) || (hSize == INVALID_HANDLE_VALUE) || (GetLastError() == ERROR_ALREADY_EXISTS))
		return LX_INVALID_SHAREDMEMORY;

	// �õ���Ź����ڴ��С��ָ��
	UINT *pSize = (UINT *)MapViewOfFile(hSize, FILE_MAP_WRITE, 0, 0, sizeof(UINT));

	if (pSize == NULL)
		return LX_INVALID_SHAREDMEMORY;

	// д�빲���ڴ�Ĵ�С
	memcpy(pSize, &nSize, sizeof(UINT));

	UnmapViewOfFile(pSize);

	return LX_OK;
}

LX_RETURN_VALUE CShareMemory::ReleaseSharedMemory()
{
	CLock lock;
	// �򿪹����ڴ�
	HANDLE hFileMapping = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, SHARE_MEMORY_NAME);

	// �رչ����ڴ�
	if (hFileMapping != NULL)
		CloseHandle(hFileMapping);

	// �򿪴�Ź����ڴ��С���ļ�ӳ��
	HANDLE hSize = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, SHARE_MEMORY_SIZE_NAME);

	// �رմ�Ź����ڴ��С���ļ�ӳ��
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

	// �õ������ڴ�Ĵ�С
	memcpy(&nSize, pSize, sizeof(UINT));

	return LX_OK;
}

LX_RETURN_VALUE CShareMemory::WriteToSharedMemory(void *pDate, UINT nSize)
{
	UINT nSharedMemorySize = 0;

	// �õ������ڴ�Ĵ�С
	if (GetSharedMemorySize(nSharedMemorySize) != LX_OK)
		return LX_INVALID_SHAREDMEMORY;

	// ��鹲���ڴ�Ĵ�С
	if (nSize > nSharedMemorySize)
		return LX_INVALID_SIZE;

	CLock lock;

	HANDLE hFileMapping = OpenFileMapping(FILE_MAP_WRITE, FALSE, SHARE_MEMORY_NAME);

	if (hFileMapping == NULL)
		return LX_INVALID_SHAREDMEMORY;

	void *pMapView = MapViewOfFile(hFileMapping, FILE_MAP_WRITE, 0, 0, nSize);

	if (pMapView == NULL)
		return LX_INVALID_SHAREDMEMORY;

	// ��չ����ڴ�
	memset(pMapView, 0, nSharedMemorySize);

	// ������д�빲���ڴ�
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

	// �ӹ����ڴ��ȡ����
	memcpy(pData, pMapView, nSize);
	UnmapViewOfFile(pMapView);

	return LX_OK;
}