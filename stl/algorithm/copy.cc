#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::copy;
using std::ostream_iterator;
using std::istream_iterator;

void test0()
{
    
    vector<int> vec;
    istream_iterator<int> isi(cin);
    copy(isi,istream_iterator<int>(),std::back_inserter(vec));
    copy(isi,istream_iterator<int>(),std::back_insert_iterator<vector<int>>(vec));

    copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    
}

int main()
{
    test0();
    return 0;
}

