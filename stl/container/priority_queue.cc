#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::stack;


void test0()
{
    // 初始化
    vector<int> vec = {1,4,6,3};
    // 默认规则修改为greater
    priority_queue<int,vector<int>,std::greater<int>> pq3(vec.begin(),vec.end());
    // 基本操作
    cout << "size" << pq3.size() << endl;
    cout << "push" << endl;
    pq3.push(5);
    cout << "emplace" << endl;
    pq3.emplace(6);
    // 遍历
    vector<int> vec2 = {0,9,10,8};
    vector<int>::iterator it2 = vec2.begin();
    while(it2 != vec2.end()){
        pq3.push(*it2);
        ++it2;
        cout << "优先级最高的元素" << pq3.top() << endl;
    }
    while(!pq3.empty()){
        cout << pq3.top() << " ";
        pq3.pop();
    }
    cout << endl;
}
void test1(){
    vector<int> vec = {0,9,3,2};

}


int main()
{
    test0();
    return 0;
}

