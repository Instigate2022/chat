#include "connect.hpp"

std::ofstream infile;
Json::Value user_json;

struct Client
{
    std::string name;
    int socket;
    bool isOnline = true;

    Client(std::string name, int socket)
    {
        this->name = name;
        this->socket = socket;
    }
};

struct ClientsList
{
    std::vector<Client*> list;

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
        std::vector<Client*> new_list;
        for (int i = 0; i < list.size(); ++i) {
            if (list[i]->name != client->name) {
                new_list.push_back(list[i]);
            }
        }
        this->list = new_list;
    }
};

ClientsList clients_list;

void ClientConnect(int client)
{
    std::cout << "Client connected\n";
    bool isExit = false;
    std::thread thSend([&](){isExit = Send(client, &isExit);});
    std::thread thRecv([&](){isExit = Recv(client, &isExit);});
    thSend.join();
    thRecv.join();
}
/*
bool loginProcess(int client, bool *isExit)
{
    std::cout << "Client connected\n";
    bool LoggedIn = false;
    std::vector<std::string> list;
    while(!LoggedIn) {
        char buffer[buf_s];
        memset(buffer, 0 ,buf_s);
        recv(client, buffer, buf_s, 0);
        list = split(buffer, ' ');
        if (list[0] == "{?}") {
            LoggedIn = ClientLogin(client, list[1], list[2]);
            continue;
        }
        if (list[0] == "{??}") {
            Registration(client, list[1], list[2]);
            continue;
        }
    }
    setClientsList(client, list[1], list[2]);
    bool logOut = false;
    std::thread thSend([&](){logOut = Send(client, isExit, &logOut);});
    std::thread thRecv([&](){logOut = Recv(client, isExit, &logOut);});
    thSend.detach();
    thRecv.join();
    std::cout << "END LOGIN PROCESS\n";
    return *isExit;
}
*/
void setClientsList(int socket, std::string login)
{
    Client *user = new Client(login, socket);
    clients_list.addClient(user);
    std::cout << "Client added successful\n";
}

bool ClientLogin(int client, std::string name, std::string pass)
{
    Json::Value temp = user_json[name];
    std::string message;
    bool answer = false;
    if(temp.isNull()){
        message = "{?} Cancel";
    }
    else{

        Json::FastWriter fast_writer;
        std::string data_pass = fast_writer.write(user_json[name]);

        data_pass = data_pass.substr(1, data_pass.size() - 3);
        if(pass != data_pass){
            message = "{?} Wrong";
        }
        else{
            message = "{?} Ok";
            answer = true;
        }
    }
    send(client, message.c_str(), message.size(),0);
    return answer;
}
void Registration(int client, std::string login, std::string pass)
{
    char buffer[buf_s];
    memset(buffer, 0, sizeof(buffer));

    std::cout<<"temp:"<<user_json<<'\n';
    if(user_json[login].isNull()){
        write_user_to_json(user_json, login, pass);
        strcpy(buffer, "Ok");
        send(client, buffer, sizeof(buffer), 0);
    }
    else{
        std::cout << "else\n";
        strcpy(buffer, "Already exists");
        send(client, buffer, sizeof(buffer), 0);
    }


    /*
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
    */
}

void write_user_to_json(Json::Value& root,std::string login, std::string password){
    root[login] = password;
    infile.open("user-pass.json");

    Json::StyledStreamWriter writer;
    writer.write(infile, root);
    infile.close();
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
        recv(client, buffer, buf_s, 0);
        std::cout << "Buffer: " << buffer << '\n';
    }
    Client* user = clients_list.getClientBySocket(client);
    for (int i = 0; i < clients_list.size() - 1; ++i) {
        std::string message = "{!} " + user->name + " Connected\n";
        Client* send_to = clients_list.getClientByIndex(i);
        send(send_to->socket, message.c_str(), message.size(), 0);
    }
}

