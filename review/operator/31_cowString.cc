#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::ostream;

class CowString{
public:
    CowString();
    CowString(const CowString& rhs);
    CowString(const char* pstr);
    CowString& operator=(const CowString& rhs);
    size_t size(){return strlen(_pstr);};
    const char* c_str(){return _pstr;};
    int use_count(){
        return *(int*)(_pstr - kRefCountLength);
    }

    ~CowString();

private:
    class CharProxy{
    public:
        CharProxy(CowString& cowString ,size_t index)
            :_cowString(cowString)
             ,_index(index){
                 cout << "CharProxy(CowString* cowString,size_t index)" << endl;
             };

        char& operator=(const char& c){
            if(_index >= 0 && _index < _cowString.size()){

                if(_cowString.use_count() > 1){
                    _cowString.decreaseRefcount();
                    char* ptemp = _cowString.malloc(_cowString._pstr);
                    strcpy(ptemp,_cowString._pstr);
                    _cowString._pstr = ptemp;
                    _cowString.initRefCount();
                }
                _cowString._pstr[_index] = c;
                return _cowString._pstr[_index];
            }else{
                cout << "out of range" << endl;
                static char nullchar = '\0';
                return nullchar;
            }
        }


        operator char(){
            cout << "operator char()" << endl;
            return _cowString._pstr[_index];
        }

        //friend
        //ostream& operator<< (ostream& os,const CharProxy& cp);

    private:
        CowString& _cowString;
        size_t _index;
    };

public:
    CharProxy  operator[](size_t idx);
private:
    char* malloc(const char* pstr = nullptr){
        if(pstr){
            return new char[strlen(pstr) + 1 + kRefCountLength]() + kRefCountLength;
        }else{
            return new char[1 + kRefCountLength]() + kRefCountLength;
        }
    }
    void release(){
        decreaseRefcount();
        if(use_count() == 0){
            delete [] (_pstr - kRefCountLength);
            _pstr = nullptr;
            cout << ">>delete heap" << endl;
        }
    }
    void initRefCount(){
        *(int*)(_pstr - kRefCountLength) = 1;
    }
    void increaseRefCount  (){  
        ++*(int*)(_pstr - kRefCountLength);
    }
    void decreaseRefcount(){
        --*(int*)(_pstr - kRefCountLength);
    }
    friend
        ostream & operator<<(ostream & os,const CowString & rhs);
    //friend
    //    ostream& operator<< (ostream& os,const CowString::CharProxy& cp);
private:
    static const int kRefCountLength ;
    char* _pstr;
};
const int CowString::kRefCountLength = 4;

ostream & operator<<(ostream & os,const CowString & rhs){
    os << rhs._pstr;
    return os;
}

//ostream& operator<< (ostream& os,const CowString::CharProxy& cp){
//
//    if(cp._index >= 0 && cp._index < cp._cowString.size()){
//        os << cp._cowString._pstr[cp._index];
//    }else{
//        os << "out of range";
//    }
//    return os;
//}

CowString::CowString()
    :_pstr(malloc())
{
    initRefCount();
    cout << "CowString()" << endl;
}
CowString::CowString(const CowString& rhs)
    :_pstr(rhs._pstr){
        increaseRefCount();
    }
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
        release();
        _pstr = rhs._pstr;
        increaseRefCount();
    }
    return *this;
}
#if 0
char& CowString::operator[](size_t idx){
    if(idx < size()){// 如果这样定义的话，那么不论是读还是写都会进行深拷贝了
        if(use_count() > 1){
            decreaseRefcount();
            char* temp = malloc(_pstr);
            strcpy(temp,_pstr);// 深拷贝
            _pstr = temp;
            initRefCount();
        }
        return _pstr[idx];
    }else{
        cout << "out of range" << endl;
        static char nullchar = '\0';
        return nullchar;
    }
}
#endif

CowString::CharProxy CowString::operator[](size_t idx){
    return CowString::CharProxy(*this,idx);
}

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

void test1(){

    CowString str1;
    CowString str2 = str1;
    cout << "str1:" << str1 << endl;
    cout << "str2:" << str2 << endl;
    cout << str1.use_count() << endl;
    cout << str2.use_count() << endl;

    cout << endl;
    CowString str3("hello");
    CowString str4 = str3;
    cout << "str3:" << str3 << endl;
    cout << "str4:" << str4 << endl;
    cout << str3.use_count() << endl;
    cout << str4.use_count() << endl;

    cout << endl;
    str1 = str3;
    cout << "str1:" << str1 << endl;
    cout << "str2:" << str2 << endl;
    cout << "str3:" << str3 << endl;
    cout << "str4:" << str4 << endl;
    cout << str1.use_count() << endl;
    cout << str2.use_count() << endl;
    cout << str3.use_count() << endl;
    cout << str4.use_count() << endl;
}

int main()
{
    test0();
    return 0;
}

