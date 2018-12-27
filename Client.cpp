#include "Client.h"

/*
 * Function Name: createClient
 * Input: double, string
 * Output:
 * Function Operation: the function create a socket for connecting to
 * the client.
 */
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
        throw runtime_error("Invalid address/ Address not supported");
    }
    // connect to the client
    if (connect(clientSocket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        throw runtime_error("Connection Failed");
    }
}

/*
 * Function Name: setValueInMap
 * Input: string, double
 * Output:
 * Function Operation: the function create a string message with a value and
 * a path and send it to the client(simulator).
 * the client.
 */
void Client::setValueInMap(string serverPath, double value) {
    string myMessage = "set " + serverPath + " " + to_string(value) + "\x0d\x0a";
    send(clientSocket, myMessage.c_str(), myMessage.length(), 0);
}

/*
 * Function Name: ~Client
 * Input:
 * Output:
 * Function Operation: ~Client destructor.
 */
Client::~Client() {
    close(clientSocket);
}