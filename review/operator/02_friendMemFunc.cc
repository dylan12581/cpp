#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class Point;

class Line{
public:
	float distance(const Point & lhs, const Point & rhs);
    void setX(Point & lhs,int x);
};

class Point{
public:
    Point(int x,int y)
        :_ix(x),_iy(y)
    {}

	friend float Line::distance(const Point & lhs, const Point & rhs);
    friend void Line::setX(Point & lhs,int x);

    void print() const{
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

private:
    int _ix;
    int _iy;
};

float Line::distance(const Point & lhs, const Point & rhs){
    return sqrt((lhs._ix - rhs._ix)*(lhs._ix - rhs._ix) +   //error，有问题，不知道Point的具体实现
            (lhs._iy - rhs._iy)*(lhs._iy - rhs._iy));
}

void Line::setX(Point& lhs,int x){
    lhs._ix = x;
}

void test0(){
    Point pt1(0,0);
    Point pt2{3,4};
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

