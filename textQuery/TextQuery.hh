#ifndef _TextQuery_H_
#define _TextQuery_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <memory>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::map;
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

#include "QueryResult.hh"

class TextQuery
{
    friend class QueryResult;

public:
    TextQuery(ifstream &ifs);
    QueryResult Query(const string &sought);

private:
    shared_ptr<vector<string>> _file;
    map<string, shared_ptr<set<size_t>>> _wms;
    map<string, size_t> _dicts;
};

void dealLine(string &line);

// 获取文件内容
TextQuery get_file(const string &fileName);

#endif
