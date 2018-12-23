//
// Created by sharon on 21/12/18.
//


#include "Server.h"

void *thread_func(void *arg) {
    cout << "yay! thread_func" << endl;
    Server *myServer = (Server *) arg;
    char buffer[1024] = {0};
    int readVars;
    while (myServer->continueThread) {
        readVars = read(myServer->getClientSocket(), buffer, 1024);
        if (readVars > 1) {
            myServer->ParserOfVars(buffer);
        }
    }
}

Server::Server() {
    initializeMap();
}


void Server::createServer(double port) {
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

    close(listenSocket);
}

void Server::ParserOfVars(string buffer) {
    cout << "start " << buffer << " end" << endl;
    restString += buffer;
    int i = 0;
    string tempValue = "";
    double value = 0;
    unordered_map<string,double>::iterator it = myTable.begin();
    while (restString[i] != '\n' && (it != myTable.end())) {
        if (restString.find(',') < restString.find('\n')) {
            tempValue = restString.substr(0, restString.find(','));
            cout << tempValue << endl;
            value = stod(tempValue);
            myTable[(*it).first] = value;
            restString.erase(0, restString.find(',') + 1);
            it++;
            i = 0;
        } else {
            i++;
        }
    }
    tempValue = restString.substr(0, restString.find('\n'));
    cout << tempValue << endl;
    if (tempValue.compare("") != 0) {
        value = stod(tempValue);
        myTable[(*it).first] = value;
        restString.erase(0, restString.find('\n') + 1);
    } else if (restString[0] == '\n') {
        restString.erase(0, restString.find('\n') + 1);
    }
}

int Server::getClientSocket() {
    return clientSocket;
}


void Server::initializeMap() {
    myTable.insert(make_pair(VAR_1, 0));
    myTable.insert(make_pair(VAR_2, 0));
    myTable.insert(make_pair(VAR_3, 0));
    myTable.insert(make_pair(VAR_4, 0));
    myTable.insert(make_pair(VAR_5, 0));
    myTable.insert(make_pair(VAR_6, 0));
    myTable.insert(make_pair(VAR_7, 0));
    myTable.insert(make_pair(VAR_8, 0));
    myTable.insert(make_pair(VAR_9, 0));
    myTable.insert(make_pair(VAR_10, 0));
    myTable.insert(make_pair(VAR_11, 0));
    myTable.insert(make_pair(VAR_12, 0));
    myTable.insert(make_pair(VAR_13, 0));
    myTable.insert(make_pair(VAR_14, 0));
    myTable.insert(make_pair(VAR_15, 0));
    myTable.insert(make_pair(VAR_16, 0));
    myTable.insert(make_pair(VAR_17, 0));
    myTable.insert(make_pair(VAR_18, 0));
    myTable.insert(make_pair(VAR_19, 0));
    myTable.insert(make_pair(VAR_20, 0));
    myTable.insert(make_pair(VAR_21, 0));
    myTable.insert(make_pair(VAR_22, 0));
    myTable.insert(make_pair(VAR_23, 0));
    myTable.insert(make_pair(VAR_24, 0));
}

Expression *Server::getValueFromMap(string s) {
    char temp[1000];
    strcpy(temp, s.c_str());


    if ((myTable.find(s)) != myTable.end()) {
        Expression *exp = new Number(myTable.find(s)->second);
        return exp;
    } else {
        return nullptr;
    }
}

Server::~Server() {
    continueThread = false;
    close(clientSocket);
}