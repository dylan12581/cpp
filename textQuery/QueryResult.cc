#include "QueryResult.hh"

QueryResult::QueryResult(const string &sought, shared_ptr<vector<string>> lines, shared_ptr<set<size_t>> wms, size_t times)
    : _queryWord(sought), _lines(lines), _wms(wms), _times(times)
{
}

void print(ostream &os, const QueryResult &result)
{

    int count = result._times;
    os << "------------------------------------------------------" << endl;
    os << result._queryWord << " occurs " << count << (count > 1 ? "times" : "time") << endl;

    // 根据行号打印
    for (auto &lineNumber : *result._wms)
    {
        os << "(line " << lineNumber << ") " << (*result._lines)[lineNumber - 1] << endl;
    }
    os << "------------------------------------------------------" << endl;
}
