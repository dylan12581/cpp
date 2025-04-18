#include <iostream>
#include <string.h>
#include <algorithm>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::for_each;
using std::remove_if;
using std::vector;
using std::move;


template<class T>
void display(const T& container){
    for(auto& ele:container){
        cout << ele << " ";
    }
    cout << endl;
}

bool func(int value){
    return value > 3;
}

void test0()
{
    vector<int> vec = {1, 3, 5, 9, 6, 4, 6, 5};
        //remove_if不能将满足条件的元素删除，但是可以返回待删除
    //元素的首迭代器
    auto it = remove_if(vec.begin(), vec.end(), [](int &value){
                        return value > 5;
                        });
    /* auto it = remove_if(vec.begin(), vec.end(), func); */
    vec.erase(it, vec.end());

    for_each(vec.begin(), vec.end(), [](int &value){
             cout << value << "  ";
             });
    cout << endl;
}
void test1(){
    std::less<int> com;
    cout << com(1,2) << endl;

    vector<int> vec = {1, 3, 5, 9, 6, 4, 6, 5};
    //auto it = remove_if(vec.begin(),vec.end(),std::bind1st(com,5));
    //vec.erase(it,vec.end());
    auto it = remove_if(vec.begin(),vec.end(),std::bind2nd(std::greater<int>(),5));
    vec.erase(it,vec.end());
    
    for_each(vec.begin(),vec.end(),[](int& value){
             cout << value << " ";
             });
    cout << endl;
}
void test2(){
    vector<int> vec;
    vec.push_back(10);

    bool flag = true;
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << "  ";
        if(flag){
            //底层发生了扩容操作，导致迭代器已经失效了
            vec.push_back(20);
            flag = false;
            it = vec.begin();//重置迭代器的位置
        }
    }
    cout << endl;
}


int main()
{
    test2();
    return 0;
}

