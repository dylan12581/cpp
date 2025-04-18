#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
struct Node{
public:
    Node(int num)
        :_num(num)
         ,_next(nullptr)
    {
        cout << "num" << endl;
    }
    int _num;
    Node* _next;
};

class Stack{
public:
    Stack(int capacity)
        :_size(0)
         ,_capacity(capacity)
         ,_head(nullptr)
         ,_tail(nullptr){
             cout << "Stack(int capacity)" << endl;
         }
    ~Stack(){
        if(_head != nullptr){
            Node* tmp = _head;
            _head = _head->_next;
            delete tmp;
        }
        cout << "~Stack()" << endl;
    }

    bool full()const {
        return _size == _capacity;
    }

    bool empty()const{
        return _size == 0;
    }

    void push(const int& value){
        if(!full()){
            Node* new_node = new Node(value);
            if(!_head){
                _head = new_node;
                _tail = new_node;
            }else{
                _tail->_next = new_node;
                _tail = new_node;
            }
            ++_size;
        }else{
            cout << "stack is full" << endl;
        }
    }
    void pop(){// 出栈的时候也要对销毁结点
        if(!empty()){
            if(_size == 1){
                _head = _tail = nullptr;
                delete _head;
            }else{
                Node* tmp = _head;
                while(tmp->_next != _tail){
                    tmp = tmp->_next;
                }
                delete _tail;
                _tail = tmp;
            }
            --_size;
        }else{
            //cout << "stack is empty" << endl;
            throw "stack is empty";
        }
    }
    int top()const{
        if(!empty()){
            return _tail->_num;
        }else{
            //cout << "stack is empty" << endl;
            throw "stack is empty";
        }
    }
private:
    int _size;
    int _capacity;
    Node* _head;
    Node* _tail;
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

