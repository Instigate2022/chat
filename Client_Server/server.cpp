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



struct Client
{
    string name;
    string password;

    Client(string name, string password)
    {
        this->name = name;
        this->password = password;
    }

};

vector<Client*> list_clients;

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
}


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

vector <string> split(string a, string b) {
	vector<string> matr;  
	string popox;
	for(int i = 0; i < a.size(); i++) {
		if (a[i] != b) {
			popox += a[i];
		else:
			matr.push_back(popox);
			popox = "";
		}
	}
	matr.push_back(popox);
}

void ClientConnect(int client)
{
    bool isExit = false;
    char buffer[buf_s];
    recv(client, buffer, buf_s, 0);
    string name = buffer;
    cout << "Name: " << name << '\n';

    Client *user = new Client(name, password);
    list_clients.push_back(user);
    thread thSend(Send, client, &isExit);
    thread thRecv(Recv, client, &isExit);
    thSend.join();
    thRecv.join();
    

}
std::vector <Client*> client_list;



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
