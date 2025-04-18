#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Base{
public:
    virtual void print(){
        cout << "Base::print()" << endl;
    }
    virtual void display(){
        cout << "Base::display()" << endl;
    }
    virtual void show(){
        cout << "Base::show()" << endl;
    }
private:
    long _base = 10;

};

class Derived
:public Base
{
public:
    // in one vTable
    virtual void display() {
		cout << "Derived::display()" << endl;
	}
	virtual void show() {
		cout << "Derived::show()" << endl;
	}

 	virtual void print() {
		cout << "Derived::print()" << endl;
	}

    virtual void func(){
        cout << "Derived::func()" << endl;
    }
private:
    long _derived = 100;

};
int global = 1;
void test0()
{
    Derived d;
    cout << "sizeof(d)" << sizeof(d) << endl;
    cout << endl;
    long* pderived = (long*)&d;
    cout << pderived[0] << endl;
    cout << pderived[1] << endl;
    cout << pderived[2] << endl;

    cout << endl;
    long* pVtable = (long*)pderived[0];
    cout << pVtable[0] << endl;
    cout << pVtable[1] << endl;
    cout << pVtable[2] << endl;
    cout << pVtable[3] << endl;

    const char* str = "hello";
    int* pi = new int(10);

    printf("虚函数表的位置：%p\n",pVtable);
    printf("d的位置在栈上:%p\n",&d);
    printf("程序代码的位置：%p\n",(void*)pVtable[0]);
    printf("文字常量的位置：%p\n",str);
    printf("堆的位置：%p\n",pi);
    printf("全局静态区的位置：%p\n",&global);
    delete pi;
    
    cout << endl;
    typedef void(*Function)();
    Function f = (Function)(pVtable[0]);
    f();
    f = (Function)(pVtable[1]);
    f();
    f = (Function)(pVtable[2]);
    f();
    f = (Function)(pVtable[3]);
    f();

}
void test1(){
    Base b1;
    Base * pb1 = &b1;
    long * p1 = (long*)pb1;
    long * p = (long*)(*p1);
    cout << p << endl;
    const char* s1 = "hello";
    const char* s2 = "hi";
    printf("%p\n",s1);
    printf("%p\n",s2);
    int* ph = new int(1);
    cout << ph << endl;
}
int main()
{
    test1();
    return 0;
}

