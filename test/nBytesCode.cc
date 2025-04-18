#include <iostream>
#include <string>
#include <set>
#include <map>
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::map;

// 判断是中英文字符
size_t nBytesCode(const char ch){
    if(ch & (1 << 7)){
        int nBytes = 1;
        for(int idx = 0;idx != 6;++idx){
            if(ch & (1 << (6 - idx))){
                ++nBytes;
            }else{
                break;
            }
        }
        return nBytes;
    }
    return 1;
}

int main()
{
    string str("nihao中国");
    string ch;
    map<string,set<int>> index;
    for(size_t i = 0;i < str.size();){
        size_t size = nBytesCode(str[i]);
        ch = str.substr(i,size);
        cout << ch << " ";
        index[ch].insert(i);
        i+=size;
    }
    for(auto& ele:index){
        cout << ele.first ;
        for(auto& num:ele.second){
            cout << num << "\n";
        }
    }
    return 0;
}

