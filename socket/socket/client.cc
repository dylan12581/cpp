#include <my_header.h>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(int argc,char** argv)
{
    int socketFd = socket(AF_INET,SOCK_STREAM,0);
    if(socketFd < 0){
        perror("socket failed");
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
    cout << "1" <<endl;

    int retConn = connect(socketFd,(struct sockaddr*)&sockaddr,sizeof(sockaddr));
    if(retConn < 0){
        perror("connect failed");
        close(socketFd);
        return -1;
    }

    while(1){
        string line;
        getline(std::cin,line);

        int retSend = send(socketFd,line.data(),line.size(),0);
        if(retSend <0){
            cout << "客户端发送出错" << endl;
        }else if(retSend == 0){
            cout << "0 == retSend" << endl;
        }else{
            cout << "客户端发送正常" << endl;
        }

        char buf[1024] = {0};
        int retRecv = recv(socketFd,buf,sizeof(buf),0);
        if(retRecv <0){
            cout <<"客户端接收失败" << endl;
        }else if(retRecv == 0){
            cout << "retRecv == 0" << endl;
        }else{
            cout <<"recv msg from server: " << buf << endl;
        }
    }
    close(socketFd);
    
    return 0;
}