bool Send(int client, bool *isExit)
{
    while(!*isExit) {
        char buffer[buf_s];
        memset(&buffer, 0, sizeof(buffer));
        std::cin.getline(buffer, buf_s);
        std::string message = "Server: " + std::string(buffer);
        memset(&buffer, 0, sizeof(buffer));
        strcpy(buffer, message.c_str());
        send(client, buffer, buf_s, 0);
    }
}

bool Recv(int client, bool *isExit)
{
    while (!*isExit)
    {
        std::cout << "Start While\n";
        char buffer[buf_s];
        memset(buffer, 0, buf_s);
        recv(client, buffer, buf_s, 0);
        std::cout << "New Message: " << buffer << '\n';
        if (std::string(buffer).size() == 0) {
            std::cout << "Client Crashed\n";
            clientDisconnected(client);
            return true;
        }
        std::vector<std::string> list = split(std::string(buffer), ' ');

        print_vector(list);

        if (list[0] == "{!!}") {
            setClientsList(client, list[1]);
            addConnectedClients(client);
        }
        if (list[0] == "{#}") {
            clientLogOut(list[1]);
            continue;
        }
        if (list[0] == "{?}") {
            ClientLogin(client, list[1], list[2]);
            continue;
        }else if (list[0] == "{FILE}") {
                recvFile(client, list[1], list[2]);
            }
        if (list[0] == "{??}") {
            Registration(client, list[1], list[2]);
            continue;
        }
        if (list[0] == "{SENDTO}") {
            SendTo(list[1], std::string(buffer));
        }
    }
}

void SendTo(std::string to_whom, std::string message)
{
    int index = message.find(to_whom);
    std::cout << "Index: " << index << '\n';
    message.erase(0, index + to_whom.size() + 1);
    std::cout << "Message before erase: " << message << '\n';
    Client* user = clients_list.getClientByName(to_whom);
    if (user == nullptr) {
        std::cout << "User Not Found\n";
        return;
    }
    send(user->socket, message.c_str(), message.size(), 0);
}

void clientLogOut(std::string name)
{
    Client *user = clients_list.getClientByName(name);
    if (user == nullptr) {
        return;
    }
    //clients_list.remove(user);
    std::cout << "Remove: " << user->name << " by socket: " << user->socket << '\n';
    std::string message = "{#} " + user->name + " Disconnected\n";
    for (int i = 0; i < clients_list.size(); ++i) {
        Client* send_to = clients_list.getClientByIndex(i);
        send(send_to->socket, message.c_str(), message.size(), 0);
    }
}

void recvFile(int client, std::string to_whom, std::string file_name)
{
	std::cout << "To: " << to_whom << '\n';
	std::cout << "File name: " << file_name << '\n';
	std::string msg = "Ready Read\n";
	send(client, msg.c_str(), msg.size(), 0);

	char file_size_str[16];
	recv(client, file_size_str, 16, 0);
	int file_size = atoi(file_size_str);
	char * bytes = new char[file_size];

	std::fstream file;
	file.open(file_name,std::ios_base::out | std::ios_base::binary);

	if(file.is_open()) {
		recv(client, bytes, file_size, 0);	
		file.write(bytes,file_size);
	}
	delete [] bytes;
	file.close();
	std::cout << "End signal: " << '\n';
}

void clientDisconnected(int client)
{
    Client* user = clients_list.getClientBySocket(client);
    if (user == nullptr) {
         return;
     }
    std::cout << "Remove user: " << user->name << '\n';
    clients_list.remove(user);
    std::cout << "Connected Clients: " << clients_list.size() << '\n';
    std::string message = "{#} " + user->name + " Disconnected\n";
    for (int i = 0; i < clients_list.size(); ++i) {
        char buffer[buf_s];
        Client* user = clients_list.getClientByIndex(i);
        send(user->socket, message.c_str(), message.size(), 0);
    }
}

std::vector<std::string> split(std::string a, char b)
{
    std::vector<std::string> matr;
    std::string popox = "";
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

void print_vector(std::vector<std::string> list)
{
    for (int i = 0; i < list.size(); ++i) {
        std::cout << i << " " << list[i] << ".\n";
    }
}
