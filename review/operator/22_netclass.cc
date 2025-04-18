#include <iostream>
using std::cout;
using std::endl;

class Line
{
    class Point
    {
    public:
        Point(int x,int y)
            : _ix(x)
              , _iy(y)
        {
            cout << "Point(int,int)" << endl;
        }

        void print() const{
            cout << "(" << _ix
                << "," << _iy
                << ")";
        }

        void getLine(const Line & rhs){
            rhs._num;//即使是私有成员也是ok的
            Line::_count;//外部类的静态成员
            _count;// 不通过类名直接访问
            _iz;
        }

        ~Point(){
            cout << "~Point()" << endl;
        }
        friend class Line;
    private:
        int _ix;
        int _iy;
        static int _iz;
    };
public:
    Line(int x1,int y1,int x2,int y2)
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

    void getPoint(){
        _pt1._ix;//访问内部类的私有成员，需要声明友元
        Point::_iz;// 需要声明友元
        /* _iz;//error *///需要依赖对象访问
    }

    ~Line(){
        cout << "~Line()" << endl;
    }
private:
    Point _pt1;
    Point _pt2;
    int _num = 10;
    static int _count;
};
int Line::Point::_iz = 0;
int Line::_count = 0;

int main(){
    return 0;
}


