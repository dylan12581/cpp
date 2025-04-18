#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::unordered_map;

class WordConvert{
public:
    void readRules(const string & ruleFile);
    void convert(const string& convFile);

private:
    unordered_map<string,string> _rules;
};
void WordConvert::readRules(const string & ruleFile){
    ifstream ifs(ruleFile);
    if(!ifs){
        throw "open ruleFile failed";
    }
    // brb be right back的情况出现
    string key;
    string value;
    while(ifs >> key,getline(ifs,value)){
        // 得到的value值前面会有一个空格,利用substr取出前面的空格
        value = value.substr(1);
        _rules[key]  = value;
    }
}
void WordConvert::convert(const string & convFile){
    ifstream ifs(convFile);
    if(!ifs){
        throw "open convFile failed";
    }
    string line;
    string word;
    ofstream ofs(string("newfile"));
    while(getline(ifs,line)){
        istringstream iss(line);
        while(iss >> word){
            if(_rules.count(word)){
                word = _rules[word];
            }
            ofs << word << " ";
        }
        ofs << endl;
    }
    ofs.close();
}

int main()
{
    WordConvert wc;
    wc.readRules("map.txt");
    wc.convert("file.txt");

    return 0;
}

