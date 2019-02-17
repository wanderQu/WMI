#pragma once
#include"CLock.h"
#define SHARE_MEMORY_NAME TEXT("shareMemoryName")
#define SHARE_MEMORY_SIZE_NAME TEXT("shareMemorySizeName")

typedef enum
{
	LX_OK = 0,						// ��������
	LX_SHAREDMEMORY_EXISTS = 1,		// �����ڴ��Ѿ�����
	LX_INVALID_SHAREDMEMORY = 2,	// �����ڴ���󷵻�
	LX_INVALID_SIZE = 3				// �����ڴ��С����
}LX_RETURN_VALUE;

class CShareMemory
{
public:
	CShareMemory();
	~CShareMemory();

	// ���������ڴ�
	LX_RETURN_VALUE CreateSharedMemory(UINT nSize);
	// �ͷŹ����ڴ�
	LX_RETURN_VALUE ReleaseSharedMemory();
	// �õ������ڴ��С
	LX_RETURN_VALUE GetSharedMemorySize(UINT& nSize);
	// �����ڴ�д������
	LX_RETURN_VALUE WriteToSharedMemory(void *pData, UINT nSize);
	// �ӹ����ڴ��ȡ����
	LX_RETURN_VALUE ReadFromSharedMemory(void *pData, UINT nSize);

	LX_RETURN_VALUE rv;

};

