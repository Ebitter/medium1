#include "include/cw_mutil_thread_feature_extract.h"
#include "mylib.h"
#include "string.h"

char pCharY[100];
char pCharZ[100];
MYLIB_H_DLL_C int mylib_get_version(long long handle,char* szVersion)
{
    printf("mylib get version\n");
    return cw_mutil_thread_feature_extract_get_version(handle, szVersion);
}

MYLIB_H_DLL_C int mylib_cGO_test(Mylib_cGO_test  *test)
{
    printf("mylib_cGO_test\n");
    CGO_TEST tmp;
    tmp.pCharZ = new char[100];
    int ret = cw_cGO_test(&tmp);
    test->intX = tmp.intX;
    memcpy(test->pCharZ, tmp.pCharZ, strlen(tmp.pCharZ));
    test->size_pCharZ = strlen(tmp.pCharZ);
    test->size_stringY = tmp.stringY.size();
    memcpy(test->stringY, tmp.stringY.c_str(), tmp.stringY.size());
    delete []tmp.pCharZ;

    return ret;
}
MYLIB_H_DLL_C int mylib_get_int(void)
{
    return 1920;
}
MYLIB_H_DLL_C char *mylib_get_char_buf(int len)
{
    return new char[len];
}

MYLIB_H_DLL_C int mylib_delete_char_buf(char *buf)
{
    delete []buf;
    return 0;
}
