//
// Created by hadar on 12/18/18.
//

#ifndef UNTITLED_CONNECTCOMMAND_H
#define UNTITLED_CONNECTCOMMAND_H

#include "Command.h"
#include <iostream>
#include <pthread.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "Client.h"


using namespace std;


class ConnectCommand : public Command {

    string ip = "";
    double port = -1;
    int parametersNum = 2;
    Client *myClient = new Client();
public:
    ConnectCommand() = default;
    
    int doCommand(vector<string>);

    bool IsIpValid(string);

    bool IsNumberValid(string);

    Client *getClient();

    ~ConnectCommand();
};


#endif //UNTITLED_CONNECTCOMMAND_H
