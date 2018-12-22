//
// Created by sharon on 21/12/18.
//

#include "Client.h"

Client::Client(double port, string ip) {
    struct sockaddr_in address;
    int clientSocket = 0;
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        throw runtime_error("Socket creation error");
    }

    memset(&address, '0', sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons((uint16_t) port);

    if (inet_pton(AF_INET, ip.c_str(), &address.sin_addr) <= 0) {
        cout << "Invalid address/ Address not supported \n";
    }

    if (connect(clientSocket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        throw runtime_error("Connection Failed");
    }

}