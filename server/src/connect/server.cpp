#include "server.h"
#include "client.h" 
#include "clients_list.h"
/* #include <cstring>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <jsoncpp/json/json.h>
*/

//add_connected_clients, client_logout, client_login, registration, send_to

std::vector<std::string> server::commands = {"{!!}", "{#}", "{?}","{FILE}", "{??}", "{SENDTO}"};
Json::Value user_json;

clients_list list_of_clients;

server* server::m_server = nullptr;

server* server::get_instance(const int& domain,
                             const int& type,
                             const int& protocol,
                             const int& port,
                             const int& count_listeners){
    if( m_server == nullptr){
        m_server = new server(domain, type, protocol, port, count_listeners);
    }
    return m_server;
}

server::server(const int domain, 
               const int type,
               const int protocol,
               const int port,
               const int count_listeners)
    :m_domain(domain), m_type(type), m_protocol(protocol),
    m_port(port), m_count_listeners(count_listeners)
{}

int server::socket_with_assertion(int m_domain,int m_type,int m_protocol) const{
    int sockfd = socket(m_domain, m_type, m_protocol);
    assert(sockfd >= 0 && "socket faied");
    return sockfd; 
}
void server::bind_with_assertion(int sockfd, const struct sockaddr *addr, socklen_t addrlen) const{
    int res = bind(sockfd, addr, addrlen);
    assert(res >= 0 && "bind failed");
}
void server::listen_with_assertion(int sockfd, int backlog) const{
    int res = listen(sockfd, backlog);
    assert(res >= 0 && "listen failed");
}
int server::accept_with_assertion(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    int res = accept(sockfd, addr, addrlen);
    assert(res >= 0 && "accept failed");
    return res;
}
int server::send_with_assertion(int sockfd, const void *buf, int len, int flags) const{
    int res = send(sockfd, buf, len, flags);
    //assert(res >= 0 && "send failed");
    return res;
}
int server::recv_with_assertion(int sockfd, void *buf, int len, int flags) const{
    int res = recv(sockfd, buf, len, flags);
    //assert(res >= 0 && "recv failed");
    return res;
}
std::vector<std::string> server::split(std::string message, char del) const{
    std::vector<std::string> words;
    std::string  word = "";

    for(int i = 0; i < message.size(); i++) {
        if (message[i] != del) {
            word += message[i];
        }
        else {
            words.push_back(word);
            word = "";
        }
    }
    words.push_back(word);
    return words;
}
void server::set_clients_list(int socket, std::string login,std::string password, std::string state)
{
    client *user = new client(login, password, socket, true);
    list_of_clients.add_client(user);
    if(state == "{??}"){
        user->write_user_to_json(user_json);
    }
}

void server::registration(int user, std::string name, std::string password)
{
    //check in json case1 is exist, case2 not exist
    //case2 write password to json
    char buffer[buf_s];
    memset(buffer, 0, sizeof(buffer));
    //case1 send user that such user exists 
     
    Json::Value temp = user_json[name];
    if(!temp.isNull()){
        strcpy(buffer, "Is Exist");
        send_with_assertion(user, buffer, sizeof(buffer), 0);
    }
    else{
        //set_client and add to list_of_clients
        strcpy(buffer, "Ok");
        send_with_assertion(user, buffer, sizeof(buffer), 0);
    }
}

bool server::client_login(int user, std::string name, std::string password){

    Json::Value temp = user_json[name];
    std::string message;
    bool ans = true;
    if(temp.isNull()){
        message = "{?} Cancel";
        ans = false;
        //user_json.removeMember(name);
    }
    else{
        Json::FastWriter fast_writer;
        std::string data_pass = fast_writer.write(user_json[name]);
        //std::cout << data_pass;
        data_pass = data_pass.substr(1, data_pass.size() - 3);
        if(password != data_pass){
            message = "{?} Wrong";
            ans = false;
        }
        else{
            message = "{?} Ok";
            set_clients_list(user, name, password, "{?}");
            ans = true;
        }
    }
    send_with_assertion(user, message.c_str(), message.size(), 0);
    return ans;
}
void server::client_logout(std::string name){
    client *user = list_of_clients.get_client_by_name(name);
    if (user != nullptr) {
        list_of_clients.remove_client(user);
        std::string message = "{#} " + user->get_name() + " Disconnected\n";
        send_message_all_users(message, -1);
    }
}
void server::client_disconnected(int user){
    client* some_user = list_of_clients.get_client_by_socket(user);
    if (some_user != nullptr) {
        list_of_clients.remove_client(some_user);
        std::string message = "{#} " + some_user->get_name() + " Disconnected\n";
        send_message_all_users(message, -1);
    }
}

void server::send_message_all_users(std::string message, int new_user_index) const{
    int socket;
    for(int i = 0; i < list_of_clients.get_size(); ++i){
        if(i == new_user_index){
            continue;
        }
        socket = list_of_clients.get_client_by_index(i)->get_socket();
        send_with_assertion(socket, message.c_str(), message.size(), 0);
    }
}

