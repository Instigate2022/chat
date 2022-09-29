#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>

#define buf_s 1024

class Client{
public:
    std::string name;
    int serverSocket;

public:
    bool connect(std::string IP, int Port);
    bool run();
    bool login(std::string login, std::string password);
    bool registration(std::string login, std::string password);
    //bool Send(bool *isExit);
    void Send(std::string message);
    bool Recv(bool *isExit);
};

#endif