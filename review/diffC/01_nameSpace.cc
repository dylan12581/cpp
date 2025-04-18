#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

namespace shy{

     int number = 10;
}//end of  namespace shy
namespace wd{

     int number = 100;
     void display(){
         cout << number << endl;
     }
}//end of  namespace shy


void test0()
{
    using namespace shy;
    cout << "shy number = " << number << endl;
    using namespace wd;
    display();
    // ambigious
    cout << "wd number = " << wd::number << endl;
}

int main()
{
    test0();
    return 0;
}

