#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
using log4cpp::Appender;
using log4cpp::FileAppender;
using log4cpp::OstreamAppender;
using log4cpp::RollingFileAppender;
using log4cpp::PatternLayout;
using log4cpp::Category;
using log4cpp::Priority;


int main(int argc, char** argv) {
    
    
    PatternLayout* ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");


    PatternLayout* ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");


    PatternLayout* ptn3 = new PatternLayout();
    ptn3->setConversionPattern("%d %c [%p] %m%n");

    OstreamAppender* pos = new OstreamAppender("console",&std::cout);
    pos->setLayout(ptn1);

    FileAppender* filePos = new FileAppender("file","wd.log");
    filePos->setLayout(ptn2);

    RollingFileAppender* rfPos = new RollingFileAppender("rollingfile","rollingfile.log",5*1024,9);
    rfPos->setLayout(ptn3);


    Category & salesDepart = Category::getInstance("salesDepart");

    salesDepart.setPriority(Priority::ERROR);

    salesDepart.addAppender(pos);
    salesDepart.addAppender(filePos);
    salesDepart.addAppender(rfPos);
    
    int count = 100;
    while(count-- > 0){
        salesDepart.emerg("this is an emerg msg");
        salesDepart.fatal("this is an fatal msg");
        salesDepart.alert("this is an alert msg");
        salesDepart.crit("this is an crit msg");
        salesDepart.error("this is an error msg");
        salesDepart.warn("this is an warn msg");
        salesDepart.notice("this is an notice msg");
        salesDepart.info("this is a info msg");
    }

    Category::shutdown();

    return 0;
}
