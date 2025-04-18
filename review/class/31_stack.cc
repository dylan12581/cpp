#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Stack{
public:
    Stack(int size)
        :_size(size)
        ,_top(-1)
        ,_data(new int[_size]()){

            cout << "Stack(int size)" << endl;
    }
    ~Stack(){
        if(_data){
            delete  []_data;
            _data = nullptr;
        }
        cout << "~Stack()" << endl;
    }
    bool full()const {
        return _top == _size - 1;
    }
    bool empty()const{
        return -1 == _top;
    }
    void push(const int& value){
        if(!full()){
            _data[++_top] = value;
        }else{
            cout << "stack is full" << endl;
        }
    }
    int pop(){
        if(!empty()){
            return _data[_top--];
        }else{
            //cout << "stack is empty" << endl;
            throw "stack is empty";
        }
    }
    int top()const{
        if(!empty()){
            return _data[_top];
        }else{
            //cout << "stack is empty" << endl;
            throw "stack is empty";
        }
    }


private:
    int _size;
    int _top;
    int* _data;

};

void test0()
{
    Stack st(12);
    cout << "栈是不是空的？" << st.empty() << endl;
    st.push(1);
    cout << "栈是不是满的？" << st.full() << endl;

    for(int idx = 2; idx != 15; ++idx)
    {
        st.push(idx);
    }

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << "栈是不是空的？" << st.empty() << endl;
}

int main()
{
    test0();
    return 0;
}

