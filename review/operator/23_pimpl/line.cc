#include "line.hh"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;


void test0()
{
    Line ll(10,20,30,40);
    ll.printLine();
}

int main()
{
    test0();
    return 0;
}

