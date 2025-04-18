#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::copy;
using std::ostream_iterator;
using std::istream_iterator;


void test0()
{
    vector<int> vec = {1,2,3};
    ostream_iterator<int> osi(cout," ");
    copy(vec.begin(),vec.end(),osi);
    cout << "|";
}
void test1(){

    vector<int> vec;

    vec.reserve(10);
    istream_iterator<int> isi(cin);

    //copy(isi,istream_iterator<int>(),ostream_iterator<int>(cout," "));
    //copy(isi,istream_iterator<int>(),vec.begin());
    copy(isi,istream_iterator<int>(),std::back_inserter(vec));

    copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
    


    
}

int main()
{
    test1();
    return 0;
}

