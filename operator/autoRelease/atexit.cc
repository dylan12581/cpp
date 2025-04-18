#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

void display(){
    cout << "display()" << endl;
}

void print(){
    cout << "print()" << endl;
}
void display1(int x = 1){
    cout << "display()" << x << endl;
}
void test0()
{
    atexit(display);
    atexit(print);
    atexit(print);
}

int main()
{
    test0();
    display1();
    return 0;
}

