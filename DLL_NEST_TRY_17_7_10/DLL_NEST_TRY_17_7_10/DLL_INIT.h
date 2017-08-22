#ifndef Dll_INIT_H_
#define Dll_INIT_H_
#ifdef MYDLL
#define MYDLL extern "C" _declspec(dllimport) 
#else
#define MYDLL extern "C" _declspec(dllexport) 
#endif
MYDLL int dll_nest(int plus1, int plus2);
//You can also write like this:
//extern "C" {
//_declspec(dllexport) int Add(int plus1, int plus2);
//};
#endif