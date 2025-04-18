#include <iostream>
#include <vector>
#include <string.h>

using std::cout;
using std::endl;
using std::vector;

void test0()
{
    int arr[5] = {1,2,3,4,5};
    vector<int> vec1;
    vector<int> vec2(10);
    vector<int> vec3(10,20);
    vector<int> vec4{1,2,3};
    vector<int> vec5(arr,arr + 5);
    vector<int> vec6(vec5.begin(),vec5.end());

    for(auto& ele : vec4){
        cout << ele << endl;
    }

    for(auto& ele : vec5){
        cout << ele << endl;
    }

    for(auto& ele : vec6){
        cout << ele << endl;
    }
}
void test1(){
    vector<int> vec1{1,2,3,4,5};
    vector<int>::iterator it = vec1.begin();
    for(;it != vec1.end();++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "vec1.size = " << vec1.size() << endl;
    cout << "vec1.capacity = " << vec1.capacity() << endl;


    vec1.pop_back();
    cout << endl;
    cout << "vec.size:"  << vec1.size() << endl;
    cout << "vec.capacity:" << vec1.capacity() << endl;

    vec1.shrink_to_fit();
    cout << endl;
    cout << "vec1.size:"  << vec1.size() << endl;
    cout << "vec.capacity:" << vec1.capacity() << endl;

    vec1.clear();
    cout << endl;
    cout << "vec.size:"  << vec1.size() << endl;
    cout << "vec.capacity:" << vec1.capacity() << endl;
}
void test2(){
    vector<int> nums(10);
    cout << "nums.size" << nums.size() << endl;
    cout << "nums.capacity" << nums.capacity() << endl;
    cout << endl;

    vector<int> nums2;
    cout << "nums2.capacity" << nums2.capacity() << endl;
    nums2.reserve(10);
    cout << "nums2.size" << nums2.size() << endl;
    cout << "nums2.capacity" << nums2.capacity() << endl;
}

void test3(){

    vector<int> nums;
    cout << &nums << endl;
    cout << sizeof(nums) << endl;


    cout << "nums is empty? " << nums.empty() << endl;
    cout << "nums' size: " << nums.size() << endl;
    cout << "nums' capacity: " << nums.capacity() << endl;
    cout << endl;

    int num = 10;
    nums.push_back(num);
    cout << "nums' size: " << nums.size() << endl;
    cout << "nums' capacity: " << nums.capacity() << endl;
    cout << endl;

    nums.push_back(10);
    cout << "nums' size: " << nums.size() << endl;
    cout << "nums' capacity: " << nums.capacity() << endl;
    cout << endl;

    nums.push_back(10);
    cout << "nums' size: " << nums.size() << endl;
    cout << "nums' capacity: " << nums.capacity() << endl;
    cout << endl;
    nums.push_back(10);
    cout << "nums' size: " << nums.size() << endl;
    cout << "nums' capacity: " << nums.capacity() << endl;
    cout << endl;
    nums.push_back(10);
    cout << "nums' size: " << nums.size() << endl;
    cout << "nums' capacity: " << nums.capacity() << endl;
    cout << endl;
    nums.push_back(10);
    cout << "nums' size: " << nums.size() << endl;
    cout << "nums' capacity: " << nums.capacity() << endl;
    cout << endl;
    nums.push_back(10);
    cout << "nums' size: " << nums.size() << endl;
    cout << "nums' capacity: " << nums.capacity() << endl;
    cout << endl;
    nums.push_back(10);
    cout << "nums' size: " << nums.size() << endl;
    cout << "nums' capacity: " << nums.capacity() << endl;
    cout << endl;
    nums.push_back(10);
    cout << "nums' size: " << nums.size() << endl;
    cout << "nums' capacity: " << nums.capacity() << endl;
    cout << endl;

    cout << sizeof(nums) << endl;
}


int main()
{
    test3();
    return 0;
}

