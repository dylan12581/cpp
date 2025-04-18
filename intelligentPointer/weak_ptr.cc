#include <iostream>
#include <memory>


using std::cout;
using std::endl;
using std::weak_ptr;
using std::shared_ptr;


void test0()
{
    shared_ptr<int> sp(new int(10));
    weak_ptr<int> wp1(sp);
    weak_ptr<int> wp2;
    weak_ptr<int> wp3;
    wp2 = sp;
    cout << sp.get() << endl;

    cout << wp1.use_count() << endl;
    cout << sp.use_count() << endl;
    cout << wp2.use_count() << endl;

    if(sp){
        cout << "hello" << endl;
     }
    //if(wp3){
    //    cout << "hello" << endl;
    // }
    shared_ptr<int> sp2 = wp2.lock();
    if(sp){
        cout << "提升成功" << endl;
        cout << *sp2 << endl;
    }else{
        cout << "提升失败，托管的空间已经被销毁" << endl;
    }

    bool flag = wp1.expired();
    if(flag){
        cout << "不存在关联的空间" << endl;
    }else{
        cout << "关联的空间存在" << endl;
    }




}

int main()
{
    test0();
    return 0;
}

