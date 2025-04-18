#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template <class T1,class T2>
T1 add(T1 t1,T2 t2){
    cout << "template" << endl;
    return t1 + t2;
}

short add(short s1,short s2){
    cout << "add(short,short)" << endl;
    return s1 + s2;
}

void test0()
{
    short s1 = 1,s2 = 2;
    cout << add(s1,s2) << endl;
    cout << add<short>(s1,s2) << endl;
}

int main()
{
    test0();
    return 0;
}

