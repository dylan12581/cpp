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
    int getReal()const{
        return _real;
    }
    int getImage()const{
        return _image;
    }

private:
    int _real;
    int _image;
};
//普通函数形式
Complex operator+(const Complex & lhs,const Complex & rhs){
    return Complex(lhs.getReal() + rhs.getReal(),
                   lhs.getImage() + rhs.getImage());
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

