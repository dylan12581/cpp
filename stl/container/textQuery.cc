#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include <unordered_set>
#include <utility>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;
using std::unordered_set;
using std::unordered_multiset;
using std::pair;

// 拿到题目，先对数据成员进行分析，先看用什么数据成员
class TextQuery
{
public:
    //......
    TextQuery(int capacity){
        _lines.reserve(capacity);// 先申请capacity的空间
    }
    void readFile(const string & filename);
    void query(const string & word);//

private:
    //......
    vector<string> _lines;//O(1)
    unordered_map<string, unordered_multiset<int> > _wordNumbers;//the the
    unordered_map<string, int> _dict;// 底层哈希表
};

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
void dealLine(string& line){
    // shenzhen-Hongkong 应该拆分成两个单词，如果直接使用istringstream将一行内容拆分成
    // 单词再进行处理，可以用空格替代符号或数字
    for(auto& ch : line){
        if(!isalpha(ch)){
            ch = ' ';
        }else if(isupper(ch)){
            ch = tolower(ch);// 大写字母替换成小写
        }
    }
}
void TextQuery::readFile(const string & filename){
    ifstream ifs(filename);
    if(!ifs.good()){
        cerr << "ifstream open file failed" << endl; 
        exit(EXIT_FAILURE);
    }
    string line;
    int currLineNumber = 1;
    while(getline(ifs,line)){
        _lines.push_back(line);
        dealLine(line);
        istringstream iss(line);
        string word;
        while(iss >> word){
            //dealWord(word);
        //     set<int> s = {currLineNumber};
        //    // 记录单词和所在的行号
        //    pair<map<string, set <int> >::iterator,bool> ret1 = _wordNumbers.insert({word,s});
        //    if(ret1.second == 0){
        //        ret1.first->second.insert(currLineNumber);
        //    }
        // 利用map下标操作的特性，没有则插入value,默认值
           _wordNumbers[word].insert(currLineNumber);// 插入的是每个单词和出现的行号，如果一个单词在一行出现多次，会多次插入

           // 记录单词和出现的次数
        //    pair<map<string,int>::iterator,bool> ret2  =_dict.insert({word,1});
        //    if(ret2.second == 0){
        //        ++ret2.first->second;
        //    }
        // 利用map下标操作的特性
        //++_dict[word];

        }
        ++currLineNumber;
    }
}

void TextQuery::query(const string & word){
    // 在dict中打印次数
    // map<string,int>::iterator res1 = _dict.find(word);
    // if(res1 == _dict.end()){
    //     cout << "要找的词不存在！"  << endl;
    //     return;
    // }
    int count = _dict[word];
    cout << "------------------------------------------------------" << endl;
    cout << word << " occurs " << count << 
    (count > 1 ? "times" : "time") << endl;

    // 在wordNumbers中查找行号
    unordered_map<string,unordered_multiset<int>>::iterator res2 = _wordNumbers.find(word);
    if(res2 == _wordNumbers.end()){
        cout << "要找的词不存在！"  << endl;
        return;
    }
    
    // 根据行号打印
    for(auto& lineNumber: res2->second){
        
        cout <<"(line " << lineNumber << ") " <<  _lines[lineNumber - 1] << endl;
        
    }
    cout << "------------------------------------------------------" << endl;
}
//程序测试用例
int main(int argc, char *argv[])
{
    cout << "请选择要查询的文本:" ;
    string queryText;
    cin >> queryText;
    cout.flush();
    // 先初始化vector的容量为150，防止vector反复扩容,耗费性能
    TextQuery tq(150);
    tq.readFile(queryText);

    cout << "请输入要查询的单词:" ;
    cout.flush();
    string queryWord;
    cin >> queryWord;
    tq.query(queryWord);
    return 0;
}
