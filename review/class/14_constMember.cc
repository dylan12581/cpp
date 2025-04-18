#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point()
    //初始化列表完成的是严格意义上的数据成员初始化
    //只有构造函数能够使用初始化列表
    : _ix(0)//const int _ix = 0;
    , _iy(0)//const int _iy = 0;
    ,_p(new int(1))
    {
        //严格意义上，在函数体中对数据成员进行“初始化”
        //其实是赋值操作
        cout << "Point()" << endl;
    }

    //数据成员的初始化顺序与其在初始化列表中顺序无关
    //与数据成员的声明顺序一致
    Point(int x,int y,int z)
    : _ix(x)// const int _ix = x;
    , _iy(y)
    ,_p(new int(z))
    {
        cout << "Point(int,int)" << endl;
    }
    Point(const Point& rhs)
        :_ix(rhs._ix)// const int _ix = rhs._ix
         ,_iy(rhs._iy)
    {}

    void print(){
        _p = new int(2);//ok
        cout << "(" << _ix
            << "," << _iy << *_p
            << ")" << endl;

           // *_p = 10;//ok
    }

    ~Point(){
        delete _p;
        cout << "~Point()" << endl;
    }
private:
    //数据成员的声明
    //C++11之后允许在数据成员声明处“初始化”
    //实际是默认值的属性
   const int _ix = 10;
   const int _iy = 10;
   const int* _p = new int(10);
};

void test0(){
    Point p1;
    p1.print();

    Point p2(3,4,5);
    p2.print();

    Point p3 = p1;
    p3.print();

    /* p3 = p1; */ //error
}

int main(void){
    test0();
    return 0;
}
