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

    Complex & operator=(const Complex & rhs){
        _real = rhs._real;
        _image = rhs._image;
        return *this;
    }

    //友元函数的重载形式
    friend
    Complex operator+(const Complex & lhs,const Complex & rhs);
private:
    int _real;
    int _image;
};

Complex operator+(const Complex & lhs,const Complex & rhs){
    return Complex(lhs._real + rhs._real,
                   lhs._image + rhs._image);
}

void test0()
{
    Complex cx1(1,2);
    Complex cx2(3,4);
    Complex cx3 = cx1 + cx2;
    Complex cx4 = operator+(cx1,cx2);
    cx4.print();
    cx3.print();
}

int main()
{
    test0();
    return 0;
}

