#include <math.h>
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

//前向声明
class Line;

class Point{
public:
    Point(int x, int y)
    : _ix(x)
    , _iy(y)
    {}

    friend float Line::distance(const Point & lhs, const Point & rhs);
private:
    int _ix;
    int _iy;
};

class Line{
public:
	float distance(const Point & lhs, const Point & rhs){
        return sqrt((lhs._ix - rhs._ix)*(lhs._ix - rhs._ix) +   
                (lhs._iy - rhs._iy)*(lhs._iy - rhs._iy));
    }
};



void test0(){
    Point pt(0,0);
    Point pt2(3,4);
    Line ll;
    cout << ll.distance(pt,pt2) << endl;
}

int main(void){
    test0();
    return 0;
}