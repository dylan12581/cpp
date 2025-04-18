#include <iostream>
#include <string.h>

using std::cout;
using std::cerr;
using std::endl;
//自定义一个String类保存字符串内容，实现以下String类的各个函数，并给出相应的测试用例
class String 
{
public:
	String()
    :_pstr(new char[1]())
    {
    }
	String(const char *pstr)
    :_pstr(new char[strlen(pstr) + 1]())
    {
        strcpy(_pstr,pstr);
    }
	String(const String &str)
    :_pstr(new char[strlen(str._pstr) + 1]())
    {
        strcpy(_pstr,str._pstr);
    }
	~String(){
        if(_pstr){
            delete []_pstr;
            _pstr = nullptr;
        }
        cout << "~String()" << endl;
     }
	String &operator=(const String & str){
        if(this != &str){
            delete []_pstr;
            _pstr = new char[strlen(str._pstr) + 1]();
            strcpy(_pstr,str._pstr);
        }
        return *this;

    }
	String &operator=(const char *pstr){
           //if(this->_pstr!= pstr){//应该不存在自相等的情况
            delete []_pstr;
            _pstr = new char[strlen(pstr) + 1]();
            strcpy(_pstr,pstr);
        //}
        return *this;
    }
	String &operator+=(const String &str){
        size_t totalLen = strlen(_pstr) + strlen(str._pstr);
        const char* temp = _pstr;
        _pstr = new char[totalLen + 1 ]();
        strcat(_pstr,temp);
        strcat(_pstr,str._pstr);
        delete [] temp; 
        return *this;
    }
	String &operator+=(const char *pstr){
        
        size_t totalLen = strlen(_pstr) + strlen(pstr);
        const char* temp = _pstr;
        _pstr = new char[totalLen + 1 ]();
        strcat(_pstr,temp);
        strcat(_pstr,pstr);
        delete [] temp; 
        return *this;
    }
	
	char &operator[](std::size_t index){
        if(index < strlen(_pstr) - 1){
            return _pstr[index];
        }else{
            cerr << "out of range" << endl;
            static char errorValue = '\0';
            return errorValue;
        }
    }

	const char &operator[](std::size_t index) const{
            if(index < strlen(_pstr) - 1){
            return _pstr[index];
        }else{
            cerr << "out of range" << endl;
            static char errorValue = '\0';
            return errorValue;
        }
    }
	
	std::size_t size() const{
        return strlen(_pstr);
    }
	const char* c_str() const{
        return _pstr;
    }
	 void print()const{
        cout << _pstr << endl;
    }
	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);
	
	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);
	
	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);

private:
	char * _pstr;
};
bool operator==(const String &lhs, const String &rhs){
    return (strcmp(lhs._pstr,rhs._pstr) == 0) ? true : false;
}
bool operator!=(const String &lhs, const String &rhs){
    return (strcmp(lhs._pstr,rhs._pstr) == 0) ? false : true;
}
bool operator<(const String &lhs, const String &rhs){
    return (strcmp(lhs._pstr,rhs._pstr) < 0) ? true : false;
}
bool operator>(const String &lhs, const String &rhs){
    return (strcmp(lhs._pstr,rhs._pstr) > 0) ? true : false;
}
bool operator<=(const String &lhs, const String &rhs){
    return (strcmp(lhs._pstr,rhs._pstr) < 0 || strcmp(lhs._pstr,rhs._pstr) == 0) ? true : false;
}
bool operator>=(const String &lhs, const String &rhs){
    return (strcmp(lhs._pstr,rhs._pstr) > 0 || strcmp(lhs._pstr,rhs._pstr) == 0) ? true : false;
}
std::ostream &operator<<(std::ostream &os, const String &s){
    os << s._pstr ;
    return os;
}
std::istream &operator>>(std::istream &is, String &s){
    is >> s.

}

String operator+(const String &lhs, const String &rhs){
     size_t totalLen = lhs.size() + rhs.size();
     char* pstr = new char[totalLen + 1 ]();
    strcat(pstr,lhs.c_str());
    strcat(pstr,lhs.c_str());
    return String(pstr);
}
String operator+(const String &lhs, const char *rhs){
     size_t totalLen = lhs.size() + strlen(rhs);
     char* pstr = new char[totalLen + 1 ]();
        strcat(pstr,lhs.c_str());
        strcat(pstr,rhs);
        return String(pstr);
}
String operator+(const char *lhs, const String &rhs){
       size_t totalLen = strlen(lhs) + rhs.size();
        char* pstr = new char[totalLen + 1 ]();
        strcat(pstr,lhs);
        strcat(pstr,rhs.c_str());
        return String(pstr);
}

void test0()
{
    String str1;
	str1.print();

	String str2("wangdao");
	str2.print();
	
    String str3(str2);
	str3.print();

    String str4 = str3;
	str4.print();

    String str5 = "wangdao5";
    str5.print();

    str5 += str2;
    str5.print();
    
    str5 += "4321";
    str5.print();

    cout << str5[0] << endl;
    str5[0] = 'T';
    str5.print();

    const String str6("wangdao");
    cout << str6[0] << endl;
    //str6[0] = 'T';

    cout << str6.size() << endl;
    printf("%s\n",str6.c_str());

    String str7 = str6 + str6;
    str7.print();

    String str8 = str7 + "1234";
    str8.print();

    String str9 = "1234" + str7;
    str9.print();
}

int main()
{
    test0();
    return 0;
}

