#include <string.h>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ostream;
using std::istream;

class String 
{
public:
    String()
    // : _pstr(nullptr)//后面操作的时候，需要判空
	: _pstr(new char[1]()){
        cout << "String()" << endl;
    }
    // 三合一原则
    //String s1("hello")
    String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 1]()){
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    //String s2 = s1;
    String(const String &rhs)
    : _pstr(new char[strlen(rhs._pstr) +1]()){
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    ~String(){
        cout << "~String()" << endl;
        if(_pstr){
            delete [] _pstr;
            _pstr = nullptr;
        }
    }

    //String s1("hello");
    //String s2("world");
    //s1 = s1;
    //s1 = s2;
    String &operator=(const String &rhs){
        cout << "String &operator=(const String &)" << endl;
        if(this != &rhs){
            delete [] _pstr;
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }
        return  *this;
    }

    // s1 = "hello";
    String &operator=(const char *pstr){
        cout << "String &operator=(const char *)" << endl;
        String tmp(pstr);
        *this = tmp;
        return *this;
    }

    //s1 += s2;
    String &operator+=(const String &rhs)
    {
        cout << "String &operator+=(const String &)" <<endl;

        char * temp = new char[strlen(_pstr) + strlen(rhs._pstr) + 1]();
        strcpy(temp, _pstr);
        strcat(temp, rhs._pstr);
        delete [] _pstr;
        _pstr = temp;

        return *this;
    }

    //s1 += "hello"
    String &operator+=(const char *pstr){
        cout << "String &operator+=(const char *)" << endl;
        String tmp(pstr);
        *this += tmp;
        return *this;
    }

    //const String s1("helo");
    //s1[0]
    char &operator[](size_t index)//index > = 0
    {
        if(index < size()){

            return _pstr[index];
        }else{
            static char nullchar = '\0';
            return nullchar;
        }
    }

    const char &operator[](size_t index) const//不能修改成员的值
    {
        if(index < size()){
            return _pstr[index];
        }else{
            static char nullchar = '\0';
            return nullchar;
        }
    }

    std::size_t size() const{
        return strlen(_pstr);
    }

    const char* c_str() const{
        return _pstr;
    }

    friend bool operator==(const String &, const String &);
    friend bool operator!=(const String &, const String &);

    friend bool operator<(const String &, const String &);
    friend bool operator>(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator>=(const String &, const String &);

    friend ostream &operator<<(ostream &os, const String &s);
    friend istream &operator>>(istream &is, String &s);

private:
    char * _pstr;
};

bool operator==(const String &lhs, const String &rhs){
    return !strcmp(lhs._pstr, rhs._pstr);
}

bool operator!=(const String &lhs, const String &rhs){
    return strcmp(lhs._pstr, rhs._pstr);
}

bool operator<(const String &lhs, const String &rhs)
{
    return strcmp(lhs._pstr, rhs._pstr) < 0;
}

bool operator>(const String &lhs, const String &rhs)
{
    return strcmp(lhs._pstr, rhs._pstr) > 0;
}
bool operator<=(const String &lhs, const String &rhs)
{
    return strcmp(lhs._pstr, rhs._pstr) <= 0;
}
bool operator>=(const String &lhs, const String &rhs)
{
    return strcmp(lhs._pstr, rhs._pstr) >= 0;
}

ostream & operator<<(ostream &os, const String &rhs){
    if(rhs._pstr){
        os << rhs._pstr;
    }
    return os;
}

//String s1("hello")
//cin >> s1;
istream &operator>>(istream &is, String &rhs)
{
    if(rhs._pstr){
        delete [] rhs._pstr;
        rhs._pstr = nullptr;
    }

    //动态获取从键盘输入数据的长度
    vector<char> buffer;
    char ch;
    while((ch = is.get()) != '\n'&&ch != ' '&&ch != '\t')
    /* while((ch = is.get()) != '\n') */
    {
        buffer.push_back(ch);
    }

    rhs._pstr = new char[buffer.size() + 1]();
    strncpy(rhs._pstr, &buffer[0], buffer.size());// 注意对buffer[0]取地址

    return is;
}

// 返回临时值
String operator+(const String &lhs, const String &rhs)
{
    cout << "String operator+(const String &, const String &)" << endl;

    String tmp(lhs);
    tmp += rhs;

    return tmp;
}

//s1 + "hello"
String operator+(const String &lhs, const char *pstr){
    cout << "String operator+(const String &, const char *)"<< endl;
    String tmp(lhs);
    tmp += pstr;

    return tmp;

}

//"hello" + s1
String operator+(const char *pstr, const String &rhs){
    cout << "String operator+(const char*, const String &)" << endl;
    String tmp(pstr);
    tmp += rhs;

    return tmp;
}


void test0()
{
    String s1;
    cin >> s1;
    cout << "s1 = " << s1 << endl;

    /* cout << endl << endl; */
    /* String s2 = "hello"; */
    /* cout << "s2 = " << s2 << endl; */

    /* cout << endl; */
    /* s2 = "world"; */ 
    /* cout << "s2 = " << s2 << endl; */

    /* cout << endl; */
    /* s2 = s2; */
    /* cout << "s2 = " << s2 << endl; */

    /* cout << endl; */
    /* String s3 = "wuhan"; */
    /* String s4 = ",world"; */
    /* s3 += s4; */
    /* cout << "s3 = " << s3 << endl; */

    /* s3 += " welcome to string word"; */
    /* cout << "s3 = " << s3 << endl; */
}

void test1(){
    std::string str1,str2;
    cin >> str1 >> str2;
    cout << "str1:" << str1 << endl;
    cout << "str2:" << str2 << endl;
}

void test2(){
    String str1,str2;
    cin >> str1 >> str2;
    cout << "str1:" << str1 << endl;
    cout << "str2:" << str2 << endl;
}

int main(void)
{
    test2();
    return 0;
}




