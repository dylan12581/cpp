#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

//函数模板的声明
template <class T>
T add(T t1, T t2);


void test1(){ 
    int i1 = 1, i2 = 2;
	cout << add(i1,i2) << endl;
}

//函数模板的实现
template <class T>
T add(T t1, T t2)
{
    return t1 + t2;
}


int main()
{
    test1();
    return 0;
}

