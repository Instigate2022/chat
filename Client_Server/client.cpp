#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <thread>

#define PORT 1242
#define buf_s 1024

void Send(int server, bool *isExit);
void Recv(int server, bool *isExit);

using namespace std;

string user_name;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Get server ip\n";
        exit(1);
    }
    string server_ip = argv[1];
    int server;

    char bufer[buf_s];
    struct sockaddr_in server_addres;

    server = socket(AF_INET,SOCK_STREAM,0);

    server_addres.sin_port = htons(PORT);

    server_addres.sin_family = AF_INET;

    inet_pton(AF_INET , server_ip.c_str() , &server_addres.sin_addr);

    connect(server, (struct sockaddr *)&server_addres, sizeof(server_addres));

    cout << "Get your name\n";
    string name;
    cin >> name;
    user_name = name;
    send(server, name.c_str(), name.size(), 0);
    bool isExit = false;
    thread thSend(Send, server, &isExit);
    thread thRecv(Recv, server, &isExit);
    thSend.join();
    thRecv.join();
}

void Send(int server, bool *isExit)
{
    while(!*isExit) {
        char buffer[buf_s];
        memset(&buffer, 0, sizeof(buffer));
        cin.getline(buffer, buf_s);
        std::string message = user_name + ": " + buffer;
        send(server, message.c_str(), message.size(), 0);
    }
}

void Recv(int server, bool *isExit)
{
    while(!*isExit) {
        char buffer[buf_s];
        memset(&buffer, 0, sizeof(buffer));
        recv(server, buffer, buf_s, 0);
        if (buffer[0] == '{') {
            cout << "OK\n";
        }
        cout << buffer << '\n';
    }
}
