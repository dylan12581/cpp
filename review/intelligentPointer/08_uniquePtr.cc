#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

class Point
{
public:
    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {}

    void print() const{
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
private:
    int _ix;
    int _iy;
};
void test1(){
    vector<unique_ptr<Point>> vec;
    unique_ptr<Point> up4(new Point(1,2));
    //vec.push_back(up4);
    vec.push_back(std::move(up4));
    vec.push_back(unique_ptr<Point>(new Point(2,3)));
    //up4->print();
    vec[0]->print();
    cout << &vec[0] << endl;
    cout << &up4 << endl;
    // 底层移交控制权，返回的是空指针
    cout << up4.get() << endl;

    up4.reset(new Point(6,8));
    up4->print();
}

void test0()
{
    unique_ptr<int> up(new int(10));
    cout << "*up" << *up << endl;
    cout << "up.get()" << up.get() << endl;
    cout << endl;
    //unique_ptr<int> up2(up);
    unique_ptr<int> up2(new int(20));
    //up2 = up;
    cout << "*up" << *up << endl;
    cout << "up.get()" << up.get()<< endl;
    cout << "*up.get()" << *up.get() << "\n";
}

void test2(){
    unique_ptr<Point> upp(new Point(3,7));
    unique_ptr<Point> upp2(new Point(6,4));
    vector<unique_ptr<Point>> vec(10);

    //底层都会涉及到调用unique_ptr的拷贝构造
    //有风险
    //vector<unique_ptr<Point>> vec2(10,
                        //unique_ptr<Point>(new Point(7,7)));
    //vector<unique_ptr<Point>> vec3{std::move(upp)};
}
int main()
{
    test2();
    return 0;
}

