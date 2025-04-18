#include <string.h>
#include <math.h>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <functional>
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::map;
using std::unordered_map;
using std::istringstream;
using std::make_pair;
using std::pair;
using std::ifstream;

void test0(){
    // string str = "aaabbb";
    // size_t pos = str.find_first_of("=");
    // if(pos == string::npos){
    //     return ;
    // }
    // cout << pos << "\n";
    // string key = str.substr(0,pos);
    // string val = str.substr(pos + 1);
    // cout << key << "\n";
    // cout << val << "\n";

    string word;
    int val;
    istringstream iss("sss 1");
    iss >> word >> val;
    cout << word << val + 1; 

    // for(auto& ele:index){
    //     cout << ele.first ;
    //     for(auto& num:ele.second){
    //         cout << num << "\n";
    //     }
    // }
}
void test1(){
    if(nullptr){
        cout << "find\n";
    }
}
void test2(){
    string line("1 0 1234");
    size_t a,b,c;
    istringstream iss(line);
    iss >> a >> b >> c;
    cout << a << b << c << "\n";
}
void test3(){
    unordered_map<size_t,pair<size_t,size_t>> map;
    map[123] = make_pair<size_t,size_t>(123,123);
}
void test5(){
    double res = pow(1.2,2);
    cout << res << "\n";
    double res2 = sqrt(res);
    cout << res2 << "\n";
    double res3 = log2(4);
    cout << res3 << "\n";
}

void test6(){
    string str = "据新闻报道，近日有网友发现自己手机上安装的很多APP存在频繁自启动，访问、读取手机信息的现象。其中一款移动教学软件十几分钟访问手机照片和文件近两万五千次；另一款办公软件一小时内尝试自启动近7000次。  　　手机APP窃取隐私或过度收集用户信息现象，早已不是新问题。在智能手机已经成为人们工作生活必须品的背景下，人们对智能手机的深度依赖决定着其已成为人们的随身物品。工作开会时携带手机，居家旅游时携带手机，甚至休息时也将手机放到床头。那么，一旦一些APP无视用户权益，随意窥探、收集用户隐私的话，消费者将毫无隐私和安全感而言，沦为被随意窥视隐私的“裸奔者”。由此，本来是提高生活品质和便利度的智能手机就完全可能沦为被操纵的“肉鸡”。人们完全有理由担心工作生活中的私密聊天内容会被偷偷地录制、窃取，睡觉休息时的画面会被录制、传播，手机相册中的照片会被上传，扩散。要知道，这些隐私更直观、更私密、更具有画面感，泄露的后果也更严重。  　　对很多人来说，失窃几千元的后果未必大，而一旦手机中的隐私被窃取的话，则可能带来严重的精神伤害和心理折磨。利用先进技术窃取用户隐私的行为，让弱势的用户毫无招架之力，只能任其摆布，除非其舍弃智能手机，返回到“老年机”时代。  　　当作恶的APP比现实中的窃贼更可怕、更难以防范的时候，就不能仅靠弱势的消费者来抵制，更不能靠唯利是图的APP开发者、运营者良心发现。根据有关规定，APP未向用户明示并经同意，不得开启收集地理位置、读取通讯录、使用摄像头、启用录音等功能，不得开启与服务无关的功能，否则将会被下架。根据网络安全法，侵犯个人信息的，最高可处100万元罚款，并可责令停业整顿，关闭网站，吊销证照。根据刑法及司法解释，非法获取行踪轨迹、通信内容等信息50条以上的，或者其他信息5000条以上的，就可能构成侵犯公民个人信息罪。  　　在信息时代，守护公民隐私的重要意义不亚于守护公民的财产安全。监管部门和执法机关理当积极作为，科学应对，妥善处置。如推行强制标准和事先审查制度，不符合保护隐私标准不得面市。强化监测力度，及时下架、屏蔽违规APP，追究开发者和应用商店的行政责任乃至刑事责任。";
    
    for(auto it = str.begin();it!= str.end();){
        if(*it == '\r' || *it == '\n' || *it == ' '|| *it == '　　'){
            it = str.erase(it);
        }else{
            ++it;
        }
    }
    cout << str ;
}
void test7(){
    string str = "<title>手机APP窃取隐私 不容漠视</title>     ";
    size_t a = str.find("<title>");
    size_t b = str.find("</title>");
    cout << a << " " << b << "\n";
    string newstr = str.substr(a + 7,b - a - 7);
    size_t c,d;
    if( (c = str.find("<des>"))!=string::npos){
        d = str.find("</des>");
        newstr += str.substr(c + 5,d - c -5);
    }
    cout << newstr <<  "\n";

}
void test8(){
    string str = "";
    string str1 = "123";
    cout << str << str1;
}
void test9(){

    map<string,set<pair<int,double>>> s;
    s["中国"].insert({1,2});
    s["中国"].insert({1,3});
    for(auto& ele:s["中国"]){
        cout << ele.first << ele.second;
    }
}
void test10(){
    char* pc = new char[10]();
    memset(pc,'1',10);
    string p(pc);
    cout << "p=" <<  p << "=" << endl; 
    delete []pc;
    cout << "p=" <<  p << "=" << endl; 
    cout << "p=" <<  p << "=" << endl; 
}
void test11(){
    ifstream ifs("/home/shy/searchEngine/data/newWebPage.dat");
    if(!ifs){
        cout << "ifs newWebPage.dat\n";
        return ;
    }

    ifs.seekg(8584,std::ios::beg);
    char* pc = new char[4289]();
    ifs.read(pc,4289);
    string c(pc);
    cout << c ;
}
int main()
{
    test11();
    return 0;
}

