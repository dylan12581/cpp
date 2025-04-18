#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Stack{
public:
    // 构造函数
    Stack()
        :_capacity(4)
         ,_v(vector<int>())
    {
        cout << "Stack()" << endl;
    }
    bool empty(){
        return (_v.size() == 0);
    }
    bool full(){
        return (_v.size() == _capacity);
    }
    void push(int x){
        _v.push_back(x);
    }
    void pop(){
        _v.pop_back();
    }
    int top(){
        auto it = _v.end() - 1;
        return *it;
    }
private:
        
    vector<int> _v;
    int _capacity;

};

void test0()
{
    Stack st;
    cout << st.empty() << endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.full() << endl;
    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.pop();
}

int main()
{
    test0();
    return 0;
}

