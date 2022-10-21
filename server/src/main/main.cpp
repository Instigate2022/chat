#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> 
#include "../connect/server.h"
#include "../connect/clients_list.h"
#include "../connect/client.h"

#define port 1236

int main(int argc, char* argv[]){

    server* chat_server = server::get_instance(AF_INET, SOCK_STREAM, 0, port, 5);
    chat_server->run();
      return 0;
}
