#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// 最小字符串优化
void test0()
{
    string str1("hello world");
    cout << str1.size() << endl;
    cout << str1.capacity() << endl;
    cout << &str1 << endl;// 栈地址
    printf("%p\n",&str1[0]);// 

    cout << endl;
    string str2("hello,world!!!!!!!");
    cout << str2.size() << endl;
    cout << str2.capacity() << endl;
    cout << &str2 << endl;
    printf("%p\n",&str2[0]);

    cout << endl;
    string str3 = str2;
    cout << str3.size() << endl;
    cout << str3.capacity() << endl;
    cout << &str3 << endl;
    printf("%p\n",&str3[0]);
    

    cout << sizeof(str1) << endl;
    cout << sizeof(str2) << endl;
    cout << sizeof(str3) << endl;
    cout << sizeof(size_t) << endl;// 无符号整数，64位平台为8个字节
}

int main()
{
    test0();
    return 0;
}

