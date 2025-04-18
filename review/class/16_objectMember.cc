#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point
{
public:
    Point()
    : _ix(0)//int _ix = 0;
    , _iy(0)//int _iy = 0;
    {
        cout << "Point()" << endl;
    }

    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    void print(){
        cout << "(" << _ix
            << "," << _iy
            << ")";
    }

    ~Point(){
        cout << "~Point()" << endl;
    }

private:
    int _ix;
    int _iy;
};


class Line
{
public:
    Line(int x1,int y1,int x2,int y2)
    : _pt1(x1,y1)
    , _pt2(x2,y2)
    {
        cout << "Line(int*4)" << endl;
    }

    void printLine(){
        _pt1.print();
        cout << "--------->";
        _pt2.print();
        cout << endl;
    }

    ~Line(){
        cout << "~Line()" << endl;
    }
private:
    //声明了Point类型的对象成员
    Point _pt1;
    Point _pt2;
};

void test0(){
    Line ll(1,2,3,4);
    ll.printLine();
}

int main(void){
    test0();
    return 0;
}
