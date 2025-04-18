#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template <class ...Args>
void display(Args ...args){
    cout << "模板参数包中的参数个数 " << sizeof...(Args) << endl;
    cout << "函数参数包中的参数个数 " << sizeof...(args) << endl;

}
void test0()
{
    display();
    display(1,"hello",3.3,true,5);
}

void print(){
    cout << endl;
}
void print(int x){
    cout << x << endl;
    cout << "void print(int)" << endl;
}
template <class T,class ...Args>
void print(T x,Args ...args){
    cout << x << " ";
    print(args...);
}
void test1(){
    //print();
    //print(1);
    print("hello",1,true,3.6,1);
}

void printType(){
    cout << endl;
}
template <class T,class ...Args>
void printType(T x,Args ...args){
    cout << typeid(x).name() << " ";
    printType(args...);
}
void test2(){
    printType("hello",1,true,3.6,1);
}

int main()
{
    test2();
    return 0;
}

