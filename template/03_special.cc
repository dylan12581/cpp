#include <string.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <class T>
T add(T t1,T t2){
    return t1 + t2;
}
// 特化模板
template<>
const char* add<const char*>(const char* t1,const char* t2){
    char* ptmp = new char[strlen(t1) + strlen(t2) + 1]();
    strcpy(ptmp,t1);
    strcat(ptmp,t2);
    return ptmp;
}

void test0()
{
    cout << add(1,2) << endl;
    cout << add(1.1,2.2) << endl;
    cout << add<string>("hello,","world") << endl;
    // 通用模板下无法应对以下的调用
    const char* p = add<const char*>("hello,","world");
    cout << p << endl;
    delete  [] p;
}

int main()
{
    test0();
    return 0;
}

