#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template <class ...Args>
void display(Args ...args){
    //输出模板参数包中类型参数个数
    cout << "sizeof...(Args) = " << sizeof...(Args) << endl;
    //输出函数参数包中参数的个数
    cout << "sizeof...(args) = " << sizeof...(args) << endl;
}
void test0()
{
    display();
    display(1,"hello",3.3,1,2,true);
}
void test1(){
    printf("%d%d%d",1,2,3);
}

int main()
{
    test0();
    return 0;
}

