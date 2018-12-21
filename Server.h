//
// Created by sharon on 21/12/18.
//

#ifndef UNTITLED_SERVER_H
#define UNTITLED_SERVER_H

#include <pthread.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "SymbolTable.h"
#include <string.h>

#define airspeed-indicator_indicated-speed-kt

using namespace std;

class Server {
    int listenSocket;
    int clientSocket;
    SymbolTable *myTable = new SymbolTable;
public:
    Server(double);

    int getClientSocket();
    void ParserOfVars(string);
};


#endif //UNTITLED_SERVER_H
