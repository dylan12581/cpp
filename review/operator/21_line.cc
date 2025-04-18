#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::ostream;

class Line
{
private:
    class Point{
    public:
        Point(int x,int y)
        : _ix(x)
        , _iy(y)
        {
             cout << "Point(int,int)" << endl;
        }
        void print()const {
             cout << "(" << _ix
                << "," << _iy
                << ")";
        }
        ~Point(){
            cout << "~Point()" << endl;
        }
    friend ostream& operator<<(ostream& os,const Line::Point& rhs);// 需要知道Line::Point类里面的私有成员
    private:
        int _ix;
        int _iy;
    };
public:
    Line(int x1, int y1, int x2, int y2)
    : _pt1(x1,y1)
    , _pt2(x2,y2)
    {
          cout << "Line(int*4)" << endl;
    }
    void printLine() const{
        _pt1.print();
        cout << "--------->";
        _pt2.print();
        cout << endl;
    }
    ~Line(){
        cout << "~Line()" << endl;
    }
    friend ostream& operator<<(ostream& os,const Line& rhs);
    friend ostream& operator<<(ostream& os,const Line::Point& rhs);// 需要知道Point类是Line类里面的
private: 
    Point _pt1;
    Point _pt2;
};

ostream& operator<<(ostream& os,const Line& rhs){
    os << rhs._pt1 << "------->" << rhs._pt2 << endl;
    return os;
}
ostream& operator<<(ostream& os,const Line::Point& rhs){
    os << "(" << rhs._ix << "," << rhs._iy << ")";
    return os;
}

void test0()
{
    cout << sizeof(Line) << endl;

    Line ll(1,2,3,4);
    ll.printLine();
}
void test1(){
    cout << sizeof(Line) << endl;

    Line ll(1,2,3,4);
    /* ll.printLine(); */
    cout << ll << endl;

    /* Line::Point pt(1,2); */

}

int main()
{
    test1();
    return 0;
}

