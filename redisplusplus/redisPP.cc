#include <sw/redis++/redis++.h>
#include <iostream>

using namespace sw::redis;
using namespace std;

void test0()
{
    auto redis = Redis("tcp://127.0.0.1:6379");

    redis.set("key","val");
    auto val = redis.get("key");
    if(val){
        std::cout << *val << std::endl;
    }

    std::vector<std::string> vec = {"a","b","c"};
    redis.rpush("list",vec.begin(),vec.end());
    redis.rpush("list",{"a","b","c"});

    vec.clear();
    redis.lrange("list",0,-1,std::back_inserter(vec));
    for(auto& ele:vec){
        std::cout << ele << " ";
    }
    std::cout << "\n";
}

int main()
{
    test0();
    return 0;
}

