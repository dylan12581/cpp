#include <iostream>
#include <functional>
#include <algorithm>

using std::cout;
using std::endl;
using std::bind;
using namespace std::placeholders;

int add(int x,int y){
    cout << "add(int,int)" << endl;
    return x + y;
}
int multiply(int a,int b,int c){
    cout << "multiply(int,int,int)" << endl;
    return a * b  * c;
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
    static int mul(int x, int y)
    {
        cout << "static int Example::mul(int, int)" << endl;
        return x * y;
    }
};
void test0(){
    //auto f = bind(add,1,2);
    auto f = bind(&add,1,2);
    cout << f() << endl;
    auto f2 = bind(&multiply,1,2,3);
    cout << f2() << endl;

    Example ex;
    //auto f3 = bind(&Example::add,&ex,2,4);
    auto f3 = bind(&Example::add,ex,2,4);
    cout << f3() << endl;

    int a = 999;
    auto f4 = bind(&Example::mul,1,a);
    cout << f4() << endl;

    auto f5 = bind(&Example::mul,1,_1);
    cout << f5(2) << endl;
}
void func(int x1, int x2, int x3, const int &x4, int x5)
{
    cout << "x1 = " << x1 << endl
         << "x2 = " << x2 << endl
         << "x3 = " << x3 << endl
         << "x4 = " << x4 << endl
         << "x5 = " << x5 << endl;
}

void test()
{
    int number = 100;
    using namespace std::placeholders;
    //占位符整体代表的是形参的位置
    //占位符中的数字代表的是实参的位置
    auto f = bind(func, 10, _1, _2, number, number);
    // scref引用包装器
    auto f2 = bind(func, 10, _1, _2,std::ref(number), number);
    number = 200;
    f(1, 20, 300, 4000, 50000);//多余的参数直接丢弃
    f2(1, 20, 300, 4000, 50000);//多余的参数直接丢弃
    /* f(20); */
     f(20,30);
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
