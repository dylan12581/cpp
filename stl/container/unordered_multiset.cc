#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>

using std::cout;
using std::endl;
using std::unordered_multiset;
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
    unordered_multiset<int> num = {1,1,3,2,6,5};
    display(num);
    unordered_multiset<int>::iterator it = num.begin();
    cout << "*it:" << *it <<  endl;
    cout << "===插入===" << endl;
    unordered_multiset<int>::iterator ret = num.insert(4);
    if(ret != num.end())
    {
        cout << "插入成功 " << *ret << endl;
    }
    else
    {
        cout << "插入失败，该元素存在unordered_multiset中" << endl;
    }
    display(num);
    cout << "*it:" << *it <<  endl;
    cout << "===删除===" << endl;
    it = num.erase(it);
    cout << "*it:" << *it <<  endl;
    cout << "===查找===" << endl;
    size_t cnt = num.count(1);
    cout << "cnt" << cnt << endl;
    unordered_multiset<int>::iterator ret2 = num.find(1);
    if(ret2 == num.end()){
        cout << "该元素不存在unordered_multiset中" << endl;
    }
    else
    {
        cout << "该元素是存在的 " << *ret2 << endl;
    }
    cout << "没有bound系列函数" << endl;
    //unordered_multiset<int>::iterator bd1 = num.lower_bound(1);
    //cout << "lower_bound:" << *bd1 << endl;
    //unordered_multiset<int>::iterator bd2 = num.upper_bound(1);
    //cout << "upper_bound:" << *bd2 << endl;
    //pair<unordered_multiset<int>::iterator,unordered_multiset<int>::iterator> bd3 = num.equal_range(2);
    //cout << "equal_range:";
    //while(bd3.first != bd3.second){
    //    cout << *bd3.first << " ";
    //    ++bd3.first;
    //}
    //cout << endl;
    cout << "===unordered_multiset的下标操作无===" << endl;
    //cout << num[0] << endl;
    //num[0] = 1;
}

int main()
{
    test0();
    return 0;
}

