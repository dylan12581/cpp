#include <iostream>
#include <vector>
#include <string.h>


using std::cout;
using std::endl;
using std::vector;

class Point{
public:
    Point(int x = 0,int y = 0)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }
        ~Point(){
        cout << "~Point()" << endl;
    }
    void print() const{
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }

    Point(const Point & rhs)
    : _ix(rhs._ix)
    , _iy(rhs._iy){
        cout << "Point(const Point &)" << endl;
    }
private:
    int _ix;
    int _iy;
};

void test0()
{
    Point pt1(2,5);
    Point pt2(5);
    Point pt3;
    
    Point pt4 = 2;
    Point pt5 = {2,5};
    pt5.print();
}

void test1(){
    vector<Point> nums;

    //保存5个Point对象（该类型的默认值 —— 无参构造初始化）
    vector<Point> nums2(5);
    for(auto & ele : nums2){
        ele.print();
    }

    cout << endl;
    vector<Point> nums3(3,4);
    for(auto & ele : nums3){
        ele.print();
    }

    cout << endl;
    vector<Point> nums4{3,4};
    for(auto & ele : nums4){
        ele.print();
    }

    cout << endl;
    vector<Point> nums5{{2,6},{8,9}};
    for(auto & ele : nums5){
        ele.print();
    }
}
void test2(){
    vector<Point> vec;
    Point pt(3,7);
    cout << &pt << endl;
    vec.push_back(pt);
    cout << &vec[0] << endl;
    int * p = new int();
    cout << p ;
    delete p;

    //vec.reserve(10);
    //vec.push_back(Point(3,5));
    //vec.push_back(Point(8,9));
    //vec.push_back(Point(6,7));
    //vec.push_back(Point(6,7));

    //for(auto & ele:vec){
    //    ele.print();
    //}
}
void test3(){
    vector<Point> nums{{3,5},{7,9},{6,8}};
    vector<Point> nums2{Point(3,7),Point(7,9),Point(8,6)};
}

int main()
{
    test3();
    return 0;
}

