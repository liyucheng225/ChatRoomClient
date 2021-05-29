#ifndef CLIENT_H
#define CLIENT_H

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include "thirdPary/json.hpp"
#include "clientservice.h"

using namespace std;
using json = nlohmann::json;

#define PORT "8000"
#define IP "192.168.65.129"

class Client
{
public:
   /*获取单例对象*/
   static Client *instance();
   Client(const char *ip , const uint16_t port);
   ~Client();
   int clientfd;
private:
   sockaddr_in server;
};

#endif // CLIENT_H
