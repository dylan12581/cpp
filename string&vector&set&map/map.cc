#include <iostream>
#include <string>
#include <map>
#include <utility>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;
using std::make_pair;

void test0()
{

    pair<int,string> p1(3,"shanghai");

    // 创建
    map<int,string> m1 = {
        {1,"beijing"},
        {3,"chengde"},
        pair<int,string>(2,"shaoxing"),
        p1,
        {4,"hangzhou"},
        make_pair(5,"tianjin")
    };
    // 遍历
    // 1.迭代器
    map<int,string>::iterator it = m1.begin();
    for(;it != m1.end();++it){
        cout << (*it).first << (*it).second << endl;
        cout << it->first << it->second << endl;
    }
    // 增强for循环
    for(pair<const int,string>& ele:m1){
    //for(auto& ele:m1){
        cout << ele.first << ele.second << endl;
    }

    // 查找操作

    size_t result1 = m1.count(1);
    size_t result2 = m1.count(7);
    cout << result1 << endl;
    cout << result2 << endl;
    
    map<int,string>::iterator it2 = m1.find(7);
    if(it2 != m1.end()){
        cout << "find" << it2->first << it2->second << endl;
    }else{
        cout << "not find" << endl;
    }

    map<int,string>::iterator it3 = m1.find(3);
    if(it3 != m1.end()){
        cout << "find" << it3->first << it3->second << endl;
    }else{
        cout << "not find" << endl;
    }
    // 插入操作
    // 1.单个元素
    pair<map<int,string>::iterator,bool> res1 = m1.insert({1,"hainan"});
    if(res1.second == 1){
        cout << "insert sucess:" << res1.first->first << res1.first->second << endl;
    }else{
        cout << "insert failed,ele alread exists:" << res1.first->first << res1.first->second << endl;
    }
    // 2.多个元素
    map<int,string> m2 = {
        {1,"hongkong"},
        make_pair(6,"xiangjiang"),
        pair<int,string>(8,"zhengzhou")
    };

    m1.insert(m2.begin(),m2.end());
    m1.insert({{9,"hefei"},{10,"dali"}});
    m1.insert({{9,"hefei"},{10,"dali"},make_pair(11,"lijiang")});
    
    map<int,string>::iterator it4 = m1.begin();
    for(;it4 != m1.end();++it4){
        cout << it4->first << it4->second << endl;
    }
    // 下标访问
    cout << m1[0] << endl;
    cout << m1[1] << endl;
    cout << m1[2] << endl;
    for(auto& ele:m1){
        cout << ele.first << ele.second << endl;
    }
    m1[0] = "guangdong";
    for(auto& ele:m1){
        cout << ele.first << ele.second << endl;
    }

    map<string,int> m3 = {{"song",1},{"yu",2}};
    for(auto& ele:m3){
        cout << ele.first << ele.second << endl;
    }
    cout << sizeof(m3) << endl;
}


int main()
{
    test0();
    return 0;
}

