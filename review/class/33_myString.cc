#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class String{
public:
    String()
        :_pstr(new char[1]())
    {
        cout << "String()" << endl;
    }
    String(const char* pstr)
        :_pstr(new char[strlen(pstr) + 1]())
    {
        strcpy(_pstr,pstr);
        cout << "String(const char* pstr)" << endl;
    }
    size_t size()const{

        if(_pstr){
            return strlen(_pstr);
        }
        return 0; 
    }

    char* c_str()const{
        if(_pstr){
            return _pstr;
        }
        return nullptr;
    }

    String(const String& rhs)
        :_pstr(new char[rhs.size() + 1]())
    {
        strcpy(_pstr,rhs.c_str());
        cout << "String(const String&)" << endl;
    }

    String& operator=(const String& rhs){
        if(this != &rhs){
            if(_pstr){
                delete []_pstr;
            }
            _pstr = new char[rhs.size() + 1]();
            strcpy(_pstr,rhs.c_str());
        }
        cout << "String& operator=(const String&)" << endl;
        return *this;
    }
    ~String(){
        if(_pstr){
            delete []_pstr;
            _pstr = nullptr;
        }
        cout << "~String()" << endl;
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

private:
    char* _pstr;
    int _price;

};
    int main(void)
{
    String str1;
    str1.print();

    cout << endl;
    //隐式转换
    //先使用C风格字符串创建出临时的String对象
    //再复制出str2;
    String str2 = "Hello,world";
    String str3("wangdao");
    str2.print();
    str3.print();

    cout << endl;
    String str4 = str3;
    str4.print();

    cout << endl;
    str4 = str2;
    str4.print();

    const char * pstr = str3.c_str();
    cout << pstr << endl;

    return 0;
}
