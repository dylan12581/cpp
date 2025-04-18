#ifndef _AND_QUERY_H_
#define _AND_QUERY_H_

#include "binaryQuery.hh"
#include <algorithm>
#include <iterator>

using std::inserter;
using std::set_intersection;

class andQuery
    : public binaryQuery
{
    friend Query operator&(const Query &lhs, const Query &rhs);

    andQuery(const Query &lhs, const Query &rhs)
        : binaryQuery(lhs, rhs, "&")
    {
    }
    QueryResult eval(TextQuery &t) const;
    string repl() const;
};
QueryResult andQuery::eval(TextQuery &t) const
{
    QueryResult lhsResult = _lhs.eval(t);
    QueryResult rhsResult = _rhs.eval(t);

    shared_ptr<set<size_t>> retLines(new set<size_t>());
    // 取交集
    set_intersection(lhsResult.begin(), lhsResult.end(),
                     rhsResult.begin(), rhsResult.end(),
                     inserter(*retLines, retLines->begin()));

    return QueryResult(repl(), t._file, retLines, lhsResult._times + rhsResult._times);
}

#endif