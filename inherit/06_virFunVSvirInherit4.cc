#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class A{
    public:
    virtual void f(){cout << "A:f()" << endl;}
    virtual void af(){cout << "A:af()" << endl;}
    private:
    int _ia;
    char _ca;
    // double a = 10;
};

class A1
:virtual public A
{
    public:
    virtual void f(){cout << "A1:f()" << endl;}
    virtual void f1(){cout << "A1:f1()" << endl;}
    virtual void af1(){cout << "A:af1()" << endl;}
    private:
    int _ia1;
    char _ca1;
    // double a1 = 10;
};

class A2
:virtual public A
{
    public:
    virtual void f(){cout << "A1:f()" << endl;}
    virtual void f2(){cout << "A1:f2()" << endl;}
    virtual void af2(){cout << "A:af2()" << endl;}
    private:
    int _ia2;
    char _ca2;
    // double a1 = 10;
};

class D
:public A1,public A2
{
     public:
    virtual void f(){cout << "D:f()" << endl;}
    virtual void f1(){cout << "D:f1()" << endl;}
    virtual void f2(){cout << "D:f2()" << endl;}
    virtual void df(){cout << "D:df()" << endl;}
    private:
    int _id;
    char _cd;
};

void test0()
{
    
}

int main()
{
    test0();
    return 0;
}


