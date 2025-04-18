#include <math.h>
#include <iostream>
#include <string>
#include <unordered_set>

using std::cout;
using std::endl;
using std::unordered_set;
using std::ostream;

template<class Container>
void display(const  Container&  con){
    for(auto& elem: con){
        cout << elem << " ";
    }
    cout << endl;
}

class Point{
public:
    Point(int x,int y)
        :_ix(x),_iy(y)
    {
    }
    double getDistance()const{
        return hypot(_ix,_iy);
    }
    int getX()const{
        return _ix;
    }
    int getY()const{
        return _iy;
    }
    friend
        ostream& operator<<(ostream& os,const Point& rhs);
    friend 
        bool operator==(const Point& lhs,const Point& rhs);

private:
    int _ix;
    int _iy;

};

// 重载输出流运算符
ostream& operator<<( ostream& os,const Point& rhs){
    os << "("<< rhs._ix << " " << rhs._iy << ")";
    return os;
}
// std::equal to中的重载
bool operator==(const Point& lhs,const Point& rhs){
    cout << "bool operator==" << endl;
    return  (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
}
// 函数对象
struct HashPoint{
    size_t operator()(const Point& rhs)const{
        cout << "HashPoint()" << endl;
        return (rhs.getX() << 1) ^ (rhs.getY() << 2);
    }
};
struct EqualToPoint{

    bool operator()(const Point& lhs,const Point& rhs)const{
        cout << "EqualToPoint()" << endl;
        return  (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
    }
};

// 模板特化
template<>
struct std::hash<Point>{
    // 不能友元
    size_t operator()(const Point& rhs)const{
        cout << "template<> struct hash" << endl;
        return (rhs.getX() << 1) ^ (rhs.getY() << 2);
    }
};
template<>
struct std::equal_to<Point>{

    bool operator()(const Point& lhs,const Point& rhs)const{
        cout << "template<> EqualTo" << endl;
        return  (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
    };
};

    void test0()
    {
        //unordered_set<Point,PointComp> unordered_set1 = {Point(1,1),Point(1,-1),Point(2,1),Point(2,2)};
        cout << "不指定都会走特化版本" << endl;
        unordered_set<Point> unordered_set1 = {Point(1,1),Point(1,1),Point(1,-1),Point(2,1),Point(2,2)};
        display(unordered_set1);
        cout << "hash走函数对象，equal_to默认参数走特化版本" << endl;
        unordered_set<Point,HashPoint> unordered_set2 = {Point(1,1),Point(1,1),Point(1,-1),Point(2,1),Point(2,2)};
        display(unordered_set2);
        cout << "hash走函数对象，equal_to也是" << endl;
        unordered_set<Point,HashPoint,EqualToPoint> unordered_set3 = {Point(1,1),Point(1,1),Point(1,-1),Point(2,1),Point(2,2)};
        display(unordered_set3);

    }

    int main()
    {
        test0();
        return 0;
    }

