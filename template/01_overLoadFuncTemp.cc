#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template<class T>
T add(T t1,T t2){
    return t1 + t2;
}

template<class T1,class T2>
T1 add(T1 t1, T2 t2){
    return t1 + t2;
}


void test0()
{
    double x = 9.1;
    int y = 10;
    cout << add(x,y) << endl;
    cout << add(y,x) << endl;
}

int main()
{
    test0();
    return 0;
}

