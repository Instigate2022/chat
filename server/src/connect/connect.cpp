#include "connect.hpp"

struct Client
{
    string name;
    string password;
    int socket;
    bool isOnline = true;

    Client(string name, string password, int socket)
    {
        this->name = name;
        this->password = password;
        this->socket = socket;
    }
};

struct ClientsList
{
    vector<Client*> list;

    void addClient(Client* client) {
        list.push_back(client);
        for (int i = 0; i < list.size(); ++i) {
            std::cout << i << " client: " << list[i]->name << '\n';
        }
    }

    int size() {
        return list.size();
    }

    Client* getClientByIndex(int index)
    {
        if (index < list.size()) {
            return list[index];
        }
        return nullptr;
    }

    Client* getClientBySocket(int socket)
    {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->socket == socket) {
                return list[i];
            }
        }
        return nullptr;
    }

    Client* getClientByName(std::string name) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->name == name) {
                std::cout << "List[i] = " << list[i]->name << '\n';
                std::cout << "Name = " << name << '\n';
                return list[i];
            }
        }
        return nullptr;
    }

    void remove(Client* client)
    {
        vector<Client*> new_list;
        for (int i = 0; i < list.size(); ++i) {
            if (list[i] != client) {
                new_list.push_back(list[i]);
            }
        }
        this->list = new_list;
    }
};

ClientsList clients_list;

void ClientConnect(int client)
{
    bool LoggedIn = false;
    while (!LoggedIn) {
        char buffer[buf_s];
        memset(&buffer, 0, buf_s);
        recv(client, buffer, buf_s, 0);
        string message = buffer;
        cout << "New Message " << message << '\n';
        int index = message.find("#");
        if (index >= 0) {
            return;
        }
        vector<string> splited = split(message, ' ');
        for (int i = 0; i < splited.size(); i++) {
            cout << i << " " << splited[i] << '\n';
        }
        if (splited[0] == "{?}") {
            LoggedIn = ClientLogin(client, splited[1], splited[2]);
        } else if (splited[0] == "{??}"){
            Registration(client, splited[1], splited[2]);
        }
    }
    cout << "Connected clients: " << clients_list.size() << '\n';
    bool isExit = false;
    thread thSend([&](){isExit = Send(client, &isExit);});
    thread thRecv([&](){isExit = Recv(client, &isExit);});
    thSend.join();
    thRecv.join();
}

bool ClientLogin(int client, std::string login, std::string pass)
{
    char buffer[buf_s];
    memset(buffer, 0, buf_s);
    std::ifstream user_file(login);
    if (!user_file) {
        strcpy(buffer, "Dont exist");
        std::cout << buffer << '\n';
        send(client, buffer, sizeof(buffer), 0);
        return false;
    }
    strcpy(buffer, "Ok");
    send(client, buffer, buf_s, 0);
    user_file.close();

    for (int i = 0; i < clients_list.size(); ++i) {
        memset(buffer, 0, buf_s);
        std::string message = "{!} " + login + " Connected";
        strcpy(buffer, message.c_str());
        Client* user = clients_list.getClientByIndex(i);
        std::cout << "Send to: " << user->name << " By Socket: " << user->socket << '\n';
        send(user->socket, buffer, buf_s, 0);
    }

    Client* user = new Client(login, pass, client);
    clients_list.addClient(user);

    return true;
}

void Registration(int client, std::string login, std::string pass)
{
    char buffer[buf_s];
    memset(buffer, 0, sizeof(buffer));
    std::ifstream file(login);
    if (file.is_open()) {
        file.close();
        strcpy(buffer, "Is Exist");
        std::cout << buffer << '\n';
        send(client, buffer, sizeof(buffer), 0);
        return;
    }
    std::ofstream user_file(login);
    user_file << pass;
    user_file.close();
    strcpy(buffer, "Ok");
    send(client, buffer, sizeof(buffer), 0);
}

void addConnectedClients(int client)
{
    for(int i = 0; i < clients_list.size() - 1; ++i) {
        char buffer[buf_s];
        memset(buffer, 0, buf_s);
        Client *user = clients_list.getClientByIndex(i);
        std::string messageForClient = "{!} " + user->name + " Connected";
        std::cout << "Message for client: " << messageForClient << '\n';
        strcpy(buffer, messageForClient.c_str());
        send(client, buffer, buf_s, 0);
    }
}

bool Send(int client, bool *isExit)
{
    addConnectedClients(client);
    while(!*isExit) {
        char buffer[buf_s];
        memset(&buffer, 0, sizeof(buffer));
        cin.getline(buffer, buf_s);
        send(client, buffer, buf_s, 0);
        int index = std::string(buffer).find("#");
        if (index >= 0) {
            std::cout << "Client: " << client << " Disconnected\n";
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
        std::string message = buffer;
        int index = message.find("#");
        if (index >= 0) {
            std::cout << "Client: " << client << " Disconnected\n";
            *isExit = true;
        }
        vector<string> splited = split(message, ' ');
        std::cout << "Splited size: " << splited.size() << '\n';
        for (int i = 0; i < splited.size(); ++i) {
            std::cout << i << " " << splited[i] << '\n';
        }
        if (splited.size() >= 2) {
            message.erase(0, message.find_first_of(" ") + 1);
            std::cout << "Message = " << message << '\n';
            memset(&buffer, 0, sizeof(buffer));
            strcpy(buffer, message.c_str());
            std::cout << "Clients List Szie: " <<  clients_list.size() << '\n';
            std::cout << "Splited[0] =" << splited[0] << ".\n";
            Client* user = clients_list.getClientByName(splited[0]);
            if (user != nullptr) {
                std::cout << "User != nullptr\n";
                send(user->socket, buffer, buf_s, 0);
            }
        }
        if (*isExit) {
            Client* user = clients_list.getClientBySocket(client);
            std::cout << "Remove user: " << user->name << '\n';
            clients_list.remove(user);
            std::cout << "Removed. Connected Clients: " << clients_list.size() << '\n';
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
