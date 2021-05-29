#include "client.h"

/*返回客户端单例对象*/
Client *Client::instance() {
    static Client client(IP,atoi(PORT));
    return &client;
}

/*构造函数*/
Client::Client(const char *ip , const uint16_t port) {
    //创建socket
    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientfd == -1) {
        perror("create socket error!");
        exit(-1);
    }

    //录入连接server服务器信息
    memset(&server, 0, sizeof(sockaddr_in));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    //server与clientfd连接
    if (-1 == connect(clientfd, (sockaddr *)&server, sizeof(sockaddr_in))) {
        perror("connect error!");
        close(clientfd);
        exit(-1);
    }
    /*初始化客户端业务处理模块*/
    ClientService::instance();
}

Client::~Client() {
    close(clientfd);
}
