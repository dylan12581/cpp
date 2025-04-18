#include <iostream>
#include <memory>
#include <algorithm>

using std::allocator;
using std::cout;
using std::endl;

template <typename T>
class Vector
{
public:
    using iterator = T*;
    Vector();
    iterator begin()
    {
        return _start;
    }
    iterator end()
    {
        return _finish;
    }
    size_t size() const;
    size_t capacity() const;

    ~Vector();
    void push_back(const T &t);
    void pop_back();
    // reserve todo:思路：要allocato，拷贝原来的内容到新的地址，销毁原来的内容，然后更新capa,还有三个指针
    // void reverse(size_t newCap){
    //     T* newLoc= _alloc.allocate(newCap);
    //     _alloc.construct()
    // }
    
    void insert(iterator pos, const T& value);

private:
    void reallocate(); // 重新分配内存,动态扩容要用的
private:
    static std::allocator<T> _alloc; // 注意此处是静态的成员，不占用对象空间
    T *_start;                       // 指向数组中的第一个元素
    T *_finish;                      // 指向最后一个实际元素之后的那个元素
    T *_end_of_storage;              // 指向数组本身之后的位置
};
template <typename T>
// std::allocator<T> Vector<T>::_alloc = std::allocator<T>();//
std::allocator<T> Vector<T>::_alloc; // 默认调用无参构造

template <typename T>
Vector<T>::Vector()
        : _start(nullptr),
         _finish(nullptr), 
         _end_of_storage(nullptr) {};

template <typename T>
void Vector<T>::push_back(const T &t)
{
    if (size() == capacity())// 边界条件
    {
        reallocate(); // 扩容
    }
    if (size() < capacity())
    {
        _alloc.construct(_finish, t); // 构建对象
        ++_finish;                    // 不要忘记++_finish
    }
}

template <typename T>
size_t Vector<T>::size() const
{
    return _finish - _start;
}

template <typename T>
size_t Vector<T>::capacity() const
{
    return _end_of_storage - _start;
}

template <typename T>
void Vector<T>::pop_back()
{
    if (size() > 0)
    {
        _alloc.destroy(--_finish);// 销毁最后一个元素
    }
}

template <typename T>
void Vector<T>::reallocate() // 重新分配内存,动态扩容要用
{
    // 1.申请两倍的新空间
    size_t oldCapacity = capacity();
    size_t newCapacity = (oldCapacity > 0) ? oldCapacity * 2 : 1;// 考虑原vector为空的情况
    // 2.将老的空间的元素拷贝到新的空间来
    // 3.老空间上的元素需要销毁，同时老的空间也要回收
    // 原vector不为空的情况
    T *newStart = _alloc.allocate(newCapacity);
    if (_start)
    {   // 未初始化的拷贝
        std::uninitialized_copy(_start, _finish, newStart);
        while (_finish != _start)
        {
            _alloc.destroy(--_finish);
            // _alloc.destroy(_start++);// 二选一
        }
        _alloc.deallocate(_start, oldCapacity);
    }
    // 4.三个指针与新的空间之间产生联系
    _start = newStart;
    _finish = _start + oldCapacity;
    _end_of_storage = _start + newCapacity;
}

template <typename T>
Vector<T>::~Vector()
{
    // 原vector为空，什么都不做
    if (_start)
    {
        while (_finish != _start)
        {
            _alloc.destroy(--_finish);
        }
        _alloc.deallocate(_start, capacity());
    }
}

template <typename T>
void Vector<T>:: insert(iterator pos, const T& value){
    
    size_t distance = end() - pos;//记录待插入迭代器与尾部迭代器的偏移量
    if(size() == capacity()){
        reallocate();
    }
    auto it = end();
    while(distance--)
    {
        _alloc.construct(it,*(it - 1));
        --it;
    }
    pos = end() - distance;// 待插入元素的位置
    _alloc.construct(pos,value);
    ++_finish;
}
// 打印，写成模板形式更好
template <class Container>
void display(const Container &vec)
{
    cout << "vec.size() = " << vec.size() << endl
         << "vec.capacity() = " << vec.capacity() << endl;
}

void test()
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


    cout << endl;
    numbers.push_back(5);
    display(numbers);

    cout << endl;
    for (auto &elem : numbers) // 发现如果没有begin和end迭代器会报错，
    // 说明auto会用到迭代器
    {
        cout << elem << " ";
    }
    cout << endl;
    // Todo:insert,clear,

    it = numbers.begin();
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
    test();
    return 0;
}
