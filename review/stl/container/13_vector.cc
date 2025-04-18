#include <iostream>
#include <memory>
#include <string.h>

using std::cout;
using std::endl;
using std::allocator;

template <typename T>
class Vector{
public:
    using iterator = T*;
    Vector();
    ~Vector();
    iterator begin()const{return _start;};
    iterator end()const{return _finish;};
    size_t size()const{return _finish - _start;};
    size_t capacity()const{return _end_of_storage - _start;};
    void push_back(const T& val);
    void pop_back();
    void insert(iterator pos,const T& val);
private:
    void reallocate();
private:
    static allocator<T> _alloc;
    T* _start;
    T* _finish;
    T* _end_of_storage;
};

template<typename T>
allocator<T> Vector<T>::_alloc  = std::allocator<T>();

template<typename T>
Vector<T>::Vector()
    :_start(nullptr),_finish(nullptr),_end_of_storage(nullptr)
{}

template<typename T>
void Vector<T>::insert(iterator pos,const T& val){

    size_t distance = end() - pos;// 在扩容之前记录待插入元素迭代器位置与容器尾部位置
    if(size() == capacity()){
        reallocate();
    }
    auto it = end();
    while(distance--){
        _alloc.construct(it,*(it - 1));
        --it;
    }
    pos = end() - distance;
    _alloc.construct(pos,val);
    ++_finish;// 别忘了这个
}
template<typename T>
Vector<T>::~Vector(){
    if(_start){
        while(_start != _finish){
            _alloc.destroy(--_finish);
        }
        _alloc.deallocate(_start,capacity());
    }
}
template<typename T>
void Vector<T>::push_back(const T& val){
    if(size() == capacity()){
        reallocate();
    }
    _alloc.construct(_finish,val);
    ++_finish;
}

template<typename T>
void Vector<T>::pop_back(){
    if(size() > 0){
        _alloc.destroy(--_finish);
    }
}

template<typename T>
void Vector<T>::reallocate(){
    size_t oldCap = capacity();
    size_t newCap = (oldCap > 0) ? oldCap * 2 : 1;// 考虑原来为空的情况
    T* newStart = _alloc.allocate(newCap);
    if(_start){
        std::uninitialized_copy(_start,_finish,newStart);
        while(_start != _finish){
            _alloc.destroy(--_finish);// 将老的空间的元素销毁
        }
        _alloc.deallocate(_start,oldCap);// 销毁原来老的空间
    }
    // 更新三个指针
    _start = newStart;
    _finish = newStart + oldCap;
    _end_of_storage = newStart + newCap;
}
template <class Container>
void display(const Container &vec){
    cout << "vec.size() = " << vec.size() << endl
         << "vec.capacity() = " << vec.capacity() << endl;
}


void test0()
{
     Vector<int> numbers;
    display(numbers);

    cout << endl;
    numbers.push_back(1);
    display(numbers);

    cout << endl;
    numbers.push_back(2);
    display(numbers);

    cout << endl;
    numbers.push_back(3);
    display(numbers);

    cout << endl;
    numbers.push_back(4);
    display(numbers);

    cout << endl;
    auto it = numbers.begin();
    numbers.insert(it ,0);
    display(numbers);
      for (auto &elem : numbers) // 发现如果没有begin和end迭代器会报错，
    // 说明auto会用到迭代器
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    test0();
    return 0;
}

