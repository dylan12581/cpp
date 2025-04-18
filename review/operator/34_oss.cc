#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::ostream;

class String{
public:
    String(const char* pstr){
        _size = strlen(pstr);
        if(_size <= 15){
            _capacity = 15;
            memset(_buffer._local,0,sizeof(_buffer._local));
            strcpy(_buffer._local,pstr);
        }else{
            _capacity = _size;
            _buffer._pointer = new char[strlen(pstr) + 1]();
            strcpy(_buffer._pointer,pstr);
        }
    }
    String(const String& rhs)
        :_size(rhs._size)
         ,_capacity(rhs._capacity){
         if(_size <= 15){
            _capacity = 15;
            memset(_buffer._local,0,sizeof(_buffer._local));
            strcpy(_buffer._local,rhs._buffer._local);
        }else{
            _capacity = _size;
            _buffer._pointer = new char[rhs._capacity + 1]();
            strcpy(_buffer._pointer,rhs._buffer._pointer);
        }
    }
    ~String(){
        if(_size > 15){
            delete  []_buffer._pointer;
            _buffer._pointer = nullptr;
        }
    }
    char& operator[](size_t idx){
        if(idx > _size - 1){
            cout << "out of range" << endl;
            static char nullchar = '\0';
            return nullchar;
        }
        if(_size > 15){
            return _buffer._pointer[idx];
        }else{
            return _buffer._local[idx];
        }
    }
    friend
    ostream& operator<<(ostream& os,const String& rhs);
private:
    union Buffer{
    	char * _pointer;
	    char _local[16];
        };

private:
    size_t _size;
    size_t _capacity;
    Buffer _buffer;
};

ostream& operator<<(ostream& os,const String& rhs){
    if(rhs._size > 15){
        os << rhs._buffer._pointer;
    }else{
        os << rhs._buffer._local;
    }
    return os;
}


void test0()
{
    String str1("hello");

    cout << str1 << endl;
    cout << &str1 << endl;
    printf("%p\n",&str1[0]);
    cout << str1[0] << endl;
    str1[0] = 'H';
    cout << str1 << endl;

    cout << endl;
    String str2("hello,world!!!!!");
    cout << str2 << endl;
    cout << &str2 << endl;
    printf("%p\n",&str2[0]);
    cout << str2[0] << endl;
    str2[0] = 'X';
    cout << str2 << endl;

    cout << endl;
    String str3 = str1;
    cout << str3 << endl;
    printf("%p\n",&str3[0]);

    String str4 = str2;
    cout << str4 << endl;
    printf("%p\n",&str4[0]);
}

int main()
{
    test0();
    return 0;
}

