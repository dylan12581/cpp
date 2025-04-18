#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

using std::cout;
using std::endl;
using std::ofstream;
using std::string;


void test0()
{
    ofstream ofs;
    ofs.open("1.cc");

    ofstream ofs2("2.cc");

    string filename = "3.cc";
    ofstream ofs3(filename);
}
void test1(){

    string filename = "3.cc";
    ofstream ofs(filename);

    string line("hello world!\n");
    ofs << line;

    ofs.close();
}
void test2(){

    string filename = "2.cc";
    ofstream ofs(filename,std::ios::app);

    string line("hello world!\n");
    ofs << line;
}
void test3(){

    string filename = "4.cc";
    ofstream ofs(filename,std::ios::app);

    char buff[100] = "hello world";
    ofs.write(buff,sizeof(buff));

}

int main()
{
    test3();
    return 0;
}

