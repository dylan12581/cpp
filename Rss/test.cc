#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using namespace tinyxml2;

struct RssItem
{
  string title;
  string link;
  string description;
  string content;
};

class RssReader
{
public:
  RssReader()
  {
  }
  void parseRss() // 解析
  {
  }
  void dump(const string &filename); // 输出
private:
  vector<RssItem> _rss;
};

int example_1()
{
  XMLDocument doc;
  doc.LoadFile("resources/dream.xml");

  return doc.ErrorID();
}
/** @page Example_1 Load an XML File
 *  @dontinclude ./xmltest.cpp
 *  Basic XML file loading.
 *  The basic syntax to load an XML file from
 *  disk and check for an error. (ErrorID()
 *  will return 0 for no error.)
 *  @skip example_1()
 *  @until }
 */

int example_2()
{
  static const char *xml = "<element/>";
  XMLDocument doc;
  doc.Parse(xml);

  return doc.ErrorID();
}
/** @page Example_2 Parse an XML from char buffer
 *  @dontinclude ./xmltest.cpp
 *  Basic XML string parsing.
 *  The basic syntax to parse an XML for
 *  a char* and check for an error. (ErrorID()
 *  will return 0 for no error.)
 *  @skip example_2()
 *  @until }
 */

int example_3()
{
  static const char *xml =
      "<?xml version=\"1.0\"?>"
      "<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
      "<PLAY>"
      "<TITLE>A Midsummer Night's Dream</TITLE>"
      "</PLAY>";

  XMLDocument doc;
  doc.Parse(xml);

  XMLElement *titleElement = doc.FirstChildElement("PLAY")->FirstChildElement("TITLE");
  const char *title = titleElement->GetText();
  printf("Name of play (1): %s\n", title);

  XMLText *textNode = titleElement->FirstChild()->ToText();
  title = textNode->Value();
  printf("Name of play (2): %s\n", title);

  return doc.ErrorID();
}

bool example_4()
{
  static const char *xml =
      "<information>"
      "	<attributeApproach v='2' />"
      "	<textApproach>"
      "		<v>2</v>"
      "	</textApproach>"
      "</information>";

  XMLDocument doc;
  doc.Parse(xml);

  int v0 = 0;
  int v1 = 0;

  XMLElement *attributeApproachElement = doc.FirstChildElement()->FirstChildElement("attributeApproach");
  attributeApproachElement->QueryIntAttribute("v", &v0);

  XMLElement *textApproachElement = doc.FirstChildElement()->FirstChildElement("textApproach");
  textApproachElement->FirstChildElement("v")->QueryIntText(&v1);

  printf("Both values are the same: %d and %d\n", v0, v1);

  return !doc.Error() && (v0 == v1);
}

void test0()
{
  cout <<  example_4() << "\n";
}

int main()
{
  test0();
  return 0;
}
