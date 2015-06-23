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
