#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;
using std::function;

int add(int x, int y)
{
    cout << "int add(int, int)" << endl;
    return x + y;
}

int multiply(int x, int y, int z)
{
    cout << "int multiply(int, int, int)" << endl;
    return x * y * z;
}
class Example
{
public:
    //每个非静态成员函数的第一个参数位置隐含this指针
    int add(int x, int y)
    {
        cout << "int Example::add(int, int)" << endl;
        return x + y;
    }
    int _data = 100;
};


void test0()
{
    auto f = bind(&add,1,2);
    f();
    auto f2 = bind(&multiply,1,2,3);
    f2();
    Example ex;
    auto f3 = bind(&Example::add,&ex,1,2);
    f3();
    auto f4 = bind(&Example::_data,&ex);
    cout << "f4()=" << f4() << endl;
}
void test1()
{
    using  namespace std::placeholders;
    auto f = bind(&add,1,_1);
    f(3);
}
void func(int x1, int x2, int x3, const int &x4, int x5)
{
    cout << "x1 = " << x1 << endl
         << "x2 = " << x2 << endl
         << "x3 = " << x3 << endl
         << "x4 = " << x4 << endl
         << "x5 = " << x5 << endl;
}
void test(){
    int num = 100;
    using namespace std::placeholders;
    auto f = bind(func,10,_2,_5,std::cref(num),num);
    num = 200;
    f(1,20,300,4000,500000);
    f(0,20,0,0,500000);
}
void test3(){
    using namespace std::placeholders;
    function<int(int)> f = bind(&add,1,_1);
    f(1);
}


int main()
{
    test();
    return 0;
}

