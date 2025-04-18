#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Point{
public:
    static Point* getInstant()// 静态函数,不需要对象就能够访问
    {
        if(nullptr == _pInstant){// 防止每次调用都new
         _pInstant= new Point(1,2);
        }
        return _pInstant;
    }
    // 多次赋值用
    void init(int x,int y){
        _ix = x;
        _iy = y;
    }
    // 析构函数私有，需要手动进行析构函数的设置
    static void destroy(){
        if(_pInstant){ // 防止多次delete空指针的问题
        delete _pInstant;
        _pInstant = nullptr;
         cout << ">>delete heap" << endl;
        }

    }


    void print()const{
         cout << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
    }
    // 在这个类中删除拷贝构造和赋值运算符函数
    Point(const Point& rhs) = delete;
    Point& operator=(const Point& rhs) = delete;
private:
    // 构造函数私有,析构函数私有
    Point(int x,int y)
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int,int)" << endl;
    }
    ~Point(){
        cout << "~Point()" << endl;
    }

    int _ix;
    int _iy;
    static Point* _pInstant;// 实例的指针

};
Point* Point::_pInstant = nullptr;// 初始化静态

void test0()
{
    cout << " " << endl;
}

int main()
{
    test0();
    return 0;
}

