#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

int gNum = 3;
static int sNum = 300;
int gNum2 = 3;
const int gNum3 = 3;

namespace cpp{
    int cppNum = 1;
}

void test0()
{
    const int cNum  = 1;
    static int sNum2 = 1;
    int num = 1;
    int num2 = 2;
    int* p = new int(1);
    const char* pstr = "hello";

    cout << &pstr << endl;
    cout << &p << endl;
    cout << &num2 << endl;
    cout << &num << endl;
    cout << &cNum << endl;
    cout << endl;

    cout << p << endl;
    cout << endl;

    cout << &sNum2 << endl;
    cout << &cpp::cppNum << endl;
    cout << &gNum2 << endl;
    cout << &sNum << endl;
    cout << &gNum << endl;
    cout << endl;

    printf("%p\n",pstr);
    cout << static_cast<void*>(const_cast<char*>(pstr)) << endl;;
    cout << static_cast<const void*>(pstr) << endl;
    cout << &gNum3 << endl;
    cout << endl;

}

int main()
{

    test0();
    printf("%p\n",&main);
    printf("%p\n",&test0);
    cout << reinterpret_cast<void*>(test0)<< endl;

    return 0;
}

