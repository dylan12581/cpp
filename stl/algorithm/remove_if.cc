#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::remove_if;
using std::for_each;


void test0()
{
    vector<int> vec = {3,2,1,5,7,3,2};
    //1
    //vector<int>::iterator it = remove_if(vec.begin(),vec.end(),[](int value){
    //          return value > 5;
    //          });
    //2
    //auto it = remove_if(vec.begin(),vec.end(),std::bind1st(std::less<int>(),5));
    //3
    auto it = remove_if(vec.begin(),vec.end(),std::bind2nd(std::greater<int>(),5));
    function<bool()> it2  = std::bind1st(std::greater<int>(),5);
    
    vec.erase(it,vec.end());


    //1
    ////for_each(vec.begin(),vec.end(),[](int value){
    //         cout << value << " ";
    //         });
    
    //2
    std::copy(vec.begin(),vec.end(),std::ostream_iterator<int>(cout," "));
    cout << endl;

}

int main()
{
    test0();
    return 0;
}

