#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
    }

    //计算点到原点的距离
    double getDistance() const
    {
        return hypot(_ix, _iy);
    }

    int getX() const
    {
        return _ix;
    }

    int getY() const
    {
        return _iy;
    }

    ~Point()
    {

    }

    friend std::ostream &operator<<(std::ostream &os, const Point &rhs);
    friend bool operator<(const Point &lhs, const Point &rhs);
    friend struct ComparePoint;
private:
    int _ix;
    int _iy;
};
std::ostream &operator<<(std::ostream &os, const Point &rhs){
    os << "(" << rhs._ix
       << ", " << rhs._iy
       << ")";
    return os;
}
//运算符的重载
bool operator<(const Point &lhs, const Point &rhs)
{
    cout << "bool operator<" << endl;
    if(lhs.getDistance() < rhs.getDistance()){
        return true;
    }
    else if(lhs.getDistance() == rhs.getDistance()){
        if(lhs._ix < rhs._ix){
            return true;
        }
        else if(lhs._ix == rhs._ix){
            if(lhs._iy < rhs._iy){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

//函数对象
struct ComparePoint
{
    bool operator()(const Point &lhs, const Point &rhs) const
    {
        /* cout << "struct ComparePoint" << endl; */
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
};
template<>
struct std::less<Point>{
    bool operator()( const Point& lhs, const Point& rhs ) const{
        /* cout << "template <> " << endl; */
        if(lhs.getDistance() < rhs.getDistance()){
            return true;
        }
        else if(lhs.getDistance() == rhs.getDistance()){
            if(lhs.getX() < rhs.getX()){
                return true;
            }
            else if(lhs.getX() == rhs.getX()){
                if(lhs.getY() < rhs.getY()){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
};


void test0()
{
    int arr[] = {1,2,3};
    priority_queue<int> pq(arr,arr + 3);
    while(!pq.empty()){
        cout << "优先级最高的元素:" << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
}
void test1(){
   vector<int> number{2, 3, 6, 8, 9, 1, 4, 7, 5};
   priority_queue<int,vector<int>, std::greater<int>> pque;
    for(size_t idx = 0; idx != number.size(); ++idx)    {
       pque.push(number[idx]);
       cout << "当前优先级队列中，优先级最高的元素是: " << pque.top() << endl;
   }
}
void test2(){
    priority_queue<Point, std::vector<Point>, ComparePoint> pque;

    vector<Point> vec = {
        Point(1, 2),
        Point(-1, 2),
        Point(1, -2),
        Point(1, 2),
        Point(3, 2),
    };
    for(size_t idx = 0; idx != vec.size(); ++idx)    {
       pque.push(vec[idx]);
       cout << "当前优先级队列中，优先级最高的元素是: " << pque.top() << endl;
    }
    while(!pque.empty()){
        cout << pque.top() << " ";
        pque.pop();
    }
    cout << endl;
}
int main()
{
    test2();
    return 0;
}

