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

using namespace std;

class Server {
    SymbolTable *myTable = new SymbolTable;
public:
    Server(double, double);

    int WaitForConnection(int, struct MyParams *);

    void ParserOfVars(string);
};


#endif //UNTITLED_SERVER_H
