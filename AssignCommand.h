//
// Created by sharon on 22/12/18.
//

#ifndef UNTITLED_ASSIGNCOMMAND_H
#define UNTITLED_ASSIGNCOMMAND_H

#include "Server.h"
#include "MakeItDouble.h"
#include <string>
#include "Client.h"
#include "Command.h"

class AssignCommand : public Command {
    Server *myServer;
    Client *myClient;
    SymbolTable *myTable;
    string var;
    double value;
    string path;
    int parametersNum = 1;
    MakeItDouble *myMakeItDouble;

public:
    int doCommand(vector<string>);

    void setSymbolTable(SymbolTable *);

    string cleanPath(string s);
    void setServer(Server *);

    void setClient(Client *);
};


#endif //UNTITLED_ASSIGNCOMMAND_H
