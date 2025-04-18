#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template<class T>
T add(T t1,T t2){
    cout << "模板一" << endl;
    return t1 + t2;
}

template<class T1,class T2>
T1 add(T1 t1, T2 t2){
    cout << "模板二" << endl;
    return t1 + t2;
}


void test0()
{
    double x = 9.1;
    int y = 10;
    cout << "显式实例化" << endl;
    cout << add<int,int>(x,y) << endl;
    cout << add<int>(x,y) << endl;
    cout << add<int>(y,x) << endl;
    cout << "------------"<< endl;
    cout << "隐式实例化" << endl;
    cout << add(x,x) << endl;
    cout << add(x,y) << endl;
    cout << add(y,x) << endl;
}

int main()
{
    test0();
    return 0;
}

