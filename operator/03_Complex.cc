#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ostream;
using std::istream;

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
    // 前置++
    Complex& operator++(){
        ++_real;
        ++_image;
        return *this;
    }
    Complex operator++(int){
        Complex temp(*this);
        ++_real;
        ++_image;
        return temp;
    }
    // ostream& operator<<(ostream & os){
        // os << _real << " + " << _image << " i ";
        // return os;
    // }
    friend ostream& operator<<(ostream& os,const Complex& lhs);
    friend istream& operator>>(istream& is,Complex& rhs);

private:
    int _real;
    int _image;
};
ostream& operator<<(ostream& os,const Complex& lhs){
    os << lhs._real << "+" << lhs._image << "i";
    return os;
}
void readInt(istream & is,int num){
    while(is >> num,!is.eof()){
        if(is.bad()){
            cerr << "is has broken" << endl;
            return;
        }else if(is.fail()){
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "请输入一个整数，看清楚一点" << endl;
        }else{
            // cout << num << endl;
            break;
        }
    }


}
istream& operator>>(istream& is,Complex& rhs){
        // is >> rhs._real;
        // is >> rhs._image;
        cout << "请输入实部" << endl;
        readInt(is,rhs._real);
        cout << "请输入虚部" << endl;
        readInt(is,rhs._image);
        return is;
}

void test0()
{
    Complex cx1(1,2);
    Complex cx2(2,3);
    Complex cx3(3,4);
    cx3 = cx1 + cx2;
    cx3.operator=(cx1.operator+(cx2));
    cx3.print();
}
void test1()
{
    Complex cx1(1,2);
    Complex cx2(2,3);
    Complex cx3(3,4);
    cx3 = cx1 + cx2;
    cx3.operator=(cx1.operator+(cx2));
    cx3.print();
    cout << endl;
    // cx3.operator<<(cout) << endl;
    // cx3 << cout << endl;
    cin >> cx3;
    cout << cx3 << endl;

}
int main()
{
    test1();
    return 0;
}

