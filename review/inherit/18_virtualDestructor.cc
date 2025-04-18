#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Base
{
public:
    Base()
    : _base(new int(10))
    { cout << "Base()" << endl; }

    virtual void display() const{
        cout << "*_base:" << *_base << endl;
    }

    //virtual
    ~Base(){
        if(_base){
            delete _base;
            _base = nullptr;
        }
        cout << "~Base()" << endl;
    }
private:
    int * _base;
};

class Derived
: public Base{
public:
    Derived()
    : Base()
    , _derived(new int(20))
    {
        cout << "Derived()" << endl;
    }

    virtual void display() const override{
        cout << "*_derived:" << *_derived << endl;
    }

    ~Derived(){
        if(_derived){
            delete _derived;
            _derived = nullptr;
        }
        cout << "~Derived()" << endl;
    }
private:
    int * _derived;
};

void test0()
{
    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;

    Base * pbase = new Derived();
    pbase->display();
    delete pbase;

    Derived* pd = new Derived();
    delete pd;
}

int main()
{
    test0();
    return 0;
}

