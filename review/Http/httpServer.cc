#include "httpServer.h"
#include <iostream>

#include <string.h>

using std::cout;
using std::endl;

void httpServer::start(){
    _fd = socket(AF_INET,SOCK_STREAM,0);
    if(_fd < 0){
        perror("socket");
        return;
    }
    int on = 1;
    int ret = setsockopt(_fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
    if(ret  < 0){
        perror("setsockopt");
        return;
    }
    struct sockaddr_in serverAddr;
    memset(&serverAddr,0,sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(_ip.c_str());
    serverAddr.sin_port = htons(_port);

    ret = bind(_fd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
    if(ret < 0){
        perror("bind");
        return;
    }
    ret = listen(_fd,10);
    if(ret < 0){
        perror("listen");
        return;
    }
}

void httpServer::recvAndShow(){
    while(true){
        int netFd = accept(_fd,nullptr,nullptr);
        char buf[1024] = {0};
        int ret = recv(netFd,buf,sizeof(buf),0);
        printf("ret:%d\n recv:%s\n",ret,buf);
        //handleRequest(netFd);
        string msg = response();
        printf("\r\n%s\n",msg.c_str());
        ret = send(netFd,msg.c_str(),msg.size(),0);
        close(netFd);
    }
}

string httpServer::response(){
    string startLine = "HTTP/1.1 200 OK\r\n";
    string headers = "Server: MyHttpServer\r\n";
    string body("<html><body>hello, client</body></html>");
    headers += "Content-Type: text/html\r\n";
    headers += "Content-Legnth: " + std::to_string(body.size()) + "\r\n";
    string emptyLine("\r\n");
    return startLine + headers + emptyLine + body;

}

#if 0// POST请求 
void httpServer::handleRequest(int netfd){
    // 打印客户端发出的请求
    char buf[4096];
    ssize_t sret = recv(netfd, buf, 4096, 0);
    buf[sret] = '\0';
    printf("Received HTTP request:\n%s\n", buf);
    printf("-------------------------\n");

    // 构建回复的内容
    char head[] = "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n";
    char response[8192] = {0};
    /// 读文件
    int fd = open("login.html",O_RDONLY);
    bzero(buf,sizeof(buf));
    sret = read(fd,buf,sizeof(buf));
    sprintf(response,"%sContent-Length:%ld\r\n\r\n%s",head,sret, buf);
    //发送响应
    send(netfd, response, strlen(response),0);
}
#endif

void test0(){
    httpServer server("0.0.0.0",8080);
    server.start();
    server.recvAndShow();
}

int main(){
    test0();
    return 0;
}

