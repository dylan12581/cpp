#include <iostream>
#include <limits>
#include <string>


using std::cout;
using std::endl;
using std::string;
using std::cin;

void printStreamStatus(std::istream & is){ 
    cout << "is's goodbit:" << is.good() << endl;
    cout << "is's badbit:" << is.bad() << endl;
    cout << "is's failbit:" << is.fail() << endl;
    cout << "is's eofbit:" << is.eof() << endl;
}
void checkStreamStatus(std::istream & is){ 
    cout << "is's goodbit:" << is.good() << endl;
    cout << "is's badbit:" << is.bad() << endl;
    cout << "is's failbit:" << is.fail() << endl;
    cout << "is's eofbit:" << is.eof() << endl;
}
void readInt(int &num){
    cout << "请输入一个整型 数据" << endl;
    cin >> num;
    while(!cin.eof()){
        if(cin.bad()){
            cout << "cin has broken!" << endl;
            return;
        }else if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "请输入一个int型数据" << endl;
            cin >> num;
        }else{
            cout << "num" << num << endl;
            break;
        }
    }
}
void inputInt(int &num){
    cout << "请输入一个int型数据" << endl;
    while(cin >> num,!cin.eof()){
        if(cin.bad()){
            cout << "cin has broken" << endl;
            return ;
        }else if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "请输入一个int型数据" << endl;
        }else{
            cout << "num" << num << endl;
            break;
         }
    }
}
void test0(){
    printStreamStatus(cin);  //goodbit状态
    int num = 0;    
    cin >> num;   
    cout << "num:" << num << endl;
    printStreamStatus(cin);  //进行一次输入后再检查cin的状态
  if(!cin.good()){
        //恢复流的状态
        cin.clear();
        //清空缓冲区，才能继续使用
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << endl;
        printStreamStatus(cin);
    }
}
void test1()
{

    int num = 10;
    cout << "执行输入操作前检查流的状态" << endl;
    checkStreamStatus(cin);
    cout << endl;
    cout << std::numeric_limits<std::streamsize>::max() << endl;;

    cin >> num;
    cout << "执行输入操作后检查流的状态" << endl;
    checkStreamStatus(cin);
    cout << endl;
    if(!cin.good()){
        // 恢复流的状态
        cin.clear();
        // 清空缓冲区
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        checkStreamStatus(cin);
    }
    string line;
    cin >> line;
    cout << "line" << line <<endl;
    cout << "line.size" << line.size() <<endl;
    cout << "num:" << num << endl;
}
void test2(){
    int num = 0;
    readInt(num);
}
void test3(){
    int num = 0;
    inputInt(num);
}
void test4(){
    int num = 0;
    cin >> num;
    if(cin){// 判断流的状态
        cout << "hello" << endl;
     }
}
void test5(){
    int num = 0,num2 = 0;
    //cout << &cin << endl;
    //cout << &(cin >> num) << endl;
    cin >> num >> num2;
    cout << "num" << num << endl;
    cout << "num2" << num2 << endl;

}
void test6(){
    char *str;
    cin >> str;// 未定义行为
    cout << str;// 未定义行为
}
extern "C" void test8(){
    char* str;
    printf("%s\n",str);// 未定义行为
}
void test9(){
    char a[200] = {0};
    cin.getline(a, 200, ' ');
    cout << a;
}
int main()
{
    test9();
    return 0;
}

