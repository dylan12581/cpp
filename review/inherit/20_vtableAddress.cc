#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    virtual void func(){
        cout << "Base::func()" << endl;
    }
};

class Derived
: public Base
{
public:
    void func(){
        cout << "Derived::func()" << endl;
    }
};

int num = 10;

const int num2 = 100;

void test0(){
    cout <<"quanju:"<<  &num << endl;
    cout << endl;


    //多个Base类对象中的虚函数指针指向的是同一张虚表
    Base b1;
    Base * pb1 = &b1;
    long * p1 = (long*)pb1;
    long * p = (long*)(*p1);
    cout <<"xubiao:" <<  p << endl;


    Base b2;
    Base * pb2 = &b2;
    long * p2 = (long*)pb2;
    long * pa = (long*)(*p2);
    cout <<"xubiao:"<<pa << endl;

    //Derived类对象中的虚函数指针指向的虚表与Base类的虚表不同
    Derived d1;
    long * pd = (long*)(&d1);
    long * pp = (long*)(*pd);
    cout << "xubiao2:" << pp << endl;


    cout << endl;
    const char * pstr = "hello";
    printf("wenzichangliang:%p\n",pstr);
    cout <<"wenzichangliang:"<< &num2 << endl;

}

int main(void){
    test0();
    return 0;
}

