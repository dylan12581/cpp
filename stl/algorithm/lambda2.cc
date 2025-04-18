#include <iostream>
#include <vector>
#include <string>
#include <functional>

using std::cout;
using std::endl;
using std::function;
using std::vector;
using std::string;

vector<function<void(const string& )>> vec;
void test0()
{
    int num = 100;
    string name("wanddaao");

    vec.push_back([&num,&name](const string& value){
                  cout << "num = " << num << endl;
                  cout << "name = " << name << endl;
                  cout << "value = " << value << endl;
                  });
}
void test2()
{
    for(auto func : vec)
    {
        func("wuhan");
    }
}

int main()

{
    test0();
    test2();
    return 0;
}

