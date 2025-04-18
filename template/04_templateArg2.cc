#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template <class T = int,int kBase = 10>
T multiply(T x,T y){
    return x *y * kBase;
}

void test0()
{
    double i1 = 1.1,i2 = 2.1;

    //cout << multiply(i1,i2) << endl;//error
    cout << multiply(i1,i2)<< endl;
    cout << multiply<int>(i1,i2)<< endl;
    cout << multiply<int,5>(i1,i2)<< endl;
}

int main()
{
    test0();
    return 0;
}

