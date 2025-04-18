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
	Derived(int base, int derived)
	: Base(base)
	, _derived(derived)
    // ,_b1(base)
    /* , _b1(base) */
	{ cout << "Derived(int,int)" << endl; }

	void print() const
	{
		cout << "_base:" << _base
		<< ", _derived:" << _derived << endl;
	}
private:
	int _derived;
    Base _b1; 
};


class Test
{
public:
    Test(int x)
    // : _b1(x)
    {}
private:
    // Base _b1;
};


void test0(){
    //Base类是抽象类
    /* Base base(10); */
    Derived d1(4,8);
    Base * pb = &d1;
    pb->print();
    Test(10);
}

int main(void){
    test0();
    return 0;
}
