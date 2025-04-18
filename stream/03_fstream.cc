#include <string.h>

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;
using std::istream;


void test0()
{
    ifstream ifs;
    ifs.open("test1.cc");

    ifstream ifs2("test2.cc");

    string filename = "test3.cc";
    ifstream ifs3(filename);

    cout << ifs.good() << endl;
    cout << ifs << endl;
    // 为啥会报错？？
    cout << ifs2.good() << endl;
    cout << ifs3.good() << endl;

    string word;
    // ifs>>word返回值为ifs对象本身，等文件输入流进入eofbit状态
    // 结束循环
    while(ifs >> word){
        cout << word << endl;
    }
    // 使用之后关闭文件流
    ifs.close();
}
void test2(){
    ifstream ifs("test1.cc");
    char buff[1024] = {0};
    // 第三个参数为分隔符,可不加
    // 为啥会报错？？
    while(ifs.getline(buff,sizeof(buff),';')){
        cout << buff << endl;
        memset(buff,0,sizeof(buff));
    }
    ifs.close();
}
void test3(){
    string line;
    ifstream ifs("test1.cc");
    // 为啥会报错？？
    while(getline(ifs,line)){
        cout << line << endl;
    }
    ifs.close();
}
void test4(){
    string filename = "test1.cc";
    ifstream ifs(filename);

    if(!ifs){
        cerr << "ifs open file fail";
        return;
    }

    // 读取一个文件的所有内容要先获取文件的大小
    // 将游标放到了文件的最后
    ifs.seekg(0,std::ios::end);
    long length = ifs.tellg();
    cout << length << endl;

    char* pdata = new char[length + 1]();
    // 将游标移动回开头位置
    ifs.seekg(0,std::ios::beg);
    ifs.read(pdata,length);

    //content包含 
    string content(pdata);
    cout << "content" << content << endl;
    cout << "pdata" << pdata ;
    ifs.close();

}

int main()
{
    test4();
    return 0;
}

