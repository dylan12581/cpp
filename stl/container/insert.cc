#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


template<class Container>
void display(Container con){
    for(auto& elem: con){
        cout << elem << " ";
    }
    cout << endl;

}
void test0()
{
    vector<int> nums = {1,2,3,4,5};


    vector<int>::iterator it = nums.begin();
    it += 2;
    cout << "*it : " << *it << endl;
    display(nums);

    nums.insert(it,9);
    display(nums);
    it = nums.begin();
    it += 2;
    cout << "*it : " << *it << endl;
    nums.insert(it,8);
    display(nums);
    cout << "*it : " << *it << endl;

    it = nums.begin();
    it += 2;
    nums.insert(it,0);
    display(nums);
    cout << "*it : " << *it << endl;

    it = nums.insert(it,10,1);
    display(nums);
    cout << "*it : " << *it << endl;
}
void test1(){

    vector<int> nums = {1,2,3,3,3,3,4,5,3,6};

    for(auto it = nums.begin();it != nums.end();++it){
        while(3 == *it){
            nums.erase(it);
            cout << *it << endl;
        }
    }
    display(nums);

}

int main()
{
    test0();
    return 0;
}

