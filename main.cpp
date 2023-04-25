#include "UServer.h"


int main(int argc, char *argv[]) 
{
    int port;
    try
    {
        std::cout<<"Введите номер порта:";
        std::cin>>port;
        UServer server;
        server.InitServer("127.0.0.1", port);
        server.Read();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
