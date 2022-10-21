#ifndef SERVER_H
#define SERVER_H 

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <string>
#include <vector>
#include <unordered_map>

#include <cstring>
#include <cassert>
#include <fstream>
#include <jsoncpp/json/json.h>

#define buf_s 1024

class server{
private:
    /**
     * The Server's constructor should always be private to prevent direct
     * construction calls with the `new` operator.
     */
    server(const int domain, const int type, const int protocol,
           const int port, const int count_listeners);
    static server* m_server;
    //static std::unique_ptr<server*> m_server;
    int m_domain;
    int m_type;
    int m_protocol;
    int m_port;
    int m_count_listeners;
    static std::vector<std::string> commands;

public:
    /**
     * Servers should not have copy constructor.
     */
    server(const server &other) = delete;

    /**
     * Servers should not be assignable.
     */
    server& operator=(const server&) = delete; 
    //Server should not have move constructor.
    server(server&&) = delete; 
    server& operator=(server&&) = delete; 
    /**
     * This is the static method that controls the access to the server 
     * instance. On the first run, it creates a servern object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
    static server *get_instance(const int& domain,
                               const int& type,
                               const int& protocol,
                               const int& port,
                               const int& count_listeners);
    void run(); 

    /*
       Socket()  creates  an  endpoint  for  communication  and  returns  a file
       descriptor that refers to that endpoint.  The file descriptor returned by
       a  successful  call  will be the lowest-numbered file descriptor not cur‐
       rently open for the process.
    */
    int socket_with_assertion(int domain,int type,int protocol) const;

    /*
       When  a  socket  is  created  with  Socket,  it exists in a name space
       (address family) but has no address assigned to it.  Bind()  assigns  the
       address  specified by addr to the socket referred to by the file descrip‐
       tor sockfd.  addrlen specifies the size, in bytes, of the address  struc‐
       ture  pointed  to  by  addr.   Traditionally,  this  operation  is called
       “assigning a name to a socket”.
       */
    void bind_with_assertion(int sockfd, const struct sockaddr *addr, socklen_t addrlen) const;

    /*
       Listen() marks the socket referred to by sockfd as a passive socket, that
       is, as a socket that will be used to accept incoming connection  requests
       using Accept.
       */
    void listen_with_assertion(int sockfd, int backlog) const;

    /*
       extracts the first connection  request on  the  queue  of  pending 
       connections for the listening socket, sockfd,
       creates a new connected socket, and returns a new file descriptor  refer‐
       ring  to  that  socket.  The newly created socket is not in the listening
       state.  The original socket sockfd is unaffected by this call.
       */
    int accept_with_assertion(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

    /*
       may be used to receive data on  both  connectionless
       and  connection-oriented  sockets.
       */
    int recv_with_assertion(int sockfd, void *buf, int len, int flags) const;

    /*
       Send is used to transmit a message to another socket.
       */
    int send_with_assertion(int sockfd, const void *buf, int len, int flags) const;

    bool is_file_empty(std::ifstream& file) const;


    void send_message_all_users(std::string message, int new_user_index)const;

    //split command, username and pawword
    std::vector<std::string> split(std::string message, char del) const;

    // function for registration
    void registration(int user, std::string name, std::string password);

    //fucntion for login
    bool client_login(int user, std::string name, std::string password);
    ////
    void client_logout(std::string name);
    void client_disconnected(int client);
    void send_to(std::string to_whom, std::string message);

    void send_info_consisting_users(int user, int new_user_index) const;


    void add_connected_clients(int user);
    bool recv_message(int user, bool* is_exit);

    void client_connect(int user);

    void set_clients_list(int socket, std::string login,std::string password, std::string state);
    int check_command(std::string command) const;
    //send user all his(her) conversation history
    void send_user_history(int user) const;
    void send_online_user_info()const;
    void do_commands(int user, std::vector<std::string>& list,int commands, std::string buffer);

    void recv_file(int user, std::string to_whom, std::string file_name);
};
    

//void recvFile(int client, std::string to_whom, std::string file_name);

#endif //SERVER_H
