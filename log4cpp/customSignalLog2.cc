#include <iostream>

#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PropertyConfigurator.hh>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using namespace log4cpp;


#define LogWarn(msg) Mylogger::getInstance()->warn(msg , __FILE__ , __FUNCTION__ ,__LINE__)
#define LogError(msg) Mylogger::getInstance()->error(msg , __FILE__ , __FUNCTION__ ,__LINE__)
#define LogInfo(msg) Mylogger::getInstance()->info(msg , __FILE__ , __FUNCTION__ ,__LINE__)
#define LogDebug(msg) Mylogger::getInstance()->debug(msg , __FILE__ , __FUNCTION__ ,__LINE__)
class Mylogger
{
public:

    static Mylogger* getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Mylogger();
        }
        return _pInstance;
    }
        static void destroy(){
        if(_pInstance){
            delete _pInstance;
            Category::shutdown();// 放在这对吗？？？？？
            _pInstance = nullptr;
        }
    }

    void warn(const char *msg,const char* fileName,const char* funcName,int line){
        _log.warn(string(fileName) + " : "  + funcName + " : " +  to_string(line) + " : " + msg ) ;
    }
    void error(const char *msg,const char* fileName,const char* funcName,int line){
        _log.error(string(fileName) + " : "  + funcName + " : " +  to_string(line) + " : " + msg ) ;
    }
     void info(const char *msg,const char* fileName,const char* funcName,int line){
        _log.info(string(fileName) + " : "  + funcName + " : " +  to_string(line) + " : " + msg ) ;
    }
     void debug(const char *msg,const char* fileName,const char* funcName,int line){
        _log.debug(string(fileName) + " : "  + funcName + " : " +  to_string(line) + " : " + msg ) ;
    }

private:
    Mylogger( )
        :_log(Category::getRoot())
    {
        string initFileName = "log4cpp.properties";
        PropertyConfigurator::configure(initFileName);
    }
    ~Mylogger(){};

private:
    Category & _log;
    static Mylogger* _pInstance;
};
Mylogger* Mylogger::_pInstance = nullptr;


void test0()
{
    //第一步，完成单例模式的写法
    Mylogger *log = Mylogger::getInstance();

    log->warn("The log is info message", __FILE__ , __FUNCTION__ ,__LINE__);
    log->info("The log is info message", __FILE__ , __FUNCTION__ ,__LINE__);
    log->error("The log is info message", __FILE__ , __FUNCTION__ ,__LINE__);
    log->debug("The log is info message", __FILE__ , __FUNCTION__ ,__LINE__);

   
    
}
void test1()
{
    LogWarn("The log is info message");
    LogError("The log is error message");
    LogWarn("The log is warn message");
    LogDebug("The log is debug message");
}
int main(){

    test0();
    test1();
    Mylogger::destroy();

    return 0;
}

