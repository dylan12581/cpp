#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Base {
public:
	Base(int base = 1)
    : _base(base)
    {
        /* cout << "Base()" << endl; */
    }

    Base & operator=(const Base & rhs)
    {
        cout << "Base的赋值运算符函数" << endl;
        _base = rhs._base;
        return *this;
    }
    virtual
    void print() const{
        cout << _base << endl;
    }
/* private: */
	long _base;
};

class Derived
: public Base
{
public:
	Derived(long base = 2,long derived = 3)
    : Base(base)
	, _derived(derived)
	{
        cout << "Derived(long)" << endl; 
    }
/* private: */
	long _derived;
};

void test0()
{
    Base base;
    Derived d1;
    base = d1;
    base.print();
}
void test1()
{
    Base base;
    Derived d1;
    Base* pbase = &d1;

    //C语言的转换不会区分是否合理
    Derived * p1 = (Derived*)pbase;
    cout << p1->_derived << endl;
    p1->print();

    Derived* pDer =dynamic_cast<Derived*> (pbase);
    if(pDer){
       pDer->print();
    }else{
       cout << "typecast failed" << "\n";
    }

}

int main()
{
    test1();
    return 0;
}

