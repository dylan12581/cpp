#include <iostream>
#include <string.h>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::vector;

void test0()
{
    shared_ptr<int> sp(new int(1));
    shared_ptr<int> sp2 = sp;
    cout << sp.get() << endl;
    cout << sp2.get() << endl;
    cout << *sp << endl;
    cout << *sp2 << endl;
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << endl;
    shared_ptr<int> sp3(new int(2));
    sp = sp3;
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << sp3.use_count() << endl;
}
void test1(){
    shared_ptr<int> sp(new int(1));
    shared_ptr<int> sp2 = sp;
    shared_ptr<int>sp3(new int(72));

    vector<shared_ptr<int>> vec;
    vec.push_back(sp);
    vec.push_back(std::move(sp3));
    cout << sp.use_count() << "\n";
    cout << sp3.use_count() << "\n";
    cout << vec[1].use_count() << endl;
}

int main()
{
    test1();
    return 0;
}

