#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>

const int PORT = 8080;
const int BUFFER_SIZE = 1024;

int main() {
    // 创建套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // 连接服务器
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    std::cout << "-------->\n";
    while(1){
        std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
    }
    std::cout << "-------->\n";
    // 发送数据
    const char* message = "Hello, Server!";
    int ret = write(sockfd, message, strlen(message));
    std::cout << "ret=" << ret << std::endl;
    perror("write");

    if(ret == -1){
        perror("write");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    

    // 接收回显的数据
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read = read(sockfd, buffer, BUFFER_SIZE);
    std::cout << "bytes_read=" << bytes_read << std::endl;
    perror("bytes_read");
    
    if (bytes_read > 0) {
        std::cout << "Received from server: " << std::string(buffer, bytes_read) << std::endl;
    } else if (bytes_read == -1) {
        perror("read");
    }else{
        std::cout << "server disconnected\n";
    }

    close(sockfd);
    return 0;
}
