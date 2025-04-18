#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class A{
    void func(){}
    virtual void run(){cout << "A:run()" << endl;}
    virtual void run1(){cout << "A:run1()" << endl;}
    virtual void run2(){cout << "A:run2()" << endl;}
    double a = 10;
};

class B
:virtual public A
{
    void run(){cout << "B:run()" << endl;}
    void run1(){cout << "B:run1()" << endl;}
    double b = 1;
};
void test0()
{
    
}

int main()
{
    test0();
    return 0;
}

