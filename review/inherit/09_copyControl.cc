#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class Base{
public:
    Base(long x,const char* pstr)
    : _base(x)
    ,_pbase(new char[strlen(pstr) + 1]())
    {
        strcpy(_pbase,pstr);
        /* cout << "Base()" << endl; */
    }
    
    Base(const Base & rhs)
    : _base(rhs._base)
    ,_pbase(new char[strlen(rhs._pbase) + 1]())
    {
        strcpy(_pbase,rhs._pbase);
        cout << "Base的拷贝构造函数" << endl;
    }

    Base& operator=(const Base & rhs){
        if(this != &rhs){
            delete []_pbase;
            _pbase = new char[strlen(rhs._pbase) + 1]();
            strcpy(_pbase,rhs._pbase);
            cout << "Base的赋值运算符函数" << endl;
            _base = rhs._base;
            return *this;
    }
}
    ~Base(){
        if(_pbase){
            delete []_pbase;
            _pbase = nullptr;
        }
    }
    
protected:
    long _base;
    char* _pbase;
};

class Derived
: public Base
{
public:
    Derived(long base,long derived,const char* pstr)
    : Base(base,pstr)
    , _derived(derived)
    {
        /* cout << "Derived()" << endl; */
    }

    Derived(const Derived & rhs)
    : Base(rhs)//显式调用Base类的拷贝构造函数
    , _derived(rhs._derived)
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
        cout << "_pbase:" << _pbase << endl;
    }
private:
    long _derived;
};
void test0(){
    Derived d1(20,30,"aa");
    Derived d2(60,70,"cc");
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
