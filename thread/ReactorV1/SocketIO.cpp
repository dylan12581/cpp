/**
 * Project C++
 */
#include "SocketIO.h"
#include "unistd.h"
#include <iostream>
using std::cout;
using std::endl;

/**
 * SocketIO implementation
 */


/**
 * @param fd
 * @param n
 * @return size_t
 */
SocketIO::SocketIO(int fd)
    :_connfd(fd)
{
}
SocketIO::~SocketIO(){}

size_t SocketIO::readn(char* buf, size_t n) {
    size_t left = n;
    char* pstr = buf;
    while(left > 0){

        int ret = read(_connfd,pstr,n); 
        if(ret < 0 && errno == EINTR){
            continue;
        }else if(ret == -1){
            return -1;
        }else if(ret == 0){
            break;
        }
        left -= ret;
        pstr += ret;
    }
    return n - left;
}

/**
 * @param fd
 * @param n
 * @return size_t
 */
size_t SocketIO::writen(const char* buf, size_t n) {
    cout << n << endl;
    size_t left = n;
    const char* pstr = buf;
    while(left > 0){
        int ret = write(_connfd,pstr,left);
        cout << ret << endl;
        if(ret < 0 && errno == EINTR){
            continue;
        }else if(ret == 0){
            break;
        }else if(ret < 0){
            return -1;
        }
        left -= ret;
        pstr += ret;
    }

    return n - left;
}

/**
 * @param fd
 * @return string
 */
size_t SocketIO::getLine(char* buf,size_t n) {
    size_t left = n;//65535
    size_t ret = 0;
    size_t total = 0;
    char* pstr = buf;

    while(left > 0){
        ret = recv(_connfd,pstr,left,MSG_PEEK);
        if(ret < 0 && errno == EINTR){
            continue;
        }else if(ret == 0){
            break;
        }else if(ret < 0){
            return -1;
        }
        cout << ret << endl;
        for(size_t idx = 0;idx < ret;++idx){
            if(pstr[idx] == '\n'){
                int sz = idx + 1;
                pstr[idx] = '\0';
                readn(pstr,sz);
                pstr += idx;
                total += sz;
                return total;
            }
        }
      readn(pstr,ret);
      left -= ret;
      pstr += ret;
      total += ret;
    }

    *pstr = '\0';

    return total;
}
