#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int x,int y)
        : _ix(x), _iy(y)
    {/* cout << "Point(int,int)" << endl; */ }

    void print() const{
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;}
    ~Point(){
        /* cout << "~Point()" << endl; */
    }
protected:
    int _ix;
private:
    int _iy;
};
class Point3d
:protected Point{
public:
    Point3d(int x,int y,int z)
        :Point(x,y),_iz(z){
            cout << "Point3d(int*3)" << endl;
    }
    ~Point3d(){
           cout << "~Point3D()" << endl;
    }
    void display() const{
        // print();//由基类子对象进行调用
        cout << "ix:" << _ix << endl;
        // cout << "iy:" << _iy << endl;//error
        cout << "iz:" << _iz << endl;
    }
private:
    int _iz;
};
class Point4d
:public Point3d
{
    void func(){
        _ix;
        display();
        print();
    }
};

void test0()
{
    
    Point3d pt3d(1,2,3);
    pt3d.display();
    // pt3d.print();
}

int main()
{
    test0();
    return 0;
}

