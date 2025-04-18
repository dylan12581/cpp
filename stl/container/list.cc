#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

template<class Container>
void display(Container con){
    for(auto& elem: con){
        cout << elem << " ";
    }
    cout << endl;
}


void test1(){

    list<int> nums = {1,2,3,4,3,3,4,5,3,6};

    for(auto it = nums.begin();it != nums.end();++it){
        while(3 == *it){
            it = nums.erase(it);
            cout << *it << endl;
            display(nums);
        }
    }
    display(nums);
}

void test2(){
    cout << "-----list 初始化----" << endl;
    list<int> l;
    display(l);
    cout << "----迭代器遍历---" << endl;
    list<int>::iterator it = l.begin();
    for(;it != l.end();++it){
        cout << *it  << " ";
    }

    cout << endl;
    list<int> l1(10,1);
    display(l1);
    cout << "----增强for循环遍历---" << endl;
    for(auto & elem : l1){
        cout <<elem <<" ";
    }

    cout << endl;
    list<int> l2(l1.begin(),l1.end());
    display(l2);
    cout <<"-----list不支持下标遍历" << endl;

    list<int> l3(l2);
    display(l3);
    list<int> l5(list<int>(10,2));
    display(l5);

    list<int> l4 = {3,2,5,1,4,4,6};
    display(l4);

    cout << endl;
    cout <<"---尾部插入与删除操作" << endl;
    l4.push_back(6);
    display(l4);
    l4.pop_back();
    l4.emplace_back(0);
    display(l4);
    cout <<"---头部插入与删除操作" << endl;
    l5.push_front(1);
    l5.pop_front();
    l4.emplace_front(0);
    cout <<"---任意位置插入与删除操作" << endl;
    list<int>::iterator it4 = l4.begin();
    ++it4;
    ++it4;
    cout << "*it4: " << *it4 << endl;
    // insert返回值是insert插入元素最开始位置的迭代器
    it4 = l4.insert(it4,1);
    display(l4);
    cout << "*it4: " << *it4 << endl;
    it4 = l4.insert(it4,5,3);
    display(l4);
    cout << "*it4: " << *it4 << endl;
    l4.insert(it4,l5.begin(),l5.end());
    display(l4);
    cout << "*it4: " << *it4 << endl;
    it4 = l4.insert(it4,{1,2,3,4,5});
    display(l4);
    cout << "*it4: " << *it4 << endl;
    cout <<"---其他操作---" << endl;
    cout << "l4.size():" << l4.size() << endl;
    cout << "l4.earse()" << endl;
    for(it4 = l4.begin();it4 != l4.end();)
    {
        if(2 == *it4){
            it4 = l4.erase(it4);
        }else{
            ++it4;
        }
    }
    display(l4);
    cout << "swap()" << endl;
    l4.swap(l5);
    display(l4);
    cout << "resize()" << endl;
    l4.resize(5);
    display(l4);
    l4.resize(10);
    display(l4);
    l4.resize(15,1);
    display(l4);
    cout << l4.back() << endl;
    cout << l4.front() << endl;
    cout << "sort()" << endl;
    l4.sort();
    display(l4);
    cout << "reverse()" << endl;
    l4.reverse();
    display(l4);
    cout << "unique()" << endl;
    l4.unique();
    l4.sort();
    display(l4);
    cout << "l5:";
    display(l5);
    l5.sort();
    cout << "l5:";
    display(l5);

    cout << "merge()" << endl;
    l4.merge(l5);
    display(l4);


    cout << "splice()" << endl;
    l4.splice(l4.begin(),l4,l4.begin());
    display(l4);
}
void test3(){
    list<int> number = {1, 3, 3, 5, 8, 9, 3, 4, 2};
    display(number);

    list<int> number2 = {11, 55, 99, 77, 33};
    display(number2);

    cout << endl;
    auto it = number.begin();
    ++it ;
    cout << "*it" << *it << endl;

    auto it2 = number2.begin();
    ++it2;
    ++it2;
    cout << "*it2" << *it2 << endl;

    cout<< "具体位置的某个元素" << endl;
    number.splice(it,number2,it2);
    display(number);
    display(number2);
    cout << "*it2" << *it2 << endl;
}
void test4(){
    cout << "同意链表进行splice操作" << endl;
    list<int> number2 = {11, 55, 99, 77, 33};
    display(number2);
    auto it = number2.begin() ;
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    auto it2 = number2.end();
    --it2;
    --it2;
    cout << "*it2 = " << *it2 << endl;

    number2.splice(it,number2,it2);
    display(number2);

}

void test5(){
    cout << "同意链表进行splice操作" << endl;
    // 注意范围，会出错 
    list<int> number2 = {11, 55, 99, 77, 33};
    display(number2);
    auto it = number2.begin() ;
    ++it;
    ++it;
    cout << "*it = " << *it << endl;
    auto it2 = number2.end();
    auto it3 = number2.begin() ;
    ++it3;
    cout << "*it3 = " << *it3 << endl;

    number2.splice(it,number2,it3,it2);
    display(number2);

}

int main()
{
    test4();
    return 0;
}

