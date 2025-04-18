#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;

void inputInt(int & number){
    cout << "请输入一个整数:" << endl;
    cin >> number;
    // 逗号表达式
    //while(cin >> number,number++,!cin.eof());
     while(!cin.eof()){
        if(cin.bad()){
            return;
        }else if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "请输入一个整数：" << endl;
            cin >> number;
        }else{
            // 合法输入
            (cout<< number) << endl;
            break;
        }
    }
}

void test0()
{
    int num = 0;
    inputInt(num);
}

int main()
{
    test0();
    return 0;
}

