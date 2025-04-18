#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point
{
public:
    Point()
    : _ix(0)
    , _iy(0)
    {
        cout << "Point()" << endl;
    }

    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    //拷贝构造
    Point(const Point & rhs)
    : _ix(rhs._ix)//int _ix = rhs._ix;
    , _iy(rhs._iy)
    {
        cout << "拷贝构造函数" << endl;
    }

    void print(){
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    ~Point(){
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};

//拷贝构造函数
void func(Point  p){
    p.print();
}

void test0(){
    Point p(3,7);
    func(p);
}

Point func2(){
    Point p(3,4);
    return p;
}

void test2(){
    // 加上-fno-elide-constructors
    func2().print();
    cout << "over" << endl;
}

// 此处是否是直接进行的隐式转换
void test3(){
    Point pt4 = Point(2,3);
    pt4.print();
    cout << "over" << endl;
}

int main()
{
    test2();
    return 0;
}

