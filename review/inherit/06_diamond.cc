#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    void print() const{
        /* cout << "A::print()" << _a << endl; */
        cout << "hello" << endl;
    }
    double _a;
};

class B
: public A
{
public:
    double _b;
};

class C
: public A
{
public:
    double _c;
};

class D
: public B
, public C
{
public:
    //void print() const{
    //    /* cout << "D::print()" << _d << endl; */
    //    cout << "hello" << endl;
    //}
    double _d;
};

void test0(){
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;

    D d1;
    //d1.print();
    //d1.A::print();
    d1.B::print();
    d1.C::print();
}

int main(void){
    test0();
    return 0;
}

