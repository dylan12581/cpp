#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template<class T>
void swap(T& a,T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T, typename Compare = std::less<T>> 
class HeapSort 
{ 
public:  
    HeapSort(T *arr, size_t size);  
    void heapAdjust(size_t ,size_t,Compare&);  
    void sort(Compare&);
    void print()const;
private:  
    vector<T> _vec;
    Compare _cmp;
};


template<typename T,typename Compare>
void HeapSort<T,Compare>::print()const{
    for(auto & elem : _vec){
        cout << elem << " ";
    }
    cout << endl;
}

template<typename T,typename Compare>
void HeapSort<T,Compare>::heapAdjust(size_t rootIdx,size_t heapLen,Compare& cmp){
    size_t leftSonIdx = (rootIdx << 1) + 1;
    size_t rightSonIdx = (rootIdx << 1) + 2;
    size_t maxIdx = rootIdx;// 假设最开始的最大元素下标是rootIdx
                            //
    if(leftSonIdx < heapLen && cmp(_vec[maxIdx],_vec[leftSonIdx])){
        maxIdx = leftSonIdx;
    }
    if(rightSonIdx < heapLen && cmp(_vec[maxIdx],_vec[rightSonIdx])){
        maxIdx = rightSonIdx;
    }
    // 现在maxIdx位置的元素是三个结点中最大的，交换元素
    //_vec.swap(maxIdx,rootIdx);
    if( maxIdx != rootIdx ){
        swap(_vec[maxIdx],_vec[rootIdx]);
    //接下来需要接着判断交换后的maxId的子树是否符合大顶堆的概念
        heapAdjust(maxIdx,heapLen,cmp);
    }
}

template<typename T,typename Compare>
void HeapSort<T,Compare>::sort(Compare& cmp){
    // 交换首尾元素，传入根节点继续进行构建大根堆
    size_t heapLen = _vec.size() ;
    while(heapLen > 1){
        //_vec.swap(0,heapLen);
        swap(_vec[0],_vec[heapLen - 1]);
        --heapLen;
        heapAdjust(0,heapLen,cmp);
    }
    // 构建结束
}
    template<typename T,typename Compare>
HeapSort<T,Compare>::HeapSort(T* arr,size_t size)
    :_vec(vector<T>())
    ,_cmp(Compare())
{
    for(size_t idx = 0;idx < size;++idx){
        _vec.push_back(arr[idx]);
    }
    // 先进行第一次大顶堆的构建
    for(int idx = (size - 2) / 2; idx >= 0;--idx){
        cout << idx << endl;
        heapAdjust(idx,size,_cmp);
    }

    print();
    // 构建完成之后，根元素就是最大的元素
    // 交换首尾元素，此时只有根节点不满足条件，传入根节点继续进行构架大根堆
    sort(_cmp);
}
int main()
{
    int arr[] = {9,5,3,1,5};
    cout << "arr" << endl;

    HeapSort<int> hs(arr,5);
    cout << "main";
    hs.print();

    return 0;
}

