#include <iostream>
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
: public Base 
{
public:
	void print() const
	{
		cout << "_base:" << _base
		<< ", _derived:" << _derived << endl;
	}
protected:
	Derived(int base, int derived)
	: Base(base)
	, _derived(derived)
	{ cout << "Derived(int,int)" << endl; }
private:
	int _derived;
};

class Test
: public Derived
{
public:
    Test(int base,int derived)
    : Derived(base,derived)
    {}
};


void test0(){
    Base * pb;
    Derived * pd;
    Test t1(10,20);
    pb = &t1;
    pd = &t1;

    pb->print();
    pd->print();
}

int main(void){
    test0();
    return 0;
}
