#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
//#ifdef _WIN32
//#define MYLIB_H_C_EXPORTS
//#endif

//#ifdef MYLIB_H_C_EXPORTS
//#define MYLIB_H_DLL_C __declspec(dllexport)
//#else
//#define MYLIB_H_DLL_C
//#endif
//extern "C" {
int mylib_get_version(long long handle,char* szVersion);


typedef struct _Mylib_cGO_test
{
    int intX;
    char *stringY;
    int size_stringY;
    char *pCharZ;
    int size_pCharZ;
} Mylib_cGO_test;
int mylib_cGO_test(Mylib_cGO_test  *test);

int mylib_get_int(void);
char *mylib_get_char_buf(int len);

int mylib_delete_char_buf(char *buf);

//}

#endif // MYLIB_H
