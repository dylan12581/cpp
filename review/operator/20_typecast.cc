#include <iostream>
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

    Complex(const Point & rhs);
    

    void print() const{
        cout << _real << " + "
            << _image << "i"
            << endl;
    }

    Complex & operator=(const Point &rhs);

    Complex(const Complex& rhs){
        cout << "Complex(const Complex& rhs)" << endl;
        _real = rhs._real;
        _image = rhs._image;
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

    ~Point(){
        cout << "~Point()" << endl;
    }

    operator Complex(){
        cout << "类型转换函数operator Complex" << endl;
        return Complex(_ix,_iy);
    }

    friend class Complex;
private:
    int _ix;
    int _iy;
};

Complex & Complex::operator=(const Point &rhs){
    cout << "Complex的特殊的赋值运算符函数" << endl;
    _real = rhs._ix;
    _image = rhs._iy;
    return *this;
}

Complex::Complex(const Point & rhs)
: _real(rhs._ix)
, _image(rhs._iy)
{
    cout << "Complex类的特殊构造函数" << endl;
}

void test1(){
    Point pt(8,9);
    Complex cx(4,6);
    //1.利用Point类的类型转换函数将Point对象转换成Complex类对象
    //2.利用Complex类的赋值运算符函数接受Point对象的赋值
    //3.隐式转换思路，利用Complex类的特殊构造函数
    //使用Point对象创建出一个临时的Complex对象
    //优先级: 2 > 1 > 3
    cx = pt;
    cx.print();

    Complex cx2 = pt;
}
int main(){

    test1();
    return 0;
}
