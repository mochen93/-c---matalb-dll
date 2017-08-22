// DLL_NEST_TRY_17_7_10.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <windows.h>
#include "DLL_INIT.h"
typedef int(*padd)(int a, int b);
#define CALLFUNCTIONFROMDLL(dllname,functionname,functiontype,returntype,defaultreturnvalue,...) \
	HMODULE hDll = (HMODULE)0; \
	functiontype pFun = (functiontype)0; \
	returntype eRet = (defaultreturnvalue); \
if (hDll = LoadLibrary(dllname))\
{\
	eRet = 2; \
if (pFun = (functiontype)GetProcAddress(hDll, functionname))\
	eRet = pFun(##__VA_ARGS__); \
	hDll = (HMODULE)0; \
}\
	return eRet;

int __stdcall ADD(int a, int b)
{
	//CALLFUNCTIONFROMDLL ("2017.7.6. _DLL.dll", "Add", padd, int,(int)1,a,b)
	CALLFUNCTIONFROMDLL("2017_7_6_dllinit2.dll", "Add", padd, int, (int)1, a, b)
}
int dll_nest(int plus1, int plus2)
{   
	int t =	ADD(plus1,plus2);
	t = t*t;
	return t;
    
}

