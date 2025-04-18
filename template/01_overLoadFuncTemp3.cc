#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template<class T1,class T2>
T1 add(T1 t1,T2 t2){
    cout << "模板一" << endl;
    return t1 + t2;
}

template<class T1,class T2>
T1 add(T2 t2, T1 t1){
    cout << "模板二" << endl;
    return t1 + t2;
}


void test0()
{
    double x = 9.1;
    int y = 10;
    cout << add<int>(y,x) << endl;
    cout << add<double>(y,x) << endl;
    cout << add<int,double>(x,y)<< endl;
    cout << add<double,int>(x,y)<< endl;
}

int main()
{
    test0();
    return 0;
}

