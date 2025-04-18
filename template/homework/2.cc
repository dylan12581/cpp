#include <iostream>
#include <set>

using std::cout;
using std::endl;
using std::set;

template<class T>
T add(T t1,T t2){
    return t1 + t2;
}

template<>// 特化模板
set<int> add<set<int>>(set<int> t1,set<int> t2){
    set<int> newSet(t1);
    // for(auto& ele:t2){
    //     newSet.insert(ele);
    // }
    newSet.insert(t2.begin(),t2.end());
    return newSet;
}


void test0()
{
    cout << add(1,2) << endl;
    cout << add(1.1,1.2) << endl;
    set<int> set1 = {1,3,4,5};
    set<int> set2 = {1,2,6,5};
    set<int> set3 = add(set1,set2);
    for(auto& ele:set3){
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
    test0();
    return 0;
}

