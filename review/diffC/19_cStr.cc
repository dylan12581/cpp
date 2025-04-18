#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:

private:

};

void test0()
{
    char arr[6] = {'h','e','l','l','o'};
    cout << arr << endl;
    cout << arr + 1 << endl;

    //要留出位置放空字符
    char arr2[] = {'h','e','l','l','o','\0'};
    char arr3[] = "world";

    printf("%p\n",&arr3[0]);
    cout << arr2 << endl;
    cout << arr3 << endl;

    cout << endl;
    char ch1 = 'a';
    char ch2 = 'b';
    char ch3 = '\0';
    char arr4[] = {ch1,ch2,ch3};
    printf("%p\n",&ch1);
    printf("%p\n",&arr4[0]);
}

void test1(){
    const char* p  = "hello";
    cout << p << endl;
    printf("%p\n",p);

    char* pstr = new char[strlen(p) + 1]();
    strcpy(pstr,p);
    cout << pstr << endl;
    printf("%p\n",pstr);
    delete  []pstr;
    pstr = nullptr;
}
void test2(){
    char arr[] = {'i','o','u'};
    char arr2[] = "world";
    cout << arr << endl;
}
void test3(){
    char arr[] = {'i','o','u'};
    "world";
    char arr2[] = "helll";
    char arr3[] = "wangdao";
    cout << arr << endl;
    cout << arr2 << endl;
    cout << arr3 << endl;

    printf("%p\n",arr);
    printf("%p\n",arr2);
    printf("%p\n",arr3);
}
void test4(){
    const char* pstr = "hello";
    //pstr[0] = 'H';
    cout << pstr << endl;
    printf("%p\n",pstr);    
    printf("%p\n",&pstr);
    printf("%s\n",pstr);
}
void test5(){
    const char* p = "hello";
    cout << sizeof(p) << endl;
    cout << strlen(p) << endl;
    char* pstr = new char[strlen(p) + 1]();
    strcpy(pstr,p);
    cout << pstr << endl;
    printf("%p\n",pstr);
    printf("%p\n",p);
    
}
int main()
{
    test4();
    return 0;
}

