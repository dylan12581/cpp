#include <my_header.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


int main(int argc,char** argv)
{
    int sockFd = socket(AF_INET,SOCK_STREAM,0);
    if(sockFd < 0){
        perror("sockFd failed");
        return -1;
    }

    string ip( "192.168.182.128");
    //const char* ip = "127.0.0.1";
    string port( "8080");

    sockaddr_in sockaddr;
    memset(&sockaddr,0,sizeof(sockaddr));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = inet_addr(ip.c_str());
    sockaddr.sin_port = htons(atoi(port.c_str()));

    int opt = 1;
    int retval = setsockopt(sockFd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    if(retval < 0){
        perror("setsockopt addr failed");
        close(sockFd);
        return -1;
    }
    retval = setsockopt(sockFd,SOL_SOCKET,SO_REUSEPORT,&opt,sizeof(opt));
    if(retval < 0){
        perror("setsockopt port failed");
        close(sockFd);
        return -1;
    }
    int retBind = bind(sockFd,(struct sockaddr*)&sockaddr,sizeof(sockaddr));
    if(retBind < 0){
        perror("bind");
        close(sockFd);
        return -1;
    }

    int retListen = listen(sockFd,128);
    if(retListen < 0){
        perror("listen");
        close(sockFd);
        return -1;
    }

    cout << "server is listening..." << endl;

    struct sockaddr_in clientaddr;
    int len = sizeof(clientaddr);
    int connFd = accept(sockFd,(struct sockaddr*)&clientaddr,(socklen_t*)(&len));
    if(connFd < 0){
        perror("accept");
        close(sockFd);
        return -1;
    }
    cout << "client ip: " << inet_ntoa(clientaddr.sin_addr) << endl;
    cout << "client port:" << ntohs(clientaddr.sin_port) << endl;



    while(1){
        char buf[1024] = {0};
        int retRecv = recv(connFd,buf,sizeof(buf),0);
        if(retRecv < 0){
            perror("服务器接收数据失败");
            close(sockFd);
            return -1;
        }else if(retRecv == 0){
            cout << "retRecv == 0 " << endl;
        }else{
            cout << "recv msg from client : " << buf << endl;
        }

        cout << "我服务器想发送数据给客户端 " << endl;
        string line;
        getline(std::cin,line);
        int retSend = send(connFd,line.data(),line.size(),0);
        if(retSend < 0){
            cout << "服务器发送数据出错" << endl;
        }else if(retSend == 0){
            cout << "retSend == 0" << endl;
        }else{
            cout << "服务器发送数据正常" << endl;
        }
    }
    close(connFd);
    close(sockFd);
    
    return 0;
}

