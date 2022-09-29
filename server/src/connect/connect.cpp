#include "connect.hpp"

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

void ClientConnect(int client)
{
    bool isExit = false;
    char buffer[buf_s];
    memset(&buffer, 0, sizeof(buffer));
    recv(client, buffer, buf_s, 0);
    string message = buffer;
    cout << "New Message " << message << '\n';
    int index = std::string(buffer).find("#");
    if (index >= 0) {
        return;
    }
    vector<string> splited = split(message, ' ');
    std::string msg = "Ok";
    send(client, msg.c_str(), msg.size(), 0);
    for (int i = 0; i < splited.size(); i++) {
        cout << i << " " << splited[i] << '\n';
    }

    if (splited[0] == "{?}") {
        Client* client = new Client(splited[1],splited[2]);
        clients_list.addClient(client);
    }
    cout << "Connected clients: " << clients_list.size() << '\n';
    thread thSend([&](){isExit = Send(client, &isExit);});
    thread thRecv([&](){isExit = Recv(client, &isExit);});
    thSend.join();
    thRecv.join();
}


bool Send(int client, bool *isExit)
{
    while(!*isExit) {
        char buffer[buf_s];
        memset(&buffer, 0, sizeof(buffer));
        cin.getline(buffer, buf_s);
        send(client, buffer, buf_s, 0);
        int index = std::string(buffer).find("#");
        if (index >= 0) {
            return true;
        }
    }
}

bool Recv(int client, bool *isExit)
{
    while(!*isExit) {
        char buffer[buf_s];
        memset(&buffer, 0, sizeof(buffer));
        recv(client, buffer, buf_s, 0);
        cout << buffer << '\n';
        int index = std::string(buffer).find("#");
        if (index >= 0) {
            return true;
        }
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
