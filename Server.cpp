//
// Created by sharon on 21/12/18.
//


#include "Server.h"

struct MyParams {
    Server *myServer;
    int clientSocket;
};

void *thread_func(void *arg) {
    struct MyParams *params = (struct MyParams *) arg;
    char buffer[1024] = {0};
    int readVars;
    while (1) {
        readVars = read(params->clientSocket, buffer, 1024);
        if (readVars != -1) {
            params->myServer->ParserOfVars(buffer);
        }
    }
}

Server::Server(double port, double hertz) {


    int listenSocket, clientSocket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    string hello = "Hello from server";

    // Creating socket file descriptor
    if ((listenSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        throw runtime_error("socket failed");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);


    if (bind(listenSocket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        throw runtime_error("bind failed");
    }
    if (listen(listenSocket, 1) < 0) {
        throw runtime_error("listen failed");
    }
    if ((clientSocket = accept(listenSocket, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        throw runtime_error("accept failed");
    }
    struct MyParams *params = new MyParams();
    params->myServer = this;
    params->clientSocket = clientSocket;
    pthread_t waitForClient;
    pthread_create(&waitForClient, nullptr, thread_func, params);

    /*
    send(clientSocket, hello.c_str(), hello.length(), 0);
    cout << "Hello message sent\n";*/
}

void Server::ParserOfVars(string buffer) {

}

