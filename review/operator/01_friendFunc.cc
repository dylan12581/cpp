#include <iostream>
#include <cmath>
#include <string.h>

using std::cout;
using std::endl;

class Point{
public:
    Point(int x,int y)
        :_ix(x)
         ,_iy(y)
    {}

    friend float distance(const Point& lhs,const Point& rhs);


private:
    int _ix;
    int _iy;
};
float distance(const Point& lhs,const Point& rhs){
      return sqrt((lhs._ix - rhs._ix)*(lhs._ix - rhs._ix) +
                (lhs._iy - rhs._iy)*(lhs._iy - rhs._iy));
}

void test0()
{
    Point pt1(0,0);
    Point pt2{3,4};
    cout << distance(pt1,pt2) << endl;
}

int main()
{
    test0();
    return 0;
}

