#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point
{
public:
    Point(){
        _ix = 0;
        _iy = 0;
        cout << "Point()" << endl;
    }

    Point(int x,int y = 1){
        _ix = x;
        _iy = y;
        cout << "Point(int,int)" << endl;
    }

    void setX(int x)
    {
        _ix = x;
    }

    void setY(int y){
        _iy = y;
    }

    void print(){
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test0(){
    /* int a; */
    /* a = 10; */
    int a = 10;
    cout << a << endl;


    Point pt(3,6);
    pt.print();


    Point pt2(8,4);
    pt2.print();

    Point pt3;
    pt3.print();

    Point pt4(1);
    pt4.print();

}

int main(void){
    test0();
    return 0;
}
