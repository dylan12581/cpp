#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <list>
#include <set>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::copy;
using std::back_inserter;
using std::cin;
using std::istream_iterator;
using std::list;

void test0()
{
    vector<int> vec = {1,2,3,4,5};
    ostream_iterator<int> oi(cout,"\n");
    copy(vec.begin(),vec.end(),oi);
    cout << "----------" << endl;
}
template<typename T>
void display(const T& con){
    for(auto& ele:con){
        cout << ele << " ";
    }
    cout << endl;
}

void test1(){
    vector<int> vec;
    istream_iterator<int> ii(cin);
    //cout << *ii << endl;
    //ii++;
    //cout << *ii << endl;
    // copy(ii,istream_iterator<int>(),back_inserter(vec));
    //display(vec);
    vec.resize(10);
    cout << vec.size() << endl;
    copy(ii,istream_iterator<int>(),vec.begin());
    cout << "----" << endl;
    display(vec);
}
void test2(){
    vector<int> vec = {1,3,7,9};
    std::list<int> lis = {2,6,8,10};
    //copy(lis.begin(),lis.end(),back_inserter(vec));
    //copy(lis.begin(),lis.end(),std::back_insert_iterator<vector<int>>(vec));
    //copy(vec.begin(),vec.end(),ostream_iterator<int>(cout,"\n"));
    //display(vec);
    //cout << endl;
    ////copy(vec.begin(),vec.end(),std::front_inserter(lis));
    //copy(vec.begin(),vec.end(),std::front_insert_iterator<std::list<int>>(lis));
    //display(lis);
    cout << endl;
    std::set<int> s1 = {1,10,5,6};
    auto it = s1.begin();
    //copy(vec.begin(),vec.end(),std::inserter(s1,it));
    copy(vec.begin(),vec.end(),std::insert_iterator<std::set<int>>(s1,it));
    //copy(vec.begin(),vec.end(),std::back_inserter(s1));// error/set中无push_back函数

    copy(s1.begin(),s1.end(),std::ostream_iterator<int>(cout,"\n"));
    display(s1);

    std::set<int>::reverse_iterator rit = s1.rbegin();
    for(;rit != s1.rend();++rit){
        cout << *rit << " ";
    }
    cout << endl;
}

void test3(){
    vector<int> vec;
    std::set<int> s1 = {2,1,3,5,6,4};
    vec.resize(6);
    display(vec);
    std::uninitialized_copy(s1.begin(),s1.end(),vec.begin());
    display(vec);
}
void func(int& num){
    cout << num << "\n";
}
void test4(){
    vector<int> vec = {1,2,3,2,1};
    int cnt = count(vec.begin(),vec.end(),3);
    cout << "cnt=" <<  cnt << endl;
    auto it = find(vec.begin(),vec.end(),3);
    cout << "it=" << *it << endl;
    bool flag = binary_search(vec.begin(),vec.end(),3);
    cout << "flag=" << flag << endl;
    std::for_each(vec.begin(),vec.end(),func);

    std::for_each(vec.begin(),vec.end(),[](int& num){
                  ++num;
                  cout << num << "\n";
                  });
    display(vec);
}
int ga = 1;
void testLambda(){
    int a = 1;
    std::function<void(int)> f = [=](int value)mutable{
        cout << ga << endl;
        cout << a++ << endl;
        cout << a << endl;
    };
    f(1);
    std::function<int(int)> f2 = std::bind([](int a){return a;},std::placeholders::_1);
    cout << f2(2);
}

using std::string;
using std::function;
vector<function<void(const string &)>> vec;
void test()
{
   int num = 100;
   string name("wangdao");
   vec.push_back([&](const string &value){   //捕获了局部变量的引用//error
       cout << "num = " << num << endl;
       cout << "name = " << name << endl;
       cout << "value = " << value << endl;
   });  
}
void test5() {
   for(auto func : vec)    {   //这边进行执行的时候，num与name已经离开了
                                //作用域，所以相当于捕获了局部变量的引用
                                //同时局部变量离开了其作用域，那么就会有问题
       func("wuhan");
   }
}


int main()
{
    // test();
    test1();
    return 0;
}

