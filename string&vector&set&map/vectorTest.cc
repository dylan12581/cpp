#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Point{
public:
    // 无参构造函数
    Point()
        :_ix(0)
         ,_iy(0)
    {
        cout << "Point()" << endl;
    }
    // 有参构造函数
    Point(int x,int y)
        :_ix(x)
         ,_iy(y)
    {
        cout << "Point(int,int)" << endl;
    }
    // 拷贝构造函数
    Point(const Point& rhs)
        :_ix(rhs._ix)
         ,_iy(rhs._iy)
    {
        cout << "Point(const Point& )" << endl;
    }
    // 赋值运算符函数
    Point & operator=(const Point& rhs){
        _ix = rhs._ix;
        _iy = rhs._iy;
        cout << "Point& operator=(const Point& rhs)" << endl;
        return *this;
    }
    // 打印
    void print()const{
        cout << "x=" << _ix << "y=" << _iy << endl;
    }
    // 析构
    ~Point(){
        cout<< "~Point()" << endl;
    }

private:
    int _ix;
    int _iy;
};
void test0()
{
    vector<Point> pt;
    cout << pt.size() << endl;
    cout << pt.capacity() << endl;

    pt.push_back(Point(1,2));
    cout << pt.size() << endl;
    cout << pt.capacity() << endl;

    pt.push_back(Point(3,4));
    cout << pt.size() << endl;
    cout << pt.capacity() << endl;

    pt.push_back(Point(5,6));
    cout << pt.size() << endl;
    cout << pt.capacity() << endl;

    vector<Point> pt2(10,Point(1,2));
    cout << pt2.size() << endl;
    cout << pt2.capacity() << endl;

    vector<Point> pt3{Point(1,2),Point(3,4),Point(5,6)};
    cout << pt3.size() << endl;
    cout << pt3.capacity() << endl;

    // 遍历
    // 1.
    for(int idx = 0;idx < pt.size();idx++){
        pt[idx].print();
    }
    // 2.
    for(auto & point : pt){
        point.print();
    }
    for(Point& point : pt){
        point.print();
    }
    // 3.迭代器实现
    vector<Point>::iterator it = pt.begin();
    //auto it = pt.begin();
    for(;it != pt.end();it++){
        (*it).print();
    }

    pt.pop_back();
    cout << pt.size() << endl;
    cout << pt.capacity() << endl;

    pt.clear();
    cout << pt.size() << endl;
    cout << pt.capacity() << endl;

    pt.shrink_to_fit();
    cout << pt.size() << endl;
    cout << pt.capacity() << endl;

    pt.reserve(5);
    cout << pt.size() << endl;
    cout << pt.capacity() << endl;

}

int main()
{
    test0();
    return 0;
}

