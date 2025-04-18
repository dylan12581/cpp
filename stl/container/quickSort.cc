#include <math.h>
#include <iostream>
#include <vector>
#include <functional>
using std::cout;
using std::endl;
using std::ostream;
using std::vector;

class Point
{
public:
    Point(int ix, int iy)
        : _ix(ix), _iy(iy)
    {}
    int getX()const { return _ix; }
    int getY()const { return _iy; }
    double getDistance()const{
        return hypot(_ix,_iy);
    }

    friend ostream &operator<<(ostream &os, const Point &rhs);
private:
    int _ix;
    int _iy;
};
// 模板特化
template<>
struct std::less<Point>{

    bool operator()(const Point &lhs, const Point &rhs)
    {
        cout << "template<> std::less<Point>" << endl;
        if(lhs.getDistance() < rhs.getDistance()){
            return true;
        }
        else if(lhs.getDistance() == rhs.getDistance()){
            if(lhs.getX() < rhs.getX()){
                return true;
            }
            else if(lhs.getX() == rhs.getX()){
                if(lhs.getY() <= rhs.getY()){
                    return true;
                }
                return false;
            }else{
                return false;
            }
        }else{
            return  false;
        }
    }
};
ostream &operator<<(ostream &os, const Point &rhs)
{
    os << "(" << rhs._ix << "," << rhs._iy << ")";
    return os;
}
// 运算符重载
bool operator<(const Point& lhs,const Point& rhs){
        cout << " operator< " << endl;
        if(lhs.getDistance() < rhs.getDistance()){
            return true;
        }
        else if(lhs.getDistance() == rhs.getDistance()){
            if(lhs.getX() < rhs.getX()){
                return true;
            }
            else if(lhs.getX() == rhs.getX()){
                if(lhs.getY() <= rhs.getY()){
                    return true;
                }
                return false;
            }else{
                return false;
            }
        }else{
            return  false;
        }
}
// 函数对象
struct PointCompare
{
    bool operator()(const Point &lhs, const Point &rhs)
    {
        cout << " struct PointCompare" << endl;
        if(lhs.getDistance() < rhs.getDistance()){
            return true;
        }
        else if(lhs.getDistance() == rhs.getDistance()){
            if(lhs.getX() < rhs.getX()){
                return true;
            }
            else if(lhs.getX() == rhs.getX()){
                if(lhs.getY() <= rhs.getY()){
                    return true;
                }
                return false;
            }else{
                return false;
            }
        }else{
            return  false;
        }
    }

};

template <typename T, typename Compare = std::less<T>> // 默认采用升序比较器
class MyQsort
{
public:
    MyQsort(T *arr, size_t size, Compare com = Compare());
    void quick(int left, int right, Compare &com);    // 递归操作
    int partition(int left, int right, Compare &com); // 分区
    void print();                                     // 进行打印
private:
    vector<T> _vec;
};

template <typename T, typename Compare>// 此处不用填写默认参数,会报错
MyQsort<T, Compare>::MyQsort(T *arr, size_t size, Compare com)
{
    for (size_t idx = 0; idx < size; ++idx)
    {
        _vec.push_back(arr[idx]);
    }
    quick(0, _vec.size() - 1, com);
}

template <typename T, typename Compare>
void MyQsort<T, Compare>::quick(int left, int right, Compare &com)
{
    if (left >= right)
    {
        return;
    }
    int pivot = partition(left, right, com);
    quick(left, pivot - 1, com);
    quick(pivot + 1, right, com);
}

// 双向分区
    template <typename T, typename Compare>
int MyQsort<T, Compare>::partition(int left, int right, Compare &com)
{
    T pivot = _vec[left];
    while (left < right)
    {
        // while (left < right && pivot < _vec[right])
        while (left < right && com(pivot, _vec[right]))
        {
            --right;
        }
        _vec[left] = _vec[right];
        while (left < right && com(_vec[left], pivot))
        {
            ++left;
        }
        _vec[right] = _vec[left];
    }
    _vec[left] = pivot;
    return left;
}

// 打印
    template <typename T, typename Compare>
void MyQsort<T, Compare>::print()
{
    for (auto &elem : _vec)
    {
        cout << elem << " ";
    }
    cout << endl;
}


void test0()
{
    int arr[] = {2, 3, 1, 6, 5};
    MyQsort<int> mq(arr, 5);
    mq.print();

    Point p[5] = {Point(1, 2), Point(1, 1), Point(2, 2), Point(2, 1), Point(0, 0)};
    //MyQsort<Point,PointCompare> mq2(p, 5, PointCompare());// 函数对象,模板参数传入是类型，函数参数传入的是对象或变量
    //MyQsort<Point> mq2(p, 5);// 特化模板
    MyQsort<Point> mq2(p, 5,std::less<Point>());// 特化模板
    mq2.print();
}

int main()
{
    test0();
    return 0;
}
