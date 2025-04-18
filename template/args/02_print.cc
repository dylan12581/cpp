#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

void print(){
    cout << "print()" << endl;
    cout << endl;
}
void print(int x){
    cout << "print(int)" << endl;
    cout << x << endl;
}
template<class T>
void print(T x){
    cout << "print(T x)" << endl;
    cout << x << endl;
}
template<class T,class ...Args>
void print(T x,Args ...args){
    cout << x << " ";
    print(args...);
}

void test0()
{
    print();

    print(2.3);

    print(1,"hello",3.6,true);
    print(1,"hello",3.6,true,100);
    print(1,"hello",3.6,true,100,"hello");

}

int main()
{
    test0();
    return 0;
}

