#include "src/gui/login.h"
#include "../engine/client.hpp"
#define IP "192.168.6.206"
#define PORT 1236

#include <QApplication>

int main(int argc, char *argv[])
{
    Client *client = new Client();
    bool isConnected = client->Connect(IP, PORT);
    QApplication a(argc, argv);
    Login w(client, isConnected);
    return a.exec();
}
