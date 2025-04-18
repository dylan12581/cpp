#pragma once
#include <pthread.h>
#include <iostream>
#include <string>
#include <sstream>
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <mutex>
#include <thread>
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using std::mutex;
using namespace::log4cpp;

#define addPrefix(msg) (string("[").append(__FILE__)\
        .append(":").append(__func__)\
        .append(":").append(std::to_string(__LINE__))\
        .append("]").append(msg).c_str())

#define LogWarn(pstr) myLogger::getInstance()->\
                            warn(addPrefix(pstr))

#define LogInfo(pstr) myLogger::getInstance()->\
                            info(addPrefix(pstr))

#define LogError(pstr) myLogger::getInstance()->\
                            error(addPrefix(pstr))

#define LogDebug(pstr) myLogger::getInstance()->\
                            debug(addPrefix(pstr))

class myLogger
{
public:
    void warn(const char* msg){
        std::lock_guard<mutex> lock(_mutex);
        _Catagory.warn(msg);
    }
    void info(const char* msg){
        std::lock_guard<mutex> lock(_mutex);
        _Catagory.info(msg);
    }
    void error(const char* msg){
        std::lock_guard<mutex> lock(_mutex);
        _Catagory.error(msg);
    }
    void debug(const char* msg){
        std::lock_guard<mutex> lock(_mutex);
        _Catagory.debug(msg);
    }

static myLogger* getInstance(){
        pthread_once(&_once,init_r);
        return _pInstance;
    };
private:
    static void init_r(){
        _pInstance = new myLogger();
        atexit(destroy);
    }
    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
    myLogger(Priority::PriorityLevel priority = Priority::PriorityLevel::DEBUG) 
        :_Catagory(Category::getRoot().getInstance("name"))//初始化列表进行严格初始化
       ,_priority(priority)
    {
        //1.设置布局
        PatternLayout* ptn1 = new PatternLayout();
        ptn1->setConversionPattern("%d %c [%p] %m%n");
        PatternLayout* ptn2 = new PatternLayout();
        ptn2->setConversionPattern("%d %c [%p] %m%n");

        //2文件目的地
        Appender* Oappender = new OstreamAppender("console",&cout);
        // 3 绑定布局
        Oappender->setLayout(ptn1);

        FileAppender* fileAppender = new FileAppender("file","05.log");
        fileAppender->setLayout(ptn2);

        // 4 创建日志记录器
        _Catagory.addAppender(Oappender);
        _Catagory.addAppender(fileAppender);

        _Catagory.setPriority(_priority);
        cout << "myLogger" << endl;
    }

    myLogger(const myLogger& rhs) = delete;
    myLogger& operator=(const myLogger& rhs) = delete;
    ~myLogger() {
        _Catagory.shutdown();
        cout << "~myLogger" << endl;
    }
private:
    Category& _Catagory;
    Priority::PriorityLevel _priority;
    static myLogger* _pInstance;
    static pthread_once_t _once;
    mutex _mutex;
};
myLogger* myLogger::_pInstance = nullptr;
pthread_once_t myLogger::_once = PTHREAD_ONCE_INIT;


