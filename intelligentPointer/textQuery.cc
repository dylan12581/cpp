#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>



using std::cout;
using std::endl;
using std::cerr;
using std::cin;
using std::string;
using std::vector;
using std::set;
using std::map;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::shared_ptr;

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
class QueryResult;
 class TextQuery
 {
 public:
     TextQuery(int capacity)
         :_lines(new vector<string> ())
          ,_word2Numbers()
          ,_dict()
     {
         _lines->reserve(capacity);
     }
     void readFile(const string filename){
         ifstream ifs(filename);
         if(!ifs){
             cerr << "open file failed" << endl; 
             return;
         }
         string line;
         int currLineNumber = 1;
         while(getline(ifs,line)){
             _lines->push_back(line);
             dealLine(line);
             istringstream iss(line);
             string word;
             while(iss >> word){
                 // if  
                 if(_word2Numbers[word] == nullptr){
                     _word2Numbers[word].reset(new set<int>());
                 } 
                 _word2Numbers[word]->insert(currLineNumber);
                 ++_dict[word];
             }
             ++currLineNumber;
         }
     }
     QueryResult query(const string &word);
 private:
     //......
     shared_ptr<vector<string>> _lines; 
     map<string, shared_ptr<set<int>> > _word2Numbers;
     map<string,int> _dict;
 };

class QueryResult{
public:
    friend
    void print(ostream & os, const QueryResult &);
    QueryResult(string queryWord,shared_ptr<vector<string>> lines,shared_ptr<set<int>> wordNumbers,int times)
        :_queryWord(queryWord)
         ,_lines(lines)
         ,_wordNumbers(wordNumbers)
         ,_times(times)
    {
    }
private:
    string _queryWord;
    shared_ptr<vector<string>> _lines;
    shared_ptr<set<int>> _wordNumbers;
    int _times;
};
QueryResult TextQuery::query(const string &word){
    map<string,shared_ptr<set<int>>>::iterator it = _word2Numbers.find(word);
    if(it == _word2Numbers.end()){
        static shared_ptr<set<int>> nodata(new set<int>());
        return QueryResult(word,_lines,nodata,_dict[word]);// 返回空set
    }else{
        return QueryResult(word,_lines,it->second,_dict[word]);
    }
}
void print(ostream & os, const QueryResult & result){

       int count = result._times;
       os << "------------------------------------------------------" << endl;
       os << result._queryWord << " occurs " << count <<
       (count > 1 ? "times" : "time") << endl;
  
       // 根据行号打印
       for(auto& lineNumber: *result._wordNumbers){
           os <<"(line " << lineNumber << ") " <<  (*result._lines)[lineNumber - 1] << endl;
       }
       os << "------------------------------------------------------" << endl;
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
       print(cout,tq.query(queryWord));
       return 0;

    return 0;
 } 

