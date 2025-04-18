#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void test0()
{
    vector<int> numbers;
    vector<long> numbers2(10);
    vector<int> numbers3(10,1);
    vector<int> numbers4{1,2,3};
    // 迭代器进行构造
    vector<int> numbers5(numbers3.begin(),numbers3.end());

    int a = *numbers3.begin();
    cout << "a=" << a << endl;

    int arr[5] = {1,2,3,4,5};
    vector<int> numbers6(arr,arr + 5);
    // 遍历
    for(int idx = 0;idx < numbers5.size();idx++){
        cout << numbers5[idx] << endl;
    }
    // 
    for(auto & ele: numbers6){
        cout << ele << endl;
    }
    for(int & ele: numbers6){
        cout << ele << endl;
    }
    //
    vector<int>::iterator it = numbers6.begin();
    // auto it = numbers6.begin();
    for(;it != numbers6.end();it++){
        cout << *it << endl;
    }

}
void test1(){

    vector<int> num{1,2,3,4,5};
    cout << num.size() << endl;
    cout << num.capacity() << endl;
    cout << endl;
    num.push_back(1);
    for(int & ele: num){
        cout << ele << endl;
    }
    cout << num.capacity() << endl;

    num.pop_back();
    for(int & ele: num){
        cout << ele << endl;
    }
    cout << endl;
    num.clear();
    cout << num.size() << endl;
    cout << num.capacity() << endl;
    cout << endl;

    num.reserve(5);
    cout << num.size() << endl;
    cout << num.capacity() << endl;
}
void test2(){
    vector<int> numbers;
    cout << numbers.size() << endl;
    cout << numbers.capacity() << endl;
    cout << sizeof(numbers) << endl;

    numbers.push_back(1);
    cout << numbers.size() << endl;
    cout << numbers.capacity() << endl;
    cout << sizeof(numbers) << endl;

    numbers.push_back(1);
    cout << numbers.size() << endl;
    cout << numbers.capacity() << endl;
    cout << sizeof(numbers) << endl;

    numbers.push_back(1);
    cout << numbers.size() << endl;
    cout << numbers.capacity() << endl;
    cout << sizeof(numbers) << endl;
}

int main()
{
    test2();
    return 0;
}

