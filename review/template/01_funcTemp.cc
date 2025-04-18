#include <iostream> #include <string>
using std::cout;
using std::endl;
using std::string;

template<class T>
T add(T x,T y){
    return x + y;
}
template<class T1,class T2>
T1 add(T1 x,T2 y){
    return x + y;
}


void test0()
{
    cout << add(1,2) << endl;
    cout << add(1.1,2.2) << endl;
    cout << add(string("hello"),string("i")) << endl;
    cout << add<int>(1,2) << endl;
}

int main()
{
    test0();
    return 0;
}

