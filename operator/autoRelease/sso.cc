#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::ostream;

class String {
public:
    String(const char * pstr){
        if(strlen(pstr) <= 15){
            strcpy(_buffer._local,pstr);
            _size = strlen(pstr);
            _capacity = 15;
        }else{// 开辟空间，深拷贝
            _buffer._pointer = new char[strlen(pstr) + 1]();
            strcpy(_buffer._pointer,pstr);
            _size = strlen(pstr);
            _capacity = _size;
        }
    }
    ~String(){
        if(_capacity > 15){
            delete []_buffer._pointer;
            _buffer._pointer = nullptr;
        }
    }
    char & operator[](size_t idx){
        if(idx > _size - 1){
            cout << "out of range" << endl;
            static char nullchar = '\0';
            return nullchar;
        }
        if(_capacity <= 15){
            return _buffer._local[idx];
        }else{
            return  _buffer._pointer[idx];
        }
    }
    void getSizeCapa(){
        cout << "size:" << _size << endl;
        cout << "capacity:" << _capacity << endl;
    }


    friend
    ostream & operator<<(ostream & os,const String & rhs);
private:
	union Buffer{
		char * _pointer;
		char _local[16];
	};
	size_t _size;
	size_t _capacity;
    Buffer _buffer;
};

ostream& operator<<(ostream& os,const String & rhs){
    if(rhs._capacity <= 15){
        os << rhs._buffer._local;
    }else{
        os << rhs._buffer._pointer;
    }
    return os;
}

void test0(){
    String str1("hello");
    cout << str1 << endl;
    str1.getSizeCapa();
    cout << str1[0] << endl;
    cout << str1[6] << endl;

    String str2("hello,world!!!!!");
    cout << str2 << endl;
    str2.getSizeCapa();
    cout << str2[0] << endl;
    cout << str2[17] << endl;
}

int main()
{
    test0();
    return 0;
}

