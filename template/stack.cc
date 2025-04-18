#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <class T = int,int kCapacity = 10>
class Stack{
public:
    Stack()
        :_data(new T[kCapacity]())
         ,_top(-1)
    {
        cout << "Stack()" << endl;
    }
    Stack(T x)
        :_data(new T[x]())
         ,_top(-1)
    {
        cout << "Stack()" << endl;
    }
    ~Stack(){
        if(_data){
            delete []_data;
            _data = nullptr;
        }
        cout << "~Stack()" << endl;
    }
    bool empty()const{
        return _top == -1;
    }
    bool full()const{
        return _top == kCapacity;
    }
    void push(const T & rhs){
        if(full()){
            throw "stack is full!";
        }
        _data[++_top] = rhs; 
    }
    void pop(){
        if(empty()){
            throw "stack is empty";
        }
        --_top;
    }
    T top();

private:
    T* _data;
    int _top;
};

template <class T,int kCapacity>
T Stack<T,kCapacity>::top(){
    if(empty()){
        throw "stack is empty";
    }
    return _data[_top];
}
void test0()
{
    Stack<string,20> st;
    st.push("hello");
    st.push("world");
    cout << st.top() << endl;
    st.pop();
    st.pop();

    try{
    st.pop();
    }catch(const char* msg){
        cout << "st is empty" << endl;
    }


    Stack<>st2;
    st2.push(1);
    st2.push(2);
    cout << st2.top() << endl;



    Stack<> st3(10);// 无法通过隐式推导！！！，可以将默认值设置为char进行查看
    st2.push(1);
    st2.push(2);
    cout << st2.top() << endl;

}

int main()
{
    test0();
    return 0;
}

