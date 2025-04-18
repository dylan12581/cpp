#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

int add(int x,int y){
    return x + y;
}
// 函数指针
typedef void (*Function) ();

void print(){
    cout << "printf()" << endl;
}
void display(){
    cout << "display()" << endl;
}


void test0()
{

    // 省略写法
    int (*p)(int,int) = add;
    // 完整写法
    int (*p2)(int,int) = &add;

    // 省略写法
    cout << p(1,2) << endl;
    cout << p2(1,2) << endl;
    // 完整写法
    cout << (*p)(1,2) << endl;
    cout << (*p2)(1,2) << endl;

    void (*p1)() = &print;
    void (*p3)() = print;
    p1();
    p3();
    (*p1)();
    (*p3)();

    p1 = display;
    p1 = &display;
    p1();

    Function p4 = display;
    p4();

    Function p5;
    p5 = print;
    p5();

    Function arr[] = {p4,p5};
    arr[1]();
    arr[0]();

}


int main()
{
    test0();
    return 0;
}

