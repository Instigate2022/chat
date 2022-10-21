#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <jsoncpp/json/json.h>

class client
{
public:
    //accessors
    std::string get_name() const;
    std::string get_password() const;
    int get_socket() const;
    bool get_is_online() const;
    
    //constructor
    client(std::string name,std::string password, int socket, bool is_online);
    void write_user_to_json(Json::Value& root) const;
    
    //method for writting client login and passrod to json file


    //operators for compare
    bool operator==(const client& other) const;
    bool operator!=(const client& other) const;
    
    //mutator
    void set_is_online(bool state);

private:
    std::string m_name;
    std::string m_password;
    int m_socket;
    bool m_is_online = true;
};


#endif //CLIENT_H
