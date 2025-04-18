#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class A
{
public:
    virtual void print() = 0;
    virtual void display() = 0;
};

class B
: public A
{
public:
    void print() override{
        cout << "B::print()" << endl;
    }
    void display() override{
        cout << "B::display()" << endl;
    }
};

class C
: public A
{
public:
    void print() override{
        cout << "C::print()" << endl;
    }
    /* void display() override{ */
    /*     cout << "C::display()" << endl; */
    /* } */
};

class D
: public C
{
public:
    /* void print() override{ */
    /*     cout << "D::print()" << endl; */
    /* } */
    void display() override{
        cout << "D::display()" << endl;
    }
};
void test0()
{
    //A a;
    B b;
    A* pa = &b;
    pa->print();
    pa->display();
    cout << endl;


    D d;
    A* pa2 = &d;
    pa2->display();
    pa2->print();

    A & ref = d;
    ref.display();
    ref.print();

}

int main()
{
    test0();
    return 0;
}

