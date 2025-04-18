#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::ostream;

class Line
{
//public:
    class Point{
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
        void getLine(Line& rhs) const{
            // 类内对类外进行访问,不管是访问公有还是私有，都可以
            // 默认内部类是外部类的友元
            _count;// 静态成员可以直接访问，通过对象访问，作用域限定符访问，
            rhs._count;
            Line::_count;
            rhs._num;//普通数据成员需要通过对象进行访问
            //_num//error
        }
        void getPoint(){
            cout << "line getPoint()" << endl;
        }

        ~Point(){
            cout << "~Point()" << endl;
        }
        friend class Line;
    friend
    ostream& operator<<(ostream& os,const Point &rhs);
    private:
        int _ix;
        int _iy;
        static int _iz;// 初始化要放在最外面
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
    void getPoint(const Point& rhs){
        rhs._ix;// 需要声明友元
        rhs._iz;// 静态成员函数两种访问形式，不需要声明友元
        // _iz;// error
        Point::_iz;
    }
    void getLine(){
            cout << "line getLIne()" << endl;
        }
    ~Line(){
        cout << "~Line()" << endl;
    }
    //
    friend
    ostream& operator<<(ostream& os,const Point &rhs);
    friend
    ostream& operator<<(ostream& os,const Line& rhs);
private: 
    Point _pt1;
    Point _pt2;
    int _num;
    static int _count;
};
int Line::_count = 0;
int Line::Point::_iz = 0;

ostream& operator<<(ostream& os,const Line::Point &rhs){
    os << rhs._ix << "," << rhs._iy;
    return os;
}
ostream& operator<<(ostream& os,const Line& rhs){
    // 此处需要对Point对象进行<<运算符重载
    os << rhs._pt1 << rhs._pt2 ;
    return os;
}

void test0()
{
    // public情况下可以进行定义
    // private声明不了
    // Line::Point p1(1,2);
    // p1.print();
    Line ll(1,2,3,4);
    ll.printLine();

    // 进行输出运算符重载
    cout << ll << endl;
}

int main()
{
    test0();
    return 0;
}

