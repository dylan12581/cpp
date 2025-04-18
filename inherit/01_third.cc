#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point{
public:
    Point(int x = 0,int y = 0)
        :_ix(x),_iy(y) {}
    void print2d(){
        cout << _ix << _iy << endl;
    }

protected:
    void display2d(){
        cout << "display2d" <<endl;
    }
private:
    int _ix;
    int _iy;
};

class Point3d
:private Point
{
public:
    Point3d(int x,int y,int z)
        :Point(x,y),_iz(z)
    {
        cout << "Point(int*3)" << endl;
    }
    void print3d(){
        cout << _iz << endl;
    }
protected:
    void display3d(){
        display2d();
        cout << "display2d" <<endl;
    }
private:
    int _iz;
};

class Point4d
:public Point3d{
public:
    Point4d(int x,int y,int z,int time)
        :Point3d(x,y,z),_time(time)
    {
        cout << "Point4d(int * 4)" << endl;
    }
    void print4d(){
        print3d();
        //print2d();
        cout << _time << endl;
    }
protected:
    void display4d(){
        display3d();
        //display2d();
        cout << "display4d" << endl;
    }
private:
    int _time;
};

void test0()
{
    Point3d d3(1,2,3);
    d3.display2d();
    d3.print2d();
    d3.print3d();
    Point4d d4(1,2,3,4);
    d4.print2d();
    d4.print3d();
    d4.print4d();
}

int main()
{
    test0();
    return 0;
}

