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


struct ComparePoint{
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

template<>
struct std::less<Point>{

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
    set<int> number = {1,3,2,6,3,9,7,0};
    display(number);
    int arr[] = {1,2,3,0};
    set<int> number2(arr,arr+5);
    display(number2);
    set<int> number4(number2);
    display(number4);
    set<int> number3(std::move(number2));
    display(number3);

    
    for(auto it = number.begin();it != number.end();++it){
        cout << "*it:" << *it << endl;
    }
    size_t cnt =  number.count(0);
    cout << cnt << endl;
    auto it = number.find(1);
    //it += 2;
    ++it;
    --it;
    if(it == number.end()){
        cout << "该元素不存在set中" << endl;
    }else{
        cout << "元素存在set中" << endl;
    }
    pair<set<int>::iterator,bool> ret = number.insert(7);
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

    set<Point> pnumber = {{1,2},{3,4},{2,3}};
    display(pnumber);

    set<Point,ComparePoint> pnumber2 = {{1,2},{3,4},{2,3}};
    display(pnumber);
}

void test1()
{
    multiset<int> number = {1,3,2,6,3,9,7,0};
    display(number);
    auto it1 = number.lower_bound(2);
    //it1 += 2;
    cout << "*it1=" << *it1 << endl;
    auto it4 = number.upper_bound(2);
    cout << "*it2=" << *it4 << endl;
    auto range = number.equal_range(3);

    while(range.first != range.second){
        cout << *range.first << endl;
        ++range.first;
    }

    int arr[] = {1,2,3,0};
    multiset<int> number2(arr,arr+5);
    display(number2);
    multiset<int> number4(number2);
    display(number4);
    multiset<int> number3(std::move(number2));
    display(number3);

    for(auto it = number.begin();it != number.end();++it){
        cout << "*it:" << *it << endl;
    }
    size_t cnt =  number.count(0);
    cout << cnt << endl;
    auto it = number.find(1);
    if(it == number.end()){
        cout << "该元素不存在multiset中" << endl;
    }else{
        cout << "元素存在multiset中" << endl;
    }

    auto ret = number.insert(7);
    cout << "insert success" << *ret << endl;
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

    multiset<Point> pnumber = {{1,2},{3,4},{2,3}};
    display(pnumber);

    multiset<Point,ComparePoint> pnumber2 = {{1,2},{3,4},{2,3}};
    display(pnumber);
}
void test2(){
    map<int,string> number = {
        {2,"world"}
        ,{3,"hello"}
        ,std::make_pair(4,"wuhan")
        ,pair<int,string>(5,"chengde")
    };
    display2(number);
    pair<map<int,string>::iterator,bool> it3 = number.insert({0,"yingfang"});
    if(it3.second){
        cout << "insert success" << it3.first->first << " " << it3.first->second << "\n";
    }else{
        cout << "insert failed,already exists" << endl;
    }
    auto it = number.begin();
    auto it2 = it;
    ++it2;
    //it2 += 2;
    number.erase(it,it2);
    display2(number);
    cout << number[0] << endl;
    display2(number);

    map<Point,int,ComparePoint> number2 = {
        {{1,2},1}
        ,{{2,3},2}
        ,{{2,4},2}
    };
    display2(number2);
}
void test3(){

    multimap<int,string> number = {
        {2,"world"}
        ,{3,"hello"}
        ,std::make_pair(4,"wuhan")
        ,pair<int,string>(5,"chengde")
    };
    display2(number);
    multimap<int,string>::iterator it3 = number.insert({0,"yingfang"});
        cout << "insert success" << it3->first << " " << it3->second << "\n";
    auto it = number.begin();
    auto it2 = it;
    ++it2;
    //it2 += 2;
    number.erase(it,it2);
    display2(number);
    //cout << number[0] << endl;
    display2(number);

    multimap<Point,int,ComparePoint> number2 = {
        {{1,2},1}
        ,{{2,3},2}
        ,{{2,4},2}
    };
    display2(number2);
}


int main()
{
    test3();
    return 0;
}

