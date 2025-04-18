#include <iostream>
#include <string>
#include <set>
#include <utility>

using std::cout;
using std::endl;
using std::set;
using std::pair;

// 打印
template<class Container>
void display(const Container& con){
    for(auto& elem:con){
        cout << elem << " ";
    }
    cout << endl;
}

void test0()
{
    cout << "====初始化===" << endl;
    set<int> num = {1,3,2,6,5};
    display(num);
    set<int>::iterator it = num.begin();
    cout << "*it:" << *it <<  endl;
    cout << "===插入===" << endl;
    pair<set<int>::iterator,bool> ret = num.insert(4);
    if(ret.second)
    {
        cout << "插入成功 " << *ret.first << endl;
    }
    else
    {
        cout << "插入失败，该元素存在set中" << endl;
    }
    display(num);
    cout << "*it:" << *it <<  endl;
    cout << "===删除===" << endl;
    num.erase(it);
    cout << "*it:" << *it <<  endl;
    cout << "===查找===" << endl;
    size_t cnt = num.count(1);
    cout << "cnt" << cnt << endl;
    set<int>::iterator ret2 = num.find(1);
    if(ret2 == num.end()){
        cout << "该元素不存在set中" << endl;
    }
    else
    {
        cout << "该元素是存在的 " << *it << endl;
    }
    cout << "bound系列函数" << endl;
    set<int>::iterator bd1 = num.lower_bound(1);
    cout << "lower_bound:" << *bd1 << endl;
    set<int>::iterator bd2 = num.upper_bound(1);
    cout << "upper_bound:" << *bd2 << endl;
    pair<set<int>::iterator,set<int>::iterator> bd3 = num.equal_range(2);
    cout << "equal_range:";
    while(bd3.first != bd3.second){
        cout << *bd3.first << " ";
        ++bd3.first;
    }
    cout << endl;
    cout << "===set的下标操作===" << endl;
    //cout << num[0] << endl;
    //num[0] = 1;
}

int main()
{
    test0();
    return 0;
}

