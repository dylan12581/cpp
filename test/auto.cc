#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:

private:

};

void test0()
{
    int n = 1;
    int& ele = n;
    auto m = ele;//auto会去除& 和 const属性
    m = 2;
    cout << "ele=" << ele << endl;
    cout << "m=" << m << endl;
}
#include <vector>
using std::vector;
void test1(){
    vector<int> vec = {1,2,3};
    int a = vec.at(4);
    cout << a << endl;
}

int main()
{
    test1();
    return 0;
}

