#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template <class T,int kBase>
T multiply(T x,T y){
    return x *y * kBase;
}

void test0()
{
    int i1 = 1,i2 = 2;

    //cout << multiply(i1,i2) << endl;//error
    cout << multiply<int,10>(i1,i2)<< endl;
}

int main()
{
    test0();
    return 0;
}

