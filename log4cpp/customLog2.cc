#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>

#include <iostream>

using std::cout;
using std::endl;
using namespace log4cpp;


void test0()
{
    // 设置布局
    PatternLayout* ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout* ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout* ptn3 = new PatternLayout();
    ptn3->setConversionPattern("%d %c [%p] %m%n");

    
    // 设置目的地，并绑定布局
    auto appender1 = new OstreamAppender("console",&cout);
    appender1->setLayout(ptn1);

    auto appender2 = new FileAppender("file","file.log");
    appender2->setLayout(ptn2);

    auto appender3 = new RollingFileAppender("rollingfile","rolling.log",5*1024,9);
    appender3->setLayout(ptn3);


    // 创建记录器
    Category& test = Category::getRoot().getInstance("test"); 
    // 设置优先级
    test.setPriority(Priority::WARN);
    // 绑定目的地
    test.addAppender(appender1);
    test.addAppender(appender2);
    test.addAppender(appender3);

    // 记录日志

       int count = 100;
    while(count > 0){
        test.emerg("this is an emerg msg");
        test.fatal("this is a fatal msg");
        test.alert("this is an alert msg");
        test.crit("this is a crit msg");
        test.error("this is an error msg");
        test.warn("this is a warn msg");
        test.notice("this is a notice msg");
        test.info("this is an info msg");
        test.debug("this is a debug msg");
        --count;
    }

    Category::shutdown();
    
}

int main()
{
    test0();
    return 0;
}

