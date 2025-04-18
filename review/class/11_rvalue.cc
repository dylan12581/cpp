#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point
{
public:
    Point()
    : _ix(0)
    , _iy(0)
    {
        cout << "Point()" << endl;
    }

    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    //拷贝构造
    Point(const Point & rhs)
    : _ix(rhs._ix)//int _ix = rhs._ix;
    , _iy(rhs._iy)
    {
        cout << "拷贝构造函数" << endl;
    }

    void print(){
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    ~Point(){
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test3(){
    Point(2,3).print();
    //&Point(1,2);
    cout << "over" << endl;
    int a = 1;
    cout << &a << endl;
    cout << &(++a) << endl;
    cout << ++a << endl;
    cout << a++ << endl;

    //&(a++);
}
void test4(){
    int a = 10;
    int b = 20;
    int & ref = a;
    cout << ref << endl;
    const int & ref1 = a + b;
    cout << ref1 << endl;
}

int main()
{
    test3();
    return 0;
}

