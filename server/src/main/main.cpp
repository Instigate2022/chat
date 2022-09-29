#include "../connect/connect.hpp"

int main()
{
    int server ,client;
    socklen_t size;
    server = socket(AF_INET , SOCK_STREAM , 0);

    struct sockaddr_in serv_addres;
    serv_addres.sin_port = htons(PORT);
    serv_addres.sin_family = AF_INET;
    serv_addres.sin_addr.s_addr = htons(INADDR_ANY);

    bind(server, (struct sockaddr*)&serv_addres,sizeof(serv_addres));
    cout << "stacvec bind anel " << endl;

    size = sizeof(serv_addres);

    listen(server , 2);

    while (true)
    {
        client = accept(server , (struct sockaddr *)&serv_addres, &size);
        thread th1(ClientConnect, client);
        th1.detach();
        /// TBD collect in a map
        std::cout << "client connected" << client << std::endl;
    }
}

