#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
    Point()
    : _ix(0)
    , _iy(0){
        cout << "Point()" << endl;
    }

    Point(int x,int y)
    : _ix(x)
    , _iy(y){
        cout << "Point(int,int)" << endl;
    }

    Point(const Point & rhs)
    : _ix(rhs._ix)//int _ix = rhs._ix;
    , _iy(rhs._iy)
    {
         cout << "拷贝构造函数" << endl;
    }

    Point & operator=(const Point & rhs){
        cout << "赋值运算符函数" << endl;
        this->_ix = rhs._ix;
        this->_iy = rhs._iy;
        return *this;
    }
    //void print(){
    //    cout << 
    //        "(" << this->_ix
    //        << "," << this->_iy
    //        << ")" << endl;
    //}

    void print() const {
        cout << "const" 
            << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
    }
    void setX(int x){
        _ix = x;
    }

    ~Point(){
        cout << "~Point()" << endl;
    }
private:
    int _ix;
    int _iy;
};
void test0(){
    Point pt1(1,2);
    pt1.print();
    pt1.setX(2);
    pt1.print();

    const Point pt2(3,4);
    pt2.print();
}
int main(){
    test0();

    return 0;
}

