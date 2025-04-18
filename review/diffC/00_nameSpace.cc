#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

namespace shy{

     int number = 10;
}//end of  namespace shy

void test0()
{
    cout << "shy number = " << shy::number << endl;
}

int main()
{
    test0();
    return 0;
}

