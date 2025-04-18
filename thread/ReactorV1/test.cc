#include <iostream>
#include "Socket.h"
#include "InetAddress.h"
#include "acceptor.h"
#include "SocketIO.h"
#include "TcpConnection.h"

using std::cout;
using std::endl;


void test0()
{
    acceptor server("192.168.182.128",8080);
    server.ready();
    TcpConnection conn(server.accept());
    cout << "server is listening..." << endl;
    cout << conn.toString() << endl;
    while(1){

        cout << "recv client msg : " << conn.receive() << endl;
        conn.send("hello");
        //conn.send(msg);
    }
}

int main()
{
    test0();
    return 0;
}

