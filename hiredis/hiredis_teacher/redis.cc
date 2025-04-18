#include "redis.h"

Redis::Redis()
: _pConnect(nullptr)
, _pReply(nullptr)
{
    cout << "Redis()" << endl;
}

Redis::~Redis()
{
    cout << "~Redis()" << endl;

    if(_pConnect)
    {
        redisFree(_pConnect);
        _pConnect = nullptr;
    }
    
    if(_pReply)
    {
        freeReplyObject(_pReply);
        _pReply = nullptr;                
    }
}

bool Redis::connect(const string &host, int port)
{
    _pConnect = redisConnect(host.c_str(), port);
    if(_pConnect == nullptr)
    {
        return false;
    }

    if(_pConnect != nullptr && _pConnect->err)
    {
        std::cerr << "connect error : " << _pConnect->errstr << endl;
        return false;
    }

    return true;
}

void Redis::set(string key, string value)
{
   _pReply = (redisReply *)redisCommand(_pConnect, "SET %s %s", key.c_str(), value.c_str());
   if(_pReply)
   {
       freeReplyObject(_pReply);
       _pReply = nullptr;
   }
}

string Redis::get(string key)
{
    std::cerr << "56\n";
    _pReply = (redisReply *)redisCommand(_pConnect, "GET %s", key.c_str());
    std::cerr << "58\n";
    if(_pReply)
    {
        if(_pReply->type == REDIS_REPLY_STRING)
        {
            std::cerr << "63\n";
            string str = _pReply->str; 
            freeReplyObject(_pReply);
            _pReply = nullptr;
            
            return str;
        }
        else
        {
            std::cerr << "73\n";
            return nullptr;
        }
    }
    else
    {
        std::cerr << "79\n";
        return nullptr;
    }
}

