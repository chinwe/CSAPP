#include "stdafx.h"
#include "Header.h"
#include <stdio.h>

//判断两个无符号整数相加是否溢出
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

//uadd_ok测试函数
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

//判断两个有符号整数相加是否溢出
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

//tadd_ok测试函数
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