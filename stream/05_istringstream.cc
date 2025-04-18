#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using std::cout;
using std::endl;
using std::istringstream;
using std::ifstream;
using std::string;


void test0()
{
    string s("123 456");

    istringstream iss(s);
    int num1 = 0;
    int num2 = 0;
    iss >> num1 >> num2;
    cout << "num1" << num1 << endl;
    cout << "num2" << num2 << endl;

}
void readConfig(const string& filename){
    ifstream ifs(filename);
    if(!ifs.good()){
        cout << "open file fail" << endl;
        return;
    }

    string line;
    string key,value;
    while(getline(ifs,line)){
        istringstream iss(line);

        iss >> key >> value;
        cout << key << "----->" << value << endl;
    }

}
// 读取配置文件
void test1(){
    readConfig("myserver.conf");
}

int main()
{
    test1();
    return 0;
}