void server::send_to(std::string to_whom, std::string message)
{
    int index = message.find(to_whom);
    message.erase(0, index + to_whom.size() + 1);
    client* user = list_of_clients.get_client_by_name(to_whom);
    if (user == nullptr) {
        std::cout << "User Not Found\n";
        return;
    }
    send_with_assertion(user->get_socket(), message.c_str(), message.size(), 0);
}

void server::send_info_consisting_users(int user, int new_user_index) const{
    std::string message_for_client = "{!} ";
    char buffer[buf_s];
    for(int i = 0; i < list_of_clients.get_size() - 1; ++i) {
        memset(buffer, 0, buf_s);
        message_for_client += list_of_clients.get_client_by_index(i)->get_name() + " Connected";
        strcpy(buffer, message_for_client.c_str());
        send_with_assertion(user, buffer, buf_s, 0);
    }
}
void server::add_connected_clients(int user)
{
    send_info_consisting_users(user, list_of_clients.get_size() - 1);
    //
    std::string message = list_of_clients.get_client_by_socket(user)->get_name();
    message = "{!} " + message + " Connected\n";
    send_message_all_users(message, list_of_clients.get_size() - 1);
}

void server::do_commands(int user, std::vector<std::string>& list,int command, std::string buffer){
        switch(command){
            case 1:
                //"{!!}"
                add_connected_clients(user);
                break;
            case 2:
                //"{#}"
                client_logout(list[1]);
                break;
            case 3:
                //"{?}"
                client_login(user, list[1], list[2]);
                break;
            case 4:
                //"{FILE}"
                recv_file(user, list[1], list[2]);
                break;
            case 5:
                //"{??}"
                registration(user, list[1], list[2]);
                set_clients_list(user, list[1], list[2],"{??}");
                break;
            case 6:
                //"{SENDTO}"
                send_to(list[1], buffer); 
                break;
        }
}
bool server::recv_message(int user, bool *is_exit){
    char buffer[buf_s];
    while (!*is_exit)
    {
        memset(buffer, 0, buf_s);
        recv_with_assertion(user, buffer, buf_s, 0);
        if (std::string(buffer).size() == 0) {
            client_disconnected(user);
            return true;
        }
        std::vector<std::string> list = split(std::string(buffer), ' ');

        int command = check_command(list[0]); 
        do_commands(user, list, command, buffer);
        std::cout << buffer << std::endl;
    }
}
void server::client_connect(int user){
    bool is_exit = false;
    std::thread recieve_thread([&](){
            is_exit = recv_message(user, &is_exit);
            });
    recieve_thread.join();
}

int server::check_command(std::string command) const{
    for(int i = 0; i < server::commands.size(); ++i){
        if(server::commands[i] == command){
            return i + 1;
        }
    }
    return -1;
}

void server::recv_file(int user, std::string to_whom, std::string file_name){
    std::cout << "To: " << to_whom << '\n';
    std::cout << "File name: " << file_name << '\n';
    std::string msg = "Ready Read\n";
    send_with_assertion(user, msg.c_str(), msg.size(), 0);

    char file_size_str[16];
    recv_with_assertion(user, file_size_str, 16, 0);
    int file_size = atoi(file_size_str);
    char * bytes = new char[file_size];

    std::fstream file;
    file.open(file_name,std::ios_base::out | std::ios_base::binary);

    if(file.is_open()) {
        recv_with_assertion(user, bytes, file_size, 0);	
        file.write(bytes,file_size);
    }
    delete [] bytes;
    file.close();
    std::cout << "End signal: " << '\n';
}

bool server::is_file_empty(std::ifstream& file) const{
    return file.peek() == std::ifstream::traits_type::eof();
}

void server::run(){
    //read user's data
    std::ifstream file("json_file", std::ifstream::binary);
    
  //  assert(file && "file doesn't exist");
    if(!(is_file_empty(file))){
        file >> user_json;
    }
    //create socket or server
    int chat_server = socket_with_assertion(m_domain, m_type, m_protocol);

    //create addres for sever
    socklen_t size;
    struct sockaddr_in adr = {0};
    adr.sin_family = m_domain;
    adr.sin_addr.s_addr = htons(INADDR_ANY);
    adr.sin_port = htons(m_port);
    //static_cast, dynamic_cast
    bind_with_assertion(chat_server, (struct sockaddr *) &adr, sizeof adr);

    listen_with_assertion(chat_server, m_count_listeners); 

    size = sizeof(adr);
    int user;
    while(1){
        user = accept_with_assertion(chat_server, (struct sockaddr *)&adr, &size);
        std::thread thread_chat([&](){
                client_connect(user);
                });
        thread_chat.detach();
        //thread_chat.detach();
    }
}
