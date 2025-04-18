#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Base {
public:
	Base(){ cout << "Base()" << endl; }

    Base(int base)
    : _base(base)
    {
        cout << "Base(int)" << endl;
    }

    ~Base(){
        cout << "~Base()" << endl;
    }

private:
	long _base;
};

class Test{
public:
    Test(long test)
    : _test(test)
    { cout << "Test()" << endl; }

    ~Test(){ cout << "~Test()" << endl; }
private:
    long _test;
};

class Derived
: public Base
{
public:
	Derived(long base,long derived,long test,long de)
    // : Base()  //自动调用Base的无参构造
    : Base(base)//显式调用Base的构造函数初始化基类子对象
	, _derived(derived)
    , _t1(test)//显式调用Test的构造函数初始化成员子对象
    , _b1(de)//显式调用Base的构造函数初始化成员子对象
	{ cout << "Derived(long,long)" << endl; }

    ~Derived(){
        cout << "~Derived()" << endl;
    }
private:
	long _derived;
    Test _t1;
    Base _b1;
};


void test0()
{
    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;
    Derived d1(1,2,3,4);
}


int main()
{
    test0();
    return 0;
}

