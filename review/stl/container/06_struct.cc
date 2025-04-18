#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

struct Base{
    void print(){
        cout << "base" << "\n";
    }
};
struct Derived
:Base
{


};
struct Derived2
:Derived{


};

void test0()
{
    Derived2 d2;
    d2.print();
}

int main()
{
    test0();
    return 0;
}

