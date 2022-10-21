#include "../connect/connect.hpp"
int main()
{
    std::ifstream file("user-pass.json", std::ifstream::binary);
    if(file){
        file >> user_json;

    }
    int server, client;
    socklen_t size;
    server = socket(AF_INET , SOCK_STREAM , 0);

    struct sockaddr_in serv_addres;
    serv_addres.sin_port = htons(PORT);
    serv_addres.sin_family = AF_INET;
    serv_addres.sin_addr.s_addr = htons(INADDR_ANY);

    if (bind(server, (struct sockaddr*)&serv_addres,sizeof(serv_addres)) < 0) {
        std::cout << "Bind Error\n";
        return 1;
    }
    std::cout << "Binding ..." << std::endl;

    size = sizeof(serv_addres);

    listen(server , 2);

    while (true)
    {
        client = accept(server , (struct sockaddr *)&serv_addres, &size);
        std::thread th1(ClientConnect, client);
        th1.detach();
        /// TBD collect in a map
        std::cout << "client connected " << client << std::endl;
    }
}
