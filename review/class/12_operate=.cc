#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point
{
public:
    Point()
    : _ix(0)
    , _iy(0)
    {
        cout << "Point()" << endl;
    }

    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    //拷贝构造
    Point(const Point & rhs)
    : _ix(rhs._ix)//int _ix = rhs._ix;
    , _iy(rhs._iy)
    {
        cout << "拷贝构造函数" << endl;
    }

    Point& operator=(const Point& rhs){

        this->_ix = rhs._ix;
        this->_iy = rhs._iy;
        cout << "operator=" << endl;
        return *this;
    }

    void print(){
        cout << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
    }

    ~Point(){
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test3(){
    Point pt1(1,2),pt2(3,4);
    pt1 = pt2;
    pt1.print();
    pt2.print();
}

int main()
{
    test3();
    return 0;
}

