#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


void test0()
{
    vector<int> vec = {1,2};
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    vec.reserve(10);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    for(auto & elem: vec){
        cout << elem << endl;
    }
}

int main()
{
    test0();
    return 0;
}

