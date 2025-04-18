#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class Stack{
public:
    Stack()
        :_topIndex(-1)
    {}
    bool empty()	//判断栈是否为空
    {
        return (_topIndex == -1);
    }
	bool full()	//判断栈是否已满
    {
        return (_topIndex == _capacity - 1);
    }
	void push(int ele) //元素入栈
    {
        if(full()){
            cout<< "stack is full" << endl;
            return;
        }
        _data[++_topIndex] = ele;
    }
	void pop()     //元素出栈
    {
        if(empty()){
            cout <<"stack is empty" << endl;
            return;
        }
        _topIndex--;
    }
	int  top()		//获取栈顶元素
    {
        return _data[_topIndex];
    }

private:
    static const int _capacity = 10;
    int _data[_capacity];
    int _topIndex; 

};


void test0()
{
    Stack stack;
    // 测试栈是否为空
    cout << "预期输出: 1，实际输出: " << stack.empty() <<endl;
    // 测试 push 和 top
    cout << "测试：push 和 top" << endl;
    stack.push(10);
    cout << "预期输出: 10，实际输出: " << stack.top() << endl;
    // 测试栈是否已满
    cout << "测试：栈是否已满" << endl;
    for (int i = 0; i < 9; ++i) {
        stack.push(i);
    }
    cout << "预期输出: 1，实际输出: " << stack.full() << endl;
    // 测试栈溢出
    stack.push(9);
    // test pop
    cout << "测试：pop" << endl;
    stack.pop();
    cout << "预期输出: 7，实际输出: " << stack.top() << endl;
    // 测试多次pop是否为空
    cout << "测试：栈是否为空（多次 pop 后）" << endl;
    while (!stack.empty()) {
        stack.pop();
    }
    cout << "预期输出: 1，实际输出: " << stack.empty() << endl;
    // 测试栈为空不能继续出栈
    stack.pop();

}

int main()
{
    test0();
    return 0;
}

