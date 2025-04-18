#include "line.hpp"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Line::LineImpl{

    class Point{
    public:
        Point(int x,int y)
            :_ix(x)
             ,_iy(y)
        {
            cout << "Point(int,int)" << endl;
        }
        ~Point(){
            cout << "~Point()" << endl;
        }
        void printPoint()const{
            cout<< "(" << _ix << "," << _iy << ")" << endl;
        }
    private:
        int _ix;
        int _iy;
    };
public:

    LineImpl(int x1,int y1,int x2,int y2)
        :_pt1(Point(x1,y1))
         ,_pt2(x2,y2)
    {
        cout << "LineImpl(int,int,int,int)" << endl;
    }
    ~LineImpl(){
        cout << "~LineImpl()" << endl;
    }
    void printLineImpl()const{
            _pt1.printPoint(); 
            cout <<  "---->";
             _pt2.printPoint();
            cout << endl;
        }
    //friend class Line;// 声明Line外部类是内部类的友元，才能调用

private:
    Point _pt1;
    Point _pt2;
};

Line::Line(int x1,int y1,int x2,int y2)
    :_pimpl(new LineImpl(x1,y1,x2,y2))
{
    cout << "Line(int*4)" <<endl;

}
Line::~Line(){
    cout << "~Line()" <<endl;
    if(_pimpl){
        delete _pimpl;
        _pimpl = nullptr;
    }
}
void Line::printLine() const{
    _pimpl->printLineImpl();
}
