#include "server.h"


int config_receiver(data *server){
    int socket_, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if((socket_ = socket(AF_INET, SOCK_STREAM , 0)) == 0){
        perror("socket failed");
        return -1;
    }

    if(setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(DISTRIBUTED_PORT);

    if(bind(socket_, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        return -1;
    }

    if(listen(socket_, 3) < 0){
        perror("listen");
        return -1;
    }

    if((new_socket = accept(socket_, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
        perror("accept");
        return -1;
    }
    server->recv_socket = new_socket;
    printf("Distributed server receiving requests\n");
    return 0;
}


int config_sender(data *server){
    int socket_ = 0;
    struct sockaddr_in server_addr;

    if ((socket_ = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("Socket creation error \n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(CENTRAL_HOST);
    server_addr.sin_port = htons(CENTRAL_PORT);

    if(inet_pton(AF_INET, CENTRAL_HOST, &server_addr.sin_addr)<=0){
        printf("Invalid address/ Address not supported\n");
        return -1;
    }

    while(connect(socket_, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        printf("Connection Failed. Trying again... \n");
    }

    server->send_socket = socket_;
    return 0;
}
