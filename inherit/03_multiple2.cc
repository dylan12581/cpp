#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class A{
public:
    void print()const{
        cout << "A::print()" << endl;
    }
    double _a;
private:
};
class B:public A
{
public:
    double _b;
};
class C:public A{
public:
    double _c;
};
class D:public B,public C{
public:
    double _d;
    void print()const{
        cout << "D::print()" << endl;
    }
};

void test0()
{
    D dd;
    dd.B::print();
    dd.print();
    cout << sizeof(D) << endl;
}

int main()
{
    test0();
    return 0;
}

