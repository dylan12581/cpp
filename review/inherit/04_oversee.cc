#include <iostream>
using std::cout;
using std::endl;

class Base{
public:
    Base(long x)
    : _base(x)
    {
        /* cout << "Base()" << endl; */
    }

    void print() const{
        cout << "Base::_base:" << _base << endl;
        cout << "Base::_data:" << _data  << endl;
    }
    
    long _data = 100;
private:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long base,long derived)
    : Base(base)//初始化基类子对象
    , _derived(derived)
    {
        /* cout << "Derived()" << endl; */
    }

    void print(int x) const{
        cout << "Derived::_derived:" << _derived << endl;
        cout << "Derived::_data:" << _data  << endl;
    }
    
    char _data = 'A';
private:
    long _derived;
};

void test0(){

    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;
    cout << endl;

    Derived d1(1,2);
    cout << d1._data << endl;
    cout << d1.Base::_data << endl;

    cout << endl;
    d1.print(10);
    d1.Base::print();
}

int main(void){
    test0();
    return 0;
}

