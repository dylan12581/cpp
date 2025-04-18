#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


void test0()
{
    cout << "-----初始化------" << endl;
    //1
    vector<int> v;

    //2
    vector<int> v1(10);
    vector<int> v2(10,1);

    //3
    vector<int> v3(v2);
    vector<int> v4(vector<int>(10,2));

    //4
    vector<int> v6(v2.begin(),v2.end());

    //5
    vector<int> v5 = {1,2,3,4,5};

    cout << "-----遍历------" << endl;
    //1.
    for(auto & elem : v2){
        cout << elem << " ";
    }
    cout << endl;
    //2.
    vector<int>::iterator it = v4.begin();
    for(;it != v4.end();++it){
        cout << *it << " ";
    }
    cout << endl;

    //3.
    vector<int>::iterator it2;
    for(it2 = v5.begin();it2 != v5.end();++it2){
        cout << *it2 << " ";
    }
    cout << endl;
    //4.
    for(size_t idx = 0;idx < v6.size();++idx){
        cout << v6[idx] << " ";
    }
    cout << endl;
}
template<class Container>
void print(const Container& container){
    for(auto & elem : container){
        cout << elem << " ";
    }
    cout << endl;
}
void test1(){
    cout << "---尾部插入与删除---" << endl;
    vector<int> v1 = {1,2,3,4,5};
    print(v1);
    v1.push_back(6);
    print(v1);
    v1.pop_back();
    cout << "---头部插入与删除---" << endl;
    cout << "vector不支持头部插入与删除操作" << endl;
    cout << "sizeof(vector): " << sizeof(v1) << endl;
    cout << "&v1" << &v1 << endl; 
    cout << "&v1[0]" << &v1[0] << endl;
    cout << "&*v1.begin()" << &*v1.begin() << endl;
    
    int *pdata = v1.data();
    cout << "pdata = " << pdata << endl;
    cout << "resize()" << endl;
    cout << v1.size() << endl;
    //cout << v1.resize();
}
void test2(){
    vector<int> v1 = {1,2,3,4,5};
    auto it = v1.begin();
    cout << "it[0]" << it[0] << endl;
    //cout << "->" << << endl;
    cout << "*it" << *it << endl;
    it = v1.insert(it,0);
    cout << "*it" << *it << endl;
    


}

int main()
{
test2();
    return 0;
}

