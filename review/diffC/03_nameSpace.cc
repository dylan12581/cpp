#include <iostream>
#include <string.h>


int number = 100;

namespace shy{

int number = 10;
void display(){
    std::cout << "shy number = " << number <<std::endl;
}
namespace cpp{
int number = 1;
void display(){
    std::cout << "cpp number = " << number << std::endl;
}
}

}//end of  namespace shy

void test0()
{
    using shy::number;
    using shy::cpp::display;
    std::cout << "shy number = " << number << std::endl;
    display();
}

int main()
{
    test0();
    return 0;
}

