#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>
#include <vector>

#define buf_s 1024

class Client{
public:
    std::string name;
    int serverSocket;
    void *wind_chat = nullptr;

public:
    bool connect(std::string IP, int Port);
    bool run();
    bool login(std::string login, std::string password);
    bool registration(std::string login, std::string password);
    //bool Send(bool *isExit);
    void Send(std::string message, std::string to_whom);
    bool Recv(bool *isExit);
    void set_chat_window(void *window);
    void disconnect();
    std::vector<std::string> split(std::string msg, char split_char);
};

#endif
