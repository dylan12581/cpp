#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Base{
public:
    // Base(){ cout << "Base()" << endl; }
    Base(long base, const char* pbase)
        :_pbase(new char[strlen(pbase) + 1]()),_base(base)
    { 
        strcpy(_pbase,pbase);
        cout << "Base(long,char*)" << endl; 
    }
    ~Base(){ 
        if(_pbase){
            delete []_pbase;
            _pbase = nullptr;
            cout << "~Base()" << endl; 
        }
    }
    Base(const Base& rhs)
        :_pbase(new char[strlen(rhs._pbase)]())
         ,_base(rhs._base)
    {
        strcpy(_pbase,rhs._pbase);
        cout << "Base(const Base& rhs)" << endl;
    }
    Base& operator=(const Base& rhs){
        if(this != &rhs){
            delete  []_pbase;
            _pbase = new char[strlen(rhs._pbase)]();
            strcpy(_pbase,rhs._pbase);
            _base = rhs._base;
        }
        cout << "Base& operator=(const Base& rhs)" << endl;
        return *this;
    }
    void displayb(){ cout << _base << _pbase << endl; }
private:
    char*  _pbase;
    long _base;
};
class Derived
:public Base{
public:
    Derived(long base,long derived, const char* pbase,const char* pderived)
        //:Base()// 自动调用Base的默认无参构造
        :Base(base,pbase)
         ,_pderived(new char[strlen(pbase) + 1]())
         ,_derived(derived){
             strcpy(_pderived,pderived);
             cout << "Derived(long)" << endl;
         }
    ~Derived(){
        if(_pderived){
            delete []_pderived;
            _pderived = nullptr;
            cout << "~Derived()" << endl;
        }
    }
    Derived(const Derived& rhs)
        :Base(rhs)// base的拷贝构造.没有会报错
         ,_pderived(new char[strlen(rhs._pderived)]())
         ,_derived(rhs._derived)
    {

        strcpy(_pderived,rhs._pderived);
        cout << "Derived(const Derived & rhs)" << endl;
    }
    Derived& operator=(const Derived& rhs){
        //
        if(this != &rhs){
            Base::operator=(rhs);
            delete  []_pderived;
            _pderived = new char[strlen(rhs._pderived)]();
            strcpy(_pderived,rhs._pderived);
            _derived = rhs._derived;
            cout << "Derived& operator=(const Derived& )" << endl;
        }
        return *this;
    }

    void displayd(){
        displayb();
        cout << _derived << _pderived << endl;
    }
private:
    char* _pderived;
    long _derived;
};

void test0()
{
    Derived d(1,2,"base","derived");
    cout << sizeof(d) << endl;
    d.displayd();
}

void test1()
{
    Base base(1,"base");
    Derived d(1,2,"base","derived");

    cout << sizeof(base) << endl;
    cout << sizeof(d) << endl;

    base = d;
    //d = base;// error

    Base *pbase = &d;
    //Derived* pderived = &base;//error
    pbase->displayb();

    Base& rbase = d;
    rbase.displayb();
    //Derived& rderived = base;//err
}
void testCopy(){
    Derived d1(1,1,"base1","derived1");
    d1.displayd();
    Derived d2(2,2,"base2","derived2");
    d2.displayd();
    cout << endl;
    Derived d3 = d2;

    d2 = d1;
    d2.displayd();
}

int main()
{
    testCopy();
    return 0;
}

