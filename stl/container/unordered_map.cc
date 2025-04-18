#include <math.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <utility>

using std::cout;
using std::endl;
using std::unordered_map;
using std::pair;
using std::map;
using std::string;
using std::make_pair;
using std::ostream;

// 打印
template<class Container>
void display(const Container& con){
    for(auto& elem:con){
        cout << elem.first << " " << elem.second;
    }
    cout << endl;
}

class Point{
public:
    Point(int x = 0,int y = 0)
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
ostream & operator<<( ostream& os,const Point& rhs);
private:
    int _ix;
    int _iy;

};
ostream & operator<<(ostream& os,const Point& rhs){
    os <<"(" << rhs._ix << " " << rhs._iy << ")";
    return os;
}


void test0()
{
    cout << "====初始化===" << endl;
    unordered_map<string,Point> num = {
        pair<string,Point>("wuhan",Point(1,2)),
        {"wuhan",Point(2,2)},
        {"shaoxing",Point(4,2)},
        make_pair("wangdap",Point(6,7)),
    };
    display(num);

    cout << "===插入===" << endl;
    pair<unordered_map<string,Point>::iterator,bool> ret = num.insert({"hello",Point(7,7)});
    if(ret.second)
    {
        cout << "插入成功 " << ret.first->first << " " << ret.first->second << endl;
    }
    else
    {
        cout << "插入失败，该元素存在unordered_map中" << endl;
    }
    display(num);

    cout << "===删除===" << endl;
    auto it = num.begin();
    auto it2 = num.begin();
    ++it2;
    ++it2;
    num.erase(it);
    display(num);
    cout << "===查找===" << endl;
    size_t cnt = num.count("hello");
    cout << "cnt" << cnt << endl;
    unordered_map<string,Point>::iterator ret2 = num.find("shaoxing");
    if(ret2 == num.end()){
        cout << "该元素不存在unordered_map中" << endl;
    }
    else
    {
        cout << "该元素是存在的 " << ret2->first  << ret2->second<< endl;
    }

    cout << "无bound系列函数" << endl;
    //unordered_map<string,Point>::iterator bd1 = num.lower_bound("wuhan");
    //cout << "lower_bound:" << bd1->first << bd1->second << endl;
    //unordered_map<string,Point>::iterator bd2 = num.upper_bound("shaoxing");
    //cout << "upper_bound:" << bd2->first << bd2->second << endl;
    //pair<unordered_map<string,Point>::iterator,unordered_map<string,Point>::iterator> bd3 = num.equal_range("shaoxing");
    //cout << "equal_range:";
    //while(bd3.first != bd3.second){
    //    cout << bd3.first->first << bd3.first->second << " ";
    //    ++bd3.first;
    //}
    cout << endl;
    cout << "===unordered_map的下标操作===" << endl;
    cout << "下标无则增添" << endl;
    cout << num[string("xxx")] << endl;
    display(num);
    cout << "下标有修改" << endl;
    num[string("shaoxing")] = Point(1,2);
    display(num);
    cout << "只打印" << endl;
    cout << num[string("shaoxing")]<< endl;
    display(num);
    



}

int main()
{
    test0();
    return 0;
}

