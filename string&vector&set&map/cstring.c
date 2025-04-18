#include <string.h>
#include <my_header.h>
void test0()
{
    char str[] = "hello,";
    char * pstr = "world";
    //求取字符串长度
    printf("%ld\n", strlen(str));

    // 比较字符串大小
    char* str1 = "hal";
    char* str2 = "hbl";
    printf("%d\n",strcmp(str1,str2));
    printf("%d\n",strncmp(str1,str2,1));

    //字符串拼接
    char * ptmp = (char*)malloc(strlen(str) + strlen(pstr) + 1);
    strcpy(ptmp, str);
    strcat(ptmp, pstr);
    printf("%s\n", ptmp);
    printf("%ld\n", strlen(ptmp));


    //查找子串
    char * p1 = strstr(ptmp, "world");
    printf("p1:%s\n",p1);
    char* p2 = strchr(ptmp,'l');
    printf("p2:%s\n",p2);
    free(ptmp);

    char str3[] = "llllllll";
    char str4[] = "aaaaaaaa";

    strncpy(str3,str4,10);

    printf("str3  :%s\n",str3);


}

int main()
{
    test0();
    return 0;
}

