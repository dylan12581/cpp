#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

namespace cpp{
    extern int num;
    extern void print();
}
void test(){
    using cpp::print;
    print();
}

int main(){

    test();
    return 0;
}

