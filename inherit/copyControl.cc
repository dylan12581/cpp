#include <iostream>
using std::cout;
using std::endl;

class Base{
public:
    Base(long x = 0)
    : _base(x)
    {
        /* cout << "Base()" << endl; */
    }
    
    Base(const Base & rhs)
    : _base(rhs._base)
    {
        cout << "Base的拷贝构造函数" << endl;
    }

    Base& operator=(const Base & rhs){
        cout << "Base的赋值运算符函数" << endl;
        _base = rhs._base;
        return *this;
    }
    
protected:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long base,long derived)
    : Base(base)
    , _derived(derived)
    {
        /* cout << "Derived()" << endl; */
    }

    Derived(const Derived & rhs)
    :Base(rhs)//显式调用Base类的拷贝构造函数
     ,_derived(rhs._derived)
    {
        cout << "Derived的拷贝构造函数" << endl;
    }
    
    Derived & operator=(const Derived & rhs){
        Base::operator=(rhs);//显式调用Base类的赋值运算符函数
        _derived = rhs._derived;
        cout << "Derived的赋值运算符函数" << endl;
        return *this;
    }

    void print() const{
        cout << "_base:" << _base << endl;
        cout << "_derived:" << _derived << endl;
    }
private:
    long _derived;
};

void test0(){
    Derived d1(20,30);
    Derived d2(60,70);
    Derived d3 = d1;
    d3.print();

    cout << endl;
    d2 = d1;
    d2.print();
}


int main(void){
    test0();
    return 0;
}

