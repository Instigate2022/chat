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

void Client::setMyMacAddres()
{
    std::string bash_command = "ifconfig -a | grep ether | gawk '{print $2}' > mac_addres.txt";
    system(bash_command.c_str());
    std::ifstream info("mac_addres.txt");
    info >> mac_addres;
    std::cout << "Mac Addres: " << mac_addres << '\n';
}

bool Client::connect(std::string IP, int Port) {
    setMyMacAddres();
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
    char buffer[buf_s];
    int chgitem = gethostname(buffer, buf_s);
    std::cout << "Host ID = " << gethostid() << '\n';
    std::cout << "Chgitem = " << chgitem << '\n';
    std::cout << "Hostname = " << buffer << '\n';
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
        } else if (splited[0] == "{#}") {
            Chat* chat = (Chat*)wind_chat;
            chat->client_disconnected(splited[1]);
        }
        if (wind_chat != nullptr) {
            Chat* chat = (Chat*)wind_chat;
            chat->set_list_message(message);
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
    wind_chat = nullptr;
    char buffer[buf_s];
    strcpy(buffer, message.c_str());
    send(serverSocket, buffer, buf_s, 0);
}

void Client::sendFile(std::string to_whom)
{
    if(file_link == "") {
        return;
    }
    std::string file_name = file_link;
    file_name.erase(0, file_name.find_last_of("/") + 1);
    std::string message = "{FILE} " + to_whom + " " + file_name;
    send(serverSocket, message.c_str(), message.size(), 0);

    char buffer[buf_s];
    recv(serverSocket, buffer, buf_s, 0);
    std::cout << "Server ready recv file: " << buffer << '\n';
    memset(buffer, 0, buf_s);

    FILE* file;
    int words = 0;
    char c;
    std::cout << "File name: " << file_name << '\n';
    file = fopen(file_link.c_str(), "r");
    while((c = getc(file)) != EOF)
    {
        fscanf(file,"%s",buffer);
        std::cout << "buffer: " << buffer << '\n';
        if(isspace(c) || c == '\t')
            words++;
    }

    //send(serverSocket,&words,sizeof(int),0);
    rewind(file);
    char ch;
    while(ch != EOF)
    {
        fscanf(file, "%s", buffer);
        ch = fgetc(file);
        if (std::string(buffer).size() == 0) continue;
        std::string(buffer) += ch;
        std::cout << "IN 2 while: " << buffer << '\n';
        send(serverSocket,buffer,buf_s,0);
    }
    std::string end_signal = "{END OF FILE}";
    send(serverSocket, end_signal.c_str(), end_signal.size(), 0);

    /*
    QFile file(file_name);
    if(!(file.open(QIODevice::Append)))
    {
        qDebug("File cannot be opened.");
        exit(0);
    }
    QByteArray read = read(client->bytesAvailable());
    file.write(read);
    file.close();

    */
}

bool Client::RecvFile()
{
    FILE* fp;
    char buffer[buf_s];
    int ch = 0;
    fp = fopen("recievd.txt" ,"a");
    int words;
    recv(serverSocket, &words, sizeof(int), 0);
    while(ch != words)
    {
        recv(serverSocket, buffer, buf_s,0);
        fprintf(fp,"%s", buffer);
    }
    file_link = "";
}
