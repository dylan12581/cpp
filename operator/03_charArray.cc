#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class charArray{
public:
    charArray(const char* pstr)
    :_capacity(strlen(pstr) + 1)
    ,_data(new char[_capacity]())
    {
        strcpy(_data,pstr);
    }
    ~charArray()
    {
        if(_data){
            delete[] _data;
            _data = nullptr;
        }
    }
    charArray(const charArray& rhs)
    :_capacity(rhs._capacity)
    ,_data(new char[rhs._capacity]())
    {
        strcpy(_data,rhs._data);
    }
    charArray& operator=(const charArray& rhs){
        if(this != &rhs){
            delete[] rhs._data;
            _data = new char[rhs._capacity]();
            strcpy(_data,rhs._data);
            _capacity = rhs._capacity;
        }
        return *this;
    }
    // 非const对象调用非const的charArray成员函数
    char&  operator[](size_t idx){
        if(idx < _capacity - 1){
            return _data[idx];
        }else{
            cout << "out of range!" << endl;
            static char nullchar = '\0';
            return nullchar;
        }
    }
    // const的charArray
    const char& operator[](size_t idx)const{
           if(idx < _capacity - 1){
            return _data[idx];
        }else{
            static char nullchar = '\0';
            return nullchar;
        }
    }

private:
    size_t _capacity;
    char* _data;
};

void test0()
{   char arr[] = "hello";
    cout << arr[0] << endl;
    arr[0] = 'H';


    charArray ca("hello");
    //ca.operator[](0);//本质
    cout << ca[0] << endl;
    ca[0] = 'H';
    cout << ca[0] << endl;

    cout << endl;
    const charArray ca2("world");
    cout << ca2[0] << endl;
    cout << ca2.operator[](0)  << endl;
}

int main()
{
    test0();
    return 0;
}

