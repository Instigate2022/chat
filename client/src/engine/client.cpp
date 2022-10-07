#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <string.h>
#include <fstream>

#include "client.hpp"
#include "../gui/chat.h"
#include "../gui/login.h"


std::vector<std::string> split(std::string str, char ch)
{
    std::vector<std::string> list;
    std::string buffer = "";
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != ch) {
            buffer += str[i];
        } else {
            list.push_back(buffer);
            buffer = "";
        }
    }
    if (buffer.size() != 0) {
        list.push_back(buffer);
    }
    return list;
}

bool Client::Connect(std::string ip, int port)
{
    sockaddr_in server_address;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_port = htons(port);
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, ip.c_str(), &server_address.sin_addr);
    int reply = connect(serverSocket, reinterpret_cast<const sockaddr*>(&server_address), sizeof(server_address));
    std::cout << "Reply: " << reply << '\n';
    if (reply != 0) {
        std::cout << "Don`t connected\n";
        return false;
    }
    std::cout << "Successfull connected\n";
    isExit = false;
    return true;
}

std::string Client::login(std::string login, std::string pass)
{
    name = login;
    this->pass = pass;
    char buffer[buf_s];
    memset(buffer, 0, buf_s);
    std::string message = "{?} " + login + " " + pass;
    send(serverSocket, message.c_str(), message.size(), 0);
    recv(serverSocket, buffer, buf_s, 0);
    std::cout << "Recv: " << buffer << '\n';
    std::vector<std::string> list = split(std::string(buffer), ' ');
    return list[1];
}

void Client::check_login(std::string reply)
{
    std::cout << "Reply: " << reply << '\n';
    Login *window = (Login*)wind_login;
    return;
}

void Client::set_chat_window(void *wind_chat)
{
    this->wind_chat = wind_chat;
    LoggedIn = true;
}

void Client::add_in_users_list(std::string name)
{
    Chat *window = (Chat*) wind_chat;
    window->set_users_list(name);
    std::cout << "Users list updated\n";
    std::string message = "Ok";
    send(serverSocket, name.c_str(), name.size(), 0);
}

bool Client::registration(std::string login, std::string pass)
{
    char buffer[buf_s];
    memset(buffer, 0, buf_s);
    std::string message = "{??} " + login + " " + pass;
    send(serverSocket, message.c_str(), message.size(), 0);
    recv(serverSocket, buffer, buf_s, 0);
    std::cout << "Buffer: " << buffer << '\n';
    if (std::string(buffer) == "Ok") {
        return true;
    }
    return false;
}

void Client::Send(std::string message, std::string to_whom)
{
    std::cout << "To whom: " << to_whom << '\n';
    std::cout << "Message: " << message << '\n';
    std::string msg = "{SENDTO} " + to_whom + " " + name + ": " + message;
    send(serverSocket, msg.c_str(), msg.size(), 0);
}

void Client::run()
{
    thRecv = std::thread([&](){isExit = Recv();});
    thRecv.detach();
}

bool Client::Recv()
{
    std::string message = "{!!} " + name;
    send(serverSocket, message.c_str(), message.size(), 0);
    std::cout << "Start recv\n";
    while(!isExit) {
        char buffer[buf_s];
        memset(buffer, 0, buf_s);
        recv(serverSocket, buffer, buf_s, 0);
        std::cout << "New Message: " << buffer << '\n';
        std::vector<std::string> list = split(std::string(buffer), ' ');
        if (list[0] == "{?}") {
            std::string message = "{?} " + name + " " + pass;
            send(serverSocket, message.c_str(), message.size(), 0);
            continue;
        }
        if (list[0] == "{#}") {
            Chat* window = (Chat*)wind_chat;
            window->client_disconnected(list[1]);
            continue;
        }
        if (list[0] == "{!}") {
            add_in_users_list(list[1]);
            continue;
        }
        other_message(std::string(buffer));
    }
}

void Client::other_message(std::string message)
{
    int index = message.find_first_of(":");
    if (index < 0) {
        return;
    }
    std::string name = message.substr(0, index);
    std::cout << "Other Message\n Sender Name: " << name << "\nMessage: " << message << '\n';
    Chat *window = (Chat*)wind_chat;
    window->set_list_message(name, message);
}

void Client::logOut()
{
    thRecv.~thread();
    sleep(0);
    isExit = true;
    wind_chat = nullptr;
    std::string message = "{#} " + name;
    send(serverSocket, message.c_str(), message.size(), 0);
    name = "";
    std::cout << "Log Out message: " << message << '\n';
}
