#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;


class String
{
public:
    String()
    /* : _pstr(nullptr) */
    : _pstr(new char[1]())
    {
        cout << "String()" << endl;
    }
  
    String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    String(String && rhs)
        :_pstr(rhs._pstr)// 浅拷贝
    {
        cout << "String(String&&)" << endl;
        rhs._pstr = nullptr;
    }
    String(const String & rhs)
    : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    String & operator=(const String & rhs){
        cout << "String &operator=(const String &)" << endl;
        if(this != &rhs){
            if(_pstr)
            {
                delete [] _pstr;
            }
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }

    String& operator=(String&& rhs){
        cout << "String& operator=(String&&)" << endl;
        if(this != &rhs){
            delete  []_pstr;
            _pstr = rhs._pstr;// 浅拷贝
            rhs._pstr = nullptr;
        }
        return *this;
    }

    size_t length() const
    {
        size_t len = 0;
        if(_pstr)
        {
            len = strlen(_pstr);
        }
        return len;
    }

    const char * c_str() const
    {
        if(_pstr)
        {
            return _pstr;
        }
        else
        {
            return nullptr;
        }
    }

    ~String()
    {
        cout << "~String()" << endl;
        printf("_pstr = %p\n",_pstr);
        if(_pstr)
        {
            delete [] _pstr;
            _pstr = nullptr;
        }
    }

    void print() const
    {
        if(_pstr)
        {
            cout << "_pstr = " << _pstr << endl;
        }else{
            cout << endl;
        }
    }

    size_t size()const{
        return strlen(_pstr);
    }

    friend
    ostream& operator<<(ostream&os,String& rhs);

private:
    char * _pstr;
};
ostream& operator<<(ostream&os,String& rhs){
    os << rhs._pstr << endl;
    return os;
}

class SafeFile{
public:
    SafeFile(FILE* fp)
        :_fp(fp)
    {
        cout << "SafeFile(FILE*)" << endl;
    }
    void write(const String& msg){
        fwrite(msg.c_str(),1,msg.size(),_fp);
    }
    ~SafeFile(){
        cout << "~SafeFile()" << endl;
        if(_fp){
            fclose(_fp);
            cout << "fclose(_fp)" << endl;
        }
    }

private:
    FILE* _fp;
};

void test0(){
     String s1("hello");
    // //拷贝构造
     String s2 = s1;
    //先构造，再拷贝构造
    //利用"hello"这个字符串创建了一个临时对象
    //并复制给了s3
    //这一步实际上new了两次
    String s3 = "hello";
    
}
void test1(){
    int a = 1,b = 2;
    &a;
    &b;
    //&(a + b);//err
    //&10;
    //&string("hello");

    int & r1 = a;
    //int & r2 = 1;
    
    const int & r3 = a;
    const int & r4 = 1;

    String s1("hello");
	String s2("wangdao");
	&s1;
	&s2;
	//&(s1 + s2);
    //
    
    // 右值引用只能够绑定右值
    int && r_ref = 10;
  //int && r_ref2 = a;
    & r_ref;
}
void test4(){
    String s3("hello");
    s3 = String("awa");

    String s1("world");
    s1 = s3;

    String("wand") = String("wand");
}
String func2(){
    // String str1("wangdao");
    // str1.print();
    return String("wandao");//返回时会调用移动构造函数
}
void test2(){
    func2();// 临时对象销毁时调用析构函数
    //&func2();
    // String&& ref = func2();//延长对象的生命周期到右值引用的作用域
    // &ref;
    // String str = func2();
    // str.print();
    
}
void test3(){
    String msg = "hello,world";

    SafeFile sf(fopen("wd.txt","a+"));

    sf.write(msg);
}

int main(){
    test2();
    return 0;
}
