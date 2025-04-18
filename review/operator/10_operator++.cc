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
    //成员函数形式
    Complex operator+(const Complex & rhs){
         return Complex(this->_real + rhs._real,
                        this->_image + rhs._image);
    }
    Complex& operator++(){
        ++_real;
        ++_image;
        return *this;
    }
    Complex operator++(int){
        Complex tmp(*this);
        ++_real;
        ++_image;
        return tmp;
    }



private:
    int _real;
    int _image;
};
void test0()
{
    Complex cx1(1,2);
    Complex cx2(3,4);
    Complex cx3 = cx1 + cx2;
    Complex cx4 = cx1.operator+(cx2);
    cx4.print();
    cx3.print();
}
void test1(){
    Complex cx1(1,2);
    Complex cx2(3,4);
    ++cx1;
    cx1.print() ;
    cx1.operator++();
    cx1.print() ;
    (++cx1).print();
    cx2++.print();
    cx2.operator++(1).print();
    cx2.print();
}

int main()
{
    test1();
    return 0;
}

