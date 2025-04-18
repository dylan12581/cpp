#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const int PORT = 8080;
const int BUFFER_SIZE = 1024;

void set_nonblocking(int sockfd) {
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl F_GETFL");
        exit(EXIT_FAILURE);
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl F_SETFL");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // 创建套接字
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // 设置套接字为非阻塞模式
    set_nonblocking(listen_fd);

    // 绑定地址和端口
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(listen_fd);
        exit(EXIT_FAILURE);
    }

    // 监听连接
    if (listen(listen_fd, SOMAXCONN) == -1) {
        perror("listen");
        close(listen_fd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

    while (true) {
        // 接受新连接
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int conn_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_len);

        if (conn_fd == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                // 没有新的连接，稍后再试
                std::cout << "conn_fd = -1" << "\n";
                usleep(100000); // 休眠100毫秒
                continue;
            } else {
                perror("accept");
                close(listen_fd);
                exit(EXIT_FAILURE);
            }
        }

        // 设置客户端套接字为非阻塞模式
        set_nonblocking(conn_fd);

        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;
        while ((bytes_read = read(conn_fd, buffer, BUFFER_SIZE)) > 0) {
            std::cout << "Received: " << std::string(buffer, bytes_read) << std::endl;

            // 回显数据给客户端
            if (write(conn_fd, buffer, bytes_read) != bytes_read) {
                perror("write");
                break;
            }
        }

        if (bytes_read == -1) {
            if (errno != EAGAIN && errno != EWOULDBLOCK) {
                perror("read");
            }
            std::cout << "errno = EAGAIN || errno = EWOULDBLOCK" << std::endl;

        } else if (bytes_read == 0) {

            std::cout << "Client disconnected" << std::endl;
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}
