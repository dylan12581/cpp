#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Point{
public:
    Point(int x = 0,int y = 0)
    : _ix(x)
    , _iy(y)
    {
        /* cout << "Point(int,int)" << endl; */
    }

    void print() const{
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
    //3.友元类的声明
    //Line类所有的成员函数中都可以
    //通过Point对象直接访问Point类的私有成员
    friend class Line;
private:
    int _ix;
    int _iy;
};

class Line
{
public:
    float distance(const Point & lhs,const Point & rhs){
        return sqrt(pow(lhs._ix - rhs._ix,2) +
            pow(lhs._iy - rhs._iy,2));
    }

    void setX(Point & lhs,int x){
        lhs._ix = x;
    }
};


void test0()
{
    Point pt1(0,0);
    Point pt2(3,4);
    Line ll;
    cout << ll.distance(pt1,pt2) << endl;

    ll.setX(pt1,100);
    pt1.print();
}

int main()
{
    test0();
    return 0;
}

