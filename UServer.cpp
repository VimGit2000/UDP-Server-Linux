#include "UServer.h"

const char *hello = "Message delivered";

UServer::UServer(/* args */)
{

}

 int UServer::InitServer(std::string s_addr, int port)
 {
     // Создание дескриптора файла сокета

    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        throw std::runtime_error("Socket don't creater!");
    }

    memset(&servaddr, 0, sizeof(servaddr));
       // Заполнение информации о сервере
    servaddr.sin_family    = AF_INET; // IPv4
    //servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  // servaddr.sin_addr.s_addr = inet_addr("0.0.0.0");
   // servaddr.sin_port = htons(PORT);
    servaddr.sin_port = htons(port);
    // Привязываем сокет с адресом сервера

    if ( bind(sockfd, (const struct sockaddr *)&servaddr,  sizeof(servaddr)) < 0 ) {
     throw std::runtime_error("Socket bind failed");
    }

    std::cout <<"Socket sucesseful created!" << std::endl;
   
    return sockfd;
 }

 void UServer::Read()
 {
    memset(&cliaddr, 0, sizeof(cliaddr));
    int STOP;
   // char *hello = "Hello from server";
    while(true) {
        lenght  = sizeof(cliaddr);  // len is value / resuslt
        countBytes = recvfrom(sockfd, (char *)buffer, MAXLINE,  MSG_WAITALL, ( struct sockaddr *) &cliaddr, ( socklen_t *)&lenght );
        buffer[countBytes] = '\0';
        std::cout <<"Client Send:" << buffer << std::endl;
        SendMessage();
      //  sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *) &cliaddr,lenght);
    }
 }


void UServer::SendMessage()
{
   lenght  = sizeof(cliaddr);  // len is value / resuslt
    memset(&cliaddr, 0, sizeof(cliaddr));
    sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *) &cliaddr,lenght);
}


UServer::~UServer()
{

          close(sockfd);
}
