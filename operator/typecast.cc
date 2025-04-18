#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
class Point;
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
    Complex& operator=(const Point& rhs);
    Complex(const Point&rhs);
private:
    int _real;
    int _image;
};


class Point
{
public:
    
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

    operator Complex(){
        cout << "类型转换函数operator Complex" << endl;
        return Complex(_ix,_iy);
    }
    ~Point(){
        cout << "~Point()" << endl;
    }
    friend Complex& Complex::operator=(const Point& rhs);
    friend Complex::Complex(const Point&rhs);
private:
    int _ix;
    int _iy;
};
Complex& Complex::operator=(const Point& rhs){
    cout << "Complex的特殊的赋值运算符函数" << endl;
    _real = rhs._ix;
    _image = rhs._iy;
    return *this;
}
Complex::Complex(const Point&rhs)
:_real(rhs._ix)
,_image(rhs._iy)
{
    cout << "Complex类的特殊构造函数" << endl;
}



void test0()
{
    Point pt(8,9);
    Complex cx(4,6);
     cx = pt;
    //1.
    cx = pt.operator Complex();
    //2.
    cx.operator=(pt);
    //3.
    cx = Complex(pt);
    cx.print();
}

int main()
{
    test0();
    return 0;
}

