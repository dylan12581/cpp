#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

int gNum = 10;

int func1(){
    return gNum;
}

int & func2(){
    return gNum;
}
//func3的返回值是右值属性的右值引用
//不能有效地延长其绑定的内容的生命周期
int && func3(){
    //error
    //return gNum;

    //存在隐患，返回的实际是悬空引用
    //return 1;

    //int a = 1, b = 3;
    //return a + b;

   return std::move(gNum);
}
void test0(){
    //func1的返回值是gNum的副本
    //&func1();
    int && ref1 = func1();
    int & ref2 = gNum;
    cout << &ref1 << endl;
    ref1 = 2;
    cout << ref1 << endl;
    //cout << &func1() << endl;
    cout << &gNum << endl;
    cout << &ref2 << endl;

    cout << &func2() << endl; 
    cout << endl;
    int && ref3 = func3();
    cout << &ref3 << endl;
}

int main(){
    test0();
    return 0;
}

