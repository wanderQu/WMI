// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 SQLITE_DLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// SQLITE_DLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
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