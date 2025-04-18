#include "TcpServer.h"


TcpServer:: TcpServer(const string& ip,unsigned short port)
    :_acceptor(ip,port),_epollEvent(_acceptor)
{}

TcpServer::~TcpServer(){};

void TcpServer::start(){
    _acceptor.ready();
    _epollEvent.loop();
}

void TcpServer::stop(){
    _epollEvent.unloop();
}

void TcpServer::setAllCallBack(TcpConnectionCallBack&& newCb,TcpConnectionCallBack&& closeCb,TcpConnectionCallBack&& MessageCb){
    _epollEvent.setNewConnCb(std::move(newCb));
    _epollEvent.setCloseConnCb(std::move(closeCb));
    _epollEvent.setMessageConnCb(std::move(MessageCb));
}


