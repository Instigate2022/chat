#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <string.h>

#include "client.hpp"

bool Client::connect(std::string IP, int Port) {
    struct sockaddr_in server_addres;
    serverSocket = socket(AF_INET,SOCK_STREAM,0);
    server_addres.sin_port = htons(Port);
    server_addres.sin_family = AF_INET;
    inet_pton(AF_INET , IP.c_str() , &server_addres.sin_addr);

    int ret = ::connect(serverSocket, (struct sockaddr *)&server_addres, sizeof(server_addres));
    if (ret == 0) {
        return true;
    }
    return false;
}

bool Client::run()
{
    if (serverSocket < 0) {
        return false;
    }
    bool isExit = false;
//    std::thread thSend([&](){isExit = Send(&isExit);});
    std::thread thRecv([&](){isExit = Recv(&isExit);});

//    thSend.join();
    thRecv.join();
}

bool Client::login(std::string login, std::string password)
{
    char rec[30];
    std::string message = "{?} " + login + " " + password;
    send(serverSocket, message.c_str(), message.size(), 0);
    recv(serverSocket, rec, 30, 0);
    if (std::string(rec) == "Ok") {
        return true;
    }
    return false;
}

bool Client::registration(std::string login, std::string password)
{
    char rec[30];
    std::string message = "{??} " + login + " " + password;
    send(serverSocket, message.c_str(), message.size(), 0);
    recv(serverSocket, rec, 30, 0);
    if (std::string(rec) == "Ok") {
        return true;
    }
    return false;

}
/*
bool Client::Send(bool *isExit)
{
    while(!*isExit) {
        char buffer[buf_s];
        memset(buffer, 0, buf_s);
        std::cin.getline(buffer, buf_s);
        send(serverSocket, buffer, buf_s, 0);
        int index = std::string(buffer).find('#');
        if (index >= 0) {
            exit(0);
        }
    }
}
*/

bool Client::Recv(bool *isExit)
{
    while(!*isExit) {
        char buffer[buf_s];
        memset(buffer, 0, buf_s);
        recv(serverSocket, buffer, buf_s, 0);
        std::cout << buffer << '\n';
        int index = std::string(buffer).find('#');
        if (index >= 0) {
            exit(0);
        }
    }
}

void Client::Send(std::string message) {
    char buffer[buf_s];
    memset(buffer, 0, buf_s);
    strcpy(buffer, message.c_str());
    std::cout << 
    send(serverSocket, buffer, buf_s, 0);
}