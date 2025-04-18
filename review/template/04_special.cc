#include <iostream>
#include <string>
#include <string.h>
using std::cout;
using std::endl;
using std::string;

template<class T>
T add(T x,T y){
    cout << "1" << endl;
    return x + y;
}
template<class T1,class T2>
T1 add(T1 x,T2 y){
    cout << "2" << endl;
    return x + y;
}
template<>
const char* add(const char* x,const char* y){
    char* temp = new char[strlen(x) + strlen(y) + 1]();
    strcpy(temp,x);
    strcat(temp,y);
    return temp;
}


void test0()
{
    cout << add(1,2) << endl;
    cout << add(1.1,2.2) << endl;
    cout << add(string("hello"),string("i")) << endl;
    cout << add("hello","c") << endl;
    cout << add<int>(1,2) << endl;
    
}

int main()
{
    test0();
    return 0;
}

