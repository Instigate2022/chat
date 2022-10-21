#ifndef CLIENTS_LIST_H
#define CLIENTS_LIST_H

#include <vector>
#include <string>
#include <cassert>
#include "client.h"
#include <algorithm>

class clients_list
{

private:
    std::vector<client*> list;

public:

    //accessor
    std::vector<client*>&  get_list() const;
    //added client in clients list

    int get_size() const;

    client* get_client_by_index(int index) const;

    client* get_client_by_socket(int socket) const;

    client* get_client_by_name(std::string name) const;

    //add client
    void add_client(client* user);
    //delete client
    void remove_client(client* user);
};

#endif //CLIENTS_LIST_H
