#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point
{
public:
    static Point & getInstance(){
        static Point pt(1,2);
        return pt;
    }
    
    void print() const{
        cout << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
    }
    
private:
     Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }
     ~Point(){
         cout << "~Point()" << endl;
     }
     Point(const Point&) = delete;
     Point* operator=(const Point& rhs) = delete;
private:
    int _ix;
    int _iy;
};

void test0()
{
    Point & pt1 = Point::getInstance();
    Point & pt2 = Point::getInstance();
    cout << &pt1 << endl;
    cout << &pt2 << endl;
}

int main()
{
    test0();
    cout << "over" << endl;
    return 0;
}

