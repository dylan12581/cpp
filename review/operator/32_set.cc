#include <iostream>
#include <set>
#include <utility>

using std::cout;
using std::endl;
using std::set;
void test0()
{
    set<int> s1;
    set<int> s2{1,2,3};
    set<int> s3(s2);
    set<int> s4(s2.begin(),s2.end());
    for(auto& ele:s2){
        cout << ele << " ";
    }
    cout << endl;
    for(auto it = s3.begin();it != s3.end();++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << s2.count(1) << endl;
    auto it = s2.find(3);
    if(it == s2.end()){
        cout << "不存在" << endl;
    }else{
        cout << *it << endl;
    }
}
void test1(){
    std::pair<int,std::string> num = {1,"xiaoming"};
    cout << num.first << " " << num.second << endl;
}
void test2(){
    set<int> s1{1,2,3};
    std::pair<set<int>::iterator,bool> ret = s1.insert(3);
    if(ret.second){
            cout << "該元素插入成功" << *(ret.first) << endl;
    }else{
        cout << "該元素插入失敗，表明該元素已經存在" << endl;
    }
    s1.insert({0,7,3});
    for(auto & ele:s1){
        cout << ele << " ";
    }
    cout << endl;
    auto it = s1.begin();
    //*it = 300;//error
}

int main()
{
    test2();
    return 0;
}

