#include "redis.h"
#include <memory>

using std::unique_ptr;

void test()
{
    unique_ptr<Redis> pRedis(new Redis());

    if(!pRedis->connect("127.0.0.1", 6379))
    {
        std::cerr << "connect error!" << endl;
        return;
    }

    /* pRedis->set("name", "lili"); */
    pRedis->set("name", "哩哩");
    std::cerr << "18\n";
    cout << "Get the name is " << pRedis->get("name") << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

