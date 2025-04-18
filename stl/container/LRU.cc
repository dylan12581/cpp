#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>

using std::cout;
using std::endl;
using std::unordered_map;
using std::list;
using std::pair;

class LRUCache {
public:
    LRUCache(size_t capacity)
        :_capacity(capacity)
    {}

    int get(int key) {
        // 之前有此元素，交换到list头部,并返回
        auto it = _map.find(key);
        if(it != _map.end()){
            _list.splice(_list.begin(),_list,it->second);
            // 更新map中key对应list中的位置
            _map[key] = _list.begin();
            return it->second->second;
        }
        // 之前无此元素，返回-1
        return -1;
    }

    void put(int key, int value) {
        // 之前无此元素
        if(_map.count(key) == 0){// 没有则直接插入到list头部
            if(_list.size() == _capacity){// 元素已经满则先pop_back再插入
                auto elem = _list.back() ;// 删除unordered_map中的元素
                _list.pop_back();// 删除list中的尾元素
                _map.erase(elem.first);// 通过key值删除，通过迭代器删除也行
                                       //_map.erase(_map.find(elem.first));// 通过迭代器删除
            }
            //_list.emplace_front(pair<int,int>(key,value));
            _list.push_front({key,value});
            auto currIt = _list.begin();
            _map[key] = currIt;
        }else{// 有则直接更新元素,并且交换到list头部
            _map[key]->second = value;
            _list.splice(_list.begin(),_list,_map[key]);
            //同时更新到map中
            _map[key] = _list.begin();
        }
    }
    void display()const{
        for(auto& elem : _list){
            cout << elem.first << "," << elem.second << " ";
        }
        cout << endl;
    }
private:
    list<pair<int,int>> _list;
    unordered_map<int,list<pair<int,int>>::iterator> _map;
    size_t _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
void test0(){

    LRUCache* obj = new LRUCache(2);
    obj->put(1,10);
    obj->display();
    obj->put(2,20);
    obj->display();
    obj->get(1);
    obj->display();
    obj->put(3,30);
    obj->display();
    delete obj;
}

int main()
{
    test0();
    return 0;
}

