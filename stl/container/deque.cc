#include <iostream>
#include <deque>

using std::cout;
using std::endl;
using std::deque;


template <class Container>
void display(const Container& con){
    for(auto &elem : con)
    {
        cout << elem << "  ";
    }
    cout << endl;
}


void test0()
{
    deque<int> number = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    display(number);

    cout << endl << "在deque的尾部进行插入与删除" << endl;
    number.push_back(111);
    number.push_back(222);
    display(number);
    number.pop_back();
    display(number);

    cout << endl << "在deque的头部进行插入与删除" << endl;
    number.push_front(100);
    number.push_front(200);
    display(number);
    number.pop_front();
    display(number);

    cout << endl << "在deque的任意位置插入元素" << endl;
    deque<int>::iterator it = number.begin();
    it += 2;
    number.insert(it,200);
    display(number);
    cout << "*it" << *it << endl;
    cout << number.size() << endl;
    cout << (it._M_last - it._M_first) << endl;

    number.insert(it,4,55);
    display(number);
    cout << "*it" << *it << endl;

    int arr[] = {12,34,56,78};
    number.insert(it,arr,arr + 4);
    display(number);
    cout << "*it" << *it << endl;

    number.insert(it,{111,333,444,555});
    display(number);
    cout << "*it" << *it << endl;


}

int main()
{
    test0();
    return 0;
}

