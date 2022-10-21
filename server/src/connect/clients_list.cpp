#include "clients_list.h"

void clients_list::add_client(client* user) {
    list.push_back(user);
}
int clients_list::get_size() const{
    return list.size();
}
client* clients_list::get_client_by_index(int index) const
{
    return index >= 0 && index < list.size() ? list[index] : nullptr;
}

client* clients_list::get_client_by_socket(int socket) const
{
    return *find_if(list.begin(), list.end(),
            [socket](client* user){return user->get_socket() == socket;});
}

client* clients_list::get_client_by_name(std::string name) const {
    return *find_if(list.begin(), list.end(),
            [name](client* user){return user->get_name() == name;});
}
void clients_list::remove_client(client* user)
{
    auto itr = std::remove_if(list.begin(), list.end(),
                             [user](client* some_user) 
                             {return some_user == user;});
    list.erase(itr);
}
