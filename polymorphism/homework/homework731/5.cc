#include<iostream>

using std::endl;
using std::cout;

class A{
public:
    virtual void a(){ cout << "A::a()" << endl; } 
    void b(){ cout << "A::b()" << endl; } 
    virtual void c(){ cout << "A::c()" << endl; } 
    void e(){ cout << "A::e()" << endl; }
};

class B{
public:
    virtual void a(){ cout << "B::a()" << endl; } 
    void c(){ cout << "B::c()" << endl; } 
    void d(){ cout << "B::d()" << endl; } 
    virtual void f(){ cout << "B::f()" << endl; }
};

class C
: public A
, public B
{
public:
    virtual void a(){ cout << "C::a()" << endl; } 
    virtual void b(){ cout << "C::b()" << endl; } 
    void c(){ cout << "C::c()" << endl; } 
    void d(){ cout << "C::d()" << endl; } 
};

void test0(){
    C c;// 派生类对象直接访问
    c.a(); // 没有通过虚表，本质也是虚函数，隐藏
    c.b(); // 没有通过虚表，本质也是虚函数，隐藏
    c.c(); // 没有通过虚表，本质也是虚函数，隐藏
    c.d(); // 没有通过虚表，普通成员函数，隐藏
    c.e(); // 访问基类子对象A中的成员函数，没有通过虚表
    c.f(); // 访问基类子对象B中的成员函数，没有通过虚表，本身也是虚函数
    
    cout << endl;
    A* pa = &c;// 基类指针指向派生类对象
    pa->a(); // 通过虚函数表访问，符合动态多态条件
    pa->b(); // 访问基类子对象A中的普通成员函数b
    pa->c(); // 通过虚函数表访问，符合动态多态条件
    //pa->d();// A中无该成员函数
    pa->e(); // 访问基类子对象A中的普通成员函数b
    //pa->f();// A中无该成员函数
    
    cout << endl;
    B* pb = &c;// 基类指针指向派生类对象
    pb->a(); // 通过虚函数表访问，符合动态多态条件
    //pb->b(); // B中无该成员函数
    pb->c(); // 访问基类子对象B中的普通成员函数c
    pb->d(); // 访问基类子对象B中的普通成员函数d
    //pb->e(); // B中无该成员函数
    pb->f(); // B自己定义的虚函数，通过虚函数表访问，没有覆盖

    cout << endl;
    C * pc = &c;// 派生类指针指向派生类对象
    pc->a(); // 通过虚函数表访问本类的虚函数实现
    pc->b(); // 通过虚函数表访问本类的虚函数实现
    pc->c(); // 通过虚函数表访问本类的虚函数实现
    pc->d(); // 不是虚函数，隐藏
    pc->e();// 访问基类子对象A中的普通成员函数e
    pc->f();// 通过虚函数表访问基类子对象B中的虚函数f
}
int main(){
    test0();
    return 0;
}