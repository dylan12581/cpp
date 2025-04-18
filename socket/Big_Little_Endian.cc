#include "stdio.h"
#include <arpa/inet.h>


void test0()
{
    int num = 0x12345678;
    char* p =(char*) &num;
    printf("%x\n",*p);

    printf("小端转换为大端\n");
    int res = htonl(num);
    p = (char*)&res;
    printf("%x\n",*p);
}

int main()
{
    test0();
    return 0;
}

