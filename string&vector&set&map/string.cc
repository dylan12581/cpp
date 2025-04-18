#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


// string的初始化
void test0()
{
    string str;
    cout << str << endl;

    string str2("hello");
    cout << str2 << endl;

    string str3(str2);
    cout << str3 << endl;

    string str4 = str2;
    cout << str4 << endl;

    string str5(str2,2,2);
    cout << str5 << endl;

    string str6(2,'h');
    cout << str6 << endl;

    string str7 = "hello";
    cout << str7 << endl;

    string str8("hello",2);
    cout << str8 << endl;

    // 迭代器的方式创建
    // begin()返回首迭代器
    // end()返回尾后迭代器
    string str9(str2.begin(),str2.end());
    cout << str9 << endl;

    const char* str10 = "hell0";
    string str11(str10,str10 + 5);
    cout << str11 << endl;


    //char* str12 = str2.begin();// error
    auto it = str2.begin();// 自动推导类型
    string::iterator it2 = str2.end();
    string str12(it,it2);
    cout << str12 << endl;

    string str13 = str2 + ',' + str12 + "hhh";
    cout << str13 << endl;
}
// 常用操作
void test1(){
    string str2("hello");
    printf("%s\n",str2.c_str());
    printf("%s\n",str2.data());

    cout << str2.empty() << endl;
    cout << str2.size() << endl;
    cout << str2.length() << endl;

    str2.push_back('a');
    cout << str2 << endl;

    str2.append(1,'e');
    cout << str2 << endl;
    str2.append("iou");
    cout << str2 << endl;

    string str1(str2);
    str2.append(str1,5);
    cout << str2 << endl;
    cout << str1 << endl;
    cout << endl;

    // 查找子串
    size_t pos1 = str2.find(str1,0);
    cout << pos1 << endl;

    size_t pos2 = str2.find('h',0);
    cout << pos2 << endl;

    size_t pos3 = str2.find("hello",0,5);
    cout << pos3 << endl;

    bool a = (str2 >= str1);
    cout << a << endl;
}
void test3()
{

    string str = "this is an example";
    cout << str << '\n';
    // earse返回的是迭代器后边的内容
    string::iterator it = str.begin();
    str.erase(it);
    cout << str << '\n';


}
// 遍历
void test2(){
    string str("hello");
    // for循环遍历
    for(size_t idx = 0;idx < str.size();idx++)
    {
        cout << str[idx] << endl;
    }
    // cout << str.at(5) << endl;
    cout << endl;
    // 增强for循环遍历
    for(auto & ch: str){
        cout << ch << endl;
    }
    cout << endl;

     cout << endl;

    // iterator
    string::iterator it = str.begin();
    // auto it = str.begin();
    for(;it != str.end();it++){
        cout << *it << endl;
    }
    cout << endl;

}
void test4(){
    string str("");
    cout << str.size() << endl;
}
void test5(){
    string str("hello");
    string sub = str.substr(0,1);
    cout << sub << endl;
}


int main()
{
    test5();
    return 0;
}

