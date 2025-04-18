/**
 * Project C++
 */
#include "SocketIO.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
using std::endl;
using std::cout;

/**
 * SocketIO implementation
 */


/**
 * @param fd
 */
SocketIO::SocketIO(int fd)
    :_connFd(fd)
{

}

SocketIO::~SocketIO() {
    close(_connFd);
}

/**
 * @param msg
 * @param n
 * @return size_t
 */
size_t SocketIO::writen(const char* msg, size_t n) {
    size_t left = n;
    const char* pstr = msg;
    while(left > 0){
        size_t ret = write(_connFd,pstr,left);
        if(ret < 0 && errno == EINTR){
            continue;
        }else if(ret < 0){
            perror("write");
            return -1;
        }else if(ret == 0){
            break;
        }else{
            pstr += ret;
            left -= ret;
        }
    }
    cout << msg << endl;
    return n - left;
}

/**
 * @param buff
 * @return size_t
 */
size_t SocketIO::getLine(char* buff) {
    size_t total = 0;
    size_t left = sizeof(buff);
    char* pstr = buff;

    while(left > 0){
        size_t ret = recv(_connFd,pstr,left,MSG_PEEK);
        //cout << "recv" << endl;
        if(ret < 0 && errno == EINTR){
            continue;
        }else if(ret < 0){
            perror("recv");
            return -1;
        }else if(ret == 0){
            break;
        }else{
            //cout << "else" << endl;
            //cout << ret << endl;
            for(size_t idx = 0;idx < ret;++idx){
                if(pstr[idx] == '\n'){
                    size_t sz = idx + 1;
                    total += sz;
                    left -= sz;
                    pstr[sz] = '\0';
                    readn(pstr,sz);
                    //cout << "85" << endl;
                    return total;
                }
            }
                //cout << "88" << endl;
                readn(pstr,ret);
                left -= ret;
                total += ret;
                pstr += ret;
 
        }
    }
    *pstr = '\0';
    //cout << pstr << endl;
    return total;
}

/**
 * @param buff
 * @param n
 * @return size_t
 */
size_t SocketIO::readn(char* buff, size_t n) {
    size_t left = n;
    char* pstr = buff;
   // cout << "readn" << left << endl;
    while(left > 0){
        
        size_t ret = read(_connFd,pstr,left);
        //cout << "readn" << ret << endl;
        if(ret < 0 && errno == EINTR){
            continue;
        }else if(ret < 0){
            perror("read");
        }else if(ret == 0){
            break;
        }else{
            pstr += ret;
            left -= n;
        }
    }
    //cout << "readn" << endl;
    return n - left;
}
