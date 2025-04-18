#include <iostream>
#include <vector>
#include <deque>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;

void test0()
{
    deque<int> deq;
    deque<int> deq2(10,1);
    deque<int> deq3(10);
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    deque<int> deq4(arr,arr + 10);
    deque<int> deq5(deq4);
    deque<int> deq6 = {1,2,3};

    for(size_t idx = 0;idx != deq4.size();++idx){
        cout << deq4[idx] << " ";
    }
    cout << endl;
    for(auto& ele:deq5){
        cout << ele << " ";
    }
    cout << endl;
    // 尾部插入与删除
    deq3.push_back(1);
    deq3.push_back(2);
    deq3.pop_back();
    deq3.push_front(1);
    deq3.push_front(1);
    deq3.pop_front();
    auto it = deq3.begin();
    while(it != deq3.end()){
        cout << *it << " ";
        ++it;
    }
    cout << deq[0] <<endl;
}

void test1()
{
    list<int> lis;
    list<int> lis2(10,1);
    list<int> lis3(10);
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    list<int> lis4(arr,arr + 10);
    list<int> lis5(lis4);
    list<int> lis6 = {1,2,3};

    //for(size_t idx = 0;idx != lis4.size();++idx){
    //    cout << lis4[idx] << " ";
    //}
    cout << endl;
    for(auto& ele:lis5){
        cout << ele << " ";
    }

    cout << endl;
    lis3.push_back(1);
    lis3.push_back(2);
    lis3.pop_back();
    lis3.push_front(5);
    lis3.push_front(6);
    lis3.pop_front();

    auto it = lis3.begin();
    while(it != lis3.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

void test2(){
    vector<int> vec;
    vector<int> vec2(10,1);
    vector<int> vec3(10);
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    vector<int> vec4(arr,arr + 10);
    vector<int> vec5(vec4);
    vector<int> vec6 = {1,2,3};

    for(size_t idx = 0;idx != vec4.size();++idx){
        cout << vec4[idx] << " ";
    }
    cout << endl;
    for(auto& ele:vec5){
        cout << ele << " ";
    }
    cout << endl;

    vec3.push_back(1);
    vec3.push_back(2);
    vec3.pop_back();
    //vec3.push_front
    auto it = vec3.begin();
    while(it != vec3.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    int* pdata = vec3.data();
    cout << pdata << endl;

    auto it3 = vec3.begin();
    vec3.insert(it3,1);

    for(auto& ele:vec3){
        cout << ele << " ";
    }
    cout << endl;
}
template<class T>
void display(T container){
    for(auto& ele:container){
        cout << ele << " ";
    }
    cout << endl;
}

void test3(){
    vector<int> number = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    display(number);
    cout << "number.size() = " << number.size() << endl;//9
    cout << "number.capacity() = " << number.capacity() << endl;//9
    cout << endl << "在容器尾部进行插入: " << endl;
    number.push_back(10);
    number.push_back(11);
    display(number);
    cout << "number.size() = " << number.size() << endl;//11
    cout << "number.capacity() = " << number.capacity() << endl;//18
    cout << endl << "在容器vector中间进行插入: " << endl;
    auto it = number.begin();
    ++it;
    ++it;
    number.insert(it, 22);
    display(number);
    cout << "*it = " << *it << endl;
    cout << "number.size() = " << number.size() << endl;//12
    cout << "number.capacity() = " << number.capacity() << endl;//18
    it = number.insert(it, 7, 100);//因为插入个数不确定，有可能底层已经发生了扩容
    display(number);
    cout << "*it = " << *it << endl;
    cout << "number.size() = " << number.size() << endl;//19
    cout << "number.capacity() = " << number.capacity() << endl;//24
                                                                //正确办法是重置迭代器的位置
    vector<int> vec{51, 52, 53, 56, 57, 59};
    number.insert(it, vec.begin(), vec.end());//继续使用该迭代器就会出现问题（内存错误）
    display(number);
    cout << "*it = " << *it << endl;
    cout << "number.size() = " << number.size() << endl;
    cout << "number.capacity() = " << number.capacity() << endl;
    //解决方案：每次在插入元素的时候，可以将迭代器的位置进行重置更新，避免因为底层扩容，迭代器还指向老
    //的空间而出现问题
    //vector<int> vec{51, 52, 53, 56, 57, 59};
    //it = number.begin();//重新置位
    //++it;
    //++it;
    //number.insert(it, vec.begin(), vec.end());//继续使用该迭代器就会出现问题（内存错误）
    //display(number);
    //cout << "*it = " << *it << endl;
    //cout << "number.size() = " << number.size() << endl;
    //cout << "number.capacity() = " << number.capacity() << endl;

}

template<class T>
void printCapacity(const T& vec){
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
}

void test4(){
    vector<int> vec = {1,2,3,4,5,6,6,6};

    auto it = vec.begin();
    it +=2;

    // for(vector<int>::iterator it = vec.begin();it != vec.end();){
    //     if(*it ==  6){    //while行不行，可以
    //         vec.erase(it);
    //     }else{
    //         ++it;
    //     }
    // }
    for(vector<int>::iterator it = vec.begin();it != vec.end();++it){
        while(*it ==  6){    //while行不行，可以
            vec.erase(it);
        }
    }
    display(vec);
    vector<int> vec2 = {1,2,3,4,5,6};
    vec.swap(vec2);
    vec.push_back(7);
    display(vec);
    printCapacity(vec);
    vec.shrink_to_fit();
    printCapacity(vec);
    vec.clear();
    printCapacity(vec);
    
    vec.resize(5,1);
    printCapacity(vec);
    display(vec);

    vec.resize(10);
    printCapacity(vec);
    display(vec);

    cout << vec.front() << endl;
    cout << vec.back() << endl;

    vec.emplace_back(1);
    vec.emplace_back();
    printCapacity(vec);
    display(vec);

    vec.emplace_back(4);
    printCapacity(vec);
    display(vec);
}

void test5(){
    deque<int> vec = {1,2,3,4,5,6,6,6};
    auto it = vec.begin();
    it +=2;

    for(deque<int>::iterator it = vec.begin();it != vec.end();){
        if(*it ==  6){    //while行不行，可以
            vec.erase(it);
        }else{
            ++it;
        }
    }
    display(vec);
    cout << vec.size() << endl;
    vec.emplace_back(7);
    display(vec);

}

template<class T1,class T2>
struct ComparePoint{
    bool operator()(const T1& a,const T2& b)const{
        return a > b;
    }
};
void test6(){
    list<int> vec = {1,2,3,4,5,6,6,6};
    auto it = vec.begin();
    //it +=2;

    for(list<int>::iterator it = vec.begin();it != vec.end();){
        if(*it ==  6){    //while行不行，可以
            it = vec.erase(it);
        }else{
            ++it;
        }
    }
    display(vec);
    cout << vec.size() << endl;
    vec.emplace_back(2);
    display(vec);
    vec.sort();
    display(vec);
    ComparePoint<int,int> cp;
    vec.sort(cp);
    display(vec);
    vec.unique();
    display(vec);
    vec.reverse();
    display(vec);
    list<int> lis2 = {0,8,9};
    vec.merge(lis2);
    display(vec);
    display(lis2);
}
void test7(){
    list<int> number{8, 3, 4, 3, 6, 7, 6, 9, 1, 8, 9};
    number.unique();
    display(number);
    number.sort();//默认情况是以小于符号进行排序
    number.unique();//unique在去除重复元素的时候，链表必须为有序
    display(number);

    list<int> number2{11, 22, 33};
    number.merge(number2);
    number.reverse();
    display(number);

    list<int> number3{41, 42, 43, 44, 45, 46, 47};
    auto it = number.begin();
    ++it;
    ++it;

    auto it2 = number3.begin();
    ++it2;
    ++it2;
    number.splice(it,number3,it2);
    display(number);
}

void test8(){
    list<int> number3{41, 42, 43, 44, 45, 46, 47};
    auto it = number3.begin();
    ++it;
    ++it;
    cout << "*it=" << *it << endl;
    auto it2 = number3.end();
    --it2;
    cout << "*it2=" << *it2 << endl;
    number3.splice(it,number3,it2);
    display(number3);
}
void test9(){
    list<int> number3{41, 42, 43, 44, 45, 46, 47};
    auto it = number3.begin();
    ++it;
    ++it;
    ++it;
    cout << "*it=" << *it << endl;
    auto it2 = number3.begin();
    ++it2;
    cout << "*it2=" << *it2 << endl;
    auto it3 = it2;
    ++it3;
    ++it3;
    ++it3;
    ++it3;
    cout << "*it3=" << *it3 << endl;
    number3.splice(it,number3,it2);
    display(number3);
}

int main()
{
    test4();
    return 0;
}

