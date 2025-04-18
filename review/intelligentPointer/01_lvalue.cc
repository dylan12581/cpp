#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Computer{
public:

private:

};

void test0()
{
    /* &1; */
    int a = 1, b = 2;
    &a;
    /* &(a + b); */

    int * p = new int(10);
    cout << p << endl;
    &(*p);
    delete p;

    /* &String("hello"); */
    string s1("world");
    &s1;

    string * ps = new string("world");
    cout << ps << endl;

    const char * pstr = "world";
    printf("%p\n",pstr);
}

void test2(){
    int a = 1;
    int b = 2;
    int & ref = a;
    /* int & ref2 = a + b; */
    const int & ref2 = a + b;
    cout << &ref2 << endl;

    const string & refs = string("hello");
    cout << &refs << endl;

    const int & ref3 = a;
    string s1("wangdao");
    const string & refs2 = s1;
}

void test3(){
    int a = 1;
    int b = 2;
    //右值引用只能绑定右值，不能绑定左值
    int && ref = a + b;
    /* int && ref2 = a; */
    cout << &ref << endl;
    
    string && refs = string("hello");
    cout << &refs << endl;
}

int main()
{
    test3();
    return 0;
}

