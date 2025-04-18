/** * Project C++ */
#include "SocketIO.h"
#include "unistd.h"
#include <sys/types.h>
#include <sys/socket.h>


/**
 * SocketIO implementation
 */


/**
 * @param fd
 */
SocketIO::SocketIO(int fd)
    :_connFd(fd)
{}

SocketIO::~SocketIO() {
    close(_connFd); 
}

/**
 * @param buff
 * @param n
 * @return size_t
 */
size_t SocketIO::getLine(char* buff, size_t n) {
    size_t left = n;
    char* pstr = buff;
    size_t total = 0;
    while(left > 0){
        ssize_t ret = recv(_connFd,pstr,left,MSG_PEEK);
        if(ret < 0 && errno == EINTR){
            continue;
        }else if(ret == 0){
            std::cout << "recv = 0 in getLine" << std::endl;
            break;
        }else if(ret < 0){
            perror("recv");
            return -1;
        }else{
            for(int idx = 0;idx < ret;++idx){
                if(pstr[idx] == '\n'){
                    int sz = idx + 1;
                    pstr[sz] = '\0';
                    total += sz;
                    left -= sz;
                    readn(pstr,sz);
                    return total;
                }
            }
            readn(pstr,ret);
            total += ret;
            left -= ret;
        }
    }
    *pstr = '\0';
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
    while(left > 0){
        ssize_t ret = read(_connFd,pstr,n);
        if(ret < 0 && errno == EINTR){
            continue;
        }else if(ret == 0){
            break;
        }else if(ret < 0){
            perror("read");
            return -1;
        }else{
            pstr += ret;
            left -= ret;
        }
    }
    return n - left;
}

/**
 * @param buff
 * @param n
 * @return size_t
 */
size_t SocketIO::writen(const char* buff, size_t n) {
    size_t left = n;
    const char* pstr = buff;
    while(left > 0){
        ssize_t ret = write(_connFd,pstr,left);
        if(ret < 0 && errno == EINTR){
            continue;
        }else if(ret == 0){
            break;
        }else if(ret < 0){
            perror("write");
        }else {
            pstr += ret;
            left -= ret;
        }
    }
    return n - left;
}
