#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;
using std::ostream;

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

template<>
struct std::less<Point>{
    bool operator()(const Point& lhs,const Point& rhs){
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
struct PointCompare{
     bool operator()(const Point &lhs, const Point &rhs){
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

template<class T,class Compare = std::less<T>>
class MyQsort{
public:
    MyQsort(T* arr,size_t size,Compare compare = Compare());
    void quick(int left,int right,Compare& com);
    int partition(int left,int right,Compare& com);

    void print();

private:
    vector<T> _vec;
};

template<class T,class Compare>
MyQsort<T,Compare>::MyQsort(T* arr,size_t size,Compare compare){
    for(size_t i = 0;i < size;++i){
        _vec.push_back(arr[i]);
    }
    quick(0,_vec.size() - 1,compare);
}

template<class T,class Compare>
int MyQsort<T,Compare>:: partition(int left,int right,Compare& com){
    T pivot = _vec[left];
    int low = left;
    int high = right;
    while(low < high){
        while(low < high && com(pivot,_vec[high])){
                --high;
        }
        if(low < high){
            _vec[low] = _vec[high];
            ++low;
        }
        while(low < high && !com(pivot,_vec[low])){
                ++low;
        }
        if(low < right){
            _vec[high] = _vec[low];
            --high;
        }
    }
    _vec[low] = pivot;
    return low;
}
template<class T,class Compare>
void MyQsort<T,Compare>::quick(int left,int right,Compare& com){
    if(left >= right){
        return;
    }

    int pivot = partition(left,right,com);
    quick(left,pivot - 1,com);
    quick(pivot + 1,right,com);
}

    template <typename T, typename Compare>
void MyQsort<T, Compare>::print()
{
    for (auto &elem : _vec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void test0(){
    int arr[] = {3,4,0,5,2,7,3,6};
    MyQsort<int> mq(arr, 8);
    mq.print();

    Point p[5] = {Point(1, 2), Point(1, 1), Point(2, 2), Point(2, 1), Point(0, 0)};
    MyQsort<Point,PointCompare> mq2(p,5);
    //MyQsort<Point> mq2(p,5,std::less<Point>());
    mq2.print();
}

int main()
{
    test0();
    return 0;
}

