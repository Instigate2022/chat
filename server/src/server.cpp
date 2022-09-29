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
#include <map>


#define PORT 1233
#define buf_s 1024

using namespace std;


struct Client
{
    string name;
    string password;
    bool isOnline = true;

    Client(string name, string password)
    {
        this->name = name;
        this->password = password;
    }

};

struct ClientsList
{
    vector<Client*> list;
    Client* getClient(string name) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i]->name == name) {
                return list[i];
            }
        }
        return nullptr;
    }

    void addClient(Client* client) {
        list.push_back(client);
    }
    int size() {
        return list.size();
    }
};

ClientsList clients_list;

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

vector<string> split(string a, char b)
{
	vector<string> matr;
	string popox = "";
	for(int i = 0; i < a.size(); i++) {
		if (a[i] != b) {
			popox += a[i];
        }
		else {
			matr.push_back(popox);
			popox = "";
		}
	}
    matr.push_back(popox);
    return matr;
}

void ClientConnect(int client)
{
    bool isExit = false;
    char buffer[buf_s];
    memset(&buffer, 0, sizeof(buffer));
    recv(client, buffer, buf_s, 0);
    string message = buffer;
    cout << "New Message" << message << '\n';
    vector<string> splited = split(message, ' ');
    for (int i = 0; i < splited.size(); i++) {
        cout << i << " " << splited[i] << '\n';
    }

    if (splited[0] == "{?}") {
        Client* client = new Client(splited[1],splited[2]);
        clients_list.addClient(client);
    }
    cout << "Connected clients: " << clients_list.size() << '\n';
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
