#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;


void test0()
{
    ofstream ofs("out.txt",std::ios_base::app);
    string line("hello,world!\n");
    ofs << line;
    string word("gn!\n");
    ofs << word;
    char buff[] = "for love";
    ofs.write(buff,strlen(buff));
    ofs.close();
}

void test2(){
    //输入abcd 1234
    char  str ;
    cin >> str;
    cout << str;
}

void test1(){
    //输入abcd 1234
    char a[200] = {0};
    cin.getline(a, 200, ' ');
    cout << a;
}


int main()
{
    test1();
    return 0;
}

