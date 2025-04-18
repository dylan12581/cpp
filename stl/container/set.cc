#include <math.h>
#include <iostream>
#include <string>
#include <set>

using std::cout;
using std::endl;
using std::set;
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
        bool operator<(const Point& lhs,const Point& rhs);

private:
    int _ix;
    int _iy;

};

// 重载输出流运算符
ostream& operator<<( ostream& os,const Point& rhs){
    os << "("<< rhs._ix << " " << rhs._iy << ")";
    return os;
}
// 重载<运算符
bool operator<(const Point& lhs,const Point& rhs){
    cout << "bool operator<" << endl;
    if(lhs.getDistance() < rhs.getDistance())
    {
        return true;
    }
    else if(lhs.getDistance() == rhs.getDistance())
    {
        if(lhs._ix < rhs._ix)
        {
            return true;
        }
        else if(lhs._ix == rhs._ix)
        {
            if(lhs._iy < rhs._iy)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
// 函数对象
struct PointComp{

    bool operator()(const Point& lhs,const Point& rhs)const{
        cout << "struct PointComp" << endl;
        if(lhs.getDistance() < rhs.getDistance()){
            return true;
        }
        else if(lhs.getDistance( ) == rhs.getDistance()){
            if(lhs.getX() < rhs.getX()){
                return true;
            }
            else if(lhs.getX() == rhs.getX()){
                if(lhs.getY() < rhs.getY()){
                    return true;
                }
            }
            return false;
        }
        else{
            return false;
        }
    }

};

// 模板特化
template<>
struct std::less<Point>{
    // 不能友元
    bool operator()(const Point& lhs,const Point& rhs)const{
        cout << "template<>" << endl;
        if(lhs.getDistance() < rhs.getDistance()){
            return true;
        }
        else if(lhs.getDistance( ) == rhs.getDistance()){
            if(lhs.getX() < rhs.getX()){
                return true;
            }
            else if(lhs.getX() == rhs.getX()){
                if(lhs.getY() < rhs.getY()){
                    return true;
                }
            }
            return false;
        }
        else{
            return false;
        }
    }
};

void test0()
{
    //set<Point,PointComp> set1 = {Point(1,1),Point(1,-1),Point(2,1),Point(2,2)};
    set<Point> set1 = {Point(1,1),Point(1,-1),Point(2,1),Point(2,2)};
    display(set1);

}

int main()
{
    test0();
    return 0;
}

