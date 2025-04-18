#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
class Base{
public:
    Base(long base,const char * pbase)
        : _base(base)
          , _pbase(new char[strlen(pbase) + 1]())
    {
        strcpy(_pbase,pbase);
    }

    ~Base(){
        if(_pbase){
            delete [] _pbase;
            _pbase = nullptr;
        }
    }

    Base(const Base & rhs)
        : _base(rhs._base)
          , _pbase(new char[strlen(rhs._pbase) + 1]())
    {
        cout << "Base的拷贝构造" << endl;
        strcpy(_pbase,rhs._pbase);
    }

    Base & operator=(const Base & rhs){
        if(this != &rhs){
            cout << "Base赋值运算符函数" << endl;
            delete [] _pbase;
            _pbase = new char[strlen(rhs._pbase) + 1]();
            strcpy(_pbase,rhs._pbase);
            _base = rhs._base;
        }
        return *this;
    }
protected:
    long _base = 10;
    char * _pbase;
};

class Derived
: public Base
{
public:
    Derived(long base, const char * pbase,
            long derived,const char * pderived)
    : Base(base,pbase)
    , _derived(derived)
    , _pderived(new char[strlen(pderived) + 1]())
    {
        strcpy(_pderived,pderived);
    }

    Derived(const Derived & rhs)
    : Base(rhs)//显式调用基类的拷贝构造
    , _derived(rhs._derived)
    , _pderived(new char[strlen(rhs._pderived) + 1]())
    {
        strcpy(_pderived, rhs._pderived);
        cout << "Derived(const Derived &)" << endl;
    }

    Derived & operator=(const Derived & rhs){
        cout << "Derived & operator=(const Derived &)" << endl;
        if(this != &rhs){
            //显式调用基类的赋值运算符函数
            Base::operator=(rhs);//关键
            delete [] _pderived;
            _pderived = new char[strlen(rhs._pderived) + 1]();
            strcpy(_pderived,rhs._pderived);
            _derived = rhs._derived;
        }
        return *this;
    }

    ~Derived(){
        if(_pderived){
            delete [] _pderived;
            _pderived = nullptr;
        }
    }

    void print() const{
        cout << "_base:" << _base << endl;
        cout << "_pbase:" << _pbase << endl;
        cout << "_derived:" << _derived << endl;
        cout << "_pderived:" << _pderived << endl;
    }

private:
    long _derived = 12;
    char * _pderived;
};



void test0()
{
    Derived d1(20,"beijing",30,"hello");
    Derived d2(60,"shanghai",70,"world");
    Derived d3 = d1;
    d3.print();

    cout << endl;
    d2 = d1;
    d2.print();
}

int main()
{
    test0();
    return 0;
}

