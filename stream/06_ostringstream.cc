#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::ostringstream;
using std::string;


void test0()
{
    int num1 = 123,num2 = 456;
    ostringstream oss;
    // 
    oss << "num1 = " << num1 << ",num2 = " << num2 << endl;
    cout << oss.str() << endl;

    string res = oss.str();
    cout << res << endl;

    string str("hello");
    string str2 = str + ",world" + std::to_string(4);
    cout << str2 << endl;

}

int main()
{
    test0();
    return 0;
}

