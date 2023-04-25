#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT     8080
#define MAXLINE 1024

class UServer
{
public:
    UServer(/* args */);
    ~UServer();
    int InitServer(std::string s_addr, int port);
    void Read();
    void SendMessage();
    void Run();
    
    
private:

    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr, cliaddr;
    int lenght = 0;
    int countBytes = 0;
    /* data */

};

