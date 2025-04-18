#include <iostream>
#include <limits>
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

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
    
    Complex & operator++(){
        cout << "Complex前置++函数" << endl;
        ++_real;
        ++_image;
        return *this;
    }

    //后置++运算符重载函数的参数列表中加入一个int
    //与前置++作区分
    Complex operator++(int)
    {
        cout << "Complex后置++函数" << endl;
        Complex temp(*this);
        ++_real;
        ++_image;
        return temp;
    }

    Complex & operator+=(const Complex & rhs){
        _real += rhs._real;
        _image += rhs._image;
        return *this;
    }

    //ostream & operator<<(ostream & os){
    //    os << _real << " + " << _image << "i";
    //    return os;
    //}

    friend
    ostream & operator<<(ostream & os,const Complex & cx);
    friend
    istream & operator>>(istream & os, Complex & cx);
    friend
    Complex operator+(const Complex & lhs,const Complex & rhs);
private:
    int _real;
    int _image;
};
ostream& operator<<(ostream& os,const Complex& cx){
    os << cx._real << " " << cx._image;
    return os;
}
void readInt(istream& is,int& num){
    cout << "please input a int number" << endl;
    while(is >> num,!is.eof()){
        if(is.bad()){
            cout << "cin has broken!" << endl;
            return;
        }else if (is.fail()){
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "请输入一个int型数据" << endl;
        }else{
            cout << "num = " << num << endl;
            break;
        }
    }
}
istream & operator>>(istream & is, Complex & cx){
    cout << "请输入实部 : " << endl;
    readInt(is,cx._real);
    cout << "请输入虚部 : " << endl;
    readInt(is,cx._image);
    return is;
}


void test0(){
    Complex cx(1,2);
    //cx << cout;
    cout << cx << endl;
    operator<<(cout,cx) << endl;
}
void test1(){
    Complex cx(1,2);
    std::cin >> cx;
    cout << cx << endl;
}
int main(){
    test1();
    return 0;
}
