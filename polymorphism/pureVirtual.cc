#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class A{
public:
    virtual void print() = 0;
    virtual void display() = 0;
};
class B
:public A
{
public:
    virtual void print()override{
        cout << "B::print()" << endl;
    }
};

class C
:public B
{
    virtual void display() override{
        cout << "C::display()" << endl;
    }
};

void test0()
{
    //A aa;
    // B bb;
    C cc;
    A* pa = &cc;
    pa->print();
    pa->display();
    B* pb = &cc;
    pb->print();
    pb->display();
}

int main()
{
    test0();
    return 0;
}

