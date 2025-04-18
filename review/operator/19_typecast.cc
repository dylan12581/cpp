#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Complex
{
public:
    Complex(int real,int image)
    : _real(real)
    , _image(image)
    {}

    void print() const{
        cout << _real << " + "
            << _image << "i"
            << endl;
    }
private:
    int _real;
    int _image;
};

class Point
{
public:
    /* explicit */
    Point(int x = 0,int y = 0)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    void print(){
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    operator int(){
        cout << "类型转换函数operator int" << endl;
        return _ix + _iy;
    }
    operator Complex(){
        cout << "类型转换函数operator Complex" << endl;
        return Complex(_ix,_iy);
    }

    ~Point(){
        cout << "~Point()" << endl;
    }

private:
    int _ix;
    int _iy;
};

void test0()
{
    Point pt1(2,4);
    //隐式转换
    pt1 = 5;
    pt1.print();//(5,0)
    cout << endl;

    int num = 10;
    //此时的需求是将Point对象转换成int型变量
    num = pt1;
    /* num = pt1.operator int(); */
    cout << num << endl;
    pt1.print();
    cout << endl;
}
void test1(){
    Point pt(8,9);
    Complex cx(4,6);
    //需求是Point对象转换成Complex类对象
    cx = pt;
    cx.print();
}

int main()
{
    test1();
    return 0;
}

