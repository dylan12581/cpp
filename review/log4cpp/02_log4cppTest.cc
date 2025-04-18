#include <iostream>
#include <fstream>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;
using namespace log4cpp;

void test0()
{
    // 输出目的地
    Appender* appender1 = new OstreamAppender("console",&std::cout);
    // 布局
    appender1->setLayout(new BasicLayout());

    Appender* appender2 = new FileAppender("default","02.log",true);
    appender2->setLayout(new BasicLayout());

    std::ofstream ofs("02.log1",std::ios_base::out | std::ios_base::app);
    auto appender3 = new OstreamAppender("file",&ofs);
    appender3->setLayout(new BasicLayout());

    // 日志记录器
    Category& root = Category::getRoot();

    root.setPriority(Priority::WARN);
    root.addAppender(appender1);

    Category& sub1 = Category::getInstance("sub1");
    sub1.setPriority(Priority::DEBUG);
    sub1.setAppender(appender3);
    sub1.setAdditivity(false);

    Category & sub11 = Category::getInstance("sub1.sub11");
    sub11.error("sub11 error");
    sub11.emerg("sub11 emerg");

    Category & sub2 = Category::getRoot().getInstance("sub2");
    sub2.error("sub2 error");
    sub2.emerg("sub2 emerg");

    root.warn("%d + %d == %s ?", 1, 1, "two");
 
    root.error("root error");
    root.info("root info");
    sub1.error("sub1 error");
	sub1.warn("sub1 warn");
	sub1.info("sub1 info");

    root << Priority::ERROR << "Streamed root error";
    root << Priority::INFO << "Streamed root info";
   	sub1 << Priority::ERROR << "Streamed sub1 error";
	sub1 << Priority::WARN << "Streamed sub1 warn";
}

int main()
{
    test0();
    return 0;
}

