#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <string.h>

#include "client.hpp"
#include "../gui/chat.h"

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
    std::cout << "Create Thread\n";
    std::thread thRecv([&](){isExit = Recv(&isExit);});

//    thSend.join();
    std::cout << "Start Thread\n";
    thRecv.join();
}

bool Client::login(std::string login, std::string password)
{
    std::string message = "{?} " + login + " " + password;
    send(serverSocket, message.c_str(), message.size(), 0);
    char rec[buf_s];
    memset(rec, 0, buf_s);
    recv(serverSocket, rec, buf_s, 0);
    std::cout << "Rec is " << rec << '\n';
    if (std::string(rec) == "Ok") {
        name = login;
        return true;
    }
    return false;
}

bool Client::registration(std::string login, std::string password)
{
    std::string message = "{??} " + login + " " + password;
    send(serverSocket, message.c_str(), message.size(), 0);
    char rec[buf_s];
    memset(rec, 0, buf_s);
    recv(serverSocket, rec, buf_s, 0);
    std::cout << "Rec is " << rec << '\n';
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
        std::string message = buffer;
        std::cout << "New Message: " << message  << '\n';
        if (message.size() == 0) {
            continue;
        }
        std::vector<std::string> splited = split(message, ' ');
        for (int i = 0; i < splited.size(); ++i) {
            std::cout << i << " " << splited[i] << ".\n";
        }
        if (splited[0] == "{!}") {
            std::cout << "In go to set users list\n";
            while (wind_chat == nullptr) {
                sleep(2);
            }
            Chat* chat = (Chat*)wind_chat;
            chat->set_users_list(splited[1]);
            message.erase(0, message.find_first_of('}') + 1);
        }
        if (wind_chat != nullptr) {
            Chat* chat = (Chat*)wind_chat;
            chat->set_list_message(message);
        }
        int index = message.find('#');
        if (index >= 0) {
            exit(0);
        }
    }
}

void Client::Send(std::string message, std::string to_whom) {
    if (message.size() == 0) {
        return;
    }
    std::string msg = to_whom + " " + name + ": " + message;
    char buffer[buf_s];
    memset(buffer, 0, buf_s);
    strcpy(buffer, msg.c_str());
    send(serverSocket, buffer, buf_s, 0);
}

void Client::set_chat_window(void *window)
{
    this->wind_chat = window;
}

std::vector<std::string> Client::split(std::string msg, char split_char)
{
    std::vector<std::string> list;
    std::string str = "";
    for(int i = 0; i < msg.size(); i++) {
        if (msg[i] != split_char) {
            str += msg[i];
        }
        else {
            list.push_back(str);
            str = "";
        }
    }
    list.push_back(str);
    return list;
}

void Client::disconnect()
{
    std::string message = "{#} " + name;
    char buffer[buf_s];
    strcpy(buffer, message.c_str());
    send(serverSocket, buffer, buf_s, 0);
}
