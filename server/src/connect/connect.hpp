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
#include <map>
#include <vector>
#include <map>

#define PORT 1233
#define buf_s 1024

using namespace std;

void ClientConnect(int client);
void Send(int client, bool *isExit);
void Recv(int client, bool *isExit);
vector<string> split(string a, char b);

#endif
