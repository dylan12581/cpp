#include "TcpConnection.h"
#include "Acceptor.h"
#include "EpollEvent.h"
#include "Socket.h"
#include "SocketIO.h"
#include "InetAddress.h"
#include "EpollEvent.h"

void test0()
{
    Acceptor acceptor("192.168.182.128",8080);
    acceptor.ready();
    EpollEvent epoll(acceptor);
    epoll.loop();
}

int main()
{
    test0();
    return 0;
}

