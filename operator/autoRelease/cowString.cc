#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::ostream;

class CowString{
public:
    CowString()
        :_pstr(malloc())
    {
        iniRefCount();
    }
    CowString(const char* rhs)
        :_pstr(malloc(rhs))
    {
        iniRefCount();
        strcpy(_pstr,rhs);
    }
    ~CowString(){
        release();
    }
    CowString(const CowString& rhs)
        :_pstr(rhs._pstr)// 浅拷贝
    {
        addRefCount();
    }
    CowString& operator=(const CowString& rhs){
        if(&rhs != this){
            release();
            _pstr = rhs._pstr;
            addRefCount();
        }
        return *this;
    }
    size_t size()const{
        return strlen(_pstr);
    }
    const char* c_str()const{
        return _pstr;
    }
    int refCount(){
        return *(int*)(_pstr - _prefLen); 
    }
    friend ostream& operator<<(ostream& lhs,const CowString& rhs);

    // 缺点：不管是读还是写都会进行深拷贝
    // 因为返回类型是char型，之后调用这个运算符函数具体做读操作还是写操作都是未知的
    //char& operator[](size_t idx){
    //    if(idx < strlen(_pstr)){
    //        if(refCount() > 1){
    //            deRefCount();
    //            // 深拷贝
    //            char* temp = malloc(_pstr);
    //            strcpy(temp,_pstr);
    //            _pstr = temp;
    //            iniRefCount();
    //        }
    //        return _pstr[idx];
    //    }else{
    //        cout << "out of range" << endl;
    //        static char nullchar = '\0';
    //        return nullchar;
    //    }
    //    return _pstr[idx];
    //}

private:
    // 设置一个代理类型,设置为内部类，私有的，只为CowString服务
    class charProxy{
    public:
        charProxy(CowString& cStr,int index)
            :_cStr(cStr)
             ,_index(index)
        {}
        // 返回值为char或char&都行，因为赋值操作里面已经完成，不用&只会影响连续复制的情况
        char& operator=(char c){
            if(_index < 0 || _index < _cStr.size()){
                if(_cStr.refCount() > 1){
                    // 原始空间计数减1
                    _cStr.deRefCount();
                    // 深拷贝
                    char* temp = _cStr.malloc(_cStr._pstr);
                    strcpy(temp,_cStr._pstr);
                    _cStr._pstr = temp;
                    // 初始化新的计数
                    _cStr.iniRefCount();
                }
                // 进行写操作
                _cStr._pstr[_index] = c;
                return _cStr._pstr[_index];
            }
            cout << "out of range" << endl;
            static char nullchar = '\0';
            return nullchar;
        }
        // str[1] = str[2];的情况
        charProxy& operator=(const charProxy& rhs){
            _cStr._pstr[_index] = rhs._cStr._pstr[rhs._index];
            return *this;
        }
        friend ostream& operator<<(ostream& os,const charProxy& rhs);
        // 针对 ch = str[0]; 将charProxy对象转换成char,赋值的三种方式：赋值运算符不可重载(左操作数为char类型)，特殊构造
        // 函数也不行，所以用类型转换函数
        operator char(){
            return _cStr._pstr[_index];
        }

    private:
        CowString& _cStr;// 引用数据成员，初始化要严格初始化或在这里初始化
        size_t _index;
    };
public:
    // CowString类的下标访问运算符返回一个charProxy内部类:包含上一个引用的信息
    charProxy operator[](int idx){
        return charProxy(*this,idx);// 设计思路：看能提供什么，这里返回的不是引用(注意生命周期），而是副本：但绑定的依然是引用
    }

friend ostream& operator<<(ostream& os,const charProxy& rhs);
private:
    void release(){
        deRefCount();
        if(refCount() == 0){
            delete [](_pstr - _prefLen);
            _pstr = nullptr;
            cout << "delete heap" << endl;
        }
    }

    void iniRefCount(){
        *(int*)(_pstr - _prefLen) = 1;
    }

    void addRefCount(){
        ++*(int*)(_pstr - _prefLen);
    }
    void deRefCount(){
        --*(int*)(_pstr - _prefLen);
    }
    char* malloc(const char* rhs = nullptr){
        if(rhs){
            return new char[1 + strlen(rhs) + _prefLen]() + _prefLen;
        }else{
            return new char[1 + _prefLen]() + _prefLen;
        }
    }

private:
    char* _pstr;
    static const int _prefLen = 4;
};
ostream& operator<<(ostream& os,const CowString& rhs){
    os << rhs._pstr;
    return os;
}
// 注意既要访问CowString这个类下的charProxy类
// 又要访问charProxy类下的私有成员，所有都要进行友元声明
ostream& operator<<(ostream& os,const CowString::charProxy& rhs){
    if(rhs._index < 0 || rhs._index < rhs._cStr.size()){
    os << rhs._cStr._pstr[rhs._index];
    }else{
        // os << '\0';
        os << "out of range" ;
    }
    return os;
}

void test1(){
    CowString str1;
    CowString str2 = str1;
    cout << "str1:" << str1 << endl;
    cout << "str2:" << str2 << endl;
    cout << str1.refCount() << endl;
    cout << str2.refCount() << endl;

    cout << endl;
    CowString str3("hello");
    CowString str4 = str3;
    cout << "str3:" << str3 << endl;
    cout << "str4:" << str4 << endl;
    cout << str3.refCount() << endl;
    cout << str4.refCount() << endl;

    cout << endl;
    str1 = str3;
    cout << "str1:" << str1 << endl;
    cout << "str2:" << str2 << endl;
    cout << "str3:" << str3 << endl;
    cout << "str4:" << str4 << endl;
    cout << str1.refCount() << endl;
    cout << str2.refCount() << endl;
    cout << str3.refCount() << endl;
    cout << str4.refCount() << endl;
}
void test0()
{
    CowString str1("hello");
    cout << "str1 refCount:" << str1.refCount() << endl;
    CowString str2 = str1;
    // 此时str2.str1指向同一片堆空间,计数加1
    cout << "写操作前" << endl;
    cout << "str1 refCount:" << str1.refCount() << endl;
    cout << "str2 refCount:" << str2.refCount() << endl;
    str1[0] = 'H';
    // 进行写操作后，str1重新开辟了一块堆空间,原str2空间计数减1，新开辟空间计数为1
    cout << "写操作后" << endl;
    cout << "str1 refCount:" << str1.refCount() << endl;
    cout << "str2 refCount:" << str2.refCount() << endl;
    // 此时str3.str1指向同一片堆空间,计数加1
    CowString str3 = str1;
    cout << "读操作前" << endl;
    cout << "str1 refCount:" << str1.refCount() << endl;
    cout << "str3 refCount:" << str3.refCount() << endl;
    cout << str1[0] << endl;
    // 进行读操作后，str1不会重新开辟新空间，计数不变
    cout << "读操作后" << endl;
    cout << "str1 refCount:" << str1.refCount() << endl;
    cout << "str3 refCount:" << str3.refCount() << endl;

    cout << "str1:" << str1 << endl;
    cout << "str2:" << str2 << endl;
    cout << "str3:" << str3 << endl;

    char c = 'a';
    c = str1[1];
    // 此时也不用重载输出运算符函数
    str1[1] = str1[2];// 需要重载赋值运算符函数
}

int main()
{
    test0();
    return 0;
}

