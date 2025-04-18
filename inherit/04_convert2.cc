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
            cout << "~Base()" << endl; }
    }
    virtual void displayb(){ cout << _base << _pbase << endl; }
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

    // 合理的转换
    Derived * pd = dynamic_cast<Derived*>(pbase);
    if(pd){
        cout << "转换成功" << endl;
        pd->displayd();
    }else{
        cout << "转换失败" << endl;
    }

    // 不合理的转换
    Base* pbase2 = &base;
    Derived* pd2 = dynamic_cast<Derived*>(pbase2);
    if(pd2){
        cout << "转换成功" << endl;
        pd2->displayd();
    }else{
        cout << "转换失败" << endl;
    }

    Base& rbase = d;
    rbase.displayb();
    //Derived& rderived = base;//err

}

int main()
{
    test1();
    return 0;
}

