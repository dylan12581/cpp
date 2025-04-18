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
public:
    Derived(int base, int derived)
	: Base(base)
	, _derived(derived)
    //, _b1(base)
	{ cout << "Derived(int,int)" << endl; }
    void print()const{
        cout << "_base:" << _base <<  _derived << endl;

    }

private:

    int _derived;
    //Base _b1;
};


void test0()
{
    Derived d(1,2);
    Base* pb = &d;
    pb->print();
}

int main(){
    test0();
    return 0;
}

