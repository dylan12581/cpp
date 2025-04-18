#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::for_each;
using std::vector;

void display(int & value){
    ++ value;
    cout << "value" <<value <<  endl;
}

void test0()
{
    vector<int> vec = {1,5,2,3,4};
    sort(vec.begin(),vec.end());
    // lamda 表达式
    for_each(vec.begin(),vec.end(),[](int value){
             cout << value << " ";
             });
    cout << endl;

    for_each(vec.begin(),vec.end(),display);

    for_each(vec.begin(),vec.end(),[](int value){
             cout << value << " ";
             });
    cout << endl;
    

}

int main()
{
    test0();
    return 0;
}

