#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <thread>

#define buf_s 1024

std::vector<std::string> split(std::string str, char ch);

class Client{
private:
    int serverSocket;
    std::string name;
    std::string pass;
    void* wind_login;
    void* wind_chat;
    bool LoggedIn = false;
    bool isExit;
    std::thread thRecv;

public:
    bool Connect(std::string ip, int port);
    void run();
    std::string file_link = "";
    std::string login(std::string login, std::string pass);
    void set_chat_window(void* wind_chat);
    void add_in_users_list(std::string name);
    bool registration(std::string login, std::string pass);
    void Send(std::string message, std::string to_whom);
    void sendFile(std::string to_whom);
    bool RecvFile();
    bool Recv();
    void other_message(std::string message);
    void logOut();
};

#endif
