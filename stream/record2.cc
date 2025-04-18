#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // sort函数

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::to_string;

struct Record{
    Record(const string& word,int frequency)
    :_word(word)
    ,_frequency(frequency)
    {}

    string _word;
    int _frequency;
};
// sort函数中比较自定义类的大小关系
bool operator<(const Record& lhs,const Record& rhs){
    return lhs._word < rhs._word;
}

   
   
class Dictionary{
public:
    Dictionary(int capacity)
    {
        _dict.reserve(capacity);
    }
    void read(const string& filename);
    void store(const string& filename);
private:
    vector<Record> _dict;
};
/* 去除字母外的其他字符就是非法 */
string getResult(const string& word){
    string result;
    for(auto & ch : word){
        if(isalpha(ch)){
            result += ch;
        }
    }
    // 考虑使用word.erase();
    return result;
}
void dealWord(string& word){
    auto it = word.begin();
    while(it != word.end()){
        if(!isalpha(*it)){
            // 将it指向下一位
            //返回值是一个迭代器，指向被删除的字符之后的字符位置。
            it = word.erase(it);
        }else{
            ++it;
        }
    }
}

void Dictionary::read(const string& filename){
    // 创建文件流对象
    ifstream ifs(filename);
    if(!ifs){
        cerr << "ifstream open file failed" << endl; 
        return;
    }
    // 逐行读取文件内容
    string line;
    while(getline(ifs,line)){
        istringstream iss(line);
        string word;
        string result;
        while(iss >> word){
            // 非法字符，下一次循环
            result = getResult(word);
            // 二选一
            // dealWord(word);
            // 去除过滤非字母后string为空的情况
            if(result == string())
            {
                continue;;
            }
            int flag = 0;
            for(auto &rec : _dict){
                if(rec._word == result){
                    rec._frequency++;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){// 结构体增加有参构造
                //Record newRecord;
                // newRecord._word = result;
                // newRecord._frequency = 1;
                //_dict.push_back(newRecord);// vector元素存在堆空间，可以
                _dict.push_back(Record(word,1));// vector元素存在堆空间，可以
            }
        }
    }
    // 进行排序
    // 或者可以直接用map容器，得到的结果就是排序好的结果
    sort(_dict.begin(),_dict.end());
}
void Dictionary:: store(const string& filename){

    //ofstream ofs(filename,std::ios::app);
    // 不用追加打开模式，每次生成内容直接进行覆盖
    ofstream ofs(filename);
    //ostringstream oss;
    for(auto & rec : _dict){
        ofs << "|" << rec._word << " " << to_string(rec._frequency) << "|" << endl;
    }
    ofs.close();
}


void test0(const string& filename,const string& filename2)
{
    // 先初始化vector的容量为10000，防止vector反复扩容,耗费性能
    Dictionary dict(10000);
    dict.read(filename);
    dict.store(filename2);
}

int main(int argc,char* argv[])
{
    if(argc != 3){
        cerr << "worng argc!" << endl;
        return -1;
    }
    test0(argv[1],argv[2]);
    return 0;
}
