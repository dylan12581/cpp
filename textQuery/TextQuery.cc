#include "TextQuery.hh"

TextQuery::TextQuery(ifstream &ifs)
    : _file(new vector<string>())
{
    string line;
    int currLineNumber = 1;
    while (getline(ifs, line))
    {
        _file->push_back(line);
        dealLine(line);
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            if (_wms[word] == nullptr)
            {
                _wms[word].reset(new set<size_t>());
            }
            _wms[word]->insert(currLineNumber);
            ++_dicts[word];
        }
        ++currLineNumber;
    }
}

QueryResult TextQuery::Query(const string &sought)
{
    // map<string,shared_ptr<set<size_t>>>::iterator it = _wms.find(sought);
    auto it = _wms.find(sought);
    if (it == _wms.end())
    {
        static shared_ptr<set<size_t>> noData(new set<size_t>());
        return QueryResult(sought, _file, noData, _dicts[sought]);
    }
    return QueryResult(sought, _file, it->second, _dicts[sought]);
}

void dealLine(string &line)
{
    // shenzhen-Hongkong 应该拆分成两个单词，如果直接使用istringstream将一行内容拆分成
    // 单词再进行处理，可以用空格替代符号或数字
    for (auto &ch : line)
    {
        if (!isalpha(ch))
        {
            ch = ' ';
        }
        else if (isupper(ch))
        {
            ch = tolower(ch); // 大写字母替换成小写
        }
    }
}

// 获取文件内容
TextQuery get_file(const string &fileName)
{
    ifstream ifs(fileName);
    if (!ifs)
    {
        cerr << "open file failed" << endl;
        exit(EXIT_FAILURE);
    }
    return TextQuery(ifs);
}