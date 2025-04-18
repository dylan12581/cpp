#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

void printType(){
    cout << endl;
}

template<class T,class ...Args>
void printType(T x,Args ...args){
    cout << typeid(x).name() << " ";
    printType(args...);
}

void test0()
{

    printType(1,"hello",3.6,true,100);

}

int main()
{
    test0();
    return 0;
}

