#include "WordQuery.hh"

WordQuery::WordQuery(const string &sought)
    : _queryWord(sought) {}
QueryResult WordQuery::eval(TextQuery &t) const
{
    return t.Query(_queryWord);
}
string WordQuery::repl() const
{
    return _queryWord;
}
