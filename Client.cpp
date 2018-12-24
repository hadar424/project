//
// Created by sharon on 21/12/18.
//

#include "Client.h"

void Client::createClient(double port, string ip) {
    struct sockaddr_in address;
    clientSocket = 0;
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
    cout << "client connected to simulator!" << endl;
}

void Client::setValueInMap(string serverPath, double value) {
    string myMessage = "set " + serverPath + " " + to_string(value) + "\x0d\x0a";
    cout << myMessage;
    char buffer[1024];
    strcpy(buffer, myMessage.c_str());
    int rc = send(clientSocket, myMessage.c_str(), strlen(myMessage.c_str()), 0);
    cout << "sent rc=" + to_string(rc) << endl;
    cout << "lets wait for response from telnet server...\n";
    rc = read(clientSocket, buffer, 1024);
    if (rc > 0) {
        buffer[rc] = 0;
        cout << buffer << endl;
    }


}

Client::~Client() {
    close(clientSocket);
}