// 2017_7_6_dlluse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
/***********************************************************************/
/*请查看dll,将所需函数类型指针定义如下
*/
typedef int(*padd)(int a, int b);
/**********************************************************************/
/*宏函数CALLFUNCTIONFROMDLL
dllname 调用dll名称
functionname dll中调用函数名称
functiontype 上节中所定义函数的类型指针
returntype  返回类型值
defaultreturnvalue   发生错误时返回值*/
/************************************************************************/
#define CALLFUNCTIONFROMDLL(dllname,functionname,functiontype,returntype,defaultreturnvalue,...) \
	HMODULE hDll = (HMODULE)0; \
	functiontype pFun = (functiontype)0; \
	returntype eRet = (defaultreturnvalue); \
if (hDll = LoadLibrary(dllname))\
{\
	eRet = 2; \
if (pFun = (functiontype)GetProcAddress(hDll, functionname))\
	eRet = pFun(##__VA_ARGS__); \
else \
{\
	printf("函数调用失败\n"); \
}\
	hDll = (HMODULE)0; \
}\
else \
{\
	printf("打开DLL失败\n");\
}\
	return eRet;
/****************************************************/
//多一层函数方便调用,因为宏函数不允许赋值
/******************************************************/
int __stdcall ADD(int a, int b)
{
	//CALLFUNCTIONFROMDLL ("2017.7.6. _DLL.dll", "Add", padd, int,(int)1,a,b)
     CALLFUNCTIONFROMDLL("2017_7_6_dllinit2.dll", "Add", padd, int, -1, a, b)
}
int __stdcall nest(int a, int b)
{
	//CALLFUNCTIONFROMDLL ("2017.7.6. _DLL.dll", "Add", padd, int,(int)1,a,b)
	CALLFUNCTIONFROMDLL("DLL_NEST_TRY_17_7_10.dll", "dll_nest", padd, int, -1, a, b)
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	/*
		HINSTANCE hDLL;
		padd add;
	    hDLL = LoadLibrary("2017.7.6. _DLL.dll");//加载动态链接库MyDll.dll文件；
		add= (padd)GetProcAddress(hDLL, "Add");
		int A = add (5, 8);
		*/
	int A = ADD(5, 8);
	printf("比较的结果为%d\n",A);
	int B = nest(5, 8);
	printf("比较的结果为%d\n", B);

		//FreeLibrary(hDLL);//卸载MyDll.dll文件；
	
	return 0;
}

