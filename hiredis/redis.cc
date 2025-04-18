#include "redis.h"
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

redis::redis()
    : _pConnect(nullptr), _pReply(nullptr)
{
    cout << "redis()" << endl;
}
redis::~redis()
{
    if (_pConnect)
    {
        redisFree(_pConnect);
        _pConnect = nullptr;
    }
    if (_pReply)
    {
        freeReplyObject(_pReply);
        _pReply = nullptr;
    }
    cout << "~redis()" << endl;
}
bool redis::connect(const string &host, int port)
{
    _pConnect = redisConnect(host.c_str(), port);
    if (_pConnect == nullptr)
    {
        cerr << "Connection error: can't allocate redis context" << endl;
        return false;
    }
    if (_pConnect->err)
    {
        cerr << "connect error : " << _pConnect->errstr << endl;
        redisFree(_pConnect);
        return false;
    } // 不为空的情况
    return true;
}
void redis::set(string key, string value)
{
    _pReply = (redisReply *)redisCommand(_pConnect, "SET %s %s", key.c_str(), value.c_str());
    if (_pReply)
    {
        if (_pReply->type == REDIS_REPLY_ERROR)
        {
            cerr << _pReply->str << endl;
        }
        freeReplyObject(_pReply); // 释放内存，防止内存泄漏
        _pReply = nullptr;
    }
}
string redis::get(string key)
{
    _pReply = (redisReply *)redisCommand(_pConnect, "GET %s", key.c_str());
    if (_pReply)
    {
        string result;
        if (_pReply->type == REDIS_REPLY_STRING)
        {
            result = _pReply->str;
        }
        freeReplyObject(_pReply);
        _pReply = nullptr;
        return result;
    }
    else
    {
        cerr << "Failed to execute GET command." << endl;
        return "";
    }
}
