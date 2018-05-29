//#include <QCoreApplication>
#include "stdio.h"
#include "include/cw_mutil_thread_feature_extract.h"
int main(int argc, char *argv[])
{
    _cGO_test test;
    test.pCharZ = new char[100];
    printf("test.x= %d\n", test.intX);
    printf("test Y=%s\n", test.stringY.c_str());
    printf("test Z=%s\n", test.pCharZ);

    long long handle;
    char* szVersion;
    cw_mutil_thread_feature_extract_get_version(handle, szVersion);

    cw_cGO_test(&test);
    printf("test.x= %d\n", test.intX);
    printf("test Y=%s\n", test.stringY.c_str());
    printf("test Z=%s\n", test.pCharZ);

}
