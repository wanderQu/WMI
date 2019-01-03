// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� SQLITE_DLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// SQLITE_DLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef SQLITE_DLL_EXPORTS
#define SQLITE_DLL_API __declspec(dllexport)
#else
#define SQLITE_DLL_API __declspec(dllimport)
#endif
#pragma once
#include "sqlite3.h"

extern "C" SQLITE_DLL_API bool DB_open(sqlite3 **db, char *name);
extern "C" SQLITE_DLL_API char* getTbName(int i);
extern "C" SQLITE_DLL_API bool DB_create(sqlite3 *db, char *tbName, char *Key);
extern "C" SQLITE_DLL_API bool DB_insertID(sqlite3 *db, int tbID, char *key, char *value);
extern "C" SQLITE_DLL_API bool DB_insertName(sqlite3 *db, char *tbName, char *key, char *value);
extern "C" SQLITE_DLL_API bool DB_select(sqlite3 *db, sqlite3_callback callback, void *data, char *tbName, char *key = 0);
extern "C" SQLITE_DLL_API bool DB_excuteNoCall(sqlite3 *db, const char *commond, char *errMsg = 0);
extern "C" SQLITE_DLL_API bool DB_excute(sqlite3 *db, const char *commond, sqlite3_callback callback, void *data, char *errMsg = 0);
extern "C" SQLITE_DLL_API bool DB_selectTitle(sqlite3 *db, sqlite3_callback callback, void *data, char *tbName);
extern "C" SQLITE_DLL_API bool DB_close(sqlite3 *db);
extern "C" SQLITE_DLL_API char* U2G(const char* utf8);
extern "C" SQLITE_DLL_API char* G2U(const char* gb2312);