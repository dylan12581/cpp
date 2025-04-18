#include <iostream>
#include <string.h>

using std::cout;
using std::endl;


class Complex{
public:
    Complex(int real,int image)
    :_real(real)
    ,_image(image)
    { }
    void print()const{
        cout << _real << " + "
         << _image << "i" << endl;
    }
    Complex& operator=(const Complex& rhs){
        _real = rhs._real;
        _image = rhs._image;
        return *this;
    }
    Complex operator+(const Complex& rhs){
          return Complex(_real + rhs._real,
                    _image + rhs._image);
    }

private:
    int _real;
    int _image;
};

void test0()
{
    Complex cx1(1,2);
    Complex cx2(2,3);
    Complex cx3(3,4);
    cx3 = cx1 + cx2;
    cx3.operator=(cx1.operator+(cx2));
    cx3.print();
}

int main()
{
    test0();
    return 0;
}

