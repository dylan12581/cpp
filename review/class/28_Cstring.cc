#include <string.h>
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;


void test0()
{
    char str[] = "hello,";
	char * pstr = "world";
	//求取字符串长度
	printf("%zu\n", strlen(str));

	//字符串拼接
	char * ptmp = (char*)malloc(strlen(str) + strlen(pstr) + 1);
	strcpy(ptmp, str);
	strcat(ptmp, pstr);
	printf("%s\n", ptmp);

	//查找子串
	char * p1 = strstr(ptmp, "world");
	printf("%s\n", p1);

	free(ptmp);
}

int main()
{
    test0();
    return 0;
}

