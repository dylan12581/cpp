#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::istringstream;
using std::ifstream;

void test0(){
    /* string s("hello world"); */
    string s("123 456");
    int num = 10;
    int num2 = 10;
    //将字符串内容传递给了字符串输入流对象  
    istringstream iss(s);
    iss >> num >> num2;
    cout << "num:" << num << endl;
    cout << "num2:" << num2 << endl;
}

void readConfig(const string & filename){
    ifstream ifs(filename);

    if(!ifs){
        cerr << "ifstream open file failed!" << endl;
        return;
    }

    string line;
    string key;
    string value;
    while(getline(ifs,line)){
        istringstream iss(line);
        iss >> key >> value;
        cout << key << " -----> " << value << endl;
    }
}

void test1(){
    readConfig("myserver.conf");
}

int main(void){
    test0();
    return 0;
}
