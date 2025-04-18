#include <iostream>
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

    Complex operator+(const Complex & rhs){
        return Complex(_real + rhs._real,
                       _image + rhs._image);
    }   

    Complex & operator+=(const Complex & rhs){
        _real += rhs._real;
        _image += rhs._image;
        return *this;
    }
    // friend Complex & operator+=(Complex & lhs,const Complex & rhs);

private:
    int _real;
    int _image;
};

// Complex & operator+=(Complex & lhs,const Complex & rhs){
//     lhs._real += rhs._real;
//     lhs._image += rhs._image;
//     return lhs;
// }

void test0(){
    int a = 1, b =3;
    a += b;

    Complex cx1(1,2);
    Complex cx2(3,4);
    cx2 += cx1;
    cx2.print();
    cx2.operator+=(cx1);// 倾向于使用成员函数
    // operator+=(cx2,cx1);
    cx2.print();
}

int main(void){
    test0();
    return 0;
}

