#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Base{
public:
    Base(long x)
    : _base(x)
    {}

    virtual void display() const{
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
    Base base(10);
    Derived dd(1,2);
    Base* pb = &base;
    pb->display();

    Base& rb = base;
    rb.display();

    Base* pb2 = &dd;
    pb2->display();
    Base& rb2 = dd;
    rb2.display();

    print(&base);
    cout << endl;
    print(&dd);
    
    cout << "sizeof(Base):" << sizeof(Base) << endl;
    cout << "sizeof(Derived):" << sizeof(Derived) << endl;
}

int main()
{
    test0();
    return 0;
}

