#include <iostream>
#include <vector>
#include <string.h>

using std::cout;
using std::endl;
using std::vector;


void test0()
{
    vector<int> nums{1,2,3};
    vector<int> nums2{3,8,9,7};
    vector<int> nums3{7,4,3,1,4};
    vector<vector<int>> Nums{nums,nums2,nums3};
    for(auto& ele : Nums){
        for(size_t idx = 0;idx < ele.size();++idx){
            cout << ele[idx] << " ";
        }
        cout << endl;
    }
    vector<vector<int>> Nums2{{1,2,3},{3,8,9,7},{7,4,3,1,4}};
    auto it = Nums.begin();
    while(it != Nums.end()){
        for(auto& ele: *it){
            cout << ele << " ";
        }
        ++it;
        cout << endl;
    }
}

int main()
{
    test0();
    return 0;
}

