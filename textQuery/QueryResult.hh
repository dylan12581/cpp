#ifndef _QUERYRESULT_H_
#define _QUERYRESULT_H_

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include <map>

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

class QueryResult
{
public:
    QueryResult(const string &sought, shared_ptr<vector<string>> lines, shared_ptr<set<size_t>> wms, size_t times);

    friend void print(ostream &os, const QueryResult &result);

private:
    string _queryWord;
    shared_ptr<vector<string>> _lines;
    shared_ptr<set<size_t>> _wms;
    size_t _times;
};

#endif