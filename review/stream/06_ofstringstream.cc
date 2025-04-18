#include <iostream>
#include <sstream>
#include <string>


using std::ostringstream;
using std::cout;
using std::endl;
using std::string;


void test0()
{
    int num = 123,num2 = 456;
    ostringstream oss;
    oss << "num = " << num  << ", num2 = " << num2 << endl;
    string res = oss.str();
    cout << res << endl;

    string str1("hello");
    string str2 = str1 + ",world" + std::to_string(1);
    cout << str2 << endl;


}

int main()
{
    test0();
    return 0;
}

