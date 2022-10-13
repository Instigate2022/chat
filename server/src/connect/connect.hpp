#ifndef CONNECT_HPP
#define CONNECT_HPP

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
#include <vector>
#include <fstream>

#define PORT 1234
#define buf_s 1024

void ClientConnect(int client);
bool loginProcess(int client, bool *isExit);
bool Send(int client, bool *isExit);
void SendTo(std::string to_whom, std::string message);
bool Recv(int client, bool *isExit);
void recvFile(int client, std::string to_whom, std::string file_name);
void setClientsList(int socket, std::string login);
std::vector<std::string> split(std::string a, char b);

bool ClientLogin(int client, std::string login, std::string pass);
void Registration(int client, std::string login, std::string pass);
void clientLogOut(std::string name);
void clientDisconnected(int client);

void print_vector(std::vector<std::string> list);

#endif
