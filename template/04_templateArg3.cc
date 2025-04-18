#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template <class T1 = double,class T2 = double,int kBase = 10>
T1 multiply(T2 t1,T2 t2){
    return t1 * t2 * kBase;
}

void test0()
{
    cout << multiply<double>(1.2,1.2) << endl;
    cout << multiply(1.2,1.2) << endl;
    
}

int main()
{
    test0();
    return 0;
}

