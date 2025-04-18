#include <iostream>
#include <fstream>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/RollingFileAppender.hh>


using std::cout;
using std::endl;
using namespace log4cpp;


void test0()
{
      //1.设置布局
    PatternLayout* ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout* ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout* ptn3 = new PatternLayout();
    ptn3->setConversionPattern("%d %c [%p] %m%n");

    // 输出目的地
    Appender* appender1 = new OstreamAppender("console",&std::cout);
    appender1->setLayout(ptn1);

    Appender* appender2 = new FileAppender("default","03.log",true);
    appender2->setLayout(ptn2);

    RollingFileAppender* appender3 = new RollingFileAppender(
                                                             "03_rollingfile","03_rolling log",
                                                             5 * 1024,9
                                                            );
    appender3->setLayout(ptn3);

    // 日志记录器
    Category& salesDepart = Category::getRoot().getInstance("salesDepart");

    salesDepart.setPriority(Priority::WARN);
    // 绑定目的地
    salesDepart.addAppender(appender1);
    salesDepart.addAppender(appender2);
    salesDepart.addAppender(appender3);

    int count = 100;
    while(count > 0){
        salesDepart.emerg("this is an emerg msg");
        salesDepart.fatal("this is a fatal msg");
        salesDepart.alert("this is an alert msg");
        salesDepart.crit("this is a crit msg");
        salesDepart.error("this is an error msg");
        salesDepart.warn("this is a warn msg");
        salesDepart.notice("this is a notice msg");
        salesDepart.info("this is an info msg");
        salesDepart.debug("this is a debug msg");
        --count;
    }
    //7.确保妥善地进行了内存回收
    Category::shutdown();
}

int main()
{
    test0();
    return 0;
}

