#include <iostream>
#include <set>
#include <utility>
#include <string>

using std::cout;
using std::endl;
using std::set;
using std::pair;
using std::string;


void test0()
{
    // set的创建
    set<int> s1;
    set<int> s2{3,2,3,5,1};
    set<int> s3(s2.begin(),s2.end());
    set<int> s4 = s3;
    s1= s4;
    // 遍历结果自动去重和排序
    for(auto& ele : s1){
        cout << ele << endl;
    }
    //auto it = s1.begin();
    set<int>::iterator it1 = s1.begin();
    for(;it1 != s1.end();++it1){
        cout << *it1 << endl;
    }
    // 查找
    size_t result = s1.count(1);
    size_t result2 = s1.count(9);
    cout << result << endl;
    cout << result2 << endl;

    set<int>::iterator it = s1.find(1);
    set<int>::iterator it2 = s1.find(9);
    if(it != s1.end()){
        cout << "该元素存在:"<< *it << endl;
    }else{
        cout << "该元素不存在" << endl;
    }

    if(it2 != s1.end()){
        cout << "该元素存在:"<< *it << endl;
    }else{
        cout << "该元素不存在" << endl;
    }
    // 插入数据
    pair<set<int>::iterator,bool> p1 = s1.insert(8);
    if(p1.second == true){
        cout << "插入成功" << *p1.first << endl;
    }else{
        cout << "插入失败,已经存在" << *p1.first << endl;
    }
    // 插入多个数据
    set<int> s5 = {6,7,8};
    s1.insert(s5.begin(),s5.end());
    // for(auto& ele:s1);
    for(const int& ele:s1){
        cout << ele << " ";
    }
    cout << endl;

    s1.insert({11,12,13});
    for(const int& ele:s1){
        cout << ele << " ";
    }
    cout << endl;
    // 不允许修改值
    set<int>::iterator it3 = s1.begin();
    ++it3;
    //*it3 = 100;// error
}

void pairTest(){
    pair<int,string> num1 = {1,"hello"};
    pair<string,int> num2 = {"abandon",1};
    pair<string,int> num3("abandon",2);

    cout << num1.first << " " << num1.second << endl;
    cout << num2.first << " " << num2.second << endl;
    cout << num3.first << " " << num3.second << endl;
}

int main()
{
    // test0();
    pairTest();
    return 0;
}

