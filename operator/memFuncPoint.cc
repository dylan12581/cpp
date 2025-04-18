#include <iostream>
#include <string.h>

using std::cout;
using std::endl;


class FFF
{
public:
    void print(int x){
        cout << "FFF::print:" << x << endl;
    }

    void display(int x){
        cout << "FFF::display:" << x << endl;
    }
};
// 起别名给这个成员函数指针类型
typedef void(FFF::*MemFun)(int);
class FFF2
{
public:
    void print(int x){
        cout << "FFF2::print:" << x << endl;
    }

    void display(int x){
        cout << "FFF2::display:" << x << endl;
    }
};
void print(int x){
    cout << "print:" << x << endl;
}

void display(int x){
    cout << "display:" << x << endl;
}

void test0()
{
    // 定义普通函数指针,省略、完整
    void (*p)(int);
    p = display;
    p(2);

    // 定义成员函数指针，必须完整形式
    void (FFF::*p1)(int);
    p1 = &FFF::display;
    FFF f1;
    f1.display(2);
    // 成员指针运算符的第一种形式
    (f1.*p1)(2);

    p1 = &FFF::print;
    f1.print(2);
    (f1.*p1)(2);

    MemFun p2 = &FFF::display;
    (f1.*p2)(3);

    FFF* p3 = new FFF();
    p3->display(2);
    // 成员指针运算符的第二种形式
    (p3->*p2)(2);
    p3->print(3);
    (p3->*p1)(3);

    p3 = nullptr;
    
    p3->display(2);
    (p3->*p2)(2);
    p3->print(3);
    (p3->*p1)(3);
}

int main()
{
    test0();
    return 0;
}

