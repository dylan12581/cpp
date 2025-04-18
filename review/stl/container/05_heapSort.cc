#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;
using std::ostream;

template<class T>
void swap(T& a,T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

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



template <class T,class Compare = std::less<T>>
class HeapSort{
public:
    HeapSort(T* arr,size_t size,Compare = std::less<T>());
    void print(int len);
    void first_build_heap(Compare& com);
    void heapify(int treeLen,int rootIdx,Compare& com);
private:
    vector<T> _vec;
};

template <class T,class Compare>
void HeapSort<T,Compare>::print(int len){
    for(int idx = 0;idx < len;++idx){
        cout << _vec[idx] << " ";
    }
    cout << endl;
}

template <class T,class Compare>
void HeapSort<T,Compare>::heapify(int treeLen,int rootIdx,Compare& com){
    while(1){
        int  maxIdx = rootIdx;
        int leftSonIdx = (rootIdx << 1) + 1;
        int rightSonIdx = (rootIdx << 1) + 2;
        if(leftSonIdx < treeLen && com(_vec[maxIdx],_vec[leftSonIdx])){
            maxIdx = leftSonIdx;
        }
        if(rightSonIdx < treeLen && com(_vec[maxIdx],_vec[rightSonIdx])){
            maxIdx = rightSonIdx;
        }
        if(maxIdx != rootIdx){
            swap(_vec[maxIdx],_vec[rootIdx]);
        }else{
            break;
        }
        rootIdx = maxIdx;
    }
}
template <class T,class Compare>
void HeapSort<T,Compare>::first_build_heap(Compare& com){
    int lastIndex = (_vec.size() - 2) >> 1;
    for(int i = lastIndex;i >= 0;i--){
        heapify(_vec.size(),i,com);
    }
    cout << "第一次堆化之后数组为:" ;
    print(_vec.size());
}

template <class T,class Compare>
HeapSort<T,Compare>::HeapSort(T* arr,size_t size,Compare com)
    :_vec(vector<T>())
{
    for(size_t idx =  0;idx < size;++idx){
        _vec.push_back(arr[idx]);
    }
    // 先进行第一次大顶堆的构建
    first_build_heap(com);

    int heapLen = size;
    while(heapLen > 1){
        swap(_vec[0],_vec[heapLen - 1]);
        --heapLen;
        heapify(heapLen,0,com);
        cout << "重新构建大顶堆后:";
        print(heapLen);
    }
}

void test0()
{
    int arr[] = {9,5,3,1,5};
    HeapSort<int> hs(arr,5);
    hs.print(5);

    Point p[5] = {Point(1, 2), Point(1, 1), Point(2, 2), Point(2, 1), Point(0, 0)};
    //HeapSort<Point,PointCompare> mq2(p,5,PointCompare());
    HeapSort<Point> mq2(p,5);
    mq2.print(5);

}

int main()
{
    test0();
    return 0;
}

