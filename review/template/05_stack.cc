#include <iostream>
#include <string.h>

using std::cout;
using std::endl;


template <class T = int, int kCapacity = 10>
class Stack
{
public:
    Stack()
    : _top(-1)
    , _data(new T[kCapacity]())
    {
        cout << "Stack()" << endl;
    }
    ~Stack(){
        if(_data){
            delete [] _data;
            _data = nullptr;
        }
        cout << "~Stack()" << endl;
    }
    bool empty() const{
        return -1 == _top;
    }
    bool full() const{
        return _top == kCapacity - 1;
    }
    void push(const T & t1){
        if(!full()){
            _data[++_top] = t1;
        }else{
            cout << "栈已经满" << endl;
        }
    }
    void pop(){
        if(!empty()){
            --_top;
        }else{
            cout << "栈已经空" << endl;
        }
    }
    T top();
private:
    int _top;
    T * _data;
};
template <class T,int kCapacity>
T Stack<T,kCapacity>::top(){
    if(!empty()){
        return _data[_top];
    }else{
        throw "栈为空";
    }
}

void test0()
{
    Stack<int,5> s1;
    Stack<> s2;
}

int main()
{
    test0();
    return 0;
}

