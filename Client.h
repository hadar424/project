//
// Created by sharon on 21/12/18.
//

#ifndef UNTITLED_CLIENT_H
#define UNTITLED_CLIENT_H

#include <pthread.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "SymbolTable.h"
#include <string.h>

using namespace std;

class Client {
    int clientSocket;
public:
    void createClient(double, string);

    void setValueInMap(string, double);
    ~Client();
};


#endif //UNTITLED_CLIENT_H
