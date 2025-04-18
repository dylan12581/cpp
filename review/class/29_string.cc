#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void test0()
{
    string str;
    string str2("hello");
    string str3("world",3);
    string str4(str3);
    string str5(5,'h');
    string str6(str2,1,3);

    cout << str << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 << endl;
    cout << str5 << endl;
    cout << str6 << endl;
}
void test1(){
    char arr[] = "hello";
    string str(arr,arr + 5);
    cout << str << endl;
    string str2(str.begin(),str.end());
    cout << str2 << endl;
}
void test2(){
    string str1 = "hello";
    string::iterator it =  str1.begin();
    auto it2 = str1.end();
    string str2(it,it2);
    cout << str2 << endl;
}
void test3(){
    string str = "hello";
    str += ",world";
    cout << str << endl;
    string str2 = str + '!';
    cout << str2 << endl;
}
void test4(){
    string str1("hello");
    printf("str1 = %s\n",str1.c_str());
    printf("addressof str1 = %p\n",str1.data());
    cout << &str1 << endl;
    cout << str1.size() << endl;
    cout << str1.length() << endl;
    str1.append(1,',');
    str1.append("world");
    str1.append(string("!"));
    cout << str1 << endl;
    cout << str1.find(',') << endl;
    cout << str1.find("world") << endl;
    cout << str1.find("wc",0,1) << endl;
}
void test5(){
    string str("hello");
    for(size_t idx = 0;idx < str.size();++idx){
        cout << str[idx] << endl;
    }
    cout << str.at(4) << endl;
    cout << str.at(5) << endl;
}
void test6(){
    string str("hello");
    for(auto& c:str){
        cout << c << endl;
    }
    auto it = str.begin();
    while(it != str.end()){
        cout << *it << endl;
        ++it;
    }
}
void test7(){
    string str(5,'h');
    cout << &str << endl;
    printf("%p\n",&str[0]);
}

int main()
{
    test7();
    return 0;
}

