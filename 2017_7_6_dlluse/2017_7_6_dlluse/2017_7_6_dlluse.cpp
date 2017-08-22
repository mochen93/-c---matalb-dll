// 2017_7_6_dlluse.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
/***********************************************************************/
/*��鿴dll,�����躯������ָ�붨������
*/
typedef int(*padd)(int a, int b);
/**********************************************************************/
/*�꺯��CALLFUNCTIONFROMDLL
dllname ����dll����
functionname dll�е��ú�������
functiontype �Ͻ��������庯��������ָ��
returntype  ��������ֵ
defaultreturnvalue   ��������ʱ����ֵ*/
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
	printf("��������ʧ��\n"); \
}\
	hDll = (HMODULE)0; \
}\
else \
{\
	printf("��DLLʧ��\n");\
}\
	return eRet;
/****************************************************/
//��һ�㺯���������,��Ϊ�꺯��������ֵ
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
	    hDLL = LoadLibrary("2017.7.6. _DLL.dll");//���ض�̬���ӿ�MyDll.dll�ļ���
		add= (padd)GetProcAddress(hDLL, "Add");
		int A = add (5, 8);
		*/
	int A = ADD(5, 8);
	printf("�ȽϵĽ��Ϊ%d\n",A);
	int B = nest(5, 8);
	printf("�ȽϵĽ��Ϊ%d\n", B);

		//FreeLibrary(hDLL);//ж��MyDll.dll�ļ���
	
	return 0;
}

