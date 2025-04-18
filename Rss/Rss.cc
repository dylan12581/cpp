#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include "tinyxml2.h"

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::regex;
using std::ofstream;
using namespace tinyxml2;

struct RssItem
{
    string _title;
    string _link;
    string _description;
    string _content;
};

class RssReader
{
public:
    RssReader(int capacity){
        _rss.reserve(capacity);// 先分配多少空间
    }
    void parseRss(const string& filename)//解析
    {
        // 打开xml文件
        XMLDocument doc;
        doc.LoadFile(filename.c_str());
        if(doc.ErrorID()){
            cerr << "LoadFile failed" << endl;
            return ;
        }
        // 开始进行解析
        XMLElement* itemNode = doc.FirstChildElement("rss")->FirstChildElement("channel")->FirstChildElement("item");

        while(itemNode){
            string title = itemNode->FirstChildElement("title")->GetText();
            string link = itemNode->FirstChildElement("link")->GetText();
            string description = itemNode->FirstChildElement("description")->GetText();
            string content = itemNode->FirstChildElement("content:encoded")->GetText();

            // 去除标签
            regex reg("<[^>]+>");
            description = regex_replace(description,reg,"");
            content = regex_replace(content,reg,"");

            // 存入vector
            RssItem rss;
            rss._title = title;
            rss._link = link;
            rss._description = description;
            rss._content = content;
            _rss.push_back(rss);
            // 寻找下一篇的item
            itemNode = itemNode->NextSiblingElement("item");
        }
    }
    void dump(const string & filename)//输出
    {
        ofstream ofs(filename);
        if(!ofs){
            cerr << "ofs filename failed" << endl;
            return;
        }
        // 将vector中的元素输出到文件中
        for(size_t idx = 0; idx < _rss.size() ;++idx){
            ofs << "<doc>\n\t<docid>" << idx + 1
                << "</docid>\n\t<title>" << _rss[idx]._title 
                << "</title>\n\t<link>" << _rss[idx]._link 
                << "</link>\n\t<description>" << _rss[idx]._description
                << "</description>\n\t<content>" << _rss[idx]._content << "</content>\n</doc>";
            ofs << '\n';
        }


    }
private:
    vector<RssItem> _rss;
}; 
void test0()
{
    RssReader rss(20);
    rss.parseRss("coolshell.xml");
    rss.dump("pagelib.dat");
}

int main()
{
    test0();
    return 0;
}

