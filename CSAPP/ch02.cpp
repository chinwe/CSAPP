#include "stdafx.h"
#include "Header.h"
#include <stdio.h>

//�ж������޷�����������Ƿ����
int uadd_ok(unsigned x, unsigned y)
{
    int iOk = 0;
    if ((x + y) >= x)
    {
        //not overflow
        iOk = 1;
    }

    return iOk;
}

//uadd_ok���Ժ���
void test_uadd_ok()
{
    printf("call test_uadd_ok() \n");
    
    unsigned x = 10u;
    unsigned y = 20u;
    unsigned ret = uadd_ok(x, y);

    printf("uadd_ok(%u, %u) ret %d \n", x, y, ret);

    x = 0xFFFFFFFFu;
    y = 0u;
    ret = uadd_ok(x, y);
    printf("uadd_ok(%u, %u) ret %d \n", x, y, ret);
    
    x = 0xFFFFFFFFu;
    y = 123u;

    ret = uadd_ok(x, y);
    printf("uadd_ok(%u, %u) ret %d \n", x, y, ret);

    printf("============================================================================\n");

}

//�ж������з�����������Ƿ����
int tadd_ok(int x, int y)
{
    int sum = x + y;

    if (x < 0 && y < 0 && sum >= 0)
    {
        return 0;   //negative overflow
    }

    if (x >= 0 && y >= 0 && sum < 0)
    {
        return 0;   //positive overflow
    }

    return 1;
}

//tadd_ok���Ժ���
void test_tadd_ok()
{
    printf("call test_tadd_ok() \n");

    int x = 10;
    int y = 20;
    int ret = tadd_ok(x, y);

    printf("tadd_ok(%u, %u) ret %d \n", x, y, ret);

    x = 0x7FFFFFFF;
    y = 0x7FFFFFFF;
    ret = tadd_ok(x, y);
    printf("tadd_ok(%d, %d) ret %d \n", x, y, ret);

    x = 0x80000000;
    y = 0x80000000;

    ret = tadd_ok(x, y);
    printf("tadd_ok(%d, %d) ret %d \n", x, y, ret);

    x = 0xFFFFFFFF;
    y = 0x80000001;

    ret = tadd_ok(x, y);
    printf("tadd_ok(%d, %d) ret %d \n", x, y, ret);

    printf("============================================================================\n");

}