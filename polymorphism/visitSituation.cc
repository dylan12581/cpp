#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Grandpa{
public:
    Grandpa() {cout << "Grandpa()" << endl;}
    ~Grandpa(){ cout << "~Grandpa()" << endl; }

    virtual void func1() {
        cout << "Grandpa::func1()" << endl;
    }

    virtual void func2(){
        cout << "Grandpa::func2()" << endl;
    }
};

class Parent
: public Grandpa
{
public:
    Parent(){
        cout << "Parent()" << endl;
        func1();//构造函数中调用虚函数
    }
    virtual void func1() override {
        cout << "Parent::func1()" << endl;
    }
    virtual void func2() override {
        cout << "Parent::func2()" << endl;
    }

    ~Parent(){
        cout << "~Parent()" << endl;
        func2();//析构函数中调用虚函数
    }
};

class Son
: public Parent
{
public:
    Son() { cout << "Son()" << endl; }
    ~Son() { cout << "~Son()" << endl; }

    virtual void func1() override {
        cout << "Son::func1()" << endl;
    }

    virtual void func2() override{
        cout << "Son::func2()" << endl;
    }
};

void test0()
{
    Son ss;
    cout << sizeof(ss) << endl; // 8???
    Grandpa* p = &ss;
    p->func1();
    p->func2();
}

int main()
{
    test0();
    return 0;
}

