#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::set;
using std::multiset;
using std::map;
using std::multimap;
using std::pair;
using std::unordered_map;
using std::unordered_set;
using std::unordered_multimap;
using std::unordered_multiset;

template<class T>
void display(const T& container){
    for(auto& ele:container){
        cout << ele << " ";
    }
    cout << endl;
}

template<class T>
void display2(const T& container){
    for(auto& ele:container){
        cout << ele.first << " " << ele.second << "\n";
    }
}

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
private:
    int _ix;
    int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs){
    os << "("<< rhs._ix << " " << rhs._iy << ")";
    return os;
}

bool operator<(const Point &lhs, const Point &rhs){
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


template<>
struct std::hash<Point>{
    size_t operator()(const Point& rhs)const{
        cout << "template<> struct hash" << endl;
        return (rhs.getX() << 1)^(rhs.getY() << 2);
    }
};

template<>
struct std::equal_to<Point>{
    bool operator()(const Point& lhs,const Point& rhs)const{
        cout << "template<> struct equal_to" << endl;
        return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
    }
};

struct HashPoint{
  size_t operator()(const Point& rhs)const{
        cout << "template<> struct HashPoint" << endl;
        return (rhs.getX() << 1)^(rhs.getY() << 2);
    }
};

struct EqualPoint{
    bool operator()(const Point& lhs,const Point& rhs)const{
        cout << "struct EqualPoint" << endl;
        return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
    }
};
bool operator==(const Point& lhs,const Point& rhs){
    cout << "operator==" << endl;
    return (lhs.getX() == rhs.getX()) && (lhs.getY() == rhs.getY());
}

void test5()
{
    unordered_set<int> number = {1,3,2,6,3,9,7,0};
    display(number);

    auto itt = number.begin();
    ++itt;
    //--itt;
    //itt += 2;

    int arr[] = {1,2,3,0};
    unordered_set<int> number2(arr,arr+5);
    display(number2);
    unordered_set<int> number4(number2);
    display(number4);
    unordered_set<int> number3(std::move(number2));
    display(number3);

    for(auto it = number.begin();it != number.end();++it){
        cout << "*it:" << *it << endl;
    }
    size_t cnt =  number.count(0);
    cout << cnt << endl;
    auto it = number.find(1);
    if(it == number.end()){
        cout << "该元素不存在unordered_set中" << endl;
    }else{
        cout << "元素存在unordered_set中" << endl;
    }
    pair<unordered_set<int>::iterator,bool> ret = number.insert(7);
    if(ret.second){
        cout << "insert success" << *ret.first << endl;
    }else{
        cout << "insert failed" << endl;
    }
    display(number);
    int arr1[] = {1,2,3,5};
    number.insert(arr1,arr1 + 4);
    display(number);
    number.insert({44,33,22});
    display(number);


    auto it2 = number.begin();
    ++it2;
    cout << "*it2=" << *it2 << endl;
    //*it2 = 100;
    number.erase(it2);
    display(number);

    unordered_set<Point,HashPoint,EqualPoint> pnumber = {{1,2},{3,4},{2,3}};
    display(pnumber);

    unordered_set<Point> pnumber2 = {{1,2},{3,4},{2,3}};
    display(pnumber);

}

int main(){
    test5();
    return 0;
}
