#include "Computer.hpp"

#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
extern int Add(int x,int y);

extern void test1();

void test0(){
    Computer pc;
    pc.setBrand("Huawei");
    pc.setPrice(30000);
    pc.print();
}

int main(void){
    test0();
    test1();
    return 0;
}


