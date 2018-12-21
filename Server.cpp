//
// Created by sharon on 21/12/18.
//


#include "Server.h"

struct MyParams {
    double port;
    double hertz;
    Server *myServer;
};

void *thread_func(void *arg) {
    /*
    struct MyParams *params = (struct MyParams *) arg;
    char buffer[1024] = {0};
    int valread;
    while (1) {
        valread = read(new_socket, buffer, 1024);
        if (valread != -1) {
            cout << buffer << endl;
            arg->myServer->ParserOfVars(buffer);
        }
    }*/
}
/*
int Server::WaitForConnection(int new_socket, struct MyParams *args) {
    pthread_t trid;
    pthread_create(&trid, nullptr, thread_func, args);

}*/

Server::Server(double port, double hertz) {
    /*
    struct MyParams *params = new MyParams();
    params->port = port;
    params->hertz = hertz;
    params->myServer = this;
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    string hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        throw runtime_error("socket failed");
    }
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        throw runtime_error("setsockopt");
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(params->port);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        throw runtime_error("bind failed");
    }
    if (listen(server_fd, 3) < 0) {
        throw runtime_error("listen");
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        throw runtime_error("accept");
    }
    params->myServer->WaitForConnection(new_socket, params);

    send(new_socket, hello.c_str(), hello.length(), 0);
    cout << "Hello message sent\n";

    return nullptr;*/
}

void Server::ParserOfVars(string buffer) {

}