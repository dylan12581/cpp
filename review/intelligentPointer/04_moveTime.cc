#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
    String()
    : _pstr(new char[1]()){
        cout << "String()" << endl;
    }

    String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 1]()){
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }

    //移动构造
    String(String && rhs)
    : _pstr(rhs._pstr)//浅拷贝
    {
        cout << "String的移动构造" << endl;
        rhs._pstr = nullptr;
    }

    //拷贝构造
    String(const String & rhs)
    : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    //移动赋值函数
    String & operator=(String && rhs){
        cout << "String的移动赋值函数" << endl; 
        if(this != &rhs){
            delete [] _pstr;
            _pstr = rhs._pstr;
            rhs._pstr = nullptr;
        }
        return *this;
    }

    //赋值运算符函数
    String & operator=(const String & rhs)
    {
        cout << "String &operator=(const String &)" << endl;
        if(this != &rhs)
        {
            if(_pstr)
            {
                delete [] _pstr;
            }
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
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
        if(_pstr)
        {
            delete [] _pstr;
            _pstr = nullptr;
        }
    }

    void print() const
    {
        /* &this; */
        if(_pstr)
        {
            cout << "_pstr = " << _pstr << endl;
        }else{
            cout << endl;
        }
    }
private:
    char * _pstr;
};

String func2(){
    String str1("wangdao");
	str1.print();
    return str1;//调用移动构造函数
}

void test2(){
    func2();
    //&func2(); //error,右值
   	String && ref = func2();
    &ref;  //右值引用本身为左值
}

String s10("beijing");

String func3(){
    s10.print();
    return s10;
}

void test3(){
    //func3的返回值是s10的副本（复制产生的）
    func3();   //调用拷贝构造函数
}

int main()
{
    test3();
    return 0;
}

