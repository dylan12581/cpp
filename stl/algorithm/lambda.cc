#include <iostream>
#include <string.h>
#include <functional>


using std::cout;
using std::endl;
using std::function;

void test()
{
    int num = 10;
    int age = 20;
    int value = 20;

    //auto f = [=, &num](int number)mutable
    function<void(int)> f = [=, &num](int number)mutable
    {
        ++num;
        ++age;
        cout << "num = " << num << endl;
        cout << "age = " << age << endl;
        cout << "number = " << number << endl;
    };
    cout << "函数调用" << endl;
    [num](int value){
        cout << value << endl;
        cout << num << endl;
    }(10);

    //11 21 20 11 20
    f(20);
    cout << "num = " << num << endl;
    cout << "age = " << age << endl;

    //num = 11 age = 20 value = 20
    //12 22 30 12 20
    cout << endl << endl;
    f(30);
    cout << "num = " << num << endl;
    cout << "age = " << age << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}
