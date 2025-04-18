#include <iostream>
#include <string>
#include <map>
#include <utility>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::make_pair;


void checkFind(map<int,string>& rhs,int key){
    auto it = rhs.find(key);
    if(it == rhs.end()){
        cout << "該元素不在map中" << endl;
    }else{
        cout << "該元素在map中" << endl;
        cout << it->first << " " << it->second << endl;
    }

}
void test0()
{
    map<int,string> m1 = {
        {1,"zs"}
        ,make_pair(2,"ls")
        ,pair<int,string>(3,"wu")
    };
    for(auto& ele:m1){
        cout << ele.first << ele.second << endl;
    }
    map<int,string>::iterator it = m1.begin();
    while(it != m1.end()){
        cout << (*it).first << (*it).second << endl; 
        ++it;
    }
    cout << endl;
    cout << m1.count(1) << endl;
    checkFind(m1,2);
    //插入
    
    pair<map<int,string>::iterator,bool> it2 =  m1.insert({3,"wh"});
    if(it2.second){
        cout << it2.first->first << ":" << it2.first->second << endl;
    }else{
        cout << "元素插入失败!!" << endl;
    }
    cout << endl;

    m1[1] = "kk";
    m1[0] = "o00";

    for(auto& ele:m1){
        cout << ele.first << ":" << ele.second << endl;
    }
}

int main()
{
    test0();
    return 0;
}

