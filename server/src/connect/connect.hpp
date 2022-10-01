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

using namespace std;

void ClientConnect(int client);
bool Send(int client, bool *isExit);
bool Recv(int client, bool *isExit);
vector<string> split(string a, char b);

bool ClientLogin(int client, std::string login, std::string pass);
void Registration(int client, std::string login, std::string pass);

#endif