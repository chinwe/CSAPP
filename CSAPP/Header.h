#ifndef HEADER_H
#define HEADER_H

//判断两个无符号整数相加是否溢出
int uadd_ok(unsigned x, unsigned y);

//uadd_ok测试函数
void test_uadd_ok();

//判断两个有符号整数相加是否溢出
int tadd_ok(int x, int y);

//tadd_ok测试函数
void test_tadd_ok();

#endif // !HEADER_H

