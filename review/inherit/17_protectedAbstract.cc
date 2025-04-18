#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
class Base {
    public:
    virtual
    void print() const{
		cout << "_base:" << _base << endl;
    }
protected:
	Base(int base)
    : _base(base)
    {
        cout << "Base()" << endl;
    }

	int _base;
};
class Derived
:public Base
{
protected:
    Derived(int base, int derived)
	: Base(base)
	, _derived(derived)
    //, _b1(base)
	{ cout << "Derived(int,int)" << endl; }
public:
    void print()const{
        cout << "_base:" << _base <<  _derived << endl;
    }
private:
    int _derived;
    //Base _b1;
};
class Test
:public Derived{
public:
    Test(int base,int derived)
        :Derived(base,derived)
    {}
};


void test0()
{
    Base* pb;
    Derived* pd;
    Test t1(1,2);
    pb = &t1;
    pd = &t1;

    pb->print();
    pd->print();

}

int main(){
    test0();
    return 0;
}

