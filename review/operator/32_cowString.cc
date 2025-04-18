#include <iostream>
#include <string.h>
#include <ostream>

using std::cout;
using std::endl;

class CowString{
public:
    CowString();
    CowString(const CowString& rhs);
    CowString(const char* msg);
    CowString& operator=(const CowString& rhs);
    size_t size()const{return strlen(_pstr);}
    const char* c_str()const{return _pstr;}
    int use_count()const{return *(_pstr - kRefCountLength);}
    ~CowString();
private:
    class CharProxy{
    public:
        CharProxy(CowString& cowString,size_t index)
            :_index(index),_cowString(cowString){
            }

        char& operator=(const char& ch){
            if(_index >= 0 && _index < _cowString.size()){
                if(_cowString.use_count() > 1){
                    _cowString.deRefCount();// 引用计数-1
                    char* ptemp = _cowString.malloc(_cowString.c_str());// 深拷贝
                    strcpy(ptemp,_cowString.c_str());// 深拷贝
                    _cowString._pstr = ptemp;//深拷贝
                    _cowString.initRefCount();//新空间初始化引用计数
                }
                _cowString._pstr[_index] = ch;
                return _cowString._pstr[_index];
            }else{
                cout << "out of range" << endl; 
                static char nullChar = '0';
                return nullChar;
            } 
        }
        operator char(){
            cout << "operator char()" << endl;
            return _cowString._pstr[_index];
        }

    friend
    std::ostream& operator<<(std::ostream& os,const CowString::CharProxy& charProxy);

    private:
        size_t _index;
        CowString& _cowString;
    };
public:
    CharProxy operator[](int index);
    friend
    std::ostream& operator<<(std::ostream& os,const CowString::CharProxy& charProxy);
private:
    static const int kRefCountLength ;
    char* _pstr;
private:
    // 工具函数
    // 引用计数相关
    void inRefCount(){
        ++*(_pstr - kRefCountLength);
    }
    void deRefCount(){
        --*(_pstr - kRefCountLength);
    }
    void initRefCount(){
        *(_pstr - kRefCountLength) = 1;
    }
    char* malloc(const char* pstr = nullptr){
        if(pstr){// 不为空
            return new char[strlen(pstr) + 1 + kRefCountLength]() + kRefCountLength;
        }else{
            return new char[ 1 + kRefCountLength]() + kRefCountLength;
        }
    }
    void release(){
        deRefCount();
        if(use_count() == 0){
            delete  [](_pstr - kRefCountLength);
            _pstr = nullptr;
            cout << ">>delete heap" << endl;
        }

    }
};
const int CowString::kRefCountLength = 4;

std::ostream& operator<<(std::ostream& os,const CowString& cowString){
    os << cowString.c_str();
    return os;
}

std::ostream& operator<<(std::ostream& os,const CowString::CharProxy& charProxy){
    if(charProxy._index >= 0 && charProxy._index < charProxy._cowString.size()){
        os << charProxy._cowString._pstr[charProxy._index];
    }else{
        os << "out of range";
    }
    return os;
}

CowString::CowString()
    :_pstr(malloc()){
        initRefCount();
    };
CowString::CowString(const CowString& rhs)
    :_pstr(rhs._pstr){
        inRefCount();
    };
CowString::CowString(const char* pstr)
    :_pstr(malloc(pstr)){
        strcpy(_pstr,pstr);
        initRefCount();
    }
CowString::~CowString(){
    release();
}
CowString& CowString::operator=(const CowString& rhs){
    if(this != &rhs){
        // 释放原来的内存
        release();
        // 浅拷贝
        _pstr = rhs._pstr;
        // 引用计数加一
        inRefCount();
    }
    return *this;
}
CowString::CharProxy CowString::operator[](int index){
    return CharProxy(*this,index);
};


void test0()
{
    CowString str1("hello");
    CowString str2 = str1;// 拷贝构造函数
    cout << str1.use_count() << endl;
    cout << str2.use_count() << endl;

    str1[0] = 'H';// 写
    str1.operator[](0).operator=('H');

    char ch = 'A';
    ch = str1[0];
    cout << ch << endl;
    cout << str1[0] << endl;

    cout << str1.use_count() << endl;
    cout << str2.use_count() << endl;

    cout << str1 << endl;
    cout << str2 << endl;
}

int main()
{
    test0();
    return 0;
}

