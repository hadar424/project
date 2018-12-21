//
// Created by sharon on 21/12/18.
//


#include "Server.h"

void *thread_func(void *arg) {
    cout << "yay! thread_func" << endl;
    Server *myServer = (Server *) arg;
    char buffer[1024] = {0};
    int readVars;
    while (1) {
        readVars = read(myServer->getClientSocket(), buffer, 1024);
        if (readVars > 1) {
            //cout << "start\n" << buffer << "\nend"<< endl;
            myServer->ParserOfVars(buffer);
        }
    }
}

Server::Server(double port) {
    struct sockaddr_in address;
    int addrLen = sizeof(address);

    // Creating socket file descriptor
    if ((listenSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        throw runtime_error("socket failed");
    }

    memset(&address, '0', sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(listenSocket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        throw runtime_error("bind failed");
    }
    if (listen(listenSocket, 1) < 0) {
        throw runtime_error("listen failed");
    }
    if ((clientSocket = accept(listenSocket, (struct sockaddr *) &address, (socklen_t *) &addrLen)) < 0) {
        throw runtime_error("accept failed");
    }
    pthread_t waitForClient;
    pthread_create(&waitForClient, nullptr, thread_func, this);
}

void Server::ParserOfVars(string buffer) {
    int i = 0;
    int counterVar = 0;
    while (buffer[i] != '\n') {
        string temp = buffer.substr(0, buffer.find(','));
        counterVar++;
        buffer.erase(0, buffer.find(',') + 1);
        i++;
    }

}

int Server::getClientSocket() {
    return clientSocket;
}


