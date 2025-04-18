#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;

class Computer{
public:

private:

};

void test0()
{
    shared_ptr<int> sp(new int(10));
    cout << sp.get() << endl;
    cout << *sp << endl;
    shared_ptr<int> sp2 = sp;
    cout << sp2.get() << endl;
    cout << *sp2 << endl;
    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << endl;

    shared_ptr<int> sp3(new int(30));
    sp = sp3;

    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << sp3.use_count() << endl;
}

void test1(){
    shared_ptr<int> sp(new int(36));
    shared_ptr<int> sp2 = sp;
    shared_ptr<int> sp3(new int(72));

    vector<shared_ptr<int>> vec;
    vec.push_back(sp);
    vec.push_back(std::move(sp3));

    cout << sp.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << sp3.use_count() << endl;
    cout << *sp3 << endl;
}

void test2(){
    shared_ptr<int> sp(new int(10));
    cout << "sp.use_count(): " << sp.use_count() << endl;

    cout << endl;
    cout << "执行复制操作" << endl;
    shared_ptr<int> sp2 = sp;
    cout << "sp.use_count(): " << sp.use_count() << endl;
    cout << "sp2.use_count(): " << sp2.use_count() << endl;

    cout << endl;
    cout << "再创建一个对象sp3" << endl;
    shared_ptr<int> sp3(new int(30));
    cout << "sp.use_count(): " << sp.use_count() << endl;
    cout << "sp2.use_count(): " << sp2.use_count() << endl;
    cout << "sp3.use_count(): " << sp3.use_count() << endl;

    cout << endl;
    cout << "执行赋值操作" << endl;
    sp3 = sp;
    cout << "sp.use_count(): " << sp.use_count() << endl;
    cout << "sp2.use_count(): " << sp2.use_count() << endl;
    cout << "sp3.use_count(): " << sp3.use_count() << endl;

	cout << endl;
	cout << "作为容器元素" << endl;
	vector<shared_ptr<int>> vec;
	vec.push_back(sp);
	vec.push_back(std::move(sp2));
}
int main()
{
    test1();
    return 0;
}

