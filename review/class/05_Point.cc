#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point()
    //初始化列表完成的是严格意义上的数据成员初始化
    //只有构造函数能够使用初始化列表
    //: _ix(0)//int _ix = 0;
    //, _iy(0)//int _iy = 0;
    {
        //严格意义上，在函数体中对数据成员进行“初始化”
        //其实是赋值操作
        //int _ix;
        //_ix = 0;
        /* _ix = 0; */
        /* _iy = 0; */
        cout << "Point()" << endl;
    }

    //数据成员的初始化顺序与其在初始化列表中顺序无关
    //与数据成员的声明顺序一致
    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        /* _ix = x; */
        /* _iy = y; */
        cout << "Point(int,int)" << endl;
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
    //数据成员的声明
    //C++11之后允许在数据成员声明处“初始化”
    //实际是默认值的属性
    int _ix = 10;
    int _iy = 10;
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

    cout << sizeof(Point) << endl;

}

int main(void){
    test0();
    return 0;
}
