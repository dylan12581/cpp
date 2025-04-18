#include <iostream>
#include <string.h>
#include <functional>


using std::cout;
using std::endl;
using std::function;
using std::bind;

int add(int x,int y){

        return x + y;
}
void test1(){
    using namespace std::placeholders;
    function<int(int)> f  =bind(&add,_1,2);
    function<int()> f1  =bind(&add,2,2);
    cout << f(1) << endl;
    cout << f1() << endl;
}

int main()
{
    test1();
    return 0;
}

