#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Base{
public:
    Base(long x)
    : _base(x)
    {}

    virtual
    void display() const{
        cout << "Base::display()" << endl;
    }

   private:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long base,long derived)
    : Base(base)
    , _derived(derived)
    {}
    //virtual
    void display() const override{
        cout << "Derived::display()" << endl;
    }
private:
    long _derived;
};
void print(Base* pbase){
    pbase->display();
}


void test0()
{
    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;
    cout << endl;

    Base base(10);
    Derived dd(1,2);

    print(&base);
    cout << endl;
    //用一个基类指针指向派生类对象
    //能够操纵的只有基类部分
    print(&dd);
}
void test1(){

    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;
    cout << endl;


    Derived d1(2,4);
    Base * pb = &d1;
    pb->display();
    Base& pb2 = d1;
    pb2.display();


    Base base(10);
    Base * p2 = &base;
    p2->display();
}
int main()
{
    test1();
    return 0;
}

