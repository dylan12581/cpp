#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class String{
public:
    String()
        :_pstr(new char[1]())
    {cout << "String()"<< endl;}
     String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    String(String&& rhs)
         :_pstr(rhs._pstr){
        cout << "String的移动构造" << endl;
        rhs._pstr = nullptr;}
      //拷贝构造
    String(const String & rhs)
    : _pstr(new char[strlen(rhs._pstr) + 1]()){
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    // 移动赋值构造函数
    String& operator=(String&& rhs){
        cout << "String& operator=(String&& rhs)" << endl;
        //if(this!= &rhs){
            delete  []_pstr;
            _pstr = rhs._pstr;
            rhs._pstr = nullptr;
        //}
        return *this;
    }

    //String & operator=(String && rhs){
    //    delete [] _pstr;
    //    _pstr = new char[6]{'h','e','l','l','o'};
    //    rhs._pstr = nullptr;
    //    cout << "String& operator=(String&&)" << endl;
    //return *this;
    //}

    String& operator=(const String& rhs){
        cout << "String& operator=(const String& rhs)" << endl;
        if(this!= &rhs){
            if(_pstr){
                delete  []_pstr;
            }
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr,rhs._pstr);
        }
        return *this;
    }
    size_t length() const{
        size_t len = 0;
        if(_pstr)
        {
            len = strlen(_pstr);
        }

        return len;
    }
      const char * c_str() const {
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
        if(_pstr)
        {
            delete [] _pstr;
            _pstr = nullptr;
        }
    }
      void print()const
      {
        if(_pstr)
        {
            cout << "_pstr = " << _pstr << endl;
        }else{
            cout << endl;
        }
    }
private:
        char* _pstr;
};

void test0()
{
    String s1("hello");
    String s2 = s1;
    //String s3 = String("hello");
    String s3 = "hello";
}

void test1(){
    String s3("hello");
    s3 = String("wangdao");

    String s1("world");
    s1 = s3;

    String("wangdao") = String("wangdao");
}
void test2(){
    int a = 1;
    &a;
    //&(std::move(a));
    String s1("hello");
    s1.print();

    String s2 = std::move(s1);
    s1.print();
    s2.print();

}
void test3(){
    String s1("hello");
    s1 = std::move(s1);
    s1.print();
}

int main()
{
    test3();
    return 0;
}

