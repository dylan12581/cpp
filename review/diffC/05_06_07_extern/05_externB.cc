#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

extern int num;
extern void print();

void test0()
{
    cout << num << endl;
    print();
}

int main()
{
    test0();
    return 0;
}

