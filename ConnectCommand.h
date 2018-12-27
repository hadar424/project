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
    string ip;
    double port;
    int parametersNum;
    Client *myClient;
    bool IsIpValid(string);
    bool IsNumberValid(string);
public:
    ConnectCommand();
    int doCommand(vector<string>);
    Client *getClient();
    ~ConnectCommand();
};


#endif //UNTITLED_CONNECTCOMMAND_H
