#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Computer{
public:

private:

};
void func(int x = 0,int y = 0){
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}
void test0()
{
    func(1,2);
    func(1);
    func();
}
// 往往在函数声明中规定默认参数
void func1(int x ,int y = 0);
void test1(){
    func1(1,2);
    func1(1);
}
void func1(int x ,int y ){
    cout << x + y << endl;
}
int main()
{
    test1();
    return 0;
}

