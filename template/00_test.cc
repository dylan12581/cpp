#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <class T>
T add(T a,T b){
    return a + b;
}

void test0()
{
    cout << add(1,2) << endl;
    cout << add(1.1,2.1) << endl;
    cout << add<int>(2.1,2.1) << endl;
    cout << add(string("hello"),string("world")) << endl;
}

int main()
{
    test0();
    return 0;
}

