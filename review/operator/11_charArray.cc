#include <string.h>
#include <iostream>


using std::cout;
using std::endl;

class   CharArray{
public:
    CharArray(const char* pstr)
        :_capacity(strlen(pstr) + 1)
        ,_data(new char[_capacity]())
    {
        strcpy(_data,pstr);
        cout << "CharArray(int capacity)" << endl;
    }
    ~CharArray(){
        if(_data){
            delete []_data;
            _data = nullptr;
        }
        cout << "~CharArray()" << endl;
    }
    // 非const版本
    char& operator[](size_t index){
        if(index >= _capacity - 1){
            cout << "out of range" << endl;
            static char nullchar = '\0';
            return nullchar;
        }
        return _data[index];
    }
    // const版本
    const char& operator[](size_t index)const{
        //_capacity = 100;
        //_data = new char[10]();
        
        //只能人为避免
        //_data[index] = 10;
        return _data[index];
    }
    void print()const{

        cout << _data << endl;
    }
//    friend char& operator[](CharArray&ca,size_t index);//error

private:
    size_t _capacity;
    char* _data;

};
//error
// char& operator[](CharArray&ca,size_t index){
//     if(index >=ca._capacity - 1){
//            cout << "out of range" << endl;
//            static char nullchar = '\0';
//            return nullchar;
//        }
//        return ca._data[index];
// }

void test0()
{
    CharArray ca("hello");
    cout << ca[0] << endl;
    ca[0] = 'e';
    ca.print();
    ca[5] = 'o';
    ca.print();

    const CharArray ca2("waaaa");
    //ca2[1] = 'o';
    cout << ca2[1] << endl;
}

int main()
{
    test0();
    return 0;
}

