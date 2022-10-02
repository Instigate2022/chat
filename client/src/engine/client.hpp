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
    std::string mac_addres;
    void *wind_chat = nullptr;
    std::string file_link = "";

public:
    void setMyMacAddres();
    bool connect(std::string IP, int Port);
    bool run();
    bool login(std::string login, std::string password);
    bool registration(std::string login, std::string password);
    //bool Send(bool *isExit);
    void Send(std::string message, std::string to_whom);
    void sendFile(std::string to_whom);
    bool RecvFile();
    bool Recv(bool *isExit);
    void set_chat_window(void *window);
    void disconnect();
    std::vector<std::string> split(std::string msg, char split_char);
};

#endif
