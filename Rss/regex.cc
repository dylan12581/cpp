#include <iostream>
#include <string>
#include <regex>

using std::cout;
using std::endl;
using std::regex;
using std::string;


void test0(){
    string  description = "<![CDATA[<p><今天>跟大家分享一个etcd的内存大量占用的问题，这是前段时间在我们开源软件Easegress中遇到的问题，问题是比较简单的，但是我还想把前因后果说一下，包括，为...</p>";
    
    //string  content = nullptr;
    cout << "before = " << description << endl;

    std::regex reg("<[^>]*>");
    description = regex_replace(description, reg, "");//regex_replace函数的使用
   // content = regex_replace(content, reg, "");//regex_replace函数的使用
    cout << "after = " << description << endl;
}

int main()
{
    test0();
    return 0;
}

