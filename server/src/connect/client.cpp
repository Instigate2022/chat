#include "client.h"

std::ofstream infile;

client::client(std::string name, std::string password, int socket, bool is_online)
    :m_name(name), m_password(password), m_socket(socket), m_is_online(is_online)
{}

bool client::operator==(const client& other) const{
    return m_name == other.m_name && m_password == other.m_password &&
           m_socket == other.m_socket && m_is_online == other.m_is_online;
}
bool client::operator!=(const client& other) const{
    return !(*this == other);
}

std::string client::get_name() const
{
    return m_name;
}
std::string client::get_password() const{
    return m_password;
}
int client::get_socket() const{
    return m_socket;
}
bool client::get_is_online() const{
    return m_is_online;
}

void client::set_is_online(bool state){
    m_is_online = state;
}

void client::write_user_to_json(Json::Value& root) const{
    root[m_name] = m_password;
    infile.open("json_file");

    Json::StyledStreamWriter writer;
    writer.write(infile, root);
    infile.close();
}
