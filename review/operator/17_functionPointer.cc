#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

void print(int x){
    cout << "print:" << x << endl;
}

void display(int x){
    cout << "display:" << x << endl;
}

void show(){
    cout << "show()" << endl;
}

typedef void(*pFunction)(int);

void test0()
{
    void (*p)(int);
    p = &print;
    (*p)(3);
    p = &display;
    (*p)(4);

    pFunction p2 = print;
    p2(9);

    pFunction arr[2] = {p,p2}; 
    arr[1](3);

}

int main()
{
    test0();
    return 0;
}

