#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point{
public:
    //禁止隐式转换
    //explicit
    Point(int x = 0,int y = 0)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    Point(const Point & rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }


    ~Point(){
        cout << "~Point()" << endl;
    }

    void print() const{
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

     Point & operator=(int x){ 
         _ix = x; 
         _iy = x; 
         return *this; 
     } 
private:
    int _ix;
    int _iy;
};


void test0()
{
    Point pt(2,5);
    Point pt2(2);
    Point pt3;

    Point pt4 = 4;
    pt4.print();

}

int main()
{
    test0();
    return 0;
}

