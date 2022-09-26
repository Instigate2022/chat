#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <cstring>
#include <thread>
#include <map>
#include <vector>

#define PORT 1242
#define buf_s 1024

using namespace std;

struct Clients
{
    string name;
    int socket;

    Clients(string name, int socket)
    {
        this->name = name;
        this->socket = socket;
    }

};

vector<Clients> list_clients;

void ClientConnect(int client);
void Send(int client, bool *isExit);
void Recv(int client, bool *isExit);

int main()
{
    int server ,client;
    socklen_t size;
    server = socket(AF_INET , SOCK_STREAM , 0);

    struct sockaddr_in serv_addres;

    serv_addres.sin_port = htons(PORT);

    serv_addres.sin_family = AF_INET;

    serv_addres.sin_addr.s_addr = htons(INADDR_ANY);


    bind(server, (struct sockaddr*)&serv_addres,sizeof(serv_addres));
    cout << "stacvec bind anel " << endl;


    size = sizeof(serv_addres);

    listen(server , 2);

    while (true)
    {
        client = accept(server , (struct sockaddr *)&serv_addres, &size);
        thread th1(ClientConnect, client);
        th1.detach();
        /// TBD collect in a map
        std::cout << "client connected" << client << std::endl;
    }
}

void ClientConnect(int client)
{
    bool isExit = false;
    char buffer[buf_s];
    recv(client, buffer, buf_s, 0);
    string name = buffer;
    Clients user(name, client);
    list_clients.push_back(user);
    thread thSend(Send, client, &isExit);
    thread thRecv(Recv, client, &isExit);
    thSend.join();
    thRecv.join();
}

void Send(int client, bool *isExit)
{
    while(!*isExit) {
        char buffer[buf_s];
        memset(&buffer, 0, sizeof(buffer));
        cin.getline(buffer, buf_s);
        send(client, buffer, buf_s, 0);
    }
}

void Recv(int client, bool *isExit)
{
    while(!*isExit) {
        char buffer[buf_s];
        memset(&buffer, 0, sizeof(buffer));
        recv(client, buffer, buf_s, 0);
        cout << buffer << '\n';
    }
}
