#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class String
{
public:
    String()
    :_pstr(new char[1]{'\0'})// new char语法也可以满足，但析构函数
    {
        cout << "String()" << endl;
    }// 无参构造函数
	String(const char *pstr)
        :_pstr(new char[strlen(pstr) + 1]())
    {
        strcpy(_pstr,pstr);
        cout << "String(const char* )" << endl;
    }
	String(const String &rhs)
        :_pstr(new char[strlen(rhs._pstr) + 1]())
    {
        strcpy(_pstr,rhs._pstr);
    }
	String &operator=(const String &rhs)
    {
        if(this != &rhs ){
        delete[]_pstr;
        _pstr = new char[strlen(rhs._pstr) + 1]();
        strcpy(_pstr,rhs._pstr);
        }
        return *this;
    }
    ~String(){
        if(_pstr){
        delete []_pstr;
        _pstr = nullptr;
        }
        cout << "~string()" << endl;
    }
    void print()const{
        cout << _pstr << endl;
    }
    size_t length() const{
        return strlen(_pstr);
    }
    const char * c_str() const{
        return _pstr;
    }

private:
	char * _pstr;
};

int main()
{
	String str1;
	str1.print();
	

	String str2 = "Hello,world";
	String str3("wangdao");
	
	str2.print();		
	str3.print();	
	
	String str4 = str3;
	str4.print();
	
	str4 = str2;
	str4.print();

    printf("%s\n",str4.c_str());
    printf("%zu\n",str4.length());
	
	return 0;
}
