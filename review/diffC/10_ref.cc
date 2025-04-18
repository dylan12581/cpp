#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:

private:

};

void test0()
{
    int num = 1;
    int num2 = 2;
    int& ref = num;
    //int& ref2;//error未初始化
    cout << num << endl;
    cout << ref << endl;
    cout << &num << endl;
    cout << &ref << endl;

    ref = 10;
    cout << num << endl;
    ref = num2;//这里是赋值操作，不是更改绑定
    cout << num << endl;
    cout << num2 << endl;
    cout << &num << endl;
    cout << &ref << endl;
}
void test1(){
    int num1 = 10;
    int* p = &num1;
    cout << &p << endl;
    cout << p << endl;
    cout << &num1 << endl;

    int& ref = num1;
    cout << sizeof(ref) << endl;
    cout << &ref << endl;
    cout << ref << endl;

}
void test2(){
    int num = 18;
    const int & ref= num;// const pointer to const
    //ref = 10;error
    num = 20;
    cout << num << endl;
}
int a = 10;
int func(){
    return a;
}
int b = 200;
int& func2(){
    return b;
}

void test3(){
    cout << func() << endl;
    //&func();//error
    cout << &a << endl;
    cout << &func2() << endl;;
    cout << &b << endl;
}

int main()
{
    test3();
    return 0;
}

