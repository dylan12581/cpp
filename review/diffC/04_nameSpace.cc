#include <iostream>
#include <string.h>


int number = 100;
void display(){
    std::cout << "global number = " << number <<std::endl;
}

namespace {
int number = 10;
void display(){
    std::cout << "anonymous number = " << number <<std::endl;
    }
}//end of  namespace anonymous 

void test0()
{
    std::cout << "global number = " << ::number << std::endl;
    ::display();
}

int main()
{
    test0();
    return 0;
}

